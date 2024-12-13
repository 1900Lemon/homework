// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MyFPSHw : ModuleRules
{
	public MyFPSHw(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput","OnlineSubsystem","HeadMountedDisplay","MoviePlayer","UMG"
			,"Slate",
			"SlateCore"
		});
		PrivateDependencyModuleNames.AddRange(new string[]{});
	}
}
