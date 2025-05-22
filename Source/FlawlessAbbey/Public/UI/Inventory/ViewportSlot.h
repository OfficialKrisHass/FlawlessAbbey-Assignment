#pragma once

#include "CoreMinimal.h"
#include "UI/Inventory/InventorySlot.h"
#include "ViewportSlot.generated.h"

UCLASS(Abstract)
class FLAWLESSABBEY_API UViewportSlot : public UInventorySlot {

	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	virtual bool NativeOnDrop(const FGeometry& geometry, const FDragDropEvent& event, UDragDropOperation* operation) override;

};
