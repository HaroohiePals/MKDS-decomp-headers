#pragma once

typedef struct
{
    u8 courseId;
    u16 rankTime50cc;
    u16 rankTime100cc;
    u16 rankTime150cc;
} ranktime_gp_entry_t;

typedef struct
{
    u32 signature;
    u32 fileSize;
    u16 courseCount;
    u16 rankTimeDeltaFactor;
    u16 firstPlacePercentageFactor;
    u16 startBoostFactor;
    u16 powerSlideFactor;
    u16 itemHitFactor;
    u16 offRoadTimeFactor;
    u16 wallHitFactor;
    u16 damageFactor;
    u16 respawnFactor;
    ranktime_gp_entry_t courseRankTimes[1];
} ranktime_gp_t;