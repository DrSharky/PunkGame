// Copyright Dystopia Games, Inc. All Rights Reserved.


#include "Weapons/BaseWeapon.h"

// Sets default values
ABaseWeapon::ABaseWeapon()
{
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	RootComponent = Mesh;
}

void ABaseWeapon::UseWeapon()
{
	UE_LOG(LogTemp, Log, TEXT("%s used."), *WeaponName.ToString());

	if (Type == EWeaponType::Melee)
	{
		UE_LOG(LogTemp, Log, TEXT("Performing melee attack."));
	}
	else if (Type == EWeaponType::Ranged)
	{
		UE_LOG(LogTemp, Log, TEXT("Firing ranged weapon."));
	}
}