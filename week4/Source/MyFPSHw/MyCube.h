// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/PlayerState.h"
#include <Net\UnrealNetwork.h>
#include "Engine/Engine.h"
#include "MyCube.generated.h"

UCLASS()
class MYFPSHW_API AMyCube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyCube();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	

	UPROPERTY(EditAnywhere, BlueprintReadWrite,category = "Scale")
	int32 y = 2;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UStaticMeshComponent* CubeMesh;

	/*UPROPERTY(ReplicatedUsing = OnRep_Score)
	float Score;*/

	//UFUNCTION()
	//void OnRep_Score();

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//int Y;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UMaterialInstance* PointOneMaterial;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UMaterialInstance* PointTwoMaterial;


	UPROPERTY(ReplicatedUsing = OnRep_Material)
	UMaterialInstance* CurrentMaterial;

	

	UFUNCTION()
	void OnRep_Material();

	//UFUNCTION()
	//void OnRep_Point();

	//UFUNCTION()
	//void OnRep_Scale();

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MyCube")
	//UMaterialInstance* CurrentMaterial;

	//UFUNCTION(Server, Reliable, WithValidation)
	//void ServerSetMaterial(UMaterialInstance* NewMaterial);

	
	//UFUNCTION(NetMulticast, Reliable)
	//void MulticastSetMaterial(UMaterialInstance* NewMaterial);

	FTimerHandle BeHittedTimer;
	UPROPERTY(ReplicatedUsing = OnRep_Point)
	bool bIsTwo = false;
	UPROPERTY(ReplicatedUsing = OnRep_Scale)
	//bool bScaled = false;
	int32 ScaleCnt = 0;


	
	//bool bCurrentIsTwo = false;
	//
	//bool bCurrentScaled = false;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	//rep
	UFUNCTION()
	void OnRep_Point();

	UFUNCTION()
	void OnRep_Scale();



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	

	UFUNCTION()
	void OnComponentHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);


	UFUNCTION()
	void OnTakePoint(AActor* OtherActor);
	//UFUNCTION(Server, Reliable, WithValidation)
	//void ServerOnTakePoint(AActor* OtherActor);

	
	void OnTransform();

	void Scale();




	
	UFUNCTION(Server,Reliable,WithValidation)
	void ServerHit(AActor* otherActor);



};
