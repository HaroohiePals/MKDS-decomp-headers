#pragma once
#include "mission.h"
#include "raceTime.h"

typedef enum
{
    COURSE_INVALID,
    COURSE_OLD_YOSHI_GC,
    COURSE_OLD_MARIO_GC,
    COURSE_LUIGI_COURSE,
    COURSE_DOKAN_COURSE,
    COURSE_TEST1_COURSE,
    COURSE_DONKEY_COURSE,
    COURSE_WARIO_COURSE,
    COURSE_NOKONOKO_COURSE,
    COURSE_OLD_BABY_GC,
    COURSE_OLD_MARIO_SFC,
    COURSE_OLD_MOMO_64,
    COURSE_OLD_KOOPA_AGB,
    COURSE_OLD_PEACH_AGB,
    COURSE_OLD_LUIGI_GC,
    COURSE_OLD_NOKO_SFC,
    COURSE_OLD_FRAPPE_64,
    COURSE_CLOCK_COURSE,
    COURSE_MANSION_COURSE,
    COURSE_AIRSHIP_COURSE,
    COURSE_CROSS_COURSE,
    COURSE_TEST_CIRCLE,
    COURSE_BANK_COURSE,
    COURSE_OLD_HYUDORO_64,
    COURSE_RIDGE_COURSE,
    COURSE_MARIO_COURSE,
    COURSE_GARDEN_COURSE,
    COURSE_DESERT_COURSE,
    COURSE_TOWN_COURSE,
    COURSE_RAINBOW_COURSE,
    COURSE_SNOW_COURSE,
    COURSE_BEACH_COURSE,
    COURSE_KOOPA_COURSE,
    COURSE_PINBALL_COURSE,
    COURSE_STADIUM_COURSE,
    COURSE_OLD_DONUT_SFC,
    COURSE_OLD_CHOCO_64,
    COURSE_OLD_LUIGI_AGB,
    COURSE_OLD_KINOKO_GC,
    COURSE_OLD_CHOCO_SFC,
    COURSE_OLD_SKY_AGB,
    COURSE_MINI_BLOCK_COURSE,
    COURSE_MINI_BLOCK_64,
    COURSE_MINI_DOKAN_GC,
    COURSE_MINI_STAGE1,
    COURSE_MINI_STAGE2,
    COURSE_MINI_STAGE3,
    COURSE_MINI_STAGE4,
    COURSE_MR_STAGE1,
    COURSE_MR_STAGE2,
    COURSE_MR_STAGE3,
    COURSE_MR_STAGE4,
    COURSE_AWARD,
    COURSE_STAFFROLL,
    COURSE_STAFFROLLTRUE
} CourseId;

typedef enum
{
    CUP_MUSHROOM,
    CUP_FLOWER,
    CUP_STAR,
    CUP_SPECIAL,
    CUP_SHELL,
    CUP_BANANA,
    CUP_LEAF,
    CUP_LIGHTNING
} CupId;

typedef enum
{
    RACE_MODE_GP, ///< Grand Prix
    RACE_MODE_TA, ///< Time Trail (Time Attack)
    RACE_MODE_MG, ///< Battle (Minigame)
    RACE_MODE_VS, ///< Versus
    RACE_MODE_MR, ///< Mission
    RACE_MODE_NT ///< Wifi (Net)
} RaceMode;

typedef enum
{
    RACE_DISPLAY_MODE_DEFAULT,
    RACE_DISPLAY_MODE_TITLE,
    RACE_DISPLAY_MODE_REPLAY,
    RACE_DISPLAY_MODE_COURSE_INTRO,
    RACE_DISPLAY_MODE_MG_INTRO,
    RACE_DISPLAY_MODE_AWARD,
    RACE_DISPLAY_MODE_STAFF_ROLL
} RaceDisplayMode;

typedef enum
{
    RACE_MG_MODE_BALLOON_BATTLE,
    RACE_MG_MODE_SHINE_RUNNERS
} RaceMgMode;

typedef enum
{
    RACE_CC_MODE_50CC = 0,
    RACE_CC_MODE_100CC = 1,
    RACE_CC_MODE_150CC = 2
} RaceCCMode;

typedef enum
{
    RACE_GP_MODE_50CC,
    RACE_GP_MODE_100CC,
    RACE_GP_MODE_150CC,
    RACE_GP_MODE_MIRROR,

    RACE_GP_MODE_MAX
} RaceGPMode;

typedef enum
{
    RACE_COURSE_MODE_CHOOSE = 0,
    RACE_COURSE_MODE_IN_ORDER = 1,
    RACE_COURSE_MODE_RANDOM = 2
} RaceCourseMode;

typedef enum
{
    RACE_CPU_MODE_NONE = 0, //?
    RACE_CPU_MODE_EASY = 1,
    RACE_CPU_MODE_NORMAL = 2,
    RACE_CPU_MODE_HARD = 3
} RaceCPUMode;

typedef enum
{
    RACE_RULES_FREE = 0,
    RACE_RULES_NR_WINS = 1,
    RACE_RULES_NR_RACES = 2
} RaceRules;

typedef enum
{
    CHAR_MARIO, ///< Mario
    CHAR_DK, ///< Donkey Kong
    CHAR_KINOPIO, ///< Toad
    CHAR_KOOPA, ///< Bowser
    CHAR_PEACH, ///< Peach
    CHAR_WARIO, ///< Wario
    CHAR_YOSHI, ///< Yoshi
    CHAR_LUIGI, ///< Luigi
    CHAR_KARON, ///< Dry Bones
    CHAR_DAISY, ///< Daisy
    CHAR_WALUIGI, ///< Waluigi
    CHAR_ROBO, ///< ROB
    CHAR_HEYHO, ///< Shy Guy

    CHAR_COUNT
} CharacterId;

typedef enum
{
    DRIVER_TYPE_PLAYER,
    DRIVER_TYPE_ENEMY,
    DRIVER_TYPE_GHOST,
    DRIVER_TYPE_3,
    DRIVER_TYPE_INVALID
} DriverType;

typedef enum
{
    GHOST_TYPE_PERSONAL,
    GHOST_TYPE_DOWNLOAD,
    GHOST_TYPE_STAFF,
    GHOST_TYPE_INVALID
} GhostType;

#define RACE_DRIVER_COUNT_MAX       8
#define RACE_COURSE_QUEUE_LENGTH    33

#define RACE_CONFIG_DRIVER_FIELD1C_BIT0     (1 << 0)

typedef struct
{
    u32 character;
    u32 kart;
    DriverType type;
    s32 team;
    u32 field10;
    u32 driverIndex;
    GhostType ghostType;
    u16 field1C;
    s8 field1E;
    u8 field1F;
    u16* nickname;
    u8* emblemTex;
    u32 field28;
    u8 useCustomEmblem;
    u8 field2D;
    u8 field2E;
    u8 field2F;
} race_config_driver_t;

typedef struct
{
    CourseId course;
    CupId cup;
    RaceMode raceMode;
    RaceDisplayMode displayMode;
    RaceCCMode ccMode;
    RaceCPUMode cpuMode;
    RaceMgMode mgMode;
    RaceRules rules;
    RaceCourseMode courseMode;
    GhostType taGhost;
    mission_config_t mrConfig;
    s8 mrLevel;
    s8 mrIndex;
    u8 field56;
    s8 isMirror;
    s8 teams;
    u8 field59;
    u8 field5A;
    u8 field5B;
    u32 rngSeed;
    u16 raceNr;
    s8 playerDriverId;
    u8 cpuDriverId;
    s8 lapCountOverride;
    u8 field65;
    u8 gap66[2];
    race_config_driver_t drivers[RACE_DRIVER_COUNT_MAX];
} race_config_t;

typedef struct
{
    race_config_t current;
    race_config_t next;
    u8 driverCount;
    u8 field3D1;
    u8 teamDriverCount[2];
    u8 field3D4;
    s8 field3D5[2];
    u8 field3D7;
    u16 nrRacesNrWins;
    u8 gap3DA[2];
    u8* courseQueue;
    u8 courseQueueIdx;
    u8 field3E1;
    race_time_t personalGhostTime;
    u8 personalGhostAvailable;
    u8 gap3E7;
    race_time_t ghostTime;
    race_time_t ghostLapTimes[5];
} race_multi_config_t;

extern const CourseId gCupDefs[8][4];
extern race_multi_config_t* gRaceMultiConfig;

void rconf_init(NNSFndHeapHandle heapHandle);
int rconf_courseIdToOrderIdx(CourseId course);
void rconf_setupNext(void);
void rconf_setupNextGpRace(void);

int rconf_getLapCount(void);

void sub_204451C(int driverIdx);

static inline CourseId rconf_getCourse(void)
{
    return gRaceMultiConfig->current.course;
}

static inline RaceMode rconf_getRaceMode(void)
{
    return gRaceMultiConfig->current.raceMode;
}

static inline RaceDisplayMode rconf_getDisplayMode(void)
{
    return gRaceMultiConfig->current.displayMode;
}

static inline RaceCCMode rconf_getCCMode(void)
{
    return gRaceMultiConfig->current.ccMode;
}

static inline RaceMgMode rconf_getMgMode(void)
{
    return gRaceMultiConfig->current.mgMode;
}

static inline RaceRules rconf_getRules(void)
{
    return gRaceMultiConfig->current.rules;
}

static inline BOOL rconf_getIsMirror(void)
{
    return gRaceMultiConfig->current.isMirror;
}

static inline BOOL rconf_getTeamsMode(void)
{
    return gRaceMultiConfig->current.teams;
}

static inline mission_config_t* rconf_getMrConfig(void)
{
    return &gRaceMultiConfig->current.mrConfig;
}

static inline u32 rconf_getMrCamParamsIdx(void)
{
    return gRaceMultiConfig->current.mrConfig.camParamsIdx;
}

static inline s8 rconf_getPlayerDriverId(void)
{
    return gRaceMultiConfig->current.playerDriverId;
}

static inline u8 rconf_getCpuDriverId(void)
{
    return gRaceMultiConfig->current.cpuDriverId;
}

static inline race_config_driver_t* rconf_getDriver(u16 idx)
{
    return &gRaceMultiConfig->current.drivers[idx];
}

static inline u32 rconf_getDriverCount(void)
{
    return gRaceMultiConfig->driverCount;
}

static inline s8 rconf_getMrLevel(void)
{
    return gRaceMultiConfig->current.raceMode == RACE_MODE_MR ? gRaceMultiConfig->current.mrLevel : (s8)-1;
}

static inline s8 rconf_getMrIndex(void)
{
    return gRaceMultiConfig->current.raceMode == RACE_MODE_MR ? gRaceMultiConfig->current.mrIndex : (s8)-1;
}

static inline BOOL rconf_isDriverValidAndNoEnemy(u16 driverId)
{
    int result = 0;
    u32 type = rconf_getDriver(driverId)->type;
    if (type <= DRIVER_TYPE_3 && (1 << type) & 0xD)
        result = 1;
    return result != 0;
}