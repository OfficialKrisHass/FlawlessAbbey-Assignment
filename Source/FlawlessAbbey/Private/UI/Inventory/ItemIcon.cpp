#include "UI/Inventory/ItemIcon.h"
#include "UI/Inventory/InventorySlot.h"

#include "Inventory/ItemData.h"
#include "Inventory/InventoryComponent.h"

#include "Player/FlawlessAbbeyCharacter.h"

#include <Components/Image.h>

#include <Blueprint/WidgetBlueprintLibrary.h>

void UItemIcon::UpdateWidget() {

	SetIcon(m_slot->GetItem());

}
void UItemIcon::SetIcon(UItemData* item) {

	if (item != nullptr) {

		icon->SetBrushFromTexture(item->icon);
		icon->SetOpacity(1.0f);

	}
	else {

		icon->SetBrushFromTexture(nullptr);
		icon->SetOpacity(0.0f);

	}

}

FReply UItemIcon::NativeOnMouseButtonDown(const FGeometry& geometry, const FPointerEvent& mouseEvent) {

	if (!mouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton)) return Super::NativeOnMouseButtonDown(geometry, mouseEvent);

	return UWidgetBlueprintLibrary::DetectDragIfPressed(mouseEvent, this, EKeys::LeftMouseButton).NativeReply;

}
void UItemIcon::NativeOnDragDetected(const FGeometry& geometry, const FPointerEvent& mouseEvent, UDragDropOperation*& outOperation) {

	TObjectPtr<UDragDropOperation> operation = NewObject<UDragDropOperation>();
	TObjectPtr<UItemIcon> visual = CreateWidget<UItemIcon>(GetOwningPlayer(), GetClass());

	if (visual == nullptr) return;
	visual->SetIcon(m_slot->GetItem());

	TObjectPtr<UDragPayload> payload = NewObject<UDragPayload>();
	payload->item = m_slot->GetItem();
	payload->slot = m_slot;

	operation->Payload = Cast<UObject>(payload);
	operation->DefaultDragVisual = visual;
	operation->OnDragCancelled.AddDynamic(this, &UItemIcon::HandleDragCancelled);
	outOperation = operation;

	m_slot->SetItem(nullptr);

	TObjectPtr<AFlawlessAbbeyCharacter> character = Cast<AFlawlessAbbeyCharacter>(GetOwningPlayer()->GetCharacter());
	if (character == nullptr) return;

	character->GetInventoryComponent()->RemoveItemFromSlot(m_slot->GetIndex());

}

void UItemIcon::HandleDragCancelled(UDragDropOperation* operation) {

	TObjectPtr<UDragPayload> payload = Cast<UDragPayload>(operation->Payload);
	if (payload == nullptr) return;

	TObjectPtr<AFlawlessAbbeyCharacter> character = Cast<AFlawlessAbbeyCharacter>(GetOwningPlayer()->GetCharacter());
	if (character == nullptr) return;

	payload->slot->SetItem(payload->item);
	character->GetInventoryComponent()->AddItemToSlot(payload->item, payload->slot->GetIndex());

}