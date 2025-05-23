#include "UI/Inventory/ViewportSlot.h"
#include "UI/Inventory/ViewportPanel.h"
#include "UI/Inventory/Inventory.h"
#include "UI/Inventory/ItemIcon.h"

#include "Inventory/Item.h"
#include "Inventory/InventoryComponent.h"

#include "Player/FlawlessAbbeyCharacter.h"

#include <Blueprint/DragDropOperation.h>

void UViewportSlot::NativeConstruct() {

	Super::NativeConstruct();

	icon->SetSlot(this);
	icon->UpdateWidget();

}

void UViewportSlot::SetItem(UItemData* item) {

	UInventorySlot::SetItem(item);

	TObjectPtr<AFlawlessAbbeyCharacter> character = Cast<AFlawlessAbbeyCharacter>(GetOwningPlayer()->GetCharacter());
	if (character == nullptr) return;

	TObjectPtr<UInventory> inventoryUI = Cast<UInventory>(character->GetInventoryComponent()->GetUI());
	if (inventoryUI == nullptr) return;

	TObjectPtr<UViewportPanel> viewport = Cast<UViewportPanel>(inventoryUI->GetViewportPanel());
	if (viewport == nullptr) return;

	if (item != nullptr)
		viewport->SetTexture(item->icon);
	else
		viewport->SetTexture(nullptr);

}

bool UViewportSlot::NativeOnDrop(const FGeometry& geometry, const FDragDropEvent& event, UDragDropOperation* operation) {

	if (m_item != nullptr) return false;

	TObjectPtr<UItemData> item = Cast<UItemData>(operation->Payload);
	if (item == nullptr) return false;

	SetItem(item);

	return true;

}
