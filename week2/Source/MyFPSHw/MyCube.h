// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "GameFramework/PlayerController.h"
#include "GameFramework/PlayerState.h"

#include "MyCube.generated.h"

UCLASS()
class MYFPSHW_API AMyCube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyCube();
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UStaticMeshComponent* CubeMesh;


	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//int Y;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UMaterialInstance* PointOneMaterial;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UMaterialInstance* PointTwoMaterial;

	FTimerHandle BeHittedTimer;

	bool BisTwo = false;
	bool bScaled = false;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	

	UFUNCTION()
	void OnComponentHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	//获取积分
	void OnTakePoint(AActor* OtherActor);


	//开始时随即变形
	void OnTransform();

	void Scale(int y);
	
	
};
