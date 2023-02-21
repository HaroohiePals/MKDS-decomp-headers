#pragma once
#include "race/raceConfig.h"
#include "race/items/item.h"
#include "race/mapData/mapData.h"
#include "race/drivers/driver.h"

typedef enum
{
    MGCNT_DRIVER_STATE_ALIVE,
    MGCNT_DRIVER_STATE_DYING,
    MGCNT_DRIVER_STATE_DEAD
} MgcntDriverState;

typedef struct
{
    u32 field0;
    u32 field4;
    MgcntDriverState state;
    VecFx32 position;
    s32 field18;
    s32 field1C;
    u32 field20;
    u32 field24[RACE_DRIVER_COUNT_MAX];
    u16 field44;
    u16 mgDriverTeamId;
    u16 place;
    int balloonShineCount;
    u16 balloonShineInventoryCount;
    u8 gap52[0x64 - 0x52];
    s32 micInflatingCounter;
    s32 keyInflating;
    BOOL isInflating;
} mgcnt_driver_t;

typedef BOOL (*mgcnt_try_steal_balloon_func_t)(u16 driverId1, u16 driverId2);
typedef void (*mgcnt_field384_func_t)(u16 driverId1, u16 driverId2);
typedef BOOL (*mgcnt_on_damage_func_t)(u16 driverId1, u16 driverId2);
typedef void (*mgcnt_on_kill_func_t)(u16 driverId);
typedef void (*mgcnt_on_end_func_t)();
typedef void (*mgcnt_apply_force_to_driver_balloons_func_t)(u16 driverId, const VecFx32* force);

typedef struct
{
    mgcnt_driver_t drivers[RACE_DRIVER_COUNT_MAX];
    mgcnt_try_steal_balloon_func_t tryStealBalloonFunc;
    mgcnt_field384_func_t field384;
    mgcnt_on_damage_func_t onDamageFunc;
    mgcnt_on_kill_func_t onKillFunc;
    mgcnt_on_end_func_t onEndFunc;
    u8 gap394[0x39C - 0x394];
    mgcnt_apply_force_to_driver_balloons_func_t applyForceToDriverBalloonsFunc;
    u16 collectableShineCount;
    u16 timeLimit;
    u16 shineRunnersRound;
    s32 mgEndDelayCounter;
    int maxOwnedShineCount;
    int minOwnedShineCount;
    s32 winDriverTeamId;
    u16 lastShineMepoIdx;
    void* blncntDriverEntries;
} mgcnt_t;

fx32 mgcnt_20A23A0(const driver_t* driver);
void mgcnt_setBlncntDriverEntries(/*balloon_controller_entry_t*/void* entries);
/*balloon_controller_entry_t*/
void* mgcnt_getBlncntDriverEntries();
void mgcnt_setTryStealBalloonFunc(mgcnt_try_steal_balloon_func_t func);
void mgcnt_setField384(mgcnt_field384_func_t func);
void mgcnt_setOnDamageFunc(mgcnt_on_damage_func_t func);
void mgcnt_setOnKillFunc(mgcnt_on_kill_func_t func);
void mgcnt_setOnEndFunc(mgcnt_on_end_func_t func);
void mgcnt_setApplyForceToDriverBalloonsFunc(mgcnt_apply_force_to_driver_balloons_func_t func);
void mgcnt_driverInflateBalloonByMic(u16 driverId);
void mgcnt_driverStopInflateBalloonByMic(u16 driverId);
int mgcnt_getDriverMicInflatingCounter(u16 driverId);
int mgcnt_getDriverKeyInflating(u16 driverId);
void mgcnt_setDriverIsInflating(u16 driverId, BOOL isInflating);
BOOL mgcnt_getDriverIsInflating(u16 driverId);
void mgcnt_applyForceToDriverBalloons(u16 driverId, const VecFx32* force);
BOOL mgcnt_handleDriverDriverCollide(u16 driverId1, u16 driverId2);
void mgcnt_20A1E40(u16 driverId, it_item_inst_t* item);
void mgcnt_notifyStarInvincibilityStart(u16 driverId);
void mgcnt_20A1DDC(u16 driverId);
u16 mgcnt_20A1CD8(u16 driverId);
BOOL mgcnt_20A1748(u16 driverId);
void mgcnt_resetDriverState(u16 driverId);
void mgcnt_killDriver(u16 driverId) ATTRIBUTE_NEVER_INLINE;
int mgcnt_handleShineRunnersTimeUp();
void mgcnt_tryFinish();
BOOL mgcnt_hasMgEnded();
BOOL mgcnt_hasWinnerBeenDecided();
u16 mgcnt_getDriverPlace(u16 driverId);
u16 mgcnt_getCollectableShineCount();
void mgcnt_updateCollectableShineCount(int delta);
u16 mgcnt_getTotalOwnedShineCount();
u16 mgcnt_getMaxOwnedShineCount();
u16 mgcnt_getDriverBalloonShineCount(u16 driverId);
void mgcnt_updateDriverBalloonShineCount(u16 driverId, int delta);
u16 mgcnt_getDriverBalloonShineInventoryCount(u16 driverId);
void mgcnt_updateDriverBalloonShineInventoryCount(u16 driverId, int delta);
BOOL mgcnt_isDriverDead(u16 driverId);
BOOL mgcnt_isDriverShineCountLow(u16 driverId);
BOOL mgcnt_hasDriverWon(u16 driverId);
const VecFx32* mgcnt_getDriverPosition(u16 driverId);
const nkm_mepo_entry_t* mgcnt_getRandomShineMepo();
void mgcnt_init();
void mgcnt_forceEnd();
void mgcnt_update();