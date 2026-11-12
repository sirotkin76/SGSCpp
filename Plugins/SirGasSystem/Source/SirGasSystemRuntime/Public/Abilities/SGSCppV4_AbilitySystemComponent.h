// Copyright (c) 2026 SirotkinAleksandr. All Rights Reserved.

#pragma once

#include "Engine.h"
#include "Net/UnrealNetwork.h"
#include "AbilitySystemComponent.h"
#include "SGSCppV4_AbilitySystemComponent.generated.h"

struct FSGSCppV4Slot;
struct FSGSCppV4_Ability_Update;

class USGSCppV4_AttributeSet;
class USGSCppV4_DataAsset_Attr_Skill;
class USGSCppV4_DataAsset_Attr_Character_Init;

/**
 * 
 */
 //UCLASS(meta=(BlueprintSpawnableComponent), Blueprintable, BlueprintType, meta = (ShowWorldContextPin))
UCLASS(ClassGroup=("FSGSCpp"), meta=(BlueprintSpawnableComponent), Blueprintable, BlueprintType, meta = (ShowWorldContextPin))
class SIRGASSYSTEMRUNTIME_API USGSCppV4_AbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY()
	USGSCppV4_AttributeSet* AttributeSet;
	
	UPROPERTY()
	bool bAbilitiesInitialized;
	
	UPROPERTY()
	bool bStartAttrIsActive;
	
	UPROPERTY()
	TArray<UGameplayAbility * > V4_ArrActiveAbilities;
	
	UPROPERTY()
	TArray<TSubclassOf<UGameplayEffect>> Effects_Update_UsePlayerLevel;
	
	UPROPERTY()
	TArray<TSubclassOf<UGameplayAbility>> V4_GameplayAbilityClasses;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FSGSCpp")
	USGSCppV4_DataAsset_Attr_Character_Init* SGSCppV4_DataAsset_Init;

	// Constructors and overrides
	USGSCppV4_AbilitySystemComponent();

	USGSCppV4_AttributeSet* FSGSCppV4_AttributeSet_Get();

	virtual void BeginPlay() override;

	/** Returns a list of currently active ability instances that match the tags */
	void GetActiveAbilitiesWithTags(const FGameplayTagContainer& GameplayTagContainer, TArray<UGameplayAbility*> &ActiveAbilities);

	/** Returns the default level used for ability activations, derived from the character */
	int32 GetDefaultAbilityLevel() const;

	/** Version of function in AbilitySystemGlobals that returns correct type */
	static USGSCppV4_AbilitySystemComponent* GetAbilitySystemComponentFromActor(const AActor* Actor, bool LookForComponent = false);

	/** Attempts to remove any startup gameplay abilities */
	void RemoveStartupGameplayAbilities();
		
	/**
	* Skill
	*/
	
	UFUNCTION(BlueprintCallable, Category = "FSGSCpp|Component|Abilities")
	void FSGSCppV4_Skill_Add(FSGSCppV4Slot DataAsset_Skill);
	
	UFUNCTION(BlueprintCallable, Category = "FSGSCpp|Component|Abilities")
	void FSGSCppV4_Skill_Del(FSGSCppV4Slot DataAsset_Skill);

	/**
	* Effects_Update_UsePlayerLevel
	*/
	
	UFUNCTION(BlueprintCallable, Category = "FSGSCpp|Component|Abilities")
	void FSGSCppV4_Effects_Update_UsePlayerLevel_Add(TSubclassOf<UGameplayEffect> inEffects_Update_UsePlayerLevel);
	
	UFUNCTION(BlueprintCallable, Category = "FSGSCpp|Component|Abilities")
	void FSGSCppV4_Effects_Update_UsePlayerLevel_Del(TSubclassOf<UGameplayEffect> inEffects_Update_UsePlayerLevel);

	/**
	* Abilities - Getter
	*/
	
	UFUNCTION(BlueprintCallable, Category = "FSGSCpp|Component|Abilities", meta = (Keywords = "FSGSCppV4 Get Active Abilities With Tags"))
	void FSGSCppV4_Abilities_Tag_Get(FGameplayTagContainer AbilityTags, TArray<UGameplayAbility*> &ActiveAbilities);

	UFUNCTION(BlueprintCallable, Category = "FSGSCpp|Component|Ability", meta = (Keywords = "FSGSCppV4 Get Cooldown Remaining For Tag"))
	bool FSGSCppV4_Ability_Cooldown_Tag_Get(FGameplayTagContainer CooldownTags, float& TimeRemaining, float& CooldownDuration);

	/**
	* Abilities - Getter - Attribute
	*/
	
	UFUNCTION(BlueprintCallable, Category = "FSGSCpp|Getter", meta = (Keywords = "FSGSCppV4 Get Character Attr"))
	void FSGSCppV4_Attr_Base_Get(float& AttackPower, float& DefensePower, float& MoveSpeed, float& Damage, int32& Level);

	UFUNCTION(BlueprintCallable, Category = "FSGSCpp|Getter", meta = (Keywords = "FSGSCppV4 Get Character Attr"))
	int32 FSGSCppV4_Attr_Level_Get();
	
	UFUNCTION(BlueprintPure, Category = "FSGSCpp|Getter", meta = (Keywords = "FSGSCppV4 Get Health | HP"))
	void FSGSCppV4_Attr_Health_Get(float &Health, float &HealthMax, float &Percent);

	UFUNCTION(BlueprintPure, Category = "FSGSCpp|Getter", meta = (Keywords = "FSGSCppV4 Get Stamina | SP"))
	void FSGSCppV4_Attr_Stamina_Get(float &Stamina, float &StaminaMax, float &Percent);

	UFUNCTION(BlueprintCallable, Category = "FSGSCpp|Getter", meta = (Keywords = "FSGSCppV4 Get Mana | MP"))
	void FSGSCppV4_Attr_Mana_Get(float &Mana, float &ManaMax, float &Percent);

	UFUNCTION(BlueprintPure, Category = "FSGSCpp|Getter", meta = (Keywords = "FSGSCppV4 Get Experience | XP"))
	void FSGSCppV4_Attr_Experience_Get(float &Experience, float &ExperienceMax, float &Percent);

	UFUNCTION(BlueprintPure, Category = "FSGSCpp|Getter", meta = (Keywords = "FSGSCppV4 Get Water | "))
	void FSGSCppV4_Attr_Water_Get(float &Water, float &WaterMax, float &Percent);

	UFUNCTION(BlueprintPure, Category = "FSGSCpp|Getter", meta = (Keywords = "FSGSCppV4 Get Food | "))
	void FSGSCppV4_Attr_Food_Get(float &Food, float &FoodMax, float &Percent);

	UFUNCTION(BlueprintPure, Category = "FSGSCpp|Getter", meta = (Keywords = "FSGSCppV4 Get Oxygen | "))
	void FSGSCppV4_Attr_Oxygen_Get(float &Oxygen, float &OxygenMax, float &Percent);

	/**
	* ЛОГИКА С ТЕГАМИ
	*/

	UFUNCTION(BlueprintCallable, Category = "FSGSCpp|Component|Abilities", meta = (Keywords = "FSGSCppV4 Activate Abilities With Tags"))
	bool FSGSCppV4_Abilities_Tags_Activate(FGameplayTagContainer AbilityTags, bool bAllowRemoteActivation = true);

	
	UFUNCTION(BlueprintCallable, Category = "FSGSCpp|Component|Ability", meta = (Keywords = "FSGSCppV4 Activate Ability With Tag"))
	bool FSGSCppV4_Ability_Tag_Activate(FGameplayTag AbilityTagL, bool bAllowRemoteActivation = true);

	/**
	* Cancel
	*/
	
	UFUNCTION(BlueprintCallable, Category = "FSGSCpp|Component|Ability")
	void FSGSCppV4_Ability_Tag_Cancel(FGameplayTag AbilityTag);

	/**
	* Find
	*/
	
	UFUNCTION(BlueprintPure, Category = "FSGSCpp|Component|Abilities")
	void FSGSCppV4_Abilities_Tags_Find(FGameplayTagContainer AbilityTags, bool& AbilitiesIsFind);

	/**
	* Update
	*/
	
	UFUNCTION(BlueprintCallable, Category = "FSGSCpp|Component|Function")
	void FSGSCppV4_Effects_Update();

	UFUNCTION(BlueprintCallable, Category = "FSGSCpp|Component|Function")
	void FSGSCppV4_Game_New_Init_Attr();

	// GameplayAbility
	UFUNCTION(BlueprintCallable, Category = "FSGSCpp|Component|Ability")
	bool FSGSCppV4_Ability_Add(TSubclassOf<UGameplayAbility> NewGameplayAbility, int32 level);

	// GameplayEffect
	UFUNCTION(BlueprintCallable, Category = "FSGSCpp|GameplayEffect")
	virtual void FSGSCppV4_GameplayEffect_Add(TSubclassOf<UGameplayEffect> GameplayEffectL, int32 level);

	/**
	* Данные Setter
	*/

	UFUNCTION(BlueprintCallable, Category = "FSGSCpp|Component|Function")
	void FSGSCppV4_Attr_Health_Set(float SetNewHealth);
	
	UFUNCTION(BlueprintCallable, Category = "FSGSCpp|Component|Function")
	void FSGSCppV4_Attr_Level_Set(int32 NewLevel);

	/**
	* Del
	*/

	UFUNCTION(BlueprintCallable, Category = "FSGSCpp|Component|Abilities")
	void FSGSCppV4_Ability_Del(TSubclassOf <UGameplayAbility> UGameplayAbilityL);

};
