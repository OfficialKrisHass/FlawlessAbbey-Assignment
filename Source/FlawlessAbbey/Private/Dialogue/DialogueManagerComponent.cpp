#include "Dialogue/DialogueManagerComponent.h"
#include "Dialogue/DialogueScript.h"

#include "Player/FlawlessAbbeyCharacter.h"
#include "Player/FlawlessAbbeyPlayerController.h"

#include "UI/Dialogue/DialogueBox.h"

#include <Blueprint/UserWidget.h>

#include <EnhancedInputComponent.h>

UDialogueManagerComponent::UDialogueManagerComponent() {
	
	PrimaryComponentTick.bCanEverTick = true;

}

void UDialogueManagerComponent::BeginPlay() {

	Super::BeginPlay();

	TObjectPtr<AFlawlessAbbeyCharacter> character = Cast<AFlawlessAbbeyCharacter>(GetOwner());
	if (character == nullptr) return;

	TObjectPtr<UEnhancedInputComponent> inputComponent = Cast<UEnhancedInputComponent>(character->InputComponent);
	if (inputComponent == nullptr) return;

	inputComponent->BindAction(advanceAction, ETriggerEvent::Triggered, this, &UDialogueManagerComponent::AdvanceDialogue);
	
}

void UDialogueManagerComponent::StartDialogue(UDialogueScript* script) {

	if (script == nullptr) return;

	m_script = script;

	m_dialogueBox = CreateWidget<UDialogueBox>(GetWorld()->GetFirstPlayerController(), dialogueBoxClass);
	m_dialogueBox->AddToViewport();
	m_dialogueBox->SetVisibility(ESlateVisibility::Visible);

	m_lineIndex = 0;
	m_dialogueBox->SetLine(m_script, m_lineIndex);

	TObjectPtr<AFlawlessAbbeyCharacter> character = Cast<AFlawlessAbbeyCharacter>(GetOwner());
	if (character == nullptr) return;

	TObjectPtr<AFlawlessAbbeyPlayerController> controller = Cast<AFlawlessAbbeyPlayerController>(character->GetController());
	if (controller == nullptr) return;

	controller->SetShowMouseCursor(true);
	controller->SetInputMode(FInputModeGameAndUI());

	controller->DisableDefaultMappingContext();
	controller->AddMappingContext(dialogueMappingContext);

}

void UDialogueManagerComponent::AdvanceDialogue() {

	if (m_lineIndex < 0) return;

	if (m_lineIndex >= m_script->lines.Num() - 1) {

		EndDialogue();
		return;

	}

	m_lineIndex++;
	m_dialogueBox->SetLine(m_script, m_lineIndex);

}
void UDialogueManagerComponent::EndDialogue() {

	m_script = nullptr;

	m_dialogueBox->RemoveFromViewport();

	TObjectPtr<AFlawlessAbbeyCharacter> character = Cast<AFlawlessAbbeyCharacter>(GetOwner());
	if (character == nullptr) return;

	TObjectPtr<AFlawlessAbbeyPlayerController> controller = Cast<AFlawlessAbbeyPlayerController>(character->GetController());
	if (controller == nullptr) return;

	controller->SetShowMouseCursor(false);
	controller->SetInputMode(FInputModeGameOnly());

	controller->EnableDefaultMappingContext();
	controller->RemoveMappingContext(dialogueMappingContext);

}

void UDialogueManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {

	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}