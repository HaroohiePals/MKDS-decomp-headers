#pragma once
#include "jnLyt.h"

int jn_ui_calcOriginCoordX(jnui_coord_t coord, int width);
int jn_ui_calcOriginCoordY(jnui_coord_t coord, int height);

int jn_ui_checkTouch(const jnui_bnbl_res_t* bnbl, u16 x, u16 y);

const jnui_bnll_res_element_t* jn_ui_getBnllElement(const jnui_bnll_res_t* bnll, int idx);
const jnui_bncl_res_element_t* jn_ui_getBnclElement(const jnui_bncl_res_t* bncl, int idx);

//and this particular function should belong in some other file???
// static inline int sub_20291C4(u32 x, u32 y, const jn_ui_bnbl* bnbl)
// {
// 	return jn_ui_checkTouch(bnbl, x, y);
// }

static inline void jnui_registerObjCharVramTransfer(int engine, int vramOffset, void* src, int length)
{
    DC_FlushRange(src, length);

    if (engine == 0)
        NNS_GfdRegisterNewVramTransferTask(NNS_GFD_DST_2D_OBJ_CHAR_MAIN, vramOffset, src, length);
    else
        NNS_GfdRegisterNewVramTransferTask(NNS_GFD_DST_2D_OBJ_CHAR_SUB, vramOffset, src, length);
}
