// Copyright HeheKrazy


#include "Player/SBS_PlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/SBS_PlayerState.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/SBS_AttributeSet.h"

ASBS_PlayerCharacter::ASBS_PlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	//Default Values
	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);

	//Default Values for Camera Boom
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	CameraBoom->SetupAttachment(GetRootComponent());\
	CameraBoom->TargetArmLength = 300.0f;
	CameraBoom->bUsePawnControlRotation = true;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 500.0f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.0f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 150.0f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.0f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	//Default Values for Follow Camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>("FollowCamera");
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	Tags.Add(SBSTags::Player);
}

UAbilitySystemComponent* ASBS_PlayerCharacter::GetAbilitySystemComponent() const
{
	ASBS_PlayerState* SBSPlayerState = Cast<ASBS_PlayerState>(GetPlayerState<ASBS_PlayerState>());
	if (!IsValid(SBSPlayerState)) return nullptr;
	return SBSPlayerState->GetAbilitySystemComponent();
}

UAttributeSet* ASBS_PlayerCharacter::GetAttributeSet() const
{
	ASBS_PlayerState* SBSPlayerState = Cast<ASBS_PlayerState>(GetPlayerState<ASBS_PlayerState>());
	if (!IsValid(SBSPlayerState)) return nullptr;

	return SBSPlayerState->GetAttributeSet();
}

void ASBS_PlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	if (!IsValid(GetAbilitySystemComponent()) || !HasAuthority()) return;

	GetAbilitySystemComponent()->InitAbilityActorInfo(GetPlayerState(), this);
	OnASCInitialized.Broadcast(GetAbilitySystemComponent(), GetAttributeSet());
	GiveStartupAbilities();
	InitializeAttributes();

	USBS_AttributeSet* SBSAttributeSet = Cast<USBS_AttributeSet>(GetAttributeSet());
	if (!IsValid(SBSAttributeSet)) return;

	GetAbilitySystemComponent()->GetGameplayAttributeValueChangeDelegate(SBSAttributeSet->GetHealthAttribute()).AddUObject(this, &ThisClass::OnHealthChanged);
}

void ASBS_PlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	if (!IsValid(GetAbilitySystemComponent())) return;

	GetAbilitySystemComponent()->InitAbilityActorInfo(GetPlayerState(), this);
	OnASCInitialized.Broadcast(GetAbilitySystemComponent(), GetAttributeSet());
}
