#pragma once
#include "raceConfig.h"
#include "raceTime.h"
#include "rankpoint.h"
#include "ranktimeGp.h"

typedef enum
{
    RSTAT_DRIVER_STATE_0,
    RSTAT_DRIVER_STATE_1,
    RSTAT_DRIVER_STATE_2,
    RSTAT_DRIVER_STATE_3,
    RSTAT_DRIVER_STATE_4
} RStatDriverState;

typedef enum
{
    RSTAT_MR_RESULT_SUCCESS,
    RSTAT_MR_RESULT_1,
    RSTAT_MR_RESULT_2,
    RSTAT_MR_RESULT_3,
    RSTAT_MR_RESULT_4,
    RSTAT_MR_RESULT_5,
    RSTAT_MR_RESULT_6
} RStatMrResult;

#define RSTAT_DRIVER_FLAGS_IS_PLAYER        (1 << 0) //1
#define RSTAT_DRIVER_FLAGS_BIT1             (1 << 1) //2
#define RSTAT_DRIVER_FLAGS_WRONG_DIRECTION  (1 << 2) //4
#define RSTAT_DRIVER_FLAGS_BIT3             (1 << 3) //8
#define RSTAT_DRIVER_FLAGS_MR_WIN_DELAY     (1 << 4) //0x10
#define RSTAT_DRIVER_FLAGS_MR_LOSE_DELAY    (1 << 5) //0x20
#define RSTAT_DRIVER_FLAGS_PERFORM_FINISH   (1 << 6) //0x40

typedef struct
{
    RStatDriverState state;
    u32 lapFrameCounter;
    u32 field8;
    race_time_t lapTimes[5];
    race_time_t totalTime;
    s32 curLap;
    u32 firstPlaceTime;
    u32 totalMilliseconds;
    u16 flags;
    u16 curCpoi;
    s16 lastCorrectKeyPoint;
    s16 curKeyPoint;
    u16 curCpat;
    u16 highestReachedLap;
    //field3C
    u16 place : 4;
    u16 driverId : 4;
    u16 field3CBit89 : 2;
    s16 skillRankPoints;
    fx32 cpoiProgress;
    fx32 raceProgress;
    fx32 lapProgress;
    u32 cpoiMask[16];
} race_driver_status_t;

typedef struct
{
    int rankTimeDeltaPoints;
    int firstPlacePercentagePoints;
    int startBoostPoints;
    int powerSlidePoints;
    int itemHitPoints;
    int offRoadTimePoints;
    int wallHitPoints;
    int damagePoints;
    int respawnPoints;
} race_skill_rankpoints_t;

typedef struct
{
    u32 frameCounter;
    BOOL timeRunning;
    race_time_t lapTime;
} race_status_time_t;

typedef struct
{
    race_status_time_t time;
    u16 rankTimeGp;
    u16 finishedDriverCount;
    u16 field10;
    race_driver_status_t driverStatus[RACE_DRIVER_COUNT_MAX];
    s8 placeDriverIds[RACE_DRIVER_COUNT_MAX];
    MATHRandContext32 safeRng;
    u32 rngSeed;
    MATHRandContext32 randomRng;
    MATHRandContext32 stableRng;
    ranktime_gp_t* rankTimeGpRtt;
    BOOL resultsStored;
    BOOL camAnimComplete;
    fx32* cpoiKeyPointProgress;
    u8 gap4D8[4];
    rankpoint_t* rankPointRpt;
    RStatMrResult missionResult;
    fx32 oneDivCpatSegmentCount;
    fx32 oneDivNrLaps;
    BOOL useTimeLimit;
    BOOL uncontrollable;
    u32 timeLimit;
    u8 field4F8;
    u8 field4F9;
    u16 mrWinDelayCounter;
    u16 mrLoseDelayCounter;
    race_skill_rankpoints_t skillRankPoints;
} race_status_t;

extern race_status_t* gRaceStatus;


void rstat_winMission(u16 playerId);
void rstat_init(NNSFndHeapHandle heapHandle);
void rstat_finalize();
void rstat_loseMission(u16 playerId);
void rstat_update();
void rstat_startTime();
void rstat_initInputRecorders();
void rstat_getLapTime(u8* minutes, u8* seconds, u16* milliseconds);
int rstat_getPlace(u16 driverId);
u32 rstat_getDriverHighestReachedLap(u16 driverId);
BOOL rstat_hasDriverFinished(u16 driverId);
void rstat_getDriverTotalTime(u16 driverId, u8* minutes, u8* seconds, u16* milliseconds);
void rstat_getDriverLapTime(u16 driverId, int lap, u8* minutes, u8* seconds, u16* milliseconds);
int rstat_getDriverBestLapTime(u16 driverId, u8* minutes, u8* seconds, u16* milliseconds);
BOOL rstat_getUncontrollable();
fx32 rstat_getRaceProgress(u16 driverId);
fx32 rstat_getLapProgress(u16 driverId);
int rstat_getFrameCounter();
u16 rstat_getRankPoints(int place);
void rstat_203C2E4(u16 driverId);
BOOL rstat_isDriverInFinalLap(u16 driverId);
u32 rstat_getDriverTotalMilliseconds(u16 driverId);
void rstat_handleMissionEndAreas(const VecFx32* position, u16 driverId);
BOOL rstat_isMrWinDelayOver();
BOOL rstat_203C0BC();

static inline BOOL rstat_hasAnyDriverReachedLap(int lap)
{
    for (int i = 0; i < (int)rconf_getDriverCount(); i++)
        if (rstat_getDriverHighestReachedLap(i) >= lap)
            return TRUE;
    return FALSE;
}

static inline BOOL rstat_signedHasAnyDriverReachedLap(int lap)
{
    for (int i = 0; i < (int)rconf_getDriverCount(); i++)
        if ((int)rstat_getDriverHighestReachedLap(i) >= lap)
            return TRUE;
    return FALSE;
}