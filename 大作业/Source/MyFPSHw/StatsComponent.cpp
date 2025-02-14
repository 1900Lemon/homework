// Fill out your copyright notice in the Description page of Project Settings.


#include "StatsComponent.h"
#include"EnemyCharacter.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values for this component's properties
UStatsComponent::UStatsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	// ...
}


// Called when the game starts
void UStatsComponent::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp,Warning,TEXT("Health:%f"),Stats[EStat::Health]);
	// ...
	// AActor* MyOwner = GetOwner();
 //
	// if(MyOwner)
	// {
	// 	MyOwner->OnTakeAnyDamage.AddDynamic(this, &UStatsComponent::HandleTakeDamage);
 //
	// 	//所有者对象现在一定会响应OnTakeAnyDamage函数。
	// 	// MyOwner->OnTakeAnyDamage.AddDynamic(this,&UStatsComponent::HandleTakeAnyDamage);
	// }
 
	//将生命值设置为最大生命值。
	
}


// Called every frame
void UStatsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// ...
}

// void UStatsComponent::ReduceHealth(float Damage)
// {
// 	if (Stats[EStat::Health] <= 0)
// 	{
// 		return ;
// 	}
// 	Stats[EStat::Health] -= Damage;
// 	Stats[EStat::Health] = UKismetMathLibrary::FClamp(
// 		Stats[EStat::Health],
// 		0,
// 		Stats[EStat::MaxHealth]
// 	);
// }




