// Copyright (c) 2026 SirotkinAleksandr. All Rights Reserved.

#pragma once

#include "Engine.h"
#include "SGSCppV4_Actor_Interactable.h"
#include "Net/UnrealNetwork.h"
#include "SGSCppV4_Actor_Interactable_Storage.generated.h"

UCLASS()
class SIRGASSYSTEMRUNTIME_API ASGSCppV4_Actor_Interactable_Storage : public ASGSCppV4_Actor_Interactable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASGSCppV4_Actor_Interactable_Storage();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
