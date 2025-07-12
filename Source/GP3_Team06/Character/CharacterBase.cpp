// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterBase.h"

#include "GP3_Team06/Components/MovementComponents/CustomMovementComponent.h"


ACharacterBase::ACharacterBase(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer.SetDefaultSubobjectClass<UCustomMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	PrimaryActorTick.bCanEverTick = true;
}


