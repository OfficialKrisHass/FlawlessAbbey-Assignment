// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "FlawlessAbbeyCharacter.generated.h"

class AInteractible;

class UInventoryComponent;
class UDialogueManagerComponent;

class UInputComponent;
class USkeletalMeshComponent;
class UCameraComponent;

class UInputAction;
class UInputMappingContext;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class AFlawlessAbbeyCharacter : public ACharacter {

	GENERATED_BODY()

public:
	AFlawlessAbbeyCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

	USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

	TObjectPtr<UInventoryComponent> GetInventoryComponent() const { return m_inventory; }

	TObjectPtr<UDialogueManagerComponent> GetDialogueManagerComponent() const { return m_dialogueManager; }

protected:
	virtual void BeginPlay();

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Mesh, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> Mesh1P;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> FirstPersonCameraComponent;

	UPROPERTY(VisibleAnywhere, Category = "Inventory")
	TObjectPtr<UInventoryComponent> m_inventory = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Dialogue")
	TObjectPtr<UDialogueManagerComponent> m_dialogueManager = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* JumpAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> interactAction = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> openInventoryAction = nullptr;

	UPROPERTY()
	TObjectPtr<AInteractible> overlappingInteractible = nullptr;

	void Interact();

	virtual void NotifyActorBeginOverlap(AActor* other) override;
	virtual void NotifyActorEndOverlap(AActor* other) override;

};