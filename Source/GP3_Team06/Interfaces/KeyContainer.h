// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Interface.h"
#include "KeyContainer.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnKeyStatusChanged, const FGameplayTag&, Key);

UINTERFACE(BlueprintType, NotBlueprintable)
class UKeyContainer : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GP3_TEAM06_API IKeyContainer
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable, Category = "Key Container")
	virtual bool AddKey(const FGameplayTag& NewKeyTag) = 0;
	UFUNCTION(BlueprintCallable, Category = "Key Container")
	virtual bool RemoveKey(const FGameplayTag& KeyTag) = 0;
	UFUNCTION(BlueprintCallable, Category = "Key Container")
	virtual const FGameplayTagContainer& GetContainedKeys() const = 0;
	
	virtual bool ContainsKeys(const FGameplayTagContainer& RequiredKeys) = 0;
	virtual bool ContainsKey(const FGameplayTag& RequiredKey) = 0;
};
