#pragma once

#include "CoreMinimal.h"
#include "UI/UserWidgetBase.h"
#include "InventorySlot.generated.h"

class UButton;
class UImage;

class UItemData;

UCLASS()
class FLAWLESSABBEY_API UInventorySlot : public UUserWidgetBase {

	GENERATED_BODY()

public:
	void SetItem(TObjectPtr<UItemData> item);

#if WITH_EDITOR
	virtual void OnDesignerChanged(const FDesignerChangedEventArgs& EventArgs) override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Widgets", meta = (BindWidget))
	TObjectPtr<UButton> button = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Widgets", meta = (BindWidget))
	TObjectPtr<UImage> icon = nullptr;

	virtual void NativeOnInitialized() override;

private:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UItemData> m_item = nullptr;

	void UpdateWidget();
	
};