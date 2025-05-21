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

		if (m_inventoryUI != nullptr)
			m_inventoryUI->OnInventoryUpdated(m_slots);

		return true;

	}

	return false;

}

void UInventoryComponent::RemoveItem(UItemData* item) {

	if (item == nullptr) return;

	for (FItemSlot& slot : m_slots) {

		if (slot.item.Get() != item) continue;
		slot.item = nullptr;

		if (m_inventoryUI != nullptr)
			m_inventoryUI->OnInventoryUpdated(m_slots);

		return;

	}

}