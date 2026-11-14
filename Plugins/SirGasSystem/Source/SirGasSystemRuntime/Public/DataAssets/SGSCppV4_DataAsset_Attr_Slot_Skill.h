// Copyright (c) 2026 SirotkinAleksandr. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Texture2D.h"
#include "Materials/MaterialInterface.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "GameplayTagContainer.h"
#include "SGSCppV4_DataAsset_Attr_Slot.h"
#include "DataAssets/SGSCppV4_DataAsset_Attr.h"
#include "SGSCppV4_DataAsset_Attr_Slot_Skill.generated.h"

class UUserWidget;
class UGameplayEffect;
class UGameplayAbility;
/**
 * 
*/


UCLASS()
class SIRGASSYSTEMRUNTIME_API USGSCppV4_DataAsset_Attr_Slot_Skill : public USGSCppV4_DataAsset_Attr_Slot
{
	GENERATED_BODY()
	
public:

	USGSCppV4_DataAsset_Attr_Slot_Skill();
	
	/*
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParentForUpdateLevel")
	TSoftObjectPtr <UPrimaryDataAsset> Parent;
	*/
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "01_Skill")
	FName UniqueNameForUpdate;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "01_Skill")
	TSubclassOf <UGameplayAbility> GameplayAbility;
		
	/*
	 * Параметр который влияет на атрибуты игрока. Умножает дамаг или защиту или выносливость
	 * A parameter that affects player attributes. It multiplies damage, defense, or stamina.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "01_Skill")
	TSubclassOf<UGameplayEffect> GameplayEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "01_Skill|AbilityTag")
	FGameplayTag AbilityTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "01_Skill|AbilityTag")
	FGameplayTagContainer CooldownTag;

	/*
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "01_Skill")
	FString TypeAbility;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "01_Skill")
	FString TypeDamage;
	*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "01_Skill|Info", meta = (ClampMin = 1, Min = 1))
	int32 MaxLevel = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "01_Skill|Info", meta = (ClampMin = 1, Min = 1))
	TArray<FString> ArrStringForInfo;

	
	/*
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "01_Skill|AbilityInfo")
	float CoolDownDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "01_Skill|AbilityInfo")
	float Cost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "01_Skill|AbilityInfo")
	UMaterialInterface* UI_Material;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "01_Skill|AbilityInfo")
	TSubclassOf<UUserWidget> UI_WidgetIconForAbility;
	*/


};
