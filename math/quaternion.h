#pragma once

typedef struct
{
    fx32 x, y, z, w;
} quaternion_t;

extern quaternion_t stru_217B660;

void qtrn_20D7BEC(const MtxFx43* mtx);
void qtrn_fromForwardVec(const VecFx32* forward, quaternion_t* dst);
void qtrn_fromYAngle(u16 angle, quaternion_t* dst);
void qtrn_20D7A3C(const VecFx32* a1, u16 angle, quaternion_t* a3);
void qtrn_20D79B0(const quaternion_t* a1, u16 angle, quaternion_t* dst);
void qtrn_20D7938(const quaternion_t* a, const quaternion_t* b, quaternion_t* dst);
void qtrn_rot_20D788C(const quaternion_t* a1, u16 angle, quaternion_t* dst);
void qtrn_rotY(const quaternion_t* a1, u16 angle, quaternion_t* dst);
void qtrn_rotZ(const quaternion_t* a1, u16 angle, quaternion_t* dst);
void qtrn_rot_20D76A8(const quaternion_t* a1, u16 angle, quaternion_t* dst);
void qtrn_slerp(const quaternion_t* a, const quaternion_t* b, quaternion_t* dst, fx32 t);
void qtrn_normalizeFast(const quaternion_t* src, quaternion_t* dst);
void qtrn_fromEulerAngles(const VecFx32* rotation, quaternion_t* dst);
void qtrn_fromAxisAngle(const VecFx32* axis, u16 angle, quaternion_t* dst);
BOOL qtrn_lookAt(quaternion_t* dst, const VecFx32* a, const VecFx32* b);
void qtrn_normalize(const quaternion_t* src, quaternion_t* dst);
void qtrn_mult(const quaternion_t* a, const quaternion_t* b, quaternion_t* dst);
void qtrn_lerp(const quaternion_t* a, const quaternion_t* b, quaternion_t* dst, fx32 f);
void qtrn_toMtx43(MtxFx43* dst, const quaternion_t* quaternion);
void qtrn_toMtx33(MtxFx33* dst, const quaternion_t* quaternion);