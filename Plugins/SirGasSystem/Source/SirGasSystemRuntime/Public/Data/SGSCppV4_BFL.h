// Copyright (c) 2026 SirotkinAleksandr. All Rights Reserved.

#pragma once

#include "Engine.h"
#include "Net/UnrealNetwork.h"
#include "SGSCppV4_Enumerations.h"
#include "SGSCppV4_Struct.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SGSCppV4_BFL.generated.h"

class USGSCppV4_Component_Storage;
class USGSCppV4_AbilitySystemComponent;
class USGSCppV4_DataAsset_Attr;
class USGSCppSirV4;

/**
 * 
 */
UCLASS(Blueprintable, Category = "FSGSCpp|BFL")
class SIRGASSYSTEMRUNTIME_API USGSCppV4_BFL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
		
public:
					
	UFUNCTION(BlueprintCallable, Category = "FSGSCpp|BFL|Storage", meta = (WorldContext = "WorldContextObject")) /*, meta = (Keywords = "BFL Storage - Get slot | skill - Activate (By or USE) Id")*/
	static void FSGSCppV4_BFL_Storage_GetSlot_UseId(USGSCppV4_Component_Storage * Storage, int32 Get_Id, bool &IsValid, FSGSCppV4Slot &Slot);

	
	UFUNCTION(BlueprintCallable, Category="FSGSCpp|BFL|Storage", meta = (WorldContext = "WorldContextObject"))
	static void FSGSCpp_BFL_Player_Skill_ActivateById(const UObject* WorldContextObject, int32 idSkill, bool &SkillIsValid, int32 &SkillLevel,  USGSCppV4_DataAsset_Attr_Skill*& SKill );

	UFUNCTION(BlueprintCallable, Category="FSGSCpp|BFL|GAS", meta = (WorldContext = "WorldContextObject"))
	static USGSCppV4_AbilitySystemComponent* FSGSCpp_BFL_Player_AbilitySystemComponent_Get(const UObject* WorldContextObject, int32 PlayerIndex = 0);

	UFUNCTION(BlueprintCallable, Category="FSGSCpp|BFL|GAS", meta = (DefaultToSelf = "Caller"))
	static bool FSGSCpp_BFL_Tag_Activate(USGSCppV4_AbilitySystemComponent* USGSCppV4_AbilitySystemComponent, FGameplayTag AbilityTag);

	UFUNCTION(BlueprintCallable, Category="FSGSCpp|BFL|GAS", meta = (DefaultToSelf = "Caller"))
	static void FSGSCpp_BFL_Tag_Cancel(USGSCppV4_AbilitySystemComponent* USGSCppV4_AbilitySystemComponent, FGameplayTag AbilityTag);


	UFUNCTION(BlueprintCallable, Category="FSGSCpp|BFL|Inventory")
	static void FSGSCppV4_BFL_Storage_Slots_Set(USGSCppV4_Component_Storage * Owner, TArray<FSGSCppV4Slot> ArrNewInvSlots);

	UFUNCTION(BlueprintCallable, Category="FSGSCpp|BFL|Base")
	static ESGSSirDirectionMovement FSGSCppBFLGetDirectionMovementV4(float ForwardL, float RightL);

	/*
	UFUNCTION(BlueprintCallable, Category="SGSCpp|BFLV4|Slot")
	static void SGSCppBFLSlotCheckNameV4(USGSCppSirV4 * Owner, FName FindName,
	bool &ResFindName, FSGSSlot &ResInvSlotData, int32 &ResIndexInSlots);

	UFUNCTION(BlueprintCallable, Category="SGSCpp|BFLV4|Slot")
	static void SGSCppBFLSlotAddNotStackableV4(USGSCppSirV4 * NewOwner, FSGSSlot NewSlot, bool &Added);
	
	UFUNCTION(BlueprintCallable, Category="SGSCpp|BFLV4|Slot")
	static void SGSCppBFLSlotAddV4(USGSCppSirV4 * inOwner, FSGSSlot inInvSlot);
	
	UFUNCTION(BlueprintCallable, Category="SGSCpp|BFLV4|Slot")
	static void SGSCppBFLSlotsReplaceNotStackableV4(USGSCppSirV4 * inNewOwner, FSGSSlot inNewSlot, USGSCppSirV4 * inOldOwner, FSGSSlot inOldSlot);
	
	UFUNCTION(BlueprintCallable, Category="SGSCpp|BFLV4|Slot", meta = (DisplayName = "SGS  Slots Delete - Clear slot  V4"))
	static void SGSCppBFLSlotClearV4(USGSCppSirV4 * inOwner, int32 inInvSlotIndex);
	
	UFUNCTION(BlueprintCallable, Category="SGSCpp|BFLV4|Slot")
	static void SGSCppBFLSlotSetNewDataV4(USGSCppSirV4 * inOwner, FSGSSlot inOldInvSlot, FSGSSlot inNewInvSlot);

	UFUNCTION(BlueprintCallable, Category="SGSCpp|BFLV4|Count")
	static void SGSCppBFLSlotCountSetV4(USGSCppSirV4 * inOwner, FSGSSlot inInvSlot, int32 inSetNewCount);

	UFUNCTION(BlueprintCallable, Category="SGSCpp|BFLV4|Slot")
	static void SGSCppBFLSlotReplaceV4(USGSCppSirV4 * inOldOwner, USGSCppSirV4 * inNewOwner, int32 inNewIndex, FVector2D inNewGrid, FSGSSlot inOldInvSlot);

	UFUNCTION(BlueprintCallable, Category="SGSCpp|BFLV4|Slot")
	static void SGSCppBFLFreeSlotSetV4(USGSCppSirV4 * inOldOwner, USGSCppSirV4 * inNewOwner, FSGSSlot inOldInvSlot, int32 inNewIndex);
	*/

};
 