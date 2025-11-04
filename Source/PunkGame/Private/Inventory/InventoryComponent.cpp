// Copyright Dystopia Games, Inc. All Rights Reserved.


#include "Inventory/InventoryComponent.h"
#include "Weapons/BaseWeapon.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	CurrentWeapon = nullptr;
	CurrentIndex = -1;
}

void UInventoryComponent::AddItem(UItemDataAsset* ItemData, int32 Quantity)
{

	if (ItemData)
	{
		for (FInventoryItem& ExistingItem : Items)
		{
			if (ExistingItem.IsValid() && ExistingItem.ItemData == ItemData)
			{
				ExistingItem.Quantity = FMath::Min(ExistingItem.Quantity + Quantity, ItemData->MaxStack);
				return;
			}
		}
	}

	FInventoryItem NewItem;
	NewItem.ItemData = ItemData;
	NewItem.Quantity = Quantity;
	Items.Add(NewItem);
}

bool UInventoryComponent::HasItem(FName ItemID) const
{
	for (const FInventoryItem& Item : Items)
	{
		if (Item.IsValid() && Item.ItemData->ItemID == ItemID)
		{
			return true;
		}
	}
	return false;
}

void UInventoryComponent::EquipNextWeapon()
{
	if (Weapons.Num() == 0) return;
	int32 NextIndex = (CurrentIndex + 1) % Weapons.Num();
	EquipWeapon(NextIndex);
}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UInventoryComponent::EquipWeapon(int32 Index)
{
	if (Weapons.IsValidIndex(Index))
	{
		ABaseWeapon* NewWeapon = Weapons[Index];
		if (NewWeapon && NewWeapon != CurrentWeapon)
		{
			if (CurrentWeapon)
			{
				CurrentWeapon->SetActorHiddenInGame(true);
			}

			CurrentWeapon = NewWeapon;
			CurrentWeapon->SetActorHiddenInGame(false);
			CurrentIndex = Index;
		}
	}
}