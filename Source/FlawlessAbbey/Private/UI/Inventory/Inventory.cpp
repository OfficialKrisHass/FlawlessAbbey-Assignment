#include "UI/Inventory/Inventory.h"
#include "UI/Inventory/InventorySlot.h"

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

    closeButton->OnClicked.AddDynamic(this, &UInventory::CloseInventory);

}

void UInventory::OnInventoryUpdated(const TArray<FItemSlot>& slots) {

    for (int32 i = 0; i < slots.Num(); i++)
        m_slots[i]->SetItem(slots[i].item);

}

void UInventory::CloseInventory() {

    SetVisibility(ESlateVisibility::Hidden);

    TObjectPtr<AFlawlessAbbeyPlayerController> controller = Cast<AFlawlessAbbeyPlayerController>(GetOwningPlayer());
    if (controller == nullptr) return;

    controller->SetShowMouseCursor(false);
    controller->SetInputMode(FInputModeGameOnly());

    controller->EnableMovement();

}
void UInventory::OpenInventory() {

    if (!IsInViewport())
        AddToViewport();

    SetVisibility(ESlateVisibility::Visible);

    TObjectPtr<AFlawlessAbbeyPlayerController> controller = Cast<AFlawlessAbbeyPlayerController>(GetOwningPlayer());
    if (controller == nullptr) return;

    controller->SetShowMouseCursor(true);
    controller->SetInputMode(FInputModeGameAndUI());

    controller->DisableMovement();

}