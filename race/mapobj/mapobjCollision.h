#pragma once
#include "race/items/item.h"
#include "mapobj.h"

u32 mobj_getDriverHitResponse(BOOL useSimpleHitResp, int collisionMode, MObjGroup objGroup, int objIdx);
u32 mobj_getItemHitObjResponse(BOOL useSimpleHitResp, MKDSItem itemType, MObjGroup objGroup, int objIdx);
u32 mobj_getItemHitResponse(BOOL useSimpleHitResp, MKDSItem itemType, MObjGroup objGroup, int objIdx, BOOL a5);
u32 mobj_handleDriverCollision(driver_t* driver, mobj_inst_t* mobj);
u32 mobj_handleItemCollision(it_item_inst_t* item, mobj_inst_t* mobj, u32* objRespOut);
BOOL mobj_getCollidesWithDriver(int collisionMode, mobj_inst_t* mobj);
BOOL mobj_getCollidesWithItem(MKDSItem itemType, mobj_inst_t* mobj);
u32 mobj_getItemHitObjResponseForMObj(MKDSItem itemType, mobj_inst_t* mobj);