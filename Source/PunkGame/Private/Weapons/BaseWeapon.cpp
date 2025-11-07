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

	if (Type == WeaponType::Melee)
	{
		UE_LOG(LogTemp, Log, TEXT("Performing melee attack."));
	}
	else if (Type == WeaponType::Ranged)
	{
		UE_LOG(LogTemp, Log, TEXT("Firing ranged weapon."));
	}
}