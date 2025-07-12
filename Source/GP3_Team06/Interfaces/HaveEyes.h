// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HaveEyes.generated.h"

class UCameraComponent;

UINTERFACE()
class UHaveEyes : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GP3_TEAM06_API IHaveEyes
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category = "I Have Eyes Interface")
	UCameraComponent* GetCameraComponent();
};
