// Copyright Epic Games, Inc. All Rights Reserved.

//#include "MyFPSHwGameMode.h"
//#include "MyFPSHwCharacter.h"
//#include "UObject/ConstructorHelpers.h"


#include "MyFPSHwGameMode.h"
#include "MyFPSHwCharacter.h"
#include "MyCube.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "GameFramework\PlayerController.h"
#include "GameFramework\PlayerState.h"
#include "GameFramework\GameState.h"
#include "UObject/ConstructorHelpers.h"

//AMyFPSHwGameMode::AMyFPSHwGameMode()
//	: Super()
//{
//	// set default pawn class to our Blueprinted character
//	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
//	DefaultPawnClass = PlayerPawnClassFinder.Class;
//
//}


AMyFPSHwGameMode::AMyFPSHwGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
	//DefaultPawnClass = AMyFPSHwCharacter::StaticClass();
	PlayerControllerClass = APlayerController::StaticClass();
	PlayerStateClass = APlayerState::StaticClass();
	GameStateClass = AGameStateBase::StaticClass();
	/*if(HUDWidget == nullptr)
	{
		FStringClassReference HudWidgetClassRef(TEXT("widgetBlueprint'/Game/OneFirst/Menu/HUD.HUD_C'"));
		UClass* HudWidgetClass = HudWidgetClass.TryLoadClass<UUserWidget>();
		if (HudWidgetClass)
		{
			HUDWidget = CreateWidget<UMyUserWidget>(GetWorld(), HudWidgetClass);
			if (HUDWidget)
			{
				HUDWidget->AddToViewport();
			}
		}
	}*/

	

}

void AMyFPSHwGameMode::BeginPlay()
{
	Super::BeginPlay();
	//InitCubeForPlayers();
	FString MapName = GetWorld()->GetMapName();
	UE_LOG(LogTemp, Warning, TEXT("%s"),*MapName);
	if (MapName == TEXT("UEDPIE_0_FirstPersonMap")) {
		UE_LOG(LogTemp, Log, TEXT("2"));
		CurrentTime = TotalTime;
		GetWorldTimerManager().SetTimer(CountdownTimerHandlle, this, &AMyFPSHwGameMode::UpdateCountdown, 1.0f, true);
	} else {
		UE_LOG(LogTemp, Log, TEXT("3"));
		// 如果不是map1，则确保计时器被清除
		GetWorldTimerManager().ClearTimer(CountdownTimerHandlle);
	};

}




void  AMyFPSHwGameMode::UpdateCountdown() {
	
	if (CurrentTime > 0) {
		CurrentTime--;
		//HUDWidget->UpdateTime(CurrentTime)/*;*/
		UE_LOG(LogTemp, Log, TEXT("%d seconds remaining!"), CurrentTime);
	}
	else {
		GetWorldTimerManager().ClearTimer(CountdownTimerHandlle);
		/*HUDWidget->UpdateTime(CurrentTime);*/
		GameOver();
	}
}

void AMyFPSHwGameMode::GameOver()
{
	UE_LOG(LogTemp, Log, TEXT("Game Over!"));
	for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator();Iterator;++Iterator) {
		APlayerController* PlayerController = Iterator->Get();
		if (PlayerController) {
			APlayerState* PlayerState = PlayerController->PlayerState;
			if (PlayerState) {
				float Scores = PlayerState->Score;
				
				UE_LOG(LogTemp, Log, TEXT("scores:%f"), Scores);
			}
		}
	}
}






