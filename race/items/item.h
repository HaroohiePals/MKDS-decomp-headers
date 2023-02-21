#pragma once
#include "sfx.h"
#include "race/light.h"

typedef enum
{
    ITEM_KOURA_G,
    ITEM_KOURA_R,
    ITEM_BANANA,
    ITEM_KINOKO,
    ITEM_STAR,
    ITEM_KOURA_W,
    ITEM_THUNDER,
    ITEM_F_BOX,
    ITEM_ITEMBOX,
    ITEM_BOMB,
    ITEM_GESSO,
    ITEM_TERESA,
    ITEM_KINOKO_P,
    ITEM_KILLER,

    ITEM_COUNT
} MKDSItem;

typedef struct
{
    BOOL enabled;
    BOOL wifiEnabled;
    MKDSItem type;
    u32 count;
    u32 field10;
    u32 field14;
    void* activateFunc;
} it_itemconfig_t;

typedef struct
{
    u32 instanceSize;
    u32 limit;
    u32 field8;
    int instanceCount;
    int field10;
    void* loadFunc;
    void* initInstanceFunc;
    void* field1C;
    void* field20;
    void* field24;
    void* updateFunc;
    void* renderFunc;
    void* visibilityFlagCalcFunc;
    void* field34;
    void* field38;
    void* destroyInstFunc;
    int field40;
    int field44;
    void* field48;
    int field4C;
    void* field50;
    u32 gap54;
    void* field58;
    int field5C;
    int field60;
    int colSphereRadius;
    int sphereRadius1;
    int sphereRadius2;
    int field70;
    int scale;
    int field78;
    int field7C;
    int field80;
    int field84;
    int field88;
    u32 gap8C;
    int field90;
    int field94;
    int field98;
    int field9C;
    int fieldA0;
    int fieldA4;
} it_item_def_t;

#define ITEM_INST_FLAGS_BIT28    (1 << 28)

typedef struct
{
    sfx_emitter_t sfxEmitter;
    u32 type;
    u32 field48;
    u16 field4C;
    u16 field4E;
    VecFx32 position;
    VecFx32 velocity;
    VecFx32 scale;
    u32 flags;
    u16 field78;
    u16 field7A;
    light_t light;
    light_t* lightPtr;
    MtxFx43 mtx;
    u8 gapC4[12];
    VecFx32* fieldD0;
    u32 visibilityFlags;
    s16 alpha;
    u16 colEntryId;
    u32 fieldDC;
    fx32 sphereSize;
    VecFx32 fieldE4;
    VecFx32 fieldF0;
    u32 fieldFC;
    u32 field100;
    u32 field104;
    VecFx32 field108;
    u16 field114;
    u16 field116;
    u16 field118;
    u16 field11A;
    u32 field11C;
    u32 field120;
    u32 field124;
    u8 field128DriverMask;
} it_item_inst_t;

typedef struct
{
    u32 id;
    it_item_inst_t* instances;
    u32 totalInstanceCount;
    u32 itemParamsField10;
    u32 activeInstanceCount;
    u32 field14;
    u32 field18;
    u32 activeInstanceCount2;
    u32 limit;
    void* renderFunc;
    void* visibilityFlagCalcFunc;
    u32 itemParamsField70;
    fx32 scale;
    u32 itemParamsField78;
    u32 itemParamsField5C;
    u32 itemParamsFieldA4;
    BOOL renderingDisabled;
} it_itemset_t;

//action buffer entry struct
typedef struct itnet_action_t_ {
	u8 data[20];
	MKDSItem itemType;
	u32 action;
	u32 field1C;
} itnet_action_t;

extern it_itemconfig_t* it_sItemConfigs;
extern it_itemset_t* it_sItemsets;

it_item_inst_t* it_spawnItem(MKDSItem item, u32 flags, const VecFx32* position, const VecFx32* up);
void it_startThrowAnim(it_item_inst_t* item, u32 a2, const VecFx32* position, const VecFx32* a4, const VecFx32* up);
