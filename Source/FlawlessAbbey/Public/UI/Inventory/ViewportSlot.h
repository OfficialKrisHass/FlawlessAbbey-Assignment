#pragma once

#include "CoreMinimal.h"
#include "UI/Inventory/InventorySlot.h"
#include "ViewportSlot.generated.h"

class UItemData;

UCLASS(Abstract)
class FLAWLESSABBEY_API UViewportSlot : public UInventorySlot {

	GENERATED_BODY()

public:
	virtual void SetItem(UItemData* item) override;

protected:
	virtual void NativeConstruct() override;

};
