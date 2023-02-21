#pragma once
#include "race/raceTime.h"

typedef struct
{
    u32 characterId;
    u32 kartId;
    u32 field8;
} struct_217B488_driver_config_t;

typedef struct
{
    u32 titleMenuSkipIntro;
    u32 field4;
    u32 singlePlayerMenuTarget;
    BOOL ghostReceive;
    u32 field10;
    u32 field14;
    u32 unk18;
    u32 field1C;
    struct_217B488_driver_config_t driverConfigs[4];
    u32 unk50;
    u8 field54;
    u32 field58;
    u32 playedCourses[5];
    u32 field70;
    u32 field74;
    BOOL useDLResult;
    s32 playerGlobalRank;
    u32 gpRank;
    u32 cup;
    u32 ccMode;
    u32 mirrorMode;
    u32 playerCharacter;
    u32 playerKart;
    race_time_t courseTimes[4];
    u16 playerTotalRankPoints;
    u32 driverCharacters[8];
    u32 driverKarts[8];
    u8 unkEC[0x20];
    u32 heyhoPaletteRows[8];
    u32 field12C;
} struct_217B488_t;

extern struct_217B488_t* gStruct217B488;

//void sub_20CEFA0(NNSFndHeapHandle heapHandle);

static inline u32 struct217B488_getTitleMenuSkipIntro()
{
    return gStruct217B488->titleMenuSkipIntro;
}

static inline void struct217B488_setTitleMenuSkipIntro(BOOL skipIntro)
{
    gStruct217B488->titleMenuSkipIntro = skipIntro;
}

static inline void struct217B488_setField4(u32 field4)
{
    gStruct217B488->field4 = field4;
}

static inline void struct217B488_setSinglePlayerMenuTarget(u32 target)
{
    gStruct217B488->singlePlayerMenuTarget = target;
}

static inline void struct217B488_setField10(u32 field10)
{
    gStruct217B488->field10 = field10;
}

static inline void struct217B488_setField14(u32 field14)
{
    gStruct217B488->field14 = field14;
}

static inline u32 struct217B488_getField74()
{
    return gStruct217B488->field74;
}

static inline void struct217B488_setField74(u32 field74)
{
    gStruct217B488->field74 = field74;
}

static inline BOOL struct217B488_getUseDLResult()
{
    return gStruct217B488->useDLResult;
}
