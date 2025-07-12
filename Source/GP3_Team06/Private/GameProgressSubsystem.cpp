// Fill out your copyright notice in the Description page of Project Settings.


#include "GameProgressSubsystem.h"

EObjective UGameProgressSubsystem::GetCurrentObjective()
{
	return CurrentObject;
}

void UGameProgressSubsystem::ChangeObjective(const EObjective NextObjective)
{
	CurrentObject = NextObjective;
	ObjectiveChanged.Broadcast(CurrentObject);
	NotifyPlayerOnObjectiveChanged.Broadcast();
	
}

