// Copyright (c) 2026 SirotkinAleksandr. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SGSCppV4_DataAsset_Attr.h"
#include "Abilities/SGSCppV4_GameplayAbility.h"
#include "SGSCppV4_DataAsset_Attr_Init_Character.generated.h"



/**
 * 
 */
UCLASS()
class SIRGASSYSTEMRUNTIME_API USGSCppV4_DataAsset_Attr_Character_Init : public USGSCppV4_DataAsset_Attr
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SGSCpp")
	TArray<TSubclassOf<UGameplayAbility>> Abilities;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SGSCpp")
	TArray<TSubclassOf<UGameplayEffect>> Effects;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SGSCpp")
	TArray<USGSCppV4_DataAsset_Attr_Skill *> DataAsset_Abilities;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SGSCpp|UpdateLevel")
	TArray<TSubclassOf<UGameplayEffect>> Effects_Update_UsePlayerLevel;
	
	/** Type of this item, set in native parent class 	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SGSCpp|Animmontages")
	TArray<UAnimMontage *> arrAttackLight;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SGSCpp|Animmontages")
	TArray<UAnimMontage *> arrAttackSpec;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SGSCpp|Animmontages")
	TArray<UAnimMontage *> arrAttackHeavy;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SGSCpp|Animmontages")
	TArray<UAnimMontage *> arrHits;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SGSCpp|Animmontages")
	TArray<UAnimMontage *> arrSpawn;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SGSCpp|Animmontages")
	TArray<UAnimMontage *> arrDead;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SGSCpp|Animmontages")
	TArray<UAnimMontage *> arrStun;
 	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SGSCpp|Animmontages")
	TMap<FName, UAnimMontage *> arrOthers;
 
	// UFUNCTIONS
	UFUNCTION(BlueprintPure, Category = "SGSCpp|Getter")
	UAnimMontage * SGSCppFindArrAnimMontage(FName FindNameInArr);
};
