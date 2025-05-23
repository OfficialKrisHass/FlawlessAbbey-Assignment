#include "Inventory/ViewportPreview.h"

#include <Components/SceneComponent.h>
#include <Components/StaticMeshComponent.h>
#include <Components/SceneCaptureComponent2D.h>

AViewportPreview::AViewportPreview() {

	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Item mesh"));
	mesh->SetupAttachment(RootComponent);

	sceneCapture = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("Scene capture"));
	sceneCapture->SetupAttachment(RootComponent);

}

void AViewportPreview::BeginPlay() {

	Super::BeginPlay();

}
