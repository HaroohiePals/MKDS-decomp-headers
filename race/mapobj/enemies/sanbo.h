#pragma once
#include "sinThing.h"
#include "race/pathwalker.h"
#include "race/mapobj/mapobj.h"

typedef enum
{
    SANBO_STATE_IDLE,
    SANBO_STATE_1,
    SANBO_STATE_DIEING,
    SANBO_STATE_RESURRECTING
} SanboState;

typedef struct
{
    VecFx32 dieingPosition;
    VecFx32 dieingVelocity;
    fx32 scaleXY;
    sinthing_t rotZSinThing;
    int rotZ;
    int rotZSpeed;
    int wiggleWaitCounter;
} sanbo_part_t;

typedef struct
{
    mobj_inst_t mobj;
    int pwWaitCounter;
    int hitTimeout;
    int resurrectionWaitCounter;
    int sfxTimeout;
    sanbo_part_t bodyParts[4];
    u16 bodyPartCount;
    fx32 pwSpeed;
    pw_pathwalker_t pathwalker;
    SanboState state;
} sanbo_t;

extern mobj_def_t gSanboMObjDef;