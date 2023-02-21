#pragma once

typedef struct
{
    u32 magic; ///< File identifier: NKMD
    u16 version;
    ///< Version Number. Final tracks are always 3.7 (0x25 = 37). Beta tracks are 3.0 (0x1E = 30), 3.2 (0x20 = 32) or 3.4 (0x22 = 34).
    u16 headerLength;
    u32 offsets[17];
} nkm_header_t;

typedef struct
{
    u32 magic;
    u32 count;
} nkm_section_header_t;

typedef struct
{
    VecFx32 position;
    VecFx32 rotation;
    VecFx32 scale;
    u16 objectId;
    s16 pathId;
    s16 settings[7];
    s16 flags; //clip areas and suspend during countdown
    u16 showsInTT; ///< If the object should be displayed in time trial mode (false for item boxes for example)
} nkm_obji_entry_t;

SDK_COMPILER_ASSERT(sizeof(nkm_obji_entry_t) == 0x3C);

typedef struct
{
    nkm_section_header_t header;
    nkm_obji_entry_t entries[0];
} nkm_obji_t;

typedef struct
{
    u8 id;
    u8 loop;
    u16 pointCount;
} nkm_path_entry_t;

SDK_COMPILER_ASSERT(sizeof(nkm_path_entry_t) == 0x4);

typedef struct
{
    nkm_section_header_t header;
    nkm_path_entry_t entries[0];
} nkm_path_t;

typedef struct
{
    VecFx32 position;
    u8 pointIndex;
    u8 unknown1;
    s16 duration;

    union
    {
        u32 unknown2;
        struct
        {
            s16 unknown2_s16;
            s16 unknown2_s16_hi;
        };
    };
} nkm_poit_entry_t;

SDK_COMPILER_ASSERT(sizeof(nkm_poit_entry_t) == 0x14);

typedef struct
{
    nkm_section_header_t header;
    nkm_poit_entry_t entries[0];
} nkm_poit_t;

typedef struct
{
    u16 courseId;
    u16 nrLaps;
    u8 polePosition;
    u8 fogEnabled;
    u8 fogTableGenMode;
    u8 fogSlope;
    u8 unknown2[8];
    fx32 fogDensity;
    u32 fogColor;
    GXRgb kclColors[4];
    fx32 mobjFarClip;
    fx32 frustumFar;
} nkm_stag_data_t;

typedef struct
{
    u32 magic;
    nkm_stag_data_t data;
} nkm_stag_t;

SDK_COMPILER_ASSERT(sizeof(nkm_stag_t) == 0x2C);

typedef struct
{
    VecFx32 position;
    VecFx32 rotation;
    u16 padding;
    s16 index;
} nkm_ktps_entry_t;

SDK_COMPILER_ASSERT(sizeof(nkm_ktps_entry_t) == 0x1C);

typedef struct
{
    nkm_section_header_t header;
    nkm_ktps_entry_t entries[0];
} nkm_ktps_t;

typedef struct
{
    VecFx32 position;
    VecFx32 rotation;
    u16 enemyPointId;
    u16 itemPointId;
    s16 id;
} nkm_ktpj_entry_t;

SDK_COMPILER_ASSERT(sizeof(nkm_ktpj_entry_t) == 0x20);

typedef struct
{
    nkm_section_header_t header;
    nkm_ktpj_entry_t entries[0];
} nkm_ktpj_t;

typedef struct
{
    VecFx32 position;
    VecFx32 rotation;
    u16 padding;
    u16 id;
} nkm_ktp2_entry_t;

SDK_COMPILER_ASSERT(sizeof(nkm_ktp2_entry_t) == 0x1C);

typedef struct
{
    nkm_section_header_t header;
    nkm_ktp2_entry_t entries[0];
} nkm_ktp2_t;

typedef struct
{
    VecFx32 position;
    VecFx32 rotation;
    s16 nextMepo;
    u16 id;
} nkm_ktpc_entry_t;

SDK_COMPILER_ASSERT(sizeof(nkm_ktpc_entry_t) == 0x1C);

typedef struct
{
    nkm_section_header_t header;
    nkm_ktpc_entry_t entries[0];
} nkm_ktpc_t;

typedef struct
{
    VecFx32 position;
    VecFx32 rotation;
    u16 padding;
    s16 id;
} nkm_ktpm_entry_t;

SDK_COMPILER_ASSERT(sizeof(nkm_ktpm_entry_t) == 0x1C);

typedef struct
{
    nkm_section_header_t header;
    nkm_ktpm_entry_t entries[0];
} nkm_ktpm_t;

#define NKM_CPOI_FLAGS_FREEZE_PLACE      1 //disables place updates inside the checkpoint, used in rainbow road for the loop

typedef struct
{
    fx32 x1;
    fx32 z1;
    fx32 x2;
    fx32 z2;
    fx32 sin;
    fx32 cos;
    fx32 distance;
    s16 gotoSection;
    s16 startSection;
    s16 keyId;
    u8 respawnId;
    u8 flags;
} nkm_cpoi_entry_t;

SDK_COMPILER_ASSERT(sizeof(nkm_cpoi_entry_t) == 0x24);

typedef struct
{
    nkm_section_header_t header;
    nkm_cpoi_entry_t entries[0];
} nkm_cpoi_t;

typedef struct
{
    u16 start;
    u16 length;
    u8 next[3];
    u8 previous[3];
    u8 sectionOrder;
} nkm_cpat_entry_t;

SDK_COMPILER_ASSERT(sizeof(nkm_cpat_entry_t) == 0xC);

typedef struct
{
    nkm_section_header_t header;
    nkm_cpat_entry_t entries[0];
} nkm_cpat_t;

typedef struct
{
    VecFx32 position;
    fx32 radius;
    u8 recalcIdx;
    //most likely padding
} nkm_ipoi_entry_t;

SDK_COMPILER_ASSERT(sizeof(nkm_ipoi_entry_t) == 0x14);

typedef struct
{
    VecFx32 position;
    fx32 radius;
} nkm_ipoi_entry_beta_t;

SDK_COMPILER_ASSERT(sizeof(nkm_ipoi_entry_beta_t) == 0x10);

typedef union
{
    const nkm_ipoi_entry_t* final;
    const nkm_ipoi_entry_beta_t* beta;
} nkm_ipoi_entry_pointer_t;

typedef struct
{
    nkm_section_header_t header;
    nkm_ipoi_entry_t entries[0];
} nkm_ipoi_t;

typedef struct
{
    u16 start;
    u16 length;
    u8 next[3];
    u8 previous[3];
    s16 sectionOrder;
} nkm_ipat_entry_t;

SDK_COMPILER_ASSERT(sizeof(nkm_ipat_entry_t) == 0xC);

typedef struct
{
    nkm_section_header_t header;
    nkm_ipat_entry_t entries[0];
} nkm_ipat_t;

typedef struct
{
    u16 drifting;
    u16 unknown1;
    u32 unknown2;
} nkm_epoi_entry_settings_t;

typedef struct
{
    VecFx32 position;
    fx32 radius;
    nkm_epoi_entry_settings_t settings;
} nkm_epoi_entry_t;

SDK_COMPILER_ASSERT(sizeof(nkm_epoi_entry_t) == 0x18);

typedef struct
{
    nkm_section_header_t header;
    nkm_epoi_entry_t entries[0];
} nkm_epoi_t;

typedef struct
{
    u16 start;
    u16 length;
    u8 next[3];
    u8 previous[3];
    s16 sectionOrder;
} nkm_epat_entry_t;

SDK_COMPILER_ASSERT(sizeof(nkm_epat_entry_t) == 0xC);

typedef struct
{
    nkm_section_header_t header;
    nkm_epat_entry_t entries[0];
} nkm_epat_t;

typedef struct
{
    u32 drifting;
    u32 unknown1;
} nkm_mepo_entry_settings_t;

typedef struct
{
    VecFx32 position;
    fx32 radius;
    nkm_mepo_entry_settings_t settings;
} nkm_mepo_entry_t;

SDK_COMPILER_ASSERT(sizeof(nkm_mepo_entry_t) == 0x18);

typedef struct
{
    nkm_section_header_t header;
    nkm_mepo_entry_t entries[0];
} nkm_mepo_t;

typedef struct
{
    u16 start;
    u16 length;
    u8 next[8];
    u8 previous[8];
} nkm_mepa_entry_t;

SDK_COMPILER_ASSERT(sizeof(nkm_mepa_entry_t) == 0x14);

typedef struct
{
    nkm_section_header_t header;
    nkm_mepa_entry_t entries[0];
} nkm_mepa_t;

typedef enum
{
    NKM_AREA_SHAPE_BOX = 0,
    NKM_AREA_SHAPE_CYLINDER = 1
} NKMAreaShape;

typedef enum
{
    NKM_AREA_TYPE_0 = 0,
    NKM_AREA_TYPE_CAMERA = 1,
    NKM_AREA_TYPE_MISSION_END = 2, //param0: 0 = win, 1 = lose
    NKM_AREA_TYPE_CLIP_AREA = 3,
    NKM_AREA_TYPE_ENEMY_RESPAWN_ROUTE = 4,
    NKM_AREA_TYPE_MISSION_RIVAL_PASS_AREA = 5 //param0: object id, param1: number of passes before lose
} NKMAreaType;

typedef struct
{
    VecFx32 position;
    VecFx32 length;
    VecFx32 xVector;
    VecFx32 yVector;
    VecFx32 zVector;
    s16 param0;
    s16 param1;
    s16 enemyPointId;
    u8 shape;
    u8 cameraId;
    u8 type;
    u8 field45;
    u8 field46;
    u8 field47;
} nkm_area_entry_t;

SDK_COMPILER_ASSERT(sizeof(nkm_area_entry_t) == 0x48);

typedef struct
{
    nkm_section_header_t header;
    nkm_area_entry_t entries[0];
} nkm_area_t;

typedef enum
{
    NKM_CAME_TYPE_0,
    NKM_CAME_TYPE_1,
    NKM_CAME_TYPE_2,
    NKM_CAME_TYPE_INTRO_TOP,
    NKM_CAME_TYPE_INTRO_BOTTOM,
    NKM_CAME_TYPE_5,
    NKM_CAME_TYPE_6,
    NKM_CAME_TYPE_INTRO_MG,
    NKM_CAME_TYPE_MR_FINISH
} NKMCameType;

typedef enum
{
    NKM_CAME_FIRST_INTRO_NONE,
    NKM_CAME_FIRST_INTRO_TOP,
    NKM_CAME_FIRST_INTRO_BOTTOM
} NKMCameIntroFirst;

typedef struct
{
    VecFx32 position;
    VecFx32 rotation;
    VecFx32 target1;
    VecFx32 target2;
    u16 fovBegin;
    fx16 fovBeginSin;
    fx16 fovBeginCos;
    u16 fovEnd;
    fx16 fovEndSin;
    fx16 fovEndCos;
    s16 fovSpeed;
    u16 type; // NKMCameType
    s16 pathId;
    s16 routeSpeed;
    u16 targetSpeed;
    u16 duration;
    s16 next;
    u8 introFirst; ///< Indicates if this camera is the first camera of the top or bottom intro chain
    u8 unknown;
} nkm_came_entry_t;

SDK_COMPILER_ASSERT(sizeof(nkm_came_entry_t) == 0x4C);

typedef struct
{
    nkm_section_header_t header;
    nkm_came_entry_t entries[0];
} nkm_came_t;

typedef struct
{
    nkm_header_t header;
    nkm_obji_t obji;
} nkm_t;
