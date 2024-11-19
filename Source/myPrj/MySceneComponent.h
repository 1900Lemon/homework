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
	//FVector ��ʾ�ռ��е�λ�á������ٶȡ����ٶȵ�
	FVector StartLocation;
	UPROPERTY(EditAnywhere)//����UE�ķ���ϵͳ������л����ԣ��Լ�����ڱ༭������ʾ�ͱ༭��Щ���ԡ�
	float speed = 1.0f;

	UPROPERTY(EditAnywhere);
	//editanywhere ָ�����Կ������κεط��༭ ���Ա���C++�����߱༭
	FVector EndLocation;

	//UPROPERTY ����Խ��ն������ ����ָ�����Եĸ������Ժ���Ϊ��
	// Category: ָ�������ڱ༭���е����
	//Meta: �ṩ�����Ԫ���ݣ��� EditCondition��ClampMin��ClampMax �ȡ�
	//BlueprintReadOnly : �����ڱ༭������ʾ���ԣ���������ʱ���ɼ���
	//VisibleAnywhere : ������ EditAnywhere������Ҫ������ C++ �����п������ԵĿɼ��ԡ�
	//Parm : �����ں��������б�����ԣ��Ա����ǿ�������ͼ��ʹ�á�


		
	FVector CurrLocation;

	float stoppingDistance = 1.0f;


		
	
};
