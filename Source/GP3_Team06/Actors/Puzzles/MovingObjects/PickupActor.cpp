// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupActor.h"

#include "Camera/CameraComponent.h"
#include "GP3_Team06/Components/MovementComponents/DraggingMovementComponent.h"
#include "GP3_Team06/Components/Puzzles/PickupComponent.h"
#include "GP3_Team06/Interfaces/HaveEyes.h"
#include "GP3_Team06/Library/GameSystemsFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"


APickupActor::APickupActor()
{
	PrimaryActorTick.bCanEverTick = true;
	SetActorTickEnabled(false);
	PickupComponent = CreateDefaultSubobject<UPickupComponent>("SpherePickup");
	SetRootComponent(PickupComponent);
	DraggingMovementComponent = CreateDefaultSubobject<UDraggingMovementComponent>("Dragging Movement");
}

void APickupActor::Interact_Implementation(AActor* Interacter)
{
	Super::Interact_Implementation(Interacter);

	PickupComponent->TogglePhysics(false);
	PickupComponent->PickupItem(Interacter);
	DraggingMovementComponent->ToggleComponent(true);
	SetActorTickEnabled(true);
	

}

void APickupActor::BeginPlay()
{
	Super::BeginPlay();
	PickupComponent->OnDropEvent.AddDynamic(this,&ThisClass::DropItem);
}

void APickupActor::TickActor(float DeltaTime, ELevelTick TickType, FActorTickFunction& ThisTickFunction)
{
	Super::TickActor(DeltaTime, TickType, ThisTickFunction);
	DraggingMovementComponent->SetLocationToReach(CalculateLocationToReach());
}

void APickupActor::DropItem_Implementation()
{
	PickupComponent->TogglePhysics(true);
	DraggingMovementComponent->ToggleComponent(false);
	SetActorTickEnabled(false);
}

FVector APickupActor::CalculateLocationToReach() const
{
	
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this,0);
	FVector StartLocation = PlayerPawn->GetActorLocation();
	if (const UCameraComponent* Camera; UGameSystemsFunctionLibrary::TryGetCameraComponent(PlayerPawn, Camera))
	{
		StartLocation = Camera->GetComponentLocation();
	}
	
	const FVector ControllerForwardVector = UKismetMathLibrary::GetForwardVector(PlayerPawn->GetController()->GetControlRotation());
	return StartLocation + ControllerForwardVector * HoldDistance;
}


