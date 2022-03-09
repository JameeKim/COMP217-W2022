// Dohyun Kim (301058465)

using UnrealBuildTool;
using System.Collections.Generic;

public class UE4ProjectTarget : TargetRules
{
	public UE4ProjectTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "UE4Project" } );
	}
}
