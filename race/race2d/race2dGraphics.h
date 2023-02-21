#pragma once

const NNSG2dCellData* r2d_getRaceMCell(int index);
const NNSG2dCellData* r2d_getRaceTaMCell(int index);
const NNSG2dCellData* r2d_getRaceBattleMCell(int index);
const NNSG2dCellData* r2d_getRaceMrMCell(int index);
const NNSG2dCellData* r2d_getRaceSCell(int index);

static inline void renderCell(oam_buf_t* oamBuf, const NNSG2dCellData* cell, fx32 x, fx32 y)
{
    NNSG2dFVec2 position = {x, y};
    oamBuf->objCount += NNS_G2dMakeCellToOams(&oamBuf->oam[oamBuf->objCount], 128 - oamBuf->objCount,
                                              cell, NULL, &position, 0, TRUE);
}

static inline void renderWindowCell(oam_buf_t* oamBuf, const NNSG2dCellData* cell, fx32 x, fx32 y)
{
    int objIdx = oamBuf->objCount;
    NNSG2dFVec2 position = {x, y};
    oamBuf->objCount += NNS_G2dMakeCellToOams(&oamBuf->oam[objIdx], 128 - objIdx,
                                              cell, NULL, &position, 0, TRUE);
    for (; objIdx < oamBuf->objCount; objIdx++)
    {
        oamBuf->oam[objIdx].objMode = GX_OAM_MODE_OBJWND;
        oamBuf->oam[objIdx].priority = 1;
    }
}
