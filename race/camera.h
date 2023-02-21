#pragma once
#include "mapData/mapData.h"
#include "race/drivers/driver.h"

typedef enum
{
    CAMERA_MODE_NORMAL,
    CAMERA_MODE_DOUBLE_TOP,
    CAMERA_MODE_DOUBLE_BOTTOM
} MKDSCameraMode;

typedef struct
{
    fx32 distance;
    fx32 elevation;
    fx32 maxTargetElevation;
} cam_params_t;

typedef struct
{
    VecFx32 pointCache[4];
    int progress;
    int index;
    int field38;
} came_routestat_t;

typedef struct
{
    const nkm_came_entry_t* cameEntry;
    came_routestat_t routestat1;
    came_routestat_t routestat2;
    s16 routeSpeed;
    u16 field7E;
    u32 field80;
    u32 field84;
} came_unknown_t;

typedef struct camera_t
{
    VecFx32 up;
    VecFx32 right;
    VecFx32 target;
    VecFx32 position;
    MtxFx43 mtx;
    s32 fov;
    s32 targetFov;
    fx16 fovSin;
    fx16 fovCos;
    fx32 aspectRatio;
    fx32 frustumNear;
    fx32 frustumFar;
    fx32 frustumTop;
    fx32 frustumBottom;
    fx32 frustumLeft;
    fx32 frustumRight;
    fx32 field88;
    fx32 skyFrustumFar;
    VecFx32 lookAtTarget;
    VecFx32 lookAtPosition;
    VecFx32 fieldA8;
    VecFx32 fieldB4;
    VecFx32 upConst;
    fx32 fieldCC;
    BOOL fieldD0;
    fx32 targetElevation;
    u32 fieldD8;
    u32 fieldDC;
    u32 fieldE0;
    VecFx32 fieldE4;
    fx32 playerOffsetDirection;
    VecFx32 fieldF4;
    VecFx32 field100;
    VecFx32 field10C;
    VecFx32 field118;
    VecFx32 field124;
    u8 field130;
    //padding
    VecFx32 prevPosition;
    BOOL isShaking;
    fx32 field144;
    fx32 shakeAmount;
    u32 field14C;
    s16 field150;
    //padding
    fx32 shakeDecay;
    u32 field158;
    VecFx32 targetDirection;
    fx32 field168;
    u32 field16C;
    u32 field170;
    u32 field174;
    fx32 elevation;
    VecFx32 field17C;
    VecFx32 field188;
    came_routestat_t routeStat;
    came_routestat_t routeStat2;
    u16 field20C;
    u16 field20E;
    u16 targetDriverId;
    //padding
    u32 currentCamId;
    const nkm_came_entry_t* cameEntry;
    came_unknown_t* unknownMgCams;
    came_unknown_t* unknownMgCamsCopy;
    u16 field224;
    //padding
    u32 field228;
    u16 field22C;
    //padding
    u32 field230;
    u32 field234;
    BOOL field238;
    u16 frameCounter;
    //padding
    fx32 fovProgress;
    fx32 targetProgress;
    u32 field248;
    MKDSCameraMode mode;
    u32 field250;
    u32 field254;
    BOOL field258;
    u32 field25C;
    VecFx32 field260;
    s16 field26C;
    u16 field26E; // idk if this is a used field or just padding
} camera_t;

void cam_setupRaceParams();
void cam_setupPlayerCamera();
void cam_20777AC(u16 driverId);
void cam_setupIntroCamDouble();
void cam_setupIntroCamSingle();
void cam_init(camera_t* camera);
void cam_updateFrustum(camera_t* camera);
void cam_updateLookAt(camera_t* camera);
void cam_updateLookAtEx(camera_t* camera);
const MtxFx44* cam_getProjectionMtx();
void cam_applyFrustum(camera_t* camera, BOOL useSkyFar);
void cam_applyLookAt(camera_t* camera);
void cam_resetPlayerCamera();
void cam_updateElevationFromWater(camera_t* camera);
void cam_updatePlayerCamera(camera_t* camera, driver_t* driver);
void cam_2075EB8();
void cam_2075D08(BOOL a1);
void cam_2075CF0();
BOOL cam_updateReplayCamera(camera_t* cam);
void cam_setupMissionFinishCamera();
const MtxFx43* cam_updateIntroCamDouble();
const MtxFx43* cam_updateIntroCamSingle();
void cam_2074E6C(camera_t* camera);
camera_t* cam_getPlayerCamera();
camera_t* cam_getReplayCamera();
camera_t* cam_getIntroCamera();
void cam_setPlayerCameraTargetFov(int targetFov);
void cam_resetPlayerCameraTargetFov();
void cam_resetPlayerCameraFov();
void cam_20747F4(u32 a1);
void cam_setPlayerCameraPosRot(const VecFx32* position, const quaternion_t* rotation);
void cam_tryImpactShakePlayerCamera(int distance, fx32 strength);
void cam_tryCannonShakePlayerCamera();
void cam_2073E98();
BOOL cam_2073E88();
fx32 cam_2073E4C(const VecFx32* position);
fx32 cam_2073E04(const VecFx32* position);
