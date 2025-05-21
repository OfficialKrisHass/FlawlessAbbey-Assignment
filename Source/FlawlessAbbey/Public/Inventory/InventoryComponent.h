#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class UItemData;
struct FItemSlot;

class UInventory;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FLAWLESSABBEY_API UInventoryComponent : public UActorComponent {

	GENERATED_BODY()

public:
	UInventoryComponent();

	UFUNCTION(BlueprintCallable)
	void OpenInventory();

	UFUNCTION(BlueprintCallable)
	void CloseInventory();

	UFUNCTION(BlueprintCallable)
	bool AddItem(UItemData* item);

	UFUNCTION(BlueprintCallable)
	void RemoveItem(UItemData* item);

	UFUNCTION(BlueprintCallable)
	void BindUI(UInventory* inventoryUI) { m_inventoryUI = inventoryUI; }

private:
	UPROPERTY(EditDefaultsOnly) TArray<FItemSlot> m_slots;
	UPROPERTY() TObjectPtr<UInventory> m_inventoryUI = nullptr;

	virtual void BeginPlay() override;
	
};