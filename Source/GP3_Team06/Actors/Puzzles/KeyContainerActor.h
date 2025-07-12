// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GP3_Team06/Actors/ActorBase.h"
#include "GP3_Team06/Interfaces/KeyContainer.h"
#include "KeyContainerActor.generated.h"


UCLASS()
class GP3_TEAM06_API AKeyContainerActor : public AActorBase, public IKeyContainer
{
	GENERATED_BODY()

public:
	AKeyContainerActor();
	// KeyContainer Interface

	virtual bool AddKey(const FGameplayTag& NewKeyTag) override;
	virtual bool RemoveKey(const FGameplayTag& KeyTag) override;
	virtual const FGameplayTagContainer& GetContainedKeys() const override;
	virtual bool ContainsKeys(const FGameplayTagContainer& RequiredKeys) override;
	virtual bool ContainsKey(const FGameplayTag& RequiredKey) override;
	// End of KeyContainer Interface

public:
	UPROPERTY(BlueprintAssignable)
	FOnKeyStatusChanged OnKeyAdded;
	UPROPERTY(BlueprintAssignable)
	FOnKeyStatusChanged OnKeyRemoved;
private:
	UPROPERTY(VisibleAnywhere,Category = "Inventory|KeyContainer",meta = (Categories = "Key"))
	FGameplayTagContainer ContainedKeys;
};
