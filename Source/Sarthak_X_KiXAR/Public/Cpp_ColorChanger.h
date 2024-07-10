// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/WidgetComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/SphereComponent.h"
#include "Cpp_POV.h"
#include "Cpp_ColorChanger.generated.h"


USTRUCT(BlueprintType)
struct FColorData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ColorName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterialInterface* Material;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor Color;
};

UCLASS()
class SARTHAK_X_KIXAR_API ACpp_ColorChanger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACpp_ColorChanger();

	UPROPERTY(EditDefaultsOnly)
	USceneComponent* Root;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ACpp_POV* PovActor;

	UPROPERTY(EditAnywhere)
	TArray<AActor*> ColorActors;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UWidgetComponent* ColorWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FColorData> ColorDataArray;

	UPROPERTY(EditAnywhere)
	bool AutoInitLocation;

public:
	UFUNCTION()
	void InitLocation();

	UFUNCTION(BlueprintCallable)
	void ApplyColor(UMaterialInterface* CurrentMaterial);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
