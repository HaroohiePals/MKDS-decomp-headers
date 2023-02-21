#pragma once
#include "race/mapData/mapData.h"

typedef struct driver_t driver_t;

typedef struct
{
    int field0;
    int driverFieldCC;
    int rivalAggressiveness;
    int maxDriverFieldCC;
    int field10;
    int place;
    int field18;
    int field1C;
    int field20;
    int field24;
    BOOL hasFailedStart;
    BOOL hasStartBoost;
    u16 startBoostAmount;
    u16 field32;
} enemy_rubberbanding_t;

typedef struct
{
    void* updateFunc;
    int field4;
    u16 minTimeout;
    u16 timeoutRandomMax;
} enemy_item_params_t;


typedef struct
{
    u16 slotItemTimeout;
    u16 dragItemTimeout;
    enemy_item_params_t* slotItemParams;
    enemy_item_params_t* dragItemParams;
    int fieldC;
    int lxPressed;
    int dpadUpPressed;
    int dpadDownPressed;
    u16 dpadUpCounter;
    u16 dpadDownCounter;
    int field20;
} enemy_item_state_t;


typedef struct
{
    int field0;
    int driverFieldCC;
    int field8;
    int fieldC;
    int field10;
} enemy_field140_t;

typedef struct
{
    mdat_enemypoint_t* nextEpoi;
    mdat_enemypoint_t* curEpoi;
    VecFx32 direction;
    mdat_enemypoint_t* areaEpoi;
    BOOL areaEpoiValid;
    u16 driverId;
    u8 field1E;
    u8 field1F;
} struc_316_epoi;

typedef struct
{
    mdat_mgenemypoint_t* nextMepo;
    mdat_mgenemypoint_t* curMepo;
    VecFx32 direction;
    mdat_mgenemypoint_t* areaMepo;
    BOOL areaMepoValid;
} struc_313_mepo;


typedef struct
{
    driver_t* driver;
    u16 driverId;
    u16 field6;
    struc_316_epoi epoi;
    struc_313_mepo mepo;
    VecFx32 targetPos;
    VecFx32 field50;
    VecFx32* field5C;
    VecFx32 driftOffset;
    u16 driftEpoiRadiusScaleUpdateCounter;
    u16 driftEpoiRadiusScaleUpdateFrames;
    int field70;
    fx32 driftEpoiRadiusScale;
    u16 field78;
    u16 field7A;
    int field7C;
    u16 field80;
    int field84;
    int field88;
    int field8C;
    int driftState;
    int driftDirection;
    int field98;
    int field9C;
    int fieldA0;
    int fieldA4;
    int fieldA8;
    u16 fieldAC;
    driver_t* targetDriver;
    int fieldB4;
    int fieldB8;
    int fieldBC;
    u16 targetBalloonCount;
    u16 balloonInflateMicTimeout;
    int isInflatingBalloon;
    u16 fieldC8;
    u16 fieldCA;
    int fieldCC;
    // shine16_t* targetShine;
    void* targetShine;
    u16 shineIdx;
    int fieldD8;
    VecFx32 fieldDC;
    enemy_rubberbanding_t rubberbanding;
    enemy_item_state_t itemState;
    enemy_field140_t field140;
    int field154;
} enemy_t;

void enmy_setupFunctions();
void enmy_init(enemy_t* enemy, u16 driverId);
void enmy_208C23C(enemy_t* enemy, void* enemyPoint);
void enmy_update(enemy_t* enemy);
void enmy_recalculatePath(enemy_t* enemy);
void enmy_getTargetPosDir(VecFx32* position, VecFx32* direction, const enemy_t* enemy);
void enmy_notifySlotItemChanged(enemy_t* enemy);
void enmy_notifyDragItemChanged(enemy_t* enemy);
BOOL enmy_getHasFailedStart(const enemy_t* enemy);
BOOL enmy_getHasStartBoost(const enemy_t* enemy);
u16 enmy_getStartBoostAmount(const enemy_t* enemy);