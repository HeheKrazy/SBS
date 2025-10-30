// Copyright HeheKrazy


#include "AbilitySystem/AbilityTasks/SBS_WaitGameplayEvent.h"

void USBS_WaitGameplayEvent::StartActivation()
{
	Activate();
}

USBS_WaitGameplayEvent* USBS_WaitGameplayEvent::WaitGameplayEventToActorProxy(AActor* TargetActor, FGameplayTag EventTag, bool OnlyTriggerOnce, bool OnlyMatchExact)
{
	USBS_WaitGameplayEvent* MyObj = NewObject<USBS_WaitGameplayEvent>();
	MyObj->SetAbilityActor(TargetActor);
	MyObj->Tag = EventTag;
	MyObj->OnlyTriggerOnce = OnlyTriggerOnce;
	MyObj->OnlyMatchExact = OnlyMatchExact;
	return MyObj;
}
