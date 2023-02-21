#pragma once

typedef enum
{
    CSFX_FLOOR_MAT_ASPHALT,
    CSFX_FLOOR_MAT_CONCRETE,
    CSFX_FLOOR_MAT_EDGE,
    CSFX_FLOOR_MAT_DIRT,
    CSFX_FLOOR_MAT_STONE,
    CSFX_FLOOR_MAT_SAND,
    CSFX_FLOOR_MAT_ICE,
    CSFX_FLOOR_MAT_GRASS,
    CSFX_FLOOR_MAT_WATER,
    CSFX_FLOOR_MAT_SNOW,
    CSFX_FLOOR_MAT_BOARD,
    CSFX_FLOOR_MAT_CARPET,
    CSFX_FLOOR_MAT_KANAAMI, //metal gaze
    CSFX_FLOOR_MAT_PLASTIC,
    CSFX_FLOOR_MAT_TEPPAN, //iron plate
    CSFX_FLOOR_MAT_RAINBOW,
    CSFX_FLOOR_MAT_DORONUMA, //bog
    CSFX_FLOOR_MAT_KAIDAN, //stairs
    CSFX_FLOOR_MAT_18,

    CSFX_FLOOR_MAT_COUNT,
    CSFX_FLOOR_MAT_INVALID_19 = CSFX_FLOOR_MAT_COUNT,
    CSFX_FLOOR_MAT_NONE
} CSfxFloorMat;

typedef enum
{
    CSFX_WALL_MAT_CONCRETE,
    CSFX_WALL_MAT_FENCE,
    CSFX_WALL_MAT_WOOD,
    CSFX_WALL_MAT_TREE,
    CSFX_WALL_MAT_SHIGEMI, //brushwood
    CSFX_WALL_MAT_GAKE, //cliff?
    CSFX_WALL_MAT_KANBAN, //sign
    CSFX_WALL_MAT_ICEWALL,
    CSFX_WALL_MAT_SNOWROCK,
    CSFX_WALL_MAT_TABLE,
    CSFX_WALL_MAT_UKIWA, //swim ring?
    CSFX_WALL_MAT_JELLY,
    CSFX_WALL_MAT_KANAAMI, //metal gaze

    CSFX_WALL_MAT_COUNT,
    CSFX_WALL_MAT_NONE
} CSfxWallMat;

typedef enum
{
    CSFX_FLOOR_SFX_TYPE_RUN,
    CSFX_FLOOR_SFX_TYPE_SLIP,
    CSFX_FLOOR_SFX_TYPE_CHAKUCHI, //landing
    CSFX_FLOOR_SFX_TYPE_BRAKE,

    CSFX_FLOOR_SFX_TYPE_COUNT
} CSfxFloorSfxType;

typedef enum
{
    CSFX_WALL_SFX_TYPE_CRUSH,

    CSFX_WALL_SFX_TYPE_COUNT
} CSfxWallSfxType;

#define CSFX_BOARD_RUN      0xFFD0
#define CSFX_KAIDAN_RUN     0xFFD1

void csfx_init();
void csfx_setFloorOverride(int collisionType, int variant, const u32* sfxes);
void csfx_setWallOverride(int collisionType, int variant, const u32* sfxes);
u16 csfx_getFloorSfx(CSfxFloorSfxType sfxType, int collisionType, int variant);
u16 csfx_getWallSfx(CSfxWallSfxType sfxType, int collisionType, int variant);
