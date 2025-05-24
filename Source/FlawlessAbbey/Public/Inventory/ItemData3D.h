#pragma once

#include "CoreMinimal.h"
#include "Inventory/ItemData.h"
#include "ItemData3D.generated.h"

UCLASS()
class FLAWLESSABBEY_API UItemData3D : public UItemData {

	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UStaticMesh> mesh = nullptr;
	
};
