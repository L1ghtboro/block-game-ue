#include "Generators/Chunk.h"
#include "PerlinNoiseOverride.h"
#include "Engine/World.h"
#include "Engine/Engine.h"

// Sets default values
AChunk::AChunk() {
	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ChunkSize = 16;
	BlockSize = 50.f;
	ChunkDepth = 32;
}

// Called when the game starts or when spawned
void AChunk::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void AChunk::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void AChunk::GenerateChunk(int32 ChunkX, int32 ChunkY, const FVector& ChunkLocation) {
    ChunkWorldLocation = ChunkLocation; // Set the chunk's world position

    for (int32 X = 0; X < ChunkSize; X++) {
        for (int32 Y = 0; Y < ChunkSize; Y++) {
            float WorldX = (ChunkX * ChunkSize + X) * 0.1f;
            float WorldY = (ChunkY * ChunkSize + Y) * 0.1f;
            float NoiseValue = PerlinNoiseOverride::Noise(WorldX, WorldY, 0.0f);
            int32 Height = FMath::FloorToInt(NoiseValue * (ChunkDepth/4));

            for (int32 Z = 0; Z < Height; Z++) {
                EVoxelType VoxelType = (Z < Height - FMath::RandRange(2, 4)) ? EVoxelType::Stone : EVoxelType::Dirt;
                if (Z == Height - 1) {
                    VoxelType = EVoxelType::Grass;
                }
                SpawnVoxel(X, Y, Z, VoxelType);
            }
        }
    }
}

void AChunk::SpawnVoxel(int32 X, int32 Y, int32 Z, EVoxelType VoxelType) {
    FVector Location = ChunkWorldLocation + FVector(X * BlockSize, Y * BlockSize, Z * BlockSize);
    FActorSpawnParameters SpawnParams;
    AVoxel* Voxel = GetWorld()->SpawnActor<AVoxel>(Location, FRotator::ZeroRotator, SpawnParams);
    if (Voxel) {
        Voxel->SetVoxelType(VoxelType);
    }
}
