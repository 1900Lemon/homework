// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameOver.generated.h"

/**
 * 
 */
UCLASS()
class MYFPSHW_API UGameOver : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
public:
	
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UTextBlock* Score;
	float fScore;
	void UpdateScore();
	
};
