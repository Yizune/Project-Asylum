// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GP3_Team06/Delegates/InputDelegates.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameSystemsFunctionLibrary.generated.h"

class UCameraComponent;
class ACheckpoint;
enum class EInteractEvent : uint8;
class UDraggingMovementComponent;
/**
 * 
 */
UCLASS()
class GP3_TEAM06_API UGameSystemsFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable,BlueprintPure, Category = "GameSystems|Draggable")
	static UDraggingMovementComponent* GetDraggingMovementComponent(AActor* Actor);
	static UDraggingMovementComponent* GetDraggingMovementComponentFromActor(AActor* Actor, bool LookForComponent = true);

	UFUNCTION(BlueprintCallable, Category = "GameSystems|Input|Interact")
	static bool AddEventToInteractInput(AActor* Player, const EInteractEvent InteractEvent,const FOnInputEventSingleSignature& Event, bool bOverrideInteract = false);
	UFUNCTION(BlueprintCallable, Category = "GameSystems|Input|Interact")
	static bool RemoveEventFromInteractInput(AActor* Player, const EInteractEvent InteractEvent,const FOnInputEventSingleSignature& Event);
	UFUNCTION(BlueprintCallable, Category = "GameSystems|Input|Interact", meta = (Keywords ="Clear Input"))
	static bool ClearInteractInput(AActor* Player, const EInteractEvent InteractEvent);
	UFUNCTION(BlueprintCallable, Category = "GameSystems|Input|Interact",meta = (Keywords ="Reset Input"))
	static bool ResetInteractInputToDefault(AActor* Player, const EInteractEvent InteractEvent);
	
	UFUNCTION(BlueprintCallable, Category = "GameSystems|CheckpointSystem",meta = (Keywords ="Restart", DefaultToSelf = "WorldObject"))
	static bool RestartToCheckpoint(UObject* WorldObject);
	UFUNCTION(BlueprintCallable, Category = "GameSystems|CheckpointSystem",meta = (Keywords ="Checkpoint", DefaultToSelf = "Checkpoint"))
	static void SetCheckpoint(ACheckpoint* Checkpoint);

	UFUNCTION(BlueprintCallable,BlueprintPure, Category = "GameSystems|Interfaces|Eyes",meta = (Keywords ="GetEyes, GetCamera", DefaultToSelf = "Actor"))
	static const UCameraComponent* TryGetCameraComponent(AActor* Actor);
	static bool TryGetCameraComponent(AActor* Actor, const UCameraComponent*& OutCameraComponent);

	
	
};
