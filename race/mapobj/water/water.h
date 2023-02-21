#pragma once
#include "race/mapobj/mapobj.h"

typedef struct
{
    mobj_inst_t mobj;
} water_t;

typedef struct
{
    mobj_inst_t mobj;
} water_splash_t;

typedef enum
{
    WATER_STATE_0,
    WATER_STATE_1,
    WATER_STATE_2,
    WATER_STATE_3
} WaterState;

typedef struct water_state_t
{
    VecFx32 waterAPosition;
    VecFx32 waterCPosition;
    VecFx32 basePosition;
    WaterState state;
    fx32 tideAmplitude;
    u16 tidePhase;
    u16 tideSpeed;
    fx32 tideProgress;
    u16 field34;
    u16 field36;
    u16 field38;
    u16 field3A;
    u16 waterMovePhase;
    u16 field3E;
    u16 waterMoveSpeed;
    fx32 waterAMoveDistance;
    fx32 waterCMoveDistance;
    fx32 field4C;
    u16 waterCMovePhaseDifference;
    u16 field52;
    BOOL waterAFirst;
    u16 waterAAlpha;
    u16 waterCAlpha;
    u16 field5C;
    void* waterANsbmd;
    void* waterCNsbmd;
    model_t waterAModel;
    model_t waterCModel;
    MtxFx43 transformMtx;
    BOOL isDiveable;
    void* waterEfctNsbmd;
    void* waterEfctNsbca;
    void* waterEfctNsbma;
} water_state_t;

typedef struct water_splash_state_t
{
    fx32 splashY;
    void* nsbmd;
    void* nsbca;
    void* nsbma;
} water_splash_state_t;

extern const mobj_def_t gWaterMObjDef;
extern const mobj_def_t gSplashMObjDef;

void water_update(water_state_t* state);
void water_render(water_state_t* state, const MtxFx43* camMtx);

void water_loadMiniStage3Water();
void water_loadBeachWater();
void water_loadTownWater();
void water_loadYoshiWater();
void water_loadHyudoroWater();
