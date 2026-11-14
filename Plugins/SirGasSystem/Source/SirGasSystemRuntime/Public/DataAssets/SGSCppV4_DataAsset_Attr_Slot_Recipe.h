// Copyright (c) 2026 SirotkinAleksandr. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Data/SGSCppV4_Struct.h"
#include "SGSCppV4_DataAsset_Attr.h"

#include "SGSCppV4_DataAsset_Attr_Slot_Recipe.generated.h"

class USGSCppV4_DataAsset_Attr_Slot;
/**
 * 
 */
UCLASS(Blueprintable, Category = "SGSCpp|BFL")
class SIRGASSYSTEMRUNTIME_API USGSCppV4_DataAsset_Attr_Slot_Recipe : public USGSCppV4_DataAsset_Attr
{
	GENERATED_BODY()

public:
	
	USGSCppV4_DataAsset_Attr_Slot_Recipe();
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="01_RecipeCreateNew")
	TSoftObjectPtr<USGSCppV4_DataAsset_Attr_Slot_Recipe> CreateNewRecipe;
		
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "01_Recipe")
	bool OneTimePrescription;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "01_Recipe")
	bool UpgradeLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "01_Recipe", meta = (ClampMin = 1, Min = 1))
	float Time = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "01_Recipe")
	FString IconName;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "01_Recipe")
	FString NameShort;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "01_Recipe")
	FString NameFull;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "01_Recipe")
	FString DescriptionShort;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "01_Recipe")
	FString DescriptionFull;
	
	// Сообщение выводится, если данный рецепт не может выполняться.
	// This message is displayed if the given recipe cannot be executed.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="01_RecipeInfo")
	FString Error_Message;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="01_Recipe")
	TArray<FName> InventorySlotTypes;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="01_Recipe")
	TArray<FName> InventorySlotSubType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "01_Recipe")
	FName FastSlot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="01_Recipe")
	TSoftObjectPtr<USGSCppV4_DataAsset_Attr_Slot_Recipe> RequiredRecipeForActivateThisRecipe;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="01_RecipeCreateNewSlot")
	FSGSCppV4_SlotCount SlotCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="01_RecipeRequireSlots")
	TArray<FSGSCppV4_SlotCount> arrSlotCount;

};
