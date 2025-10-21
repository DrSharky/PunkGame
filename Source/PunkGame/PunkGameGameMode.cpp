// Copyright Epic Games, Inc. All Rights Reserved.

#include "PunkGameGameMode.h"
#include "PunkGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

APunkGameGameMode::APunkGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
