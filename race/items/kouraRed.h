#pragma once
#include "sfx.h"

typedef struct
{
    u8 gap0[0x258];
    sfx_emitter_ex_params_t sfxExParams;
} kourared_t;
