// Copyright Epic Games, Inc. All Rights Reserved.

#include "Player/FlawlessAbbeyCharacter.h"
#include "Player/Interactible.h"

#include "Inventory/InventoryComponent.h"

#include "Dialogue/DialogueManagerComponent.h"

#include <Engine/LocalPlayer.h>

#include <Components/CapsuleComponent.h>
#include <Components/SkeletalMeshComponent.h>

#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>
#include <InputActionValue.h>

#include <Camera/CameraComponent.h>

#include <Animation/AnimInstance.h>

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

AFlawlessAbbeyCharacter::AFlawlessAbbeyCharacter() {

	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);
		
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	Mesh1P->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));

	m_inventory = CreateDefaultSubobject<UInventoryComponent>(TEXT("Inventory"));

	m_dialogueManager = CreateDefaultSubobject<UDialogueManagerComponent>(TEXT("Dialogue manager"));

}

void AFlawlessAbbeyCharacter::BeginPlay() {

	Super::BeginPlay();

}

void AFlawlessAbbeyCharacter::Move(const FInputActionValue& Value) {
	
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller == nullptr) return;
	
	AddMovementInput(GetActorForwardVector(), MovementVector.Y);
	AddMovementInput(GetActorRightVector(), MovementVector.X);

}

void AFlawlessAbbeyCharacter::Look(const FInputActionValue& Value) {

	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller == nullptr) return;
	
	AddControllerYawInput(LookAxisVector.X);
	AddControllerPitchInput(LookAxisVector.Y);
	
}

void AFlawlessAbbeyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AFlawlessAbbeyCharacter::Move);

		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AFlawlessAbbeyCharacter::Look);

		EnhancedInputComponent->BindAction(interactAction, ETriggerEvent::Triggered, this, &AFlawlessAbbeyCharacter::Interact);

		EnhancedInputComponent->BindAction(openInventoryAction, ETriggerEvent::Triggered, m_inventory.Get(), &UInventoryComponent::OpenInventory);
	
	} else
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));

}

void AFlawlessAbbeyCharacter::Interact() {

	if (overlappingInteractible == nullptr) return;

	overlappingInteractible->Interact(this);

}

void AFlawlessAbbeyCharacter::NotifyActorBeginOverlap(AActor* other) {

	overlappingInteractible = Cast<AInteractible>(other);

}

void AFlawlessAbbeyCharacter::NotifyActorEndOverlap(AActor* other) {

	if (overlappingInteractible != other) return;

	overlappingInteractible = nullptr;

}