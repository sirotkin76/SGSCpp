// Copyright (c) 2026 SirotkinAleksandr. All Rights Reserved.

#pragma once

#include "Abilities/GameplayAbility.h"

#include "Abilities/SGSCppV4_AbilitySystemComponent.h"
#include "Components/ActorComponent.h"
#include "DataAssets/SGSCppV4_DataAsset_Character_Init.h"
#include "SGSCppV4_Component_Character_Init.generated.h"

/*
 * Данный компонент, требуется, для возможности создания раззных классов.
 * Pawn and Character и через данный компонент уже инициализровать
 * нужные данные в персонаже.
 */

/*
* This component is required to enable the creation of various classes—
* such as Pawn and Character—and to subsequently initialize the
* necessary data within the character via this component. 
*/

class ASGSCppV4_Character;
class ASGSCppV4_Pawn;

UCLASS(ClassGroup=("FSGSCpp|InventarySystemV4"), meta=(BlueprintSpawnableComponent), Blueprintable, BlueprintType, meta = (ShowWorldContextPin))
class SIRGASSYSTEMRUNTIME_API USGSCppV4_Component_Character_Init : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USGSCppV4_Component_Character_Init();

protected:
	
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	
	UPROPERTY()
	UAbilitySystemComponent * ASC ;

	UPROPERTY()
	TArray<UGameplayAbility * > V4_ArrActiveAbilities;
	
	UPROPERTY()
	TArray<TSubclassOf<UGameplayAbility>> V4_GameplayAbilityClasses;

	UPROPERTY()
	bool bAbilitiesInitialized;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "FSGSCpp|Character", meta = (ClampMin=1, Min=1))
	int32 CharacterLevel;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FSGSCpp")
	USGSCppV4_DataAsset_Attr_Character_Init* SGSCppV4_DataAssetInit;
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,  FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "FSGSCpp|Setter")
	void FSGSCppSetCharacterLevel(int32 NewLevel);
	
	/**
	* Character Attrubite
	*/

	//UFUNCTION(BlueprintCallable, Category = "FSGSCpp|Attr|Initialization")
	UFUNCTION()
	void FSGSCppInitializationCharacterAttrubite(USGSCppV4_AbilitySystemComponent * AbilitySystemComponent) ;

	// Implement IAbilitySystemInterface
	USGSCppV4_AbilitySystemComponent* GetAbilitySystemComponent() ;

	// GameplayAbility
	UFUNCTION(BlueprintCallable, Category = "FSGSCpp|Abilities|Add")
	bool FSGSCppAddNewGameplayAbility(TSubclassOf<UGameplayAbility> NewGameplayAbility);
	
	UFUNCTION(BlueprintCallable, Category = "FSGSCpp|Abilities|Add")
	void FSGSCppAddArrNewGameplayAbility(TArray<TSubclassOf<UGameplayAbility>> NewArrGameplayAbilities);

	// GameplayEffect
	UFUNCTION(BlueprintCallable, Category = "FSGSCpp|GameplayEffect|Add")
	virtual void FSGSCppAddGameplayEffect(TSubclassOf<UGameplayEffect> GameplayEffectL);
	
	UFUNCTION(BlueprintCallable, Category = "FSGSCpp|GameplayEffect|Add")
	virtual void FSGSCppAddGameplayEffects(TArray<TSubclassOf<UGameplayEffect>> GameplayEffectsL );

	/**
	* Cancel
	*/
	
	UFUNCTION(BlueprintCallable, Category = "FSGSCpp|Abilities|Cancel")
	void FSGSCppCancelAbility(FGameplayTag AbilityTag);

	/**
	* Has
	*/
	
	UFUNCTION(BlueprintPure, Category = "FSGSCpp|Abilities|Has")
	void FSGSCppCheckTag(FGameplayTagContainer AbilityTags, bool& TagIsEmpty);
	
protected:
	
	/** Apply the startup gameplay abilities and effects */
	void AddStartupGameplayAbilities();

	/** Adds slotted item abilities if needed */
	void AddGameplayAbilities();
	
	/** Attempts to remove any startup gameplay abilities */
	void RemoveStartupGameplayAbilities();
		
	/**
	* ЛОГИКА С ТЕГАМИ
	*/

	UFUNCTION(BlueprintCallable, Category = "FSGSCpp|Abilities|Activate")
	bool FSGSCppActivateAbilitiesWithTags(FGameplayTagContainer AbilityTags, bool bAllowRemoteActivation = true);

	UFUNCTION(BlueprintCallable, Category = "FSGSCpp|Abilities|Activate")
	bool FSGSCppActivateAbilityWithTag(FGameplayTag AbilityTagL, bool bAllowRemoteActivation = true);
	/**
	* Abilities - Getter
	*/

	/** Returns a list of active abilities matching the specified tags. This only returns if the ability is currently running */
	UFUNCTION(BlueprintCallable, Category = "FSGSCpp|Abilities|Gettter")
	void FSGSCppGetActiveAbilitiesWithTags(FGameplayTagContainer AbilityTags, TArray<UGameplayAbility*> &ActiveAbilities);
	
	/** Returns total time and remaining time for cooldown tags. Returns false if no active cooldowns found */
	UFUNCTION(BlueprintCallable, Category = "FSGSCpp|Abilities|Gettter")
	bool FSGSCppGetCooldownRemainingForTag(FGameplayTagContainer CooldownTags, float& TimeRemaining, float& CooldownDuration);


};
