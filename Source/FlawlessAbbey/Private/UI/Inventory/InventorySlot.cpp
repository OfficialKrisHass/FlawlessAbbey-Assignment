#include "UI/Inventory/InventorySlot.h"

#include "Inventory/Item.h"

#include <Components/Button.h>
#include <Components/Image.h>

void UInventorySlot::NativeOnInitialized() {

	Super::NativeOnInitialized();

	UpdateWidget();

}

void UInventorySlot::UpdateWidget() {

	if (icon == nullptr) return;

	if (m_item != nullptr) {

		icon->SetBrushFromTexture(m_item->icon);
		icon->SetOpacity(1.0f);

	}
	else {

		icon->SetBrushFromTexture(nullptr);
		icon->SetOpacity(0.0f);

	}

}

void UInventorySlot::SetItem(TObjectPtr<UItemData> item) {

	if (m_item == item) return;

	m_item = item;
	UpdateWidget();

}

#ifdef WITH_EDITOR
void UInventorySlot::OnDesignerChanged(const FDesignerChangedEventArgs& args) {

	Super::OnDesignerChanged(args);

	UpdateWidget();

}
void UInventorySlot::PostEditChangeProperty(FPropertyChangedEvent& event) {

	Super::PostEditChangeProperty(event);

	UpdateWidget();

}
#endif