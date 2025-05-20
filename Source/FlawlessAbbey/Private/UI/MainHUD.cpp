#include "UI/MainHUD.h"
#include "UI/MainLayout.h"

void AMainHUD::BeginPlay() {

    Super::BeginPlay();

    UWorld* world = GetWorld();

    layout = CreateWidget<UMainLayout>(world, layoutClass);
    layout->AddToViewport();
    layout->SetVisibility(ESlateVisibility::Visible);

}