#include "Generators/WorldGenerator.h"
#include "Generators/Chunk.h"
#include "Engine/World.h"
#include "Engine/Engine.h"

// Sets default values
AWorldGenerator::AWorldGenerator() {
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
            FVector ChunkLocation(ChunkX * ChunkSize * BlockSize, ChunkY * ChunkSize * BlockSize, 0);
            SpawnChunk(ChunkX, ChunkY, ChunkLocation);
        }
    }
}

void AWorldGenerator::SpawnChunk(int32 ChunkX, int32 ChunkY, const FVector& Location) {
    FActorSpawnParameters SpawnParams;
    AChunk* NewChunk = GetWorld()->SpawnActor<AChunk>(Location, FRotator::ZeroRotator, SpawnParams);
    if (NewChunk) {
        NewChunk->GenerateChunk(ChunkX, ChunkY, Location);
    }
}
