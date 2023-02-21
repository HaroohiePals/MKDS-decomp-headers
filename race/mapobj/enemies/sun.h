#pragma once
#include "race/pathwalker.h"
#include "race/mapobj/mapobj.h"

typedef enum
{
    SUN_STATE_SLEEP,
    SUN_STATE_MOVE,
    SUN_STATE_WAIT,
    SUN_STATE_SPAWN_SNAKE,
    SUN_STATE_SWIRL
} SunState;

typedef struct
{
    mobj_inst_t mobj;
    u32 fireSnakeSpawnCount;
    u16 fireSnakeSpawnRotY;
    s32 waitCounter;
    u32 rotZA;
    u16 rotZB;
    u16 nsbcaFrame;
    fx32 nsbcaAnimSpeed;
    pw_pathwalker_t pathwalker;
    SunState state;
} sun_t;

extern mobj_def_t gSunMObjDef;