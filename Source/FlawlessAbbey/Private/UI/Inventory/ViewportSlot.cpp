#include "UI/Inventory/ViewportSlot.h"
#include "UI/Inventory/ItemIcon.h"

#include "Inventory/Item.h"

#include <Blueprint/DragDropOperation.h>

void UViewportSlot::NativeConstruct() {

	Super::NativeConstruct();

	icon->SetSlot(this);
	icon->UpdateWidget();

}

bool UViewportSlot::NativeOnDrop(const FGeometry& geometry, const FDragDropEvent& event, UDragDropOperation* operation) {

	if (m_item != nullptr) return false;

	TObjectPtr<UItemData> item = Cast<UItemData>(operation->Payload);
	if (item == nullptr) return false;

	m_item = item;
	icon->UpdateWidget();

	return true;

}
