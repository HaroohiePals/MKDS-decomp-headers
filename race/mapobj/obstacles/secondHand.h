#pragma once
#include "race/pathwalker.h"
#include "race/collision/dynamicCollision.h"

typedef enum
{
    SECONDHAND_STATE_ACCELERATE,
    SECONDHAND_STATE_MOVE,
    SECONDHAND_STATE_DECELERATE,
    SECONDHAND_STATE_WAIT
} SecondHandState;

typedef struct
{
    mobj_inst_t mobj;
    quaternion_t curRotation;
    quaternion_t baseRotation;
    u16 startStopFrameCount;
    u16 oneDirFrameCount;
    u16 waitFrameCount;
    s16 baseVelocity;
    fx32 velocity;
    fx32 acceleration;
} secondhand_t;

extern const mobj_def_t gSecondHandMObjDef;