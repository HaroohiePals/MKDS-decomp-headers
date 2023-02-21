#pragma once
#include "jnlib/spa/spaEmitter.h"

typedef struct dptc_t dptc_t;

typedef void (*dptc_func_t)(dptc_t* controller);

typedef struct dptc_t
{
    spa_emitter_t* whiteDustCloudEmitters[2];
    spa_emitter_t* blueSparkEmitters[2];
    spa_emitter_t* contRedSparkEmitters[2];
    spa_emitter_t* contRedSparkSmallEmitters[2];
    spa_emitter_t* redSparkEmitters[2];
    spa_emitter_t* redSparksSmallEmitters[2];
    s16 contRedSparksCounter;
    int field34;
    BOOL contRedSparksActive;
    BOOL whiteDustCloudsActive;
    BOOL redSparksActive;
    BOOL blueSparksActive;
    s16 redSparksCounter;
    s16 blueSparkCounter;
    int whiteDustCloudParticleId;
    int contRedSparkParticleId;
    int contRedSparkSmallParticleId;
    int redSparkParticleId;
    int redSparksSmallParticleId;
    u16 driverId;
    u16 field62;
    int field64;
    dptc_func_t startContinuousRedSparksFunc;
    dptc_func_t suspendContinuousRedSparksFunc;
    dptc_func_t resumeContinuousRedSparksFunc;
    dptc_func_t killContRedSparksFunc;
    dptc_func_t field78;
    dptc_func_t hideAllFunc;
    dptc_func_t showAllFunc;
    void (*updateContRedSparksFunc)(dptc_t* controller, const VecFx16* a2, const VecFx32* a3);
} dptc_t;

void dptc_init(NNSFndHeapHandle heapHandle);
void dptc_startDustClouds(dptc_t* controller);
void dptc_stopDustClouds(dptc_t* controller);
void dptc_updateDustClouds(dptc_t* controller, driver_t* driver);
void dptc_killContRedSparks(dptc_t* controller);
void dptc_updateContRedSparks(dptc_t* controller, driver_t* driver);
void dptc_emitRedSparks(dptc_t* controller, BOOL a2);
void dptc_updateRedSparks(dptc_t* controller, const VecFx16* axes, const VecFx32* positions);
void dptc_emitBlueSparks(dptc_t* controller, BOOL a2);
void dptc_updateBlueSparks(dptc_t* controller, const VecFx16* axes, const VecFx32* positions);
void dptc_killAll(dptc_t* controller);
dptc_t* dptc_getControllerForDriver(u16 driverId);
void dptc_208C534(dptc_t* controller);
void dptc_208C520(dptc_t* result);
void dptc_hideAll(dptc_t* controller);
void dptc_showAll(dptc_t* controller);
