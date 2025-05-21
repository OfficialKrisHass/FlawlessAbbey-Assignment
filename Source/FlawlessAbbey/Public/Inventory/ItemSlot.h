#pragma once

#include "CoreMinimal.h"
#include "ItemSlot.generated.h"

class UItemData;

USTRUCT()
struct FLAWLESSABBEY_API FItemSlot {

	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere) TObjectPtr<UItemData> item = nullptr;

};
