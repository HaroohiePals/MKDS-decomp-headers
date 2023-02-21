#pragma once
#include "race/mapobj/mapobj.h"

typedef enum
{
    CHND_STATE_WAIT,
    CHND_STATE_MOVE,
} ChandelierState;

typedef struct
{
    mobj_inst_t mobj;
    u16 nsbcaFrame;
    s32 counter;
    ChandelierState state;
} chandelier_t;

extern mobj_def_t gChandelierMObjDef;
