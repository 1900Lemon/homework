// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyFPSHwProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "EnemyCharacter.h"
#include "GameFramework/PlayerState.h"
//#include "kismet/GamePlayStatics.h"
//#include "UObject/ConstructorHelpers.h"

AMyFPSHwProjectile::AMyFPSHwProjectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &AMyFPSHwProjectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;
	Damage = 10.0f;
	//replicate
	bReplicates = true;
}

void AMyFPSHwProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics

	
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		UE_LOG(LogTemp,Warning,TEXT("Hit"));
		AEnemyCharacter* Boss = Cast<AEnemyCharacter>(OtherActor);
		if (Boss)
		{
			UE_LOG(LogTemp,Warning,TEXT("Boss"));
			Boss->MyTakeDamage(10);
			if (Boss->Health == 0)
			{
				AActor* OwnerActor = this->GetInstigator();
				if (OwnerActor)
				{
					UE_LOG(LogTemp,Warning,TEXT("OWNER"));
					AController* OwnerController = Cast<AController>(OwnerActor->GetInstigatorController());
					if (OwnerController)
					{
						UE_LOG(LogTemp,Warning,TEXT("Controller"));
						APlayerState* OnwerPlayerState = OwnerController->PlayerState;
						//UE_LOG(LogTemp, Log, TEXT("find state:p", OwnerPlayerState));
						UE_LOG(LogTemp, Log, TEXT("find state"));
						if (OnwerPlayerState)
						{
							OnwerPlayerState->Score += 50;
						}
					}
				}
			}
			Destroy();
		}
		else
		{
			UE_LOG(LogTemp,Warning,TEXT("NonBoss"));
			OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());
			Destroy();
		}
		
	}
}