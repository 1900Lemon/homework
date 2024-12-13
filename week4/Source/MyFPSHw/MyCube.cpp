// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCube.h"
#include "MyFPSHwProjectile.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"




// Sets default values
AMyCube::AMyCube()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
	PointOneMaterial = CreateDefaultSubobject<UMaterialInstance>(TEXT("PointOneMaterial"));
	PointTwoMaterial = CreateDefaultSubobject<UMaterialInstance>(TEXT("PointTwoMaterial"));

	CubeMesh->SetSimulatePhysics(true);

	bReplicates = true;
	bReplicateMovement = true;
	bNetLoadOnClient = false;
}

void AMyCube::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AMyCube, CurrentMaterial);
	DOREPLIFETIME(AMyCube, bIsTwo);
	DOREPLIFETIME(AMyCube, ScaleCnt);
}


void AMyCube::OnRep_Material()
{
	if(CubeMesh)
	{
		CubeMesh->SetMaterial(0, CurrentMaterial);
	}
}

//void AMyCube::OnRep_Point()
//{
//	bIsTwo = bCurrentIsTwo;
//}
//
//void AMyCube::OnRep_Scale()
//{
//	bScaled = bCurrentScaled;
//}

void AMyCube::OnComponentHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("Actor address:%p"), OtherActor);
	if (AMyFPSHwProjectile* HitActor = Cast<AMyFPSHwProjectile>(OtherActor))
	{

		//用serverRPC  服务端调用 客户端同时调用 并通知服务端
		if (HasAuthority()) 
		{
			//UE_LOG(LogTemp, Warning, TEXT("be Hitted!"));
			////Scale(1);
			//OnTakePoint(OtherActor);
			//ScaleCnt += 1;
			//OnRep_Scale();
			//服务器执行逻辑
			//研究怎么同步到客户端
			ServerHit(OtherActor);
			/*for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator();Iterator;++Iterator) {
				APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
				if (PlayerController)
				{
					this->SetOwner(PlayerController);
					UE_LOG(LogTemp, Log, TEXT("Client:Cube owner is %s"), GetOwner() ? *GetOwner()->GetName() : TEXT("None"));
				}
			}*/
			UE_LOG(LogTemp, Log, TEXT("Server:Cube owner is %s"), GetOwner() ? *GetOwner()->GetName() : TEXT("None"));
		}
		else
		{
			//APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
			//if (PlayerController && PlayerController->IsLocalPlayerController())
			//{
			//	this->SetOwner(PlayerController);
			//	UE_LOG(LogTemp, Log, TEXT("Client:Cube owner is %s"), GetOwner() ? *GetOwner()->GetName() : TEXT("None"));
			//}
			//UE_LOG(LogTemp, Warning, TEXT("be Hitted!"));
			////Scale(1);
			//OnTakePoint(OtherActor);
			//ScaleCnt += 1;
			//OnRep_Scale();
			//ServerHit(OtherActor);
			//UE_LOG(LogTemp, Log, TEXT("Client:Cube owner is %s"), GetOwner() ? *GetOwner()->GetName() : TEXT("None"));
			ServerHit(OtherActor);
			UE_LOG(LogTemp, Log, TEXT("Client:Cube owner is %s"), GetOwner() ? *GetOwner()->GetName() : TEXT("None"));
		}



		//UE_LOG(LogTemp, Warning, TEXT("beHitted!"));
		//Scale(1);
		//OnTakePoint(OtherActor);
		//SetBisScaled(bScaled);
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
			if (OnwerPlayerState) 
			{
				UE_LOG(LogTemp, Log, TEXT("state"));
				if (bIsTwo)
				{
					OnwerPlayerState->Score += 20;/*
					OnwerPlayerState->OnRep_Score();*/
				}
				else 
				{
					OnwerPlayerState->Score += 10;
					//OnwerPlayerState->OnRep_Score();
				}
				//UE_LOG(LogTemp, Log, TEXT("name:%s"), OnwerPlayerState->GetPlayerName());
				/*UE_LOG(LogTemp, Log, TEXT("Score:%f"), OnwerPlayerState->Score);*/
			}
		}
		else 
		{
			UE_LOG(LogTemp, Log, TEXT("not find"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("not find"));
	}
}



void AMyCube::OnTransform()
{

	int32 RandomNum = FMath::RandRange(0, 100);
	if (RandomNum <= 50) {
		if (PointOneMaterial) {
			CurrentMaterial = PointOneMaterial;
			if (CubeMesh) 
			{
				CubeMesh->SetMaterial(0, PointOneMaterial);
			}

		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("No PointOneMaterial!"));
		}
	}
	else {
		if (PointTwoMaterial) {
			bIsTwo = true;
			CurrentMaterial = PointTwoMaterial;
			if (CubeMesh)
			{
				CubeMesh->SetMaterial(0, PointTwoMaterial);
			}

		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("No PointTwoMaterial!"));
		}
	}
}

//void AMyCube::MulticastInform()
//{
//
//}

void AMyCube::Scale()
{
	if (ScaleCnt == 2) {
		//bScaled = false;
		UE_LOG(LogTemp, Warning, TEXT("destroy!"));
		ScaleCnt = 0;
		Destroy();
	}
	else {
		//bScaled = true;
		UE_LOG(LogTemp, Warning, TEXT("scaled!"));
		FVector CurrentScale = GetActorScale3D();
		UE_LOG(LogTemp, Warning, TEXT("CurrentScaleX=%f"), CurrentScale.X);
		float targetScaleX = CurrentScale.X  / y;
		float targetScaleY = CurrentScale.Y  / y;
		float targetScaleZ = CurrentScale.Z  / y;
		UE_LOG(LogTemp, Warning, TEXT("targetScaleX=%f"), targetScaleX);
		CurrentScale.X = targetScaleX;
		CurrentScale.Y = targetScaleY;
		CurrentScale.Z = targetScaleZ;

		SetActorScale3D(CurrentScale);
	}
}

void AMyCube::ServerHit_Implementation(AActor* OtherActor)
{
	if(HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("be Hitted!"));
		//Scale(1);
		OnTakePoint(OtherActor);
		ScaleCnt += 1;
		OnRep_Scale();
	}
}

bool AMyCube::ServerHit_Validate(AActor* OtherActor)
{
	return true;
}



// Called when the game starts or when spawned
void AMyCube::BeginPlay()
{
	Super::BeginPlay();
	if (HasAuthority()) 
	{

		OnTransform();	

		//UE_LOG(LogTemp, Log, TEXT("Server:Cube owner is %s"), GetOwner() ? *GetOwner()->GetName() : TEXT("None"));
	}


	CubeMesh->OnComponentHit.AddDynamic(this, &AMyCube::OnComponentHit);
}

void AMyCube::OnRep_Point()
{

}

void AMyCube::OnRep_Scale()
{
	Scale();
}




// Called every frame
void AMyCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



