// Copyright Epic Games, Inc. All Rights Reserved.

#include "myPrjGameMode.h"
#include "myPrjCharacter.h"
#include "UObject/ConstructorHelpers.h"

AmyPrjGameMode::AmyPrjGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
