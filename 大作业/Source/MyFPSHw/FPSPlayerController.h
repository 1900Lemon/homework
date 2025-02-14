// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyUserWidget.h"
#include "GameOver.h"
#include "FPSPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MYFPSHW_API AFPSPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
		//修改1
	UPROPERTY(EditAnywhere,Category="UI")
	TSubclassOf<UMyUserWidget>RealTimeUI;
	UPROPERTY(EditAnywhere,Category="UI")
	TSubclassOf<UMyUserWidget>GameOverUI;
	float Time;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	void GetTime();
};
