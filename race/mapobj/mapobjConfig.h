#pragma once
#include "mapobjInstance.h"
#include "race/drivers/driver.h"
#include "race/items/item.h"

typedef enum
{
    MOBJ_COLLISION_TYPE_NONE,
    MOBJ_COLLISION_TYPE_SPHERE,
    MOBJ_COLLISION_TYPE_SPHEROID,
    MOBJ_COLLISION_TYPE_CYLINDER,
    MOBJ_COLLISION_TYPE_BOX,
    MOBJ_COLLISION_TYPE_CUSTOM
} MObjCollisionType;

typedef u32 (*mobj_config_driver_collide_func_t)(mobj_inst_t* instance, driver_t* driver, u8* objResp, u8* driverResp);
typedef u32 (*mobj_config_item_collide_func_t)(mobj_inst_t* instance, it_item_inst_t* item, u8* objResp, u8* itemResp);
typedef BOOL (*mobj_config_sphere_collide_func_t)(
    mobj_inst_t* instance, const VecFx32* position, fx32 sphereSize, VecFx32* pushback);

typedef struct mobj_config_t
{
    mobj_config_driver_collide_func_t driverCollideFunc;
    mobj_config_item_collide_func_t itemCollideFunc;
    MObjCollisionType colType;
    VecFx32 size;
    mobj_config_sphere_collide_func_t sphereCollideFunc;
    BOOL providesPushback;
    u32 logicType;
    s32 driverHitSfxId;
    u32 itemHitSfxId;
    fx32 nearClip;
    fx32 farClip;
    BOOL has3DModel;
    fx32 sfxAudibleMaxCamYDiff;
    fx32 sfxAudibleMinCamYDiff;
} mobj_config_t;
