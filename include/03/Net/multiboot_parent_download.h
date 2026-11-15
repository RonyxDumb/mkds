#pragma once

#include "types.h"
#include "03/Net/wh.h"

// One 0x1e-byte record of MultiBootParent.
typedef struct MultiBootChildRecord {
    /* 00 */ u8 mUnk_00[0x16];
    /* 16 */ u8 mMacAddress[6];
    /* 1c */ u16 mAid;
} MultiBootChildRecord;

// The first 0xe bytes of MultiBootParent: the state and the child masks.
typedef struct MultiBootParentHeader {
    /* 00 */ u16 mState;
    /* 02 */ u16 mMask;
    /* 04 */ u16 mRequestedMask;
    /* 06 */ u16 mDownloadPendingMask;
    /* 08 */ u16 mDownloadStartedMask;
    /* 0a */ u16 mSendCompleteMask;
    /* 0c */ u16 mBootStartableMask;
} MultiBootParentHeader;

struct MultiBootParent {
    /* 0000 */ MultiBootParentHeader mHeader;
    /* 000e */ MultiBootChildRecord mRecords[1];
    /* 002c */ u8 mFileData[0x10000];
    /* 1002c */ u8 mUnk_1002c[0x14];
    /* 10040 */ u8 mCommWork[0xb100];
    /* 1b140 */ void *mCommWorkPointer;
    /* 1b144 */ void *mFileBuffer;
    /* 1b148 */ u8 mUnk_1b148[0x18];
    /* 1b160 */ WhWork mWhWork;
};

#include "03/unk_021da000.h"
#include "code_02142eac.h"

// Object with the path pointer at 0x00 that RegisterMultiBootFile takes.
typedef struct MultiBootGameRegistryView {
    /* 00 */ const u8 *mRomFilePathp;
} MultiBootGameRegistryView;

void *GetMultiBootChildRecord(u32 index);
u32 GetMultiBootChildState(u32 aid);
u16 GetMultiBootChildMask(u32 maskIndex);
u16 GetMultiBootParentState(void);
void SetMultiBootParentState(u16 state);
void MultiBootParentStateCallback(u32 aid, u32 code, void *data);
void StartMultiBootEndToIdle(void);
void StartMultiBootBootRequests(void);
BOOL AreMultiBootChildrenBootable(void);
void StartMultiBootDownloads(void);
void StartMultiBootChildDownload(u32 aid);
void KickMultiBootChild(u32 aid);
void AcceptMultiBootChildRequest(u32 aid);
BOOL RegisterMultiBootFile(MultiBootGameRegistryView *gameRegistry);
void StartMultiBootParentFromIdle(MultiBootGameRegistryView *gameRegistry, u16 channel);
void InitMultiBootParentComm(u32 ggid, u32 tgid);
void InitMultiBootParent(u8 *object);

extern u16 *gMultiBootMaskPointers[6];
