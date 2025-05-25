#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactible.generated.h"

class AFlawlessAbbeyCharacter;

class UBoxComponent;

UCLASS(Abstract)
class FLAWLESSABBEY_API AInteractible : public AActor {

	GENERATED_BODY()
	
public:
	AInteractible();

	UFUNCTION(BlueprintCallable)
	virtual void Interact(AFlawlessAbbeyCharacter* character) {}

protected:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> mesh = nullptr;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UBoxComponent> trigger = nullptr;

private:
	virtual void BeginPlay() override;
	
};