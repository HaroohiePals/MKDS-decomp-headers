#pragma once
#include "jnlib/ui/jnLyt.h"

void kic_unpackDataForGhost();
void kic_unpackDataForMenu();
void kic_initForGhost(NNSFndHeapHandle heapHandle);
void kic_initForMenu(NNSFndHeapHandle heapHandle);
void kic_free();
void kic_putIconInLayout(int kartId, NNSG2dCellDataBank* targetCellDataBank, const jnui_bncl_res_t* targetBncl,
                         int targetElementId, u16 palRow, int engine);
