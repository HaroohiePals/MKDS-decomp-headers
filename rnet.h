#pragma once
#include "stateMachine.h"
#include "race/struc_351.h"
#include "peerMatch.h"

#define RNET_MAX_DGRAM_SIZE          0x6C
#define RNET_DGRAM_HEADER_SIZE       4
#define RNET_MAX_DGRAM_BODY_SIZE     (RNET_MAX_DGRAM_SIZE-RNET_DGRAM_HEADER_SIZE)
#define RNET_MAX_ITEM_ACTION_SIZE    48
#define RNET_MAX_ITEM_ACTIONS        16

//race item action buffer entry struct
typedef struct rnet_item_action_entry_t_
{
	u32 field0;
	void *buffer;
	u8 filled;
	u8 item;
	u8 action;
	u8 size;
} rnet_item_action_entry_t;

typedef struct rnet_driver_state_field20_t_
{
	u16 field1 : 7;
	u16 field2 : 5;
	u16 field3 : 2;
	u16 field4 : 2;
} rnet_driver_state_field20_t;

typedef struct rnet_driver_item_action_buffer_t_
{
	u8 itemActions[RNET_MAX_ITEM_ACTIONS];
	u8 itemEventData[RNET_MAX_ITEM_ACTION_SIZE];
} rnet_driver_item_action_buffer_t;

//net driver info state struct
typedef struct rnet_driver_state_t_
{
	u32 field0;
	u32 raceProgress;
	struc_351 state;
	rnet_driver_state_field20_t field20[4];
	rnet_driver_item_action_buffer_t itemActionsBuffer;
} rnet_driver_state_t;

//net race datagram struct
typedef struct rnet_dgram_t_
{
	u8 src : 2;                        //AID of origin
	u8 dst : 2;                        //AID destination
	u8 op : 4;                         //datagram opcode
	u8 field1;
	u8 field2;
	u8 field3;
	u8 data[RNET_MAX_DGRAM_BODY_SIZE]; //message body
} rnet_dgram_t;

typedef struct struc_222_field_68_t_
{
	u32 field0;
	u32 field4;
	u32 frameCounter;
	u16 fieldC;
	u16 fieldE;
	u32 field10;
	u16 field14;
	u8 gap16[0x2];
} struc_222_field_68_t;

typedef struct
{
	rnet_driver_state_t netDriverState;
	struc_222_field_68_t field68;
	int status;
	u16 field84;
	u8 field86a : 1;
	u8 place : 7;
	u8 field87;
} struc_222;

//sync(?) packet struct
typedef struct rnet_packet_sync_t_
{
	u16 srcAid;
	u8 gap2[2];
	OSTick field4;
	OSTick fieldC;
	OSTick field14;
	u32 field1C;
	u32 field20;
	u32 field24;
} rnet_packet_sync_t;

//ping status struct
typedef struct rnet_ping_t_
{
	rnet_packet_sync_t data;
	u32 field28[2];
	u32 field30;
	u8 field34;
	u8 field35;
	u8 field36;
	u8 field37;
} rnet_ping_t;

//rnet_race_state_t flags
#define RNET_STATE_FLAG_0          0x00000001
#define RNET_STATE_FLAG_1          0x00000002
#define RNET_STATE_FLAG_SENDING    0x00000004 /* A DWC send operation is in progress */
#define RNET_STATE_FLAG_4          0x00000010
#define RNET_STATE_FLAG_5          0x00000020
#define RNET_STATE_FLAG_6          0x00000040
#define RNET_STATE_FLAG_7          0x00000080
#define RNET_STATE_FLAG_8          0x00000100
#define RNET_STATE_FLAG_IDLE       0x00000200 /* racer is idle for >= 30s */

//net race state struct
typedef struct
{
    state_machine_t stateMachine;
	rnet_ping_t pingStatuses[4];
	u32 fieldF4;
	u16 lastSentAid;
	u8 heardFromBitmap;
	u8 fieldFB;
    u8 initialAidsBitmap;
	u8 fieldFD;
	u8 gapFE[0x104 - 0xFE];
    struc_222 drivers[4];
	rnet_item_action_entry_t itemActionSlots[16];
	rnet_item_action_entry_t incomingItemActions[RNET_MAX_ITEM_ACTIONS][4];
	u8 itemActionProcessed[RNET_MAX_ITEM_ACTIONS][4];
    s16 bufferAvailable;
	u8 gap726[2];
	int frameCounter;
    int field72C;
    u8 gap730[0x734 - 0x730];
	u16 lastAidSent;
	u16 field_736;
	u16 idleTime;
	u8 nextAid;
	u8 gap73B[0x73E - 0x73B];
	u8 field73E;
	u8 gap73F;
	u16 field740[4];
	u8 sendBufferHeader2;
	u8 connectedAidsBitmap;
	u8 field74A[4];
	u8 field74E[4];
	u8 gap752[0x754 - 0x752];
	rnet_dgram_t *dwcSendBuffer;
	u32 packetNextState;
	u16 flags;
    u8 gap75E[1];
    u8 field75F;
} net_race_state_t;

//struct for mapping between AIDs and driver IDs
typedef struct
{
    s8 driverToAid[4]; //map driver ID -> AID
	u8 initialAids;    //connected AIDs bitmap
	u8 initialized;    //initialized
    s8 aidToDriver[4]; //map AID -> Driver ID
} rnet_aid_map_t;

extern net_race_state_t* gNetRaceState;
extern rnet_aid_map_t* gNetRaceAidMap;
