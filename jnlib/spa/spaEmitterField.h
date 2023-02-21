#pragma once

#include "spaParticle.h"
#include "spaEmitter.h"

void spa_fieldApplyGravity(void* resData, spa_particle_t* particle, VecFx32* acceleration, spa_emitter_t* emitter);
void spa_fieldApplyRandom(void* resData, spa_particle_t* particle, VecFx32* acceleration, spa_emitter_t* emitter);
void spa_fieldApplyMagnetic(void* resData, spa_particle_t* particle, VecFx32* acceleration, spa_emitter_t* emitter);
void spa_fieldApplySpin(void* resData, spa_particle_t* particle, VecFx32* acceleration, spa_emitter_t* emitter);
void spa_fieldApplyCollision(void* resData, spa_particle_t* particle, VecFx32* acceleration, spa_emitter_t* emitter);
void spa_fieldApplyConvergence(void* resData, spa_particle_t* particle, VecFx32* acceleration, spa_emitter_t* emitter);
