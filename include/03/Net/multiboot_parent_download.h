#pragma once

#include "types.h"
#include "03/Net/wh.h"

// Values of MultiBootParentHeader.mState: READY after the setup, ACCEPTING_CHILDREN while the parent waits for
// children, DOWNLOADING once the downloads started, BOOTING once the boot requests went out, BOOTED when the parent
// ended after that, ENDING after the end request, FAILED when a call failed or no child answered the boot request.
#define MULTIBOOT_PARENT_STATE_ENDED 0
#define MULTIBOOT_PARENT_STATE_READY 1
#define MULTIBOOT_PARENT_STATE_ACCEPTING_CHILDREN 2
#define MULTIBOOT_PARENT_STATE_DOWNLOADING 3
#define MULTIBOOT_PARENT_STATE_BOOTING 4
#define MULTIBOOT_PARENT_STATE_BOOTED 5
#define MULTIBOOT_PARENT_STATE_ENDING 6
#define MULTIBOOT_PARENT_STATE_FAILED 7

// Indexes of GetMultiBootChildMask, the masks of MultiBootParentHeader in order, and the values GetMultiBootChildState
// returns for the first mask a child is in (CONNECTED to BOOT_STARTABLE), 0 for a child that is not connected.
#define MULTIBOOT_CHILD_MASK_CONNECTED 0
#define MULTIBOOT_CHILD_MASK_REQUESTED 1
#define MULTIBOOT_CHILD_MASK_DOWNLOAD_PENDING 2
#define MULTIBOOT_CHILD_MASK_DOWNLOAD_STARTED 3
#define MULTIBOOT_CHILD_MASK_SEND_COMPLETE 4
#define MULTIBOOT_CHILD_MASK_BOOT_STARTABLE 5
#define MULTIBOOT_CHILD_STATE_NOT_CONNECTED 0
#define MULTIBOOT_CHILD_STATE_CONNECTED 1
#define MULTIBOOT_CHILD_STATE_REQUESTED 2
#define MULTIBOOT_CHILD_STATE_DOWNLOAD_PENDING 3
#define MULTIBOOT_CHILD_STATE_DOWNLOAD_STARTED 4
#define MULTIBOOT_CHILD_STATE_SEND_COMPLETE 5
#define MULTIBOOT_CHILD_STATE_BOOT_STARTABLE 6

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

#include "03/Menu/wifi_menu_shared.h"
#include "code_02142eac.h"
#include "code_020091fc.h"

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
BOOL RegisterMultiBootFile(MBGameRegistry *gameRegistry);
void StartMultiBootParentFromIdle(MBGameRegistry *gameRegistry, u16 channel);
void InitMultiBootParentComm(u32 ggid, u32 tgid);
void InitMultiBootParent(u8 *object);

extern u16 *gMultiBootMaskPointers[6];
