// Copyright Dystopia Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "BaseProjectile.generated.h"

UCLASS()
class PUNKGAME_API ABaseProjectile : public AActor
{
    GENERATED_BODY()

public:

    ABaseProjectile();

    /** Particle to show in-flight (trail) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile|VFX")
    UParticleSystem* TrailParticle;

    /** Particle to spawn on impact */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile|VFX")
    UParticleSystem* ImpactParticle;

    /** Sound played on impact */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile|Sound")
    USoundBase* ImpactSound;

	FORCEINLINE class USphereComponent* GetCollisionComp() const { return CollisionComp; }
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return Mesh; }
protected:

    // Collision
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Projectile")
    class USphereComponent* CollisionComp;

    // Mesh
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Projectile")
    class UStaticMeshComponent* Mesh;

    // Movement
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Projectile")
    class UProjectileMovementComponent* ProjectileMovement;

    UPROPERTY(EditDefaultsOnly, Category = "Projectile")
	float Damage = 25.0f;

    virtual void BeginPlay() override;

    // Called on collision
    UFUNCTION()
    void OnHit(
        UPrimitiveComponent* HitComp,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComp,
        FVector NormalImpulse,
        const FHitResult& Hit
    );

    UFUNCTION()
    void DoHitEffects(const FHitResult& Hit);
};
