#pragma once
//I wanted this to be an enum, but that doesn't work
//FSOverlayID
#if __MWERKS__ > 0
FS_EXTERN_OVERLAY(o0wifi);
FS_EXTERN_OVERLAY(o2mission);
FS_EXTERN_OVERLAY(o3unk);
FS_EXTERN_OVERLAY(o1wifiutil);

#define OVERLAY_WIFI	FS_OVERLAY_ID(o0wifi)
#define OVERLAY_MISSION	FS_OVERLAY_ID(o2mission)
#define OVERLAY_UNK		FS_OVERLAY_ID(o3unk)
#define OVERLAY_UTIL	FS_OVERLAY_ID(o1wifiutil)
#else
//to keep visual studio happy, those are also the original mkds ids
#define OVERLAY_WIFI	0
#define OVERLAY_MISSION	1
#define OVERLAY_UNK		2
#define OVERLAY_UTIL	3
#endif

extern u32 SDK_OVERLAY_wifio_START;
extern u32 SDK_OVERLAY_wifio_BSS_END;
extern u32 SDK_OVERLAY_missiono_START;
extern u32 SDK_OVERLAY_missiono_BSS_END;
extern u32 SDK_OVERLAY_unko_START;
extern u32 SDK_OVERLAY_unko_BSS_END;
extern u32 SDK_OVERLAY_utilo_START;
extern u32 SDK_OVERLAY_utilo_BSS_END;

typedef struct
{
    u32 id;
    u32 start;
    u32 end;
} overlay_data_overlayinfo_t;

typedef struct
{
    u32 curOverlay;
    u32 state;
    overlay_data_overlayinfo_t overlays[3];
    FSOverlayInfo overlayInfo;
    FSFile overlayFile;
    NNSFndHeapHandle overlayFrmHeap;
    NNSFndHeapHandle overlayExpHeap;
    u32 overlayRegionStart;
    u32 overlayRegionEnd;
} overlay_data_t;

extern overlay_data_t* gOverlayData;

void overlay_init(NNSFndHeapHandle heapHandle);
void overlay_reset();
void overlay_beginLoad(u32 overlay);
void overlay_finishLoad();
void overlay_destroyExpHeap();
BOOL overlay_tryFinishLoad();
void overlay_unload();
BOOL overlay_isAddressInOverlay(void* address);
