// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FlawlessAbbey : ModuleRules
{
	public FlawlessAbbey(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
