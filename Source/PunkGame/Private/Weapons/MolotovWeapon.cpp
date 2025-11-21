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
			FVector SpawnPos = Mesh->GetSocketLocation("SpawnPos");
			FRotator SpawnRot = Mesh->GetSocketRotation("SpawnRot");
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = GetInstigator();

			World->SpawnActor<AMolotovProjectile>(MolotovProjectileClass, SpawnPos, SpawnRot, SpawnParams);
		}
	}
}