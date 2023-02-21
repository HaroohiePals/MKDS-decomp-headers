#pragma once

#include "race/objectShadow.h"
#include "race/mapobj/mapobj.h"
#include "race/mapobj/rotDieMObj.h"

typedef enum
{
    PUKU_STATE_0,
    PUKU_STATE_1,
    PUKU_STATE_2,
    PUKU_STATE_3,

    PUKU_STATE_COUNT
} PukupukuState;

typedef struct
{
    rotdiemobj_t rdmobj;
    VecFx32 fieldB8;
    u16 fieldC4;
    objshadow_t shadow;
    u32 fieldFC;
    fx32 field100;
    fx32 field104;
    fx32 field108;
} pukupuku_t;

extern const mobj_def_t gPukupukuMObjDef;
