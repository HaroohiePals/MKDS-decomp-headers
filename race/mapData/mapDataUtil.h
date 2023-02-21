#pragma once
#include "mapData.h"

nkm_poit_entry_t* mdat_getPathPoint(u16 path, u16 poit);
void mdat_getStartPosition(VecFx32* position, VecFx32* rotation, u16 player);
BOOL mdat_isPointInsideArea(const VecFx32* pPoint, const nkm_area_entry_t* area);
BOOL mdat_isInsideMissionEndArea(const VecFx32* pPoint, BOOL* arg2);
mdat_enemypoint_t* mdat_findEnemyPoint(const VecFx32* pPoint);
mdat_mgenemypoint_t* mdat_findMgEnemyPoint(const VecFx32* pPoint);
int mdat_findCameraId(const VecFx32* pPoint);
u16 mdat_getRespawnId(u16 cpoi);
mdat_enemypoint_t* mdat_getRespawnData(u16 respawnId, VecFx32* pPos, VecFx32* pRot);
mdat_mgenemypoint_t* mdat_getMgRespawnData(u16 respawnId, VecFx32* pPos, VecFx32* pRot);
mdat_itempoint_t* mdat_getItemPointForRespawn(u16 respawnId);
BOOL mdat_isDriverInClipArea(u16 driverId, int clipAreaId);
mdat_mgenemypoint_t* mdat_getNextMgEnemyPointForWarpPipe(int cannonId);