#pragma once
#include "race/objectShadow.h"
#include "race/pathwalker.h"
#include "race/mapobj/mapobj.h"

typedef enum
{
    MTREE_STATE_WAIT,
    MTREE_STATE_WALK
} MTreeState;

typedef struct
{
    mobj_inst_t mobj;
    s32 pointDuration;
    s32 counter;
    fx32 speed;
    u16 nsbcaFrame;
    s32 nsbcaFrameDelta;
    pw_pathwalker_t pathwalker;
    MTreeState state;
    objshadow_t shadow;
} movetree_t;

extern mobj_def_t gMoveTreeMObjDef;