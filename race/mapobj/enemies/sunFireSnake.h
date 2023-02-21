#pragma once
#include "jnlib/spa/spaEmitter.h"
#include "race/mapobj/mapobj.h"

typedef enum
{
    SFSN_STATE_0,
    SFSN_STATE_1,
    SFSN_STATE_2,
    SFSN_STATE_3
} SunFireSnakeState;

typedef struct
{
    mobj_inst_t mobj;
    u16 state1Counter;
    s32 state0Counter;
    VecFx32 spawnPos;
    u16 angle;
    SunFireSnakeState state;
    spa_emitter_t* ptclEmitterA;
    spa_emitter_t* ptclEmitterB;
} sfsn_t;

extern mobj_def_t gSunFireSnakeMObjDef;

void sfsn_spawn(const VecFx32* position, const VecFx32* direction);