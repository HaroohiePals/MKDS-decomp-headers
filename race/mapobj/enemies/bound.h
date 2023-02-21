#pragma once
#include "race/pathwalker.h"
#include "sinThing.h"

typedef enum
{
    BOUND_STATE_IDLE,
    BOUND_STATE_BOUNCING
} BoundState;

typedef struct
{
    mobj_inst_t mobj;
    u16 nsbtpFrame;
    u32 fieldA4;
    u32 fieldA8;
    u32 fieldAC;
    u32 fieldB0;
    u32 width;
    sinthing_t scaleXZSinThing;
    sinthing_t scaleYSinThing;
    pw_pathwalker_t pathwalker;
    BoundState state;
    u32 driverHitTimeouts[RACE_DRIVER_COUNT_MAX];
} bound_t;

extern mobj_def_t gBoundMObjDef;
extern mobj_def_t gCreamMObjDef;
extern mobj_def_t gBerryMObjDef;

BOOL bnd_handleBallHit(int index);