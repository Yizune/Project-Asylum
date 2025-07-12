// Fill out your copyright notice in the Description page of Project Settings.


#include "GameSystemsFunctionLibrary.h"

#include "GP3_Team06/Components/MovementComponents/DraggingMovementComponent.h"
#include "..\Interfaces\Movable.h"
#include "GP3_Team06/Character/PlayerCharacterBase.h"
#include "GP3_Team06/Checkpoints/Checkpoint.h"
#include "GP3_Team06/Checkpoints/CheckpointSubsystem.h"
#include "Kismet/GameplayStatics.h"

UDraggingMovementComponent* UGameSystemsFunctionLibrary::GetDraggingMovementComponent(AActor* Actor)
{
	return GetDraggingMovementComponentFromActor(Actor);
}

UDraggingMovementComponent* UGameSystemsFunctionLibrary::GetDraggingMovementComponentFromActor(AActor* Actor, const bool LookForComponent)
{
	if (Actor == nullptr)
	{
		return nullptr;
	}

	if (const IMovable* Draggable = Cast<IMovable>(Actor))
	{
		return Draggable->GetDraggingMovementComponent();
	}

	if (LookForComponent)
	{
		// Fall back to a component search to better support BP-only actors
		return Actor->FindComponentByClass<UDraggingMovementComponent>();
	}
	return nullptr;
}

bool UGameSystemsFunctionLibrary::AddEventToInteractInput(AActor* Player, const EInteractEvent InteractEvent, const FOnInputEventSingleSignature& Event, bool bOverrideInteract)
{
	APlayerCharacterBase* PlayerCharacterBase = Cast<APlayerCharacterBase>(Player);
	if (PlayerCharacterBase)
	{
		PlayerCharacterBase->AddEventToInteractInput(InteractEvent, Event, bOverrideInteract);
	}
	return PlayerCharacterBase != nullptr;
}


bool UGameSystemsFunctionLibrary::RemoveEventFromInteractInput(AActor* Player, const EInteractEvent InteractEvent, const FOnInputEventSingleSignature& Event)
{
	APlayerCharacterBase* PlayerCharacterBase = Cast<APlayerCharacterBase>(Player);
	if (PlayerCharacterBase)
	{
		PlayerCharacterBase->RemoveEventFromInteractInput(InteractEvent,Event);
	}
	return PlayerCharacterBase != nullptr;
}

bool UGameSystemsFunctionLibrary::ClearInteractInput(AActor* Player, const EInteractEvent InteractEvent)
{
	APlayerCharacterBase* PlayerCharacterBase = Cast<APlayerCharacterBase>(Player);
	if (PlayerCharacterBase)
	{
		PlayerCharacterBase->ClearInteractInput(InteractEvent);

	
	}
	return PlayerCharacterBase != nullptr;
}

bool UGameSystemsFunctionLibrary::ResetInteractInputToDefault(AActor* Player, const EInteractEvent InteractEvent)
{
	APlayerCharacterBase* PlayerCharacterBase = Cast<APlayerCharacterBase>(Player);
	if (PlayerCharacterBase)
	{
		PlayerCharacterBase->ResetInteractInputToDefault(InteractEvent);
	}
	return PlayerCharacterBase != nullptr;
}

bool UGameSystemsFunctionLibrary::RestartToCheckpoint(UObject* WorldObject)
{
	const UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(WorldObject);
	const UCheckpointSubsystem* CheckpointSubsystem = GameInstance->GetSubsystem<UCheckpointSubsystem>();
	return CheckpointSubsystem->RestartLevel();
}

void UGameSystemsFunctionLibrary::SetCheckpoint(ACheckpoint* Checkpoint)
{
	const UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(Checkpoint);
	UCheckpointSubsystem* CheckpointSubsystem = GameInstance->GetSubsystem<UCheckpointSubsystem>();
	CheckpointSubsystem->SetCheckpoint(Checkpoint);
}



const UCameraComponent* UGameSystemsFunctionLibrary::TryGetCameraComponent(AActor* Actor)
{
	const UCameraComponent* Camera;
	TryGetCameraComponent(Actor,Camera);
	return Camera;
}


bool UGameSystemsFunctionLibrary::TryGetCameraComponent(AActor* Actor, const UCameraComponent*& OutCameraComponent)
{
	if (Actor->Implements<UHaveEyes>())
	{
		if (const UCameraComponent* Camera =  IHaveEyes::Execute_GetCameraComponent(Actor))
		{
			OutCameraComponent = Camera;
			return true;
		}
	}
	return false;

}

