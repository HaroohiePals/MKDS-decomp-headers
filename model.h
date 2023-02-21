#pragma once

typedef struct
{
    NNSFndLink link;
    void* nsbmd;
    NNSG3dResTex* texRes;
} model_res_t;

typedef struct
{
    NNSG3dRenderObj renderObj;
    u32 cullReversed;
    BOOL render1Mat1Shp;
    model_res_t res;
} model_t;

extern void (*const gModelRenderFuncs[2])(model_t* model);

void model_initResList();
void model_resSetNsbmdNsbtx(model_res_t* res, void* nsbmd, void* nsbtx);
void model_setCullFront(model_t* model);
void model_setCullBack(model_t* model);
void model_initFromResMdl(model_t* model, NNSG3dResMdl* resMdl);
NNSG3dResMdl* model_initFromNsbmd(model_t* model, void* nsbmd);
NNSG3dResMdl* model_initFromNsbmdNsbtx(model_t* model, void* nsbmd, void* nsbtx);
NNSG3dResMdl* model_initFromNsbmdNoCullFix(model_t* model, void* nsbmd);
NNSG3dResMdl* model_initFromNsbmdNsbtxMetaCopy(NNSFndHeapHandle heapHandle, model_t* model, void* nsbmd, void* nsbtx);
void model_configShadowPass1(model_t* model, int alpha);
void model_configShadowPass2(model_t* model, int alpha, int polygonId);
void model_drawTransformed(model_t* model, const MtxFx43* mtx, const VecFx32* scale);
void model_render(model_t* model);

// static inline void model_draw(model_t* model)
// {
// 	gModelDrawFuncs[model->render1Mat1Shp](model);
// }

void model_setPolygonId(model_t* model, int polygonId);
void model_setLightEnableFlag(model_t* model, int light);
void model_setEmi(model_t* model, GXRgb col);
void model_setPolyIdLightFlagsEmi(model_t* model, int polygonId, int light, GXRgb emi);
void model_setCullMode(model_t* model, GXCull cullMode);
void model_releaseAll();
