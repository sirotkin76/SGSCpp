// Copyright (c) 2026 SirotkinAleksandr. All Rights Reserved.

#pragma once

#include "Engine.h"
#include "Engine/DataAsset.h"
#include "Net/UnrealNetwork.h"
#include "GameplayEffectTypes.h"
#include "Abilities/GameplayAbilityTargetTypes.h"
#include "Components/Widget.h"

#include "SGSCppV4_Struct.generated.h"


struct FGameplayEffectSpecHandle;

class USGSCppV4_TargetType;
class USGSCppV4_DataAsset_Attr_Slot;
class URPGAbilitySystemComponent;
class UGameplayEffect;
class URPGTargetType;
class USGSCppV4_DataAsset_Attr_Skill;


USTRUCT(BlueprintType)
struct FSGSCppV4_Ability_Update
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SGSCpp|AbilityUpdate")
	USGSCppV4_DataAsset_Attr_Skill * SGSCppV4_DataAsset_Attr_Ability;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SGSCpp|AbilityUpdate")
	int32 AbiltyLevel = 1;
};


USTRUCT(BlueprintType)
struct FSGSCppV4_SlotCount
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SGSCppGraph|FSGSCppV4_SlotCount")
	USGSCppV4_DataAsset_Attr_Slot * SGSCppV4_InvSlot_DataAsset;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SGSCppGraph|FSGSCppV4_SlotCount")
	int32 Count = 1;
};


USTRUCT(BlueprintType)
struct FSGSCppV4Slot
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FSGSCpp|InventarySystem")
	UPrimaryDataAsset * PrimaryDataAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FSGSCpp|InventarySystem|Navigation")
	int32 Index = -1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FSGSCpp|InventarySystem|Navigation")
	int32 Level = -1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FSGSCpp|InventarySystem|Navigation")
	FName Name;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FSGSCpp|InventarySystem", meta = (ClampMin=1, Min=1))
	int32 Count = -1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FSGSCpp|InventarySystem")
	float Condition = -1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FSGSCpp|InventarySystem|Navigation")
	FVector Location;
};


/**
 * Struct defining a list of gameplay effects, a tag, and targeting info
 * These containers are defined statically in blueprints or assets and then turn into Specs at runtime
 */
USTRUCT(BlueprintType)
struct FSGSCppGameplayEffectContainerV4
{
	GENERATED_BODY()

public:
	FSGSCppGameplayEffectContainerV4() {}

	/** Sets the way that targeting happens */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GameplayEffectContainer)
	TSubclassOf<USGSCppV4_TargetType> TargetType;

	/** List of gameplay effects to apply to the targets */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GameplayEffectContainer)
	TArray<TSubclassOf<UGameplayEffect>> TargetGameplayEffectClasses;
};

/** A "processed" version of RPGGameplayEffectContainer that can be passed around and eventually applied */
USTRUCT(BlueprintType)
struct FSGSCppV4_GE_ContainerSpec
{
	GENERATED_BODY()

public:
	FSGSCppV4_GE_ContainerSpec();

	/** Computed target data */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GameplayEffectContainer)
	FGameplayAbilityTargetDataHandle TargetData;

	/** List of gameplay effects to apply to the targets */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GameplayEffectContainer)
	TArray<FGameplayEffectSpecHandle> TargetGameplayEffectSpecs;

	/** Returns true if this has any valid effect specs */
	bool HasValidEffects() const;

	/** Returns true if this has any valid targets */
	bool HasValidTargets() const;

	/** Adds new targets to target data */
	void AddTargets(const TArray<FHitResult>& HitResults, const TArray<AActor*>& TargetActors);
};
