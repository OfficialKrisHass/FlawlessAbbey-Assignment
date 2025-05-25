#include "UI/Inventory/Inventory.h"
#include "UI/Inventory/InventorySlot.h"
#include "UI/Inventory/ViewportSlot.h"

#include "Player/FlawlessAbbeyPlayerController.h"

#include "Inventory/ItemSlot.h"

#include <Components/CanvasPanel.h>
#include <Components/HorizontalBox.h>
#include <Components/Button.h>

void UInventory::NativeConstruct() {

	Super::NativeConstruct();

    m_slots.Add(slot0);
    m_slots.Add(slot1);
    m_slots.Add(slot2);
    m_slots.Add(slot3);

    for (uint32 i = 0; i < 4; i++)
        m_slots[i]->SetIndex(i);

    viewportSlot->SetIndex(4);

    closeButton->OnClicked.AddDynamic(this, &UInventory::CloseInventory);

}

void UInventory::Update(const TArray<FItemSlot>& slots) {

    for (int32 i = 0; i < slots.Num(); i++)
        m_slots[i]->SetItem(slots[i].item);

}

void UInventory::OpenInventory() {

    if (!IsInViewport())
        AddToViewport();

    SetVisibility(ESlateVisibility::Visible);

}
void UInventory::CloseInventory() {

    SetVisibility(ESlateVisibility::Hidden);

}