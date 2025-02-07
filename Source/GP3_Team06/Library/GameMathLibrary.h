// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameMathLibrary.generated.h"

/**
 * 
 */
UCLASS()
class GP3_TEAM06_API UGameMathLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = MathLibrary, DisplayName = "Get Direction Vector")
	static FVector GetDirectionVectorToVector(FVector From, FVector To, bool Normalize = true);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = MathLibrary, DisplayName = "Get Direction Actor", meta =(DefaultToSelf = "From"))
	static FVector GetDirectionActorToActor(AActor* From, AActor* To, bool Normalize = true);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = MathLibrary, DisplayName = "GetAngleBetweenVectors")
	static float GetAngleBetweenVectors(FVector A, FVector B, bool GetInDeg = true, bool GetFullCircle = false);
};
