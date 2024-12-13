// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"


void UMyGameInstance::Init()
{
	Super::Init();

	FCoreUObjectDelegates::PreLoadMap.AddUObject(this,&UMyGameInstance::BeginLoadingScreen);
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this,&UMyGameInstance::EndLoadingScreen);
}

void UMyGameInstance::BeginLoadingScreen(const FString& MapName)
{
	
	FLoadingScreenAttributes LoadingScreen;
	LoadingScreen.bAutoCompleteWhenLoadingCompletes = false;//是否在播放完所有电影并完成加载后，加载屏幕消失
	LoadingScreen.bWaitForManualStop = true;//是否一直播放movie
	LoadingScreen.bMoviesAreSkippable = true;//是否加载完成，就可以通过单击加载屏幕跳过movie
	LoadingScreen.MinimumLoadingScreenDisplayTime = 3.0f;
	LoadingScreen.WidgetLoadingScreen = FLoadingScreenAttributes::NewTestLoadingScreenWidget();
	LoadingScreen.MoviePaths.Add("F:/UE5/ue5/MyFPSHw/Content/My/Movie/1.uasset");
	//movie 不存在时显示的widget
	if (LoadingWidget != nullptr)
	{
		CurrentWidge = CreateWidget<ULoadingWidgetClass>(this,LoadingWidget);
		if (CurrentWidge)
		{
			TSharedPtr<SWidget> LoadScreen = CurrentWidge->TakeWidget();
			LoadingScreen.WidgetLoadingScreen = LoadScreen;
			UE_LOG(LogTemp,Warning,TEXT("Loadingwidget"));
		}
	}
	else
	{
		UE_LOG(LogTemp,Warning,TEXT("Loadingwidget == nullptr!"));
		
	}
	if (GetMoviePlayer())
	{
		UE_LOG(LogTemp,Warning,TEXT("find"));
	}
	GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);

	// if (LoadingWidget && !CurrentWidge)
	// {
	// 	CurrentWidge = CreateWidget<UUserWidget>(this,LoadingWidget);
	// 	
	// 	UE_LOG(LogTemp,Warning,TEXT("LoadSuccess1!"));
	// }
	// if (CurrentWidge)
	// {
	// 	UE_LOG(LogTemp,Warning,TEXT("LoadSuccess2!"));
	// 	CurrentWidge->AddToViewport();
	// }
}


void UMyGameInstance::EndLoadingScreen(UWorld* LoadedWorld)
{
	UE_LOG(LogTemp,Warning,TEXT("LoadSuccess!"));
	
	GetMoviePlayer()->StopMovie();
	// if (CurrentWidge)
	// {
	// 	// CurrentWidge->RemoveFromParent();
	// 	// CurrentWidge = nullptr;
	// }
}


