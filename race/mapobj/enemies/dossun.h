#pragma once

#include "race/mapobj/mapobj.h"
#include "race/pathwalker.h"

typedef enum
{
    DOSSUN_STATE_0,
    DOSSUN_STATE_1,
    DOSSUN_STATE_2,
    DOSSUN_STATE_3,
    DOSSUN_STATE_4,
    DOSSUN_STATE_5,
    DOSSUN_STATE_6
} DossunState;

typedef enum
{
    DOSSUN_STAR_HIT_ANIM_STATE_INACTIVE,
    DOSSUN_STAR_HIT_ANIM_STATE_1,
    DOSSUN_STAR_HIT_ANIM_STATE_2
} DossunStarHitAnimState;

typedef struct
{
    mobj_inst_t mobj;
    DossunState state;
    int stateCounter;
    fx32 someSpeed;
    fx32 floorY;
    BOOL isSmashing;
    DossunStarHitAnimState starHitAnimState;
    s16 rotYDelta;
    s16 rotY;
    u32 lastStarHitFrame;
    u16 noStarHitPlayerMask;
    u16 sinAng;
    fx32 sinAmplitude;
    pw_pathwalker_t pathwalker;
    u16 initialPathPoint;
    BOOL isHorizontalMoveType;
    VecFx32 fieldF4;
    fx32 field100;
    fx32 someAcceleration;
    fx32 anotherSpeed;
} dossun_t;

extern const mobj_def_t gDossunMObjDef;

fx32 dossun_getMapElevation(dossun_t* dossun);
