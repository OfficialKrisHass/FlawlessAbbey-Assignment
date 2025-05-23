#pragma once

#include "CoreMinimal.h"
#include "UI/UserWidgetBase.h"
#include "ViewportPanel.generated.h"

class UImage;

UCLASS(Abstract)
class FLAWLESSABBEY_API UViewportPanel : public UUserWidgetBase {

	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetTexture(UTexture2D* texture);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Widgets", meta = (BindWidget))
	TObjectPtr<UImage> viewport = nullptr;
	
};
