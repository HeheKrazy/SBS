// Copyright HeheKrazy


#include "AbilitySystem/SBS_AttributeSet.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"	
#include "AbilitySystemBlueprintLibrary.h"
#include "GameplayTags/SBSTags.h"


/*
*	EXAMPLE Implementation for a single attribute called Health
*	Setup in GetLifetimeReplicatedProps() to replicate our Health attribute.
*	DOREPLIFETIME_CONDITION_NOTIFY(USBS_AttributeSet, Health, COND_None, REPNOTIFY_Always);
* 
*	Implementation of OnRep_Health() to call the macro for replication notification	
*	GAMEPLAYATTRIBUTE_REPNOTIFY(USBS_AttributeSet, Health, OldValue);
*/

void USBS_AttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(USBS_AttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USBS_AttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USBS_AttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USBS_AttributeSet, MaxMana, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME(ThisClass, bAttributesInitialized);
}

void USBS_AttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	
	if(Data.EvaluatedData.Attribute == GetHealthAttribute() && GetHealth() <= 0.f)
	{
		//ToDo Send gameplay event to causer of effect. (E.g., to inform that actor they killed this actor)
		FGameplayEventData Payload;
		Payload.Instigator = Data.Target.GetAvatarActor();
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(Data.EffectSpec.GetEffectContext().GetInstigator(), SBSTags::Events::KillScored, Payload);
	}

	if (!bAttributesInitialized)
	{
		bAttributesInitialized = true;
		OnAttributesInitialized.Broadcast();
	}

}

void USBS_AttributeSet::OnRep_AttributesInitialized()
{
	if(bAttributesInitialized)
	{
		OnAttributesInitialized.Broadcast();
	}
}

void USBS_AttributeSet::OnRep_Health(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USBS_AttributeSet, Health, OldValue);
}

void USBS_AttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USBS_AttributeSet, MaxHealth, OldValue);
}

void USBS_AttributeSet::OnRep_Mana(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USBS_AttributeSet, Mana, OldValue);
}

void USBS_AttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USBS_AttributeSet, MaxMana, OldValue);
}
