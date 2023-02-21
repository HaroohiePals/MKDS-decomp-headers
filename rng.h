#pragma once

static inline u32 rng_getSeed1()
{
    return (OS_GetTick() << 16) + OS_GetTick();
}

static inline u32 rng_getSeed2()
{
    return OS_GetTick() + ((OS_GetTick() << 24) + (OS_GetTick() << 8));
}

static inline u32 rng_getRandom32(MATHRandContext32* context, u32 max)
{
    return max == 0 ? 0 : MATH_Rand32(context, max);
}

static inline u16 rng_getRandom16(MATHRandContext32* context, u16 max)
{
    return max == 0 ? 0 : MATH_Rand32(context, max);
}

/**
 * \brief Generates a random fx32 between -1 and 1 with the given rng
 * \param context The rng to generate the random number with
 * \return A random fx32 between -1 and 1
 */
static inline fx32 rng_getRandomFx32(MATHRandContext32* context)
{
    return ((s16)(u16)(MATH_Rand32(context, 0) >> 20) - FX32_HALF) * 2;
}