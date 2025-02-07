// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomMovementComponent.h"

#include "GP3_Team06/DataAssets/MovementComponent/MovementComponentData.h"


UCustomMovementComponent::UCustomMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UCustomMovementComponent::InitializeComponent()
{
	Super::InitializeComponent();
	if (!MovementData)
	{
		return;
	}
	MovementData->InitializeCharacterMovementComponent(this);
}


