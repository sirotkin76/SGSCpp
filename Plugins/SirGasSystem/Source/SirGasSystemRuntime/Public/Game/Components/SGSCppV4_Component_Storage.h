// Copyright (c) 2026 SirotkinAleksandr. All Rights Reserved.

#pragma once

#include "Engine.h"
#include "Net/UnrealNetwork.h"
#include "Data/SGSCppV4_Struct.h"
#include "Components/ActorComponent.h"
#include "SGSCppV4_Component_Storage.generated.h"

class USGSCppV4_DataAsset_Attr;
class USGSCppV4_DataAsset_Attr_Slot;


UCLASS(MinimalAPI, ClassGroup=("FSGSCpp|InventarySystem"), meta=(BlueprintSpawnableComponent), Blueprintable, BlueprintType, meta = (ShowWorldContextPin)  )
class USGSCppV4_Component_Storage : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USGSCppV4_Component_Storage();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FSGSCpp|Storage|Var")
	TArray<FSGSCppV4Slot> FSGSCpp_Slots;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "FSGSCpp|Storage|Functions", meta = (DisplayName = "SGS Cpp V4 Storage Slots Get "))
	TArray<FSGSCppV4Slot> FSGSCpp_Slots_Get();
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "FSGSCpp|Storage|Functions", meta = (DisplayName = "SGS Cpp V4 Storage Slots Get use id or index "))
	FSGSCppV4Slot FSGSCpp_Slots_Get_Id(int32 index, bool &find);
		
	UFUNCTION(BlueprintCallable, Category = "FSGSCpp|Storage|Functions", meta = (DisplayName = "SGS Cpp V4 Storage Slots Set"))
	void FSGSCpp_Slots_Set(TArray<FSGSCppV4Slot> NewItems);

	UFUNCTION(BlueprintCallable, Category = "FSGSCpp|Storage|Functions", meta = (DisplayName = "SGS Cpp V4 Storage - Creates new empty slots (ADD)"))
	void FSGSCpp_Slots_InitEmpty_SetNew(int32 CountNewEmptySlots);

};
