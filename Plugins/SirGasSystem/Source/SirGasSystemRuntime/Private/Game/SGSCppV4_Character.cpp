// Copyright (c) 2026 SirotkinAleksandr. All Rights Reserved.


#include "Game/SGSCppV4_Character.h"


// Sets default values
ASGSCppV4_Character::ASGSCppV4_Character()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create ability system component, and set it to be explicitly replicated
	/*
	AbilitySystemComponent = CreateDefaultSubobject<USGSCppV4_AbilitySystemComponent>(TEXT("SGSCppV4_AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(false);
	*/

	// Create the attribute set, this replicates by default
	AttributeSet = CreateDefaultSubobject<USGSCppV4_AttributeSet>(TEXT("SGSCppV4_AttributeSet"));

	/*
	SGSCppV4_Component_MasterLogic = CreateDefaultSubobject<USGSCppV4_Component_MasterLogic>(TEXT("SGSCppV4_Component_MasterLogic"));
	SGSCppV4_Component_MasterLogic->SetIsReplicated(false);
	*/

	
}

// Called when the game starts or when spawned
void ASGSCppV4_Character::BeginPlay()
{
	Super::BeginPlay();
	
	// AbilitySystemComponent = Cast<USGSCppV4_AbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(this));
	//SGSCppV4_Component_MasterLogic->FSGSCppInitializationCharacterAttrubite(AbilitySystemComponent, FSGSCppGetAttributeSet());
}

void ASGSCppV4_Character::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
}

void ASGSCppV4_Character::UnPossessed()
{
	Super::UnPossessed();
}

void ASGSCppV4_Character::OnRep_Controller()
{
	Super::OnRep_Controller();
}

void ASGSCppV4_Character::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

/*
UAbilitySystemComponent* ASGSCppV4_Character::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

USGSCppV4_AbilitySystemComponent* ASGSCppV4_Character::GetSGSCppAbilitySystemComponent() 
{
	return AbilitySystemComponent;
}
*/

USGSCppV4_AttributeSet* ASGSCppV4_Character::FSGSCppV4_Interface_AttributeSet_Get_Implementation() const
{
	return AttributeSet;
}

// Called every frame
void ASGSCppV4_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ASGSCppV4_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

USGSCppV4_AttributeSet* ASGSCppV4_Character::FSGSCppGetAttributeSet()
{
	if (IsValid(AttributeSet)) return AttributeSet;

	return nullptr;
}

void ASGSCppV4_Character::HandleDamage(
	float DamageAmount,
	const FHitResult& HitInfo,
	const struct FGameplayTagContainer& DamageTags,
	ASGSCppV4_Character* InstigatorPawn,
	AActor* DamageCauser
	)
{
	FSGSCppOnDamaged(DamageAmount, HitInfo, DamageTags, InstigatorPawn, DamageCauser);	
}

void ASGSCppV4_Character::HandleHealthChanged(float DeltaValue, const struct FGameplayTagContainer& EventTags)
{	// We only call the BP callback if this is not the initial ability setup

	FSGSCppOnHealthChanged(DeltaValue, EventTags);
}

void ASGSCppV4_Character::HandleManaChanged(float DeltaValue, const struct FGameplayTagContainer& EventTags)
{
	FSGSCppOnManaChanged(DeltaValue, EventTags);
}

void ASGSCppV4_Character::HandleMoveSpeedChanged(float DeltaValue, const struct FGameplayTagContainer& EventTags)
{
	// Update the character movement's walk speed
	GetCharacterMovement()->MaxWalkSpeed = AttributeSet->GetMoveSpeed();;

	FSGSCppOnMoveSpeedChanged(DeltaValue, EventTags);
}

void ASGSCppV4_Character::HandleStaminaChanged(float DeltaValue, const struct FGameplayTagContainer& EventTags)
{
	FSGSCppOnStaminaChanged(DeltaValue, EventTags);
}

void ASGSCppV4_Character::HandleWaterChanged(float DeltaValue, const struct FGameplayTagContainer& EventTags)
{
	FSGSCppOnWaterChanged(DeltaValue, EventTags);
}

void ASGSCppV4_Character::HandleFoodChanged(float DeltaValue, const struct FGameplayTagContainer& EventTags)
{
	FSGSCppOnFoodChanged(DeltaValue, EventTags);
}

void ASGSCppV4_Character::HandleOxygenChanged(float DeltaValue,
	const struct FGameplayTagContainer& EventTags)
{
	FSGSCppOnOxygenChanged(DeltaValue, EventTags);
}

FGenericTeamId ASGSCppV4_Character::GetGenericTeamId() const
{
	static const FGenericTeamId PlayerTeam(0);
	static const FGenericTeamId AITeam(1);
	return Cast<APlayerController>(GetController()) ? PlayerTeam : AITeam;
}

bool ASGSCppV4_Character::FSGSCppGetIsAlive()
{
	return AttributeSet->GetMaxHealth() > 0.0f;
}

//GEngine->AddOnScreenDebugMessage(-1, 50.f, FColor::Blue, TEXT("BeginPlay")); // print string
	
//GEngine->AddOnScreenDebugMessage(-1, 50.f, FColor::Blue, TEXT("PossessedBy")); // print string