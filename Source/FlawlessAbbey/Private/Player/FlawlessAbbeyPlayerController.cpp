// Copyright Epic Games, Inc. All Rights Reserved.

#include <Player/FlawlessAbbeyPlayerController.h>

#include <Engine/LocalPlayer.h>

#include <EnhancedInputSubsystems.h>

void AFlawlessAbbeyPlayerController::BeginPlay() {

	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		Subsystem->AddMappingContext(InputMappingContext, 0);

}