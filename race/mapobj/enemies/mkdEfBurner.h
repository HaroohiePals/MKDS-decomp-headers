#pragma once
#include "race/pathwalker.h"
#include "race/raceConfig.h"
#include "race/mapobj/mapobj.h"

typedef enum
{
    EFBNR_STATE_WAIT,
    EFBNR_STATE_BURN_START,
    EFBNR_STATE_BURN,
    EFBNR_STATE_BURN_STOP,
    EFBNR_STATE_BURN_CONTINUOUS
} EfbnrState;

typedef struct
{
    mobj_inst_t mobj;
    s32 counter;
    u16 nsbtaFrame;
    fx32 scale;
    EfbnrState state;
    pw_pathwalker_t pathwalker;
    s32 driverHitTimeouts[RACE_DRIVER_COUNT_MAX];
} efbnr_t;

extern mobj_def_t gMkdEfBurnerMObjDef;

u16 efbnr_getMapIconType(efbnr_t* instance);