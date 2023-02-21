#pragma once
#include "sinThing.h"
#include "race/mapobj/mapobj.h"

typedef enum
{
    TERESA_STATE_0,
    TERESA_STATE_1
} TeresaState;

typedef struct
{
    mobj_inst_t mobj;
    VecFx32 fieldA0;
    u16 alpha;
    u16 nsbtpFrame;
    u16 flip;
    s32 state1Counter;
    s32 fieldB8;
    sinthing_t fieldBC;
    sinthing_t fieldDC;
    idk_struct2_t fieldFC;
    u32 field10C;
    TeresaState state;
} teresa_t;

extern mobj_def_t gTeresaMObjDef;

void tesa_20946B8();
void tesa_spawn(const VecFx32* position);
int tesa_getActiveInstanceCount();