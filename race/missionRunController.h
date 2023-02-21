#pragma once
#include "raceConfig.h"
#include "mapobj/mapobjInstance.h"

int mrcnt_getCurrentValue(void);
void mrcnt_notifyPowerSlide(void);
void mrcnt_notifyMissionEndWinAreaReached(void);
void mrcnt_notifyPlayerDamage(void);
void mrcnt_notifyMObjDamage(u16 objectId);

static inline int mrcnt_getCurrentValueSafe(void)
{
    return rconf_getRaceMode() == RACE_MODE_MR ? mrcnt_getCurrentValue() : 0;
}

static inline void mrcnt_notifyPowerSlideSafe(void)
{
    if (rconf_getRaceMode() == RACE_MODE_MR)
        mrcnt_notifyPowerSlide();
}

static inline void mrcnt_notifyMissionEndWinAreaReachedSafe(void)
{
    if (rconf_getRaceMode() == RACE_MODE_MR)
        mrcnt_notifyMissionEndWinAreaReached();
}

static inline void mrcnt_notifyPlayerDamageSafe(void)
{
    if (rconf_getRaceMode() == RACE_MODE_MR)
        mrcnt_notifyPlayerDamage();
}

static inline void mrcnt_notifyMObjDamageSafe(mobj_inst_t* mobj)
{
    if (rconf_getRaceMode() == RACE_MODE_MR)
        mrcnt_notifyMObjDamage(mobj->objectId);
}
