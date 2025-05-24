#include "UI/Inventory/ViewportPanel.h"

#include "Player/FlawlessAbbeyCharacter.h"

#include "Inventory/InventoryComponent.h"
#include "Inventory/ViewportPreview.h"

#include <Components/Image.h>

void UViewportPanel::NativeConstruct() {

	Super::NativeConstruct();

	m_character = Cast<AFlawlessAbbeyCharacter>(GetOwningPlayer()->GetCharacter());
	if (m_character == nullptr) return;

}

void UViewportPanel::SetTexture(UTexture2D* texture) {

	if (texture != nullptr) {

		viewport->SetBrushFromTexture(texture);
		viewport->SetOpacity(1.0f);

	}
	else {

		// SetBrushFromMaterial is slightly simpler and faster

		viewport->SetBrushFromMaterial(nullptr);
		viewport->SetOpacity(0.0f);

	}

}

void UViewportPanel::SetMaterial(UMaterialInterface* material) {

	if (material != nullptr) {

		viewport->SetBrushFromMaterial(material);
		viewport->SetOpacity(1.0f);

	}
	else {

		viewport->SetBrushFromMaterial(nullptr);
		viewport->SetOpacity(0.0f);

	}

}

FReply UViewportPanel::NativeOnMouseMove(const FGeometry& geometry, const FPointerEvent& event) {

	if (!m_dragging) return FReply::Unhandled();

	TObjectPtr<AViewportPreview> viewportPreview = m_character->GetInventoryComponent()->GetViewportPreview();
	if (viewportPreview == nullptr) return FReply::Unhandled();

	viewportPreview->Rotate(event.GetLastScreenSpacePosition() - event.GetScreenSpacePosition());
	return FReply::Handled();

}

FReply UViewportPanel::NativeOnMouseButtonDown(const FGeometry& geometry, const FPointerEvent& event) {

	if (event.GetEffectingButton() != EKeys::LeftMouseButton) return FReply::Unhandled();

	m_dragging = true;
	return FReply::Handled().CaptureMouse(TakeWidget());

}
FReply UViewportPanel::NativeOnMouseButtonUp(const FGeometry& geometry, const FPointerEvent& event) {

	if (event.GetEffectingButton() != EKeys::LeftMouseButton) return FReply::Unhandled();

	m_dragging = false;
	return FReply::Handled().ReleaseMouseCapture();

}

FReply UViewportPanel::NativeOnMouseWheel(const FGeometry& geometry, const FPointerEvent& event) {

	TObjectPtr<AViewportPreview> viewportPreview = m_character->GetInventoryComponent()->GetViewportPreview();
	if (viewportPreview == nullptr) return FReply::Unhandled();

	viewportPreview->Zoom(event.GetWheelDelta());

	return FReply::Handled();

}