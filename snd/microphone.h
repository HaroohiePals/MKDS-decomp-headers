#pragma once

#define MIC_SAMPLE_BUFFER_SIZE  1024

typedef struct
{
    s8 sampleBuffer[MIC_SAMPLE_BUFFER_SIZE];
    MICAutoParam autoParam;
    int frameCounter;
} mic_t;

void mic_init(void);
void mic_initAutoSampling(mic_t* mic);
void mic_finalize(mic_t* mic);
void mic_startAutoSampling(mic_t* mic);
void mic_stopAutoSampling(mic_t* mic);
int mic_update(mic_t* mic);
void mic_handlePreSleep(mic_t* mic);
void mic_handlePostSleep(mic_t* mic);