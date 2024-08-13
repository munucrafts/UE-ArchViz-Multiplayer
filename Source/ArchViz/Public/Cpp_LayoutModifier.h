// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cpp_POV.h"
#include "Components/WidgetComponent.h"
#include "Cpp_ColorChanger.h"
#include "Kismet/GameplayStatics.h"
#include "Cpp_LayoutModifier.generated.h"


UCLASS()
class ARCHVIZ_API ACpp_LayoutModifier : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACpp_LayoutModifier();

	UPROPERTY(EditDefaultsOnly)
	USceneComponent* Root;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UWidgetComponent* LayoutWidgetComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ACpp_POV* PovActor;

	UPROPERTY(EditAnywhere)
	TArray<AActor*> LayoutActors;

	UPROPERTY(EditAnywhere)
	TArray<UWorld*> StreamLevels;

	UPROPERTY()
	int StreamIndex;

	UPROPERTY()
	UWorld* CurrentStreamWorld;

public:
	UFUNCTION(BlueprintCallable)
	void RandomizeColors();

	UFUNCTION(BlueprintCallable)
	void RandomizeLayout();

protected:
	UFUNCTION()
	void OnLevelUnloaded();

	UFUNCTION()
	void OnLevelLoaded();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
