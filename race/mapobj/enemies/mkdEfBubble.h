#pragma once

#include "jnlib/spa/spaEmitter.h"
#include "race/objectShadow.h"
#include "race/mapobj/mapobj.h"

typedef enum
{
    EFBUB_STATE_JUMP,
    EFBUB_STATE_WAIT,

    EFBUB_STATE_COUNT
} EfbubState;

typedef struct
{
    mobj_inst_t mobj;
    int waitTime;
    fx32 lowYPos;
    u16 rotation;
    fx32 highYPos;
    objshadow_t shadow;
    u8 driverHitMask;
    spa_emitter_t* emitter69;
    spa_emitter_t* emitter70;
    BOOL emitterFail;
} efbub_t;

typedef struct
{
    mobj_logic_part_t logicPart;
    u32 field28;
} efbub_logic_part_t;

extern const mobj_def_t gMkdEfBubbleMObjDef;
