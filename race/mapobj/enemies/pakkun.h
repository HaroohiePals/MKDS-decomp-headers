#pragma once
#include "race/mapobj/mapobj.h"
#include "race/pathwalker.h"

typedef enum
{
    PAKKUN_STATE_0,
    PAKKUN_STATE_1,
    PAKKUN_STATE_2,
    PAKKUN_STATE_3,
    PAKKUN_STATE_4,
    PAKKUN_STATE_5,
    PAKKUN_STATE_6
} PakkunState;

typedef struct
{
    mobj_inst_t mobj;
    u16 polygonId;
    int nsbcaFrame;
    int fieldA8;
    int fieldAC;
    int fieldB0;
    PakkunState state;
    pw_pathwalker_t pathwalkers[7];
    s32 counter;
    u16 curPath;
    u16 pathCount;
    int field1BC[7];
    int field1D8;
    int mouthRotY;
    int mouthRotX;
    int field1E4;
    int field1E8;
    int field1EC;
    int scale;
    int scaleVelocity;
    int headElevation;
    int fireballElevation;
} pakkun_t;

extern mobj_def_t gPakkunMObjDef;
