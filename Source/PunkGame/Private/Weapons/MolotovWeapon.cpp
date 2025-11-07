// Copyright Dystopia Games, Inc. All Rights Reserved.


#include "Weapons/MolotovWeapon.h"
#include "Weapons/MolotovProjectile.h"
#include "Kismet/GameplayStatics.h"

AMolotovWeapon::AMolotovWeapon()
{
	WeaponName = "Molotov";
}

void AMolotovWeapon::UseWeapon()
{
	Super::UseWeapon();
	if (MolotovProjectileClass)
	{
		UWorld* World = GetWorld();
		if (World)
		{
			FVector MuzzleLocation = Mesh->GetSocketLocation("Muzzle");
			FRotator MuzzleRotation = Mesh->GetSocketRotation("Muzzle");
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = GetInstigator();
			// Spawn the projectile at the muzzle
			World->SpawnActor<AMolotovProjectile>(MolotovProjectileClass, MuzzleLocation, MuzzleRotation, SpawnParams);
		}
	}
}