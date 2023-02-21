#pragma once

typedef enum
{
    MISSION_TASK_GATES, ///< Drive through all gates
    MISSION_TASK_COINS, ///< Collect coins
    MISSION_TASK_LAPS, ///< Drive n laps
    MISSION_TASK_DESTROY, ///< Destroy objects
    MISSION_TASK_POWERSLIDES, ///< Power sliding
    MISSION_TASK_NONE, ///< ?? 
    MISSION_TASK_FINISHBEFORE, ///< Reach the finish line before the opponent
    MISSION_TASK_BOSS, ///< Boss fight
    MISSION_TASK_8,
    MISSION_TASK_9,
    MISSION_TASK_10
} MissionTask;

#define MISSION_FLAGS_NO_FORWARD          (1 << 0)
#define MISSION_FLAGS_DAMAGE_FORBIDDEN    (1 << 1)
#define MISSION_FLAGS_WALL_HIT_FORBIDDEN  (1 << 2)
#define MISSION_FLAGS_RESPAWN_FORBIDDEN   (1 << 3)
#define MISSION_FLAGS_MIRROR              (1 << 4)
#define MISSION_FLAGS_BACKWARDS           (1 << 5)

typedef struct
{
    u16 timeLimit;
    u16 rankTime;
    s16 timeTolerance;
    u8 id;
    u8 task;
    u8 course;
    u8 ccMode;
    u8 character;
    u8 kart;
    u8 menuId;
    u8 fieldD;
    u8 camParamsIdx;
    u8 targetValue;
    u16 winDelay;
    u16 gap12;
    u16 objectIds[4];
    u16 flags;
    u8 enemyCharacter;
    u8 enemyKart;
    char name[12];
} mission_config_t;

SDK_COMPILER_ASSERT(sizeof(mission_config_t) == 0x2C);

typedef struct
{
    u32 signature; ///< File identifier: NKMR
    u32 nrMissions;
    mission_config_t missions[0];
} mission_mr_t;
