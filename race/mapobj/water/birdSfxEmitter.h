#pragma once
#include "race/mapobj/mapobj.h"

typedef struct
{
    mobj_inst_t mobj;
    int sfxAMaxVolume;
    int volume;
    int fieldA8;
    VecFx32 position;
    int fieldB8;
    u16 sfxIdA;
    u16 sfxIdB;
    int stateUpdateCounter;
    int state;
    int sfxACounter;
} bsfx_t;

extern mobj_def_t gBirdSfxEmitterMObjDef;

int bsfx_getVolume();
