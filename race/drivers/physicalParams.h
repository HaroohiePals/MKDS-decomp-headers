#pragma once

typedef struct
{
    fx32 colSphereSize;
    fx32 colSphereZOffset;
    u8 gap8[4];
    fx16 weight;
    s16 driftBoostTime;
    fx32 maxSpeed;
    fx32 baseAcceleration;
    fx32 field18;
    fx32 field1C;
    fx32 driftBaseAcceleration;
    fx32 field24;
    fx32 field28;
    fx32 deceleration;
    fx16 handling;
    fx16 drift;
    fx32 driftTurningCompensation;
    //both arrays should have a length equal to DRIVER_COLLISION_TYPE_COUNT
    //but it's not enforced here because it is a file struct
    fx32 collisionVelocityMinusDirMultipliers[12];
    fx32 collisionSpeedMultipliers[12];
} physp_kart_params_t;

SDK_COMPILER_ASSERT(sizeof(physp_kart_params_t) == 0x98);

typedef struct
{
    fx32 field0;
    fx32 weight;
} physp_char_params_t;

SDK_COMPILER_ASSERT(sizeof(physp_char_params_t) == 8);

typedef struct
{
    physp_kart_params_t* driverKartPhysicalParams;
    physp_char_params_t* driverCharPhysicalParams;
    u32 field8;
    const physp_kart_params_t* kartPhysicalParams;
    const physp_char_params_t* charPhysicalParams;
} physp_t;

void physp_init(NNSFndHeapHandle heapHandle, int driverCount);
void physp_initForDriver(u16 driverId, u16 kart, int character);
const physp_kart_params_t* physp_getDriverKartPhysicalParams(u16 driverId);
const physp_char_params_t* physp_getDriverCharPhysicalParams(u16 driverId);
u32 physp_getField8();