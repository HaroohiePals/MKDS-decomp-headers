#pragma once
#include "mapobj.h"
#include "model.h"
#include "model2.h"
#include "animationManager.h"
#include "race/billboardModel.h"

typedef struct
{
    VecFx32 scale;
    bbm_model_t* bbModel;
    model_t* model;
    shadowmodel_t* shadowModel;
    void* nsbmd;
    anim_manager_t* nsbcaAnim;
    anim_manager_t* nsbtpAnim;
    anim_manager_t* nsbmaAnim;
    anim_manager_t* nsbtaAnim;
} mobj_model_t;

void mobj_bbModelApplyMaterial(mobj_render_part_t* renderPart, mobj_model_t* model);
void mobj_renderModel(mobj_render_part_t* renderPart, mobj_model_t* model, mobj_inst_t* mobjInstance);
void mobj_renderModelInPlace(mobj_render_part_t* renderPart, mobj_model_t* model, mobj_inst_t* mobjInstance);
void mobj_setModelPolygonIdAll(mobj_model_t* model, int polygonId);
void mobj_setModelNsbcaFrame(mobj_model_t* model, u16 frame);
u16 mobj_getModelNsbcaFrameCount(mobj_model_t* model);
void mobj_setModelNsbtaFrame(mobj_model_t* model, u16 frame);
u16 mobj_getModelNsbtaFrameCount(mobj_model_t* model);
void mobj_setModelNsbtpFrame(mobj_model_t* model, u16 frame);
u16 mobj_getModelNsbtpFrameCount(mobj_model_t* model);
