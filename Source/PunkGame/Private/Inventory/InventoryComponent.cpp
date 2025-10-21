// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UInventoryComponent::EquipNextWeapon()
{
	//if (Weapons.Num() == 0) return;
	//int32 NextIndex = (CurrentIndex + 1) % Weapons.Num();
	//EquipWeapon(NextIndex);
}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
	// ...
}

void UInventoryComponent::EquipWeapon(int32 Index)
{
	//if (Weapons.IsValidIndex(Index))
	//{
	//	ABaseWeapon* NewWeapon = Weapons[Index];
	//	if (NewWeapon && NewWeapon != CurrentWeapon)
	//	{
	//		if (CurrentWeapon)
	//		{
	//			CurrentWeapon->OnUnEquip();
	//		}
	//		CurrentWeapon = NewWeapon;
	//		CurrentWeapon->OnEquip();
	//		CurrentIndex = Index;
	//	}
	//}
}