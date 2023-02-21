#pragma once
#include "animationManager.h"
#include "model.h"
#include "sinThing.h"
#include "jnlib/spa/spaEmitter.h"

typedef enum
{
    TROPHY_ID_KINO,
    TROPHY_ID_FLOW,
    TROPHY_ID_STAR,
    TROPHY_ID_SPEC,
    TROPHY_ID_KORA,
    TROPHY_ID_BANA,
    TROPHY_ID_KONO,
    TROPHY_ID_THUN,
    TROPHY_ID_GENERIC,

    TROPHY_ID_MAX
} TrophyId;

typedef enum
{
    TROPHY_RANK_GOLD,
    TROPHY_RANK_SILVER,
    TROPHY_RANK_BRONZE,

    TROPHY_RANK_MAX
} TrophyRank;

typedef struct
{
    u16 trophyId;
    u16 trophyRank;
    u16 rotY;
    sinthing_t rotZ;
    model_t trophyModel;
    anim_manager_t trophyNsbtpAnim;
    MtxFx43 identity;
    fx16 light0DirX;
    fx16 light1DirX;
    fx16 light0DirY;
    fx16 light1DirY;
    fx16 light0DirZ;
    fx16 light1DirZ;
    VecFx32 sparkleEmitterPos;
    fx32 sparkleEmitterRadius;
    spa_emitter_t* sparkleEmitter;
    spa_emitter_t* goldConfettiEmitter;
    spa_emitter_t* silverConfettiEmitter;
} trophy_t;

void trophy_init(TrophyId trophyId, u16 trophyRank);
void trophy_update();
void trophy_render();