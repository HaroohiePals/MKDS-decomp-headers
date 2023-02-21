#pragma once
#include "mapobjConfig.h"
#include "mapobjLogicPart.h"
#include "mapobjModel.h"
#include "mapobjRenderPart.h"

mobj_config_t* mobj_createConfig(
    mobj_config_driver_collide_func_t driverCollideFunc,
    mobj_config_item_collide_func_t itemCollideFunc,
    mobj_config_sphere_collide_func_t sphereCollideFunc,
    u32 logicType, u16 providesPushback);

mobj_config_t* mobj_createDummyConfig();

mobj_config_t* mobj_createConfigEx(
    mobj_config_driver_collide_func_t driverCollideFunc,
    mobj_config_item_collide_func_t itemCollideFunc,
    mobj_config_sphere_collide_func_t sphereCollideFunc,
    u32 logicType, u16 providesPushback, u16 driverHitSfxId);

mobj_logic_part_t* mobj_createLogicPart(
    mobj_logic_part_global_init_func_t globalInitFunc,
    mobj_logic_part_instance_update_func_t instanceUpdateFunc,
    mobj_logic_part_global_pre_update_func_t globalPreUpdateFunc);

mobj_render_part_t* mobj_createRenderPart3d(
    mobj_render_part_global_init_func_t globalInitFunc,
    mobj_render_part_instance_render_func_t instanceRenderFunc,
    mobj_render_part_global_pre_render_func_t globalPreRenderFunc);

mobj_render_part_t* mobj_createRenderPart2d(
    mobj_render_part_global_init_func_t globalInitFunc,
    mobj_render_part_instance_render_func_t instanceRenderFunc,
    mobj_render_part_global_pre_render_func_t globalPreRenderFunc);

mobj_model_t* mobj_loadModel(mobj_render_part_t* renderPart, const char* fileName);
void mobj_loadNsbcaAnim(mobj_model_t* model, const char* fileName);
void mobj_loadNsbtaAnim(mobj_model_t* model, const char* fileName);
void mobj_loadNsbtpAnim(mobj_model_t* model, const char* fileName);
mobj_model_t* mobj_loadShadowModel(mobj_render_part_t* renderPart, const char* fileName);
mobj_model_t* mobj_loadBillboardModel(mobj_render_part_t* renderPart, const char* fileName);
mobj_model_t* mobj_loadTexAnimBillboardModel(mobj_render_part_t* renderPart, const char* nsbmdFileName,
                                             const char* nsbtpFileName);
