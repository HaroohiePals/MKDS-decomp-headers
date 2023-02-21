#pragma once
#include "jnLyt.h"

BOOL jnui_getLabelIsTranslucent(int elementIdx, const jnui_bnll_res_t* bnll, jnui_layout_element_t* layoutElements,
                                 const jnui_bncl_res_t* bncl);
void jnui_setLabelIsTranslucent(int elementIdx, BOOL translucent, const jnui_bnll_res_t* bnll,
                                 jnui_layout_element_t* layoutElements, const jnui_bncl_res_t* bncl);
void jnui_setLabelColorParam(int elementIdx, int colorParam, const jnui_bnll_res_t* bnll,
                              jnui_layout_element_t* layoutElements, const jnui_bncl_res_t* bncl);
u8 jnui_getLabelPriority(int elementIdx, const jnui_bnll_res_t* bnll, jnui_layout_element_t* layoutElements,
                           const jnui_bncl_res_t* bncl);
void jnui_setLabelPriority(int elementIdx, u8 priority, const jnui_bnll_res_t* bnll,
                            jnui_layout_element_t* layoutElements,
                            const jnui_bncl_res_t* bncl);
u32 jnui_initLabel(NNSFndHeapHandle heapHandle, int elementIdx, const jnui_bnll_res_t* bnll, int width, int height,
                    int parent, const NNSG2dCellDataBank* cellDataBank, const jnui_bncl_res_t* bncl,
                    jnui_layout_element_t* layoutElements, u32 vramLeft);

void jnui_21241C0(int engine, int elementIdx, const jnui_bnll_res_t* bnll, const jnui_bncl_res_t* bncl,
                   jnui_layout_element_t* layoutElements);
void jnui_212426C(int engine, int elementIdx, const jnui_bnll_res_t* bnll, const u16* text, const jnui_bncl_res_t* bncl,
                   jnui_layout_element_t* layoutElements);
void jnui_2124248(int engine, int elementIdx, const jnui_bnll_res_t* bnll, const u16* text, const jnui_bncl_res_t* bncl,
                   jnui_layout_element_t* layoutElements, s8 charWidth);
void jnui_2124224(int engine, int elementIdx, const jnui_bnll_res_t* bnll, const u16* text, const jnui_bncl_res_t* bncl,
                   jnui_layout_element_t* layoutElements, s8 charWidth);
