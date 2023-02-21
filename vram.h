#pragma once

#define VRAM_WVR_STATUS_LOADED		0
#define VRAM_WVR_STATUS_UNLOADED	1
#define VRAM_WVR_STATUS_BUSY		2
#define VRAM_WVR_STATUS_UNKNOWN		3

typedef void (*vram_wvr_load_unload_callback_func_t)(BOOL isUnload);

typedef struct
{
    vu32 status;
    vram_wvr_load_unload_callback_func_t callbackFunc;
} vram_wvr_stat_t;

extern vram_wvr_stat_t gVramWvrStatus;

void vram_initializeWvrStatus(void);
void vram_clearDisableAll(void);
void vram_setBankForARM7(GXVRamARM7 arm7);
void vram_disableAll(void);
void vram_startUpWifiVram(void);
void vram_terminateWifiVram(void);