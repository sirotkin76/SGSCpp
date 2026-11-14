// Copyright (c) 2026 SirotkinAleksandr. All Rights Reserved.


#pragma once

#include "CoreMinimal.h"
#include "DataAssets/SGSCppV4_DataAsset_Attr_Slot.h"
#include "SGSCppV4_DataAsset_Attr_Slot_Item.generated.h"

/**
 * 
 */
UCLASS()
class SIRGASSYSTEMRUNTIME_API USGSCppV4_DataAsset_Attr_Slot_Item : public USGSCppV4_DataAsset_Attr_Slot
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "01_Item")
	bool Item_AutoEquip;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "01_Item")
	bool Item_Stackable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "01_Item", meta = (ClampMin = 1, Min = 1))
	int32 Item_CountMax = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "01_Item")
	float Item_Price;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "01_Item")
	float Item_Weight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "01_Item")
	float Item_Cost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="01_Item")
	TArray<FName> Item_InventorySlotTypes;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="01_Item")
	TArray<FName> Item_InventorySlotSubType;
 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "01_Item")
	TSoftObjectPtr <UPrimaryDataAsset> Item_RecipeForPlayerHave;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "01_Item")
	TSubclassOf<AActor> Item_PickUpActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="01_Item|Visual")
	FVector2D Item_SlotGrid = FVector2D(1, 1);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "01_Item")
	TSubclassOf<UGameplayEffect> Item_AddGameplayEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "01_Item")
	TSubclassOf <UGameplayAbility> Item_AddGameplayAbility;














	
};
