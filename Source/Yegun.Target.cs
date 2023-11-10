// Copyright Yenum dot dev

using UnrealBuildTool;
using System.Collections.Generic;

public class YegunTarget : TargetRules
{
	public YegunTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "Yegun" } );
	}
}
