// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMathLibrary.h"

FVector UGameMathLibrary::GetDirectionVectorToVector(const FVector From, const FVector To, const bool Normalize)
{
	return Normalize? (To-From).GetSafeNormal() : (To-From);
}

FVector UGameMathLibrary::GetDirectionActorToActor(AActor* From, AActor* To, const bool Normalize)
{
	if (!From || !To)
	{
		return FVector();
	}
	return GetDirectionVectorToVector(From->GetActorLocation(), To->GetActorLocation(),Normalize);
}

float UGameMathLibrary::GetAngleBetweenVectors(FVector A, FVector B, bool GetInDeg, bool GetFullCircle)
{
	A.Normalize();
	B.Normalize();
	const float DotProduct = FVector::DotProduct(A, B);
	const float Angle = GetInDeg ? FMath::RadiansToDegrees(FMath::Acos(DotProduct)) : FMath::Acos(DotProduct);
	if (!GetFullCircle)
	{
		return Angle;
	}
	return FVector::CrossProduct(A, B).Z < 0.f ? -Angle : Angle;
}
