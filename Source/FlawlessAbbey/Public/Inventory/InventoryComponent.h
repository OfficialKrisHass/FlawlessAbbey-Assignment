#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class UItemData;
struct FItemSlot;

class UInventory;

class AViewportPreview;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FLAWLESSABBEY_API UInventoryComponent : public UActorComponent {

	GENERATED_BODY()

public:
	UInventoryComponent();

	// UI

	UFUNCTION(BlueprintCallable)
	void OpenInventory();
	UFUNCTION(BlueprintCallable)
	void CloseInventory();

	UFUNCTION(BlueprintCallable)
	void UpdateInventoryUI();

	UFUNCTION(BlueprintCallable)
	inline void BindUI(UInventory* inventoryUI) { m_inventoryUI = inventoryUI; }

	UFUNCTION(BlueprintCallable)
	inline UInventory* GetUI() const { return m_inventoryUI; }

	// Inventory

	UFUNCTION(BlueprintCallable)
	bool AddItem(UItemData* item);
	UFUNCTION(BlueprintCallable)
	void RemoveItem(UItemData* item);

	UFUNCTION(BlueprintCallable)
	bool AddItemToSlot(UItemData* item, int32 slotIndex);
	UFUNCTION(BlueprintCallable)
	void RemoveItemFromSlot(int32 slotIndex);

	// Preview

	UFUNCTION(BlueprintCallable)
	void PreviewItem(UItemData* item);

private:
	UPROPERTY(EditDefaultsOnly) TArray<FItemSlot> m_slots;
	UPROPERTY() TObjectPtr<UInventory> m_inventoryUI = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Viewport preview")
	TSubclassOf<AViewportPreview> viewportPreviewClass;
	UPROPERTY(EditAnywhere, Category = "Viewport preview")
	FVector viewportPreviewLocation;

	UPROPERTY()
	TObjectPtr<AViewportPreview> m_viewportPreview = nullptr;

	virtual void BeginPlay() override;
	
};