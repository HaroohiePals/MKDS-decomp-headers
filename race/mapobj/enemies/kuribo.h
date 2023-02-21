#pragma once

#include "race/mapobj/mapobj.h"
#include "race/pathwalker.h"
#include "math/quaternion.h"

typedef enum
{
    KURIBO_STATE_ROUTE_IDLE,
    KURIBO_STATE_GROUND_ROAM,
    KURIBO_STATE_HIT_GROW,
    KURIBO_STATE_HIT_SHRINK,
    KURIBO_STATE_DEAD,
    KURIBO_STATE_REAPPEAR
} KuriboState;

typedef struct
{
    mobj_inst_t mobj;
    fx32 fieldA0;
    quaternion_t direction;
    quaternion_t targetDir;
    fx32 squashRatio;
    fx32 squashVelocity;
    pw_pathwalker_t pathWalker;
    u16 frame;
    BOOL fieldF4;
    u16 dirInterpRatio;
    BOOL reappearAfterHit;
    u16 alpha;
    s16 field102;
    u32 field104;
} kuribo_t;

extern const mobj_def_t gKuriboMObjDef;

void kuribo_resetRoaming(kuribo_t* instance);
