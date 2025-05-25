#include "Player/Interactible.h"

#include <Components/BoxComponent.h>

AInteractible::AInteractible() {

	PrimaryActorTick.bCanEverTick = false;

	// Mesh setup, simulate physics but no collisions with the player

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(mesh);

	mesh->SetSimulatePhysics(true);
	mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	mesh->SetCollisionResponseToAllChannels(ECR_Block);
	mesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);

	// Trigger setup, only overlap with the player

	trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	trigger->SetupAttachment(mesh);

	trigger->SetCollisionObjectType(ECC_GameTraceChannel1);

}

void AInteractible::BeginPlay() {

	Super::BeginPlay();
	

}