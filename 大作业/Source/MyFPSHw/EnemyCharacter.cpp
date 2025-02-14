// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"
#include "MyFPSHwProjectile.h"

#include "Estat.h"


// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//StatsComp = CreateDefaultSubobject<UStatsComponent>(TEXT("Stats Component"));// Health = 100.f
	EnemyAnim = Cast<UEnemy_AnimInstance>(
		GetMesh()->GetAnimInstance()
	);
	MaxHealth = 100;
	Health = MaxHealth;
	bisDie = false;

}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	// EnemyAnim = Cast<UEnemy_AnimInstance>(
	// 	GetMesh()->GetAnimInstance()
	// );
	


}




// Called every frame
void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// isDead();
}

// Called to bind functionality to input
void AEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//PlayerInputComponent->BindAction("OnDamagePressed", IE_Pressed, this, &AEnemyCharacter::DamagePlayerCharacter);
}


// float AEnemyCharacter::GetDamage()
// {
// 	return StatsComp->Stats[EStat::Strength];
// }

void AEnemyCharacter::MyTakeDamage(float Amount)
{
	Health -= Amount;
	UE_LOG(LogTemp, Log, TEXT("current health is %f"),Health);
	Health = 	FMath::Clamp(Health,0,MaxHealth);
	if (Health <= 0)
	{
		bisDie = true;
		isDead();
		return;
	}
}

void AEnemyCharacter::isDead()
{
	Destroy();
}



// void AEnemyCharacter::ReduceHealth(float DamageAmount)
// {
// 	// Health -= DamageAmount;
// 	// if (Health<=0)
// 	// {
// 	// 	OnDeath();
// 	// 	
// 	// }
// }
//
// void AEnemyCharacter::OnDeath()
// {
// 	
// }

