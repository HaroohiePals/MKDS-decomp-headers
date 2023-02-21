#pragma once

void g2du_unpackPaletteData(NNSG2dPaletteData** palData, const void* nclr);
void g2du_getPaletteData(NNSG2dPaletteData** palData, const void* nclr);
void g2du_unpackCharacterData(NNSG2dCharacterData** charData, const void* ncgr);
void g2du_getCharacterData(NNSG2dCharacterData** charData, const void* ncgr);
void g2du_unpackCharacterDataBG(NNSG2dCharacterData** charData, const void* ncgr);
void g2du_getCharacterDataBG(NNSG2dCharacterData** charData, const void* ncgr);
void g2du_unpackCellBankData(NNSG2dCellDataBank** cellData, const void* ncer);
void g2du_getCellBankData(NNSG2dCellDataBank** cellData, const void* ncer);
