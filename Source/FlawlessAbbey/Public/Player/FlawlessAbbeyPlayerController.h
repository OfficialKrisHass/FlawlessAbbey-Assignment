// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FlawlessAbbeyPlayerController.generated.h"

class UInputMappingContext;

UCLASS()
class FLAWLESSABBEY_API AFlawlessAbbeyPlayerController : public APlayerController {

	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* InputMappingContext;

	virtual void BeginPlay() override;

};