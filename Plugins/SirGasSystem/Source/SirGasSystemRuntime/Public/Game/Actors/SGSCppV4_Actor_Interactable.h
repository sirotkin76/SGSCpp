// Copyright (c) 2026 SirotkinAleksandr. All Rights Reserved.

#pragma once

#include "Engine.h"
#include "Net/UnrealNetwork.h"
#include "Data/SGSCppV4_Interface_Interactable.h"
#include "GameFramework/Actor.h"
#include "SGSCppV4_Actor_Interactable.generated.h"

UCLASS()
class SIRGASSYSTEMRUNTIME_API ASGSCppV4_Actor_Interactable : public AActor, public ISGSCppV4_Interface_Interactable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASGSCppV4_Actor_Interactable();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="SGSCppV4", meta = (AllowPrivateAccess = "true"))
	FString UniqueId;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SGSCppV4")
	FString SGSCppV4_StatusActor;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
