#pragma once

typedef enum
{
    SCENE_TITLE,
    SCENE_MENU,
    SCENE_RACE,
    SCENE_EMBLEM,
    SCENE_MENU2,
    SCENE_TEST,
    SCENE_WLMENU,
    SCENE_OPTION,
    SCENE_RECORD,
    SCENE_LOGO,
    SCENE_RESULT,
    SCENE_NICKNAME,
    SCENE_WIFIMENU,
    SCENE_GHOST,
    SCENE_KEYBOARD,
    SCENE_ENDING
} MKDSScene;

typedef struct
{
    s16 previousScene;
    s16 currentScene;
    s16 nextScene;
} scene_manager_t;

typedef struct
{
    u32 overlayId;
    u32 nextOverlayId;
    s16 sceneId;
    void* soundHeap;
} scene_proc_t;

typedef void (*scene_init_func_t)(scene_manager_t* sceneManager);
typedef void (*scene_update_func_t)(scene_manager_t* sceneManager, u32 frameCounter);
typedef void (*scene_finalize_func_t)(scene_manager_t* sceneManager);
typedef void (*scene_vblank_func_t)(scene_manager_t* sceneManager, u32 frameCounter);
typedef void (*scene_pre_sleep_func_t)();
typedef void (*scene_post_sleep_func_t)();

typedef struct
{
    scene_init_func_t initFunc;
    scene_update_func_t updateFunc;
    scene_finalize_func_t finalizeFunc;
    scene_vblank_func_t vblankFunc;
    scene_pre_sleep_func_t preSleepFunc;
    scene_post_sleep_func_t postSleepFunc;
    s16 fadeInLength;
    s16 fadeOutLength;
    u32 field1C;
} scene_def_t;

void scproc_init(NNSFndHeapHandle heapHandle);
s16 scproc_getCurrentScene();
s16 scproc_getNextScene();
void scproc_run();
