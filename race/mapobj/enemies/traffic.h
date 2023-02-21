#pragma once
#include "race/mapobj/mapobj.h"
#include "model.h"
#include "race/pathwalker.h"
#include "race/mapobj/mapobjModel.h"

typedef struct
{
    fx32 field0;
    fx32 field4;
    fx32 field8;
    fx32 fieldC;
    fx32 field10;
    fx32 field14;
    fx32 field18;
    fx32 field1C;
    model_t** model;
    shadowmodel_t** shadowModel;
    anim_manager_t** nsbtpAnim;
    u32 field2C;
    u32 field30;
    void* field34;
} traffic_params_t;

typedef struct
{
    mobj_inst_t mobj;
    int fieldA0;
    quaternion_t fieldA4;
    quaternion_t fieldB4;
    quaternion_t fieldC4;
    int fieldD4;
    pw_pathwalker_t pathWalker;
    s16 initialPoint;
    s16 fieldFE;
    fx32 field100;
    fx32 field104;
    fx32 field108;
    u16 field10C;
    fx32 field110;
    fx32 field114;
    fx32 field118;
    fx32 field11C;
    fx32 field120;
    model_t* model;
    shadowmodel_t* shadowModel;
    anim_manager_t* nsbtpAnim;
    u16 nsbtpFrame;
    light_t light;
    VecFx32 field144;
    u16 field150;
    u16 field152;
    traffic_params_t* params;
    sfx_emitter_ex_params_t* sfxEmitterExParams;
    int field15C;
    int field160;
} traffic_t;

typedef struct
{
    mobj_render_part_t renderPart;
    VecFx32 playerIpatDir;
    BOOL updateIpatCulling;
    BOOL performIpatCulling;
} traffic_renderpart_t;

extern const traffic_params_t gTrafficCarParams;
extern const traffic_params_t gTrafficTruckParams;
extern const traffic_params_t gTrafficBusParams;

extern const mobj_def_t gCarMObjDef;
extern const mobj_def_t gTruckMObjDef;
extern const mobj_def_t gBusMObjDef;
