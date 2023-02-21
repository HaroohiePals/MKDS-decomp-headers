#pragma once
#include "race/mapobj/mapobj.h"

typedef struct
{
    mobj_inst_t mobj;
    BOOL hasSpawned;
    u32 fieldA4;
    int counter;
} shinc_t;

extern const mobj_def_t gShineControllerMObjDef;