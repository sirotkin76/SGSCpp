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

void USGSCppV4_BFL::FSGSCpp_BFL_Tag_Cancel(USGSCppV4_AbilitySystemComponent* USGSCppV4_AbilitySystemComponent, FGameplayTag AbilityTag)
{
	if (!IsValid(USGSCppV4_AbilitySystemComponent)) return ;
	if (AbilityTag == FGameplayTag::EmptyTag) return ;

	return USGSCppV4_AbilitySystemComponent->FSGSCppV4_Ability_Tag_Cancel(AbilityTag);
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
void USGSCppBFLV4::SGSCppBFLSlotCheckNameV4(USGSCppSirV4* Owner, FName FindName,
	bool &ResFindName, FSGSSlot &ResInvSlotData, int32 &ResIndexInSlots)
{
	if (!IsValid(Owner))
	{
		ResFindName = false;
		return;
	};		
	int32 indexLocal = 0;
	
	//for (TSubclassOf<UGameplayEffect> GameplayEffect : GameplayEffectsL)
		
	for (FSGSSlot slotsL : Owner->SGS_SlotsGet()) 
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

void USGSCppBFLV4:: SGSCppBFLSlotAddNotStackableV4(USGSCppSirV4 * NewOwner,
	FSGSSlot NewSlot, bool& Added)
{
	if (!IsValid(NewOwner)) return;
	
	bool AddedLocal = false;

	if (NewOwner->SGS_SlotsGet().Num() < NewOwner->SGS_GetMaxSlots())
	{
		// Есть место для записи нового слота
		// и слоты изначально не были созданы пустыми (под разную логику)
		
		NewOwner->FSGS_Slots.Add(NewSlot);
		Added = true;
		return;
	}
	else
	{
		// возможно слоты изначально были созданы пустыми
		TArray<FSGSSlot> slotsL = NewOwner->SGS_SlotsGet();
		
		for (int32 i = 0; i < NewOwner->SGS_SlotsGet().Num(); i++)
		{
			FSGSSlot slotL = slotsL[i];
			
			// Если дата ассета нет, значить слот пустой, можно записать туда данные 
			if (!IsValid(slotL.SGSCppV4_InvSlot_DataAsset))
			{
				FSGSSlot NewSlotL = NewSlot;
				NewSlotL.SlotIndex = i;
				slotsL[i] = NewSlotL;
				NewOwner->SGS_SlotsSet(slotsL);
				
				Added = true;
				return;
			}
		}
	}
	
	Added = false;
	return;
	
}

void USGSCppBFLV4::SGSCppBFLSlotAddV4(USGSCppSirV4* inOwner, FSGSSlot inInvSlot)
{
	if (!IsValid(inOwner)) return;
	
	inOwner->FSGS_Slots.Add(inInvSlot);
}

void USGSCppBFLV4::SGSCppBFLSlotsReplaceNotStackableV4(USGSCppSirV4* inNewOwner,
                                                                      FSGSSlot inNewSlot, USGSCppSirV4* inOldOwner, FSGSSlot inOldSlot)
{
	FSGSSlot inNewSlotL = inNewSlot;
	FSGSSlot inOldSlotL = inOldSlot;
	
	SGSCppBFLSlotSetNewDataV4(inNewOwner, inNewSlotL, inOldSlotL);
	SGSCppBFLSlotSetNewDataV4(inOldOwner, inOldSlotL, inNewSlotL);
	
}

void USGSCppBFLV4::SGSCppBFLSlotCountSetV4(USGSCppSirV4* inOwner, FSGSSlot InvSlot,
                                                          int32 SetNewCount)
{
	if (!IsValid(inOwner)) return;
	
	TArray<FSGSSlot> FSGS_SlotsL = inOwner->SGS_SlotsGet();
	FSGSSlot InvSlotLocalClear;
	
	
	int32 indexLocal = InvSlot.SlotIndex;

	if (InvSlot.SlotIndex < FSGS_SlotsL.Num() )
	{
		FSGS_SlotsL.Insert(InvSlotLocalClear, indexLocal);
	};

	if (InvSlot.SlotIndex < FSGS_SlotsL.Num() ) return;
		
	FSGS_SlotsL[InvSlot.SlotIndex].SGSCppV4_InvSlot_DataAsset = InvSlot.SGSCppV4_InvSlot_DataAsset;
	FSGS_SlotsL[InvSlot.SlotIndex].SlotCount = SetNewCount;
	FSGS_SlotsL[InvSlot.SlotIndex].SlotCondition = InvSlot.SlotCondition;
	FSGS_SlotsL[InvSlot.SlotIndex].SlotName = InvSlot.SlotName;
	
	inOwner->SGS_SlotsSet(FSGS_SlotsL);

}

void USGSCppBFLV4::SGSCppBFLSlotClearV4(USGSCppSirV4* inOwner, int32 inInvSlotIndex)
{
	if (!IsValid(inOwner)) return;

	TArray<FSGSSlot> FSGS_SlotsL = inOwner->SGS_SlotsGet();
	FSGSSlot InvSlotLocalClear;
	

	if (FSGS_SlotsL.Num() <= inInvSlotIndex )
	{
		for (int32 indexLocaCountl = FSGS_SlotsL.Num(); indexLocaCountl < inInvSlotIndex; indexLocaCountl = FSGS_SlotsL.Num() )
		{
			FSGS_SlotsL.Add(InvSlotLocalClear);
		};
	};
	
	FSGS_SlotsL[inInvSlotIndex].SGSCppV4_InvSlot_DataAsset = nullptr;
	FSGS_SlotsL[inInvSlotIndex].SlotCount = -1;
	FSGS_SlotsL[inInvSlotIndex].SlotCondition = -1;
	FSGS_SlotsL[inInvSlotIndex].SlotIndex = inInvSlotIndex;
	FSGS_SlotsL[inInvSlotIndex].SlotName = "";

	inOwner->SGS_SlotsSet(FSGS_SlotsL);
	
}

void USGSCppBFLV4::SGSCppBFLSlotSetNewDataV4(USGSCppSirV4* inOwner,
	FSGSSlot inOldInvSlot, FSGSSlot inNewInvSlot)
{
	if (!IsValid(inOwner)) return;

	TArray<FSGSSlot> FSGS_SlotsL = inOwner->SGS_SlotsGet();

	/*
	FSGS_SlotsL[inNewInvSlot.SlotIndex].SGSCppV4_InvSlot_DataAsset = inOldInvSlot.SGSCppV4_InvSlot_DataAsset;
	FSGS_SlotsL[inNewInvSlot.SlotIndex].SlotCount = inOldInvSlot.SlotCount;
	FSGS_SlotsL[inNewInvSlot.SlotIndex].SlotCondition = inOldInvSlot.SlotCondition;
	
	FSGS_SlotsL[inNewInvSlot.SlotIndex].SlotIndex = inNewInvSlot.SlotIndex;
	
	FSGS_SlotsL[inNewInvSlot.SlotIndex].SlotName = inOldInvSlot.SlotName;;

	inOwner->SGS_SlotsSet(FSGS_SlotsL);
	#1#
	FSGS_SlotsL[inOldInvSlot.SlotIndex].SGSCppV4_InvSlot_DataAsset = inNewInvSlot.SGSCppV4_InvSlot_DataAsset;
	FSGS_SlotsL[inOldInvSlot.SlotIndex].SlotCount = inNewInvSlot.SlotCount;
	FSGS_SlotsL[inOldInvSlot.SlotIndex].SlotCondition = inNewInvSlot.SlotCondition;
	
	FSGS_SlotsL[inOldInvSlot.SlotIndex].SlotIndex = inOldInvSlot.SlotIndex;
	
	FSGS_SlotsL[inOldInvSlot.SlotIndex].SlotName = inNewInvSlot.SlotName;;

	inOwner->SGS_SlotsSet(FSGS_SlotsL);
}

void USGSCppBFLV4::SGSCppBFLSlotReplaceV4(USGSCppSirV4* inOldOwner, USGSCppSirV4* inNewOwner,
	int32 inNewIndex, FVector2D inNewGrid, FSGSSlot inOldInvSlot)
{
	if (!IsValid(inOldOwner)) return;
	if (!IsValid(inNewOwner)) return;

	TArray<FSGSSlot> FSGS_SlotsL = inOldOwner->SGS_SlotsGet();
	
}

void USGSCppBFLV4::SGSCppBFLFreeSlotSetV4(USGSCppSirV4* inOldOwner, USGSCppSirV4* inNewOwner,
	FSGSSlot inOldInvSlot, int32 inNewIndex)
{
	if (!IsValid(inOldOwner)) return;
	if (!IsValid(inNewOwner)) return;

	FSGSSlot inOldInvSlotLocal;

	TArray<FSGSSlot> FSGS_SlotsL = inNewOwner->SGS_SlotsGet();

	if (FSGS_SlotsL.Num() < inNewIndex)
	{
		int32 localInt = FSGS_SlotsL.Num() - inNewIndex;

		for(int32 i = 0; i < localInt; i++)
		{
			FSGS_SlotsL.Add(inOldInvSlotLocal);
		}
		
	}

	FSGS_SlotsL[inNewIndex].SGSCppV4_InvSlot_DataAsset =	inOldInvSlot.SGSCppV4_InvSlot_DataAsset;
	FSGS_SlotsL[inNewIndex].SlotCount =						inOldInvSlot.SlotCount;
	FSGS_SlotsL[inNewIndex].SlotCondition =					inOldInvSlot.SlotCondition;
	FSGS_SlotsL[inNewIndex].SlotName =							inOldInvSlot.SlotName;;
	
	FSGS_SlotsL[inNewIndex].SlotIndex =						inNewIndex;

	inNewOwner->SGS_SlotsSet(FSGS_SlotsL);

	// обнуляем, чистим, удаляем старый слот
	SGSCppBFLSlotClearV4(inOldOwner, inOldInvSlot.SlotIndex);
}
*/































