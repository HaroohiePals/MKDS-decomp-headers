#pragma once

extern u32 gSpaRng;

void spa_getRandomDirection(VecFx32* dst);
void spa_getRandomXYDirection(VecFx32* dst);

static inline u32 spa_getNextRandom()
{
    gSpaRng = 1592653589 * gSpaRng + 453816691;
    return gSpaRng;
}
