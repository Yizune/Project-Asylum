// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTask.h"
#include "GP3_Team06/Delegates/HelperDelegates.h"
#include "PlayFootstepSoundPeriodicTask.generated.h"

class ACharacterBase;
/**
 * 
 */
UCLASS()
class GP3_TEAM06_API UPlayFootstepSoundPeriodicTask : public UGameplayTask
{
	GENERATED_BODY()
public:
	UPlayFootstepSoundPeriodicTask(const FObjectInitializer& ObjectInitializer);
	
	UFUNCTION(BlueprintCallable, Category="Tasks|Sounds|Footstep", meta = (DisplayName="PlayFootstepSoundPeriodic", DefaultToSelf = "FootstepOwner", BlueprintInternalUseOnly = "TRUE", Keywords = "Play Sound Footsteps"))
	static UPlayFootstepSoundPeriodicTask* PlayFootstepSoundPeriodic(FName TaskInstanceName,ACharacterBase* FootstepOwner, USoundBase* Sound, float Interval);

	virtual void Activate() override;
	virtual void TickTask(float DeltaTime) override;
	
	UFUNCTION(Blueprintable, Category="Tasks|Sounds|Footstep")
	void StopPlaying();

private:
	void PlaySoundOnInterval();
public:
	UPROPERTY(BlueprintAssignable)
	FOnGameplayEventSimpleSignature OnSoundPlayed;
	UPROPERTY(BlueprintAssignable)
	FOnGameplayEventSimpleSignature OnPreSoundPlayed;
	
private:
	UPROPERTY()
	TObjectPtr<ACharacter> FootstepOwner;
	UPROPERTY()
	TObjectPtr<USoundBase> Sound;
	float Interval;
	float TimePassed;
};
