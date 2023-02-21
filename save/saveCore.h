#pragma once

#define SAVC_SAVE_HEADER_SIGNATURE      ((u64)MKTAG('M', 'K', 'D', 'S') | ((u64)MKTAG('S', 'V', '1', '0') << 32))

typedef enum
{
    SAVC_STATUS_0,
    SAVC_STATUS_1,
    SAVC_STATUS_2,
    SAVC_STATUS_3,
    SAVC_STATUS_4
} SaveCoreStatus;

typedef enum
{
    SAVC_ERROR_NONE,
    SAVC_ERROR_1,
    SAVC_ERROR_2,
    SAVC_ERROR_INVALID_BLOCK,
    SAVC_ERROR_INVALID_HEADER_SIGNATURE
} SaveCoreError;

typedef enum
{
    SAVC_TRANSFER_TYPE_DIRECT,
    SAVC_TRANSFER_TYPE_WITH_BACKUP,
    SAVC_TRANSFER_TYPE_WITH_BACKUP_RETRY
} SaveCoreTransferType;

typedef int (*savc_transfer_callback_t)(u8* data, int length);

typedef struct
{
    SaveCoreStatus status;
    SaveCoreError error;
    u32 backupLock;
    BOOL isEnabled;
    BOOL isBusy;
    SaveCoreTransferType transferType;
    u32 backupSrcDst;
    SaveCoreError originalError;
    u8* originalSrcDst;
    u16 originalTimestamp;
    u16 field26;
    u8* readDst;
    u32 readSrc;
    u32 readLen;
    u32 readBlockSignature;
    BOOL readBlockIsHeader;
    u32 field3C;
    u8* writeSrc;
    u32 writeDst;
    u32 writeLength;
    u32 field4C;
    BOOL writeBlockIsHeader;
    void* callbackArg;
    u32 field58;
    u32 field5C;
    void* tmpBuf;
    void* testByte;
    u32 realDst;
    u8 field6C;
    u8 field6D;
    u8 field6E;
    u8 field6F;
} save_core_t;

extern save_core_t* gSaveCore;

void savc_init(NNSFndHeapHandle heapHandle);
void savc_initBackup();
BOOL savc_readBlock(u32 src, u8* dst, u32 length, savc_transfer_callback_t callback, u32 blockMagic);
BOOL savc_readWithBackup(u32 src, u32 backupSrc, u8* dst, u32 length, savc_transfer_callback_t callback, u32 blockMagic,
    BOOL isHeader);
BOOL savc_writeWithBackup(u32 dst, u32 backupDst, u8* src, u32 length, savc_transfer_callback_t callback, BOOL isHeader);
BOOL savc_writeBlock(u32 dst, u8* src, u32 length, savc_transfer_callback_t callback);

static inline BOOL savc_isEnabled()
{
    return gSaveCore->isEnabled;
}

static inline BOOL savc_isBusy()
{
    return savc_isEnabled() ? gSaveCore->isBusy : FALSE;
}
