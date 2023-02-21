#pragma once
#include "pad.h"
#include "inputRecorder.h"
#include "spi.h"

#define INPUT_PADDATA_FLAGS_BIT0		(1 << 0)
#define INPUT_PADDATA_FLAGS_BIT1		(1 << 1)
#define INPUT_PADDATA_FLAGS_MIRROR		(1 << 2)
#define INPUT_PADDATA_FLAGS_BIT3		(1 << 3)

typedef struct
{
    u16 field0; //?
    u16 pressedKeys;
    u16 flags;
    u16 field6; //?
    u32 field8;
    u32 fieldC;
} input_pad_data_t;

typedef enum
{
    INPUT_UNIT_MODE_DISABLED,
    INPUT_UNIT_MODE_REPLAYER,
    INPUT_UNIT_MODE_RECORDER,
    INPUT_UNIT_MODE_VIRTUAL,
    INPUT_UNIT_MODE_4,
    INPUT_UNIT_MODE_MASTER, //own input when unconnected, communication master input otherwise
    INPUT_UNIT_MODE_DIRECT, //always own input
    INPUT_UNIT_MODE_WIFI
} InputUnitMode;

typedef enum
{
    INPUT_UNIT_ID_0,
    INPUT_UNIT_ID_1,
    INPUT_UNIT_ID_2,
    INPUT_UNIT_ID_3,
    INPUT_UNIT_ID_4,
    INPUT_UNIT_ID_5,
    INPUT_UNIT_ID_6,
    INPUT_UNIT_ID_7,
    INPUT_UNIT_ID_MASTER,
    INPUT_UNIT_ID_DIRECT,

    INPUT_UNIT_COUNT
} InputUnitId;

typedef struct
{
    input_pad_t pad;
    input_rec_t inputRecorder;
    u32 field38;
    InputUnitMode mode;
    u16 virtualPadKeys;
    u16 keyMask;
    BOOL field44;
    input_tpmic_t tpMic;
} input_unit_t;

extern input_unit_t gInputUnits[INPUT_UNIT_COUNT];

void input_init(NNSFndHeapHandle heapHandle);
void input_initUnits();
void input_2043B48();
void input_stopTouchAutoSampling();
void input_clearPads();
void input_2043AE0();
void input_finalize();
void input_setMirrorMode(BOOL mirror);
void input_sample();
u16 input_getPressedKeys();
void input_update();
void input_pressVirtualPadKeys(InputUnitId unit, u16 keys);
void input_setFlagsBit0(BOOL a1);
BOOL input_getIsResetInvoked();
InputUnitId input_getDirectInputUnitId();
BOOL input_getFlagsBit0();
void input_setFlagsBit1(BOOL a1);
void input_2043410();
void input_20431E4();

static inline input_unit_t* input_getInputUnitById(InputUnitId id)
{
    return &gInputUnits[id];
}

static inline u16 input_isSetPadTrigById(InputUnitId id, u16 mask)
{
    return pad_isSetPadTrig(&gInputUnits[id].pad, mask);
}

static inline u16 input_isSetPadRepById(InputUnitId id, u16 mask)
{
    return pad_isSetPadRep(&gInputUnits[id].pad, mask);
}

static inline u16 input_isSetPadPressById(InputUnitId id, u16 mask)
{
    return pad_isSetPadPress(&gInputUnits[id].pad, mask);
}

static inline void input_setKeyMask(InputUnitId id, u16 mask)
{
    gInputUnits[id].keyMask = mask;
}

static inline u32 input_getTpXById(InputUnitId id)
{
    return spi_getTpX(&gInputUnits[id].tpMic);
}

static inline u32 input_getTpYById(InputUnitId id)
{
    return spi_getTpY(&gInputUnits[id].tpMic);
}

static inline BOOL input_getTpValidById(InputUnitId id)
{
    return spi_getTpValid(&gInputUnits[id].tpMic);
}

static inline int input_getMasterInputUnitId()
{
    return INPUT_UNIT_ID_MASTER;
}

static inline BOOL input_isValidPenDownEventById(InputUnitId id)
{
    return spi_isValidPenDownEvent(&gInputUnits[id].tpMic);
}
