#pragma once

#include "mapobjInstance.h"
#include "race/items/item.h"

typedef struct mobj_logic_part_t mobj_logic_part_t;

typedef void (*mobj_logic_part_global_init_func_t)(mobj_logic_part_t* logicPart);
typedef void (*mobj_logic_part_global_pre_update_func_t)(mobj_logic_part_t* logicPart);
typedef void (*mobj_logic_part_instance_update_func_t)(mobj_logic_part_t* logicPart, mobj_inst_t* instance);
typedef void (*mobj_logic_part_global_post_update_func_t)(mobj_logic_part_t* logicPart);
typedef u32 (*mobj_logic_part_thunder_func_t)(mobj_inst_t* instance, it_item_inst_t* item, u8* objResp, u8* itemResp);

typedef struct mobj_logic_part_t
{
    mobj_inst_t** mobjInstanceList;
    u16 mobjInstanceCount;
    mobj_logic_part_global_init_func_t globalInitFunc;
    mobj_logic_part_global_pre_update_func_t globalPreUpdateFunc;
    mobj_logic_part_instance_update_func_t instanceUpdateFunc;
    mobj_logic_part_global_post_update_func_t globalPostUpdateFunc;
    u32 type;
    mobj_logic_part_thunder_func_t thunderFunc;
    u32 thunderObjResp;
    struct mobj_logic_part_t** thisPointer;
} mobj_logic_part_t;

void mobj_logicPartExecute(mobj_logic_part_t* logicPart);
void mobj_logicPartExecuteThunderLogic(mobj_logic_part_t* logicPart);
void mobj_logicPartResetInstanceCount(mobj_logic_part_t* logicPart);
void mobj_logicPartIncreaseInstanceCount(mobj_logic_part_t* logicPart, u16 count);
void mobj_logicPartInit(mobj_logic_part_t* logicPart);
void mobj_logicPartAddInstance(mobj_logic_part_t* logicPart, mobj_inst_t* instance);
void mobj_logicPartSetThisPointer(mobj_logic_part_t** logicPart);
