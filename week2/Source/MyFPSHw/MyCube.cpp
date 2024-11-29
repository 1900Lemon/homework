// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCube.h"
#include "MyFPSHwProjectile.h"

// Sets default values
AMyCube::AMyCube()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
	PointOneMaterial = CreateDefaultSubobject<UMaterialInstance>(TEXT("PointOneMaterial"));
	PointTwoMaterial = CreateDefaultSubobject<UMaterialInstance>(TEXT("PointTwoMaterial"));

	CubeMesh->SetSimulatePhysics(true);
}

void AMyCube::OnComponentHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("Actor address:%p"), OtherActor);
	if (AMyFPSHwProjectile* HitActor = Cast<AMyFPSHwProjectile>(OtherActor))
	{
		UE_LOG(LogTemp, Warning, TEXT("beHitted!"));
		Scale(1);
		OnTakePoint(OtherActor);
	}
}

void AMyCube::OnTakePoint(AActor* OtherActor)
{
	AActor* OwnerActor = OtherActor->GetInstigator();
	UE_LOG(LogTemp, Warning, TEXT("OwnerActor address:%p"), OwnerActor);
	if (OwnerActor)
	{
		UE_LOG(LogTemp, Log, TEXT("find Owner"));
		AController* OwnerController = Cast<AController>(OwnerActor->GetInstigatorController());
		//UE_LOG(LogTemp, Log, TEXT("Controller:%p",OwnerController));
		if (OwnerController)
		{
			APlayerState* OnwerPlayerState = OwnerController->PlayerState;
			//UE_LOG(LogTemp, Log, TEXT("find state:p", OwnerPlayerState));
			UE_LOG(LogTemp, Log, TEXT("find"));
			if (OnwerPlayerState) {
				UE_LOG(LogTemp, Log, TEXT("state"));
				if (BisTwo) {
					OnwerPlayerState->Score += 20;
				}
				else {
					OnwerPlayerState->Score += 10;
				}
				UE_LOG(LogTemp, Log, TEXT("Score:%f"), OnwerPlayerState->Score);
			}
		}
		else {
			UE_LOG(LogTemp, Log, TEXT("not find"));
		}
	}
	else {
		UE_LOG(LogTemp, Log, TEXT("not find"));
	}
}

void AMyCube::OnTransform()
{
	int32 RandomNum = FMath::RandRange(0, 100);
	if (RandomNum <= 50) {
		if (PointOneMaterial) {

			CubeMesh->SetMaterial(0, PointOneMaterial);
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("No PointOneMaterial!"));
		}
	}
	else {
		if (PointTwoMaterial) {
			BisTwo = true;
			CubeMesh->SetMaterial(0, PointTwoMaterial);
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("No PointTwoMaterial!"));
		}
	}
}

void AMyCube::Scale(int y)
{
	if (bScaled) {
		bScaled = false;
		UE_LOG(LogTemp, Warning, TEXT("destroy!"));
		Destroy();
	}
	else {
		bScaled = true;
		UE_LOG(LogTemp, Warning, TEXT("scaled!"));
		FVector CurrentScale = GetActorScale3D();
		UE_LOG(LogTemp, Warning, TEXT("CurrentScaleX=%f"), CurrentScale.X);
		float targetScaleX = CurrentScale.X * (1 / y);
		float targetScaleY = CurrentScale.Y * (1 / y);
		float targetScaleZ = CurrentScale.Z * (1 / y);
		UE_LOG(LogTemp, Warning, TEXT("targetScaleX=%f"), targetScaleX);
		CurrentScale.X = targetScaleX;
		CurrentScale.Y = targetScaleY;
		CurrentScale.Z = targetScaleZ;

		SetActorScale3D(CurrentScale);
	}
}

// Called when the game starts or when spawned
void AMyCube::BeginPlay()
{
	Super::BeginPlay();
	OnTransform();
	CubeMesh->OnComponentHit.AddDynamic(this, &AMyCube::OnComponentHit);
}

// Called every frame
void AMyCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

