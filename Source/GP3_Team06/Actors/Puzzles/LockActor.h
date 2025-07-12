// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GP3_Team06/Actors/ActorBase.h"
#include "LockActor.generated.h"

UCLASS()
class GP3_TEAM06_API ALockActor : public AActorBase
{
	GENERATED_BODY()

public:
	ALockActor();

	//Override this function to check if the door should be able to open using CanOpenThisLock() function
	//By default Instigator is the actor that is IKeyContainer.
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable, Category = "Lock", DisplayName = "TryOpenLock")
	bool TryOpenThisLock(AActor* InInstigator);
protected:
	//Override this function to specify what should Happen when this lock is opened
	//By default Instigator is the actor that is IKeyContainer.
	UFUNCTION(BlueprintNativeEvent, Category = "Lock", DisplayName = "OpenLock")
	void OpenThisLock(AActor* InInstigator);
	//Override this function to define the condition for this lock to be opened
	//By default Instigator is the actor that is IKeyContainer.
	UFUNCTION(BlueprintNativeEvent, Category = "Lock", DisplayName = "CanOpenLock")
	bool CanOpenThisLock(AActor* InInstigator);
private:
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Lock", meta = (AllowPrivateAccess = "true"))
	bool RequiresMultipleKeys = true;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Lock", meta = (EditCondition = "RequiresMultipleKeys",EditConditionHides, Categories  ="Key",AllowPrivateAccess = "true"))
	FGameplayTagContainer RequiredKeys;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Lock", meta = (EditCondition = "!RequiresMultipleKeys",EditConditionHides, Categories  ="Key",AllowPrivateAccess = "true"))
	FGameplayTag RequiredKey;
};
