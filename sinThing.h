#pragma once

typedef struct
{
    u16 phase;
    fx32 value;
    fx32 velocity;
    fx32 baseOffset;
    fx32 amplitude;
    fx32 amplitudeVelocity;
    int phaseVelocity;
    int phaseAcceleration;
} sinthing_t;

static inline fx32 updateSinThing(sinthing_t* sinThing)
{
    sinThing->phase += sinThing->phaseVelocity;
    sinThing->velocity = sinThing->baseOffset + FX_Mul(sinThing->amplitude, FX_SinIdx(sinThing->phase)) - sinThing->value;
    sinThing->value += sinThing->velocity;
    if (sinThing->amplitude > 0)
    {
        fx32 v6 = sinThing->amplitude + sinThing->amplitudeVelocity;
        if (v6 <= 0)
            v6 = 0;
        sinThing->amplitude = v6;
    }
    else if (sinThing->amplitude < 0)
    {
        fx32 v6 = sinThing->amplitude + sinThing->amplitudeVelocity;
        if (v6 >= 0)
            v6 = 0;
        sinThing->amplitude = v6;
    }
    if (sinThing->phaseVelocity > 0)
    {
        fx32 v6 = sinThing->phaseVelocity + sinThing->phaseAcceleration;
        if (v6 <= 0)
            v6 = 0;
        sinThing->phaseVelocity = v6;
    }
    else if (sinThing->phaseVelocity < 0)
    {
        fx32 v6 = sinThing->phaseVelocity + sinThing->phaseAcceleration;
        if (v6 >= 0)
            v6 = 0;
        sinThing->phaseVelocity = v6;
    }
    return sinThing->value;
}

static inline fx32 updateSinThing2(sinthing_t* sinThing)
{
    sinThing->phase += sinThing->phaseVelocity;
    sinThing->velocity = sinThing->baseOffset + FX_Mul(sinThing->amplitude / 2, FX32_ONE - FX_CosIdx(sinThing->phase)) - sinThing->value;
    sinThing->value += sinThing->velocity;
    if (sinThing->amplitude > 0)
    {
        fx32 v6 = sinThing->amplitude + sinThing->amplitudeVelocity;
        sinThing->amplitude = v6 <= 0 ? 0 : v6;
    }
    else if (sinThing->amplitude < 0)
    {
        fx32 v6 = sinThing->amplitude + sinThing->amplitudeVelocity;
        sinThing->amplitude = v6 >= 0 ? 0 : v6;
    }
    if (sinThing->phaseVelocity > 0)
    {
        fx32 v6 = sinThing->phaseVelocity + sinThing->phaseAcceleration;
        sinThing->phaseVelocity = v6 <= 0 ? 0 : v6;
    }
    else if (sinThing->phaseVelocity < 0)
    {
        fx32 v6 = sinThing->phaseVelocity + sinThing->phaseAcceleration;
        sinThing->phaseVelocity = v6 >= 0 ? 0 : v6;
    }
    return sinThing->value;
}