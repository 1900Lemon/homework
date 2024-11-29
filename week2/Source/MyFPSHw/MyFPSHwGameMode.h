// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
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

protected:
	virtual void BeginPlay() override;

private:
	FTimerHandle CountdownTimerHandlle;
	void UpdateCountdown();
	void GameOver();
};



