// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayFootstepSoundPeriodicTask.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GP3_Team06/Character/CharacterBase.h"
#include "Kismet/GameplayStatics.h"

UPlayFootstepSoundPeriodicTask::UPlayFootstepSoundPeriodicTask(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bTickingTask = true;
}

UPlayFootstepSoundPeriodicTask* UPlayFootstepSoundPeriodicTask::PlayFootstepSoundPeriodic(FName TaskInstanceName, ACharacterBase* FootstepOwner, USoundBase* Sound, float Interval)
{
	UPlayFootstepSoundPeriodicTask* Task = NewTask<UPlayFootstepSoundPeriodicTask>(FootstepOwner, TaskInstanceName);

	if (Task)
	{
		Task->FootstepOwner = FootstepOwner;
		Task->Sound = Sound;
		Task->Interval = Interval;
	}
	return Task;
}

void UPlayFootstepSoundPeriodicTask::Activate()
{
	Super::Activate();
	if (Interval <0)
	{
		Interval = FMath::Abs(Interval);
	}
	TimePassed = 0;
	
}

void UPlayFootstepSoundPeriodicTask::TickTask(float DeltaTime)
{
	Super::TickTask(DeltaTime);
	if (FootstepOwner->GetMovementComponent()->Velocity != FVector::ZeroVector)
	{
		TimePassed+= DeltaTime;
	}
	else
	{
		TimePassed = 0;
	}
	PlaySoundOnInterval();
	
}

void UPlayFootstepSoundPeriodicTask::StopPlaying()
{
	EndTask();
}

void UPlayFootstepSoundPeriodicTask::PlaySoundOnInterval()
{
	if (TimePassed< Interval)
	{
		return;
	}
	OnPreSoundPlayed.Broadcast();
	FVector SoundLocation = FootstepOwner->GetActorLocation();
	SoundLocation.Z-= FootstepOwner->GetCapsuleComponent()->GetScaledCapsuleHalfHeight();
	UGameplayStatics::PlaySoundAtLocation(FootstepOwner,Sound,SoundLocation);
	TimePassed = 0;
	OnSoundPlayed.Broadcast();
}
