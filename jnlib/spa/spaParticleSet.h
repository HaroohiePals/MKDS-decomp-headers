#pragma once

#include "spaList.h"
#include "spaRes.h"

struct spa_emitter_t;
struct spa_particle_t;

typedef void* (*spa_alloc_func_t)(int size);
typedef void (*spa_emitter_create_callback_func_t)(struct spa_emitter_t* emitter, void* arg);

typedef struct
{
    void (*func)(void* resData, struct spa_particle_t* particle, VecFx32* acceleration, struct spa_emitter_t* emitter);
    void* resData;
} spa_transform_func_arg_pair_t;

typedef struct
{
    spa_res_emitter_t* resource;
    spa_res_emitter_scaleanim_t* scaleAnim;
    spa_res_emitter_coloranim_t* colorAnim;
    spa_res_emitter_alphaanim_t* alphaAnim;
    spa_res_emitter_texanim_t* texAnim;
    spa_res_emitter_child_t* childData;
    spa_transform_func_arg_pair_t* fieldFuncs;
    u16 fieldFuncCount;
} spa_emitter_data_t;

typedef struct
{
    const spa_res_texture_t* resource;
    u32 texVramAddr;
    u32 plttVramAddr;
    spa_res_texture_params_t texParams;
    u16 width;
    u16 height;
} spa_texture_data_t;

typedef struct
{
    spa_alloc_func_t allocFunc;
    spa_list_t activeEmitterList;
    spa_list_t freeEmitterList;
    spa_list_t freeParticleList;
    spa_emitter_data_t* emitterData;
    spa_texture_data_t* textureData;
    u16 resEmitterCount;
    u16 resTexCount;
    u16 maxEmitterCount;
    u16 maxParticleCount;
    u32 firstPolygonId : 6;
    u32 lastPolygonId : 6;
    u32 curPolygonId : 6;
    u32 constPolygonId : 6;
    u32 reverseRenderOrder : 1;
    u32 unknown : 7;
    u32 polygonAttr;
    struct spa_emitter_t* curEmitter;
    const MtxFx43* cameraMtx;
    u16 frameIndex;
} spa_particleset_t;

spa_particleset_t* spa_createParticleSet(
    spa_alloc_func_t allocFunc, u16 maxEmitterCount, u16 maxParticleCount,
    u16 constPolygonId, u16 firstPolygonId, u16 lastPolygonId);

void spa_initParticleSet(spa_particleset_t* pset, const spa_res_header_t* spa);

BOOL spa_uploadTextures(spa_particleset_t* pset, u32 (*texVramAllocFunc)(u32 szByte, BOOL is4x4comp));
BOOL spa_uploadPalettes(spa_particleset_t* pset, u32 (*plttVramAllocFunc)(u32 szByte, BOOL is4pltt));
BOOL spa_defaultUploadTextures(spa_particleset_t* pset);
BOOL spa_defaultUploadPalettes(spa_particleset_t* pset);

void spa_updateSet(spa_particleset_t* pset);
void spa_renderSet(spa_particleset_t* pset, const MtxFx43* cameraMtx);

struct spa_emitter_t* spa_createEmitter(spa_particleset_t* pset, int emitterId, VecFx32* position);

struct spa_emitter_t* spa_createEmitterWithCallback(
    spa_particleset_t* pset, int emitterId, VecFx32* position,
    void* arg, spa_emitter_create_callback_func_t func);

void spa_removeEmitter(spa_particleset_t* pset, struct spa_emitter_t* emitter);
