#pragma once

#include "race/mapobj/mapobj.h"
#include "race/pathwalker.h"
#include "math/quaternion.h"

typedef enum
{
    BASABASA_STATE_0,
    BASABASA_STATE_1,
    BASABASA_STATE_2,
    BASABASA_STATE_3
} BasabasaState;

typedef struct
{
    mobj_inst_t mobj;
    VecFx32 velocity;
    u16 nsbtpFrame;
    s32 initialCounter;
    s32 state0Counter;
    s32 state2Counter;
    BOOL emitSound;
    u16 mapIconType;
    idk_struct_t rotZ;
    u8 driverHitMask;
    BasabasaState state;
} basabasa_t;

extern mobj_def_t gBasabasaMObjDef;

void basa_spawn(u32 state2Start, const VecFx32* position, const VecFx32* velocity, u32 state0Start, BOOL emitSound,
                u16 mapIconType);
