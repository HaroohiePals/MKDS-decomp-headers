#pragma once
#include "race/mapobj/mapobj.h"
#include "race/objectShadow.h"

typedef enum
{
    WBOX_STATE_IDLE,
    WBOX_STATE_DEAD,
    WBOX_STATE_REAPPEAR_BEGIN,
    WBOX_STATE_REAPPEAR_END,

    WBOX_STATE_COUNT
} WoodBoxState;

typedef struct
{
    mobj_inst_t mobj;
    VecFx32 fieldA0;
    u16 fieldAC;
    VecFx32 fieldB0;
    VecFx32 floorNormal;
    u16 rotY;
    VecFx32 fieldCC;
    VecFx32 fieldD8;
    VecFx32 fieldE4;
    u16 fieldF0;
    VecFx32 fieldF4;
    VecFx32 field100;
    u16 field10C;
    u16 field10E;
    u16 field110;
    objshadow_t shadow;
} wbox_t;

extern const mobj_def_t gWoodboxMObjDef;