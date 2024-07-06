#include "Generators/Chunk.h"
#include "Meshes/Voxel.h"
#include "PerlinNoiseOverride.h"
#include "Engine/World.h"
#include "Engine/Engine.h"

// Sets default values
AChunk::AChunk() {
	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ChunkSize = 16;
	BlockSize = 50.f;
}

// Called when the game starts or when spawned
void AChunk::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void AChunk::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void AChunk::GenerateChunk(int32 ChunkX, int32 ChunkY) {
	for (int32 X = 0; X < ChunkSize; X++) {
		for (int32 Y = 0; Y < ChunkSize; Y++) {
			float WorldX = (ChunkX * ChunkSize + X) * 0.1f;
			float WorldY = (ChunkY * ChunkSize + Y) * 0.1f;
			float NoiseValue = PerlinNoiseOverride::Noise(WorldX, WorldY, 0.0f);
			int32 Height = FMath::FloorToInt(NoiseValue * (ChunkSize / 2));

			for (int32 Z = 0; Z < Height; Z++) {
				SpawnVoxel(ChunkX * ChunkSize + X, ChunkY * ChunkSize + Y, Z);
			}
		}
	}
}

void AChunk::SpawnVoxel(int32 X, int32 Y, int32 Z) {
	FVector Location(X * BlockSize, Y * BlockSize, Z * BlockSize);
	FActorSpawnParameters SpawnParams;
	AVoxel* Voxel = GetWorld()->SpawnActor<AVoxel>(Location, FRotator::ZeroRotator, SpawnParams);
}
