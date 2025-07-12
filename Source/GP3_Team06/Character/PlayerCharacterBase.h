// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterBase.h"
#include "GP3_Team06/Delegates/InputDelegates.h"
#include "GP3_Team06/Interfaces/HaveEyes.h"
#include "GP3_Team06/Interfaces/KeyContainer.h"
#include "PlayerCharacterBase.generated.h"

enum class EInteractEvent : uint8;
class APlayerControllerBase;
class UInventoryComponent;

UCLASS()
class GP3_TEAM06_API APlayerCharacterBase : public ACharacterBase, public IKeyContainer, public IHaveEyes
{
	GENERATED_BODY()

public:
	APlayerCharacterBase(const FObjectInitializer& ObjectInitializer);

	APlayerCharacterBase();
	// KeyContainer Interface

	virtual bool AddKey(const FGameplayTag& NewKeyTag) override;
	virtual bool RemoveKey(const FGameplayTag& KeyTag) override;
	virtual const FGameplayTagContainer& GetContainedKeys() const override;
	virtual bool ContainsKeys(const FGameplayTagContainer& RequiredKeys) override;
	virtual bool ContainsKey(const FGameplayTag& RequiredKey) override;
	// End KeyContainer Interface
	// IHaveEyes Interface
	virtual UCameraComponent* GetCameraComponent_Implementation() override;
	// End IHaveEyes Interface



	virtual void BeginPlay() override;
	//Interact
	//This function allows you to add functionality to Interact Input,
	// if bOverrideInteract == true then you will remove all of the previous Interact functions.
	//You can restore default Interact Input by calling ResetInteractInputToDefault();
	
	UFUNCTION(BlueprintCallable,Category = "PlayerCharacterBase|Input|Interact", meta = (Keywords ="Add Interact Input"))
	void AddEventToInteractInput(const EInteractEvent InteractEvent,const FOnInputEventSingleSignature& Event, bool bOverrideInteract = false);
	UFUNCTION(BlueprintCallable, Category = "PlayerCharacterBase|Input|Interact", meta = (Keywords ="Remove Interact Input"))
	void RemoveEventFromInteractInput(const EInteractEvent InteractEvent,const FOnInputEventSingleSignature& Event);
	UFUNCTION(BlueprintCallable, Category = "PlayerCharacterBase|Input|Interact", meta = (Keywords ="Clear Input"))
	void ClearInteractInput(const EInteractEvent InteractEvent);
	UFUNCTION(BlueprintCallable, Category = "PlayerCharacterBase|Input|Interact",meta = (Keywords ="Reset Input"))
	void ResetInteractInputToDefault(const EInteractEvent InteractEvent);
	UFUNCTION(BlueprintNativeEvent, Category = "PlayerCharacterBase|Input|Interact")
	void DefaultInteractAction(APawn* PossessedPawn);
protected:
	UFUNCTION(BlueprintCallable,Category = "PlayerCharacterBase|Helpers", meta = (Keywords ="GetController"))
	APlayerControllerBase* GetPlayerControllerBase() const;
	
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player|Inventory")
	UInventoryComponent* InventoryComponent;
};
