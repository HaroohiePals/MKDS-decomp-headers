#pragma once
#include "race/mapobj/mapobj.h"
#include "race/objectShadow.h"
#include "race/pathwalker.h"

typedef enum
{
    IBALL_STATE_0,
    IBALL_STATE_1,
    IBALL_STATE_2
} IballState;

typedef struct
{
    mobj_inst_t mobj;
    int rotZ;
    int fieldA4;
    int fieldA8;
    int fieldAC;
    int fieldB0;
    int fieldB4;
    int fieldB8;
    int elevation;
    fx32 fieldC0;
    pw_pathwalker_t pathwalker;
    objshadow_t shadow;
    VecFx32 routePos;
    int clipAreaMask;
    int field12C;
    IballState state;
} iball_t;

extern mobj_def_t gIronBallMObjDef;
extern mobj_def_t gIronBallNoColMObjDef;
