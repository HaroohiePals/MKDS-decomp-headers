#pragma once
#include "item.h"

typedef struct driver_t driver_t;
typedef struct it_driver_item_status_t it_driver_item_status_t;
typedef struct mdat_itempoint_t mdat_itempoint_t;

typedef struct
{
    int itemConfigId;
    it_driver_item_status_t* driverItemStatus;
    int itemCount;
    int fieldC;
    u16 timeout;
    u16 field12;
    it_item_inst_t* items[3];
    int field20;
    int field24;
} it_driver_itemslot_t;

typedef struct
{
    int itemType;
    int itemConfigId;
    int field8;
    it_driver_item_status_t* driverItemStatus;
    driver_t* driver;
    it_item_inst_t* items[3];
    int itemCount;
    int field24;
    u16 driverId;
    MtxFx43 field2C;
    VecFx32 field5C;
    int field68;
    VecFx32 field6C;
    int field78;
    int field7C;
    int field80;
    VecFx32 field84;
    VecFx32 field90;
    VecFx32 field9C;
    VecFx32 fieldA8;
    VecFx32 fieldB4;
    u8 gapC0[12];
    int fieldCC[3];
    VecFx32 fieldD8;
    int fieldE4;
    int fieldE8;
    int fieldEC[16];
    int field12C[16];
    int field16C;
    int field170;
    u16 field174;
    u16 field176;
    int field178;
    int field17C;
    VecFx32 field180;
    u16 field18C[3];
    u16 field192;
} it_driver_dragitem_t;

typedef struct it_driver_item_status_t
{
    int field0;
    int field4;
    int field8;
    int fieldC;
    int slotItemConfigId;
    int dragItemConfigId;
    struct it_driver_item_status_t* field18;
    int field1C;
    int field20;
    int field24;
    int field28;
    int field2C;
    it_driver_itemslot_t itemSlot;
    it_driver_dragitem_t dragItem;
    u16 field1EC;
    mdat_itempoint_t* ipoi;
    int field1F4;
    u16 driverId;
    driver_t* driver;
    int driverIndex;
    int isUsingShroom;
    int field208;
    int field20C;
} it_driver_item_status_t;

extern it_driver_item_status_t* it_sDriverItemStatus;