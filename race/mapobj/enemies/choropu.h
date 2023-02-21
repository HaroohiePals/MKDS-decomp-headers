#pragma once
#include "race/mapobj/mapobj.h"
#include "race/objectShadow.h"

typedef enum
{
    CHORO_STATE_0,
    CHORO_STATE_1,
    CHORO_STATE_2,
    CHORO_STATE_3,
    CHORO_STATE_4,
    CHORO_STATE_5,
    CHORO_STATE_6,
    CHORO_STATE_7
} ChoropuState;

typedef struct
{
    mobj_inst_t mobj;
    u32 setting1;
    u32 setting0;
    u32 fieldA8;
    int fieldAC;
    int fieldB0;
    BOOL fieldB4;
    u16 rotZ;
    objshadow_t shadow;
} choropu_t;

extern const mobj_def_t gChoropuMObjDef;
