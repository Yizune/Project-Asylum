// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllerBase.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"


void APlayerControllerBase::BeginPlay()
{
	Super::BeginPlay();
	SetupMappingContext();
}

void APlayerControllerBase::SetupInputComponent()
{
	Super::SetupInputComponent();

	BindActions();
}

void APlayerControllerBase::Look_Implementation(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>();

	AddYawInput(LookAxisVector.X);
	AddPitchInput(LookAxisVector.Y);
}

void APlayerControllerBase::Move_Implementation(const FInputActionValue& Value)
{
	const FVector2D MoveInput = Value.Get<FVector2D>();;
	const FRotator MovementRotation(0.0f, GetControlRotation().Yaw, 0.0f);

	if (MoveInput.X != 0.0f)
	{
		const FVector MovementDirection = MovementRotation.RotateVector(FVector::RightVector);
		GetPawn()->AddMovementInput(MovementDirection, MoveInput.X);
	}

	if (MoveInput.Y != 0.0f)
	{
		const FVector MovementDirection = MovementRotation.RotateVector(FVector::ForwardVector);
		GetPawn()->AddMovementInput(MovementDirection, MoveInput.Y);
	}
}

void APlayerControllerBase::InteractStart_Implementation()
{
	OnInteractStartEvent.Broadcast(GetPawn());
}

void APlayerControllerBase::InteractFinish_Implementation()
{
	OnInteractFinishEvent.Broadcast(GetPawn());
}


void APlayerControllerBase::SetupMappingContext()
{
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem && DefaultMappingContext)
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
}

void APlayerControllerBase::BindActions()
{
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		//Interact
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &ThisClass::InteractStart);
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Completed, this, &ThisClass::InteractFinish);
		//EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Canceled, this, &ThisClass::InteractFinish);

		//Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerControllerBase::Move);
		EnhancedInputComponent->BindAction(MoveSprintAction, ETriggerEvent::Triggered, this, &APlayerControllerBase::Move);

		//Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APlayerControllerBase::Look);
	}
}


void APlayerControllerBase::AddInteractEvent(EInteractEvent InteractEvent, const FOnInputEventSingleSignature& Event, bool bOverride)
{
	FOnInputEventSignature& OnInteractEvent = GetOnInteractEvent(InteractEvent, false);
	if (bOverride)
	{
		ClearInteractEvent(InteractEvent);
	}
	OnInteractEvent.Add(Event);
	
}

void APlayerControllerBase::RemoveInteractEvent(EInteractEvent InteractEvent, const FOnInputEventSingleSignature& Event)
{
	FOnInputEventSignature& OnInteractEvent = GetOnInteractEvent(InteractEvent, false);
	OnInteractEvent.Remove(Event);
}

void APlayerControllerBase::ClearInteractEvent(EInteractEvent InteractEvent, bool SaveLastInputEvent)
{
	FOnInputEventSignature& OnInteractEvent = GetOnInteractEvent(InteractEvent, false);
	if (SaveLastInputEvent)
	{
		FOnInputEventSignature& LastOnInteractEvent = GetOnInteractEvent(InteractEvent, true);
		LastOnInteractEvent = OnInteractEvent;
	}
	OnInteractEvent.Clear();
}

void APlayerControllerBase::ResetInteractEvent(EInteractEvent InteractEvent)
{
	GetOnInteractEvent(InteractEvent,false) = GetOnInteractEvent(InteractEvent,true);
}

void APlayerControllerBase::SetDefaultInteractEvent(EInteractEvent InteractEvent, const FOnInputEventSingleSignature& NewDefaultEvent)
{
	GetOnInteractEvent(InteractEvent,true).AddUnique(NewDefaultEvent);
}


FOnInputEventSignature& APlayerControllerBase::GetOnInteractEvent(EInteractEvent InteractEvent, bool GetSavedEvent)
{
	switch (InteractEvent)
	{
	case EInteractEvent::EIE_InteractStart:
		return GetSavedEvent ? LastOnInteractStartEvent : OnInteractStartEvent;
	case EInteractEvent::EIE_InteractFinish:
		return GetSavedEvent ? LastOnInteractFinishEvent : OnInteractFinishEvent;
	}
	UE_LOG(LogTemp, Error, TEXT("If you see this message, then Something went wrong in GetOnInteractEvent Function inside PlayerControllerBase, Please Tell Einar about it"))
	return OnInteractStartEvent;
}
