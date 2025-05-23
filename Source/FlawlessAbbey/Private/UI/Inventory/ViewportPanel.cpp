#include "UI/Inventory/ViewportPanel.h"

#include <Components/Image.h>

void UViewportPanel::SetTexture(UTexture2D* texture) {

	if (texture != nullptr) {

		viewport->SetBrushFromTexture(texture);
		viewport->SetOpacity(1.0f);

	}
	else {

		viewport->SetBrushFromTexture(nullptr);
		viewport->SetOpacity(0.0f);

	}

}