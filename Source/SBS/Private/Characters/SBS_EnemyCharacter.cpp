// Copyright HeheKrazy


#include "Characters/SBS_EnemyCharacter.h"
#include "AbilitySystemComponent.h"	

ASBS_EnemyCharacter::ASBS_EnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
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
