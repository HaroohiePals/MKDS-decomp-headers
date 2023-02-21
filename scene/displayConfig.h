#pragma once

#define DC_MASTERBRIGHT_STATE_FADED_OUT     0
#define DC_MASTERBRIGHT_STATE_FADING_IN     1
#define DC_MASTERBRIGHT_STATE_FADED_IN      2
#define DC_MASTERBRIGHT_STATE_FADING_OUT    3

#define DC_MASTERBRIGHT_TYPE_BLACK          0
#define DC_MASTERBRIGHT_TYPE_WHITE          1

typedef struct
{
    u16 state;
    u16 fadeType;
    s16 curFrame;
    s16 frameCount;
    s16 brightness;
    u16 fieldA;
} dc_masterbright_t;

typedef struct
{
    u16 vblankWaitCount; ///< The amount of OS_WaitVBlankIntr calls between frames
    u16 mainVisiblePlane;
    u16 subVisiblePlane;
    u16 mainDisplayMode;
    u16 mainBgMode;
    u16 mainBg03d;
    u16 subBgMode;
    u16 mainBgBank;
    u16 mainObjBank;
    u16 mainBgExtPlttBank;
    u16 mainObjExtPlttBank;
    u16 texBank;
    u16 texPlttBank;
    u16 clearImgBank;
    u16 subBgBank;
    u16 subObjBank;
    u16 subBgExtPlttBank;
    u16 subObjExtPlttBank;
    u16 arm7Bank;
    u16 lcdcBank;
} display_config_base_t;

typedef struct
{
    u16 priority;
    u16 mosaic;
    u16 screenSize;
    u16 colorMode;
    u16 screenBase;
    u16 characterBase;
} display_config_bgcommon_t;

typedef struct
{
    display_config_bgcommon_t common;
    u16 extPlttSlot;
    u16 unk;
} display_config_bg01_t;

typedef enum
{
    DC_BG23_MODE_TEXT = 1,
    DC_BG23_MODE_AFFINE,
    DC_BG23_MODE_AFFINE_EXT,
    DC_BG23_MODE_256_BMP,
    DC_BG23_MODE_DC_BMP
} DcBg23Mode;

typedef struct
{
    DcBg23Mode mode;
    display_config_bgcommon_t common;
    // u16 priority;
    // u16 mosaic;
    //
    // union
    // {
    //     u16 screenSize;
    //     u16 areaOverMode;
    // };
    //
    // u16 colorMode;
    // u16 screenBase;
    // u16 characterBase;
} display_config_bg23_t;

typedef struct
{
    display_config_bg01_t bg0Config;
    display_config_bg01_t bg1Config;
    display_config_bg23_t bg2Config;
    display_config_bg23_t bg3Config;
    u16 objVRamModeChar;
    u16 objVRamModeBmp;
} display_config_engine_t;

//this seems to be 8 bytes in mkds?
//maybe something is missing
typedef struct
{
    u16 clearColor;
    u8 sortMode;
    u8 bufferMode;
} display_config_3d_t;

typedef void (*display_config_vblank_func_t)();

#define DISPLAY_CONFIG_FLAGS_BEFORE_VBLANK	        (1 << 0)
#define DISPLAY_CONFIG_FLAGS_FRAME_TIME_EXCEEDED	(1 << 1)

typedef struct
{
    display_config_base_t baseConfig;
    display_config_engine_t mainConfig;
    display_config_3d_t* config3d;
    display_config_engine_t subConfig;
    u32 fieldB4;
    display_config_vblank_func_t vblankFunc;
    OSTick frameStartTime;
    OSTick vblankTime;
    u32 renderDuration;
    u32 lastTotalDuration;
    u32 lastRenderDuration;
    u8 flags;
} display_config_t;

typedef void (*display_config_dword_21755A4_func_t)(int unknown);
extern display_config_dword_21755A4_func_t dword_21755A4;

extern display_config_t* gCurDisplayConfig;

void dc_initFade(void);
void dc_enableDisplay(void);
display_config_t* dc_createDisplayConfig(NNSFndHeapHandle heapHandle, const display_config_base_t* baseConfig);
void dc_setBg0Config(display_config_engine_t* bgConfig, int priority, BOOL mosaic, GXBGScrSizeText screenSize,
                     GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase, GXBGExtPltt extPlttSlot);
void dc_setBg1Config(display_config_engine_t* bgConfig, int priority, BOOL mosaic, GXBGScrSizeText screenSize,
                     GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase, GXBGExtPltt extPlttSlot);
void dc_setBg2Config(display_config_engine_t* bgConfig, int priority, BOOL mosaic, GXBGScrSizeText screenSize,
                     GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase);
void dc_setBg3Config(display_config_engine_t* bgConfig, int priority, BOOL mosaic, GXBGScrSizeText screenSize,
                     GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase);
void dc_setBg2ConfigDcBmp(display_config_engine_t* bgConfig, int priority, BOOL mosaic, GXBGScrSizeDcBmp screenSize,
                          GXBGAreaOver areaOverMode, GXBGScrBase screenBase);
void dc_set3DSwapConfig(display_config_t* config, GXSortMode sortMode, GXBufferMode bufferMode);
void dc_setSubObjBmpMode(display_config_t* config, GXOBJVRamModeBmp bmpMode);
void dc_setDisplayConfig(display_config_t* config);
void dc_unsetDisplayConfig(void);
void dc_handleStartOfFrame(void);
BOOL dc_wasFrameTimeExceeded(void);
void dc_notifyVBlank(void);
void dc_2037658(BOOL a1);
void dc_2037498(BOOL a1);
void dc_handleEndOfFrame(void);

void dc_fadeInSingle(s16 frameCount, BOOL main);
void dc_fadeIn(s16 frameCount);
void dc_fadeFromBlackSingle(s16 frameCount, BOOL main);
void dc_fadeFromBlack(s16 frameCount);
void dc_fadeToBlackSingle(s16 frameCount, BOOL main);
void dc_fadeToBlack(s16 frameCount);
void dc_fadeToWhiteSingle(s16 frameCount, BOOL main);
void dc_fadeToWhite(s16 frameCount);
BOOL dc_isFadedOut(void);
void dc_resetFade(void);
BOOL dc_isFadedIn(void);

static inline void dc_setMainBg0Config(display_config_t* displayConfig, int priority, BOOL mosaic,
                                       GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase,
                                       GXBGCharBase charBase, GXBGExtPltt extPlttSlot)
{
    dc_setBg0Config(&displayConfig->mainConfig, priority, mosaic, screenSize, colorMode, screenBase, charBase,
                    extPlttSlot);
}

static inline void dc_setMainBg1Config(display_config_t* displayConfig, int priority, BOOL mosaic,
                                       GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase,
                                       GXBGCharBase charBase, GXBGExtPltt extPlttSlot)
{
    dc_setBg1Config(&displayConfig->mainConfig, priority, mosaic, screenSize, colorMode, screenBase, charBase,
                    extPlttSlot);
}

static inline void dc_setMainBg2Config(display_config_t* displayConfig, int priority, BOOL mosaic,
                                       GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase,
                                       GXBGCharBase charBase)
{
    dc_setBg2Config(&displayConfig->mainConfig, priority, mosaic, screenSize, colorMode, screenBase, charBase);
}

static inline void dc_setMainBg3Config(display_config_t* displayConfig, int priority, BOOL mosaic,
                                       GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase,
                                       GXBGCharBase charBase)
{
    dc_setBg3Config(&displayConfig->mainConfig, priority, mosaic, screenSize, colorMode, screenBase, charBase);
}

static inline void dc_setMainBg2ConfigDcBmp(display_config_t* displayConfig, int priority, BOOL mosaic,
                                            GXBGScrSizeDcBmp screenSize, GXBGAreaOver areaOverMode,
                                            GXBGScrBase screenBase)
{
    dc_setBg2ConfigDcBmp(&displayConfig->mainConfig, priority, mosaic, screenSize, areaOverMode, screenBase);
}

static inline void dc_setSubBg0Config(display_config_t* displayConfig, int priority, BOOL mosaic,
                                      GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase,
                                      GXBGCharBase charBase, GXBGExtPltt extPlttSlot)
{
    dc_setBg0Config(&displayConfig->subConfig, priority, mosaic, screenSize, colorMode, screenBase, charBase,
                    extPlttSlot);
}

static inline void dc_setSubBg1Config(display_config_t* displayConfig, int priority, BOOL mosaic,
                                      GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase,
                                      GXBGCharBase charBase, GXBGExtPltt extPlttSlot)
{
    dc_setBg1Config(&displayConfig->subConfig, priority, mosaic, screenSize, colorMode, screenBase, charBase,
                    extPlttSlot);
}

static inline void dc_setSubBg2Config(display_config_t* displayConfig, int priority, BOOL mosaic,
                                      GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase,
                                      GXBGCharBase charBase)
{
    dc_setBg2Config(&displayConfig->subConfig, priority, mosaic, screenSize, colorMode, screenBase, charBase);
}

static inline void dc_setSubBg3Config(display_config_t* displayConfig, int priority, BOOL mosaic,
                                      GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase,
                                      GXBGCharBase charBase)
{
    dc_setBg3Config(&displayConfig->subConfig, priority, mosaic, screenSize, colorMode, screenBase, charBase);
}

static inline void dc_setSubBg2ConfigDcBmp(display_config_t* displayConfig, int priority, BOOL mosaic,
                                           GXBGScrSizeDcBmp screenSize, GXBGAreaOver areaOverMode,
                                           GXBGScrBase screenBase)
{
    dc_setBg2ConfigDcBmp(&displayConfig->subConfig, priority, mosaic, screenSize, areaOverMode, screenBase);
}
