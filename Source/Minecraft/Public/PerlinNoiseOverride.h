#pragma once

#include "CoreMinimal.h"

class MINECRAFT_API PerlinNoiseOverride {
public:
    static float Noise(float x, float y, float z);
private:
    static float Fade(float t);
    static float Lerp(float t, float a, float b);
    static float Grad(int hash, float x, float y, float z);
    static int Permutation[256];
    static int P[512]; // To avoid overflow
};
