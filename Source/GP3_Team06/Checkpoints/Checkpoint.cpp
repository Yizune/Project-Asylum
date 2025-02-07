// Fill out your copyright notice in the Description page of Project Settings.


#include "Checkpoint.h"

#include "Resettable.h"
#include "Components/ArrowComponent.h"
#include "Kismet/KismetSystemLibrary.h"


ACheckpoint::ACheckpoint()
{
	PrimaryActorTick.bCanEverTick = true;
	ForwardArrow = CreateDefaultSubobject<UArrowComponent>("ForwardArrow");
}

void ACheckpoint::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	if (ShowResettableActors && ResettableActors.Num()>0)
	{
		UKismetSystemLibrary::FlushPersistentDebugLines(this);
		for (const auto& ResettableActor : ResettableActors)
		{
			if (!UKismetSystemLibrary::DoesImplementInterface(ResettableActor, UResettable::StaticClass()))
			{
				continue;
			}
			UKismetSystemLibrary::DrawDebugLine(this, GetActorLocation(),ResettableActor->GetActorLocation(),DebugColor,9999,2);
		}
	}
}

void ACheckpoint::ResetToThisCheckpoint(AActor* Player)
{
	for (const auto& ResettableActor : ResettableActors)
	{
		if (ResettableActor == nullptr || !ResettableActor->Implements<UResettable>())
		{
			continue;
		}
		IResettable::Execute_Reset(ResettableActor,this,Player);
	}
}

FVector ACheckpoint::GetRespawnLocation_Implementation()
{
	return GetActorLocation();
}
