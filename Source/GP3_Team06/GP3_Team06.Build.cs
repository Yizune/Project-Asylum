// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GP3_Team06 : ModuleRules
{
	public GP3_Team06(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput","GameplayTags" ,"GameplayTasks"});
	}
}
