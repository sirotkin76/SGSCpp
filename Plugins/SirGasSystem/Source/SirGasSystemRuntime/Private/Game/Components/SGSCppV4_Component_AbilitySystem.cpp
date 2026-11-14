// Copyright (c) 2026 SirotkinAleksandr. All Rights Reserved.


#include "Game/Components/SGSCppV4_Component_AbilitySystem.h"
#include "Game/SGSCppV4_Character.h"
#include "Abilities/SGSCppV4_AttributeSet.h"
#include "AbilitySystemGlobals.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Actor.h"
#include "DataAssets/SGSCppV4_DataAsset_Attr_Slot_Skill.h"
#include "DataAssets/SGSCppV4_DataAsset_Attr_Init_Character.h"


USGSCppV4_Component_AbilitySystem::USGSCppV4_Component_AbilitySystem()
{
}

USGSCppV4_AttributeSet* USGSCppV4_Component_AbilitySystem::FSGSCppV4_AttributeSet_Get()
{
	if (!IsValid(AttributeSet))
	{
		AttributeSet = ISGSCppV4_Interface_GameplayAbility::Execute_FSGSCppV4_Interface_AttributeSet_Get(GetOwner());
			//Cast<USGSCppV4_AttributeSet>(GetOwner()->FindComponentByClass<USGSCppV4_AttributeSet>());
		
		if (IsValid(AttributeSet)) return AttributeSet;
		
		UE_LOG(LogTemp, Error, TEXT("AttributeSet: Unknown node type"));
		return nullptr;
	}
	
	return AttributeSet;
}

void USGSCppV4_Component_AbilitySystem::BeginPlay()
{
	Super::BeginPlay();

	AttributeSet = FSGSCppV4_AttributeSet_Get();
}

void USGSCppV4_Component_AbilitySystem::GetActiveAbilitiesWithTags(const FGameplayTagContainer& GameplayTagContainer,
                                                                  TArray<UGameplayAbility*>& ActiveAbilities)
{
	TArray<FGameplayAbilitySpec*> AbilitiesToActivate;
	GetActivatableGameplayAbilitySpecsByAllMatchingTags(GameplayTagContainer, AbilitiesToActivate, false);

	// Iterate the list of all ability specs
	for (FGameplayAbilitySpec* Spec : AbilitiesToActivate)
	{
		// Iterate all instances on this ability spec
		TArray<UGameplayAbility*> AbilityInstances = Spec->GetAbilityInstances();

		for (UGameplayAbility* ActiveAbility : AbilityInstances)
		{
			ActiveAbilities.Add(Cast<UGameplayAbility>(ActiveAbility));
		}
	}
}

int32 USGSCppV4_Component_AbilitySystem::GetDefaultAbilityLevel() const
{
	if (IsValid(AttributeSet)) return AttributeSet->GetLevel();
	return 0;
}

USGSCppV4_Component_AbilitySystem* USGSCppV4_Component_AbilitySystem::GetAbilitySystemComponentFromActor(const AActor* Actor,
	bool LookForComponent)
{
	return Cast<USGSCppV4_Component_AbilitySystem>(UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Actor, LookForComponent));
}

void USGSCppV4_Component_AbilitySystem::RemoveStartupGameplayAbilities()
{
	//check(GetAbilitySystemComponent());

	if (bAbilitiesInitialized)
	{
		// Remove any abilities added from a previous call
		TArray<FGameplayAbilitySpecHandle> AbilitiesToRemove;

		for (const FGameplayAbilitySpec& Spec : GetActivatableAbilities())
		{
			if (!IsValid(SGSCppV4_DataAsset_Init)) return;
			
			if ((Spec.SourceObject == this) && V4_GameplayAbilityClasses.Contains(Spec.Ability->GetClass()))
			{
				AbilitiesToRemove.Add(Spec.Handle);
				V4_GameplayAbilityClasses.Remove(Spec.Ability->GetClass());
			}
		}

		// Do in two passes so the removal happens after we have the full list
		for (int32 i = 0; i < AbilitiesToRemove.Num(); i++)
		{
			ClearAbility(AbilitiesToRemove[i]);
			
		}

		// Remove all of the passive gameplay effects that were applied by this character
		FGameplayEffectQuery Query;
		Query.EffectSource = this;
		
		RemoveActiveEffects(Query);

	}
}

void USGSCppV4_Component_AbilitySystem::FSGSCppV4_Skill_Add(FSGSCppV4Slot DataAsset_Skill)
{
	if (!IsValid(DataAsset_Skill.PrimaryDataAsset)) return;
	
	USGSCppV4_DataAsset_Attr_Slot_Skill * SGSCppV4_InvSlot_DataAssetL = Cast<USGSCppV4_DataAsset_Attr_Slot_Skill>(DataAsset_Skill.PrimaryDataAsset);
	
	if (SGSCppV4_InvSlot_DataAssetL->GameplayEffect)		FSGSCppV4_GameplayEffect_Add(		SGSCppV4_InvSlot_DataAssetL->GameplayEffect,		DataAsset_Skill.Level);
	if (SGSCppV4_InvSlot_DataAssetL->GameplayAbility)		FSGSCppV4_Ability_Add(				SGSCppV4_InvSlot_DataAssetL->GameplayAbility,		DataAsset_Skill.Level);
		
}

void USGSCppV4_Component_AbilitySystem::FSGSCppV4_Skill_Del(FSGSCppV4Slot DataAsset_Skill)
{
	if (!IsValid(DataAsset_Skill.PrimaryDataAsset)) return;
	
	USGSCppV4_DataAsset_Attr_Slot_Skill * SGSCppV4_InvSlot_DataAssetL = Cast<USGSCppV4_DataAsset_Attr_Slot_Skill>(DataAsset_Skill.PrimaryDataAsset);
	
	if (SGSCppV4_InvSlot_DataAssetL->GameplayEffect)
	{
		FSGSCppV4_Effects_Update_UsePlayerLevel_Del(SGSCppV4_InvSlot_DataAssetL->GameplayEffect);
	}
	
	if (SGSCppV4_InvSlot_DataAssetL->GameplayAbility)
	{
		FSGSCppV4_Ability_Del(SGSCppV4_InvSlot_DataAssetL->GameplayAbility);
	}
}

void USGSCppV4_Component_AbilitySystem::FSGSCppV4_Effects_Update_UsePlayerLevel_Add(
	TSubclassOf<UGameplayEffect> inEffects_Update_UsePlayerLevel)
{
	int32 IndexL = Effects_Update_UsePlayerLevel.Find(inEffects_Update_UsePlayerLevel.Get());
	
	if (IndexL != INDEX_NONE)
	{
		Effects_Update_UsePlayerLevel.Add(inEffects_Update_UsePlayerLevel);
		FSGSCppV4_GameplayEffect_Add(inEffects_Update_UsePlayerLevel, FSGSCppV4_Attr_Level_Get());
	}
}

void USGSCppV4_Component_AbilitySystem::FSGSCppV4_Effects_Update_UsePlayerLevel_Del(
	TSubclassOf<UGameplayEffect> inEffects_Update_UsePlayerLevel)
{
	int32 IndexL = Effects_Update_UsePlayerLevel.Find(inEffects_Update_UsePlayerLevel.Get());
	
	if (IndexL != INDEX_NONE)
	{
		// Remove all of the passive gameplay effects that were applied by this character
		FGameplayEffectQuery Query;
		Query.EffectSource = this;
		Query.EffectDefinition = inEffects_Update_UsePlayerLevel;
		
		RemoveActiveEffects(Query);
		
		Effects_Update_UsePlayerLevel.RemoveAt(IndexL);
	}
}

void USGSCppV4_Component_AbilitySystem::FSGSCppV4_Abilities_Tag_Get(FGameplayTagContainer AbilityTags,
                                                                   TArray<UGameplayAbility*>& ActiveAbilities)
{
	GetActiveAbilitiesWithTags(AbilityTags, ActiveAbilities);
}

bool USGSCppV4_Component_AbilitySystem::FSGSCppV4_Ability_Cooldown_Tag_Get(FGameplayTagContainer CooldownTags,
	float& TimeRemaining, float& CooldownDuration)
{
	if (CooldownTags.Num() > 0)
	{
		TimeRemaining = 0.f;
		CooldownDuration = 0.f;

		FGameplayEffectQuery const Query = FGameplayEffectQuery::MakeQuery_MatchAnyOwningTags(CooldownTags);
		TArray< TPair<float, float> > DurationAndTimeRemaining = GetActiveEffectsTimeRemainingAndDuration(Query);
		if (DurationAndTimeRemaining.Num() > 0)
		{
			int32 BestIdx = 0;
			float LongestTime = DurationAndTimeRemaining[0].Key;
			for (int32 Idx = 1; Idx < DurationAndTimeRemaining.Num(); ++Idx)
			{
				if (DurationAndTimeRemaining[Idx].Key > LongestTime)
				{
					LongestTime = DurationAndTimeRemaining[Idx].Key;
					BestIdx = Idx;
				}
			}

			TimeRemaining = DurationAndTimeRemaining[BestIdx].Key;
			CooldownDuration = DurationAndTimeRemaining[BestIdx].Value;

			return true;
		}
	}
	return false;
}

void USGSCppV4_Component_AbilitySystem::FSGSCppV4_Attr_Base_Get(float& AttackPower, float& DefensePower,
	float& MoveSpeed, float& Damage, int32& Level)
{
	if (!IsValid(AttributeSet)) return;

	AttackPower = AttributeSet->GetAttackPower();
	DefensePower = AttributeSet->GetDefensePower();
	MoveSpeed = AttributeSet->GetMoveSpeed();
	Damage = AttributeSet->GetDamage();
	
	Level = FSGSCppV4_Attr_Level_Get();
}

int32 USGSCppV4_Component_AbilitySystem::FSGSCppV4_Attr_Level_Get()
{
	if (IsValid(AttributeSet)) return AttributeSet->GetLevel();
	return 0;
}

int32 USGSCppV4_Component_AbilitySystem::FSGSCppV4_Attr_Point_Get()
{
	if (IsValid(AttributeSet)) return AttributeSet->GetPoint();
	return 0;
}

void USGSCppV4_Component_AbilitySystem::FSGSCppV4_Attr_Health_Get(float& Health, float& HealthMax, float& Percent)
{
	if (!IsValid(AttributeSet)) return;
	
	Health = AttributeSet->GetHealth();
	HealthMax = AttributeSet->GetMaxHealth();
	Percent = Health / HealthMax;
}

void USGSCppV4_Component_AbilitySystem::FSGSCppV4_Attr_Stamina_Get(float& Stamina, float& StaminaMax, float& Percent)
{
	if (!IsValid(AttributeSet)) return;
	
	Stamina = AttributeSet->GetStamina();
	StaminaMax = AttributeSet->GetMaxStamina();
	Percent = Stamina / StaminaMax;
}

void USGSCppV4_Component_AbilitySystem::FSGSCppV4_Attr_Mana_Get(float& Mana, float& ManaMax, float& Percent)
{
	if (!IsValid(AttributeSet)) return;
	
	Mana = AttributeSet->GetMana();
	ManaMax = AttributeSet->GetMaxMana();
	Percent = Mana / ManaMax;
}

void USGSCppV4_Component_AbilitySystem::FSGSCppV4_Attr_Experience_Get(float& Experience, float& ExperienceMax,
	float& Percent)
{
	if (!IsValid(AttributeSet)) return;
	
	Experience = AttributeSet->GetExperienceCur();
	ExperienceMax = AttributeSet->GetExperienceMax();
	Percent = Experience / ExperienceMax;
}

void USGSCppV4_Component_AbilitySystem::FSGSCppV4_Attr_Water_Get(float& Water, float& WaterMax, float& Percent)
{
	if (!IsValid(AttributeSet)) return;
	
	Water = AttributeSet->GetWater();
	WaterMax = AttributeSet->GetMaxWater();
	Percent = Water / WaterMax;
}

void USGSCppV4_Component_AbilitySystem::FSGSCppV4_Attr_Food_Get(float& Food, float& FoodMax, float& Percent)
{
	if (!IsValid(AttributeSet)) return;
	
	Food = AttributeSet->GetFood();
	FoodMax = AttributeSet->GetMaxFood();
	Percent = Food / FoodMax;
}

void USGSCppV4_Component_AbilitySystem::FSGSCppV4_Attr_Oxygen_Get(float& Oxygen, float& OxygenMax, float& Percent)
{
	if (!IsValid(AttributeSet)) return;

	Oxygen = AttributeSet->GetOxygen();
	OxygenMax = AttributeSet->GetMaxOxygen();
	Percent = Oxygen / OxygenMax;
}

bool USGSCppV4_Component_AbilitySystem::FSGSCppV4_Abilities_Tags_Activate(FGameplayTagContainer AbilityTags,
                                                                         bool bAllowRemoteActivation)
{
	return TryActivateAbilitiesByTag(AbilityTags, bAllowRemoteActivation);
}

bool USGSCppV4_Component_AbilitySystem::FSGSCppV4_Ability_Tag_Activate(FGameplayTag AbilityTagL,
                                                                      bool bAllowRemoteActivation)
{
	FGameplayTagContainer GameplayTagContainer;
	GameplayTagContainer.AddTag(AbilityTagL);
	// bAbilitiesInitialized
	return TryActivateAbilitiesByTag(GameplayTagContainer, bAllowRemoteActivation);
}

void USGSCppV4_Component_AbilitySystem::FSGSCppV4_Ability_Tag_Cancel(FGameplayTag AbilityTag)
{
	FGameplayTagContainer GameplayTagContainer;
	GameplayTagContainer.AddTag(AbilityTag);

	TArray<FGameplayAbilitySpecHandle> AbilitiesToRemove;

	for (const FGameplayAbilitySpec& Spec : GetActivatableAbilities())
	{
		if (Spec.Ability->GetAssetTags().HasTag(AbilityTag))
		{
			CancelAbilities(&GameplayTagContainer, nullptr, nullptr);
		}
	}
}

void USGSCppV4_Component_AbilitySystem::FSGSCppV4_Abilities_Tags_Find(FGameplayTagContainer AbilityTags,
	bool& AbilitiesIsFind)
{
	TArray<UGameplayAbility*> GetActiveAbilitiesLocal;
	
	FSGSCppV4_Abilities_Tag_Get(AbilityTags, GetActiveAbilitiesLocal);
	
	if (GetActiveAbilitiesLocal.IsEmpty())	AbilitiesIsFind = false; else AbilitiesIsFind = true;
}

void USGSCppV4_Component_AbilitySystem::FSGSCppV4_Effects_Update()
{
	for (TSubclassOf<UGameplayEffect>& GameplayEffect : Effects_Update_UsePlayerLevel)
	{
		FSGSCppV4_GameplayEffect_Add(GameplayEffect, FSGSCppV4_Attr_Level_Get());
	}
}

void USGSCppV4_Component_AbilitySystem::FSGSCppV4_Game_New_Init_Attr()
{
	// check(GetAbilitySystemComponent());

	FSGSCppV4_Init();
	
	if (!IsValid(SGSCppV4_DataAsset_Init)) return;
	
	if (GetOwner()->GetLocalRole() == ROLE_Authority && !bAbilitiesInitialized)
	{
		// Grant abilities, but only on the server	
		for (TSubclassOf<UGameplayAbility>& StartupAbility : SGSCppV4_DataAsset_Init->Abilities)
		{
			//GetAbilitySystemComponent()->GiveAbility(FGameplayAbilitySpec(StartupAbility, CharacterLevel, INDEX_NONE, this));
			
			FSGSCppV4_Ability_Add(StartupAbility, 1);
		}

		// Now apply passives
		for (TSubclassOf<UGameplayEffect>& GameplayEffect : SGSCppV4_DataAsset_Init->Effects)
		{
			FSGSCppV4_GameplayEffect_Add(GameplayEffect, 1);
			
			//FGameplayEffectContextHandle EffectContext = MakeEffectContext();
			//EffectContext.AddSourceObject(this);
			//GEngine->AddOnScreenDebugMessage(-1, 50.f, FColor::Red, TEXT("3GameplayEffects")); // print string
			//FGameplayEffectSpecHandle NewHandle = MakeOutgoingSpec(GameplayEffect, 1, EffectContext);
			
			//if (NewHandle.IsValid())
			//{
				//FActiveGameplayEffectHandle ActiveGEHandle = ApplyGameplayEffectSpecToTarget(*NewHandle.Data.Get(), this);

			//}
		}
		//AddGameplayAbilities();

		for (USGSCppV4_DataAsset_Attr_Slot_Skill* StartupAbility : SGSCppV4_DataAsset_Init->DataAsset_Abilities)
		{
			FSGSCppV4_Ability_Update local;
			
			local.SGSCppV4_DataAsset_Attr_Ability = StartupAbility;
			local.AbiltyLevel = 1;

			if (StartupAbility->GameplayEffect)		FSGSCppV4_GameplayEffect_Add(	StartupAbility->GameplayEffect, 1);
			if (StartupAbility->GameplayAbility)	FSGSCppV4_Ability_Add(			StartupAbility->GameplayAbility, 1);
			
		}

		Effects_Update_UsePlayerLevel = SGSCppV4_DataAsset_Init->Effects_Update_UsePlayerLevel;

		bAbilitiesInitialized = true;
	}
}

bool USGSCppV4_Component_AbilitySystem::FSGSCppV4_Ability_Add(TSubclassOf<UGameplayAbility> NewGameplayAbility, int32 level)
{
	GiveAbility(FGameplayAbilitySpec(NewGameplayAbility, level, INDEX_NONE, this));
	
	UGameplayAbility* AbilityInstance = NewGameplayAbility.Get()->GetDefaultObject<UGameplayAbility>();

	V4_GameplayAbilityClasses.Add(AbilityInstance->GetClass());
	

	return true;	
}

void USGSCppV4_Component_AbilitySystem::FSGSCppV4_GameplayEffect_Add(TSubclassOf<UGameplayEffect> GameplayEffectL, int32 level)
{
	FGameplayEffectContextHandle EffectContext = MakeEffectContext();
	EffectContext.AddSourceObject(this);

	FGameplayEffectSpecHandle NewHandle =  MakeOutgoingSpec(GameplayEffectL, level, EffectContext);
	if (NewHandle.IsValid())
	{
		ApplyGameplayEffectSpecToTarget(*NewHandle.Data.Get(),  this);
	}
}

void USGSCppV4_Component_AbilitySystem::FSGSCppV4_Attr_Health_Set(float SetNewHealth)
{
	if (AttributeSet)
	{
		AttributeSet->SetHpAndMaxHp(SetNewHealth, AttributeSet->GetMaxHealth());
	}
}

void USGSCppV4_Component_AbilitySystem::FSGSCppV4_Attr_Level_Set(int32 NewLevel)
{
	if (FSGSCppV4_Attr_Level_Get() != NewLevel && NewLevel > 1)
	{
		AttributeSet->SetLevel(NewLevel);
		
		/*
		RemoveStartupGameplayAbilities();
		AddStartupGameplayAbilities();
		*/
		
	}
}

void USGSCppV4_Component_AbilitySystem::FSGSCppV4_Ability_Del(TSubclassOf <UGameplayAbility> UGameplayAbilityL)
{
	//if (AbilityTag.IsValid()) FSGSCppV4_Ability_Tag_Cancel(AbilityTag);

	if (V4_GameplayAbilityClasses.Num() <= 0) return;
	if (V4_GameplayAbilityClasses.Contains(UGameplayAbilityL) == false) return;
	if (!IsValid(UGameplayAbilityL)) return;

	if (GetActivatableAbilities().Num()<=0) return;
	

	TArray<FGameplayAbilitySpecHandle> AbilitiesToRemove;
	
	for (const FGameplayAbilitySpec& Spec : GetActivatableAbilities())
	{
		if ((Spec.SourceObject == this) && Spec.Ability.GetClass() == UGameplayAbilityL)
		{
			AbilitiesToRemove.Add(Spec.Handle);
			ClearAbility(Spec.Handle);
			V4_GameplayAbilityClasses.Remove(Spec.Ability->GetClass());

			return;
			
		}
	}

	/*
	// Remove all of the passive gameplay effects that were applied by this character
	FGameplayEffectQuery Query;
	Query.EffectSource = this;
	
	RemoveActiveEffects(Query);
	*/

}
