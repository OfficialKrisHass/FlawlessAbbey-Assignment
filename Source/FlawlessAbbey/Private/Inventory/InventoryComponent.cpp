#include "Inventory/InventoryComponent.h"
#include "Inventory/Item.h"
#include "Inventory/ItemSlot.h"

#include "UI/Inventory/Inventory.h"

UInventoryComponent::UInventoryComponent() {
	
	PrimaryComponentTick.bCanEverTick = false;

	m_slots.SetNum(4);

}

void UInventoryComponent::BeginPlay() {

	Super::BeginPlay();
	
}

void UInventoryComponent::OpenInventory() {

	m_inventoryUI->OpenInventory();

}

void UInventoryComponent::CloseInventory() {

	m_inventoryUI->CloseInventory();

}

bool UInventoryComponent::AddItem(UItemData* item) {

	for (FItemSlot& slot : m_slots) {

		if (slot.item != nullptr) continue;
		slot.item = item;

		return true;

	}

	return false;

}
void UInventoryComponent::RemoveItem(UItemData* item) {

	if (item == nullptr) return;

	for (FItemSlot& slot : m_slots) {

		if (slot.item.Get() != item) continue;
		slot.item = nullptr;

		return;

	}

}

bool UInventoryComponent::AddItemToSlot(UItemData* item, int32 slotIndex) {

	if (slotIndex > 3) return false;

	FItemSlot& slot = m_slots[slotIndex];
	if (slot.item != nullptr) return false;

	slot.item = item;

	return true;

}
void UInventoryComponent::RemoveItemFromSlot(int32 slotIndex) {

	if (slotIndex > 3) return;

	FItemSlot& slot = m_slots[slotIndex];
	if (slot.item == nullptr) return;

	slot.item = nullptr;

}

void UInventoryComponent::UpdateInventoryUI() {

	m_inventoryUI->Update(m_slots);

}