#pragma once
#include "mapobj.h"

typedef struct
{
    mobj_inst_t mobj;
    fx32 dieMinY;
    fx32 dieYAccel;
    BOOL dieRotZDir;
    u16 dieRotZ;
    u16 dieRotZSpeed;
    fx32 dieInitialYVelo;
    fx32 fieldB4;
} rotdiemobj_t;
