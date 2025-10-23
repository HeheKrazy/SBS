// Copyright HeheKrazy


#include "Player/SBS_PlayerState.h"
#include "AbilitySystemComponent.h"

ASBS_PlayerState::ASBS_PlayerState()
{

	SetNetUpdateFrequency(100.f);

	//Ability System Component
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}

UAbilitySystemComponent* ASBS_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
