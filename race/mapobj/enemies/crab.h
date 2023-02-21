#pragma once
#include "sinThing.h"
#include "race/pathwalker.h"
#include "race/mapobj/mapobjInstance.h"

typedef enum
{
    CRAB_STATE_0,
    CRAB_STATE_1,
    CRAB_STATE_2,
    CRAB_STATE_3
} CrabState;

typedef struct
{
    mobj_inst_t mobj;
    u16 fieldA0;
    u16 rotZ;
    int counter;
    fx32 bodyNsbtpFrame;
    fx32 handNsbtpFrame;
    sinthing_t fieldB0;
    sinthing_t fieldD0;
    pw_pathwalker_t pathWalker;
    CrabState state;
} crab_t;

extern mobj_def_t gCrabMObjDef;