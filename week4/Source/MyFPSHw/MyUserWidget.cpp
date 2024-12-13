// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUserWidget.h"
#include "MyFPSHwGameMode.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/PlayerState.h"


void UMyUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (Score) 
	{
		Score->SetText(FText::FromString(TEXT("Score")));
	}

	if (Time)
	{
		Time->SetText(FText::FromString(TEXT("Time")));
	}

	//if (Bullets)
	//{
	//	Bullets->SetText(FText::FromString(TEXT("Score")));
	//}

	fScore = 0.f;
	iTime = 0;

}

void UMyUserWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	UpdateScore();
	UpdateTime();
}

void UMyUserWidget::UpdateScore()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
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

void UMyUserWidget::UpdateTime()
{
	AMyFPSHwGameMode* MyGameModeInstance = Cast<AMyFPSHwGameMode>(GetWorld()->GetAuthGameMode<AMyFPSHwGameMode>());
	if (MyGameModeInstance) 
	{
		if (Time)
		{
			iTime = MyGameModeInstance->CurrentTime;
			FText Text = FText::AsNumber(iTime);
			Time->SetText(Text);
		}
	}
	
}

