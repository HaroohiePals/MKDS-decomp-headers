#pragma once
#include "jnlib/spa/spaEmitter.h"
#include "race/mapobj/mapobj.h"
#include "race/pathwalker.h"

typedef enum
{
    PAKKUN_FIRE_STATE_0,
    PAKKUN_FIRE_STATE_1
} PakkunFireState;

typedef struct
{
    mobj_inst_t mobj;
    pw_pathwalker_t pathwalker;
    fx32 elevation;
    fx32 elevationVelocity;
    PakkunFireState state;
    spa_emitter_t* emitter;
} pakkunfire_t;

void pknf_spawn(pw_pathwalker_t* pathwalker, fx32 elevation);

extern mobj_def_t gPakkunFireMObjDef;