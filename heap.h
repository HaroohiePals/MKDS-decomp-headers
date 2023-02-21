#pragma once

typedef struct
{
    u32 unknown;
    void* memoryRegionStart; //?
    void* heapStart;
    NNSFndHeapHandle heapHandle;
    const char* processName; //?
} heap_info_t;

NNSFndHeapHandle heap_create(void* address, u32 size);
void* heap_alloc(NNSFndHeapHandle heap, u32 size);
void* heap_allocEx(NNSFndHeapHandle heap, u32 size, u32 alignment);
void heap_free(NNSFndHeapHandle heap, void* memoryBlock);
void heap_destroySubHeap(NNSFndHeapHandle subHeap);
NNSFndHeapHandle heap_createSubExpHeap(NNSFndHeapHandle heap);
NNSFndHeapHandle heap_createSubFrmHeap(NNSFndHeapHandle heap);
NNSFndHeapHandle heap_createSubFrmHeapWithSize(NNSFndHeapHandle heap, u32 size);
NNSFndHeapHandle heap_createSubFrmHeapWithSizeFromTail(NNSFndHeapHandle heap, u32 size);
void heap_adjustSubFrmHeap(NNSFndHeapHandle heap);
