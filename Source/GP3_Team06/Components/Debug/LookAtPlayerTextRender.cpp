// Fill out your copyright notice in the Description page of Project Settings.


#include "LookAtPlayerTextRender.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"


ULookAtPlayerTextRender::ULookAtPlayerTextRender()
{
	PrimaryComponentTick.bCanEverTick = true;
	HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	VerticalAlignment = EVerticalTextAligment::EVRTA_TextCenter;
}

void ULookAtPlayerTextRender::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	LookAtPlayer();
}

void ULookAtPlayerTextRender::LookAtPlayer()
{
	const FVector PlayerLocation =  UGameplayStatics::GetPlayerPawn(GetOwner(),0)->GetActorLocation();
	
	SetWorldRotation(UKismetMathLibrary::FindLookAtRotation(GetComponentLocation(), PlayerLocation));
}
