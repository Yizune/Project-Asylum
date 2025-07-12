// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TextRenderComponent.h"
#include "LookAtPlayerTextRender.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GP3_TEAM06_API ULookAtPlayerTextRender : public UTextRenderComponent
{
	GENERATED_BODY()

public:
	ULookAtPlayerTextRender();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
private:
	void LookAtPlayer();
};
