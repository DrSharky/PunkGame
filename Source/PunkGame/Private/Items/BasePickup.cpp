// Copyright Dystopia Games, Inc. All Rights Reserved.


#include "Items/BasePickup.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Character.h"
#include "Inventory/InventoryComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABasePickup::ABasePickup()
{
	PrimaryActorTick.bCanEverTick = false;

	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComp"));
	CollisionComp->InitSphereRadius(50.f);
	CollisionComp->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	RootComponent = CollisionComp;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComponent);
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &ABasePickup::OnOverlapBegin);
}

void ABasePickup::OnOverlapBegin(
	UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult
)
{
	if (OtherActor && (OtherActor != this))
	{
		OnPickedUp(OtherActor);
		Destroy();
	}
}

void ABasePickup::OnPickedUp_Implementation(AActor* PickingActor)
{
	if (ACharacter* Character = Cast<ACharacter>(PickingActor))
	{
		UE_LOG(LogTemp, Log, TEXT("%s picked up a %s"), *Character->GetName(), this->GetName());

		if (UInventoryComponent* InventoryComp = Character->FindComponentByClass<UInventoryComponent>())
		{
			InventoryComp->AddItem(ItemData);
			UE_LOG(LogTemp, Log, TEXT("%s added to inventory."), this->GetName());
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No InventoryComponent found on %s."), *Character->GetName());
		}
	}
}