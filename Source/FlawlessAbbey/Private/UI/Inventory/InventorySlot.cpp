#include "UI/Inventory/InventorySlot.h"
#include "UI/Inventory/ItemIcon.h"

#include "Inventory/ItemData.h"
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

	TObjectPtr<UDragPayload> payload = Cast<UDragPayload>(operation->Payload);
	if (payload == nullptr) return false;

	TObjectPtr<AFlawlessAbbeyCharacter> character = Cast<AFlawlessAbbeyCharacter>(GetOwningPlayer()->GetCharacter());
	if (character == nullptr) return false;

	if (m_item != nullptr) {

		payload->slot->SetItem(m_item);
		character->GetInventoryComponent()->AddItemToSlot(m_item, payload->slot->m_index);
		character->GetInventoryComponent()->RemoveItemFromSlot(m_index);

	}

	SetItem(payload->item);
	character->GetInventoryComponent()->AddItemToSlot(payload->item, m_index);

	return true;

}