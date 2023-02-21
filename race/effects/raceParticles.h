#pragma once
#include "jnlib/spa/spaEmitter.h"

typedef struct driver_t driver_t;

typedef enum
{
    RPTC_COLLISION_EFFECT_NONE,
    RPTC_COLLISION_EFFECT_DIRT,
    RPTC_COLLISION_EFFECT_SAND,
    RPTC_COLLISION_EFFECT_GRASS,
    RPTC_COLLISION_EFFECT_WATER,
    RPTC_COLLISION_EFFECT_MUD,
    RPTC_COLLISION_EFFECT_AGB_SKY_GARDEN,
    RPTC_COLLISION_EFFECT_SNOW,
    RPTC_COLLISION_EFFECT_FLOWER
} RaceParticlesCollisionEffect;

#define RPTC_RAINBOW_EMITTER_COUNT    3

typedef struct
{
    spa_emitter_t* emitters[RPTC_RAINBOW_EMITTER_COUNT];
} rptc_rainbow_effect_t;

typedef struct
{
    u16 emitterCount;
    u32 emitterIds[2];
} rptc_col_effect_variant_t;

typedef struct
{
    rptc_col_effect_variant_t variants[2];
    BOOL (*func)(const rptc_col_effect_variant_t* variant, int a2, driver_t* driver);
    u32 field1C;
} rptc_col_effect_t;

typedef struct
{
    int emitterId;
    int tireEmitterIds[2];
    spa_emitter_t* emitter;
    spa_emitter_t* tireEmitters[2][2];
    spa_emitter_t* field20[2];
    spa_emitter_t* wallLeafEmitter;
    spa_emitter_t* bulletBillEmitter;
    spa_emitter_t* electricEmitter;
    VecFx32 tireEmitterPositions[2];
    VecFx16 tireEmitterAxes[2];
} rptc_driver_effect_controller_t;

void rptc_init(NNSFndHeapHandle heapHandle);
void rptc_collisionParticleRender(u16 collisionEffect, driver_t* driver);
rptc_driver_effect_controller_t* rptc_getEffectControllerForDriver(u16 driverId);
void rptc_2081F10(spa_emitter_t* result, u16 driverId, u8 a3);
void rptc_killDriverEffects_copy(driver_t* driver);
void rptc_startWaterEffect(u16 driverId);
void rptc_2081E3C(spa_emitter_t* emitter, u16 driverId, u8 a3);
void rptc_startElectricEffect(u16 driverId);
void rptc_startSlipstreamEffect(driver_t* driver);
void rptc_stopSlipstreamEffect(driver_t* driver);
void rptc_startSlipstreamBeginEffect(driver_t* driver);
void rptc_stopSlipstreamBeginEffect(driver_t* driver);
void rptc_startBulletBillEffect(u16 driverId);
void rptc_startRainbowEffect(u16 driverId);
void rptc_updateRainbowEffect(u16 driverId);
void rptc_stopRainbowEffect(u16 driverId);
void rptc_stopRainbowEffectDirect(u16 driverId);
void rptc_startBoostEffect(int type, driver_t* driver);