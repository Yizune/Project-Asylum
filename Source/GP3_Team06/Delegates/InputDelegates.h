// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputDelegates.generated.h"
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInputEventSignature, APawn*, PossessedPawn);
UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnInputEventSingleSignature, APawn*, PossessedPawn);

