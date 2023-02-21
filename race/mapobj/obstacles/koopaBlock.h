#pragma once
#include "race/pathwalker.h"
#include "race/collision/dynamicCollision.h"
#include "race/mapobj/mapobjIds.h"

typedef enum
{
    KOOPABLOCK_STATE_SPEEDUP,
    KOOPABLOCK_STATE_MOVE,
    KOOPABLOCK_STATE_SLOWDOWN
} KoopaBlockState;

typedef struct
{
    dcol_inst_t dcolMObj;
    pw_pathwalker_t pathWalker;
    fx32 speed;
    u16 waitCounter;
} koopablock_t;

extern const mobj_def_t gKoopaBlockMObjDef;

void kblock_renderAll(const MtxFx43* camMtx);
BOOL kblock_isKoopaBlock(MObjId objectId);
fx32 kblock_getRouteProgress(koopablock_t* instance);