// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactable.generated.h"

UINTERFACE(BlueprintType)
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GP3_TEAM06_API IInteractable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactalbe", meta=(DefaultToSelf = "Interacter"))
	void Interact(AActor* Interacter);
};
