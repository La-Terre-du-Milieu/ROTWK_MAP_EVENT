Object MBMMGateA
	CommandSet			= CastleGateCommandSet_NoSellNew
	ReplaceModule ModuleTag_05
		Body						= ActiveBody ModuleTag_05New
			MaxHealth				= 18000.0
			MaxHealthDamaged		= 12600.0
			MaxHealthReallyDamaged  = 5400.0
		End
	End
END

Object MBMMGateB
	CommandSet			= CastleGateCommandSet_NoSellNew
	ReplaceModule ModuleTag_05
		Body						= ActiveBody ModuleTag_05New
			MaxHealth				= 18000.0
			MaxHealthDamaged		= 12600.0
			MaxHealthReallyDamaged  = 5400.0
		End
	End
END

CommandSet CastleGateCommandSet_NoSellNew
	1 = Command_ToggleGate
End
