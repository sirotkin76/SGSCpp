// Copyright (c) 2026 SirotkinAleksandr. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SGSCppV4_Interface_GameplayAbility.generated.h"

class USGSCppV4_AttributeSet;

UINTERFACE()
class USGSCppV4_Interface_GameplayAbility : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SIRGASSYSTEMRUNTIME_API ISGSCppV4_Interface_GameplayAbility
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "SGSCppV4|InterfaceFunction")
	USGSCppV4_AttributeSet* FSGSCppV4_Interface_AttributeSet_Get() const;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "SGSCppV4|InterfaceFunction")
	void FSGSCppV4_Interface_Player_NewLevel() const;
	
	/*
	virtual USGSCppV4_Component_MasterLogic* SGSCppV4_GameplayAbility_Implementation() const;
	*/
	
	/*
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat")
	float GetHealth() const;
	
	virtual float GetHealth_Implementation() const;
	*/
	
};
