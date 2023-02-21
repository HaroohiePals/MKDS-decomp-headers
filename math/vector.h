#pragma once

#define VEC_MAG_SQUARED(vec) ((fx64)((vec)->x) * (fx64)((vec)->x) + (fx64)((vec)->y) * (fx64)((vec)->y) + (fx64)((vec)->z) * (fx64)((vec)->z))

fx32 vec_normalize(const VecFx32* src, VecFx32* dst);
fx32 vec_dotProduct(const VecFx32* a, const VecFx32* b);
void vec_crossProduct(const VecFx32* a, const VecFx32* b, VecFx32* dst);

static inline fx32 vec_normalizeFastInline(const VecFx32* src, VecFx32* dst)
{
    if (src->x * (s64)src->x + src->y * (s64)src->y + src->z * (s64)src->z <
        FX32_CONST((1.f / 16) * (1.f / 16))) //below a length of 1/16 no normalization
        return 0;
    return vec_normalize(src, dst);
}

static inline void vec_mulScalar(const VecFx32* src, fx32 scalar, VecFx32* dst)
{
    dst->x = (s64)src->x * (s64)scalar >> FX32_SHIFT;
    dst->y = (s64)src->y * (s64)scalar >> FX32_SHIFT;
    dst->z = (s64)src->z * (s64)scalar >> FX32_SHIFT;
}

static inline void vec_toRenderSpace(const VecFx32* src, VecFx32* dst)
{
    dst->x = src->x >> 4;
    dst->y = src->y >> 4;
    dst->z = src->z >> 4;
}

static inline BOOL vec_isNearbyXZ(const VecFx32* vecA, const VecFx32* vecB, fx32 distance)
{
    fx32 deltaX = vecA->x - vecB->x;
    fx32 deltaZ = vecA->z - vecB->z;
    return deltaX * (s64)deltaX + deltaZ * (s64)deltaZ < (s64)distance * (s64)distance;
}

static inline u16 vec_toYAngle(const VecFx32* direction)
{
    return FX_Whole(FX_TRUNC_MUL(FX32_CONST(10430.3782), FX_Atan2(direction->x, direction->z)));
}

static inline void vec_toVecFx16(const VecFx32* src, VecFx16* dst)
{
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
}

static inline void vec_min(const VecFx32* a, const VecFx32* b, VecFx32* dst)
{
    dst->x = a->x < b->x ? a->x : b->x;
    dst->y = a->y < b->y ? a->y : b->y;
    dst->z = a->z < b->z ? a->z : b->z;
}

static inline void vec_max(const VecFx32* a, const VecFx32* b, VecFx32* dst)
{
    dst->x = a->x > b->x ? a->x : b->x;
    dst->y = a->y > b->y ? a->y : b->y;
    dst->z = a->z > b->z ? a->z : b->z;
}
