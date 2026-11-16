#pragma once

#include "types.h"
#include "thread_scheduler.h"

// Callback of a card or backup transfer; it is called with the argument stored beside it.
typedef void (*CARDCallback)(void *arg);
typedef struct CARDRomStat CARDRomStat;
typedef void (*RomPageReadFunc)(CARDRomStat *romStat);

// An offset and a length: the type of fsi_ovt9, fsi_ovt7 and the tables in the ROM header.
typedef struct CARDRomRegion {
    /* 00 */ u8 *mOffset;
    /* 04 */ u32 mLength;
} CARDRomRegion;

// The start of the ROM header: the main and sub program sizes and the file and overlay tables; FS_ReadFile reads this
// part of a ROM file.
typedef struct RomHeaderStart {
    /* 00 */ u8 mUnk_00[0x20];
    /* 20 */ u32 mMainRomOffset;
    /* 24 */ u8 mMainEntryAddress[0x4];
    /* 28 */ u32 mMainRamAddress;
    /* 2c */ u32 mMainSize;
    /* 30 */ u32 mSubRomOffset;
    /* 34 */ u8 mUnk_34[0x8];
    /* 3c */ u32 mSubSize;
    union {
        struct {
            /* 40 */ u32 mFntOffset;
            /* 44 */ u32 mFntSize;
        };
        /* 40 */ CARDRomRegion mFntTable;
    };
    union {
        struct {
            /* 48 */ u32 mFatOffset;
            /* 4c */ u32 mFatSize;
        };
        /* 48 */ CARDRomRegion mFatTable;
    };
    union {
        struct {
            /* 50 */ u32 mOverlayTable0Offset;
            /* 54 */ u32 mOverlayTable0Size;
        };
        /* 50 */ CARDRomRegion mOverlayTable0;
    };
    union {
        struct {
            /* 58 */ u32 mOverlayTable1Offset;
            /* 5c */ u32 mOverlayTable1Size;
        };
        /* 58 */ CARDRomRegion mOverlayTable1;
    };
} RomHeaderStart;

// The ROM header as held in OSSystemWork.mRomHeader; CARDi_InitCommon copies it to HW_CARD_ROM_HEADER unless the boot
// type is multiboot.
typedef struct CARDRomHeader {
    /* 00 */ RomHeaderStart mHead;
    /* 60 */ u32 mRomCtrl;
    /* 64 */ u8 mUnk_64[0x1c];
    /* 80 */ u32 mRomSize;
    /* 84 */ u8 mUnk_84[0xdc];
} CARDRomHeader;

#define HW_CARD_ROM_HEADER ((CARDRomHeader *) 0x027ffa80)

// Values of CARDiCommandArg.mResult: the request is repeated while it is ROM_ACCESS_AGAIN; 3 is stored for an
// unsupported backup type, 7 when the request flag 0x40 was set.
typedef enum RomAccessResult {
    ROM_ACCESS_SUCCEEDED = 0,
    ROM_ACCESS_UNSUPPORTED_TYPE = 3,
    ROM_ACCESS_AGAIN = 4,
    ROM_ACCESS_CALLED_OFF = 7
} RomAccessResult;

// Sizes of the backup devices CARDi_IdentifyBackupCore accepts (the size is 1 << ((type >> 8) & 0xff)).
enum {
    BACKUP_DEVICE_SIZE_512B = 0x200,
    BACKUP_DEVICE_SIZE_8KB = 0x2000,
    BACKUP_DEVICE_SIZE_32KB = 0x8000,
    BACKUP_DEVICE_SIZE_64KB = 0x10000,
    BACKUP_DEVICE_SIZE_256KB = 0x40000,
    BACKUP_DEVICE_SIZE_512KB = 0x80000,
    BACKUP_DEVICE_SIZE_1MB = 0x100000,
};

// Values written to CARDiCommandArg.mPageSize: type 1 devices of 512 bytes, 8 KB and 64 KB and all type 2 (large)
// devices get one of these; type 3 devices store their whole size instead.
enum {
    BACKUP_DEVICE_512B_PAGE_SIZE = 0x10,
    BACKUP_DEVICE_TYPE1_8KB_PAGE_SIZE = 0x20,
    BACKUP_DEVICE_64KB_PAGE_SIZE = 0x80,
    BACKUP_DEVICE_LARGE_PAGE_SIZE = 0x100,
};

// Sector size written to CARDiCommandArg.mSectSize for the large devices, and the priority of the worker thread.
#define BACKUP_DEVICE_LARGE_SECTOR_SIZE 0x10000
#define ACCESS_TASK_THREAD_PRIORITY 4

// Values written to CARDiCommandArg.mProgramPage: the 64 KB devices use their own value, every other device with one
// the common value.
enum {
    BACKUP_DEVICE_PROGRAM_PAGE_COMMON = 0x4f,
    BACKUP_DEVICE_64KB_PROGRAM_PAGE = 0x9e,
};

// The block whose address CARDi_Request sends on tag 11: mSrc, mDst and mLen describe the transfer, mType to
// mWritePageTotal the backup device, mResult is the result of the last request.
typedef struct CARDiCommandArg {
    /* 00 */ u32 mResult;
    /* 04 */ s32 mType;
    /* 08 */ u32 mId;
    /* 0c */ u32 mSrc;
    /* 10 */ u32 mDst;
    /* 14 */ u32 mLen;
    /* 18 */ u32 mTotalSize;
    /* 1c */ u32 mSectSize;
    /* 20 */ u32 mPageSize;
    /* 24 */ u32 mAddrWidth; // address bytes of the device: 1, 2 or 3; 0 when no type is set
    /* 28 */ u32 mProgramPage;
    /* 2c */ u32 mWritePage;
    /* 30 */ u32 mWritePageTotal;
    /* 34 */ u32 mUnk_34;
    /* 38 */ u32 mUnk_38;
    /* 3c */ u32 mUnk_3c;
} CARDiCommandArg;

// Bits of CARDiCommon.mFlag. Nothing in the tree sets WAKE_WORKER or STOP_REQUESTED; WAKE_WORKER is tested when a
// transfer ends and STOP_REQUESTED before each piece of a backup transfer.
enum {
    ACCESS_FLAG_INITIALIZED = 0x1,
    ACCESS_FLAG_REQUEST_SETUP_STARTED = 0x2,
    ACCESS_FLAG_BUSY = 0x4,
    ACCESS_FLAG_TASK_PENDING = 0x8,
    ACCESS_FLAG_WAKE_WORKER = 0x10,
    ACCESS_FLAG_REQUEST_PENDING = 0x20,
    ACCESS_FLAG_STOP_REQUESTED = 0x40,
    ACCESS_FLAG_TRANSFER_MASK =
        ACCESS_FLAG_BUSY | ACCESS_FLAG_TASK_PENDING | ACCESS_FLAG_STOP_REQUESTED,
};

// The ROM is read in pages of CARD_ROM_PAGE_SIZE bytes; a DMA channel is used only for numbers 0 to
// ROM_CARD_LAST_DMA_CHANNEL.
#define CARD_ROM_PAGE_SIZE 0x200
#define ROM_CARD_LAST_DMA_CHANNEL 3

// The common state of the card access: the command block, lock, transfer arguments, callback, worker thread, flags and
// the backup page buffer.
typedef struct CARDiCommon {
    /* 000 */ CARDiCommandArg *mCmd;
    /* 004 */ s32 mCommand;
    /* 008 */ vs32 mLockOwner;
    /* 00c */ vs32 mLockRef;
    /* 010 */ OSThreadQueue mLockQueue;
    /* 018 */ u32 mLockTarget;
    /* 01c */ u32 mSrc;
    /* 020 */ u32 mDst;
    /* 024 */ u32 mLen;
    /* 028 */ u32 mDma;
    /* 02c */ u32 mReqType;
    /* 030 */ u32 mReqRetry;
    /* 034 */ u32 mReqMode;
    /* 038 */ CARDCallback mCallback;
    /* 03c */ void *mCallbackArg;
    /* 040 */ void (*mTaskFunc)(struct CARDiCommon *);
    /* 044 */ OSThread mThread;
    /* 104 */ OSThread *mCurTh;
    /* 108 */ u32 mPriority;
    /* 10c */ OSThreadQueue mBusyQ;
    /* 114 */ vu32 mFlag;
    /* 118 */ u8 mUnk_118[8];
    /* 120 */ u8 mBackupCachePageBuf[0x100];
    /* 220 */ u8 mUnk_220[0x400];
} CARDiCommon;

// The ROM read state: the page reader, the control word, the page held in the cache buffer and the cache buffer.
typedef struct CARDRomStat {
    /* 00 */ RomPageReadFunc mReadFunc;
    /* 04 */ u32 mCtrl;
    /* 08 */ u32 mCachePage;
    /* 0c */ u8 mDummy[0x14];
    /* 20 */ u32 mCacheBuf[0x80];
} CARDRomStat;

// Added to the offset of every ROM read in CARDi_ReadRom; CARD_Init writes 0 and nothing else writes it.
extern u32 gRomBaseOffset;
extern CARDRomStat gRomReadState;

void CARDi_InitCommon(void);
void CARDi_UnlockResource(u32 owner, u32 target);
void CARDi_LockResource(u32 owner, u32 target);
void CARDi_SetTask(void (*task)(CARDiCommon *));
void CARDi_IdentifyBackupCore(s32 type);
int CARD_TryWaitBackupAsync(void);
int CARD_WaitBackupAsync(void);
int CARD_IdentifyBackup(s32 type);
int CARDi_RequestStreamCommand(u32 src, u32 dst, u32 len, CARDCallback callback, void *callbackArg, u32 isAsync,
                               u32 reqType, u32 reqRetry, u32 reqMode);
void CARDi_RequestStreamCommandCore(CARDiCommon *common);
RomPageReadFunc CARDi_GetRomAccessor(void);
int CARD_WaitRomAsync(void);
void CARD_Init(void);
void CARDi_ReadRom(u32 dma, u32 src, u32 dst, u32 len, CARDCallback callback, void *callbackArg, u32 isAsync);
void CARDi_ReadRomSyncCore(CARDiCommon *taskCommon);
void CARDi_ReadCard(CARDRomStat *romStat);
int CARDi_TryReadCardDma(CARDRomStat *romStat);
void CARDi_OnReadCard(void);
void CARDi_SetCardDma(void);
void CARDi_SetRomOp(u32 cmd1, u32 cmd2);
int CARDi_ReadFromCache(CARDRomStat *romStat);
int CARDi_Request(CARDiCommon *common, int reqType, int retryCount);
void CARDi_TaskThread(void *arg);
