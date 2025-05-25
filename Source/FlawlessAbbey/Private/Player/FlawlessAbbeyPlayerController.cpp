// Copyright Epic Games, Inc. All Rights Reserved.

#include <Player/FlawlessAbbeyPlayerController.h>

#include <Engine/LocalPlayer.h>

#include <EnhancedInputSubsystems.h>

void AFlawlessAbbeyPlayerController::BeginPlay() {

	Super::BeginPlay();

	m_inputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (m_inputSubsystem == nullptr) return;

	EnableDefaultMappingContext();

}

void AFlawlessAbbeyPlayerController::AddMappingContext(UInputMappingContext* context, int32 priority) {

	if (context == nullptr) return;

	m_inputSubsystem->AddMappingContext(context, priority);

}

void AFlawlessAbbeyPlayerController::RemoveMappingContext(UInputMappingContext* context) {

	if (context == nullptr) return;

	m_inputSubsystem->RemoveMappingContext(context);

}