#pragma once
#include "collision.h"
#include "model.h"
#include "race/mapobj/mapobj.h"

typedef enum
{
    DCOL_SHAPE_BOX,
    DCOL_SHAPE_CYLINDER
} DColShape;

typedef struct dcol_inst_t
{
    mobj_inst_t mobj;
    MtxFx33 lastMtx;
    MtxFx33 baseMtx;
    VecFx32 lastPosition;
    VecFx32 basePos;
    VecFx32 size;
    fx32 sizeZ2;
    BOOL isFloorYZ;
    BOOL isFloorXZ;
    BOOL isFloorXY;
    BOOL isBoostPanel;
    fx32 floorThreshold;
    VecFx32 field124;
    u32 field130;
    DColShape shape;
    u32 field138;
    u32 field13C;
    model_t* model;
} dcol_inst_t;

typedef void (*dcol_render_func_t)(dcol_inst_t* instance, const MtxFx43* camMtx, u16 alpha);

void dcol_render(mobj_render_part_t* renderPart, const MtxFx43* camMtx, dcol_render_func_t renderFunc);
void dcol_commonRender(dcol_inst_t* instance, const MtxFx43* camMtx, u16 alpha);
void dcol_setModel(mobj_render_part_t* renderPart, model_t* model);

BOOL dcol_collide(dcol_inst_t* instance, const VecFx32* position, fx32 sphereSize, u16 collideFlags,
                  col_response_t* floorResponse, col_response_t* wallResponse, VecFx32* a7,
                  u16* collisionType, VecFx32* a9, u16* a10);
