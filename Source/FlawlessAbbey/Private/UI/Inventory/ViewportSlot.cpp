#include "UI/Inventory/ViewportSlot.h"
#include "UI/Inventory/ViewportPanel.h"
#include "UI/Inventory/Inventory.h"
#include "UI/Inventory/ItemIcon.h"

#include "Inventory/ItemData.h"
#include "Inventory/ItemData3D.h"
#include "Inventory/InventoryComponent.h"
#include "Inventory/ViewportPreview.h"

#include "Player/FlawlessAbbeyCharacter.h"

#include <Blueprint/DragDropOperation.h>

void UViewportSlot::NativeConstruct() {

	Super::NativeConstruct();

	icon->SetSlot(this);
	icon->UpdateWidget();

}

void UViewportSlot::SetItem(UItemData* item) {

	UInventorySlot::SetItem(item);

	// Get the things

	TObjectPtr<AFlawlessAbbeyCharacter> character = Cast<AFlawlessAbbeyCharacter>(GetOwningPlayer()->GetCharacter());
	if (character == nullptr) return;

	TObjectPtr<UInventory> inventoryUI = Cast<UInventory>(character->GetInventoryComponent()->GetUI());
	if (inventoryUI == nullptr) return;

	TObjectPtr<UViewportPanel> viewport = Cast<UViewportPanel>(inventoryUI->GetViewportPanel());
	if (viewport == nullptr) return;

	// Implementation

	if (item == nullptr) {

		viewport->SetTexture(nullptr);
		return;

	}

	TObjectPtr<UItemData3D> item3D = Cast<UItemData3D>(item);
	if (item3D != nullptr) {

		TObjectPtr<AViewportPreview> viewportPreview = Cast<AViewportPreview>(character->GetInventoryComponent()->GetViewportPreview());
		if (viewportPreview == nullptr) return;

		viewportPreview->SetMesh(item3D->mesh);
		viewport->SetMaterial(viewportPreview->GetOutputMaterial());

		return;

	}

	viewport->SetTexture(item->icon);

}

bool UViewportSlot::NativeOnDrop(const FGeometry& geometry, const FDragDropEvent& event, UDragDropOperation* operation) {

	if (m_item != nullptr) return false;

	TObjectPtr<UItemData> item = Cast<UItemData>(operation->Payload);
	if (item == nullptr) return false;

	SetItem(item);

	return true;

}
