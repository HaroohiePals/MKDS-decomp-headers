#pragma once
#include "jnlib/ui/jnUIUtil.h"

typedef enum
{
    FONT_LC_S,
    FONT_LC_M,
    FONT_MARIO
} MKDSFont;

typedef enum
{
    PORTRAIT_MEDIUM,
    PORTRAIT_LARGE
} MKDSPortrait;

void m2d_load();
void m2d_unload();
const NNSG2dFont* m2d_getFont(MKDSFont font);
NNSG2dPaletteData* m2d_getPortraitONclr(MKDSPortrait portrait);
NNSG2dPaletteData* m2d_getPortraitShyGuyONclr(MKDSPortrait portrait);
NNSG2dCharacterData* m2d_getPortraitNceNcgr(MKDSPortrait portrait);
NNSG2dCellDataBank* m2d_getPortraitNceNcer(MKDSPortrait portrait);
const jnui_bncl_res_t* m2d_getPortraitBncl(MKDSPortrait portrait);
