#pragma once
#include "race/mapobj/mapobj.h"

typedef struct
{
    VecFx32 position;
    u16 armRotZ;
    u16 ballRotZ;
} fireball2_fireball_t;

typedef struct
{
    mobj_inst_t mobj;
    u16 nrArms;
    u16 fireballsPerArm;
    u16 armAngleDistance;
    fx32 fireballDistance;
    fx32 radius;
    u16 rotSpeed;
    u16 rotation;
    fireball2_fireball_t centerFireball;
    fireball2_fireball_t fireballs[20][20];
    int driverHitTimeouts[RACE_DRIVER_COUNT_MAX];
    fx32 playerDistanceFromRing;
} fireball2_t;

extern mobj_def_t gFireball2MObjDef;