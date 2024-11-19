// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "MySceneComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )


class MYPRJ_API UMySceneComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	/*
	 struct Fvector
	{
		float x;
		float y;
		float z;

		float Dist(Fvector v1, Fvector v2) {
			return sqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y) + (v1.z - v2.z) * (v1.z - v2.z));
		}
	};
	*/

	// Sets default values for this component's properties
	UMySceneComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
private:
	//FVector 表示空间中的位置、方向、速度、加速度等
	FVector StartLocation;
	UPROPERTY(EditAnywhere)//告诉UE的反射系统如何序列化属性，以及如何在编辑器中显示和编辑这些属性。
	float speed = 1.0f;

	UPROPERTY(EditAnywhere);
	//editanywhere 指定属性可以在任何地方编辑 可以被非C++开发者编辑
	FVector EndLocation;

	//UPROPERTY 宏可以接收多个参数 用于指定属性的各种属性和行为。
	// Category: 指定属性在编辑器中的类别。
	//Meta: 提供额外的元数据，如 EditCondition、ClampMin、ClampMax 等。
	//BlueprintReadOnly : 用于在编辑器中显示属性，但在运行时不可见。
	//VisibleAnywhere : 类似于 EditAnywhere，但主要用于在 C++ 代码中控制属性的可见性。
	//Parm : 用于在函数参数中标记属性，以便它们可以在蓝图中使用。


		
	FVector CurrLocation;

	float stoppingDistance = 1.0f;


		
	
};
