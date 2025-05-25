#include "Pickup/ItemPickup.h"

#include "Player/FlawlessAbbeyCharacter.h"

#include "Inventory/InventoryComponent.h"

#include <Components/StaticMeshComponent.h>
#include <Components/BoxComponent.h>

AItemPickup::AItemPickup() {

	PrimaryActorTick.bCanEverTick = false;

	// Simulate physics, but no collisions with the player character

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(mesh);

	mesh->SetSimulatePhysics(true);
	mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	mesh->SetCollisionResponseToAllChannels(ECR_Block);
	mesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);

	// No physics, only overlap with the player

	trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	trigger->SetupAttachment(mesh);

	trigger->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	trigger->SetCollisionObjectType(ECC_WorldDynamic);
	trigger->SetCollisionResponseToAllChannels(ECR_Ignore);
	trigger->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	trigger->OnComponentBeginOverlap.AddDynamic(this, &AItemPickup::BeginOverlap);

}

void AItemPickup::BeginPlay() {

	Super::BeginPlay();

}

void AItemPickup::BeginOverlap(UPrimitiveComponent* overlapedComponent, AActor* actor, UPrimitiveComponent* otherComponent, int32 otherIndex, bool fromSweep, const FHitResult& sweepResult) {

	if (item == nullptr) return;

	TObjectPtr<AFlawlessAbbeyCharacter> player = Cast<AFlawlessAbbeyCharacter>(actor);
	if (player == nullptr) return;

	player->GetInventoryComponent()->AddItem(item);
	player->GetInventoryComponent()->UpdateInventoryUI();

	Destroy();

}