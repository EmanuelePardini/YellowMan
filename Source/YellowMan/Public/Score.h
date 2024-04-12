// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "Score.generated.h"

UCLASS()
class YELLOWMAN_API AScore : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AScore();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USphereComponent* Sphere;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Value = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int InvulnerabilityDelayAdd = 5.f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
};
