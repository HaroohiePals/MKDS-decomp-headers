#pragma once
#include "sound3.h"
#include "soundPool.h"

typedef enum
{
    SOUND_MODE_NORMAL,
    SOUND_MODE_WIFI,
    SOUND_MODE_MULTIBOOT
} SoundMode;

#define SND_HANDLE_0         0
#define SND_HANDLE_1         1
#define SND_HANDLE_2         2
#define SND_HANDLE_JUGEM     4
#define SND_HANDLE_7         7
#define SND_HANDLE_8         8
#define SND_HANDLE_9         9
#define SND_HANDLE_10       10

#define STAR_MUSIC_STATE_STOPPED    0
#define STAR_MUSIC_STATE_PLAYING    1

typedef struct
{
    u8 field0;
    u8 field1;
    u8 seqId;
} struc_387;

typedef struct
{
    u32 field0;
    u32 frameCounter;
    NNSSndHandle starMusicHandle;
    u32 fieldC;
    u32 field10;
    u8 lapCount;
    u8 curLap;
    u8 field16;
    u8 starMusicState;
    u8 curPlace;
    u8 lastSfxPlace;
    int placeChangeSfxTimeout;
    u32 field20;
} struc_380;

extern struc_380 stru_217C814;

extern NNSSndArc gSdatOnMemSndArc;

extern u32 dword_217C780;
extern u32 dword_217C814;

void snd_handleMissionValueChange(int curValue, int target);
void nullsub_10(void);
void snd_setSdatAsCurrent(void);
void sub_2108EB4(int index, int value);
sound_pool_t* snd_getPoolById(int id);
void snd_2108E94(NNSSndCaptureOutputEffectType outputEffect);
NNSSndHandle* snd_getDword217C838Handle0(void);
NNSSndHandle* snd_getDword217C838Handle1(void);
NNSSndHandle* snd_getDword217C838Handle(int idx);
void sub_2108E38(void);
void sub_2108DDC(void);
void sub_2108D80(void);
void sub_2108D00(void);
void sub_2108C80(void);
void sub_2108C1C(void);
void sub_2108C04(void);
void sub_2108BB4(void);
void sub_2108B78(void);
void sub_2108B2C(void);
void sub_2108ADC(void);
void sub_2108A8C(void);
void sub_2108A40(void);
void sub_21089F4(void);
void sub_2108990(void);
void sub_210895C(void);
seq_heap_state_t* snd_getSeqHeapState(void);
BOOL snd_loadCharacterSounds(u16 mask);
u32 snd_getDynamicHeapSize(SoundMode mode);
u32 snd_getStaticHeapSize(SoundMode mode);
void snd_destroyHeaps(void);
void snd_initHeaps(SoundMode mode, void* heapStart);
void snd_init(void* staticHeap, u32 staticHeapSize, BOOL isNormalBoot);
void snd_main(void);
void sub_21074AC(int a1);
void sub_21073EC(u8 a1, struc_387 a2, struc_380* a3);
void snd_handleRaceStart(void);
void sub_2106EFC(void);
void snd_startStarMusic(void);
void snd_stopStarMusic(void);
void sub_2106C64(void);
void snd_handleLapChange(void);
void snd_handlePlaceChangeSfx(u32 newPlace);
void snd_2106580(void);
void snd_handleIntroAmbiance(void);
void sub_21060DC(void);
void sub_2105FCC(void);
void sub_2105EC0(void);
void snd_2105E98(void);
void snd_handleRacePause(void);
void snd_handleRaceContinue(void);
void snd_emitRaceChoiceActivationSound(int a1);
void snd_stopSeqAll(void);
void sub_2105B28(NNSSndHandle* handle, int volume);
void sub_2105B0C(NNSSndHandle* handle, int pitch);
void snd_2105AC0(int sfxId);
void snd_playSecretSound(int type);
void sub_21059E0(void);
void sub_2105980(int a1, int fadeFrame);
void sub_210593C(int result);
void sub_21057F0(int a1, int a2);
void sub_21055B0(int a1);
void sub_2105584(int a1, int fadeFrame);
void sub_2105550(void);
BOOL sub_2105504(void);
BOOL race_isBossBattle(void);

static inline void snd_startSeqArc(NNSSndHandle* handle, int seqArcNo, u16 index)
{
    if (NNS_SndHandleIsValid(handle))
        NNS_SndPlayerStopSeq(handle, 0);
    NNS_SndArcPlayerStartSeqArc(handle, seqArcNo, index);
}

static inline void snd_startSfxType0(NNSSndHandle* handle, int seqArcNo, u16 index)
{
    if ((dword_217C780 & 1) && SoundHandle_217D084.sfxEnabled1)
    {
        if (NNS_SndHandleIsValid(handle))
            NNS_SndPlayerStopSeq(handle, 0);
        snd_startSeqArc(handle, seqArcNo, index);
    }
}

static inline void snd_startSfxType0FromPool(int seqArcNo, u16 index)
{
    if (!(dword_217C780 & 1))
        return;
    NNSSndHandle* handle = &sp_acquireElement(snd_getPoolById(0))->handle;
    if (SoundHandle_217D084.sfxEnabled1)
    {
        if (NNS_SndHandleIsValid(handle))
            NNS_SndPlayerStopSeq(handle, 0);
        snd_startSeqArc(handle, seqArcNo, index);
    }
}

static inline void snd_startSfxType1(NNSSndHandle* handle, int seqArcNo, u16 index)
{
    if ((dword_217C780 & 2) && SoundHandle_217D084.sfxEnabled1)
    {
        if (NNS_SndHandleIsValid(handle))
            NNS_SndPlayerStopSeq(handle, 0);
        snd_startSeqArc(handle, seqArcNo, index);
    }
}