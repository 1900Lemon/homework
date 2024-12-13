// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "LoadingWidgetClass.h"
#include "MoviePlayer.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/IUMGModule.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "Runtime/MoviePlayer/Public/MoviePlayer.h"
#include "Runtime/SlateCore/Public/Widgets/SWidget.h"

#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class MYFPSHW_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init()override;
	//显示加载屏幕
	UFUNCTION()
	virtual  void	BeginLoadingScreen(const FString& MapName);
	//结束加载屏幕
	UFUNCTION()
	virtual void	EndLoadingScreen(UWorld* LoadedWorld);


public:
	
	UPROPERTY()
		UUserWidget* CurrentWidge;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="UMGGame")
		TSubclassOf<UUserWidget> LoadingWidget;
	
};
