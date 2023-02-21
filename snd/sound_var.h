#pragma once

typedef struct
{
    s16 value;
    s16 field2;
    s32 field4;
    s8 id;
} sound_var_t;

void sndvar_update(NNSSndHandle* handle);
BOOL sndvar_getVarField4IsZero(int var);
int sndvar_getVarField4(int var);
int sndvar_getDemoRaceDelay();
