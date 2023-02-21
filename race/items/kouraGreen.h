#pragma once
#include <nitro/types.h>

#include "sfx.h"

typedef struct
{
    u8 gap0[0x16C];
    sfx_emitter_ex_params_t sfxExParams;
} kouragreen_t;
