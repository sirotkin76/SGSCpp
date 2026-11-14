// Copyright (c) 2026 SirotkinAleksandr. All Rights Reserved.


#include "Game/SGSCppV4_Pawn.h"


// Sets default values
ASGSCppV4_Pawn::ASGSCppV4_Pawn()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create ability system component, and set it to be explicitly replicated
	AbilitySystemComponent = CreateDefaultSubobject<USGSCppV4_Component_AbilitySystem>(TEXT("SGSCppV4_AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(false);

	// Create the attribute set, this replicates by default
	AttributeSet = CreateDefaultSubobject<USGSCppV4_AttributeSet>(TEXT("SGSCppV4_AttributeSet"));

	/*
	SGSCppV4_Component_MasterLogic = CreateDefaultSubobject<USGSCppV4_Component_MasterLogic>(TEXT("SGSCppV4_Component_MasterLogic"));
	SGSCppV4_Component_MasterLogic->SetIsReplicated(false);
	*/

}

USGSCppV4_Component_AbilitySystem* ASGSCppV4_Pawn::GetSGSCppAbilitySystemComponent() 
{
	return AbilitySystemComponent;
}

// Called when the game starts or when spawned
void ASGSCppV4_Pawn::BeginPlay()
{
	Super::BeginPlay();
	
	//SGSCppV4_Component_MasterLogic->FSGSCppInitializationCharacterAttrubite(AbilitySystemComponent, AttributeSet);

	//GEngine->AddOnScreenDebugMessage(-1, 50.f, FColor::Blue, TEXT("BeginPlay")); // print string
	
}

void ASGSCppV4_Pawn::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	//GEngine->AddOnScreenDebugMessage(-1, 50.f, FColor::Blue, TEXT("PossessedBy")); // print string
}

void ASGSCppV4_Pawn::UnPossessed()
{
	Super::UnPossessed();
}

void ASGSCppV4_Pawn::OnRep_Controller()
{
	Super::OnRep_Controller();
	
	if (GetAbilitySystemComponent()) GetAbilitySystemComponent()->RefreshAbilityActorInfo();

}

void ASGSCppV4_Pawn::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

UAbilitySystemComponent* ASGSCppV4_Pawn::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

float ASGSCppV4_Pawn::FSGSCppGetHealth() const
{
	if (!AttributeSet)
		return 1.f;

	return AttributeSet->GetHealth();
}

void ASGSCppV4_Pawn::FSGSCppSetHealth(float SetNewHealth)
{
	if (AttributeSet)
	{
		AttributeSet->SetHpAndMaxHp(SetNewHealth, FSGSCppGetMaxHealth());
	}
}

float ASGSCppV4_Pawn::FSGSCppGetMaxHealth() const
{
	return AttributeSet->GetMaxHealth();
}

float ASGSCppV4_Pawn::FSGSCppGetMana() const
{
	return AttributeSet->GetMana();
}

float ASGSCppV4_Pawn::FSGSCppGetMaxMana() const
{
	return AttributeSet->GetMaxMana();
}

// Called every frame
void ASGSCppV4_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ASGSCppV4_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

USGSCppV4_AttributeSet* ASGSCppV4_Pawn::FSGSCppV4_Interface_AttributeSet_Get_Implementation() const
{
	return AttributeSet;
}

int32 ASGSCppV4_Pawn::FSGSCppGetCharacterLevel() const
{
	return 1;
}

float ASGSCppV4_Pawn::FSGSCppGetMoveSpeed() const
{
	return AttributeSet->GetMoveSpeed();
}

USGSCppV4_AttributeSet* ASGSCppV4_Pawn::FSGSCppGetAttributeSet()
{
	if (IsValid(AttributeSet)) return AttributeSet;

	return nullptr;
}

void ASGSCppV4_Pawn::HandleDamage(
	float DamageAmount,
	const FHitResult& HitInfo,
	const struct FGameplayTagContainer& DamageTags,
	ASGSCppV4_Pawn* InstigatorPawn,
	AActor* DamageCauser
	)
{
	FSGSCppOnDamaged(DamageAmount, HitInfo, DamageTags, InstigatorPawn, DamageCauser);	
}

void ASGSCppV4_Pawn::HandleHealthChanged(float DeltaValue, const struct FGameplayTagContainer& EventTags)
{	// We only call the BP callback if this is not the initial ability setup
	if (IsValid(GetAbilitySystemComponent()))
	{
		FSGSCppOnHealthChanged(DeltaValue, EventTags);
	}
}

void ASGSCppV4_Pawn::HandleManaChanged(float DeltaValue, const struct FGameplayTagContainer& EventTags)
{
	if (IsValid(GetAbilitySystemComponent()))
	{
		FSGSCppOnManaChanged(DeltaValue, EventTags);
	}
}

void ASGSCppV4_Pawn::HandleMoveSpeedChanged(float DeltaValue, const struct FGameplayTagContainer& EventTags)
{
	// Update the character movement's walk speed
	// GetCharacterMovement()->MaxWalkSpeed = FSGSCppGetMoveSpeed();

	if (IsValid(GetAbilitySystemComponent()))
	{
		FSGSCppOnMoveSpeedChanged(DeltaValue, EventTags);
	}
}

FGenericTeamId ASGSCppV4_Pawn::GetGenericTeamId() const
{
	static const FGenericTeamId PlayerTeam(0);
	static const FGenericTeamId AITeam(1);
	return Cast<APlayerController>(GetController()) ? PlayerTeam : AITeam;
}

bool ASGSCppV4_Pawn::FSGSCppGetIsAlive()
{
	return FSGSCppGetHealth() > 0.0f;
}
