#pragma once
#include "model.h"

typedef struct
{
    model_t model;
    u16 polygonId;
    u16 alpha;
    u16 flags;
} shadowmodel_t;

void model2_createFromNsbmd(model_t** model, void* file, int offset);