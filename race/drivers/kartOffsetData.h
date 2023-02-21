#pragma once

typedef struct
{
    char tireName[16];
    fx32 frontTireScale;
    VecFx32 tirePositions[4]; ///<left-right, front-back order
    VecFx32 characterPositions[13];
} kofs_entry_t;

SDK_COMPILER_ASSERT(sizeof(kofs_entry_t) == 0xE0);

typedef struct
{
    kofs_entry_t entries[0];
} kofs_t;
