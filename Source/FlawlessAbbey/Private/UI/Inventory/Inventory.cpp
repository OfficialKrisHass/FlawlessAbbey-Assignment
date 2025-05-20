#include "UI/Inventory/Inventory.h"

#include <Components/TextBlock.h>

void UInventory::NativeOnInitialized() {

	Super::NativeOnInitialized();

    m_slots.Add(slot0);
    m_slots.Add(slot1);
    m_slots.Add(slot2);
    m_slots.Add(slot3);
    
	UpdateWidget();

}

void UInventory::UpdateWidget() {

    //

}

#ifdef WITH_EDITOR
void UInventory::OnDesignerChanged(const FDesignerChangedEventArgs& args) {

    Super::OnDesignerChanged(args);

    UpdateWidget();

}
void UInventory::PostEditChangeProperty(FPropertyChangedEvent& event) {

    Super::PostEditChangeProperty(event);

    const FString propName = (event.Property != nullptr) ? event.Property->GetFName().ToString() : TEXT("");
    //if (propName != TEXT("InMag") || propName != TEXT("Mags")) return;

    UpdateWidget();

}
#endif