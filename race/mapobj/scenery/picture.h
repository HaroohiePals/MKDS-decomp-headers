#pragma once
#include "race/mapobj/mapobj.h"

typedef enum
{
    PICT_TYPE_1,
    PICT_TYPE_2,
} PictType;

typedef enum
{
    PICT_STATE_IDLE,
    PICT_STATE_WAIT,
    PICT_STATE_MOVE
} PictState;

typedef struct
{
    mobj_inst_t mobj;
    u16 nsbcaFrame;
    PictType pictureType;
    s32 counter;
    PictState state;
} picture_t;

extern mobj_def_t gPicture1MObjDef;
extern mobj_def_t gPicture2MObjDef;
