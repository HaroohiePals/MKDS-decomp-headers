#pragma once

#define BGWKR_TASK_COUNT_MAX    10
#define BGWKR_STACK_SIZE        2048
#define BGWKR_THREAD_PRIORITY   17

typedef void (*bgwkr_task_t)();

typedef struct
{
    bgwkr_task_t buffer[BGWKR_TASK_COUNT_MAX];
    u8 writePtr;
} bgwkr_queue_t;

typedef struct
{
    bgwkr_queue_t taskQueue;
    OSThread thread;
    u32 unk[2];
    u32* threadStack;
    volatile BOOL requestAvailable;
} bgwkr_t;

extern bgwkr_t* gBgWkrState;

void bgwkr_init(NNSFndHeapHandle heapHandle);
void bgwkr_2057ED4();
BOOL bgwkr_enqueueTask(bgwkr_task_t task);
void bgwkr_waitForCompletion();

static inline void bgwkr_startRequest()
{
    gBgWkrState->requestAvailable = TRUE;
}

static inline BOOL bgwkr_isRequestDone()
{
    return !gBgWkrState->requestAvailable;
}