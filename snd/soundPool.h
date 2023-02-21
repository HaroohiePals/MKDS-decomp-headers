#pragma once

typedef struct
{
	NNSSndHandle handle;
	u32 age;
} sp_handle_t;

typedef struct
{
	int nrElements;
	u32 elements1Idx;
	void* elements1;
	void* elements;
	u32 elementSize;
} sound_pool_t;

void sp_init(sound_pool_t* pool, void* elements, u32 nrElements, u32 elementSize);
void sp_updateAges(sound_pool_t* pool);
sp_handle_t* sp_acquireElement(sound_pool_t* pool);