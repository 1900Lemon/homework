// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include <Net\UnrealNetwork.h>
#include "GameFramework/GameModeBase.h"
#include "Engine/Engine.h"
#include "GameFramework/Actor.h"
#include "MyCube.h"
#include"MyUserWidget.h"
#include "MyFPSHwGameMode.generated.h"

UCLASS(minimalapi)
class AMyFPSHwGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMyFPSHwGameMode();
	UPROPERTY(EditAnywhere, BlueprintReadWrite,category = "Game")
	int32 TotalTime;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,category = "Game")
	int32 CurrentTime;
	//UPROPERTY()
	//UMyUserWidget* HUDWidget;

protected:
	virtual void BeginPlay() override;


private:
	FTimerHandle CountdownTimerHandlle;
	void UpdateCountdown();
	void GameOver();

	UPROPERTY(EditAnywhere, Category = "Game Over")
	TSubclassOf<class UUserWidget> GameOverWidgetClass;
		
	UUserWidget* GameOverWidget;
};



