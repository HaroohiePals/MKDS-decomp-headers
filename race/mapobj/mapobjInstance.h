#pragma once
#include "mapobjRender.h"
#include "race/mapData/nkm.h"
#include "sfx.h"
#include "stateMachine.h"
#include "race/drivers/driver.h"

#define MOBJ_INST_FLAGS_HIDDEN                              (1 << 0) //not rendered and no collision
#define MOBJ_INST_FLAGS_DISABLE_VISIBILITY_UPDATES          (1 << 1)
#define MOBJ_INST_FLAGS_SUSPENDED                           (1 << 2) //not updated
#define MOBJ_INST_FLAGS_BIT3                                (1 << 3)
#define MOBJ_INST_FLAGS_CLIPPED                             (1 << 4) //not rendered, because not visible
#define MOBJ_INST_FLAGS_MAP_ICON_TRANSLUCENT                (1 << 5) //supported by some objects to make the map icon translucent (for shadow)
#define MOBJ_INST_FLAGS_DISABLE_PUSHBACK                    (1 << 6) //disables collision pushback for drivers and items
#define MOBJ_INST_FLAGS_DISABLED_BEFORE_START               (1 << 7) //driverCollideFunc and itemCollideFunc are not called
#define MOBJ_INST_FLAGS_FREE                                (1 << 8) //sub object that can be acquired
#define MOBJ_INST_FLAGS_BIT9                                (1 << 9)
#define MOBJ_INST_FLAGS_MAP_ICON_MIRROR                     (1 << 10) //only supported by the flipper object to mirror the map icon
#define MOBJ_INST_FLAGS_USE_SIMPLE_HIT_RESP                 (1 << 11) //in time trial and wifi mode

//These are backups of the first 4 bits, which can be restored later
#define MOBJ_INST_FLAGS_PREV_HIDDEN                         (1 << 12)
#define MOBJ_INST_FLAGS_PREV_DISABLE_VISIBILITY_UPDATES     (1 << 13)
#define MOBJ_INST_FLAGS_PREV_SUSPENDED                      (1 << 14)
#define MOBJ_INST_FLAGS_PREV_BIT3                           (1 << 15)

#define MOBJ_INST_FLAGS_PREV_SHIFT                          12
#define MOBJ_INST_FLAGS_PREV_MASK                           (0xF << MOBJ_INST_FLAGS_PREV_SHIFT)

#define MOBJ_INST_VISIBILITY_FLAGS_FAR_CLIP                 (1 << 0)
#define MOBJ_INST_VISIBILITY_FLAGS_NEAR_CLIP                (1 << 1)
#define MOBJ_INST_VISIBILITY_FLAGS_INAUDIBLE                (1 << 2)
#define MOBJ_INST_VISIBILITY_FLAGS_WAS_UPDATED              (1 << 3)
#define MOBJ_INST_VISIBILITY_FLAGS_BIT4                     (1 << 4)
#define MOBJ_INST_VISIBILITY_FLAGS_DISTANCE_MASK            0x3FFFFFE0
#define MOBJ_INST_VISIBILITY_FLAGS_BIT30                    (1 << 30)
#define MOBJ_INST_VISIBILITY_FLAGS_BIT31                    (1 << 31)

typedef struct mobj_config_t mobj_config_t;

typedef struct mobj_inst_t
{
    u16 objectId;
    u16 flags;
    VecFx32 position;
    VecFx32 velocity;
    VecFx32 scale;
    MtxFx43 mtx;
    VecFx32 size;
    s16 colEntryId;
    u16 alpha;
    fx32 nearClip;
    fx32 farClip;
    int sfxMaxDistanceSquare;
    u32 clipAreaMask;
    u32 visibilityFlags;
    u16 has3DModel;
    u16 rotY;
    state_machine_t stateMachine;
    sfx_emitter_t* soundEmitter;
    mobj_config_t* config;
    const nkm_obji_entry_t* objiEntry;
} mobj_inst_t;

void mobj_setScale(mobj_inst_t* mobj, const VecFx32* scale);
void mobj_setSizeX(mobj_inst_t* mobj, fx32 sizeX);
void mobj_initSoundEmitterForObjectSfxParam2(mobj_inst_t* mobj);
sfx_emitter_ex_params_t* mobj_initSoundEmitterExForObjectSfxParam2(mobj_inst_t* mobj);
void mobj_initSoundEmitterForObjectSfxParam3(mobj_inst_t* mobj);
void mobj_initSoundEmitterForObjectSfxParam4(mobj_inst_t* mobj);
sfx_sound_t* mobj_emitSfxFromEmitter2(mobj_inst_t* mobj, int sfxId);
sfx_sound_t* mobj_emitSfxFromEmitter(mobj_inst_t* mobj, int sfxId);
BOOL mobj_tryDestroyByDriver(mobj_inst_t* mobj, driver_t* driver);
sfx_sound_t* mobj_driverEmitSfx2(driver_t* driver, int sfxId);
sfx_sound_t* mobj_driverEmitSfx(driver_t* driver, int sfxId);
void mobj_emitDriverHitSfx(mobj_inst_t* mobj, driver_t* driver, int a3, int a4);
void mobj_20D2600(int sfxId, const VecFx32* position, int sfxParamsId);
void mobj_setSizeY(mobj_inst_t* mobj, fx32 sizeY);
fx32 mobj_getBoundingSphereSize(mobj_inst_t* mobj);
void mobj_setFarClip(mobj_inst_t* mobj, fx32 farClip);
void mobj_setDirectionFromFloor(mobj_inst_t* mobj);
void mobj_setInvisible(mobj_inst_t* mobj);
void mobj_setVisible(mobj_inst_t* mobj);

static inline void mobj_emitSfx(mobj_inst_t* instance, int sfxId)
{
    u32 sfxParamsId;
    if (instance->sfxMaxDistanceSquare == gSfxParams[2].maxDistanceSquare)
        sfxParamsId = 2;
    else if (instance->sfxMaxDistanceSquare == gSfxParams[3].maxDistanceSquare)
        sfxParamsId = 3;
    else
        sfxParamsId = 4;

    snd_unkstruct_field0_t unk;
    unk.sfxId = sfxId;
    unk.position = &instance->position;
    unk.sfxParamsId = sfxParamsId;
    unk.squareDistance = mobj_calcXZCamDistSquare(&instance->position);
    sub_210B7A8(&unk);
}

static inline void mobj_emitSfxIfAudible(mobj_inst_t* instance, int sfxId)
{
    if (instance->visibilityFlags & MOBJ_INST_VISIBILITY_FLAGS_INAUDIBLE)
        return;

    mobj_emitSfx(instance, sfxId);
}

static inline void mobj_emitSfxIfAudible2(mobj_inst_t* instance, int sfxId)
{
    if (mobj_isInaudible(instance))
        return;

    mobj_emitSfx(instance, sfxId);
}

//these functions can probably be unified when deadstripping is turned on
//otherwise they will create static const variables that are not used

static inline void mobj_hide(mobj_inst_t* instance)
{
    static const u16 flag = MOBJ_INST_FLAGS_HIDDEN;
    instance->flags |= flag;
}

static inline void mobj_unhide(mobj_inst_t* instance)
{
    instance->flags &= ~MOBJ_INST_FLAGS_HIDDEN;
}

static inline void mobj_enableVisibilityUpdates(mobj_inst_t* instance)
{
    instance->flags &= ~MOBJ_INST_FLAGS_DISABLE_VISIBILITY_UPDATES;
}

static inline void mobj_disableVisibilityUpdates(mobj_inst_t* instance)
{
    static const u16 flag = MOBJ_INST_FLAGS_DISABLE_VISIBILITY_UPDATES;
    instance->flags |= flag;
}

static inline void mobj_suspend(mobj_inst_t* instance)
{
    static const u16 flag = MOBJ_INST_FLAGS_SUSPENDED;
    instance->flags |= flag;
}

static inline void mobj_resume(mobj_inst_t* instance)
{
    instance->flags &= ~MOBJ_INST_FLAGS_SUSPENDED;
}

static inline void mobj_setFlagsBit3(mobj_inst_t* instance)
{
    static const u16 flag = MOBJ_INST_FLAGS_BIT3;
    instance->flags |= flag;
}

static inline void mobj_clearFlagsBit3(mobj_inst_t* instance)
{
    instance->flags &= ~MOBJ_INST_FLAGS_BIT3;
}

static inline void mobj_setClipped(mobj_inst_t* instance)
{
    static const u16 flag = MOBJ_INST_FLAGS_CLIPPED;
    instance->flags |= flag;
}

static inline void mobj_resetClipped(mobj_inst_t* instance)
{
    instance->flags &= ~MOBJ_INST_FLAGS_CLIPPED;
}

static inline void mobj_setMapIconTranslucent(mobj_inst_t* instance)
{
    static const u16 flag = MOBJ_INST_FLAGS_MAP_ICON_TRANSLUCENT;
    instance->flags |= flag;
}

static inline void mobj_resetMapIconTranslucent(mobj_inst_t* instance)
{
    instance->flags &= ~MOBJ_INST_FLAGS_MAP_ICON_TRANSLUCENT;
}

static inline void mobj_disablePushback(mobj_inst_t* instance)
{
    static const u16 flag = MOBJ_INST_FLAGS_DISABLE_PUSHBACK;
    instance->flags |= flag;
}

static inline void mobj_enablePushback(mobj_inst_t* instance)
{
    instance->flags &= ~MOBJ_INST_FLAGS_DISABLE_PUSHBACK;
}

static inline void mobj_setDisabledBeforeStart(mobj_inst_t* instance)
{
    static const u16 flag = MOBJ_INST_FLAGS_DISABLED_BEFORE_START;
    instance->flags |= flag;
}

static inline void mobj_resetDisabledBeforeStart(mobj_inst_t* instance)
{
    instance->flags &= ~MOBJ_INST_FLAGS_DISABLED_BEFORE_START;
}

static inline void mobj_setFree(mobj_inst_t* instance)
{
    static const u16 flag = MOBJ_INST_FLAGS_FREE;
    instance->flags |= flag;
}

static inline void mobj_resetFree(mobj_inst_t* instance)
{
    instance->flags &= ~MOBJ_INST_FLAGS_FREE;
}

static inline void mobj_setFlagsBit9(mobj_inst_t* instance)
{
    static const u16 flag = MOBJ_INST_FLAGS_BIT9;
    instance->flags |= flag;
}

static inline void mobj_clearFlagsBit9(mobj_inst_t* instance)
{
    instance->flags &= ~MOBJ_INST_FLAGS_BIT9;
}

static inline void mobj_setMapIconMirror(mobj_inst_t* instance)
{
    static const u16 flag = MOBJ_INST_FLAGS_MAP_ICON_MIRROR;
    instance->flags |= flag;
}

static inline void mobj_resetMapIconMirror(mobj_inst_t* instance)
{
    instance->flags &= ~MOBJ_INST_FLAGS_MAP_ICON_MIRROR;
}

static inline void mobj_setUseSimpleHitResponses(mobj_inst_t* instance)
{
    static const u16 flag = MOBJ_INST_FLAGS_USE_SIMPLE_HIT_RESP;
    instance->flags |= flag;
}


static inline void mobj_setAudible(mobj_inst_t* instance)
{
    instance->visibilityFlags &= ~MOBJ_INST_VISIBILITY_FLAGS_INAUDIBLE;
}

static inline void mobj_setInaudible(mobj_inst_t* instance)
{
    static const u32 flag = MOBJ_INST_VISIBILITY_FLAGS_INAUDIBLE;
    instance->visibilityFlags |= flag;
}

static inline void mobj_setWasUpdated(mobj_inst_t* instance)
{
    static const u32 flag = MOBJ_INST_VISIBILITY_FLAGS_WAS_UPDATED;
    instance->visibilityFlags |= flag;
}

static inline void mobj_resetWasUpdated(mobj_inst_t* instance)
{
    instance->visibilityFlags &= ~MOBJ_INST_VISIBILITY_FLAGS_WAS_UPDATED;
}

static inline void mobj_setVisibilityFlagsBit4(mobj_inst_t* instance)
{
    static const u32 flag = MOBJ_INST_VISIBILITY_FLAGS_BIT4;
    instance->visibilityFlags |= flag;
}

static inline void mobj_resetVisibilityFlagsBit4(mobj_inst_t* instance)
{
    instance->visibilityFlags &= ~MOBJ_INST_VISIBILITY_FLAGS_BIT4;
}

static inline void mobj_setVisibilityFlagsBit30(mobj_inst_t* instance)
{
    static const u32 flag = MOBJ_INST_VISIBILITY_FLAGS_BIT30;
    instance->visibilityFlags |= flag;
}

static inline void mobj_setVisibilityFlagsBit31(mobj_inst_t* instance)
{
    static const u32 flag = MOBJ_INST_VISIBILITY_FLAGS_BIT31;
    instance->visibilityFlags |= flag;
}
