// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorBase.generated.h"


//Use this class if you want to have some Categories to be hidden so that the details panel looks cleaner
UCLASS(DisplayName = "Actor Base",meta = (ShortToolTip ="Use this class if you want to have some Categories to be hidden, so that the details panel looks cleaner"),
	HideCategories = (Replication, Input, HLOD, WorldPartition, Cooking, DataLayers))
class GP3_TEAM06_API AActorBase : public AActor
{
	GENERATED_BODY()

public:
	AActorBase();
};
