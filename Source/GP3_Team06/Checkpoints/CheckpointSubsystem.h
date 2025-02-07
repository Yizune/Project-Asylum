// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GP3_Team06/Delegates/HelperDelegates.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "CheckpointSubsystem.generated.h"
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLevelRestartSignature, ACheckpoint*, Checkpoint);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCheckpointChangedSignature, ACheckpoint*, NewCheckpoint, ACheckpoint*, OldCheckpoint);
class ACheckpoint;
/**
 * 
 */
UCLASS()
class GP3_TEAM06_API UCheckpointSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	void SetCheckpoint(ACheckpoint* NewCheckpoint);
	bool RestartLevel() const;
public:
	UPROPERTY(BlueprintAssignable, Category = "CheckpointSystem");
	FOnLevelRestartSignature OnLevelRestartEvent;
	UPROPERTY(BlueprintAssignable, Category = "CheckpointSystem");
	FOnCheckpointChangedSignature OnCheckpointChanged;
	UPROPERTY(BlueprintAssignable, Category = "CheckpointSystem");
	FOnGameplayEventSimpleSignature PreLevelRestart;
private:
	UPROPERTY()
	ACheckpoint* CurrentCheckpoint;
};
