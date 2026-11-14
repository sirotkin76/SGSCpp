// Copyright (c) 2026 SirotkinAleksandr. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Texture2D.h"
#include "SGSCppV4_DataAsset_Attr.h"
#include "SGSCppV4_DataAsset_Attr_Slot.generated.h"

class UGameplayAbility;
class SGSCppV4_DataAsset_Attr_Recipe;
class UGameplayEffect;

/**
 * 
 */


UCLASS(Blueprintable, Category = "SGSCpp|BFL")
class SIRGASSYSTEMRUNTIME_API USGSCppV4_DataAsset_Attr_Slot : public USGSCppV4_DataAsset_Attr
{
	GENERATED_BODY()
	
public:
	
	USGSCppV4_DataAsset_Attr_Slot();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "00_Slot")
	UTexture2D* Icon;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "00_Slot")
	FString Slot_IconName;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "00_Slot")
	FString Slot_Name;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "00_Slot")
	FString Slot_Description;
	
	// *************
	// Displays information on hover.
	// Показыавет информацию при наведении.
	// *************
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "00_Slot")
	FString Slot_Message;

	// *************
	// Данный аттрибут должен быть массивом, так как, один компонент может находится в 2 или более типах.
	// Пример - вода, вода может быть типом - крафт и типом - пища и типом - вода.
	
	// This attribute must be an array, since a single component can belong to two or more types.
	// For example, water can be classified as a crafting item, a food item, and a water item.
	
	/*ArrName.Add(TEXT("InventoryType"), "");*/
	
	// *************
	// Чтобы не запутаться данный параметр вывел в одной области с основным типом.
	// To avoid confusion, I’ve placed this parameter in the same area as the main type.
	/*ArrName.Add(TEXT("InventorySubType"), "");*/
	// *************
	



};
