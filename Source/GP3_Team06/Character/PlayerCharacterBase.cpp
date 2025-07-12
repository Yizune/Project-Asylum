// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterBase.h"

#include "Camera/CameraComponent.h"
#include "GP3_Team06/Components/Inventory/InventoryComponent.h"
#include "GP3_Team06/Player/PlayerControllerBase.h"


APlayerCharacterBase::APlayerCharacterBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
	InventoryComponent = CreateDefaultSubobject<UInventoryComponent>("Inventory Component");
}


bool APlayerCharacterBase::AddKey(const FGameplayTag& NewKeyTag)
{
	return InventoryComponent->AddKey(NewKeyTag);
}

bool APlayerCharacterBase::RemoveKey(const FGameplayTag& KeyTag)
{
	return InventoryComponent->RemoveKey(KeyTag);
}

const FGameplayTagContainer& APlayerCharacterBase::GetContainedKeys() const
{
	return InventoryComponent->GetContainedKeys();
}

bool APlayerCharacterBase::ContainsKeys(const FGameplayTagContainer& RequiredKeys)
{
	return InventoryComponent->ContainsKeys(RequiredKeys);
}

bool APlayerCharacterBase::ContainsKey(const FGameplayTag& RequiredKey)
{
	return InventoryComponent->ContainsKey(RequiredKey);
}

UCameraComponent* APlayerCharacterBase::GetCameraComponent_Implementation()
{
	return FindComponentByClass<UCameraComponent>();
}


void APlayerCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	APlayerControllerBase* ControllerBase = GetPlayerControllerBase();
	if (ControllerBase)
	{
		FOnInputEventSingleSignature Callback;
		Callback.BindDynamic(this,&ThisClass::DefaultInteractAction);
		ControllerBase->SetDefaultInteractEvent(EInteractEvent::EIE_InteractStart,Callback);
		ControllerBase->ResetInteractEvent(EInteractEvent::EIE_InteractStart);
	}
}

APlayerControllerBase* APlayerCharacterBase::GetPlayerControllerBase() const
{
	return GetController<APlayerControllerBase>();
}

 
void APlayerCharacterBase::AddEventToInteractInput(const EInteractEvent InteractEvent,const FOnInputEventSingleSignature& Event, bool bOverride)
{
	if (APlayerControllerBase* PlayerController = GetPlayerControllerBase())
	{
		PlayerController->AddInteractEvent(InteractEvent,Event,bOverride);
	}
}

void APlayerCharacterBase::RemoveEventFromInteractInput(const EInteractEvent InteractEvent,const FOnInputEventSingleSignature& Event)
{
	if (APlayerControllerBase* PlayerController = GetPlayerControllerBase())
	{
		PlayerController->RemoveInteractEvent(InteractEvent,Event);
	}
}

void APlayerCharacterBase::ClearInteractInput(const EInteractEvent InteractEvent)
{
	if (APlayerControllerBase* PlayerController = GetPlayerControllerBase())
	{
		PlayerController->ClearInteractEvent(InteractEvent);
	}
}

void APlayerCharacterBase::ResetInteractInputToDefault(const EInteractEvent InteractEvent)
{
	if (APlayerControllerBase* PlayerController = GetPlayerControllerBase())
	{
		PlayerController->ResetInteractEvent(InteractEvent);
	}
}


void APlayerCharacterBase::DefaultInteractAction_Implementation(APawn* PossessedPawn)
{
}
