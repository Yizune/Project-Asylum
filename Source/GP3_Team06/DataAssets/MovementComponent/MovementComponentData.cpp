// Fill out your copyright notice in the Description page of Project Settings.


#include "MovementComponentData.h"

#include "GP3_Team06/Components/MovementComponents/CustomMovementComponent.h"

void UMovementComponentData::InitializeCharacterMovementComponent(UCustomMovementComponent* CharacterMovementComponent)
{
	if (!CharacterMovementComponent)
	{
		return;
	}
	// Apply general settings
	CharacterMovementComponent->GravityScale = GeneralSettings.GravityScale;
	CharacterMovementComponent->MaxAcceleration = GeneralSettings.MaxAcceleration;
	CharacterMovementComponent->BrakingFrictionFactor = GeneralSettings.BrakingFrictionFactor;
	CharacterMovementComponent->SetCrouchedHalfHeight(GeneralSettings.CrouchedHalfHeight);


    // Apply walking settings
    CharacterMovementComponent->MaxStepHeight = WalkingSettings.MaxStepHeight;
    CharacterMovementComponent->SetWalkableFloorAngle(WalkingSettings.WalkableFloorAngle);
    CharacterMovementComponent->GroundFriction = WalkingSettings.GroundFriction;
    CharacterMovementComponent->MaxWalkSpeedCrouched = WalkingSettings.MaxWalkSpeedCrouched;
    CharacterMovementComponent->MaxWalkSpeed = WalkingSettings.MaxWalkSpeed;
    CharacterMovementComponent->BrakingDecelerationWalking = WalkingSettings.BrakingDecelerationWalking;

    // Apply jumping/falling settings
    CharacterMovementComponent->JumpZVelocity = JumpingSettings.JumpZVelocity;
    CharacterMovementComponent->BrakingDecelerationFalling = JumpingSettings.BrakingDecelerationFalling;
    CharacterMovementComponent->AirControl = JumpingSettings.AirControl;
    CharacterMovementComponent->AirControlBoostMultiplier = JumpingSettings.AirControlBoostMultiplier;
    CharacterMovementComponent->AirControlBoostVelocityThreshold = JumpingSettings.AirControlBoostVelocityThreshold;
    CharacterMovementComponent->bApplyGravityWhileJumping = JumpingSettings.bApplyGravityWhileJumping;

    // Apply rotation settings
    CharacterMovementComponent->RotationRate = RotationSettings.RotationRate;
    CharacterMovementComponent->bUseControllerDesiredRotation = RotationSettings.bUseControllerDesiredRotation;
    CharacterMovementComponent->bOrientRotationToMovement = RotationSettings.bOrientRotationToMovement;

	// Apply physics interaction settings
	CharacterMovementComponent->bEnablePhysicsInteraction = PhysicsInteractionSettings.bEnablePhysicsInteraction;
	CharacterMovementComponent->bTouchForceScaledToMass = PhysicsInteractionSettings.bTouchForceScaledToMass;
	CharacterMovementComponent->bPushForceScaledToMass = PhysicsInteractionSettings.bPushForceScaledToMass;
	CharacterMovementComponent->bPushForceUsingZOffset = PhysicsInteractionSettings.bPushForceUsingZOffset;
	CharacterMovementComponent->bScalePushForceToVelocity = PhysicsInteractionSettings.bScalePushForceToVelocity;
	CharacterMovementComponent->StandingDownwardForceScale = PhysicsInteractionSettings.StandingDownwardForceScale;
	CharacterMovementComponent->InitialPushForceFactor = PhysicsInteractionSettings.InitialPushForceFactor;
	CharacterMovementComponent->PushForceFactor = PhysicsInteractionSettings.PushForceFactor;
	CharacterMovementComponent->PushForcePointZOffsetFactor = PhysicsInteractionSettings.PushForcePointZOffsetFactor;
	CharacterMovementComponent->TouchForceFactor = PhysicsInteractionSettings.TouchForceFactor;
	CharacterMovementComponent->MinTouchForce = PhysicsInteractionSettings.MinTouchForce;
	CharacterMovementComponent->MaxTouchForce = PhysicsInteractionSettings.MaxTouchForce;
	CharacterMovementComponent->RepulsionForce = PhysicsInteractionSettings.RepulsionForce;

	//Apply Nav Movement

	CharacterMovementComponent->NavAgentProps.AgentRadius= NavMovementSettings.NavAgentProps.AgentRadius;
	CharacterMovementComponent->NavAgentProps.AgentHeight= NavMovementSettings.NavAgentProps.AgentHeight;
	CharacterMovementComponent->NavAgentProps.AgentStepHeight= NavMovementSettings.NavAgentProps.AgentStepHeight;
	CharacterMovementComponent->NavAgentProps.NavWalkingSearchHeightScale= NavMovementSettings.NavAgentProps.NavWalkingSearchHeightScale;
	CharacterMovementComponent->NavAgentProps.bCanCrouch= NavMovementSettings.NavAgentProps.bCanCrouch;
	CharacterMovementComponent->NavAgentProps.bCanJump= NavMovementSettings.NavAgentProps.bCanJump;
	CharacterMovementComponent->NavAgentProps.bCanWalk= NavMovementSettings.NavAgentProps.bCanWalk;
	CharacterMovementComponent->NavAgentProps.bCanSwim= NavMovementSettings.NavAgentProps.bCanSwim;
	CharacterMovementComponent->NavAgentProps.bCanFly= NavMovementSettings.NavAgentProps.bCanFly;

	CharacterMovementComponent->bUseAccelerationForPaths = NavMovementSettings.bUseAccelerationForPaths;
	
}
