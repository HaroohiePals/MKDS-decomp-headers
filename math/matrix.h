#pragma once

static inline void mtx_rotXAngle33(MtxFx33* dst, u16 angle)
{
    MTX_RotX33(dst, FX_SinIdx(angle), FX_CosIdx(angle));
}

static inline void mtx_rotXAngle43(MtxFx43* dst, u16 angle)
{
    MTX_RotX43(dst, FX_SinIdx(angle), FX_CosIdx(angle));
}

static inline void mtx_rotYAngle33(MtxFx33* dst, u16 angle)
{
    MTX_RotY33(dst, FX_SinIdx(angle), FX_CosIdx(angle));
}

static inline void mtx_rotYAngle43(MtxFx43* dst, u16 angle)
{
    MTX_RotY43(dst, FX_SinIdx(angle), FX_CosIdx(angle));
}

static inline void mtx_rotZAngle33(MtxFx33* dst, u16 angle)
{
    MTX_RotZ33(dst, FX_SinIdx(angle), FX_CosIdx(angle));
}

static inline void mtx_rotZAngle43(MtxFx43* dst, u16 angle)
{
    MTX_RotZ43(dst, FX_SinIdx(angle), FX_CosIdx(angle));
}

static inline void mtx_rotAxisAngle33(MtxFx33* dst, const VecFx32* axis, u16 angle)
{
    MTX_RotAxis33(dst, axis, FX_SinIdx(angle), FX_CosIdx(angle));
}

static inline void mtx_rotAxisAngle43(MtxFx43* dst, const VecFx32* axis, u16 angle)
{
    MTX_RotAxis43(dst, axis, FX_SinIdx(angle), FX_CosIdx(angle));
}