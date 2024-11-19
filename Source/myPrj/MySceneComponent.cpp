// Fill out your copyright notice in the Description page of Project Settings.


#include "MySceneComponent.h"


// Sets default values for this component's properties
UMySceneComponent::UMySceneComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	CurrLocation = StartLocation;
	// ...
}


// Called when the game starts
void UMySceneComponent::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = FVector(1700.0f, 500.0f, 0.0f);

	// ...
	
}


// Called every frame
void UMySceneComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if (FVector::Dist(CurrLocation, EndLocation) < stoppingDistance) {
		return;
	}
	
	FVector Direction = (EndLocation - CurrLocation).GetSafeNormal();//并做归一化
	//获得移动方向

	FVector NewLocation = CurrLocation + (Direction * (speed * DeltaTime)); //获取前进位置
	SetRelativeLocation(NewLocation);
	CurrLocation = NewLocation;
	// ...
}

