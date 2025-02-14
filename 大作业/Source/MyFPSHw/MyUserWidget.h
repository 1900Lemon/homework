// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UMG.h"
#include "MyUserWidget.generated.h"
/**
 * 
 */
UCLASS()
class MYFPSHW_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UTextBlock* Score;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UTextBlock* Time;
	//UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	//	class UTextBlock* Bullets;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UProgressBar* BloodBar;
	float fScore;
	int32 iTime;
	//int32 BulletsNum;
public:
	void UpdateScore();
	void UpdateTime();
	void UpdateBloodBar();
	//void UpdateBullets(float NewScore);
};