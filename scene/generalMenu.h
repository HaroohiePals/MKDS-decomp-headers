#pragma once

typedef struct
{
    BOOL unknownLoaded;
    BOOL selectChoisesLoaded;
    BOOL selectReturnLoaded;
    u32 fieldC;
    GXScrFmtText screenTmpBuf[0x400];
    u32 charVramLeft;
} gmenu_context_t;

typedef struct
{
    BOOL loadUnknown; //Wireless related
    const NNSG2dFont* unkFont;
    u32 field8;
    u32 fieldC;
    u32 field10;
    BOOL loadSelectChoises;
    const NNSG2dFont* selectChoisesFont;
    BOOL loadSelectReturn;
    BOOL loadBackground;
    u32 field24;
} gmenu_config_t;

typedef struct
{
    u32 field0;
    u32 field4;
    u32 field8;
    u32 fieldC;
    GXScrFmtText screenTmpBuf[0x400];
    u32 field810;
    u32 field814;
    u32 field818;
    u32 field81C;
    BOOL field820;
    u32 seqArcIndex;
} gmenu_select_return_context_t;

void sub_2128310(int a);
void gmenu_setSeqArcIndex(int a);
void sub_2128374();
BOOL sub_2128294();
void sub_21282C8();

void gmenu_loadSystemGraphics();

BOOL gmenu_checkSelectReturnTouch(int x, int y);
void gmenu_init(NNSFndHeapHandle heapHandle, const gmenu_config_t* config);
void gmenu_finish();
void gmenu_render();
void gmenu_vblank();
