#pragma once

typedef struct
{
    MtxFx43 mtx;
    u16 alpha;
} objshadow_t;

void oshd_setPositionXZ(objshadow_t* objShadow, const VecFx32* position);
void oshd_setPosition(objshadow_t* objShadow, const VecFx32* position);
void oshd_applyMaterial();
void oshd_render(objshadow_t* objShadow, fx32* scale, const MtxFx43* camMtx, u16 alpha);
void oshd_renderMat(objshadow_t* objShadow, fx32* scale, const MtxFx43* camMtx, u16 alpha);
void oshd_renderJgShadowTransformed(const VecFx32* scale, const MtxFx43* mtx, u16 alpha, u16 maxAlpha);
void oshd_renderJgShadow(u16 alpha, u16 maxAlpha);
void oshd_init();
BOOL oshd_setParams(objshadow_t* objShadow, const VecFx32* position, fx32 scale, u16 alpha);
BOOL oshd_isPointOnShadowFloor(const VecFx32* position);