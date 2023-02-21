#pragma once
#include "mapobjInstance.h"
#include "rng.h"
#include "race/items/item.h"

void mobj_initRng();
MATHRandContext32* mobj_getRng1();
MATHRandContext32* mobj_getSafeRng();
BOOL mobj_destroysItemOnHit(const mobj_inst_t* mobj, const it_item_inst_t* item);
void* mobj_getSharedMapObjFile(const char* relPath);
void* mobj_getMapObjFile(const char* relPath);
u32 mobj_parseDecimalBits(s16 decBits);

static inline u16 mobj_getRandom(MATHRandContext32* context, u32 max)
{
    if (max == 0x10000)
        return MATH_Rand32(context, 0x10000);

    return rng_getRandom16(context, max);
}

static inline u16 mobj_getRng1Random(u32 max)
{
    if (max == 0x10000)
        return MATH_Rand32(mobj_getRng1(), 0x10000);

    return rng_getRandom16(mobj_getRng1(), max);
}