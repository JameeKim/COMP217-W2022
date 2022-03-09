// Dohyun Kim (301058465)

using UnrealBuildTool;
using System.Collections.Generic;

public class UE4ProjectEditorTarget : TargetRules
{
	public UE4ProjectEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "UE4Project" } );
	}
}
