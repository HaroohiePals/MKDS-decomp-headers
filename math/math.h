#pragma once

#define FX32_TRUNC_CONST(x)            ((fx32)(x * 4096))

//for some reason the rounding constant is different than the one in the sdk???
#define FX_DEG_TO_IDX2(deg)            ((u16) ((FX64C_65536_360 * (deg) + 0x80000000LL) >> 44))

static inline int math_min(int a, int b)
{
    return a < b ? a : b;
}

static inline int math_max(int a, int b)
{
    return a > b ? a : b;
}

static inline int math_absInline(int a)
{
    return a > 0 ? a : -a;
}