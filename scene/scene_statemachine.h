#pragma once
#include "sceneProc.h"

typedef void (*ssm_render_func_t)(scene_manager_t* arg);
typedef void (*ssm_vblank_func_t)();

typedef struct
{
    ssm_vblank_func_t vblankFunc;
    ssm_render_func_t renderFunc;
} ssm_state_t;

typedef struct
{
    int frameCounter;
    BOOL changingState;
    u32 prevState;
    u32 curState;
    u32 nextState;
} ssm_t;

static inline void ssm_increaseFrameCounter(ssm_t* ssm)
{
    if (ssm->frameCounter < 0x7FFFFFFF)
        ssm->frameCounter++;
}
