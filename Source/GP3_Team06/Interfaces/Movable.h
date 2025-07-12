// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Movable.generated.h"

class UDraggingMovementComponent;

UINTERFACE(Blueprintable)
class UMovable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GP3_TEAM06_API IMovable
{
	GENERATED_BODY()

public:
	virtual UDraggingMovementComponent* GetDraggingMovementComponent() const = 0;
	
};
