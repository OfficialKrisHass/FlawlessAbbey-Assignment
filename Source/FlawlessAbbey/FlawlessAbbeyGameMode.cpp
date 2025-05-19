// Copyright Epic Games, Inc. All Rights Reserved.

#include "FlawlessAbbeyGameMode.h"
#include "FlawlessAbbeyCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFlawlessAbbeyGameMode::AFlawlessAbbeyGameMode() : Super() {
	
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}