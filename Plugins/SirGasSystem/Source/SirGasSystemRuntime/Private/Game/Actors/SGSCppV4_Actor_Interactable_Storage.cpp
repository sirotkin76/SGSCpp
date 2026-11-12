// Copyright (c) 2026 SirotkinAleksandr. All Rights Reserved.


#include "Game/Actors/SGSCppV4_Actor_Interactable_Storage.h"


// Sets default values
ASGSCppV4_Actor_Interactable_Storage::ASGSCppV4_Actor_Interactable_Storage()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Tags.Add(FName("Storage"));
	
}

// Called when the game starts or when spawned
void ASGSCppV4_Actor_Interactable_Storage::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASGSCppV4_Actor_Interactable_Storage::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

