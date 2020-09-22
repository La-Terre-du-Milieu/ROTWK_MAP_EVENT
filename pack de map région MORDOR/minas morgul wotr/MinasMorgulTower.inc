;special Power (to change duration and sound)
SpecialPower SpecialAbilityMenFortressIvoryTowerVision
	Enum				= SPECIAL_SPELL_BOOK_PALANTIR_VISION
	ReloadTime			= 120000 ; in milliseconds (CHANGE)
	InitiateAtLocationSound       = FireStorm
End

FXParticleSystem MinasMorgulBlast
  System
    Priority = ALWAYS_RENDER
    ParticleName = EXHPgranada.tga
    Lifetime = 30 30
    SystemLifetime = 5
    BurstCount = 1 1
    InitialDelay = 20 20
    IsGroundAligned = Yes
  End
  Color = DefaultColor
    Color2 = R:72 G:255 B:72 10
    Color3 = R:0 G:0 B:0 30
  End
  Update = DefaultUpdate
    SizeRate = 20 30
    SizeRateDamping = 0.1 0.1
    AngleZ = 0 7
    AngularDamping = 1 1
    AngularDampingXY = 1 1
  End
  Physics = DefaultPhysics
    Gravity = 0.08
    VelocityDamping = 0.8 0.85
  End
  EmissionVelocity = OutwardEmissionVelocity
  End
  EmissionVolume = LineEmissionVolume
    StartPoint = X:0 Y:0 Z:10
    EndPoint = X:0 Y:0 Z:15
  End
  Draw = DefaultDraw
  End
End

Object WOR_MBMMTower
	AddModule
		Behavior = UnpauseSpecialPowerUpgrade ModuleTag_IvoryTowerVisionEnabler
			SpecialPowerTemplate = SpecialAbilityMenFortressIvoryTowerVision
			TriggeredBy = Upgrade_MenFortressIvoryTower
		End
	End
	AddModule
		Behavior				 = OCLSpecialPower ModuleTag_IvoryTowerVision
			SpecialPowerTemplate = SpecialAbilityMenFortressIvoryTowerVision
			StartsPaused		 = Yes
			OCL                  = SpecialPowerIvoryTowerVision
			CreateLocation       = CREATE_AT_LOCATION
		End
	End
END
ObjectCreationList SpecialPowerIvoryTowerVision
  CreateObject
    ObjectNames = IvoryTowerVisionPing
    Count = 1
	ParticleSystem	= MinasMorgulBlast
  End
End
;the fake object that applies the bonus/malus
Object IvoryTowerVisionPing
	
	ReplaceModule ModuleTag_LifetimeUpdate
		Behavior = LifetimeUpdate ModuleTag_LifetimeUpdateNew
			MinLifetime		= 30000 ; 30sec
			MaxLifetime		= 30000
		End	
	End
	AddModule 
		Behavior = AttributeModifierAuraUpdate ModuleTag_DebuffOne
			StartsActive	= Yes				//If no, requires upgrade to turn on.
			TargetEnemy		= Yes
			AntiCategory	= LEADERSHIP BUFF
			BonusName		= GenericDebuff
			RefreshDelay	= 2000
			Range			= 99999.0
			ObjectFilter	= ANY +INFANTRY +CAVALRY -STRUCTURE -BASE_FOUNDATION  -HERO -HORDE
		End	
	End
	AddModule 
		Behavior = AttributeModifierAuraUpdate ModuleTag_Leadership
			StartsActive		= Yes ;If no, requires upgrade to turn on.
			BonusName		= GenericHeroLeadership
			RefreshDelay		= 2000
			Range			= 99999.0
			AntiCategory	= BUFF
			ObjectFilter		= GENERIC_BUFF_RECIPIENT_OBJECT_FILTER
		End
	End
	
End
;Change image of button
MappedImage BGFortress_UseIvoryTower ;Morgul Image
  Texture = BuildingRadialButtons_173.tga
  TextureWidth = 256
  TextureHeight = 256
  Coords = Left:0 Top:192 Right:64 Bottom:256
  Status = NONE
End

;The Button
CommandButton Command_SpecialAbilityIvoryTowerVision
	Command			= SPECIAL_POWER
	SpecialPower		= SpecialAbilityMenFortressIvoryTowerVision
	Options			= HIDE_WHILE_DISABLED ;NEED_TARGET_POS
    ButtonImage		= BGFortress_UseIvoryTower	
	TextLabel		= CONTROLBAR:HelmsHorn
	ButtonBorderType	= ACTION
	DescriptLabel		= CONTROLBAR:TooltipHelmsHorn
	RadiusCursorType    	= PalantirVisionRadiusCursor
	Radial			= Yes
	InPalantir		= Yes
End