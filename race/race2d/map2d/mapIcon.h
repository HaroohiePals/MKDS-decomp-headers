#pragma once
#include "race/mapobj/mapobjInstance.h"
#include "oam.h"

#define MPICN_GROUP_COUNT       49

typedef struct
{
    s32 x;
    s32 y;
} vec2i_t;

typedef struct
{
    vec2i_t position;
    const NNSG2dCellData* cell;
    u16 priority;
    u16 flipX;
    u16 rotation;
    u16 field12;
} mpicn_mobj_icon_cell_t;

typedef struct
{
    mobj_inst_t** mobjInstanceList;
    u32 cellCount;
    s32 mobjInstanceCount;
    vec2i_t* points;
    mpicn_mobj_icon_cell_t* cells;
} mpicn_mobj_icon_group_t;

typedef BOOL (*mpicn_create_func_t)();
typedef void (*mpicn_destroy_func_t)();
typedef void (*mpicn_update_func_t)();
typedef void (*mpicn_render_func_t)(oam_buf_t* oamBuf);

typedef struct
{
    mpicn_create_func_t createFunc;
    mpicn_destroy_func_t destroyFunc;
    mpicn_update_func_t updateFunc;
    mpicn_render_func_t renderFunc;
} mpicn_def_t;

typedef struct
{
    u16 minPriority;
    u32 field4;
    u32 field8;
    u32 groupCount;
    mpicn_destroy_func_t destroyFuncs[MPICN_GROUP_COUNT];
    mpicn_update_func_t updateFuncs[MPICN_GROUP_COUNT];
    mpicn_render_func_t renderFuncs[MPICN_GROUP_COUNT];
} mpicn_icon_data_t;

BOOL mpicn_createMapObjIcon(mpicn_mobj_icon_group_t** icon, MObjId objectId);
void mpicn_destroyMObjIcon(mpicn_mobj_icon_group_t** icon);
void mpicn_renderMObjIcon(oam_buf_t* oamBuf, mpicn_mobj_icon_group_t* icon, BOOL a3);
