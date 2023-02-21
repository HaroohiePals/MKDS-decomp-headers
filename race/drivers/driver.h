#pragma once
#include "sfx.h"
#include "charKart.h"
#include "math/quaternion.h"
#include "math/vector.h"
#include "physicalParams.h"
#include "input/input.h"
#include "enemy.h"
#include "race/struc_351.h"

typedef struct mobj_inst_t mobj_inst_t;

typedef enum
{
    DRIVER_COLLISION_MODE_NORMAL,
    DRIVER_COLLISION_MODE_STAR, //invincible
    DRIVER_COLLISION_MODE_TERESA, //invisible
    DRIVER_COLLISION_MODE_KILLER,

    DRIVER_COLLISION_MODE_COUNT
} DriverCollisionMode;

typedef enum
{
    DRIVER_COLLISION_REACTION_NONE,
    DRIVER_COLLISION_REACTION_1,
    DRIVER_COLLISION_REACTION_SPIN_OUT,
    DRIVER_COLLISION_REACTION_FORWARD_FLIP,
    DRIVER_COLLISION_REACTION_BACKWARD_FLIP,
    DRIVER_COLLISION_REACTION_DOUBLE_BACKWARD_FLIP,
    DRIVER_COLLISION_REACTION_THROW_UP,

    DRIVER_COLLISION_REACTION_COUNT
} DriverCollisionReaction;

typedef enum
{
    DRIVER_COLLISION_TYPE_ROAD,
    DRIVER_COLLISION_TYPE_1,
    DRIVER_COLLISION_TYPE_WEAK_OFF_ROAD,
    DRIVER_COLLISION_TYPE_OFF_ROAD,
    DRIVER_COLLISION_TYPE_HEAVY_OFF_ROAD,
    DRIVER_COLLISION_TYPE_SLIPPERY_ROAD_1,
    DRIVER_COLLISION_TYPE_SLIPPERY_ROAD_2,
    DRIVER_COLLISION_TYPE_7,
    DRIVER_COLLISION_TYPE_BOOST, //both boost and jump pads
    DRIVER_COLLISION_TYPE_CANNON_ACTIVATOR,
    DRIVER_COLLISION_TYPE_FALLS_WATER,
    DRIVER_COLLISION_TYPE_LOOPING,

    DRIVER_COLLISION_TYPE_COUNT
} DriverCollisionType;

typedef enum
{
    DRIVER_VOICE_TYPE_SPIN,
    DRIVER_VOICE_TYPE_OT,
    DRIVER_VOICE_TYPE_OT1,
    DRIVER_VOICE_TYPE_OT2,
    DRIVER_VOICE_TYPE_OT3,
    DRIVER_VOICE_TYPE_STARTDASH,
    DRIVER_VOICE_TYPE_STARTDASH_OT,
    DRIVER_VOICE_TYPE_ATTACK,
    DRIVER_VOICE_TYPE_JOY,
    DRIVER_VOICE_TYPE_GOAL1,
    DRIVER_VOICE_TYPE_GOAL23,
    DRIVER_VOICE_TYPE_GOAL48,
    DRIVER_VOICE_TYPE_MG_WIN,
    DRIVER_VOICE_TYPE_MG_LOSE
} DriverVoiceType;

typedef struct
{
    BOOL gotStartBoost;
    u32 powerSlideCount;
    int itemHitCount;
    u32 offRoadTime;
    int wallHitCount;
    int damageCount;
    int respawnCount;
} driver_statistics_t;

typedef struct
{
    s16 shroomBoostTimer;
    s16 thunderShrinkTimer;
    s16 thunderGrowTimer;
    s16 starTimer;
    s16 slipstreamStartTimer;
    s16 slipstreamTimer;
    s16 dossunGrowTimer;
    s16 dossunFlatTimer;
    s16 teresaTimer;
    s16 teresaFlickerInterval;
    s16 teresaFlickerIntervalUpdateTimer;
    s16 teresaFlickerTimer;
    s16 teresaFlickerIntervalUpdateWaitTime;
    s16 teresaFlickerIntervalStep;
    s16 gessoInkTimer;
    s16 killerFrameCounter;
    u16 field20;
    BOOL isKillerFinishing;
    s16 killerTargetPlace;
    u8 gap2A[2];
    u8 killerState[0x590 - 0x564];
} driver_timers_t;

typedef struct
{
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;
} struc_334;

typedef struct
{
    int field0;
    u8 field4;
    fx32 field8;
    int fieldC;
    int field10;
    int field14;
    fx32 field18;
    fx32 field1C;
    fx32 field20;
    fx32 field24;
    int prevLapProgress;
    u8 kaidanSfxAlternateCounter;
    int field30;
    int field34;
    int sfxId;
    int (*computePitchOffsetFunc)(sfx_emitter_ex_params_t*);
    struc_334 field40;
    int field68;
} driver_field450_t;

typedef struct
{
    NNSFndLink link;
    s16 field8;
    u8 gapA[2];
    struc_351 fieldC;
} driver_field514_field8C_entry_t;

#define DRIVER_NET_FLAGS_MINI_JUMP                    (1 << 0)
#define DRIVER_NET_FLAGS_SINGLE_SPINOUT_START         (1 << 2)
#define DRIVER_NET_FLAGS_DOUBLE_SPINOUT_START         (1 << 3)
#define DRIVER_NET_FLAGS_FORWARD_FLIP_START           (1 << 4)
#define DRIVER_NET_FLAGS_SINGLE_BACKWARD_FLIP_START   (1 << 5)
#define DRIVER_NET_FLAGS_DOUBLE_BACKWARD_FLIP_START   (1 << 6)
#define DRIVER_NET_FLAGS_BIT7                         (1 << 7)
#define DRIVER_NET_FLAGS_BIT9                         (1 << 9)
#define DRIVER_NET_FLAGS_BIT10                        (1 << 10)
#define DRIVER_NET_FLAGS_BIT11                        (1 << 11)
#define DRIVER_NET_FLAGS_BIT12                        (1 << 12)
#define DRIVER_NET_FLAGS_STAR_INVINCIBLE_START        (1 << 13)
#define DRIVER_NET_FLAGS_THUNDER_INVOKE               (1 << 14)
#define DRIVER_NET_FLAGS_THUNDER_SHRINK_START         (1 << 15)
#define DRIVER_NET_FLAGS_BIT16                        (1 << 16)
#define DRIVER_NET_FLAGS_THROW_UP_START               (1 << 17)
#define DRIVER_NET_FLAGS_SLIPSTREAM_START             (1 << 18)
#define DRIVER_NET_FLAGS_GESSO_INK_START              (1 << 19)
#define DRIVER_NET_FLAGS_KILLER_START                 (1 << 20)
#define DRIVER_NET_FLAGS_KILLER_FINISH                (1 << 21)
#define DRIVER_NET_FLAGS_BIT22                        (1 << 22)
#define DRIVER_NET_FLAGS_BIT23                        (1 << 23)
#define DRIVER_NET_FLAGS_BIT24                        (1 << 24)
#define DRIVER_NET_FLAGS_BIT25                        (1 << 25)
#define DRIVER_NET_FLAGS_TERESA_START                 (1 << 26)

#define DRIVER_NET_FLAGS_BIT29_30                     (3 << 29)

typedef struct
{
    VecFx32 position;
    u16 fieldC;
    u16 fieldE;
    VecFx32 field10;
    int field1C;
    int field20;
    fx32 field24;
    int field28;
    int flags;
    int lastFlags;
    VecFx32 field34;
    s16 driftRotY;
    int field44;
    u32 field48;
    quaternion_t field4C;
    s16 field5C;
    int field60;
    int field64;
    u8 gap68[24];
    NNSFndList field80;
    NNSFndList field8C;
    VecFx32 field98;
    u32 fieldA4;
    VecFx32 fieldA8;
    u16 fieldB4;
    u8 gapB6[1];
    u8 fieldB7;
} driver_net_state_t;

#define DRIVER_FIELD44_BIT0                     (1 << 0)
#define DRIVER_FIELD44_BIT1                     (1 << 1)
#define DRIVER_FIELD44_BIT2                     (1 << 2)
#define DRIVER_FIELD44_IS_DRIFTING              (1 << 3)
#define DRIVER_FIELD44_IS_ON_FLOOR              (1 << 4)
#define DRIVER_FIELD44_IS_TOUCHING_DRIVER       (1 << 5)
#define DRIVER_FIELD44_IS_TOUCHING_MOBJ_WALL    (1 << 6)
#define DRIVER_FIELD44_IS_TOUCHING_WALL         (1 << 7)
#define DRIVER_FIELD44_IS_GOING_BACKWARDS       (1 << 8)
#define DRIVER_FIELD44_BIT9                     (1 << 9)
#define DRIVER_FIELD44_BIT10                    (1 << 10)
#define DRIVER_FIELD44_BIT11                    (1 << 11)
#define DRIVER_FIELD44_BIT12                    (1 << 12)
#define DRIVER_FIELD44_BIT13                    (1 << 13)
#define DRIVER_FIELD44_BIT14                    (1 << 14)
#define DRIVER_FIELD44_BIT15                    (1 << 15)
#define DRIVER_FIELD44_BIT16                    (1 << 16)
#define DRIVER_FIELD44_BIT18                    (1 << 18)
#define DRIVER_FIELD44_BIT19                    (1 << 19)
#define DRIVER_FIELD44_IS_ON_FALLS_WATER        (1 << 20)
#define DRIVER_FIELD44_BIT21                    (1 << 21)
#define DRIVER_FIELD44_BIT23                    (1 << 23)
#define DRIVER_FIELD44_BIT24                    (1 << 24)
#define DRIVER_FIELD44_BIT26                    (1 << 26)
#define DRIVER_FIELD44_BIT27                    (1 << 27)
#define DRIVER_FIELD44_BIT28                    (1 << 28)
#define DRIVER_FIELD44_BIT29                    (1 << 29)
#define DRIVER_FIELD44_BIT30                    (1 << 30)
#define DRIVER_FIELD44_BIT31                    (1 << 31)

#define DRIVER_FLAGS_IN_LOOP                (1 << 0)
#define DRIVER_FLAGS_A_BUTTON               (1 << 1)
#define DRIVER_FLAGS_B_BUTTON               (1 << 2)
#define DRIVER_FLAGS_DPAD_LEFT              (1 << 3)
#define DRIVER_FLAGS_DPAD_RIGHT             (1 << 4)
#define DRIVER_FLAGS_BOOST                  (1 << 5)
#define DRIVER_FLAGS_RESPAWNING             (1 << 6)
#define DRIVER_FLAGS_WHEELSPINNING          (1 << 7)
#define DRIVER_FLAGS_BIT8                   (1 << 8)
#define DRIVER_FLAGS_BIT9                   (1 << 9)
#define DRIVER_FLAGS_BIT10                  (1 << 10)
#define DRIVER_FLAGS_BIT11                  (1 << 11)
#define DRIVER_FLAGS_BIT12                  (1 << 12)
#define DRIVER_FLAGS_FORCE_STOP             (1 << 13)
#define DRIVER_FLAGS_BIT14                  (1 << 14)
#define DRIVER_FLAGS_START_BOOST            (1 << 15)
#define DRIVER_FLAGS_CANNON                 (1 << 16)
#define DRIVER_FLAGS_BIT17                  (1 << 17)
#define DRIVER_FLAGS_BIT18                  (1 << 18)
#define DRIVER_FLAGS_DRIFT_BOOST            (1 << 19)
#define DRIVER_FLAGS_SHROOM_BOOST           (1 << 20)
#define DRIVER_FLAGS_SFX_TRIGGER_HANDLED    (1 << 21)
#define DRIVER_FLAGS_MIN_SPEED_BOOST        (1 << 22)
#define DRIVER_FLAGS_WATER_RESPAWN          (1 << 23)
#define DRIVER_FLAGS_YOUGAN_RESPAWN         (1 << 24) //lava
#define DRIVER_FLAGS_RESPAWN_START          (1 << 25)
#define DRIVER_FLAGS_DOSSUN_SMASH_CAM       (1 << 26)
#define DRIVER_FLAGS_BIT27                  (1 << 27)
#define DRIVER_FLAGS_ON_JUMP_PAD            (1 << 28)
#define DRIVER_FLAGS_BIT29                  (1 << 29)
#define DRIVER_FLAGS_ANTIGRAVITY_CAM        (1 << 30)
#define DRIVER_FLAGS_BIT31                  (1 << 31)

#define DRIVER_FLAGS2_BIT0                  (1 << 0)
#define DRIVER_FLAGS2_BIT1                  (1 << 1)
#define DRIVER_FLAGS2_BIT3                  (1 << 3)
#define DRIVER_FLAGS2_BIT4                  (1 << 4)
#define DRIVER_FLAGS2_SPIN_OUT              (1 << 5)
#define DRIVER_FLAGS2_STAR_INVINCIBLE       (1 << 6)
#define DRIVER_FLAGS2_THUNDER_SHRINK        (1 << 7)
#define DRIVER_FLAGS2_GROWING               (1 << 8)
#define DRIVER_FLAGS2_BIT10                 (1 << 10)
#define DRIVER_FLAGS2_BIT11                 (1 << 11)
#define DRIVER_FLAGS2_BIT12                 (1 << 12)
#define DRIVER_FLAGS2_SLIPSTREAM_FULL       (1 << 13)
#define DRIVER_FLAGS2_SLIPSTREAM_BEGIN      (1 << 14)
#define DRIVER_FLAGS2_BIT15                 (1 << 15)
#define DRIVER_FLAGS2_DOSSUN_FLAT           (1 << 16)
#define DRIVER_FLAGS2_GESSO_INK_FADING_OUT  (1 << 17)
#define DRIVER_FLAGS2_BIT18                 (1 << 18)
#define DRIVER_FLAGS2_BIT20                 (1 << 20)
#define DRIVER_FLAGS2_BIT21                 (1 << 21)
#define DRIVER_FLAGS2_BIT22                 (1 << 22)
#define DRIVER_FLAGS2_BIT23                 (1 << 23)
#define DRIVER_FLAGS2_BIT25                 (1 << 25)
#define DRIVER_FLAGS2_BIT26                 (1 << 26)
#define DRIVER_FLAGS2_GESSO_INK             (1 << 27)
#define DRIVER_FLAGS2_KILLER_MODE           (1 << 28)
#define DRIVER_FLAGS2_START_FAILURE         (1 << 29)
#define DRIVER_FLAGS2_FALLS_WATER           (1 << 30)
#define DRIVER_FLAGS2_BIT31                 (1 << 31)

#define DRIVER_FIELD7C_IS_PLAYER            (1 << 0)
#define DRIVER_FIELD7C_IS_ENEMY             (1 << 1)
#define DRIVER_FIELD7C_IS_GHOST             (1 << 2)
#define DRIVER_FIELD7C_BIT3                 (1 << 3)
#define DRIVER_FIELD7C_CHAR_HAS_NSBCA_ANIM  (1 << 4)
#define DRIVER_FIELD7C_IS_BEING_KILLED      (1 << 5)
#define DRIVER_FIELD7C_IS_KILLED            (1 << 6)
#define DRIVER_FIELD7C_BIT7                 (1 << 7)
#define DRIVER_FIELD7C_BIT8                 (1 << 8)
#define DRIVER_FIELD7C_IS_NET_PLAYER        (1 << 9)
#define DRIVER_FIELD7C_IS_NET_NON_PLAYER    (1 << 10)
#define DRIVER_FIELD7C_BIT12                (1 << 12)
#define DRIVER_FIELD7C_TERESA_EFFECT_ACTIVE (1 << 13)
#define DRIVER_FIELD7C_TERESA_FLICKER       (1 << 14)
#define DRIVER_FIELD7C_TERESA_RENDERING_OFF (1 << 15)
#define DRIVER_FIELD7C_BIT16                (1 << 16)
#define DRIVER_FIELD7C_BIT17                (1 << 17)
#define DRIVER_FIELD7C_MG_KILL              (1 << 18)
#define DRIVER_FIELD7C_BIT19                (1 << 19)
#define DRIVER_FIELD7C_BIT20                (1 << 20)
#define DRIVER_FIELD7C_BIT21                (1 << 21)
#define DRIVER_FIELD7C_MG_KILL_GHOST        (1 << 22)   // eliminated mg player that appears as ghost that can place item boxes
#define DRIVER_FIELD7C_BIT23                (1 << 23)
#define DRIVER_FIELD7C_BIT24                (1 << 24)
#define DRIVER_FIELD7C_BIT25                (1 << 25)
#define DRIVER_FIELD7C_BIT26                (1 << 26)
#define DRIVER_FIELD7C_BIT27                (1 << 27)
#define DRIVER_FIELD7C_BIT28                (1 << 28)
#define DRIVER_FIELD7C_BIT29                (1 << 29)

typedef struct driver_t
{
    sfx_emitter_t soundEmitter;
    u32 field44;
    u32 flags;
    u32 flags2;
    VecFx32 direction;
    VecFx32 drivingDirection;
    VecFx32 velocity;
    u16 id;
    InputUnitId inputId;
    u32 field7C;
    VecFx32 position;
    VecFx32 lastPosition;
    VecFx32 kartTiresPosition;
    VecFx32 deltaPos;
    VecFx32 deltaPosNormalized;
    VecFx32 scale;
    fx32 fieldC8;
    fx32 targetMaxSpeed;
    fx32 maxSpeed;
    u32 fieldD4;
    fx32 slipstreamSpeedMultiplier;
    fx32 speedMultiplier;
    quaternion_t rotation;
    quaternion_t fieldF0;
    quaternion_t field100;
    quaternion_t field110;
    MtxFx43 mainMtx;
    MtxFx43 field150;
    DriverCollisionReaction colReaction;
    MtxFx43 field184;
    u32 charKartMtx;
    VecFx32 colPos;
    VecFx32 prevColPos;
    fx32 colSphereSize;
    fx32 colSphereZOffset;
    VecFx32 netColPos;
    VecFx32 lastNetColPos;
    VecFx32 colPos2;
    VecFx32 field1FC;
    u32* field208;
    void* field20C[9];
    void (*field230)(driver_t* driver);
    s16 xRot;
    u16 yRot;
    s16 boostTimer;
    s16 field23A;
    s16 driftBoostCounter;
    fx32 velocityMinusDirMultiplier;
    VecFx32 upDir;
    VecFx32 field250;
    VecFx32 velocityY;
    VecFx32 fallsWaterForward;
    fx32 fallsWaterStrength;
    VecFx32 forwardDir;
    VecFx32 jumpDriftUp;
    VecFx32 jumpDriftForward;
    DriverCollisionMode collisionMode;
    fx32 maxSpeedFraction;
    fx32 deltaPosMag;
    fx32 speed;
    fx32 field2AC;
    u16 driverHitCheckMask;
    u16 driverHitMask;
    u16 lastDriverHitMask;
    u8 gap2B6[2];
    int field2B8;
    s32 field2BC;
    u16 field2C0;
    fx32 leftRightDir;
    s16 colEntryId1;
    s16 colEntryId2;
    physp_kart_params_t* kartPhysicalParams;
    physp_char_params_t* charPhysicalParams;
    fx32 turningAmount;
    VecFx32 field2D8;
    VecFx32 field2E4;
    VecFx32 field2F0;
    s32 driftLeftRightCount;
    u16 driftLeftCount;
    u16 driftRightCount;
    u16* driftDir1CountPtr;
    u16* driftDir2CountPtr;
    s32 driftLeftRightTimeout;
    enemy_t* enemyState;
    u16 field314;
    fx32 field318;
    VecFx32 field31C;
    VecFx32 field328;
    u32 field334;
    u16 field338;
    u32 field33C;
    fx32 field340;
    u32 field344;
    u32 field348;
    quaternion_t field34C;
    s16 colReactionCounter;
    fx32 field360;
    u16 spinOutAngle;
    u16 spinOutSpinCount;
    fx32 spinOutProgress;
    u32 spinOutVelocity;
    u16 field370;
    VecFx32 field374;
    u32 field380;
    u16 ghostFlickerPhase;
    s16 wallRotYSpeed;
    s16 driftRotY;
    fx16 extraDrift;
    fx32 field38C;
    u8 gap390[4];
    u32 field394;
    fx32 field398;
    fx32 field39C;
    fx32 field3A0;
    u16 tireRotX;
    s32 field3A8;
    u16 respawnCounter;
    VecFx32 field3B0;
    u16 field3BC;
    s16 field3BE;
    s16 preRespawnCounter;
    u32 respawnId;
    s16 killTimer;
    u32 driverVoiceIdx;
    s16 kartABC;
    s16 field3D2;
    s16 field3D4;
    s32 place;
    DriverCollisionType floorDriverColType;
    u32 floorColType;
    int floorColVariant;
    s16 field3E8;
    u32 yRotSpeedTarget;
    u32 yRotSpeed;
    fx32 field3F4;
    fx32 field3F8;
    u16 field3FC;
    u16 field3FE;
    u16 field400;
    fx32 field404;
    u32 field408;
    u32 respawnStartFrame;
    u32 respawnAPressFrame;
    fx32 field414;
    fx32 field418;
    VecFx32 growBackScale;
    VecFx32 thunderScale;
    fx32 dossunYScale;
    mobj_inst_t* mobjHitList[2];
    u16 mobjHitSfxTimeout[2];
    BOOL mobjHitEmittedSfx[2];
    mobj_inst_t* smashDossun;
    driver_field450_t field450;
    fx32 field4BC;
    u32 colFlagsMap2DShadow;
    u32 jumpPadSpeed;
    fx32 field4C8;
    u32 field4CC;
    u32 field4D0;
    fx32 preStartEnginePower;
    s16 fallsWaterDstId;
    s16 wallTouchTimeout;
    s16 floorTouchTimeout;
    s16 field4DE;
    s16 field4E0;
    s16 field4E2;
    u16 field4E4;
    u16 field4E6;
    fx32 field4E8;
    fx32 field4EC;
    VecFx32 idkScale;
    u16 field4FC;
    fx32 waterDepth;
    u16 field504;
    u16 field506;
    VecFx32* field508;
    quaternion_t* field50C;
    VecFx32* field510;
    driver_net_state_t* netState;
    sfx_emitter_ex_params_t field518;
    void* field534;
    driver_timers_t timers;
    charkart_t* charKart;
    fx32 field594;
    s16 field598;
    u32 field59C;
    u16 field5A0;
    u8 gap5A2[2];
    fx32 field5A4;
} driver_t;

SDK_COMPILER_ASSERT(sizeof(driver_t) == 0x5A8);

driver_t* driver_getById(u32 driverId);

driver_statistics_t* driver_getPlayerStatistics();

static inline BOOL driver_isPlayer(driver_t* driver)
{
    return (driver->field7C & DRIVER_FIELD7C_IS_PLAYER) != 0;
}

static inline BOOL driver_isEnemy(driver_t* driver)
{
    return (driver->field7C & DRIVER_FIELD7C_IS_ENEMY) != 0;
}

static inline const VecFx32* driver_getPositionById(u16 driverId)
{
    return &driver_getById(driverId)->position;
}

static inline BOOL driver_isNearby(u16 driverId, const VecFx32* position, fx32 distance)
{
    const VecFx32* driverPos = driver_getPositionById(driverId);
    return vec_isNearbyXZ(driverPos, position, distance);
}

static inline BOOL driver_isAnyNearby(const VecFx32* position, fx32 distance)
{
    for (int i = 0; i < (int)rconf_getDriverCount(); i++)
    {
        if (driver_isNearby(i, position, distance))
            return TRUE;
    }
    return FALSE;
}
