#pragma once
#include "mapobjInstance.h"

typedef enum
{
    MOBJ_RENDER_PART_TYPE_NONE = 0,
    MOBJ_RENDER_PART_TYPE_3D = 1,
    MOBJ_RENDER_PART_TYPE_2D = 2
} MObjRenderPartType;

typedef struct mobj_render_part_t mobj_render_part_t;

typedef void (*mobj_render_part_global_init_func_t)(mobj_render_part_t* renderPart);
typedef void (*mobj_render_part_global_pre_render_func_t)(mobj_render_part_t* renderPart);
typedef void (*mobj_render_part_instance_render_func_t)(
    mobj_render_part_t* renderPart, mobj_inst_t* instance, const MtxFx43* camMtx, u16 alpha);
typedef void (*mobj_render_part_global_post_render_func_t)(mobj_render_part_t* renderPart);

typedef struct mobj_render_part_t
{
    mobj_inst_t** mobjInstanceList;
    u16 mobjInstanceCount;
    mobj_render_part_global_init_func_t globalInitFunc;
    mobj_render_part_global_pre_render_func_t globalPreRenderFunc;
    mobj_render_part_instance_render_func_t instanceRenderFunc;
    mobj_render_part_global_post_render_func_t globalPostRenderFunc;
    MObjRenderPartType type;
    BOOL isTranslucent;
    BOOL isShadow;
    mobj_inst_t** alphaSortList;
    struct mobj_render_part_t** thisPointer;
} mobj_render_part_t;

void mobj_renderPartSetThisPointer(mobj_render_part_t** renderPart);
