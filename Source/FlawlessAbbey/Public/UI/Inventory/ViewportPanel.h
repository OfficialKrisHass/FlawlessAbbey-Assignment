#pragma once

#include "CoreMinimal.h"
#include "UI/UserWidgetBase.h"
#include "ViewportPanel.generated.h"

class AFlawlessAbbeyCharacter;

class UImage;

UCLASS(Abstract)
class FLAWLESSABBEY_API UViewportPanel : public UUserWidgetBase {

	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetTexture(UTexture2D* texture);

	UFUNCTION(BlueprintCallable)
	void SetMaterial(UMaterialInterface* material);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Widgets", meta = (BindWidget))
	TObjectPtr<UImage> viewport = nullptr;

	virtual void NativeConstruct() override;

	virtual FReply NativeOnMouseMove(const FGeometry& geometry, const FPointerEvent& event) override;
	virtual FReply NativeOnMouseButtonDown(const FGeometry& geometry, const FPointerEvent& event) override;
	virtual FReply NativeOnMouseButtonUp(const FGeometry& geometry, const FPointerEvent& event) override;

	virtual FReply NativeOnMouseWheel(const FGeometry& geometry, const FPointerEvent& event) override;

private:
	bool m_dragging = false;

	UPROPERTY()
	TObjectPtr<AFlawlessAbbeyCharacter> m_character = nullptr;
	
};
