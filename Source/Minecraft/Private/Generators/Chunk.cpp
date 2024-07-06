#include "Generators/Chunk.h"
#include "Meshes/Voxel.h"
#include "PerlinNoiseOverride.h"

// Sets default values
AChunk::AChunk()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ChunkSize = 16;
	BlockSize = 50.f;
}

// Called when the game starts or when spawned
void AChunk::BeginPlay(){
	Super::BeginPlay();
	
}

// Called every frame
void AChunk::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

void AChunk::GenerateChunk() {
	for (int32 X = 0; X < ChunkSize; X++) {
		for (int32 Y = 0; Y < ChunkSize; Y++) {
			float NoiseValue = PerlinNoiseOverride::Noise(X * 0.1f, Y * 0.1f, 0.0f); 
			int32 Height = FMath::FloorToInt(NoiseValue * (ChunkSize / 2));
			for (int32 Z = 0; Z < Height; Z++) {
				SpawnVoxel(X, Y, Z);
			}
		}
	}
}

void AChunk::SpawnVoxel(int32 X, int32 Y, int32 Z) {
	FVector Location(X * BlockSize / 2, Y * BlockSize / 2, Z * BlockSize / 2 );
	FActorSpawnParameters SpawnParams;
	GetWorld()->SpawnActor<AVoxel>(Location, FRotator::ZeroRotator, SpawnParams);

}

