// Fill out your copyright notice in the Description page of Project Settings.


#include "KeyContainerActor.h"

#include "GP3_Team06/GameplayTags/GamaplayTagCreator.h"


AKeyContainerActor::AKeyContainerActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

bool AKeyContainerActor::AddKey(const FGameplayTag& NewKeyTag)
{
	if (!NewKeyTag.MatchesTag(GPGameplayTags::Key))
	{
		return false;
	}
	ContainedKeys.AddTag(NewKeyTag);
	OnKeyAdded.Broadcast(NewKeyTag);
	return true;
}

bool AKeyContainerActor::RemoveKey(const FGameplayTag& KeyTag)
{
	if (!KeyTag.MatchesTag(GPGameplayTags::Key))
	{
		return false;
	}
	OnKeyRemoved.Broadcast(KeyTag);
	ContainedKeys.RemoveTag(KeyTag);
	return true;
}

const FGameplayTagContainer& AKeyContainerActor::GetContainedKeys() const
{
	return ContainedKeys;
}

bool AKeyContainerActor::ContainsKeys(const FGameplayTagContainer& RequiredKeys)
{
	return ContainedKeys.HasAllExact(RequiredKeys);
}

bool AKeyContainerActor::ContainsKey(const FGameplayTag& RequiredKey)
{
	return ContainedKeys.HasTagExact(RequiredKey);
}
