// Copyright Dystopia Games, Inc. All Rights Reserved.


#include "DevTools/DamageVolume.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"


// Sets default values
ADamageVolume::ADamageVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	SetRootComponent(Box);

	Box->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Box->SetCollisionObjectType(ECC_WorldDynamic);
	Box->SetCollisionResponseToAllChannels(ECR_Ignore);

	Box->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	Box->SetGenerateOverlapEvents(true);
	
	DamageType = UDamageType::StaticClass();

}

// Called when the game starts or when spawned
void ADamageVolume::BeginPlay()
{
	Super::BeginPlay();

	Box->OnComponentBeginOverlap.AddDynamic(this, &ADamageVolume::OnBoxBeginOverlap);
	Box->OnComponentEndOverlap.AddDynamic(this, &ADamageVolume::OnBoxEndOverlap);

	if (DamageInterval > 0.f)
	{
		GetWorldTimerManager().SetTimer(
			DamageTickHandle,
			this,
			&ADamageVolume::DealDamage,
			DamageInterval,
			true);
	}	
}

void ADamageVolume::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	GetWorldTimerManager().ClearTimer(DamageTickHandle);
	Super::EndPlay(EndPlayReason);
}

void ADamageVolume::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{
		OverlappingActors.Add(OtherActor);
	}
}

void ADamageVolume::OnBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && OtherActor != this)
	{
		OverlappingActors.Remove(OtherActor);
	}
}

void ADamageVolume::DealDamage()
{
	TArray<TObjectPtr<AActor>> Actors = OverlappingActors.Array();

	for (AActor* Actor : Actors)
	{
		if (!IsValid(Actor))
		{
			continue;
		}

		UClass* DamageClass = DamageType ? *DamageType : UDamageType::StaticClass();
		UGameplayStatics::ApplyDamage(Actor, DamagePerTick, nullptr, this, DamageClass);
	}

	for (TObjectPtr<AActor> Actor : OverlappingActors)
	{
		if (Actor)
		{
			UGameplayStatics::ApplyDamage(Actor, DamagePerTick * DamageInterval, nullptr, this, *DamageType);
		}
	}
}