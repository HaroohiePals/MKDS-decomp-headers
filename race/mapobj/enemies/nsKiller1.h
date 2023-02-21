#pragma once

#include "race/pathwalker.h"
#include "race/mapobj/mapobj.h"

typedef enum
{
    NSK1_STATE_WAIT,
    NSK1_STATE_MOVE,
    NSK1_STATE_SHOOT,
    NSK1_STATE_EMIT
} NsKiller1State;

typedef struct
{
    mobj_inst_t mobj;
    s32 counter;
    u8 unkA4[4];
    NsKiller1State state;
    pw_pathwalker_t pathwalker;
} nsk1_t;

extern mobj_def_t gNsKiller1MObjDef;