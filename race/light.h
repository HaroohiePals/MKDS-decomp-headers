#pragma once

typedef struct
{
    GXRgb color;
    s16 r;
    s16 g;
    s16 b;
    s16 rDelta;
    s16 gDelta;
    s16 bDelta;
    u16 lightMask;
    fx16 progress;
} light_t;

void light_init(light_t* light, u16 lightMask);
void light_setToKclColor(light_t* light, u16 lightMask);
void light_interpolateToKclColor(light_t* light, u16 lightMask, fx32 interpolationSpeed);
void light_apply(const light_t* light);
void light_applyDefault();
