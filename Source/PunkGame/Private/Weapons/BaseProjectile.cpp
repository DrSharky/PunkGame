// Copyright Dystopia Games, Inc. All Rights Reserved.


#include "Weapons/BaseProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABaseProjectile::ABaseProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(8.0f);
	CollisionComp->SetCollisionProfileName("BlockAllDynamic");
	CollisionComp->OnComponentHit.AddDynamic(this, &ABaseProjectile::OnHit);
	RootComponent = CollisionComp;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 2000.0f;
	ProjectileMovement->MaxSpeed = 2000.0f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));

	ImpactParticle = nullptr;
	ImpactSound = nullptr;
	TrailParticle = nullptr;
}

// Called when the game starts or when spawned
void ABaseProjectile::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp,	FVector NormalImpulse, const FHitResult& Hit)
{
	DoHitEffects(Hit);

	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		UGameplayStatics::ApplyDamage(OtherActor, Damage, GetInstigatorController(), this, nullptr);
	}


	Destroy();
}

void ABaseProjectile::DoHitEffects(const FHitResult& Hit)
{
	if (ImpactParticle)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactParticle, Hit.ImpactPoint, Hit.ImpactNormal.Rotation());
	}

	if (ImpactSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, ImpactSound, Hit.ImpactPoint);
	}
}