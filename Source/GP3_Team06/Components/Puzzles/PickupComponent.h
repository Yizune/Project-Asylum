// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GP3_Team06/Delegates/HelperDelegates.h"
#include "PickupComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GP3_TEAM06_API UPickupComponent : public USphereComponent
{
	GENERATED_BODY()

public:
	UPickupComponent();

	UFUNCTION()
	void PickupItem(AActor* Player) const;
	UFUNCTION()
	void DropItem(APawn* Player);

	UFUNCTION(BlueprintCallable, Category = "PickActor")
	void TogglePhysics(bool bTurnOn);
public:
	UPROPERTY(BlueprintAssignable)
	FOnGameplayEventSimpleSignature OnPickupEvent;
	UPROPERTY(BlueprintAssignable)
	FOnGameplayEventSimpleSignature OnDropEvent;
};
