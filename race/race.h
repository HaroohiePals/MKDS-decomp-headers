#pragma once
#include "camera.h"

typedef enum
{
    RACE_STATE_PRE_START,
    RACE_STATE_STARTED
} RaceState;

typedef enum
{
    RACE_DARKENING_FOG_STATE_OFF,
    RACE_DARKENING_FOG_STATE_ON
} RaceDarkeningFogState;

typedef struct
{
    s16 state;
    u32 frameCounter;
    int frameCounter2;
    int frameCounterModulo8;
    BOOL isOddFrame;
    int frameCounterModuloDriverCount;
    u32 toonTableOffset;
    u32 toonTableUpdateCounter;
    RaceDarkeningFogState darkeningFogState;
    RaceDarkeningFogState prevDarkeningFogState;
    BOOL isCamAnimMode;
    BOOL isCamAnimSingleScreen;
    u32 field30;
    u32 field34;
    BOOL isAwardStaffRoll;
    u32 field3C;
    VecFx16 light0Dir;
} race_state_t;

BOOL race_isCamAnimMode();
BOOL race_isAwardStaffRoll();
void race_init();
void race_initResManagement();
void race_initG3d();
void race_update();
void race_render();
void race_setLight0Direction(const VecFx32* direction);
void race_finalize();
void race_vblank();
RaceState race_getState();
void race_start();
u32 race_getFrameCounter();
int race_getFrameCounterModuloDriverCount();
int race_getFrameCounterModulo8();
BOOL race_getIsOddFrame();
void race_startDarkening();
void race_resetDarkeningFadeWaitCounter();
void race_forceDarkeningFade();
BOOL race_getIsDarkeningActive();
const MtxFx43* race_getCameraMtx();
int race_getCameraField250();
camera_t* race_getCamera();
void race_setField34();
void race_20617D8();
BOOL race_20617A8(u32* a1);
u16 race_getFirstObjectPolygonId();
u16 race_getLastParticlePolygonId();
