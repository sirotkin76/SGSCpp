// Copyright (c) 2026 SirotkinAleksandr. All Rights Reserved.


#include "Game/Actors/SGSCppV4_Actor_Interactable.h"


// Sets default values
ASGSCppV4_Actor_Interactable::ASGSCppV4_Actor_Interactable()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	UniqueId = TEXT(""+GetUniqueID());
}

// Called when the game starts or when spawned
void ASGSCppV4_Actor_Interactable::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void ASGSCppV4_Actor_Interactable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

