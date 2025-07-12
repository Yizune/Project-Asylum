// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupComponent.h"

#include "GP3_Team06/Library/GameSystemsFunctionLibrary.h"
#include "GP3_Team06/Player/PlayerControllerBase.h"


UPickupComponent::UPickupComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	TogglePhysics(true);
	UPickupComponent::SetCollisionObjectType(ECC_WorldDynamic);
	UPickupComponent::SetCollisionResponseToChannel(ECC_GameTraceChannel2,ECR_Block);
	UPickupComponent::SetCollisionResponseToChannel(ECC_Pawn,ECR_Ignore);
	
}



void UPickupComponent::PickupItem(AActor* Player) const
{
	FOnInputEventSingleSignature Callback;
	Callback.BindDynamic(this,&ThisClass::DropItem);
	UGameSystemsFunctionLibrary::AddEventToInteractInput(Player,EInteractEvent::EIE_InteractStart,Callback, true );
	OnPickupEvent.Broadcast();
}

void UPickupComponent::DropItem(APawn* Player)
{
	UGameSystemsFunctionLibrary::ResetInteractInputToDefault(Player,EInteractEvent::EIE_InteractStart);
	OnDropEvent.Broadcast();
}

void UPickupComponent::TogglePhysics(const bool bTurnOn)
{
	SetSimulatePhysics(bTurnOn);
	SetEnableGravity(bTurnOn);
}
