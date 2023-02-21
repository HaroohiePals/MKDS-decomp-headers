#pragma once

#include "heap.h"

typedef int (*process_main_func_t)(void* arg);
typedef void (*process_exit_func_t)(int processResult); //not sure if processResult is supposed to be an argument

typedef struct process_t
{
    char* name;
    process_main_func_t mainFunc;
    process_exit_func_t exitFunc;
    NNSFndHeapHandle heapHandle;
    struct process_t* prevProcess;
} process_t;

void proc_init(process_t* process, process_main_func_t mainFunc);
void proc_setMainFunc(process_t* process, process_main_func_t mainFunc);
int proc_run(process_t* process, void* arg);
process_t* proc_getCurrent();
NNSFndHeapHandle proc_getHeap(process_t* process);

static inline NNSFndHeapHandle proc_getCurrentHeap()
{
    return proc_getHeap(proc_getCurrent());
}

#define proc_alloc(size)				heap_alloc(proc_getCurrentHeap(), (size))
#define proc_allocEx(size, alignment)	heap_allocEx(proc_getCurrentHeap(), (size), (alignment))
#define proc_free(memoryBlock)			heap_free(proc_getCurrentHeap(), (memoryBlock))
