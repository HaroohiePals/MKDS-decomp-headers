#pragma once

#define SOUND_OUTPUT_EFFECT_BUFFER_SIZE		4096

typedef struct
{
    u32 seqId;
    u32 bank1;
    u32 bank2;
} seq_load_info_t;

typedef struct
{
    seq_load_info_t seqLoadInfo;
    int heapLevel;
} seq_heap_state_t;

typedef struct
{
    seq_load_info_t seqLoadInfo;
    NNSSndHandle handle;
    seq_heap_state_t* heapState;
} seq_handle_t;

typedef struct
{
    u32 field0;
    u32 state;
    u32 stateBackup;
    BOOL sfxEnabled1;
    BOOL sfxEnabled2;
    u32 field14;
    NNSSndHandle* field18;
} struc_379;

extern NNSSndHeapHandle gSndHeapHandle;
extern NNSSndArc gSdatFileSndArc;

extern u32 dword_216CB28;
extern NNSSndHandle dword_217D068;
extern struc_379 SoundHandle_217D084;

BOOL sound_210DCCC(seq_handle_t* seqHandle, int seqId, int bank1, int bank2, seq_heap_state_t* seqHeapState);
void sound_seqHandleStart(seq_handle_t* seqHandle, int volume);
void sound_seqHandleStop(seq_handle_t* seqHandle, int fadeFrame);
void sound_seqHandleUnload(seq_handle_t* seqHandle);

BOOL sound_getIsSdatLoaded();
void sound_setIsSdatLoaded(BOOL isLoaded);

u32 sound_getFadeFrameCount();
void sound_setFadeFrameCount(u32 value);

void sub_210D894(void* heapStart, u32 heapSize, const char* sdatPath);
void sound_startOutputEffect(NNSSndCaptureOutputEffectType outputEffect);
void sound_changeOutputEffect(NNSSndCaptureOutputEffectType outputEffect);
void sound_startSeq(int seqNr, int volume, NNSSndHandle* handle);
void sub_210D7AC();

static inline BOOL soundStateIs2Or3(void)
{
    return SoundHandle_217D084.state == 2 || SoundHandle_217D084.state == 3;
}
