// Copyright Epic Games, Inc. All Rights Reserved.

#include <Player/FlawlessAbbeyPlayerController.h>

#include <Engine/LocalPlayer.h>

#include <EnhancedInputSubsystems.h>

void AFlawlessAbbeyPlayerController::BeginPlay() {

	Super::BeginPlay();

	m_inputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (m_inputSubsystem == nullptr) return;

	m_inputSubsystem->AddMappingContext(defaultMappingContext, 0);
	m_inputSubsystem->AddMappingContext(uiMappingContext, 1);

}

void AFlawlessAbbeyPlayerController::EnableMovement() {

	m_inputSubsystem->AddMappingContext(defaultMappingContext, 0);

}

void AFlawlessAbbeyPlayerController::DisableMovement() {

	m_inputSubsystem->RemoveMappingContext(defaultMappingContext);

}