// Fill out your copyright notice in the Description page of Project Settings.


#include "CheckpointSubsystem.h"

#include "Checkpoint.h"
#include "Kismet/GameplayStatics.h"

void UCheckpointSubsystem::SetCheckpoint(ACheckpoint* NewCheckpoint)
{
	OnCheckpointChanged.Broadcast(NewCheckpoint, CurrentCheckpoint);
	CurrentCheckpoint = NewCheckpoint;
}

bool UCheckpointSubsystem::RestartLevel() const
{
	if (CurrentCheckpoint == nullptr)
	{
		UE_LOG(LogTemp,Error, TEXT("Cannot restart the level since a checkpoint has not been set"))
		return false;
	}
	PreLevelRestart.Broadcast();
	APawn* Player = UGameplayStatics::GetPlayerPawn(CurrentCheckpoint, 0);
	CurrentCheckpoint->ResetToThisCheckpoint(Player);
	Player->GetController()->SetControlRotation(CurrentCheckpoint->GetActorRotation());
	Player->SetActorLocation(CurrentCheckpoint->GetRespawnLocation());
	//Player->SetActorRotation(CurrentCheckpoint->GetActorRotation());
	OnLevelRestartEvent.Broadcast(CurrentCheckpoint);
	return true;
}
