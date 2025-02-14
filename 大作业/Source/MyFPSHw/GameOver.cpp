// Fill out your copyright notice in the Description page of Project Settings.


#include "GameOver.h"
#include "GameFramework/PlayerState.h"
#include "MyFPSHwGameMode.h"
#include "GameFramework/PlayerController.h"
#include "FPSPlayerController.h"
// #include "MyPlayerController.h"
#include "MyFPSHwCharacter.h"

void UGameOver::NativeConstruct()
{
	Super::NativeConstruct();
	if (Score) 
	{
		UpdateScore();
		Score->SetText(FText::FromString(TEXT("Score")));
	}
}

void UGameOver::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

void UGameOver::UpdateScore()
{
	AFPSPlayerController* PlayerController =  Cast<AFPSPlayerController>(GetWorld()->GetFirstPlayerController());
	if (PlayerController)
	{
		APlayerState* PlayerState = PlayerController->PlayerState;
		if (PlayerState)
		{
			if (Score)
			{
				fScore = PlayerState->Score;
				FText Text = FText::AsNumber(fScore);
				Score->SetText(Text);
			}
		}
	}
}
