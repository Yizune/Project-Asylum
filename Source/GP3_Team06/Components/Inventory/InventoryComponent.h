// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GP3_Team06/Interfaces/KeyContainer.h"
#include "InventoryComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GP3_TEAM06_API UInventoryComponent : public UActorComponent, public IKeyContainer
{
	GENERATED_BODY()

public:
	UInventoryComponent();
	// KeyContainer Interface

	virtual bool AddKey(const FGameplayTag& NewKeyTag) override;

	virtual bool RemoveKey(const FGameplayTag& KeyTag) override;

	virtual const FGameplayTagContainer& GetContainedKeys() const override { return ContainedKeys;};
	virtual bool ContainsKeys(const FGameplayTagContainer& RequiredKeys) override;
	virtual bool ContainsKey(const FGameplayTag& RequiredKey) override;
	// End of KeyContainer Interface


private:
	UPROPERTY(VisibleAnywhere,Category = "Inventory|KeyContainer",meta = (Categories  = "Key"))
	FGameplayTagContainer ContainedKeys;
	
};
