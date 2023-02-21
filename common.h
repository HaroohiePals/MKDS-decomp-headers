#pragma once
#if __MWERKS__ > 0
#define ATTRIBUTE_NEVER_INLINE __attribute__((never_inline))
#ifdef	__cplusplus
#include "../build/common.mch++"		/* If a compile error occurs in this line, please precompile "Nitro_TS.pch++" */
#else
/* include precompiled header for C source */
#include "../build/common.mch"		/* If a compile error occurs in this line, please precompile "Nitro_TS.pch" */
#endif
#else
#define ATTRIBUTE_NEVER_INLINE
#define ATTRIBUTE_ALIGN(x)
#ifdef	__cplusplus
#include "common.pch++"
#else
/* include precompiled header for C source */
#include "common.pch"
#endif
#endif

//check nitro system version
//#include <nnsys/version.h>
//SDK_COMPILER_ASSERT(NNSYS_VERSION_DATE == 20071126);

typedef u8 uint8_t;
typedef u16 uint16_t;
typedef u32 uint32_t;
typedef u64 uint64_t;

typedef s8 int8_t;
typedef s16 int16_t;
typedef s32 int32_t;
typedef s64 int64_t;

typedef struct
{
    fx32 x;
    fx32 y;
} vec2_t;

//fix error in include (; removed)
#undef GX_FX32_FX10_MAX
#undef GX_FX32_FX10_MIN

#define GX_FX32_FX10_MAX          (fx32)(0x00000fff)
#define GX_FX32_FX10_MIN          (fx32)(0xfffff000)

#define MKTAG(a0,a1,a2,a3) ((u32)((a0) | ((a1) << 8) | ((a2) << 16) | ((a3) << 24)))
// #define FX_TRUNC_MUL(v1, v2) ((fx32)(((s64)(v1) * (v2)) >> FX32_SHIFT))

static inline fx32 FX_TRUNC_MUL(fx32 a, fx32 b)
{
    return (s64)a * (s64)b >> FX32_SHIFT;
}

//fix for changes in the sdk we currently use
static inline void MI_CpuFillFast_fix(void* dest, u32 data, u32 size)
{
    vu32 tmp = (vu32)data;

    SDK_ASSERTMSG((size & 3) == 0, "size & 3 must be 0");
    SDK_ASSERTMSG(((u32)dest & 3) == 0, "source address must be in 4-byte alignment");

    MIi_CpuClearFast(tmp, dest, size);
}

#define MI_CpuFillFast(a,b,c) MI_CpuFillFast_fix(a,b,c)

static inline void MI_CpuClearFast_fix(void* dest, u32 size)
{
    MI_CpuFillFast(dest, 0, size);
}

#define MI_CpuClearFast(a,b) MI_CpuClearFast_fix(a,b)

#include "mkds_rom_config.h"
#include "snd/sfxIds.h"
#include "particles/particleIds.h"
