// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyAIController.h"
#include "GameFramework/Character.h"
#include "Enemy_AnimInstance.h"
#include "StatsComponent.h"
#include "Kismet/GameplayStatics.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class MYFPSHW_API AEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacter();
	// UPROPERTY(EditAnywhere,BlueprintReadWrite)
	// 	class UStatsComponent* StatsComp;
	UPROPERTY(BlueprintReadOnly)
		class UEnemy_AnimInstance* EnemyAnim;

	//调用后会对我们的玩家造成伤害的函数

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Health")
	// 	float Health

	// float GetDamage();
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category= "Health");
	float Health;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category= "Health");
	float MaxHealth;
	UFUNCTION()
	void MyTakeDamage(float Amount) ;

	bool bisDie;
	UFUNCTION(BlueprintCallable)
	void isDead();

	


	// UFUNCTION()
	// 	void ReduceHealth(float DamageAmount);
	//
	// UFUNCTION()
	// 	virtual void OnDeath();
	
};
