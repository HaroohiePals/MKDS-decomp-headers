#pragma once
#include "race/mapobj/mapobj.h"

typedef struct
{
    mobj_inst_t mobj;
    u16 index;
    u16 ccDependentSetting;
} fwdst_t;

extern const mobj_def_t gFallsWaterDstMObjDef;

const VecFx32* fwdst_getPosition(u16 index);
u16 fwdst_getCCDependentSetting(u16 index);
