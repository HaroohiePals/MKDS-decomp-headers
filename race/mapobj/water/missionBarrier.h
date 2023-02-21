#pragma once
#include "race/mapobj/mapobj.h"
#include "race/collision/dynamicCollision.h"

typedef struct
{
    dcol_inst_t dcolMObj;
} mrbarrier_t;

extern const mobj_def_t gMissionBarrierMObjDef;

BOOL mrbar_isMissionBarrier(MObjId objectId);