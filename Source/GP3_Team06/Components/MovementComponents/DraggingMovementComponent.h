// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/MovementComponent.h"
#include "GP3_Team06/Interfaces/Interactable.h"
#include "DraggingMovementComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable,
	HideCategories = ("ComponentTick", "ComponentReplication", "Collision","Replication","AssetUserData","Cooking","PlanarMovement"))
class GP3_TEAM06_API UDraggingMovementComponent : public UMovementComponent
{
	GENERATED_BODY()

public:
	UDraggingMovementComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void BeginPlay() override;


	UFUNCTION(BlueprintCallable, Category = "Dragging Movement")
	void ToggleComponent(bool bTurnOn);


	
	UFUNCTION(BlueprintCallable, Category = "Dragging Movement")
	void SetLocationToReach(const FVector& NewLocation) { LocationToReach = NewLocation;}
	UFUNCTION(BlueprintCallable,BlueprintPure, Category = "Dragging Movement")
	const FVector& GetLocationToReach() const { return LocationToReach;}

private:
	FVector CalculateDeltaMovement(float DeltaTime);
	FVector ConstrainVector(const FVector& VectorToConstrain);
protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category ="Dragging Movement" , meta = (ClampMin = 0,  UIMin = 0))
	float DragSpeed = 300;
private:
	UPROPERTY(VisibleAnywhere, Category = "Dragging Movement")
	FVector LocationToReach;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category ="Dragging Movement" , meta = (ClampMin = 0, ClampMax =1, UIMin = 0, UIMax = 1, AllowPrivateAccess = "true"))
	FIntVector MovementConstraints;
};
