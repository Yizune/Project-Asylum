#pragma once

#include "CoreMinimal.h"
#include "HelperStructs.generated.h"

USTRUCT(BlueprintType)
struct FQuestObjective
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "QuestObjective")
	FString Description;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "QuestObjective")
	FString Comments;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "QuestObjective")
	bool YesColumn;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "QuestObjective")
	bool NoColumn;
	
};