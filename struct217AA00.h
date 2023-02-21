#pragma once

#include "race/raceConfig.h"

typedef struct
{
    u16 nickName[10];
    u8 emblem[512];
    u8 hasEmblem;
    u16 field216;
    DWCAccFriendData exchangeToken;
    u8 unlockBits[4];
    u8 field228 : 4;
    u8 : 4;
    u8 field229;
    u8 field22A;
    u8 field22B;
} struct_217AA00_field45C_t;

typedef struct
{
    u8 unk0[6];
    u16 field6;
} struct_217AA00_field1E4C_entry_t;

typedef struct
{
    u16 field0;
    u16 tp;
    u8 gap4[2];
    u8 flags : 7;
    u8 mic : 1;
    u8 field7;
} struc_252;

typedef struct
{
    u32 field0;
    u32 field4;
    u32 field8;
    u8 unkC[0x426];
    u16 field432;
    u16 field434;
    u16 field436;
    u8 field438;
    u8 field439;
    u8 field43A;
    u8 field43B;
    u8 field43C;
    u8 unk43D[0x454 - 0x43D];
    u16 field454;
    u8 field456;
    u8 field457;
    u8 field458;
    u8 unk459[0x45c - 0x459];
    struct_217AA00_field45C_t field45C[RACE_DRIVER_COUNT_MAX];
    u8 unk15BC[0x15C8 - 0x15BC];
    struc_252* field15C8;
    u8 unk15CC[0x15F6 - 0x15CC];
    u8 field15F6;
    u8 unk15F7[0x1E4C - 0x15F7];
    struct_217AA00_field1E4C_entry_t field1E4C[RACE_DRIVER_COUNT_MAX];
    u16 field1E8C[RACE_DRIVER_COUNT_MAX];
    u8 unk1E9C[0x1EB0 - 0x1E9C];
    u32 field1EB0;
    u8 unk1EB4[0x1EE8 - 0x1EB4];
    MATHRandContext32 field1EE8;
} struct_217AA00_t;

extern struct_217AA00_t* gStruct217AA00;

static inline u32 struct217AA00_getField0(void)
{
    return !gStruct217AA00 ? 0 : gStruct217AA00->field0;
}

static inline BOOL struct217AA00Inline(void)
{
    BOOL result;
    u32 field0;
    result = FALSE;
    if (!gStruct217AA00)
        result = field0 = FALSE;
    else
        field0 = gStruct217AA00->field0;
    if (field0 && gStruct217AA00->field4 != 13)
        result = TRUE;
    return result;
}