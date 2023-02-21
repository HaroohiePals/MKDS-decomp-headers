#pragma once

#include "oam.h"
#include "jnLytRes.h"

typedef struct
{
    NNSG2dCharCanvas charCanvas;
    NNSG2dTextCanvas textCanvas;
    void* charData;
    u32 charDataLength;
    u32 charDataTileOffset;
    u32 width;
    u32 height;
    NNSG2dCellDataWithBR* cellData;
} jnui_label_t;

typedef struct
{
    BOOL visible;
    s16 offsetX;
    s16 offsetY;
    BOOL usePosition;
    s16 positionX;
    s16 positionY;
    BOOL useMtx;
    MtxFx22 baseMtx;
    MtxFx22 affineMtx;
    BOOL useDoubleAffine;
    s32 subElement;
    jnui_label_t* label;
} jnui_layout_element_t;

void jnui_initLayout(NNSFndHeapHandle heapHandle, const jnui_bncl_res_t* bncl, const jnui_bnll_res_t* bnll,
                     jnui_layout_element_t** layoutElements);
void jnui_renderElements(const jnui_bncl_res_t* bncl, const NNSG2dCellDataBank* cellDataBank,
                         const jnui_bnll_res_t* bnll, oam_buf_t* oamBuffer, jnui_layout_element_t* layoutElements);
void jnui_renderElementsNoIncrAffine(const jnui_bncl_res_t* bncl, const NNSG2dCellDataBank* cellDataBank,
                                     const jnui_bnll_res_t* bnll, oam_buf_t* oamBuffer,
                                     jnui_layout_element_t* layoutElements);
void jnui_renderElement(int elementIdx, const jnui_bncl_res_t* bncl, const NNSG2dCellDataBank* cellDataBank,
                        const jnui_bnll_res_t* bnll, oam_buf_t* oamBuffer, jnui_layout_element_t* layoutElements);
void jnui_setElementAffine(jnui_layout_element_t* layoutElement, int rotation, fx32 scale);
BOOL jnui_getCellIsTranslucent(int elementIdx, const NNSG2dCellDataBank* cellDataBank, const jnui_bncl_res_t* bncl);
void jnui_setCellIsTranslucent(int elementIdx, BOOL translucent, const NNSG2dCellDataBank* cellDataBank,
                               const jnui_bncl_res_t* bncl);
void jnui_setCellColorParam(int elementIdx, int colorParam, const NNSG2dCellDataBank* cellDataBank,
                        const jnui_bncl_res_t* bncl);
u8 jnui_getCellPriority(int elementIdx, const NNSG2dCellDataBank* cellDataBank, const jnui_bncl_res_t* bncl);
void jnui_setCellPriority(int elementIdx, u8 priority, const NNSG2dCellDataBank* cellDataBank,
                          const jnui_bncl_res_t* bncl);
void jnui_fillPlaceholder(int srcElementIdx, const NNSG2dCellDataBank* srcCellDataBank,
                          const NNSG2dCharacterData* srcCharData, const jnui_bncl_res_t* srcBncl, int engine,
                          int dstElementId, const NNSG2dCellDataBank* dstCellDataBank, const jnui_bncl_res_t* dstBncl);

static inline u16 jn_ui_getBnclElementCount(const jnui_bncl_res_t* bncl)
{
    return bncl->header.nrElements;
}

static inline u16 jn_ui_getBnblElementCount(const jnui_bnbl_res_t* bnbl)
{
    return bnbl->header.nrElements;
}

static inline const jnui_bncl_res_element_t* jn_ui_getBnclElement2(const jnui_bncl_res_t* bncl, int idx)
{
    const jnui_bncl_res_element_t* element = (const jnui_bncl_res_element_t*)&bncl[1];
    element += idx;
    return element;
}
