// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Enemy_AnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class MYFPSHW_API UEnemy_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadWrite)
	float CurrentSpeed{ 0.0f };
	
	
	
};
