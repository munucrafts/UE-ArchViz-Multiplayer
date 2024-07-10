// Fill out your copyright notice in the Description page of Project Settings.


#include "Cpp_ColorChanger.h"

// Sets default values
ACpp_ColorChanger::ACpp_ColorChanger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	ColorWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("ColorWidget"));
	ColorWidget->SetupAttachment(RootComponent);
	ColorWidget->SetWidgetSpace(EWidgetSpace::Screen);
	ColorWidget->SetDrawAtDesiredSize(true);
	ColorWidget->SetHiddenInGame(true);
	
	AutoInitLocation = true;

	InitLocation();
}

void ACpp_ColorChanger::InitLocation()
{
	if (ColorActors.Num() > 0)
	{
		if (AutoInitLocation)
		{
			FVector Location;
			FVector Extent;
			float Radius;
			UKismetSystemLibrary::GetComponentBounds(ColorActors[0]->GetRootComponent(), Location, Extent, Radius);
			this->SetActorLocation(Location);
		}
	}
}

void ACpp_ColorChanger::ApplyColor(UMaterialInterface* CurrentMaterial)
{
	if (ColorActors.Num() > 0)
	{
		for(int k = 0; k < ColorActors.Num(); k++)
		{
			AActor* ColorActor = ColorActors[k];
			UMeshComponent* MeshComponent = ColorActor->GetComponentByClass<UMeshComponent>();

			for (int i = 0; i < MeshComponent->GetNumMaterials(); i++)
			{
				MeshComponent->SetMaterial(i, CurrentMaterial);
			}
		}
	}
}

// Called when the game starts or when spawned
void ACpp_ColorChanger::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACpp_ColorChanger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

