#pragma once
#include "jnlib/spa/spaEmitter.h"

typedef spa_particleset_t* (*ptcm_get_particleset_by_id_func_t)(int* emitterId, int particleId);
typedef void (*ptcm_special_particle_update_func_t)();

#define PTCM_FLASH_COUNT    6

typedef struct
{
    VecFx32 directions[PTCM_FLASH_COUNT];
    spa_emitter_t* emitters[PTCM_FLASH_COUNT];
    s16 waitCounter;
} ptcm_camflashes_t;

void ptcm_init(NNSFndHeapHandle heapHandle);
void ptcm_update();
void ptcm_render(const MtxFx43* cameraMtx);
spa_emitter_t* ptcm_createEmitter(int particleId, const VecFx32* position);
spa_emitter_t* ptcm_createEmitterNoUpdateSkip(
    int particleId, const VecFx32* position, void* arg, spa_emitter_create_callback_func_t func);
void ptcm_killEmitterDirect(spa_emitter_t* emitter);
void ptcm_killEmitterDirectSafe(spa_emitter_t** emitter);
void ptcm_killEmitter(spa_emitter_t** emitter);
spa_emitter_t* ptcm_createFogOffEmitter(int emitterId, const VecFx32* position);
void ptcm_setEmitterPosition(spa_emitter_t* emitter, const VecFx32* position);
spa_emitter_t* ptcm_208B498(u32 emitterId, const VecFx32* position, u16 driverId, fx32 velocityFactor);
