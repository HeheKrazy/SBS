// Copyright HeheKrazy


#include "Player/SBS_PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/Character.h"

void ASBS_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//Setup Enhanced Input
	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (!IsValid(InputSubsystem)) return;
	
	//Add all mapping contexts
	for (UInputMappingContext* Context : InputMappingContexts)
	{
		//Add Mapping Context
		InputSubsystem->AddMappingContext(Context, 0);
	}

	//Bind Actions
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	if (!IsValid(EnhancedInputComponent)) return;

	// Jump, Move, Look
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ThisClass::Jump);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ThisClass::StopJumping);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::Move);
	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ThisClass::Look);
}

void ASBS_PlayerController::Jump()
{
	// Jump
	if (!IsValid(GetCharacter())) return;
	GetCharacter()->Jump();
}
void ASBS_PlayerController::StopJumping()
{
	// Stop jumping
	if (!IsValid(GetCharacter())) return;
	GetCharacter()->StopJumping();
}
void ASBS_PlayerController::Move(const FInputActionValue& Value)
{
	//Get movement vector from input
	if (!IsValid(GetPawn())) return;
	const FVector2D MovementVector = Value.Get<FVector2D>();

	//Find out which way is forward
	const FRotator YawRotation(0.f, GetControlRotation().Yaw, 0.f);
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	
	//Add movement in that direction
	GetPawn()->AddMovementInput(ForwardDirection, MovementVector.Y);
	GetPawn()->AddMovementInput(RightDirection, MovementVector.X);

}
void ASBS_PlayerController::Look(const FInputActionValue& Value)
{
	//Get look axis value
	const FVector2D LookAxisVector = Value.Get<FVector2D>();

	//Add yaw and pitch input to controller
	AddYawInput(LookAxisVector.X);
	AddPitchInput(LookAxisVector.Y);
}