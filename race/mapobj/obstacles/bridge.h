#pragma once
#include "race/collision/dynamicCollision.h"
#include "race/mapobj/mapobjRenderPart.h"
#include "race/mapobj/mapobjIds.h"

typedef struct
{
    mobj_render_part_t renderPart;
    fx32 animLength;
} bridge_renderpart_t;

typedef struct 
{
    dcol_inst_t dcolMObj;
    u16 field144;
    u16 rotSpeed;
    u16 angle;
    u16 field14A;
    u16 field14C;
    u16 field14E;
    u16 waitCounter;
    fx32 animProgress;
} bridge_t;

extern const mobj_def_t gBridgeMObjDef;

void bridge_renderAll(const MtxFx43* camMtx);
int bridge_getProgress();
BOOL bridge_isBridge(MObjId objectId);