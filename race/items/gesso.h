#pragma once
#include "item.h"
#include "race/drivers/driver.h"

typedef struct
{
    s16 field0;
    s16 field2;
    s16 field4;
    s16 field6;
    u16 field8;
    u16 fieldA;
} struc_373;

typedef struct
{
    it_item_inst_t item;
    driver_t* driver;
    u8 driverSplashCount[RACE_DRIVER_COUNT_MAX];
    int field138;
    VecFx32 field13C;
    VecFx32 field148;
    VecFx32 field154;
    BOOL field160;
    int field164;
    int field168;
    int field16C;
    int field170;
    VecFx32 field174;
    VecFx32 field180;
    int field18C;
    u32 gap190;
    int field194;
    BOOL visible;
    fx32 field19C;
    u8 gap1A0[0x14];
} gesso_t;

extern const it_itemconfig_t gGessoConfig;
extern const it_item_def_t gGessoDef;
