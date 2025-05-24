#include "Inventory/ViewportPreview.h"

#include <Components/SceneComponent.h>
#include <Components/StaticMeshComponent.h>
#include <Components/SceneCaptureComponent2D.h>

#include <GameFramework/SpringArmComponent.h>

AViewportPreview::AViewportPreview() {

	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Item mesh"));
	mesh->SetupAttachment(RootComponent);

	springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring arm"));
	springArm->SetupAttachment(RootComponent);

	sceneCapture = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("Scene capture"));
	sceneCapture->ShowOnlyComponents.Add(mesh);
	sceneCapture->PrimitiveRenderMode = ESceneCapturePrimitiveRenderMode::PRM_UseShowOnlyList;
	sceneCapture->SetupAttachment(springArm);

}

void AViewportPreview::BeginPlay() {

	Super::BeginPlay();

	springArm->TargetArmLength = (maxSpringLen - minSpringLen) / 2 + minSpringLen;

}

void AViewportPreview::SetMesh(UStaticMesh* itemMesh) {

	mesh->SetStaticMesh(itemMesh);

}

void AViewportPreview::Rotate(FVector2D delta) {

	springArm->AddLocalRotation(FRotator(delta.Y * rotationSpeed, -delta.X * rotationSpeed, 0.0f));

}
void AViewportPreview::Zoom(float delta) {

	springArm->TargetArmLength -= delta * zoomSpeed;

	if (springArm->TargetArmLength < minSpringLen)
		springArm->TargetArmLength = minSpringLen;
	else if (springArm->TargetArmLength > maxSpringLen)
		springArm->TargetArmLength = maxSpringLen;

}