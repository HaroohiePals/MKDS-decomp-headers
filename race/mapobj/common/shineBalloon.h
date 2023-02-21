#pragma once
#include "race/mapobj/mapobj.h"
#include "race/drivers/driver.h"

typedef enum
{
    SBLLN_STATE_0,
    SBLLN_STATE_1,
    SBLLN_STATE_2,
    SBLLN_STATE_3
} ShineBalloonState;

typedef struct
{
    mobj_inst_t mobj;
    fx32 scale;
    fx32 scaleDelta;
    s32 counter;
    driver_t* driver;
    ShineBalloonState state;
} sblln_t;

extern mobj_def_t gShineBalloonMObjDef;

void sblln_spawn(driver_t* driver);