// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

#include "GP3_Team06/GameplayTags/GamaplayTagCreator.h"


UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

bool UInventoryComponent::AddKey(const FGameplayTag& NewKeyTag)
{
	if (!NewKeyTag.MatchesTag(GPGameplayTags::Key))
	{
		return false;
	}
	ContainedKeys.AddTag(NewKeyTag);
	return true;
}


bool UInventoryComponent::RemoveKey(const FGameplayTag& KeyTag)
{
	if (!KeyTag.MatchesTag(GPGameplayTags::Key))
	{
		return false;
	}
	ContainedKeys.RemoveTag(KeyTag);
	return true;
}

bool UInventoryComponent::ContainsKeys(const FGameplayTagContainer& RequiredKeys)
{
	return ContainedKeys.HasAllExact(RequiredKeys);
}

bool UInventoryComponent::ContainsKey(const FGameplayTag& RequiredKey)
{
	return ContainedKeys.HasTagExact(RequiredKey);

}
