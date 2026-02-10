// Copyright Dystopia Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FOnHealthChanged, UHealthComponent*, HealthComp, float, NewHealth, float, Delta, AController*, Instigator, AActor*, DamageCauser, const UDamageType*, DamageType);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FOnDeath,
    AController*, Instigator,
    AActor*, DamageCauser
);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PUNKGAME_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float MaxHealth = 100.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Health")
	float CurrentHealth;

	UPROPERTY(BlueprintAssignable, Category = "Health")
	FOnHealthChanged OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "Health")
	FOnDeath OnDeath;

	UFUNCTION(BlueprintCallable, Category = "Health")
	bool IsAlive() const { return CurrentHealth > 0.f; }

	UFUNCTION(BlueprintCallable, Category = "Health")
	void Heal(float HealAmount);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void HandleTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* Damager, AActor* DamagingActor);

	bool bIsDead = false;
};
