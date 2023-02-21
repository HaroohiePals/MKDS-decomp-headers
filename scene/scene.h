#pragma once
#include "sceneProc.h"

typedef enum
{
    SCENE_STATE_INITIALIZING,
    SCENE_STATE_FADE_IN,
    SCENE_STATE_RUNNING,
    SCENE_STATE_FADE_OUT,
    SCENE_STATE_FINALIZE_WAIT,
    SCENE_STATE_FINALIZING,
    SCENE_STATE_IDLE
} SceneState;

typedef struct
{
    u32* threadStack;
    OSThread thread;
    OSThreadQueue threadQueue;
    PMSleepCallbackInfo preSleepCallback;
    PMSleepCallbackInfo postSleepCallback;
    int sceneFrameCounter;
    int totalFrameCounter;
    scene_def_t curSceneDef;
    SceneState state;
    BOOL isLcdOff;
    u8 gap114[4];
    u32 field118;
    u32 field11C;
    s8 field120;
    u8 gap121[3];
} scene_state_t;

int scene_getSceneFrameCounter();
int scene_getFadeInLength();
int scene_getFadeOutLength();
void scene_init(NNSFndHeapHandle heapHandle);
BOOL scene_areUpdatesSuspended() ATTRIBUTE_NEVER_INLINE;
void scene_reportError(int a1);
SceneState scene_getState();
void scene_runScene(scene_manager_t* sceneManager, const scene_def_t* sceneDef);