#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class UItemData;
struct FItemSlot;

class UInventory;

class AViewportPreview;

class UInputMappingContext;
class UInputAction;

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
	inline AViewportPreview* GetViewportPreview() const { return m_viewportPreview; }

private:
	UPROPERTY(EditDefaultsOnly)
	TArray<FItemSlot> m_slots;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> closeAction = nullptr;
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> inventoryMappingContext = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Viewport preview")
	TSubclassOf<AViewportPreview> viewportPreviewClass;
	UPROPERTY(EditAnywhere, Category = "Viewport preview")
	FVector viewportPreviewLocation;

	UPROPERTY()
	TObjectPtr<UInventory> m_inventoryUI = nullptr;
	UPROPERTY()
	TObjectPtr<AViewportPreview> m_viewportPreview = nullptr;

	virtual void BeginPlay() override;
	
};