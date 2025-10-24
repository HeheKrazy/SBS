// Copyright HeheKrazy


#include "AbilitySystem/SBSAbilitySystemComponent.h"

USBSAbilitySystemComponent::USBSAbilitySystemComponent()
{
	PrimaryComponentTick.bCanEverTick = true;


}

void USBSAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();
}

void USBSAbilitySystemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
