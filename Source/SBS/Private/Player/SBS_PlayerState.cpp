// Copyright HeheKrazy


#include "Player/SBS_PlayerState.h"
#include "AbilitySystem/SBSAbilitySystemComponent.h"
#include "AbilitySystem/SBS_AttributeSet.h"

ASBS_PlayerState::ASBS_PlayerState()
{

	SetNetUpdateFrequency(100.f);

	//Ability System Component
	AbilitySystemComponent = CreateDefaultSubobject<USBSAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	AttributeSet = CreateDefaultSubobject<USBS_AttributeSet>("AttributeSet");
}

UAbilitySystemComponent* ASBS_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
