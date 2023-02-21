#pragma once

#include "input/inputRecorder.h"
#include "saveCore.h"
#include "race/drivers/ghostData.h"

typedef struct
{
    u32 signature;
    u8 gap4[8];
    u16 nickname[10];
    u8 unlockBits[4];
    u16 field24;
    u8 personalGhostBits[4];
    u8 downloadGhostBits[4];
    u8 nkfeBits[2];
    u8 gap30;
    u8 field31;
    u8 gap32;
    u32 field34;
    u32 field38;
    u32 field3C;
    u32 field40;
    u32 field44;
    u32 field48;
    DWCAccUserData dwcUserData;
    u8 gap8C[0x100 - 0x8C];
} nksy_t;

typedef struct
{
    ghost_header_t header;
    u8 inputData[3532];
} nkpg_t;

typedef struct
{
    ghost_header_t header;
    u8 emblem[512];
    input_rec_recording_t inputData;
    u32 padding;
} nkdg_t;

typedef struct
{
    nksy_t* nksy;
    u8* nkem;
    u32 nkgp;
    u32 nkta;
    u32 nkmr;
    nkpg_t* nkpg;
    nkdg_t* nkdg;
    nkdg_t* staffGhost;
    u32 nkfl;
    u32 nkfe;
    u8 isBusy;
    u16 blockErrorFlags;
    u32 error;
    u8 field30[4];
    u8 field34[4];
    u8 field38;
    u8 field39;
    u8 unk3A[2];
    u8 field3C;
    u8 unk3D[3];
    u32 field40;
    u32 field44;
} save_data_t;

extern save_data_t* gSaveData;

nkdg_t* savd_loadStaffGhost(const char* path);

static inline BOOL savd_getNksyOffs31Bit0()
{
    if (((u32)(gSaveData->nksy->field31 << 31)) >> 31)
        return TRUE;
    else
        return FALSE;
}

static inline u32 savd_getNksyOffs31Bit1_2()
{
    return ((u32)(gSaveData->nksy->field31 << 29)) >> 30;
}

static inline BOOL savd_isBusy()
{
    if (!gSaveData->isBusy)
        return savc_isBusy();

    return TRUE;
}