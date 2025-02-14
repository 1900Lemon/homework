// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSPlayerController.h"
#include "MyFPSHwGameMode.h"

//修改1
	// UMyUserWidget* HUD = CreateWidget<UMyUserWidget>(this,RealTimeUI);
	// if (HUD!=nullptr)
	// {
	// 	HUD->AddToViewport();
	// }

void AFPSPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UMyUserWidget* HUD = CreateWidget<UMyUserWidget>(this,RealTimeUI);
	if (HUD!=nullptr)
	{
		HUD->AddToViewport();
	}
}

void AFPSPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	GetTime();
	if (Time <= 0)
	{
		UGameOver* HUDGameOver = CreateWidget<UGameOver>(this,GameOverUI);
		if (HUDGameOver!=nullptr)
		{
			HUDGameOver->AddToViewport();
		}	
	}
	
}

void AFPSPlayerController::GetTime()
{
	AMyFPSHwGameMode* MyGameModeInstance = Cast<AMyFPSHwGameMode>(GetWorld()->GetAuthGameMode<AMyFPSHwGameMode>());
	if (MyGameModeInstance) 
	{
			Time = MyGameModeInstance->CurrentTime;
	}
	
}

