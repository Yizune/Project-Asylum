// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GP3_Team06/Delegates/InputDelegates.h"
#include "PlayerControllerBase.generated.h"

struct FInputActionValue;
class UInputAction;
class UInputMappingContext;

UENUM()
enum class EInteractEvent : uint8
{
	EIE_InteractStart UMETA(DisplayName = "Interact Start"),
	EIE_InteractFinish UMETA(DisplayName = "Interact Finish"),
	
};

/**
 * 
 */
UCLASS()
class GP3_TEAM06_API APlayerControllerBase : public APlayerController
{
	GENERATED_BODY()
public:
	//Interact event
	
	UFUNCTION(BlueprintCallable)
	void AddInteractEvent(EInteractEvent InteractEvent,const FOnInputEventSingleSignature& Event, bool bOverride = false);
	UFUNCTION(BlueprintCallable)
	void RemoveInteractEvent(EInteractEvent InteractEvent,const FOnInputEventSingleSignature& Event);
	UFUNCTION(BlueprintCallable)
	void ClearInteractEvent(EInteractEvent InteractEvent, bool SaveLastInputEvent = true);
	UFUNCTION(BlueprintCallable)
	void ResetInteractEvent(EInteractEvent InteractEvent);
	UFUNCTION(BlueprintCallable)
	void SetDefaultInteractEvent(EInteractEvent InteractEvent,const FOnInputEventSingleSignature& NewDefaultEvent);

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

protected:
	//Input Functions:
	UFUNCTION(BlueprintNativeEvent, Category = "Player Controller Base")
	void Look(const FInputActionValue& Value);
	UFUNCTION(BlueprintNativeEvent, Category = "Player Controller Base")
	void Move(const FInputActionValue& Value);
	UFUNCTION(BlueprintNativeEvent, Category = "Player Controller Base")
	void InteractStart();
	UFUNCTION(BlueprintNativeEvent, Category = "Player Controller Base")
	void InteractFinish();
private:
	

	FOnInputEventSignature& GetOnInteractEvent(EInteractEvent InteractEvent, bool GetSavedEvent);
	
	void SetupMappingContext();
	void BindActions();
protected:
	UPROPERTY(BlueprintAssignable)
	FOnInputEventSignature OnInteractStartEvent;
	UPROPERTY(BlueprintAssignable)
	FOnInputEventSignature OnInteractFinishEvent;
	
private:
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Player Controller Base|Setup", meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Player Controller Base|Setup", meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Player Controller Base|Setup", meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveSprintAction;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Player Controller Base|Setup", meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Player Controller Base|Setup", meta = (AllowPrivateAccess = "true"))
	UInputAction* InteractAction;

private:
	
	//Interact events saved for a reset
	FOnInputEventSignature LastOnInteractStartEvent;
	FOnInputEventSignature LastOnInteractFinishEvent;

};
