#pragma once

#include "spaParticle.h"
#include "spaEmitter.h"

void spa_updateScaleAnim(spa_particle_t* particle, spa_emitter_data_t* emitterData, int progress);
void spa_updateColorAnim(spa_particle_t* particle, spa_emitter_data_t* emitterData, int progress);
void spa_updateAlphaAnim(spa_particle_t* particle, spa_emitter_data_t* emitterData, int progress);
void spa_updateTexAnim(spa_particle_t* particle, spa_emitter_data_t* emitterData, int progress);

void spa_updateChildScaleAnim(spa_particle_t* particle, spa_emitter_data_t* emitterData, int progress);
void spa_updateChildAlphaFade(spa_particle_t* particle, spa_emitter_data_t* emitterData, int progress);
