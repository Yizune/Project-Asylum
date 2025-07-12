// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTaskOwnerInterface.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

UCLASS(DisplayName = "Character Base", meta = (ShortToolTip ="Character Class to use for GP3 - Team 6 , A character is a type of Pawn that includes the ability to walk around."))
class GP3_TEAM06_API ACharacterBase : public ACharacter,public IGameplayTaskOwnerInterface
{
	GENERATED_BODY()

public:
	ACharacterBase(const FObjectInitializer& ObjectInitializer);


	//IGameplayTaskOwnerInterface

	virtual AActor* GetGameplayTaskOwner(const UGameplayTask* Task) const override {return const_cast<ACharacterBase*>(this);}
	// End IGameplayTaskOwnerInterface
};
