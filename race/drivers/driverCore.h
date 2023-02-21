#pragma once
#include "driver.h"
#include "race/mapobj/mapobjInstance.h"

typedef enum
{
    DRIVER_HIT_COL_REACTION_NONE,
    DRIVER_HIT_COL_REACTION_1,
    DRIVER_HIT_COL_REACTION_2,
    DRIVER_HIT_COL_REACTION_SINGLE_SPIN_OUT,
    DRIVER_HIT_COL_REACTION_DOUBLE_SPIN_OUT,
    DRIVER_HIT_COL_REACTION_DOUBLE_SPIN_OUT_FIRE,
    DRIVER_HIT_COL_REACTION_DOUBLE_SPIN_OUT_WATER,
    DRIVER_HIT_COL_REACTION_FORWARD_FLIP,
    DRIVER_HIT_COL_REACTION_SINGLE_BACKWARD_FLIP_1,
    DRIVER_HIT_COL_REACTION_SINGLE_BACKWARD_FLIP_2,
    DRIVER_HIT_COL_REACTION_DOUBLE_BACKWARD_FLIP,
    DRIVER_HIT_COL_REACTION_DOSSUN_SMASH,
    DRIVER_HIT_COL_REACTION_12,
    DRIVER_HIT_COL_REACTION_13,
    DRIVER_HIT_COL_REACTION_SINGLE_SPIN_ELECTRICITY
} DriverHitColReaction;

#define DRIVER_COL_REACTION_FLAGS_BIT0              (1 << 0)
#define DRIVER_COL_REACTION_FLAGS_BIT1              (1 << 1)
#define DRIVER_COL_REACTION_FLAGS_BIT2              (1 << 2)
#define DRIVER_COL_REACTION_FLAGS_HANDLE_AS_WALL    (1 << 3)

typedef BOOL(*driver_off_217AC14_t)(driver_t* driver, u32 colFlags, const VecFx32* a3);

typedef u32 (*driver_init_reaction_func_t)(driver_t* driver, u32* a1, mobj_inst_t* mobj);
typedef void (*driver_handle_reaction_func_t)(driver_t* driver, VecFx32* a1, mobj_inst_t* mobj);

extern const VecFx32 driverCore_sOneVec;
extern const VecFx32 driverCore_sForwardVec;
extern const VecFx32 driverCore_sUpVec;
extern const VecFx32 driverCore_sRightVec;
extern const VecFx32 driverCore_sZeroVec;

void driver_invokeThunder(driver_t* driver);
void driver_startShroomBoost(driver_t* driver);
void driver_startStarInvincibility(driver_t* driver);
void driver_startTeresaEffect(driver_t* driver);
void driver_startGessoInk(driver_t* driver, int splashCount);
void sub_2069044(driver_t* driver);
BOOL driver_isKilled(driver_t* driver);