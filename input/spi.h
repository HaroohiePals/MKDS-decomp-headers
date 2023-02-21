#pragma once
#include "snd/microphone.h"

typedef struct
{
    u16 tpX;
    u16 tpY;
    u16 tpValid;
    u16 field6;
} input_tpmic_tp_t;

typedef struct
{
    input_tpmic_tp_t curTp;
    input_tpmic_tp_t prevTp;
    u16 tpReleaseFrameCounter;
    u8 mic;
} input_tpmic_t;

typedef struct
{
    TPData tpSampleBuf[5];
    TPData curTp;
    BOOL tpAutoSamplingEnabled : 1;
    BOOL micAutoSamplingEnabled : 1;
    BOOL micAutoSamplingPaused : 1;
    BOOL micInputDetected : 1;
    u8 gap34[8];
    mic_t* micData;
} spi_t;

extern spi_t* gSpiData;

void spi_initTouch();
void spi_init(NNSFndHeapHandle heapHandle);
void spi_initTpMic(input_tpmic_t* tpMic);
void spi_startTouchAutoSampling();
void spi_startMicAutoSampling(NNSFndHeapHandle heapHandle);
void spi_stopTouchAutoSampling();
void spi_stopMicAutoSampling();
void spi_handlePreSleep();
void spi_handlePostSleep();
void spi_update();
void spi_updateTpMic(input_tpmic_t* tpmic, u16 touch, BOOL mic);
void spi_finalize();
u16 spi_getTouchPos();

static inline u32 spi_getTpX(input_tpmic_t* shit)
{
    return shit->curTp.tpX;
}

static inline u32 spi_getTpY(input_tpmic_t* shit)
{
    return shit->curTp.tpY;
}

static inline BOOL spi_getTpValid(input_tpmic_t* shit)
{
    return shit->curTp.tpValid;
}

static inline BOOL spi_isPenReleaseTimeout(input_tpmic_t* shit)
{
    return !spi_getTpValid(shit) && shit->tpReleaseFrameCounter < 5;
}

static inline BOOL spi_isPenDownEvent(input_tpmic_t* shit)
{
    return !shit->prevTp.tpValid && shit->curTp.tpValid;
}

static inline BOOL spi_isValidPenDownEvent(input_tpmic_t* shit)
{
    return !spi_isPenReleaseTimeout(shit) && spi_isPenDownEvent(shit);
}
