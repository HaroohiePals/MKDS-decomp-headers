#pragma once

#include "race/mapobj/mapobj.h"

typedef enum
{
    NSK2_STATE_0,
    NSK2_STATE_1
} NsKiller2State;

typedef struct
{
    mobj_inst_t mobj;
    s32 counter;
    NsKiller2State state;
    sfx_emitter_ex_params_t* sfxEmitterExParams;
} nsk2_t;

extern const mobj_def_t gNsKiller2MObjDef;

void nsk2_spawn(const VecFx32* position, const VecFx32* direction, u16 rotY);