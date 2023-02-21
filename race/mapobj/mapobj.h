#pragma once

#include "race/mapData/nkm.h"
#include "mapobjInstance.h"
#include "mapobjRenderPart.h"
#include "mapobjLogicPart.h"
#include "mapobjConfig.h"
#include "mapobjIds.h"
#include "mapobjSetupUtil.h"
#include "mapobjUtil.h"

typedef void (*mobj_inst_init_func_t)(mobj_inst_t* instance, const nkm_obji_entry_t* objiEntry, void* arg);
typedef mobj_config_t* (*mobj_config_setup_func_t)();
typedef mobj_render_part_t* (*mobj_render_part_setup_func_t)();
typedef mobj_logic_part_t* (*mobj_logic_part_setup_func_t)();

typedef struct
{
    u16 instanceCount;
    u32 instanceSize;

    mobj_inst_init_func_t instInitFunc;
    mobj_config_setup_func_t configSetupFunc;
    mobj_render_part_setup_func_t renderPartSetupFuncs[3];
    mobj_logic_part_setup_func_t logicPartSetupFunc;
    mobj_config_t* config;
    mobj_render_part_t* renderParts[3];
    mobj_logic_part_t* logicPart;
} mobj_def_t;

typedef struct
{
    u32 id;
    mobj_def_t* def;
    void* arg;
} mobj_table_entry_t;

#define MOBJ_RENDER_PART_MAX_COUNT      24
#define MOBJ_LOGIC_PART_MAX_COUNT       16

typedef struct
{
    mobj_inst_t** mobjInstanceList;
    u16 mobjInstanceCount;
    mobj_render_part_t* renderPartList[MOBJ_RENDER_PART_MAX_COUNT];
    mobj_render_part_t* renderPart3dList[MOBJ_RENDER_PART_MAX_COUNT];
    mobj_render_part_t* renderPart2dList[MOBJ_RENDER_PART_MAX_COUNT];
    u16 renderPartCount;
    u16 renderPart3dCount;
    u16 renderPart2dCount;
    u32 field130;
    mobj_logic_part_t* logicPartList[MOBJ_LOGIC_PART_MAX_COUNT];
    u16 logicPartCount;
    u32 field178;
    BOOL hasKoopaBlock;
    BOOL hasRotatingCylinder;
    BOOL hasBridge;
    BOOL hasWall;
    it_item_inst_t pseudoItem;
    BOOL logicUpdateEnabled;
} mobj_state_t;

struct water_state_t;
struct water_splash_state_t;
struct camera_t;

extern mobj_state_t* gMapObjState;
extern struct water_splash_state_t* gMObjSplashState;
extern struct water_state_t* gMObjWaterState;

int mobj_collideDriver(driver_t* driver, const VecFx32* position, VecFx32* pushback);
int mobj_queryBySphere(const VecFx32* position, fx32 sphereSize, MObjId objectId);
mobj_inst_t* mobj_getQueryResult(int idx);
const VecFx32* mobj_getQueryPushback(int idx);
BOOL mobj_sphereCollide(const VecFx32* position, fx32 sphereSize, mobj_inst_t* instance, VecFx32* pushback);
BOOL mobj_getHasWater();
fx32 mobj_getWaterPlaneDistance2(fx32 y);
fx32 mobj_getWaterTideProgress();
u16 mobj_getWaterTidePhase();
BOOL mobj_getHasDiveableWater();
fx32 mobj_getWaterPlaneDistance1(fx32 y);
BOOL mobj_20D3D10(fx32 y);
void mobj_executeAllThunderLogic();
int mobj_collideAsItem(mobj_inst_t* mobj, MKDSItem itemType, VecFx32* pushBack);
void mobj_enableLogicUpdates();
u16 mobj_getCyclicPolygonId();
u16 mobj_getStaticPolygonId();
u16 mobj_getInstanceCountWithId(MObjId objectId);
void mobj_deactivateObjsBeforeCountdown();
void mobj_activateObjsAfterCountdown();
mobj_inst_t* mobj_createObject(MObjId objectId, const nkm_obji_entry_t* obji, mobj_inst_t* parentMObj);
mobj_inst_t* mobj_createSubObject(mobj_inst_t* parentMObj, MObjId objectId);
mobj_inst_t* mobj_createObjectFromObji(const nkm_obji_entry_t* obji, MObjId objectId);
void mobj_init();
void mobj_finalize();
u32 mobj_collideAsItemDirect(
    const VecFx32* position, const VecFx32* velocity, fx32 sphereSize, s16 colEntryId, MKDSItem itemType,
    VecFx32* pushback);
int mobj_getAvailableObjectCount();
void* mobj_getWaterEffectNsbmd();
void* mobj_getWaterEffectNsbca();
void* mobj_getWaterEffectNsbma();

void mobj_setWaterStatePointer(struct water_state_t* waterState);
void mobj_setSplashStatePointer(struct water_splash_state_t* splash);
void mobj_updateAll();
void mobj_renderAll(const struct camera_t* camera);
void mobj_renderDColObjects(const struct camera_t* camera);

mobj_logic_part_t* mobj_getLogicPartForObjectId(MObjId objectId);

typedef struct
{
    fx32 value;
    fx32 velocity;
    BOOL reverse;
} idk_struct_t;

static inline void idk_update(idk_struct_t* idk, fx32 acceleration, fx32 max)
{
    idk->value += idk->velocity;
    idk->velocity += acceleration;
    if (idk->value == 0)
    {
        idk->value += idk->velocity;
        idk->velocity += acceleration;
    }
    else if (idk->value >= max)
    {
        idk->velocity = acceleration - idk->velocity;
        idk->reverse = !idk->reverse;
    }
}

typedef struct
{
    fx32 value;
    fx32 velocity;
    fx32 min;
    fx32 max;
} idk_struct2_t;

static inline void idk2_init(idk_struct2_t* idk, fx32 fieldFC, fx32 field100, fx32 field104, fx32 field108)
{
    idk->value = fieldFC;
    idk->velocity = field100;
    idk->min = field104;
    idk->max = field108;
}

static inline void idk2_update(idk_struct2_t* idk)
{
    idk->value += idk->velocity;
    if (idk->value >= idk->max)
    {
        idk->velocity = -idk->velocity;
        idk->value = 2 * idk->max - idk->value;
    }
    else if (idk->value <= idk->min)
    {
        idk->velocity = -idk->velocity;
        idk->value = 2 * idk->min - idk->value;
    }
}
