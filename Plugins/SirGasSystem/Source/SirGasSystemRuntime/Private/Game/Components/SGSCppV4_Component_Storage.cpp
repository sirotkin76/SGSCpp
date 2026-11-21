// Copyright (c) 2026 SirotkinAleksandr. All Rights Reserved.


#include "Game/Components/SGSCppV4_Component_Storage.h"


// Sets default values for this component's properties
USGSCppV4_Component_Storage::USGSCppV4_Component_Storage()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void USGSCppV4_Component_Storage::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USGSCppV4_Component_Storage::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

TArray<FSGSCppV4Slot> USGSCppV4_Component_Storage::FSGSCpp_Slots_Get()
{
	return  FSGSCpp_Slots;
}

FSGSCppV4Slot USGSCppV4_Component_Storage::FSGSCpp_Slots_Get_Id(int32 index, bool &find)
{
	FSGSCppV4Slot FSGSCpp_SlotsL;
	if (index < 0) 
	{
		find = false;
		return FSGSCpp_SlotsL;
	}

	if (index < FSGSCpp_Slots.Num())
	{
		find = true;
		return FSGSCpp_Slots[index];
	}
	
	find = false;
	return FSGSCpp_SlotsL;
}

void USGSCppV4_Component_Storage::FSGSCpp_Slots_Set(TArray<FSGSCppV4Slot> NewItems)
{
	FSGSCpp_Slots = NewItems;
}

void USGSCppV4_Component_Storage::FSGSCpp_Slots_InitEmpty_SetNew(int32 CountNewEmptySlots)
{
	FSGSCppV4Slot FSGSCppV4SlotLocal;
	FSGSCppV4SlotLocal.PrimaryDataAsset = nullptr;
	
	for (int32 i = 0; i < CountNewEmptySlots; i++)
	{
		FSGSCpp_Slots.Add(FSGSCppV4SlotLocal);
	}
}
