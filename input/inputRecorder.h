#pragma once

typedef enum
{
    INPUT_REC_STATE_IDLE,
    INPUT_REC_STATE_RECORDING,
    INPUT_REC_STATE_PLAYING,
    INPUT_REC_STATE_BUFFER_FULL
} InputRecState;

#define INPUT_REC_RECORDING_ENTRY_COUNT             1764

#define INPUT_REC_RECORDING_ENTRY_KEY_BUTTON_A      (1 << 0)
#define INPUT_REC_RECORDING_ENTRY_KEY_BUTTON_B      (1 << 1)
#define INPUT_REC_RECORDING_ENTRY_KEY_BUTTON_R      (1 << 2)
#define INPUT_REC_RECORDING_ENTRY_KEY_BUTTON_LX     (1 << 3)
#define INPUT_REC_RECORDING_ENTRY_KEY_DPAD_RIGHT    (1 << 4)
#define INPUT_REC_RECORDING_ENTRY_KEY_DPAD_LEFT     (1 << 5)
#define INPUT_REC_RECORDING_ENTRY_KEY_DPAD_DOWN     (1 << 6)
#define INPUT_REC_RECORDING_ENTRY_KEY_DPAD_UP       (1 << 7)

typedef struct
{
    u8 keys;
    u8 duration;
} input_rec_recording_entry_t;

typedef struct
{
    u32 dataLength;
    input_rec_recording_entry_t entries[INPUT_REC_RECORDING_ENTRY_COUNT];
} input_rec_recording_t;

typedef struct
{
    input_rec_recording_t* recording;
    u16 curEntry;
    u16 waitCounter;
    InputRecState state;
    BOOL isBufferClear;
} input_rec_t;

void irec_allocBuffer(input_rec_t* recorder, NNSFndHeapHandle heapHandle);
void irec_setBufferToNull(input_rec_t* recorder);
void irec_init(input_rec_t* recorder);
void irec_startRecording(input_rec_t* recorder);
void irec_stopRecording(input_rec_t* recorder);
void irec_startPlayback(input_rec_t* recorder);
void irec_stopPlayback(input_rec_t* recorder);
void irec_recordKeys(input_rec_t* recorder, u16 keys);
u16 irec_playKeys(input_rec_t* recorder);
BOOL irec_isBufferFull(const input_rec_t* recorder);
BOOL irec_isAlmostAtPlayBufferEnd(const input_rec_t* recorder);
