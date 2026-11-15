#pragma once

#include "types.h"
#include "os_thread.h"

// Two words read as a pair: fsi_ovt9, fsi_ovt7 and the tables in the ROM header.
typedef struct CARDRomRegion {
    /* 00 */ u8 *mOffset;
    /* 04 */ u32 mLength;
} CARDRomRegion;

// The first 0x60 bytes of the ROM header, the part FS_ReadFile reads to find the tables.
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

// The 0x160-byte ROM header the card leaves in OSSystemWork.mRomHeader, and the copy of it kept for the
// application.
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

// Values written to CARDiCommandArg.mPageSize: the page size of the backup devices of 512 bytes, 8 KB and 64 KB, and of
// the large devices. Smaller devices use smaller pages.
enum {
    BACKUP_DEVICE_512B_PAGE_SIZE = 0x10,
    BACKUP_DEVICE_8KB_PAGE_SIZE = 0x20,
    BACKUP_DEVICE_64KB_PAGE_SIZE = 0x80,
    BACKUP_DEVICE_LARGE_PAGE_SIZE = 0x100,
};

// Values written to CARDiCommandArg.mProgramPage: the 64 KB devices use their own value, every other device with one
// the common value.
enum {
    BACKUP_DEVICE_PROGRAM_PAGE_COMMON = 0x4f,
    BACKUP_DEVICE_64KB_PROGRAM_PAGE = 0x9e,
};

// The command block: mResult is the result of the last request.
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
    /* 24 */ u32 mAddrWidth; // address bytes of the device: 1, 2 or 3
    /* 28 */ u32 mProgramPage;
    /* 2c */ u32 mWritePage;
    /* 30 */ u32 mWritePageTotal;
    /* 34 */ u32 mUnk_34;
    /* 38 */ u32 mUnk_38;
    /* 3c */ u32 mUnk_3c;
} CARDiCommandArg;

// 0x620 bytes at gAccessState; mThread is started with the 0x400 bytes at mUnk_220 as its stack.
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
    /* 038 */ UnkFunc *mCallback;
    /* 03c */ u32 mCallbackArg;
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
    /* 00 */ void (*mReadFunc)(struct CARDRomStat *);
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
int CARDi_RequestStreamCommand(u32 src, u32 dst, u32 len, UnkFunc *callback, void *callbackArg, u32 isAsync,
                               u32 reqType, u32 reqRetry, u32 reqMode);
void CARDi_RequestStreamCommandCore(CARDiCommon *common);
UnkFunc *CARDi_GetRomAccessor(void);
int CARD_WaitRomAsync(void);
void CARD_Init(void);
void CARDi_ReadRom(u32 dma, u32 src, u32 dst, u32 len, UnkFunc *callback, u32 callbackArg, u32 isAsync);
void CARDi_ReadRomSyncCore(CARDiCommon *taskCommon);
void CARDi_ReadCard(CARDRomStat *romStat);
int CARDi_TryReadCardDma(CARDRomStat *romStat);
void CARDi_OnReadCard(void);
void CARDi_SetCardDma(void);
void CARDi_SetRomOp(u32 cmd1, u32 cmd2);
int CARDi_ReadFromCache(CARDRomStat *romStat);
int CARDi_Request(CARDiCommon *common, int reqType, int retryCount);
void CARDi_TaskThread(void *arg);
