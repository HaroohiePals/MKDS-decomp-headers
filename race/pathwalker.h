#pragma once

#include "mapData/nkm.h"

typedef int pw_progress_t;
#define PW_PROGRESS_SHIFT   24
#define PW_PROGRESS_ONE     (1 << PW_PROGRESS_SHIFT)

static inline int pw_progressMul(int a, int b) { return a * (s64)b >> PW_PROGRESS_SHIFT; }

typedef struct
{
    VecFx32 p0;
    VecFx32 p1;
    VecFx32 p2;
    VecFx32 p3;
    fx32 length;
    pw_progress_t oneDivLength;
    fx32 hermLength;
    pw_progress_t oneDivHermLength;
    fx32 linLength;
    pw_progress_t oneDivLinLength;
    VecFx32 field48;
} pw_path_part_t;

typedef struct
{
    pw_path_part_t pathPart;
    fx32 speed;
    pw_progress_t partSpeed;
    pw_progress_t progress;
} pw_simple_pathwalker_t;

typedef struct
{
    pw_path_part_t* parts;
    u32 partCount;
    BOOL loop;
} pw_path_t;

typedef struct
{
    pw_path_t* path;
    fx32 speed;
    u16 pathId;
    u32 partIdx;
    pw_progress_t partSpeed;
    pw_progress_t partProgress;
    BOOL isForwards;
    nkm_poit_entry_t* prevPoit;
    nkm_poit_entry_t* curPoit;
} pw_pathwalker_t;

void pw_init(pw_pathwalker_t* pw, u16 initialPoint, BOOL forwards);
BOOL pw_update(pw_pathwalker_t* pw);
fx32 pw_getProgress(pw_pathwalker_t* pw);
void pw_calcCurrentPointXYZ(pw_pathwalker_t* pw, VecFx32* dst);
void pw_20D8BF8_XYZ(pw_pathwalker_t* pw, VecFx32* a2, VecFx32* a3);
void pw_calcCurrentPointXZLinearY(pw_pathwalker_t* pw, VecFx32* dst);
void pw_calcCurrentPointXZ(pw_pathwalker_t* pw, VecFx32* dst);
void pw_20D8B18_XZ(pw_pathwalker_t* pw, VecFx32* a2, VecFx32* a3);
void pw_calcCurrentPointLinearXYZ(pw_pathwalker_t* pw, VecFx32* dst);
void pw_calcCurrentPointLinearXYZSpecial(pw_pathwalker_t* pw, VecFx32* a2, VecFx32* a3);
const VecFx32* sub_20D88FC(pw_pathwalker_t* pw);
fx32 sub_20D8828(const pw_pathwalker_t* pw, const VecFx32* a2);
void sub_20D879C(pw_pathwalker_t* pw, VecFx32* dst);
VecFx32* sub_20D8654(const nkm_obji_entry_t* obji);
void pw_gotoPartEnd(pw_pathwalker_t* pw);
void pw_reverse(pw_pathwalker_t* pw);

static inline BOOL pw_hasEnded(pw_pathwalker_t* pw)
{
    return !pw->path->loop &&
        (pw->isForwards ? pw->partIdx == pw->path->partCount - 1 : pw->partIdx == 0);
}

static inline void pw_setSpeed(pw_pathwalker_t* pw, fx32 speed)
{
    pw->speed = speed;
    pw->partSpeed = FX_TRUNC_MUL(speed, pw->path->parts[pw->partIdx].oneDivLength);
}

void pw_initFromPathId(pw_pathwalker_t* pw, u16 pathId, fx32 speed);
void pw_initFromObject(pw_pathwalker_t* pw, const nkm_obji_entry_t* obji, fx32 speed);
