// Fill out your copyright notice in the Description page of Project Settings.


#include "LockActor.h"

#include "../../Interfaces/KeyContainer.h"
#include "Kismet/KismetSystemLibrary.h"


ALockActor::ALockActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

bool ALockActor::CanOpenThisLock_Implementation(AActor* InInstigator)
{
	if (!UKismetSystemLibrary::DoesImplementInterface(InInstigator, UKeyContainer::StaticClass()))
	{
		return false;
	}

	IKeyContainer* InventoryCarrier = Cast<IKeyContainer>(InInstigator);
	return RequiresMultipleKeys? InventoryCarrier->ContainsKeys(RequiredKeys) : InventoryCarrier->ContainsKey(RequiredKey);
	
}

void ALockActor::OpenThisLock_Implementation(AActor* InInstigator)
{
	
}

bool ALockActor::TryOpenThisLock_Implementation(AActor* InInstigator)
{
	if (!CanOpenThisLock(InInstigator))
	{
		return false;
	}

	OpenThisLock(InInstigator);
	return true;
}

