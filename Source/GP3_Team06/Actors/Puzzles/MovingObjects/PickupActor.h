// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GP3_Team06/Actors/Puzzles/KeyActor.h"
#include "PickupActor.generated.h"

class UDraggingMovementComponent;
class UPickupComponent;

UCLASS()
class GP3_TEAM06_API APickupActor : public AKeyActor
{
	GENERATED_BODY()

public:
	APickupActor();

	virtual void Interact_Implementation(AActor* Interacter) override;

	virtual void BeginPlay() override;
	virtual void TickActor(float DeltaTime, ELevelTick TickType, FActorTickFunction& ThisTickFunction) override;
protected:
	UFUNCTION(BlueprintNativeEvent, Category = "PickupActor")
	void DropItem();
private:
	FVector CalculateLocationToReach() const;


protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category ="Components")
	UPickupComponent* PickupComponent;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category ="Components")
	UDraggingMovementComponent* DraggingMovementComponent;

private:
	//Distance between a held object and the player
	UPROPERTY(EditAnywhere, Category = "PickupActor")
	float HoldDistance = 200;
};
