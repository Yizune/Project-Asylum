// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Resettable.generated.h"

class ACheckpoint;

UINTERFACE(BlueprintType)
class UResettable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GP3_TEAM06_API IResettable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable,BlueprintNativeEvent, Category = "Resettable")
	AActor* GetActor();
	UFUNCTION(BlueprintCallable,BlueprintNativeEvent, Category = "Resettable")
	void Reset(ACheckpoint* Checkpoint, AActor* Player);
};
