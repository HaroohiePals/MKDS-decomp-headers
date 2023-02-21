#pragma once
#include "common.h"
#include "struct217AA00.h"
#include <dwc.h>

typedef struct net_menu_dgram_header_t_
{
	u32 opcode;
	u32 size;
	u8 aidSrc;
	u8 aidDest;
	u8 connectedAids;
	u8 fieldB;
} net_menu_dgram_header_t;

typedef struct net_menu_profile_dgram_t_
{
	net_menu_dgram_header_t header;
	struct_217AA00_field45C_t profile; //user_profile_t
	u32 field238;
	u32 field23C;
	u32 field240;
} net_menu_profile_dgram_t;

typedef struct net_menu_config_t_
{
	u32 field0[4];
	u32 field10[4];
	u32 selectedCourse;
	u32 field24;
	u32 field28;
	u32 vote;
	u8 gap30[4];
	u32 field34;
} net_menu_config_t;

typedef struct net_menu_dgram_t_
{
	net_menu_dgram_header_t header;
	net_menu_config_t data;
} net_menu_dgram_t;

typedef struct net_match_status_t_
{
	u32 state;
	MATHRandContext32 rand;
	u8 gap1C[0x30 - 0x1C];
	u32 field30;
	u32 field34[4];
	u8 gap44[0x49 - 0x44];
	u8 emblemNotSentAidMax;
	u8 gap4A[0x5A - 0x4A];
	u8 receivedHellosBitmap;
	u8 receivedBitmap;
	u8 field5C;
	u8 field5D;
	u8 field5E;
	u8 field5F;
} net_match_status_t;

typedef struct net_field_12F0_t_
{
	u8 gap0[0xC];
	u32 inetStatus;
} net_field_12F0_t;

typedef struct net_match_property_t_
{
	u32 value;
	char key[16];
	u8 field14;
	u8 gap15[2];
	u8 field16;
} net_match_property_t;

typedef struct net_state_field_B2C_t_
{
	//DWCFriendsMatchControl control;
	u8 control[0xDB4]; //an estimate
	u8 fieldDB4;
	u8 fieldDB5;
	u8 gapDB6[2];
	u32 fieldDB8;
	u32 state;
	net_match_property_t region;
	net_match_property_t matchType;
	net_match_property_t fieldDF0;
	net_match_property_t elo;
	u8 numPlayersMatch;
	u8 nFriendsInMatchmaker;
	u8 fieldE22;
	u8 fieldE23;
} net_state_field_B2C_t;

typedef struct net_state_t_
{
	NNSFndHeapHandle heap;
	void *heapMem;
	state_machine_t stateMachine;
	u8 raceRecvBuffers[4][128];
	net_menu_profile_dgram_t profileDatagramBuffers[4];
	net_state_field_B2C_t fieldB2C;
	net_match_status_t matchStatus;
	DWCAccUserData userData;
	DWCAccFriendData friends[60];
	u8 friendStatuses[60];
	int friendListChanged;
	net_menu_dgram_t menuRecvBuffers[4];
	net_menu_dgram_t menuSendBuffers[4];
	net_field_12F0_t field1F20;
	int heapInitialized;
	int field1F34;
	int field1F38;
	u32 frameCount;
	int field1F40;
	int lastError;
	int field1F48;
	u8 field1F4C;
	u8 field1F4D;
	u8 field1F4E[4];
	u8 numConnections;
	u8 aidMax;
	u8 field1F54;
	u8 connectedAids;
	u8 newlyDisconnectedAidsBitmap;
	u8 lastFriendStatusFetched;
} net_state_t;

extern net_state_t* gNetState;

static inline BOOL netstate_inline1()
{
    return gNetState && gNetState->heapInitialized;
}
