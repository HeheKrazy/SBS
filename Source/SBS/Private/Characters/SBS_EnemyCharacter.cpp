// Copyright HeheKrazy


#include "Characters/SBS_EnemyCharacter.h"
#include "AbilitySystem/SBSAbilitySystemComponent.h"
#include "AbilitySystem/SBS_AttributeSet.h"	

ASBS_EnemyCharacter::ASBS_EnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	AbilitySystemComponent = CreateDefaultSubobject<USBSAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<USBS_AttributeSet>("AttributeSet");
}

UAbilitySystemComponent* ASBS_EnemyCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ASBS_EnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (!IsValid(GetAbilitySystemComponent())) return;

	GetAbilitySystemComponent()->InitAbilityActorInfo(this, this);
	
	if (!HasAuthority()) return;	

	GiveStartupAbilities();
}
