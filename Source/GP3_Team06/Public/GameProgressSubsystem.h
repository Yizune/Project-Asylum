// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameProgressSubsystem.generated.h"

/**
 * 
 */

UENUM(Blueprintable)
enum class EObjective : uint8
{
	FirstObjective UMETA(DisplayName = "FirstObjective"),
	SecondObjective UMETA(DisplayName = "SecondObjective"),
	ThirdObjective UMETA(DisplayName = "ThirdObjective"),
	FourthObjective UMETA(DisplayName = "FourthObjective"),
	FifthObjective UMETA(DisplayName = "FifthObjective"),
	SixthObjective UMETA(DisplayName = "SixthObject"),
	SeventhObject UMETA(DisplayName = "SeventhObjective"),
	EightObjective UMETA(DisplayName = "EightObjective"),
	NinthObjective UMETA(DisplayName = "NinthObjective"),
	TenthObjective UMETA(DisplayName = "TenthObjective"),
	EleventhObjective UMETA(DisplayName = "EleventhObjective"),
	TwelfthObjective UMETA(DisplayName = "TwelfthObjective"),
	
};
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FObjectiveChanged,EObjective, NextObjective);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FNotifyPlayerOnObjectiveChanged);

UCLASS()
class GP3_TEAM06_API UGameProgressSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	
	EObjective CurrentObject;

	UFUNCTION(BlueprintCallable, Category="Objective Subsystem")
	EObjective GetCurrentObjective();

	UFUNCTION(BlueprintCallable, Category= "Objective Subsystem")
	void ChangeObjective(const EObjective NextObjective);

	UPROPERTY(BlueprintAssignable)
	FObjectiveChanged ObjectiveChanged;

	UPROPERTY(BlueprintAssignable)
	FNotifyPlayerOnObjectiveChanged NotifyPlayerOnObjectiveChanged;
};
