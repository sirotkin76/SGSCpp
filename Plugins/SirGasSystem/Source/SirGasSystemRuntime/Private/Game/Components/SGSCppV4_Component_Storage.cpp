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

void USGSCppV4_Component_Storage::FSGSCpp_Slots_Set(TArray<FSGSCppV4Slot> NewItems)
{
	FSGSCpp_Slots = NewItems;
}
