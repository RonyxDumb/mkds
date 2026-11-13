#pragma once

#include "types.h"

// One 0x1e-byte record of MultiBootParent.
typedef struct MultiBootChildRecord {
    /* 00 */ u8 mUnk_00[0x16];
    /* 16 */ u8 mMacAddress[6];
    /* 1c */ u16 mAid;
} MultiBootChildRecord;

struct MultiBootParent {
    /* 0000 */ u16 mState;
    /* 0002 */ u16 mMask;
    /* 0004 */ u16 mRequestedMask;
    /* 0006 */ u16 mDownloadPendingMask;
    /* 0008 */ u16 mDownloadStartedMask;
    /* 000a */ u16 mUnk_0a;
    /* 000c */ u16 mUnk_0c;
    /* 000e */ MultiBootChildRecord mRecords[15];
    /* 01d0 */ u8 mUnk_01d0[0xfe70];
    /* 10040 */ u8 mCommWork[0xb100];
    /* 1b140 */ void *mCommWorkPointer;
    /* 1b144 */ void *mFileBuffer;
};

#include "03/unk_021da000.h"
#include "code_02142eac.h"

// Fourteen bytes moved as one value.
typedef struct MultiBootParentHeader {
    /* 00 */ u16 mUnk_00[7];
} MultiBootParentHeader;

// Object with the path pointer at 0x00 that RegisterMultiBootFile takes.
typedef struct MultiBootGameRegistryView {
    /* 00 */ const u8 *mRomFilePathp;
} MultiBootGameRegistryView;

void *GetMultiBootChildRecord(u32 index);
u32 GetMultiBootChildState(u32 aid);
u16 GetMultiBootChildMask(u32 maskIndex);
u16 GetMultiBootParentState(void);
void SetMultiBootParentState(u16 state);
void MultiBootParentStateCallback(u32 aid, u32 code, WirelessMessage *event);
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
