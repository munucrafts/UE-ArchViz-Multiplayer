// Fill out your copyright notice in the Description page of Project Settings.

#include "Cpp_LayoutModifier.h"


// Sets default values
ACpp_LayoutModifier::ACpp_LayoutModifier()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	LayoutWidgetComp = CreateDefaultSubobject<UWidgetComponent>(TEXT("LayoutWidgetComp"));
	LayoutWidgetComp->SetupAttachment(RootComponent);
	LayoutWidgetComp->SetHiddenInGame(true);
	LayoutWidgetComp->SetDrawAtDesiredSize(true);
	LayoutWidgetComp->SetWidgetSpace(EWidgetSpace::Screen);

	StreamIndex = 0;
}

void ACpp_LayoutModifier::RandomizeColors()
{
	for (AActor* actor : LayoutActors)
	{
		if (ACpp_ColorChanger* ColorChanger = Cast<ACpp_ColorChanger>(actor))
		{
			int RandomIndex = FMath::RandRange(0, ColorChanger->ColorDataArray.Num() - 1);
			UMaterialInterface* CurrentMaterialInterface = ColorChanger->ColorDataArray[RandomIndex].Material;
			ColorChanger->ApplyColor(CurrentMaterialInterface);
		}
	}
}

void ACpp_LayoutModifier::RandomizeLayout()
{
	if (StreamIndex < StreamLevels.Num())
	{
		FLatentActionInfo LatentInfo;
		LatentInfo.CallbackTarget = this;
		LatentInfo.ExecutionFunction = FName("OnLevelUnloaded");
		LatentInfo.UUID = StreamIndex;
		LatentInfo.Linkage = 0;

		UGameplayStatics::UnloadStreamLevel(GetWorld(), StreamLevels[StreamIndex]->GetFName(), LatentInfo, false);
		StreamIndex++;
	}
	else
	{
		StreamIndex = 0;
		int RandomIndex = FMath::RandRange(0, StreamLevels.Num() - 1);

		FLatentActionInfo LatentInfo;
		LatentInfo.CallbackTarget = this;
		LatentInfo.ExecutionFunction = FName("OnLevelLoaded");
		LatentInfo.Linkage = 0;
		LatentInfo.UUID = RandomIndex;

		UGameplayStatics::LoadStreamLevel(GetWorld(), StreamLevels[RandomIndex]->GetFName(), true, false, LatentInfo);
		CurrentStreamWorld = StreamLevels[RandomIndex];
	}
}

void ACpp_LayoutModifier::OnLevelUnloaded()
{
	RandomizeLayout();
}

void ACpp_LayoutModifier::OnLevelLoaded()
{
	TArray<AActor*> StreamActors;
	UGameplayStatics::GetAllActorsOfClass(CurrentStreamWorld, AActor::StaticClass(), StreamActors);

	for (AActor* a : StreamActors)
	{
		int x = FMath::RandRange(0, 10);
		bool Hide = x < 3;
		a->SetActorHiddenInGame(Hide);
	}
}

// Called when the game starts or when spawned
void ACpp_LayoutModifier::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACpp_LayoutModifier::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

