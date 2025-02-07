// Copyright Epic Games, Inc. All Rights Reserved.

#include "GP3_Team06GameMode.h"
#include "GP3_Team06Character.h"
#include "UObject/ConstructorHelpers.h"

AGP3_Team06GameMode::AGP3_Team06GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
