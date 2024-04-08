// Copyright Epic Games, Inc. All Rights Reserved.

#include "YellowManGameMode.h"
#include "YellowManCharacter.h"
#include "UObject/ConstructorHelpers.h"

AYellowManGameMode::AYellowManGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
