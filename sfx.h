#pragma once

#include "list.h"
#include "snd/soundPool.h"

typedef struct
{
    u32 maxDistance;
    u32 fadePart1EndDistance;
    u32 fadePart1EndVolume;
    u32 fadeStartDistance;
    u32 maxVolume;
} sfx_base_params_t;

typedef struct
{
    int maxDistance;
    int fadePart1EndDistance;
    u32 fadePart1EndVolume;
    int fadeStartDistance;
    int maxVolume;
    fx32 fadePart1Factor;
    fx32 fadePart2Factor;
    u32 field1C;
    int maxDistanceSquare;
} sfx_params_t;

typedef struct
{
    u32 sfxId;
    const VecFx32* position;
    u32 sfxParamsId;
    int squareDistance;
} snd_unkstruct_field0_t;

typedef struct
{
    snd_unkstruct_field0_t field0;
    VecFx32 position;
    NNSSndHandle soundHandle;
    u32 field20;
    u32 field24;
} snd_unkstruct_t;

typedef struct
{
    list_link_t listLink;
    NNSFndList soundList;
    u32 field18;
    list_link_t field1C;
    VecFx32* position;
    void* startFunc;
    void* updateFunc;
    u16 field34;
    u32 field38;
    u8 sfxParamIdx;
    u32 squareDistance;
} sfx_emitter_t;

typedef struct
{
    int field0;
    int field4;
    u32 pitchOffset;
    u32 fieldC;
    u8 unk10[0xC];
} sfx_emitter_ex_params_t;

typedef struct
{
    sfx_emitter_t emitter;
    sfx_emitter_ex_params_t exParams;
} sfx_emitter_ex_t;

#define SFX_SOUND_FIELD19_BIT4      (1 << 4)
#define SFX_SOUND_FIELD19_BIT5      (1 << 5)
#define SFX_SOUND_FIELD19_BIT6      (1 << 6)
#define SFX_SOUND_FIELD19_BIT7      (1 << 7)

typedef struct
{
    sp_handle_t poolHandle;
    list_link_t listLink;
    s16 pitch;
    u16 sfxId;
    u8 seqArcId;
    u8 field19;
    u8 volume;
    u8 field1B;
} sfx_sound_t;

typedef struct
{
    int field0;
    u32 func;
    void* arg;
    u32 fieldC;
} struc_394;

typedef struct
{
    u32 elementCount;
    struc_394* elements;
} struc_393;

extern sfx_params_t gSfxParams[16];
extern struc_393 stru_217D26C[7];

void sub_210B7A8(snd_unkstruct_field0_t* a1);

static inline struc_393* getStru217D26CEntry(u32 idx)
{
    return &stru_217D26C[idx];
}
