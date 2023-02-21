#pragma once
#include "race/mapobj/mapobj.h"

typedef enum
{
    BALLOON_STATE_0,
    BALLOON_STATE_1,
    BALLOON_STATE_2
} BalloonState;

typedef struct balloon_t
{
    mobj_inst_t mobj;
    int fieldA0;
    int driverId;
    int color;
    u32 gapAC;
    VecFx32 fieldB0;
    VecFx32 fieldBC;
    int fieldC8;
    int fieldCC;
    int inflationProgress;
    int inflationDelta;
    int scale3;
    int scale3Delta;
    int fieldE0;
    int scale;
    VecFx32 fieldE8;
    int subBalloonCountPlusOne;
    struct balloon_t** subBalloons;
    BalloonState state;
} balloon_t;

extern mobj_def_t gBalloonMObjDef;
