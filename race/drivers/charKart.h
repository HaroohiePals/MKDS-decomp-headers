#pragma once
#include "animationManager.h"
#include "kartOffsetData.h"
#include "race/light.h"
#include "race/raceConfig.h"

typedef struct
{
    int field0;
    int field4;
    int field8;
    int fieldC;
    u16 field10;
    int field14;
    u16 field18;
    u16 field1A;
} charkart_field24_t;

typedef struct
{
    GXRgb diffuse;
    GXRgb emission;
    GXRgb ambient;
    u16 diffR;
    u16 diffG;
    u16 diffB;
    s16 diffRDelta;
    s16 diffGDelta;
    s16 diffBDelta;
    u16 emiR;
    u16 emiG;
    u16 emiB;
    s16 emiRDelta;
    s16 emiGDelta;
    s16 emiBDelta;
    u16 ambiR;
    u16 ambiG;
    u16 amibB;
    s16 amibRDelta;
    s16 ambiGDelta;
    s16 ambiBDelta;
    fx16 progress;
} charkart_colors_t;

typedef struct
{
    CharacterId characterId;
    s32 kartId;
    anim_manager_t* characterNsbcaAnim;
    anim_manager_t* characterNsbtpAnim;
    model_t* characterModel;
    model_t* kartModel;
    model_t* kartTireModel;
    model_t* kartShadowModel;
    const kofs_entry_t* kartOffsetData;
    charkart_field24_t field24;
    light_t light;
    u32 field54;
    BOOL isKartInvisible;
    BOOL isCharacterInvisible;
    BOOL useSeparateTires;
    BOOL inStarToonMode;
    u16 kartABC;
    charkart_colors_t colors;
    anim_animator_t field98;
    BOOL nsbtpAnimDisabled;
    u32 fieldB0;
} charkart_t;