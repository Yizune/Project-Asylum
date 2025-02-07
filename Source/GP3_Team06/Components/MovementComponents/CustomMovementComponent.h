// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "CustomMovementComponent.generated.h"


class UMovementComponentData;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent),Blueprintable,
	HideCategories = (
		"CharacterMovement_(GeneralSettings)",
		"CharacterMovement:Walking",
		"CharacterMovement:Jumping_/_Falling",
		"CharacterMovement:Gravity",
		"CharacterMovement_(Networking)",
		"CharacterMovement:Swimming",
		"CharacterMovement:Flying",
		"CharacterMovement:CustomMovement",
		"CharacterMovement_(RotationSettings)",
		"CharacterMovement:PhysicsInteraction",
		"RootMotion",
		"CharacterMovement:NavMeshMovement",
		"NavMovement",
		"CharacterMovement:Avoidance",
		"CharacterMovement",
		ComponentTick,MovementComponent,
		PlanarMovement,Cooking, Activation,ComponentReplication,Cooking,AssetUserData,Replication,Tags,Navigation))

class GP3_TEAM06_API UCustomMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

	friend class UMovementComponentData;
public:
	UCustomMovementComponent();
	virtual void InitializeComponent() override;
private:
	UPROPERTY(EditDefaultsOnly, Category = "MovementData")
	TObjectPtr<UMovementComponentData> MovementData;

};
