#pragma once

typedef enum
{
    DRAM_STATE_WAIT,
    DRAM_STATE_SPIN_END,
    DRAM_STATE_SPIN_START,
    DRAM_STATE_SPINNING,
    DRAM_STATE_SPIN_STOP,
    DRAM_STATE_ALIGN
} DramState;

typedef struct
{
    mobj_inst_t mobj;
    u16 startStopFrameCount;
    u16 spinFrameCount;
    u16 waitFrameCount;
    u16 angle;
    s16 angularSpeed;
    fx32 currentSpeed;
    fx32 startStopSpeed;
    s16 speeds[3];
    s32 alignRemainder;
} dram_t;

extern const mobj_def_t gDramMObjDef;