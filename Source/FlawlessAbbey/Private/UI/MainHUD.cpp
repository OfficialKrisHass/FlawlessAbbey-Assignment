#include "UI/MainHUD.h"
#include "UI/MainLayout.h"

#include "UI/Inventory/Inventory.h"

#include "Player/FlawlessAbbeyCharacter.h"

#include "Inventory/InventoryComponent.h"

#include <Kismet/GameplayStatics.h>

void AMainHUD::BeginPlay() {

    Super::BeginPlay();

    UWorld* world = GetWorld();

    layout = CreateWidget<UMainLayout>(world->GetFirstPlayerController(), layoutClass);
    layout->AddToViewport();
    layout->SetVisibility(ESlateVisibility::Hidden);

    if (layout->GetInventory() != nullptr) {

        layout->GetInventory()->SetOwningPlayer(world->GetFirstPlayerController());

        TObjectPtr<AFlawlessAbbeyCharacter> player = Cast<AFlawlessAbbeyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
        if (player != nullptr)
            player->GetInventoryComponent()->BindUI(layout->GetInventory());

    }

}