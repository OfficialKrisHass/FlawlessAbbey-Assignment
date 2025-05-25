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
	inline void EnableDefaultMappingContext() { AddMappingContext(defaultMappingContext, 0); }
	UFUNCTION(BlueprintCallable)
	inline void DisableDefaultMappingContext() { RemoveMappingContext(defaultMappingContext); }

	UFUNCTION(BlueprintCallable)
	void AddMappingContext(UInputMappingContext* context, int32 priority = 1);
	UFUNCTION(BlueprintCallable)
	void RemoveMappingContext(UInputMappingContext* context);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* defaultMappingContext;

	virtual void BeginPlay() override;

private:
	UPROPERTY()
	TObjectPtr<UEnhancedInputLocalPlayerSubsystem> m_inputSubsystem = nullptr;


};