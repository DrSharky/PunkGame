// Copyright Dystopia Games, Inc. All Rights Reserved.


#include "Data/HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;

	if (AActor* Owner = GetOwner())
	{
		Owner->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::HandleTakeAnyDamage);
	}
}

void UHealthComponent::Heal(float HealAmount)
{
	if (HealAmount <= 0.f || bIsDead)
	{
		return;
	}
	CurrentHealth += HealAmount;
	if (CurrentHealth > MaxHealth)
	{
		CurrentHealth = MaxHealth;
	}
	OnHealthChanged.Broadcast(this, CurrentHealth, HealAmount, nullptr, nullptr, nullptr);
}

void UHealthComponent::HandleTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* Damager, AActor* DamagingActor)
{
	if (Damage <= 0.f || bIsDead)
	{
		return;
	}

	const float OldHealth = CurrentHealth;

	CurrentHealth -= Damage;

	if (CurrentHealth < 0.f)
	{
		CurrentHealth = 0.f;
	}

	const float Delta = CurrentHealth - OldHealth;

	OnHealthChanged.Broadcast(this, CurrentHealth, Delta, Damager, DamagingActor, DamageType);

	if (CurrentHealth <= 0.f && !bIsDead)
	{
		bIsDead = true;
		OnDeath.Broadcast(Damager, DamagingActor);
	}
}