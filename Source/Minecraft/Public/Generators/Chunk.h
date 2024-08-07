// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Meshes/Voxel.h"
#include "Chunk.generated.h"

UCLASS() class MINECRAFT_API AChunk : public AActor {
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChunk();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void GenerateChunk(int32 ChunkX, int32 ChunkY, const FVector& ChunkLocation);

	UPROPERTY(EditAnywhere)
	int32 ChunkSize;

	UPROPERTY(EditAnywhere)
	int32 ChunkDepth;

	UPROPERTY(EditAnywhere)
	float BlockSize;

	FVector ChunkWorldLocation;

private:
	void SpawnVoxel(int32 X, int32 Y, int32 Z, EVoxelType VoxelType);
};
