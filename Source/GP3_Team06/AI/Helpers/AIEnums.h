// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType, DisplayName ="AI State")
enum class EAIState
{
	EAIS_Roaming UMETA(DisplayName = "Roaming"),
	EAIS_Chasing UMETA(DisplayName = "Chasing"),
	EAIS_Returning UMETA(DisplayName = "Returning"),

};
