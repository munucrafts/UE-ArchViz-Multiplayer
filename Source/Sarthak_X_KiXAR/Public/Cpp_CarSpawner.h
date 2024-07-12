// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SplineComponent.h"
#include "Engine/StaticMeshActor.h"
#include "Kismet/KismetMathLibrary.h"
#include "Cpp_CarSpawner.generated.h"


UCLASS()
class SARTHAK_X_KIXAR_API ACpp_CarSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACpp_CarSpawner();

	UPROPERTY(EditDefaultsOnly)
	USceneComponent* Root;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USplineComponent* Spline;

	UPROPERTY(EditAnywhere)
	TArray<UStaticMesh*> MeshCollectionArray;

	UPROPERTY()
	TArray<AStaticMeshActor*> CarsArray;

	UPROPERTY(EditAnywhere)
	float Speed;

	UPROPERTY(EditAnywhere)
	float CarCount;

	UPROPERTY(EditAnywhere)
	bool Inverse;

	UPROPERTY()
	TArray<float> Distances;

protected:
	UFUNCTION(BlueprintCallable)
	void MakeStraigntSpline();

	UFUNCTION()
	void SpawnCarsAlongSpline();

	UFUNCTION()
	void MoveAllCars(float DeltaTime);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
