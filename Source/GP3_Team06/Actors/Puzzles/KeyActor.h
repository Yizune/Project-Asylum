// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GP3_Team06/Actors/ActorBase.h"
#include "GP3_Team06/Interfaces/Interactable.h"
#include "KeyActor.generated.h"


USTRUCT(BlueprintType)
struct FKeyInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Key", meta = (Categories = "Key"))
	FGameplayTag KeyTag;
};

//Key actor is also a key container ???
UCLASS()
class GP3_TEAM06_API AKeyActor : public AActorBase, public IInteractable
{
	GENERATED_BODY()

public:
	AKeyActor();

private:
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Key", meta = (AllowPrivateAccess = "true"))
	FKeyInfo KeyInfo;
};
