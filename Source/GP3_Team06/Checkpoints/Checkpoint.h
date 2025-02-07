// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GP3_Team06/Actors/ActorBase.h"
#include "Checkpoint.generated.h"

class IResettable;
class UArrowComponent;

UCLASS()
class GP3_TEAM06_API ACheckpoint : public AActorBase
{
	GENERATED_BODY()
	friend class UCheckpointSubsystem;
public:
	ACheckpoint();
	virtual void OnConstruction(const FTransform& Transform) override;
protected:
	void ResetToThisCheckpoint(AActor* Player);

	UFUNCTION(BlueprintNativeEvent, Category = "Checkpoint")
	FVector GetRespawnLocation();
protected:
	
	UPROPERTY(EditAnywhere, Category = Components)
	UArrowComponent* ForwardArrow;
private:
	UPROPERTY(EditAnywhere, Category = "Checkpoint")
	TArray<AActor*> ResettableActors;
	UPROPERTY(EditAnywhere, Category = "Checkpoint|Debug")
	bool ShowResettableActors = false;
	UPROPERTY(EditAnywhere, Category = "Checkpoint|Debug")
	FLinearColor DebugColor = FLinearColor::Red;
};
