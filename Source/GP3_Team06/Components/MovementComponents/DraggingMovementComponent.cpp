// Fill out your copyright notice in the Description page of Project Settings.


#include "DraggingMovementComponent.h"

#include "GP3_Team06/Library/GameMathLibrary.h"
#include "Kismet/KismetMathLibrary.h"


UDraggingMovementComponent::UDraggingMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = false;
	
}

void UDraggingMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	
	FHitResult Hit(1.f);
	const FVector MoveDelta = CalculateDeltaMovement(DeltaTime);
	SafeMoveUpdatedComponent(MoveDelta, UpdatedComponent->GetComponentQuat(), true, Hit);

	if (Hit.IsValidBlockingHit())
	{
		HandleImpact(Hit, DeltaTime, MoveDelta);
		// Try to slide the remaining distance along the surface.
		SlideAlongSurface(MoveDelta, 1.f-Hit.Time, Hit.Normal, Hit, true);
	}
	
	UpdateComponentVelocity();

}

void UDraggingMovementComponent::BeginPlay()
{
	Super::BeginPlay();
	SetComponentTickEnabled(false);

}

void UDraggingMovementComponent::ToggleComponent(const bool bTurnOn)
{
	SetComponentTickEnabled(bTurnOn);
}

FVector UDraggingMovementComponent::CalculateDeltaMovement(float DeltaTime)
{
	const FVector OwnerLocation = GetOwner()->GetActorLocation();
	FVector NonNormDirectionToTarget = UGameMathLibrary::GetDirectionVectorToVector(OwnerLocation, GetLocationToReach(), false);

	NonNormDirectionToTarget = ConstrainVector(NonNormDirectionToTarget);
	const float MovementMultiplier = DragSpeed*DeltaTime> NonNormDirectionToTarget.Length()? NonNormDirectionToTarget.Length() : DragSpeed;
	//Setting Velocity just in case
	Velocity = NonNormDirectionToTarget * MovementMultiplier;
	NonNormDirectionToTarget.Normalize();
	return NonNormDirectionToTarget * MovementMultiplier * DeltaTime;
}

FVector UDraggingMovementComponent::ConstrainVector(const FVector& VectorToConstrain)
{
	if (MovementConstraints.IsZero())
	{
		return VectorToConstrain;
	}
	const FRotator OwnerRotation = GetOwner()->GetActorRotation();
	FVector ConstrainedVector = FVector::ZeroVector;
	if (MovementConstraints.X == 0)
	{
		ConstrainedVector += UKismetMathLibrary::ProjectVectorOnToVector(VectorToConstrain,UKismetMathLibrary::GetForwardVector(OwnerRotation));;
		
	}
	if (MovementConstraints.Y == 0)
	{
		ConstrainedVector += UKismetMathLibrary::ProjectVectorOnToVector(VectorToConstrain,UKismetMathLibrary::GetRightVector(OwnerRotation));
	}
	if (MovementConstraints.Z == 0)
	{
		ConstrainedVector += UKismetMathLibrary::ProjectVectorOnToVector(VectorToConstrain,UKismetMathLibrary::GetUpVector(OwnerRotation));
	}
	return ConstrainedVector;
	
}
