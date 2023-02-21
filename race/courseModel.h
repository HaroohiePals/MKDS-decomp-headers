#pragma once
#include "model.h"
#include "animationManager.h"

typedef struct
{
    model_t* model;
    model_t* modelV;
    anim_manager_t nsbtpAnim;
    anim_manager_t nsbtaAnim;
    anim_manager_t nsbtaAnimV;
    MtxFx43 mtx;
    BOOL modelHasPartialFog;
    s64 modelFogFlags;
    BOOL modelVHasPartialFog;
    u16 modelVFogFlags;
} crsmdl_t;

void crsmdl_init(NNSFndHeapHandle heapHandle);
void crsmdl_update();
void crsmdl_renderCourse();
void crsmdl_renderSky();
void crsmdl_setupLights();
void crsmdl_setFogFlags(BOOL enabled);
int crsmdl_getNsbtpProgress();