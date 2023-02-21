#pragma once

typedef struct
{
    fx32 height;
    u16 posIdx;
    u16 fNrmIdx;
    u16 eNrm1Idx;
    u16 eNrm2Idx;
    u16 eNrm3Idx;
    u16 attribute;
} kcol_prism_data_t;

SDK_COMPILER_ASSERT(sizeof(kcol_prism_data_t) == 0x10);

typedef struct
{
    VecFx32* posDataOffset;
    VecFx16* nrmDataOffset;
    kcol_prism_data_t* prismDataOffset;
    u32* blockDataOffset;
    fx32 prismThickness;
    VecFx32 areaMinPos;
    u32 areaXWidthMask;
    u32 areaYWidthMask;
    u32 areaZWidthMask;
    u32 blockWidthShift;
    u32 areaXBlocksShift;
    u32 areaXYBlocksShift;
    fx32 sphereRadius;
} kcol_header_t;

SDK_COMPILER_ASSERT(sizeof(kcol_header_t) == 0x3C);
