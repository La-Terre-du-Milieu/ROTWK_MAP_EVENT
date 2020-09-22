Upgrade Upgrade_HasWallTrebuchetNew
	Type			= OBJECT
	BuildCost		= 600
	BuildTime		= 10.0
	DisplayName		= Upgrade:ReplacementWeapon
End

CommandButton Command_MordorPurchaseNewWallCatapult
	Command					= OBJECT_UPGRADE 
	Upgrade					= Upgrade_HasWallTrebuchetNew
	Options					= CANCELABLE
	ButtonImage				= BMGreatSiegeWorks_Catapult
	ButtonBorderType		= UPGRADE 
	Radial					= Yes
	InPalantir	   			= Yes
	TextLabel				= CONTROLBAR:MordorCatapultUpgrade
	DescriptLabel			= CONTROLBAR:ToolTipMordorCatapultUpgrade
End
CommandSet GenericMinasMorgulBuyNewTrebCommandSetNew
	1 = Command_MordorPurchaseNewWallCatapult
End
Object MBMMWallC
	KindOf              = PRELOAD STRUCTURE IMMOBILE CHUNK_VENDOR  NOT_AUTOACQUIRABLE SELECTABLE  WALK_ON_TOP_OF_WALL IGNORE_FOR_VICTORY NEVER_CULL_FOR_MP DONT_HIDE_IF_FOGGED
	RemoveModule MakeTheFreeTreb
	CommandSet				= GenericMinasMorgulBuyNewTrebCommandSetNew
	ReplaceModule ModueTag_TrebCommandSet
		Behavior = CommandSetUpgrade ModueTag_TrebCommandSetNew
			TriggeredBy				= Upgrade_TrebuchetTurret
			ConflictsWith			= Upgrade_HasWallTrebuchetNew 
			CommandSet				= GenericMinasMorgulBuyNewTrebCommandSetNew
		End
	End

	AddModule
		Behavior = ObjectCreationUpgrade ModuleTag_MordorTreb2
			TriggeredBy				= Upgrade_HasWallTrebuchetNew Upgrade_MordorFaction
			RequiresAllTriggers		= Yes
			Delay					= 0.0		
			ThingToSpawn			= MordorMinasMorgulCatapult
			Offset					= X:100.0 Y:0.0 Z:125.0
			FadeInTime				= 600
		End
	End
END

Object MBMMWallAT
	CommandSet				= GenericMinasMorgulBuyNewTrebCommandSetNew;EmptyCommandSet
	AddModule
		Behavior = ProductionUpdate ProductionUpdateModuleTag
		End
	End
	AddModule
		Behavior = GrantUpgradeCreate ModuleTag_ActLikeAnOldUpgrade
			UpgradeToGrant			= Upgrade_TrebuchetTurret
			GiveOnBuildComplete		= Yes							; The ExemptStatus UnderConstruction hack doesn't work on foundation buildings.
		End
	End
	AddModule
		Behavior = CommandSetUpgrade ModueTag_TrebCommandSet
			TriggeredBy				= Upgrade_TrebuchetTurret
			ConflictsWith			= Upgrade_HasWallTrebuchetNew 
			CommandSet				= GenericMinasMorgulBuyNewTrebCommandSetNew
		End
	End
	AddModule
		Behavior = CommandSetUpgrade ModueTag_TrebSellCommandSet
			TriggeredBy				= Upgrade_HasWallTrebuchetNew Upgrade_TrebuchetTurret
			CommandSet				= EmptyCommandSet
			RequiresAllTriggers		= Yes
		End
	End
	;AddModule
	;	Behavior = ObjectCreationUpgrade MakeTheFreeTreb
	;		TriggeredBy				= Upgrade_TrebuchetTurret
	;		Delay					= 0
	;		GrantUpgrade			= Upgrade_HasWallTrebuchetNew
	;		DestroyWhenSold			= No
			;DeathAnimAndDuration	= AnimState:DEATH_2 AnimTime:999999
	;	End
	;End
	AddModule
		Behavior = ObjectCreationUpgrade ModuleTag_MordorTreb
			TriggeredBy				= Upgrade_HasWallTrebuchetNew Upgrade_MordorFaction
			RequiresAllTriggers		= Yes
			Delay					= 0.0		
			ThingToSpawn			= MordorMinasMorgulCatapult
			Offset					= X:40.0 Y:0.0 Z:104.0
			FadeInTime				= 600
		End
	End
	AddModule
		Behavior = SlaveWatcherBehavior WatchTheTreb
			RemoveUpgrade			= Upgrade_HasWallTrebuchetNew				; when our slave dies, remove this upgrade, so we can get the upgrade again.
		End
	End
END

Object MBMMWallA
	ReplaceModule ModuleTag_05
		Body						= ActiveBody ModuleTag_05New
			MaxHealth				= 10000.0
			MaxHealthDamaged		= 7000.0
			MaxHealthReallyDamaged  = 3000.0
		End
	End
END


Object MBMMWallA1
	ReplaceModule ModuleTag_05
		Body						= ActiveBody ModuleTag_05New
			MaxHealth				= 10000.0
			MaxHealthDamaged		= 7000.0
			MaxHealthReallyDamaged  = 3000.0
		End
	End
END
Object MBMMWallAB
	ReplaceModule ModuleTag_05
		Body						= ActiveBody ModuleTag_05New
			MaxHealth				= 10000.0
			MaxHealthDamaged		= 7000.0
			MaxHealthReallyDamaged  = 3000.0
		End
	End
END

Object MBMMWallAC
	KindOf              = PRELOAD STRUCTURE IMMOBILE CHUNK_VENDOR SELECTABLE  WALK_ON_TOP_OF_WALL IGNORE_FOR_VICTORY NEVER_CULL_FOR_MP DONT_HIDE_IF_FOGGED
	ReplaceModule ModuleTag_05
		Body						= ActiveBody ModuleTag_05New
			MaxHealth				= 10000.0
			MaxHealthDamaged		= 7000.0
			MaxHealthReallyDamaged  = 3000.0
		End
	End
END

Object MBMMWallB
	ReplaceModule ModuleTag_05
		Body						= ActiveBody ModuleTag_05New
			MaxHealth				= 10000.0
			MaxHealthDamaged		= 7000.0
			MaxHealthReallyDamaged  = 3000.0
		End
	End
END

Object MBMMWallB1
	ReplaceModule ModuleTag_05
		Body						= ActiveBody ModuleTag_05New
			MaxHealth				= 10000.0
			MaxHealthDamaged		= 7000.0
			MaxHealthReallyDamaged  = 3000.0
		End
	End
END
