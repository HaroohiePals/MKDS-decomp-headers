#pragma once
#include "animationManager.h"
#include "model.h"

typedef struct
{
    void* displayList;
    u32 displayListLength;
    fx32 posScale;
    u32 diffAmb;
    u32 speEmi;
    u32 polygonAttr;
    u16 texIdx;
    u16 texCount;
    u32* texParamList;
    u32* plttParamList;
    model_t* model;
    anim_manager_t* nsbtpAnim;
} bbm_model_t;

void bbm_updateBaseMatrices(const MtxFx43* camMtx);
void bbm_setupCustomUpAxisBillboard(const VecFx32* upVec);
void bbm_20E6D34(const VecFx32* upVec, MtxFx43* dstMtx);
const MtxFx43* bbm_getBillboardAtPos(const VecFx32* position);
const MtxFx43* bbm_getYBillboardAtPos(const VecFx32* position);
const MtxFx43* bbm_getYBillboardAtPosTransformed(const VecFx32* position, fx32 a, fx32 b);
void bbm_20E6C0C();
const MtxFx43* bbm_getCustomUpAxisBillboardAtPos(const VecFx32* position);
const MtxFx43* bbm_20E6B94(const VecFx32* position);
const MtxFx43* bbm_20E6B58(const VecFx32* position);
const MtxFx43* bbm_getYBillboardMtx();
const MtxFx43* bbm_getBillboardMtx();
const VecFx32* bbm_getBillboardRightVec();
const VecFx32* bbm_getBillboardForwardVec();
void bbm_setDefaultMatParams(bbm_model_t* result);
void bbm_restoreCameraMtx();
void bbm_applyMaterial(bbm_model_t* model);
u32 bbm_calcDistanceAlpha(const VecFx32* position);
void bbm_render(bbm_model_t* model, const VecFx32* position, BOOL distanceFade, u16 alpha);
void bbm_renderTransformedScaled(bbm_model_t* model, const MtxFx43* mtx, const VecFx32* scale, BOOL distanceFade, u16 alpha);
void bbm_renderTransformedRotatedScaled(bbm_model_t* model, const MtxFx43* mtx, u16 rotZ, const VecFx32* scale, BOOL distanceFade, u16 alpha);
void bbm_init();
void bbm_initFromNsbmd(bbm_model_t* model, void* nsbmd, const void* nsbtp, u32 unk);
void bbm_createFromNsbmd(bbm_model_t** model, void* nsbmd, const void* nsbtp, u32 unk);

static inline void bbm_setLightMask(bbm_model_t* model, GXLightMask lightMask)
{
    model->polygonAttr &= ~REG_G3_POLYGON_ATTR_LE_MASK;
    model->polygonAttr |= lightMask << REG_G3_POLYGON_ATTR_LE_SHIFT;
}

static inline void bbm_setAlpha(bbm_model_t* model, u16 alpha)
{
    model->polygonAttr &= ~REG_G3_POLYGON_ATTR_ALPHA_MASK;
    model->polygonAttr |= alpha << REG_G3_POLYGON_ATTR_ALPHA_SHIFT;
}

static inline void bbm_setEmission(bbm_model_t* model, GXRgb emission)
{
    model->speEmi &= ~0x7FFF0000;
    model->speEmi |= emission << 16;
}