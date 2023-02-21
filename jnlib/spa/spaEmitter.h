#pragma once

#include "spaList.h"
#include "spaParticleSet.h"

struct spa_particle_t;

#define SPA_EMITTER_UPDATE_MOMENT_ALWAYS		0
#define SPA_EMITTER_UPDATE_MOMENT_HALF_FIRST	1
#define SPA_EMITTER_UPDATE_MOMENT_HALF_SECOND	2

#define SPA_EMITTER_COLLISION_PLANE_Y_OVERRIDE_DISABLE		0x80000000

typedef void (*spa_emitter_callback_func_t)(struct spa_emitter_t* emitter, BOOL isAfterUpdate);

typedef struct spa_emitter_t
{
    spa_list_link_t listLink;
    spa_list_t mainParticleList;
    spa_list_t childParticleList;
    spa_emitter_data_t* emitterData;

    union
    {
        u32 flags;

        struct
        {
            u32 shouldDie : 1;
            u32 disableEmission : 1;
            u32 disableUpdates : 1;
            u32 disableRendering : 1;
            u32 startedEmitting : 1;
            u32 : 27;
        };
    };

    VecFx32 position;
    VecFx32 velocity;
    VecFx32 particleVelocity;
    u16 age;
    fx16 lastEmissionFraction;
    VecFx16 axis;
    u16 particleRotation;
    fx32 emissionCount;
    fx32 radius;
    fx32 length;
    fx32 particlePosVeloMag;
    fx32 particleAxisVeloMag;
    fx32 particleScale;
    u16 particleLifetime;
    GXRgb color;
    fx32 collisionPlaneYOverride;
    fx16 texS;
    fx16 texT;
    fx16 childTexS;
    fx16 childTexT;

    u32 emissionInterval : 8;
    u32 particleAlpha : 8;
    u32 updateMoment : 3;
    u32 field80Unk2 : 13;

    VecFx16 axisRight;
    VecFx16 axisUp;

    spa_emitter_callback_func_t callbackFunc;

    u32 userData;
    union
    {
        u32 userWorkU32;
        u16 userWorkU16[2];
        u8 userWorkU8[4];
    };
} spa_emitter_t;

void spa_initEmitter(spa_emitter_t* emitter, spa_emitter_data_t* emitterData, VecFx32* position);
void spa_updateEmitter(spa_particleset_t* pset, spa_emitter_t* emitter);
void spa_renderEmitter(spa_particleset_t* pset);
void spa_setCylinderEmitterDirection(spa_emitter_t* emitter, VecFx32* position, VecFx32* target);

static inline void spa_disableEmitterRendering(spa_emitter_t* emitter)
{
    emitter->disableRendering = TRUE;
}

static inline void spa_enableEmitterRendering(spa_emitter_t* emitter)
{
    emitter->disableRendering = FALSE;
}

static inline void spa_disableEmitterEmission(spa_emitter_t* emitter)
{
    emitter->disableEmission = TRUE;
}

static inline void spa_enableEmitterEmission(spa_emitter_t* emitter)
{
    emitter->disableEmission = FALSE;
}

static inline void spa_setEmitterPosition(spa_emitter_t* emitter, const VecFx32* position)
{
    emitter->position.x = position->x + emitter->emitterData->resource->position.x;
    emitter->position.y = position->y + emitter->emitterData->resource->position.y;
    emitter->position.z = position->z + emitter->emitterData->resource->position.z;
}

static inline void spa_setEmitterPositionX(spa_emitter_t* emitter, fx32 posX)
{
    emitter->position.x = posX + emitter->emitterData->resource->position.x;
}

static inline void spa_setEmitterPositionY(spa_emitter_t* emitter, fx32 posY)
{
    emitter->position.y = posY + emitter->emitterData->resource->position.y;
}

static inline void spa_setEmitterPositionZ(spa_emitter_t* emitter, fx32 posZ)
{
    emitter->position.z = posZ + emitter->emitterData->resource->position.z;
}

static inline void spa_setEmitterRadius(spa_emitter_t* emitter, fx32 radius)
{
    emitter->radius = radius;
}

static inline void spa_setEmitterAxis(spa_emitter_t* emitter, const VecFx16* axis)
{
    emitter->axis = *axis;
}

static inline void spa_setEmitterParticleLifetime(spa_emitter_t* emitter, u16 particleLifetime)
{
    emitter->particleLifetime = particleLifetime;
}

static inline void spa_setEmitterParticleScale(spa_emitter_t* emitter, fx16 particleScale)
{
    emitter->particleScale = particleScale;
}

static inline void spa_setEmitterEmissionCount(spa_emitter_t* emitter, fx32 emissionCount)
{
    emitter->emissionCount = emissionCount;
}

static inline void spa_setEmitterEmissionInterval(spa_emitter_t* emitter, u8 emissionInterval)
{
    emitter->emissionInterval = emissionInterval;
}

static inline void spa_setEmitterParticleVelocity(spa_emitter_t* emitter, const VecFx32* particleVelocity)
{
    emitter->particleVelocity = *particleVelocity;
}

static inline void spa_setEmitterParticleAxisVeloMag(spa_emitter_t* emitter, fx16 particleAxisVeloMag)
{
    emitter->particleAxisVeloMag = particleAxisVeloMag;
}

static inline void spa_setEmitterParticlePosVeloMag(spa_emitter_t* emitter, fx16 particlePosVeloMag)
{
    emitter->particlePosVeloMag = particlePosVeloMag;
}

static inline void spa_killEmitter(spa_emitter_t* emitter)
{
    emitter->shouldDie = TRUE;
}

static inline struct spa_particle_t* spa_getFirstParticle(spa_emitter_t* emitter)
{
    return (struct spa_particle_t*)emitter->mainParticleList.head;
}

static inline struct spa_particle_t* spa_getLastParticle(spa_emitter_t* emitter)
{
    return (struct spa_particle_t*)emitter->mainParticleList.tail;
}

static inline struct spa_particle_t* spa_getFirstChildParticle(spa_emitter_t* emitter)
{
    return (struct spa_particle_t*)emitter->childParticleList.head;
}

static inline struct spa_particle_t* spa_getLastChildParticle(spa_emitter_t* emitter)
{
    return (struct spa_particle_t*)emitter->childParticleList.tail;
}