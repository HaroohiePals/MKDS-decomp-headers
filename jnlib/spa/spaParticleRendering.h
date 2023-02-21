#pragma once
#include "spaParticleSet.h"
#include "spaParticle.h"

void spa_renderParticleBillboard(spa_particleset_t* pset, spa_particle_t* particle);
void spa_renderParticleDirBillboard(spa_particleset_t* pset, spa_particle_t* particle);
void spa_renderParticlePolygon(spa_particleset_t* pset, spa_particle_t* particle);
void spa_renderParticleDirPolygon(spa_particleset_t* pset, spa_particle_t* particle);

void spa_renderChildParticleBillboard(spa_particleset_t* pset, spa_particle_t* particle);
void spa_renderChildParticleDirBillboard(spa_particleset_t* pset, spa_particle_t* particle);
void spa_renderChildParticlePolygon(spa_particleset_t* pset, spa_particle_t* particle);
void spa_renderChildParticleDirPolygon(spa_particleset_t* pset, spa_particle_t* particle);
