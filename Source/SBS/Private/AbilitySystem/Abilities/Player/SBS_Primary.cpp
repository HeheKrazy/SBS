// Copyright HeheKrazy


#include "AbilitySystem/Abilities/Player/SBS_Primary.h"
#include "Engine/OverlapResult.h"

void USBS_Primary::HitBoxOverlapTest()
{
	//Ignore the owning actor
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(GetOwningActorFromActorInfo());

	//Ensure overlap test ignores the avatar actor
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActors(ActorsToIgnore);

	//Set collision response to only hit pawns
	FCollisionResponseParams ResponseParams;
	ResponseParams.CollisionResponse.SetAllChannels(ECollisionResponse::ECR_Ignore);
	ResponseParams.CollisionResponse.SetResponse(ECC_Pawn, ECR_Block);

	TArray<FOverlapResult> OverlapResults;
	FCollisionShape Sphere = FCollisionShape::MakeSphere(HitBoxRadius);

	//Calculate hitbox location
	const FVector ForwardVector = GetAvatarActorFromActorInfo()->GetActorForwardVector() * HitBoxForwardOffset;
	const FVector HitBoxLocation = GetAvatarActorFromActorInfo()->GetActorLocation() + ForwardVector + FVector(0.f, 0.f, HitBoxElevationOffset);

	GetWorld()->OverlapMultiByChannel(
		OverlapResults,
		HitBoxLocation,
		FQuat::Identity,
		ECC_Pawn,
		Sphere,
		QueryParams,
		ResponseParams
	);

	if(bDrawDebugs)
	{
		//Draw debug sphere
		DrawDebugSphere(GetWorld(), HitBoxLocation, HitBoxRadius, 16, FColor::Red, false, 3.f);
		
		for (const FOverlapResult& Result : OverlapResults)
		{
			if (IsValid(Result.GetActor()))
			{
				FVector DebugLocation = Result.GetActor()->GetActorLocation();
				DebugLocation.Z += 100.f; //Offset debug line upwards for visibility
				DrawDebugSphere(GetWorld(), DebugLocation, 30.f, 10, FColor::Green, false, 3.f);
			}
		}
	}

}
