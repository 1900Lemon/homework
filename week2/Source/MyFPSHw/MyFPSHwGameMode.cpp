// Copyright Epic Games, Inc. All Rights Reserved.

//#include "MyFPSHwGameMode.h"
//#include "MyFPSHwCharacter.h"
//#include "UObject/ConstructorHelpers.h"


#include "MyFPSHwGameMode.h"
#include "MyFPSHwCharacter.h"
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

	PlayerControllerClass = APlayerController::StaticClass();
	PlayerStateClass = APlayerState::StaticClass();
	GameStateClass = AGameStateBase::StaticClass();



}

void AMyFPSHwGameMode::BeginPlay()
{
	Super::BeginPlay();
	CurrentTime = TotalTime;
	GetWorldTimerManager().SetTimer(CountdownTimerHandlle, this, &AMyFPSHwGameMode::UpdateCountdown, 1.0f, true);

}



void  AMyFPSHwGameMode::UpdateCountdown() {
	if (CurrentTime > 0) {
		CurrentTime--;
		UE_LOG(LogTemp, Log, TEXT("%d seconds remaining!"), CurrentTime);
	}
	else {
		GetWorldTimerManager().ClearTimer(CountdownTimerHandlle);
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




