#pragma once

typedef struct
{
    u16 triggeredKeys;
    u16 pressedKeys;
    u16 releasedKeys;
    u16 repeatedKeys;
    u16 repeatState;
    u16 repeatFrameCounter;
    u16 repeatMask;
    u16 repeatFirstFrame;
    u16 repeatNextFrame;
    u16 resetInvoked;
    u16 field14;

    OSTick resetStartTime;
    u32 field20;
    u32 field24;
} input_pad_t;

static inline u16 pad_isSetPadTrig(input_pad_t* shit, u16 mask)
{
    return shit->triggeredKeys & mask;
}

static inline u16 pad_isSetPadPress(input_pad_t* shit, u16 mask)
{
    return shit->pressedKeys & mask;
}

static inline u16 pad_isSetPadRep(input_pad_t* shit, u16 mask)
{
    return shit->repeatedKeys & mask;
}
