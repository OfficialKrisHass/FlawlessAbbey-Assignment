#include "UI/Inventory/InventorySlot.h"
#include "UI/Inventory/ItemIcon.h"

#include "Inventory/Item.h"
#include "Inventory/InventoryComponent.h"

#include "Player/FlawlessAbbeyCharacter.h"

#include <Blueprint/DragDropOperation.h>

void UInventorySlot::NativeConstruct() {

	Super::NativeConstruct();

	icon->SetSlot(this);
	icon->UpdateWidget();

}

void UInventorySlot::SetItem(UItemData* item) {

	m_item = item;
	icon->UpdateWidget();

}

bool UInventorySlot::NativeOnDrop(const FGeometry& geometry, const FDragDropEvent& event, UDragDropOperation* operation) {

	if (m_item != nullptr) return false;

	TObjectPtr<UItemData> item = Cast<UItemData>(operation->Payload);
	if (item == nullptr) return false;

	m_item = item;
	icon->UpdateWidget();

	TObjectPtr<AFlawlessAbbeyCharacter> character = Cast<AFlawlessAbbeyCharacter>(GetOwningPlayer()->GetCharacter());
	if (character == nullptr) return false;

	character->GetInventoryComponent()->AddItemToSlot(item, m_index);

	return true;

}