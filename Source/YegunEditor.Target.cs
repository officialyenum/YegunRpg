// Copyright Yenum dot dev

using UnrealBuildTool;
using System.Collections.Generic;

public class YegunEditorTarget : TargetRules
{
	public YegunEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "Yegun" } );
	}
}
