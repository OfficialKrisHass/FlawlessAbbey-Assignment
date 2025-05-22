// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FlawlessAbbeyPlayerController.generated.h"

class UEnhancedInputLocalPlayerSubsystem;

class UInputMappingContext;

UCLASS()
class FLAWLESSABBEY_API AFlawlessAbbeyPlayerController : public APlayerController {

	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void EnableMovement();
	UFUNCTION(BlueprintCallable)
	void DisableMovement();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* defaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* uiMappingContext;

	virtual void BeginPlay() override;

private:
	UPROPERTY()
	TObjectPtr<UEnhancedInputLocalPlayerSubsystem> m_inputSubsystem = nullptr;


};