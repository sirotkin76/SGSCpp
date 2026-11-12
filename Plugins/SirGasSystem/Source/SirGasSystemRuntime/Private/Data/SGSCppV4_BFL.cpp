// Copyright (c) 2026 SirotkinAleksandr. All Rights Reserved.


#include "Data/SGSCppV4_BFL.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "Abilities/SGSCppV4_AbilitySystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Data/SGSCppV4_Enumerations.h"
#include "GameFramework/Actor.h"
#include "Game/Components/SGSCppV4_Component_Storage.h"


void USGSCppV4_BFL:: FSGSCppV4_BFL_Storage_Slots_Set(USGSCppV4_Component_Storage * Owner,
                                              TArray<FSGSCppV4Slot> ArrNewInvSlots)
{
	Owner->FSGSCpp_Slots_Set(ArrNewInvSlots);
}

ESGSSirDirectionMovement USGSCppV4_BFL::FSGSCppBFLGetDirectionMovementV4(float ForwardL, float RightL)
{
	if (ForwardL == -1.f && RightL == 0.f) return ESGSSirDirectionMovement::Back_None;
	if (ForwardL == -1.f && RightL == 1.f) return ESGSSirDirectionMovement::Back_Right;
	if (ForwardL == -1.f && RightL == -1.f) return ESGSSirDirectionMovement::Back_Left;
	
	if (ForwardL == 0.f && RightL == -1.f) return ESGSSirDirectionMovement::None_Left;
	if (ForwardL == 0.f && RightL == 1.f) return ESGSSirDirectionMovement::None_Right;
	
	if (ForwardL == 1.f && RightL == 1.f) return ESGSSirDirectionMovement::Forward_Right;
	if (ForwardL == 1.f && RightL == -1.f) return ESGSSirDirectionMovement::Forward_Left;

	return ESGSSirDirectionMovement::Forward_None;
}

void USGSCppV4_BFL::FSGSCpp_BFL_Player_Skill_ActivateById(const UObject* WorldContextObject, int32 idSkill, bool &SkillIsValid, int32 &SkillLevel,  USGSCppV4_DataAsset_Attr_Skill*& SKill)
{
	USGSCppV4_AbilitySystemComponent*  local = FSGSCpp_BFL_Player_AbilitySystemComponent_Get(WorldContextObject, 1);

	//if (IsValid(local)) return local->FSGSCppV4_BFL_Player_Skill_ActivateById(idSkill , SkillIsValid , SkillLevel , SKill);

	SkillIsValid = false;
	SkillLevel = 0;
	SKill = nullptr;
	return;
}

USGSCppV4_AbilitySystemComponent* USGSCppV4_BFL::FSGSCpp_BFL_Player_AbilitySystemComponent_Get(
	const UObject* WorldContextObject, int32 PlayerIndex)
{
	// Получаем базовый APawn через GameplayStatics
	APawn* BasePawn = UGameplayStatics::GetPlayerPawn(WorldContextObject, PlayerIndex);
	if (!BasePawn)
	{
		return nullptr;
	}
	
	USGSCppV4_AbilitySystemComponent* local = Cast<USGSCppV4_AbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(BasePawn));
	
	if (IsValid(local)) return local;

	return nullptr;

}

bool USGSCppV4_BFL::FSGSCpp_BFL_Tag_Activate(USGSCppV4_AbilitySystemComponent* USGSCppV4_AbilitySystemComponent, FGameplayTag AbilityTag)
{
	if (!IsValid(USGSCppV4_AbilitySystemComponent)) return false;
	
	if (AbilityTag == FGameplayTag::EmptyTag) return false;

	return USGSCppV4_AbilitySystemComponent->FSGSCppV4_Ability_Tag_Activate(AbilityTag, true);
}

void USGSCppV4_BFL::FSGSCpp_BFL_Tag_Cancel(UObject* Caller, FGameplayTag AbilityTag)
{
	if (!Caller) return ;
	
	USGSCppV4_AbilitySystemComponent* local = Cast<AActor>(Caller)->FindComponentByClass<USGSCppV4_AbilitySystemComponent>();

	if (!IsValid(local)) return;

	return local->FSGSCppV4_Ability_Tag_Cancel(AbilityTag);
}


void USGSCppV4_BFL::FSGSCppV4_BFL_Storage_GetSlot_UseId(USGSCppV4_Component_Storage * Storage, int32 Get_Id, bool &IsValid, FSGSCppV4Slot &Slot)
{
	if (!Storage) return ;
	
	TArray<FSGSCppV4Slot> SlotsL = Storage->FSGSCpp_Slots_Get();

	if ((SlotsL.Num()-1) < Get_Id)
	{
		IsValid = false;
		return ;
	}
	
	
	IsValid = true;
	Slot = SlotsL[Get_Id];
	
	return ;
	
	
}

/*
void USGSCppV4_AbilitySystemComponent::FSGSCppV4_BFL_Player_Skill_ActivateById(int32 idSkill, bool &SkillIsValid, int32 &SkillLevel,  USGSCppV4_DataAsset_Attr_Skill*& SKill)
{
	int32 NumL = AbilitiesForUpdate.Num();
	
	if (idSkill > (NumL-1) )
	{
		SkillIsValid = false;
		SkillLevel = 0;
		SKill = nullptr;
		
		return;
	}
	
	SkillIsValid = true;
	SkillLevel = AbilitiesForUpdate[idSkill].AbiltyLevel;
	SKill = AbilitiesForUpdate[idSkill].SGSCppV4_DataAsset_Attr_Ability;

	return;
}
*/



/*
bool USGSCppV4_BFL::SGSCpp_BFL_Tag_Activate(FGameplayTag AbilityTag)
{
	
	ISGSCppV4_Interface_GameplayAbility().SSGSCppV4_Interface_GetGameplayAbility()->FSGSCppActivateAbilityWithTag(AbilityTag, true);
	return false;
}
*/

/*
void USGSCppV4_BFL::SGSCpp_BFL_Tag_Cancel(FGameplayTag AbilityTag)
{
	ISGSCppV4_Interface_GameplayAbility::ISGSCppV4_Interface_GameplayAbility().SSGSCppV4_Interface_GetGameplayAbility()->FSGSCppCancelAbility(AbilityTag);
}
*/

/*
void USGSCppSirInvSysBFLV4::SGSCppBFLInvSysSlotCheckNameV4(USGSCppSirInvSysV4* Owner, FName FindName,
	bool &ResFindName, FSGSInvSysSlot &ResInvSlotData, int32 &ResIndexInSlots)
{
	if (!IsValid(Owner))
	{
		ResFindName = false;
		return;
	};		
	int32 indexLocal = 0;
	
	//for (TSubclassOf<UGameplayEffect> GameplayEffect : GameplayEffectsL)
		
	for (FSGSInvSysSlot slotsL : Owner->SGSInvSys_SlotsGet()) 
	{
		if (slotsL.SlotName == FindName)
		{
			// Дата ассет
			if (!IsValid(slotsL.SGSCppV4_InvSlot_DataAsset))
			{
				ResFindName = false;
				return;
			};
			
			ResIndexInSlots = indexLocal;
			ResInvSlotData = slotsL;
				
			ResFindName = true;
			return;
		};
		
		indexLocal++;
	}

	ResFindName = false;
}

void USGSCppSirInvSysBFLV4:: SGSCppBFLInvSysSlotAddNotStackableV4(USGSCppSirInvSysV4 * NewOwner,
	FSGSInvSysSlot NewSlot, bool& Added)
{
	if (!IsValid(NewOwner)) return;
	
	bool AddedLocal = false;

	if (NewOwner->SGSInvSys_SlotsGet().Num() < NewOwner->SGSInvSys_GetMaxSlots())
	{
		// Есть место для записи нового слота
		// и слоты изначально не были созданы пустыми (под разную логику)
		
		NewOwner->FSGSInvSysSlots.Add(NewSlot);
		Added = true;
		return;
	}
	else
	{
		// возможно слоты изначально были созданы пустыми
		TArray<FSGSInvSysSlot> slotsL = NewOwner->SGSInvSys_SlotsGet();
		
		for (int32 i = 0; i < NewOwner->SGSInvSys_SlotsGet().Num(); i++)
		{
			FSGSInvSysSlot slotL = slotsL[i];
			
			// Если дата ассета нет, значить слот пустой, можно записать туда данные 
			if (!IsValid(slotL.SGSCppV4_InvSlot_DataAsset))
			{
				FSGSInvSysSlot NewSlotL = NewSlot;
				NewSlotL.SlotIndex = i;
				slotsL[i] = NewSlotL;
				NewOwner->SGSInvSys_SlotsSet(slotsL);
				
				Added = true;
				return;
			}
		}
	}
	
	Added = false;
	return;
	
}

void USGSCppSirInvSysBFLV4::SGSCppBFLInvSysSlotAddV4(USGSCppSirInvSysV4* inOwner, FSGSInvSysSlot inInvSlot)
{
	if (!IsValid(inOwner)) return;
	
	inOwner->FSGSInvSysSlots.Add(inInvSlot);
}

void USGSCppSirInvSysBFLV4::SGSCppBFLInvSysSlotsReplaceNotStackableV4(USGSCppSirInvSysV4* inNewOwner,
                                                                      FSGSInvSysSlot inNewSlot, USGSCppSirInvSysV4* inOldOwner, FSGSInvSysSlot inOldSlot)
{
	FSGSInvSysSlot inNewSlotL = inNewSlot;
	FSGSInvSysSlot inOldSlotL = inOldSlot;
	
	SGSCppBFLInvSysSlotSetNewDataV4(inNewOwner, inNewSlotL, inOldSlotL);
	SGSCppBFLInvSysSlotSetNewDataV4(inOldOwner, inOldSlotL, inNewSlotL);
	
}

void USGSCppSirInvSysBFLV4::SGSCppBFLInvSysSlotCountSetV4(USGSCppSirInvSysV4* inOwner, FSGSInvSysSlot InvSlot,
                                                          int32 SetNewCount)
{
	if (!IsValid(inOwner)) return;
	
	TArray<FSGSInvSysSlot> FSGSInvSysSlotsL = inOwner->SGSInvSys_SlotsGet();
	FSGSInvSysSlot InvSlotLocalClear;
	
	
	int32 indexLocal = InvSlot.SlotIndex;

	if (InvSlot.SlotIndex < FSGSInvSysSlotsL.Num() )
	{
		FSGSInvSysSlotsL.Insert(InvSlotLocalClear, indexLocal);
	};

	if (InvSlot.SlotIndex < FSGSInvSysSlotsL.Num() ) return;
		
	FSGSInvSysSlotsL[InvSlot.SlotIndex].SGSCppV4_InvSlot_DataAsset = InvSlot.SGSCppV4_InvSlot_DataAsset;
	FSGSInvSysSlotsL[InvSlot.SlotIndex].SlotCount = SetNewCount;
	FSGSInvSysSlotsL[InvSlot.SlotIndex].SlotCondition = InvSlot.SlotCondition;
	FSGSInvSysSlotsL[InvSlot.SlotIndex].SlotName = InvSlot.SlotName;
	
	inOwner->SGSInvSys_SlotsSet(FSGSInvSysSlotsL);

}

void USGSCppSirInvSysBFLV4::SGSCppBFLInvSysSlotClearV4(USGSCppSirInvSysV4* inOwner, int32 inInvSlotIndex)
{
	if (!IsValid(inOwner)) return;

	TArray<FSGSInvSysSlot> FSGSInvSysSlotsL = inOwner->SGSInvSys_SlotsGet();
	FSGSInvSysSlot InvSlotLocalClear;
	

	if (FSGSInvSysSlotsL.Num() <= inInvSlotIndex )
	{
		for (int32 indexLocaCountl = FSGSInvSysSlotsL.Num(); indexLocaCountl < inInvSlotIndex; indexLocaCountl = FSGSInvSysSlotsL.Num() )
		{
			FSGSInvSysSlotsL.Add(InvSlotLocalClear);
		};
	};
	
	FSGSInvSysSlotsL[inInvSlotIndex].SGSCppV4_InvSlot_DataAsset = nullptr;
	FSGSInvSysSlotsL[inInvSlotIndex].SlotCount = -1;
	FSGSInvSysSlotsL[inInvSlotIndex].SlotCondition = -1;
	FSGSInvSysSlotsL[inInvSlotIndex].SlotIndex = inInvSlotIndex;
	FSGSInvSysSlotsL[inInvSlotIndex].SlotName = "";

	inOwner->SGSInvSys_SlotsSet(FSGSInvSysSlotsL);
	
}

void USGSCppSirInvSysBFLV4::SGSCppBFLInvSysSlotSetNewDataV4(USGSCppSirInvSysV4* inOwner,
	FSGSInvSysSlot inOldInvSlot, FSGSInvSysSlot inNewInvSlot)
{
	if (!IsValid(inOwner)) return;

	TArray<FSGSInvSysSlot> FSGSInvSysSlotsL = inOwner->SGSInvSys_SlotsGet();

	/*
	FSGSInvSysSlotsL[inNewInvSlot.SlotIndex].SGSCppV4_InvSlot_DataAsset = inOldInvSlot.SGSCppV4_InvSlot_DataAsset;
	FSGSInvSysSlotsL[inNewInvSlot.SlotIndex].SlotCount = inOldInvSlot.SlotCount;
	FSGSInvSysSlotsL[inNewInvSlot.SlotIndex].SlotCondition = inOldInvSlot.SlotCondition;
	
	FSGSInvSysSlotsL[inNewInvSlot.SlotIndex].SlotIndex = inNewInvSlot.SlotIndex;
	
	FSGSInvSysSlotsL[inNewInvSlot.SlotIndex].SlotName = inOldInvSlot.SlotName;;

	inOwner->SGSInvSys_SlotsSet(FSGSInvSysSlotsL);
	#1#
	FSGSInvSysSlotsL[inOldInvSlot.SlotIndex].SGSCppV4_InvSlot_DataAsset = inNewInvSlot.SGSCppV4_InvSlot_DataAsset;
	FSGSInvSysSlotsL[inOldInvSlot.SlotIndex].SlotCount = inNewInvSlot.SlotCount;
	FSGSInvSysSlotsL[inOldInvSlot.SlotIndex].SlotCondition = inNewInvSlot.SlotCondition;
	
	FSGSInvSysSlotsL[inOldInvSlot.SlotIndex].SlotIndex = inOldInvSlot.SlotIndex;
	
	FSGSInvSysSlotsL[inOldInvSlot.SlotIndex].SlotName = inNewInvSlot.SlotName;;

	inOwner->SGSInvSys_SlotsSet(FSGSInvSysSlotsL);
}

void USGSCppSirInvSysBFLV4::SGSCppBFLInvSysSlotReplaceV4(USGSCppSirInvSysV4* inOldOwner, USGSCppSirInvSysV4* inNewOwner,
	int32 inNewIndex, FVector2D inNewGrid, FSGSInvSysSlot inOldInvSlot)
{
	if (!IsValid(inOldOwner)) return;
	if (!IsValid(inNewOwner)) return;

	TArray<FSGSInvSysSlot> FSGSInvSysSlotsL = inOldOwner->SGSInvSys_SlotsGet();
	
}

void USGSCppSirInvSysBFLV4::SGSCppBFLInvSysFreeSlotSetV4(USGSCppSirInvSysV4* inOldOwner, USGSCppSirInvSysV4* inNewOwner,
	FSGSInvSysSlot inOldInvSlot, int32 inNewIndex)
{
	if (!IsValid(inOldOwner)) return;
	if (!IsValid(inNewOwner)) return;

	FSGSInvSysSlot inOldInvSlotLocal;

	TArray<FSGSInvSysSlot> FSGSInvSysSlotsL = inNewOwner->SGSInvSys_SlotsGet();

	if (FSGSInvSysSlotsL.Num() < inNewIndex)
	{
		int32 localInt = FSGSInvSysSlotsL.Num() - inNewIndex;

		for(int32 i = 0; i < localInt; i++)
		{
			FSGSInvSysSlotsL.Add(inOldInvSlotLocal);
		}
		
	}

	FSGSInvSysSlotsL[inNewIndex].SGSCppV4_InvSlot_DataAsset =	inOldInvSlot.SGSCppV4_InvSlot_DataAsset;
	FSGSInvSysSlotsL[inNewIndex].SlotCount =						inOldInvSlot.SlotCount;
	FSGSInvSysSlotsL[inNewIndex].SlotCondition =					inOldInvSlot.SlotCondition;
	FSGSInvSysSlotsL[inNewIndex].SlotName =							inOldInvSlot.SlotName;;
	
	FSGSInvSysSlotsL[inNewIndex].SlotIndex =						inNewIndex;

	inNewOwner->SGSInvSys_SlotsSet(FSGSInvSysSlotsL);

	// обнуляем, чистим, удаляем старый слот
	SGSCppBFLInvSysSlotClearV4(inOldOwner, inOldInvSlot.SlotIndex);
}
*/































