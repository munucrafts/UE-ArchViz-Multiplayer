// Fill out your copyright notice in the Description page of Project Settings.


#include "Cpp_CarSpawner.h"

// Sets default values
ACpp_CarSpawner::ACpp_CarSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	Spline = CreateDefaultSubobject<USplineComponent>(TEXT("Spline"));
	Spline->SetupAttachment(RootComponent);

	Speed = 100;
	CarCount = 10;
	Inverse = false;

	MakeStraigntSpline();

}

void ACpp_CarSpawner::SpawnCarsAlongSpline()
{
	float SplineLength = Spline->GetSplineLength();
	float Interval = SplineLength / CarCount;
	Distances.SetNum(CarCount);

	for (int i = 0; i < CarCount; i++)
	{
		float Distance = Interval * i;
		Distances[i] = Distance;

		FVector Position = Spline->GetLocationAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
		FRotator Rotation = Spline->GetRotationAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);

		AStaticMeshActor* Car = GetWorld()->SpawnActor<AStaticMeshActor>(AStaticMeshActor::StaticClass(), Position, Rotation);
		int RandInt = FMath::RandRange(0, MeshCollectionArray.Num() - 1);
		Car->GetComponentByClass<UStaticMeshComponent>()->SetStaticMesh(MeshCollectionArray[RandInt]);
		Car->SetMobility(EComponentMobility::Movable);
		CarsArray.Add(Car);
	}
}

void ACpp_CarSpawner::MoveAllCars(float DeltaTime)
{
	if (!Inverse)
	{
		for (int i = 0; i < CarsArray.Num(); i++)
		{
			Distances[i] = Distances[i] + DeltaTime * Speed;
			float SplineLength = Spline->GetSplineLength();

			if (Distances[i] > SplineLength)
				Distances[i] = 0;

			FVector NewPosition = Spline->GetLocationAtDistanceAlongSpline(Distances[i], ESplineCoordinateSpace::World);
			FRotator NewRotation = Spline->GetRotationAtDistanceAlongSpline(Distances[i], ESplineCoordinateSpace::World);
			
			CarsArray[i]->SetActorLocation(NewPosition);
			CarsArray[i]->SetActorRotation(NewRotation);
		}
	}
	else
	{
		for (int i = 0; i < CarsArray.Num(); i++)
		{
			Distances[i] = Distances[i] - DeltaTime * Speed;
			float SplineLength = Spline->GetSplineLength();

			if (Distances[i] < 0)
				Distances[i] = SplineLength;

			FVector NewPosition = Spline->GetLocationAtDistanceAlongSpline(Distances[i], ESplineCoordinateSpace::World);
			FRotator NewRotation = Spline->GetRotationAtDistanceAlongSpline(Distances[i], ESplineCoordinateSpace::World);
			NewRotation.Yaw += 180;

			CarsArray[i]->SetActorLocation(NewPosition);
			CarsArray[i]->SetActorRotation(NewRotation);
		}
	}
}

void ACpp_CarSpawner::MakeStraigntSpline()
{
	for (int i = 0; i < Spline->GetNumberOfSplinePoints(); i++)
	{
		Spline->SetSplinePointType(i, ESplinePointType::Linear, true);
	}
}

// Called when the game starts or when spawned
void ACpp_CarSpawner::BeginPlay()
{
	Super::BeginPlay();

	SpawnCarsAlongSpline();
}

// Called every frame
void ACpp_CarSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(CarCount == CarsArray.Num())
		MoveAllCars(DeltaTime);
}

