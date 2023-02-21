#pragma once

#include "scene/sceneProc.h"
#include "race\raceConfig.h"

typedef void*(*arc_load_func_t)(const char* path);

typedef enum
{
    ARC_MAINRACE,
    ARC_MAIN2D,
    ARC_MAIN2D_LOC,
    ARC_COURSE,
    ARC_SND,
    ARC_SCENE,
    ARC_KARTMODELMAINA,
    ARC_KARTMODELMAINB,
    ARC_KARTMODELSUB,
    ARC_SCENE_LOC,
    ARC_KARTMODELMENU,
    ARC_RACESCENE,
    ARC_RACESCENE_LOC,
    ARC_COURSETEX,
    ARC_CHARACTERKARTSELECT,
    ARC_CHARACTERKARTSELECT_LOC,
    ARC_GENERALMENU,
    ARC_GENERALMENU_LOC,
    ARC_MAINEFFECT,
    ARC_STATIC2D
} MKDSArchive;

typedef struct
{
    const char* path;
    int next;
    s8 somethingId;
    u32 unk3;
    BOOL allocFromTail;
    int unk5;
} arc_def_t;

typedef struct
{
    const char* name;
    int unk;
} arc_scene_def_t;

typedef struct
{
    const char* name;
    u8 hasDVariant;
} arc_course_def_t;

typedef struct
{
    NNSFndArchive arc;
    BOOL loaded;
    void* arcData;
} arc_t;

typedef struct
{
    NNSFndHeapHandle heapHandle;
    void* b;
    u32 flag0 : 29;
    BOOL flag29 : 1;
    BOOL flag30 : 1;
    BOOL flag31 : 1;
    //vs32 flags;
} arc_something_t;

typedef struct
{
    char path[FS_FILE_NAME_MAX + 1];
    void* srcBuf;
    void* dstBuf;
    void* tmpBuf;
    u32 arcId;
    u32 allocFromTail;
    u32 field94;
    u32 field98;
    u32 field9C;
} arc_loader_t;


typedef struct
{
    arc_t arcs[20];
    u32 fsTableSize;
    void* fsTable;
    arc_loader_t arcLoader;
    FSFile file;
    //0x9B0
    arc_something_t something[16];
    CourseId curLoadedCourse;
    RaceMode curLoadedRaceMode;
    NNSFndHeapHandle unk0xA78;
    NNSFndHeapHandle unk0xA7C;
    NNSFndHeapHandle unk0xA80;
} arc_data_t;

extern arc_data_t* gArcData;

void arc_init(NNSFndHeapHandle heapHandle);
BOOL arc_readFileToEnd(const char* path, void* dst, u32 maxLen);
BOOL arc_readFile(const char* path, void* dst, u32 len);
u32 arc_loadFile(const char* path, NNSFndHeapHandle heapHandle, void** ppFileData);
void arc_loadArchivesForScene(MKDSScene sceneId);
void arc_unloadAllArchives();
void arc_setHeapGroupId(u32 id);
void* arc_getMainRaceMainEffectArcFile(const char* path);
void* arc_get2dArcFile(const char* path);
void* arc_getSceneArcFile(const char* path);
void* arc_getCourseArcFile(const char* path);
void* arc_getKartModelArcFileSafe(const char* path);
void* arc_getKartModelArcFile(const char* path);
void arc_switchKartModelMainAtoB();
void arc_switchKartModelBSubToCourse();
void arc_switchCourseTexToSceneRace();
void sub_20476AC();
void sub_2047544(NNSFndHeapHandle a1, NNSFndHeapHandle a2, NNSFndHeapHandle a3);
void sub_20474E4();
void sub_20473E4();
void sub_20473A8();
void sub_20472E4(CourseId course, RaceMode raceMode);
void sub_20472A8();
void arc_2047274();
BOOL arc_isCourseTexAvailable();
void arc_resizeMainEffectArc(const void* spa, u32 texOffset);
void arc_loadStatic2D(NNSFndHeapHandle heapHandle);

//idk, some kind of thumb bridge??
void* m2d_getSceneArcFile(const char* path);

static inline BOOL arc_isArchiveLoaded(MKDSArchive arcId)
{
    return gArcData->arcs[arcId].loaded;
}

// static inline void arc_setSomethingFlag29(arc_something_t* something, BOOL flag29)
// {
// 	something->flags = (something->flags & ~0x20000000) | ((flag29 & 1) << 29);
// }

// static inline void arc_setSomethingFlag30(arc_something_t* something, BOOL flag30)
// {
// 	something->flags = (something->flags & ~0x40000000) | ((flag30 & 1) << 30);
// }

// static inline void arc_setSomethingFlag31(arc_something_t* something, BOOL flag31)
// {
// 	something->flags = (something->flags & ~0x80000000) | ((flag31 & 1) << 31);
// }
