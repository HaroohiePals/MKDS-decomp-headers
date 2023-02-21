#pragma once

#include "nkm.h"
#include "race/raceConfig.h"

typedef struct mdat_clip_area_list_entry_t
{
    const nkm_area_entry_t* entry;
    struct mdat_clip_area_list_entry_t* next;
} mdat_clip_area_list_entry_t;

typedef struct
{
    const nkm_path_entry_t* path;
    nkm_poit_entry_t* poit;
} mdat_path_t;

typedef struct mdat_enemypoint_t
{
    struct mdat_enemypoint_t* next[3];
    struct mdat_enemypoint_t* previous[3];
    const VecFx32* position;
    fx32 radius;
    const nkm_epoi_entry_settings_t* settings;
    u16 nextCount;
    u16 previousCount;
} mdat_enemypoint_t;

typedef struct
{
    mdat_enemypoint_t* points;
    mdat_enemypoint_t* firstPoint;
    mdat_enemypoint_t* lastPoint;
} mdat_enemypath_data_t;

typedef struct mdat_mgenemypoint_t
{
    struct mdat_mgenemypoint_t* next[8];
    const VecFx32* position;
    fx32 radius;
    const nkm_mepo_entry_settings_t* settings;
    u16 nextCount;
    u8 nextIsNewPathMask;
} mdat_mgenemypoint_t;

typedef struct
{
    mdat_mgenemypoint_t* points;
    mdat_mgenemypoint_t* firstPoint;
    mdat_mgenemypoint_t* lastPoint;
} mdat_mgenemypath_data_t;

typedef struct mdat_itempoint_t
{
    struct mdat_itempoint_t* next[3];
    struct mdat_itempoint_t* previous[3];
    const VecFx32* position;
    fx32 radius;
    u8 recalcIdx;
    //direction vector to next[0] in 1.1.6 format
    s8 dirX;
    s8 dirY;
    s8 dirZ;
    u16 nextCount;
    u16 previousCount;
} mdat_itempoint_t;

typedef struct
{
    mdat_itempoint_t* points;
    mdat_itempoint_t* firstPoint;
    mdat_itempoint_t* lastPoint;
} mdat_itempath_data_t;

typedef struct
{
    const nkm_obji_entry_t* obji;
    u16 objiCount;
    const nkm_path_entry_t* path;
    u16 pathCount;
    nkm_poit_entry_t* poit;
    u16 poitCount;
    const nkm_stag_data_t* stag;
    const nkm_ktps_entry_t* ktps;
    u16 ktpsCount;
    const nkm_ktpj_entry_t* ktpj;
    u16 ktpjCount;
    const nkm_ktp2_entry_t* ktp2;
    u16 ktp2Count;
    const nkm_ktpc_entry_t* ktpc;
    u16 ktpcCount;
    const nkm_ktpm_entry_t* ktpm;
    u16 ktpmCount;
    const nkm_cpoi_entry_t* cpoi;
    u16 cpoiCount;
    nkm_cpat_entry_t* cpat;
    u16 cpatCount;
    nkm_ipoi_entry_pointer_t ipoi;
    u16 ipoiCount;
    const nkm_ipat_entry_t* ipat;
    u16 ipatCount;
    const nkm_epoi_entry_t* epoi;
    u16 epoiCount;
    const nkm_epat_entry_t* epat;
    u16 epatCount;
    const nkm_area_entry_t* area;
    u16 areaCount;
    const nkm_came_entry_t* came;
    u16 cameCount;
    const nkm_mepo_entry_t* mepo;
    u16 mepoCount;
    const nkm_mepa_entry_t* mepa;
    u16 mepaCount;
    mdat_path_t* paths;
    u16 cpoiKeyCount;
    u16 cpatLastCpoiIndex;
    u16 cpatMaxSectionOrder;
    u8 unknown49;
    u8 unknown50;
    mdat_enemypath_data_t enemyPathData;
    mdat_itempath_data_t itemPathData;
    mdat_mgenemypath_data_t mgEnemyPathData;
    const nkm_came_entry_t* cameIntroFirstTopCam;
    const nkm_came_entry_t* cameIntroFirstBottomCam;
    const nkm_came_entry_t* cameType6;
    const nkm_came_entry_t* cameBattleIntroCam;
    const nkm_came_entry_t* cameMissionFinishCam;
    mdat_clip_area_list_entry_t* clipAreaLists[8];
    u16* ktpjIndexTable;
    u16* ktpcIndexTable;
    u16 curMgRespawnId;
    u16 enemyRespawnRouteAreaCount;
    fx32 trackLength;
    u32 trackLengthDiv15000;
    u16 nkmVersion;
    u8 unknown141;
    u8 missionEndAreaCount;
} mdat_mapdata_t;

extern mdat_mapdata_t* gMapData;

void mdat_shuffleRespawns(MATHRandContext32* randomContext);
void mdat_init(NNSFndHeapHandle heapHandle);

static inline const nkm_ktpj_entry_t* nkm_getKtpjEntryById(u16 id)
{
    return &gMapData->ktpj[gMapData->ktpjIndexTable[id]];
}

static inline const nkm_ktpc_entry_t* nkm_getKtpcEntryByIndex(u16 index)
{
    return &gMapData->ktpc[index];
}

static inline const nkm_path_entry_t* nkm_getPathEntryByIndex(u16 index)
{
    return &gMapData->path[index];
}

static inline const nkm_cpoi_entry_t* nkm_getCpoiEntryByIndex(u16 index)
{
    return &gMapData->cpoi[index];
}

static inline nkm_cpat_entry_t* nkm_getCpatEntryByIndex(u16 index)
{
    return &gMapData->cpat[index];
}

const nkm_area_entry_t* mdat_getAreaEntryByIndex(u16 index);

// static inline nkm_area_entry_t* nkm_getAreaEntryByIndex(u16 index)
// {
// 	return &gNkmRtData->area[index];
// }

mdat_path_t* mdat_getPath(u16 index);
//static inline nkm_route_combination_t* nkm_getRouteCombination(int index)
//{
//	return &gNkmRtData->routeCombinations[index];
//}

// static inline nkm_poit_entry_t* nkm_getPoitOnPath(u16 path, u16 poit)
// {
// 	return &nkm_getRouteCombination(path)->poit[poit];
// }

static inline mdat_itempoint_t* nkm_getIpoiRtDataByIndex(u16 index)
{
    return &gMapData->itemPathData.points[index];
}

static inline const nkm_epat_entry_t* nkm_getEpatEntryByIndex(u16 index)
{
    return &gMapData->epat[index];
}

static inline mdat_enemypoint_t* nkm_getEpoiRtDataByIndex(u16 index)
{
    return &gMapData->enemyPathData.points[index];
}

static inline const nkm_mepo_entry_t* nkm_getMepoEntryByIndex(u16 index)
{
    return &gMapData->mepo[index];
}

static inline mdat_mgenemypoint_t* nkm_getMepoRtDataByIndex(u16 index)
{
    return &gMapData->mgEnemyPathData.points[index];
}

static inline u16 mdat_getKtpcIdxFromId(u16 id)
{
    return gMapData->ktpcIndexTable[id];
}

static inline void mdat_getKtpcPosition(u16 idx, VecFx32* dst)
{
    dst->x = gMapData->ktpc[idx].position.x;
    dst->y = gMapData->ktpc[idx].position.y;
    dst->z = gMapData->ktpc[idx].position.z;
}

static inline void mdat_getKtpcRotation(u16 idx, VecFx32* dst)
{
    dst->x = gMapData->ktpc[idx].rotation.x;
    dst->y = gMapData->ktpc[idx].rotation.y;
    dst->z = gMapData->ktpc[idx].rotation.z;
}

static inline void mdat_getKtpmPosition(u16 idx, VecFx32* dst)
{
    *dst = gMapData->ktpm[idx].position;
}

static inline void mdat_getKtpmRotation(u16 idx, VecFx32* dst)
{
    *dst = gMapData->ktpm[idx].rotation;
}

static inline s16 mdat_getKtpmId(u16 idx)
{
    return gMapData->ktpm[idx].id;
}

static inline const nkm_came_entry_t* nkm_getCameEntryByIndex(u16 index)
{
    return &gMapData->came[index];
}

static inline fx32 nkm_areaGetLengthVecHalfScale()
{
    return FX32_CONST(50);
}

static inline fx32 nkm_areaGetLengthVecScale()
{
    return FX32_CONST(100);
}

int nkm_getNrLaps();
