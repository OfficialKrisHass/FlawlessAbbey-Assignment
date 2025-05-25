#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemPickup.generated.h"

class UItemData;

class UStaticMeshComponent;
class UBoxComponent;

UCLASS(Abstract)
class FLAWLESSABBEY_API AItemPickup : public AActor {

	GENERATED_BODY()

public:
	AItemPickup();

private:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> mesh = nullptr;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UBoxComponent> trigger = nullptr;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UItemData> item = nullptr;

	virtual void BeginPlay() override;

	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* overlapedComponent, AActor* actor, UPrimitiveComponent* otherComponent, int32 otherIndex, bool fromSweep, const FHitResult& sweepResult);

};