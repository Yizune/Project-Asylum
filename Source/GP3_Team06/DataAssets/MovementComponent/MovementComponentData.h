// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MovementComponentData.generated.h"

class UCustomMovementComponent;

USTRUCT()
struct FGeneralSettings
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	float GravityScale = 1.f;
	UPROPERTY(EditAnywhere, meta = (ClampMin = 0, UIMin = 0))
	float MaxAcceleration = 2048.f;
	UPROPERTY(EditAnywhere, meta = (ClampMin = 0, UIMin = 0))
	float BrakingFrictionFactor = 2.0f;
	UPROPERTY(EditAnywhere, meta=(ClampMin="0", UIMin="0", ForceUnits=cm))
	float CrouchedHalfHeight = 40.f;
};

USTRUCT()
struct FWalkingSettings
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, meta=(ClampMin="0", UIMin="0", ForceUnits="cm"))
	float MaxStepHeight = 45.f;
	UPROPERTY(EditAnywhere, meta=(ClampMin="0.0", ClampMax="90.0", UIMin = "0.0", UIMax = "90.0", ForceUnits="degrees"))
	float WalkableFloorAngle = 44.765083f;;
	UPROPERTY(EditAnywhere, meta=(ClampMin="0", UIMin="0"))
	float GroundFriction = 8.0f;
	UPROPERTY(EditAnywhere, meta=(ClampMin="0", UIMin="0", ForceUnits="cm/s"))
	float MaxWalkSpeed = 600.0f;
	UPROPERTY(EditAnywhere, meta=(ClampMin="0", UIMin="0", ForceUnits="cm/s"))
	float MaxWalkSpeedCrouched = 300.f;

	UPROPERTY(EditAnywhere, meta=(ClampMin="0", UIMin="0"))
	float BrakingDecelerationWalking = 2048.f;
};

USTRUCT()
struct FJumpingSettings
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, meta=(DisplayName="Jump Z Velocity", ClampMin="0", UIMin="0", ForceUnits="cm/s"))
	float JumpZVelocity = 420.0f;
	UPROPERTY(EditAnywhere, meta=(ClampMin="0", UIMin="0"))
	float BrakingDecelerationFalling = 0.0f;
	UPROPERTY(EditAnywhere, meta=(ClampMin="0", UIMin="0"))
	float AirControl = 0.05f;
	UPROPERTY(EditAnywhere, meta=(ClampMin="0", UIMin="0"))
	float AirControlBoostMultiplier = 2.0f;
	UPROPERTY(EditAnywhere, meta=(ClampMin="0", UIMin="0"))
	float AirControlBoostVelocityThreshold = 25.0f;
	UPROPERTY(EditAnywhere, AdvancedDisplay)
	bool bApplyGravityWhileJumping = true;
};

USTRUCT()
struct FRotationSettings
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	FRotator RotationRate = FRotator(0, 360.f, 0);
	UPROPERTY(EditAnywhere)
	bool bUseControllerDesiredRotation = false;
	UPROPERTY(EditAnywhere)
	bool bOrientRotationToMovement = false;
};

USTRUCT()
struct FPhysicsInteractionSettings
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	bool bEnablePhysicsInteraction = true; // = 1

	UPROPERTY(EditAnywhere, meta=(editcondition = "bEnablePhysicsInteraction"))
	bool bTouchForceScaledToMass  = true; // = 1

	UPROPERTY(EditAnywhere, meta=(editcondition = "bEnablePhysicsInteraction"))
	bool bPushForceScaledToMass  = false;

	UPROPERTY(EditAnywhere, meta = (editcondition = "bEnablePhysicsInteraction"))
	bool bPushForceUsingZOffset  = false;

	UPROPERTY(EditAnywhere, meta=(editcondition = "bEnablePhysicsInteraction"))
	bool bScalePushForceToVelocity  = true; // = 1
	UPROPERTY(EditAnywhere, meta=(editcondition = "bEnablePhysicsInteraction"))
	float StandingDownwardForceScale = 1.f;

	UPROPERTY(EditAnywhere, meta=(editcondition = "bEnablePhysicsInteraction"))
	float InitialPushForceFactor = 500.f;

	UPROPERTY(EditAnywhere, meta=(editcondition = "bEnablePhysicsInteraction"))
	float PushForceFactor = 750000.f;

	UPROPERTY(EditAnywhere, meta=(UIMin = "-1.0", UIMax = "1.0"), meta=(editcondition = "bEnablePhysicsInteraction"))
	float PushForcePointZOffsetFactor = -0.75f;

	UPROPERTY(EditAnywhere, meta=(editcondition = "bEnablePhysicsInteraction"))
	float TouchForceFactor = 1.0f;

	UPROPERTY(EditAnywhere, meta=(editcondition = "bEnablePhysicsInteraction"))
	float MinTouchForce = -1.0f;

	UPROPERTY(EditAnywhere, meta=(editcondition = "bEnablePhysicsInteraction"))
	float MaxTouchForce = 250.f;

	UPROPERTY(EditAnywhere, meta=(editcondition = "bEnablePhysicsInteraction"))
	float RepulsionForce = 2.5f;
};

USTRUCT()
struct FNavMovementSettings
{
	GENERATED_BODY()

	FNavMovementSettings()
	{
		NavAgentProps.AgentRadius = -1;
		NavAgentProps.AgentHeight = -1;
		NavAgentProps.AgentStepHeight = -1;
		NavAgentProps.NavWalkingSearchHeightScale = 0.5f;
		NavAgentProps.bCanCrouch = false;
		NavAgentProps.bCanJump = true;
		NavAgentProps.bCanWalk = true;
		NavAgentProps.bCanSwim = true;
		NavAgentProps.bCanFly = false;
		
	}
	UPROPERTY(EditAnywhere, Category = NavMovement, meta = (DisplayName = "Movement Capabilities", Keywords = "Nav Agent"))
	FNavAgentProperties NavAgentProps;
	UPROPERTY(EditAnywhere, Category = NavMovement)
	bool bUseAccelerationForPaths = true;

};
/**
 * 
 */
UCLASS(DisplayName = "Movement Data", meta = (ShortToolTip ="When you make a character make this component as well so that you can tweak MovementComponent"))
class GP3_TEAM06_API UMovementComponentData : public UDataAsset
{
	GENERATED_BODY()
public:
	void InitializeCharacterMovementComponent(UCustomMovementComponent* CharacterMovementComponent);

private:
	UPROPERTY(EditAnywhere, DisplayName = "Character Movement (General Settings)")
	FGeneralSettings GeneralSettings;
	UPROPERTY(EditAnywhere, DisplayName = "Character Movement: Walking")
	FWalkingSettings WalkingSettings;
	UPROPERTY(VisibleAnywhere, DisplayName = "Character Movement: Jumping / Falling")
	FJumpingSettings JumpingSettings;
	UPROPERTY(EditAnywhere, DisplayName = "Character Movement (Rotation Settings)")
	FRotationSettings RotationSettings;
	UPROPERTY(EditAnywhere, DisplayName = "Character Movement: Physics Interaction")
	FPhysicsInteractionSettings PhysicsInteractionSettings;
	UPROPERTY(EditAnywhere, DisplayName = "Nav Movement")
	FNavMovementSettings NavMovementSettings;
	
};
