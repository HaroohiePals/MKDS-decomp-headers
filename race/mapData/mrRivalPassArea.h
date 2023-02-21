#pragma once

void area_initMissionRivalPassAreas(NNSFndHeapHandle hnd);
void area_finalizeMissionRivalPassAreas();
BOOL area_updateMissionRivalPassAreas();

typedef struct
{
    u16 index;
    fx32 size;
    u8 prevNrObjsInside;
    u8 passCount;
} area_mission_rival_pass_area_t;

typedef struct
{
    area_mission_rival_pass_area_t* entries;
    u16 count;
} area_mission_rival_pass_area_status_t;