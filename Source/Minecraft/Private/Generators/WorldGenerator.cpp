#include "Generators/WorldGenerator.h"
#include "Generators/Chunk.h"
#include "Engine/World.h"
#include "Engine/Engine.h"

// Sets default values
AWorldGenerator::AWorldGenerator() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ChunkSize = 16; // Size of each chunk
	BlockSize = 50.f; // Size of each blocks
}

// Called when the game starts or when spawned
void AWorldGenerator::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void AWorldGenerator::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void AWorldGenerator::GenerateWorld(int32 WorldSize) {
	for (int32 ChunkX = 0; ChunkX < WorldSize; ChunkX++) {
		for (int32 ChunkY = 0; ChunkY < WorldSize; ChunkY++) {

			float GetNewX = ChunkX * ChunkSize * BlockSize;
			float GetNewY = ChunkY * ChunkSize * BlockSize;

			FVector ChunkLocation = FVector(GetNewX, GetNewY, 0.f);

			SpawnChunk(ChunkX, ChunkY, ChunkLocation);
		}
	}
}

void AWorldGenerator::SpawnChunk(int32 ChunkX, int32 ChunkY, const FVector& Location) {
	FActorSpawnParameters SpawnParams;
	AChunk* NewChunk = GetWorld()->SpawnActor<AChunk>(Location, FRotator::ZeroRotator, SpawnParams);
	if (NewChunk) {
		NewChunk->GenerateChunk(ChunkX, ChunkY);
	}
}
