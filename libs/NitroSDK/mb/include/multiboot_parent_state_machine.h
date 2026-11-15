#pragma once

#include "types.h"
#include "multiboot_mode_constants.h"
#include "reset_interrupts_halt.h"
#include "multiboot_task_thread.h"
#include "multiboot_game_info_beacon.h"
#include "mb_data.h"
#include "file_command_handlers.h"
#include "file_handle_setup.h"
#include "file_archive_access.h"
#include "multiboot_block_header_end.h"
#include "multiboot_data_pieces.h"
#include "multiboot_communication.h"
#include "wireless_link_control.h"

struct SegmentBuffer;

// Called with the child index, the event code and a message or user info that depends on the code.
typedef void (*MBParentStateCallback)(u32 child, u32 code, void *data);

// Values of the event code MBi_CommParentCallback receives, named by what the handler does with them.
enum {
    MULTIBOOT_PARENT_EVENT_CHILD_CONNECTED = 0,
    MULTIBOOT_PARENT_EVENT_CHILD_DISCONNECTED = 1,
    MULTIBOOT_PARENT_EVENT_MP_DATA_RECEIVED = 3,
    MULTIBOOT_PARENT_EVENT_ENDED = 0x11,
    MULTIBOOT_PARENT_EVENT_PARENT_STARTED = 0x15,
    MULTIBOOT_PARENT_EVENT_MP_SEND_READY = 0x19,
    MULTIBOOT_PARENT_EVENT_BEACON_DUE = 0x1c,
    MULTIBOOT_PARENT_EVENT_ERROR = 0xff,
    MULTIBOOT_PARENT_EVENT_REQUEST_FAILED = 0x100,
};

// What the parent asks of one child (MB_CommPWork.mReq2child), set once the child is in the state that allows it.
enum {
    MULTIBOOT_CHILD_REQUEST_NONE = 0,
    MULTIBOOT_CHILD_REQUEST_DOWNLOAD = 2,
    MULTIBOOT_CHILD_REQUEST_ACCEPT = 3,
    MULTIBOOT_CHILD_REQUEST_REFUSE = 4,
    MULTIBOOT_CHILD_REQUEST_BOOT = 5,
};

typedef enum MBCommPState {
    MULTIBOOT_PARENT_NONE,
    MULTIBOOT_PARENT_STARTED,
    MULTIBOOT_PARENT_CHILD_CONNECTED,
    MULTIBOOT_PARENT_CHILD_DISCONNECTED,
    MULTIBOOT_PARENT_CHILD_REFUSED,
    MULTIBOOT_PARENT_CHILD_ENTERED,
    MULTIBOOT_PARENT_DOWNLOAD_STARTED,
    MULTIBOOT_PARENT_DOWNLOAD_DONE,
    MULTIBOOT_PARENT_BOOT_ACKED,
    MULTIBOOT_PARENT_CHILD_BOOTED,
    MULTIBOOT_PARENT_CHILD_REQUESTED,
    MULTIBOOT_PARENT_ENTRY_FULL,
    MULTIBOOT_PARENT_ENDED,
    MULTIBOOT_PARENT_ERROR,
    MULTIBOOT_PARENT_CHILD_WAITING
} MBCommPState;

// Second argument of MB_CommResponseRequest: refuse the child, accept it, start sending the program, boot it.
typedef enum MBCommResponse {
    MULTIBOOT_RESPONSE_REFUSE,
    MULTIBOOT_RESPONSE_ACCEPT,
    MULTIBOOT_RESPONSE_SEND,
    MULTIBOOT_RESPONSE_BOOT
} MBCommResponse;

// Object behind mbc. The members from 0x1788 on are reached from a pointer advanced in steps of 0x5d4
// bytes, so their offsets here include the 0x1788.
typedef struct DataRangeLoadJob {
    /* 00 */ WorkerTask mTask;
    /* 10 */ MBiCacheInfo *mDataRange;
    /* 14 */ MBiCacheList *mDataRangeTable;
} DataRangeLoadJob;

typedef struct MB_CommPWork {
    /* 0000 */ u8 mSendBuffer[0x400];
    /* 0400 */ u8 mRecvBuffer[0x1300 - 0x400];
    /* 1300 */ MBUserInfo mUser;
    /* 1316 */ u16 mIsMbInitialized;
    /* 1318 */ s32 mBlockSizeMax;
    /* 131c */ u32 mStartMpBusy;
    /* 1320 */ u32 mIsStartedEx;
    /* 1324 */ u8 mPadding[0x1340 - 0x1324];
    /* 1340 */ MBUserInfo mChildUser[15];
    /* 148a */ u16 mChildversion[15];
    /* 14a8 */ u32 mChildggid[15];
    /* 14e4 */ MBParentStateCallback mCallback;
    /* 14e8 */ u32 mPCommState[15];
    /* 1524 */ u8 mEntryCount;
    /* 1525 */ u8 mCurFileid;
    /* 1526 */ s8 mChildEntryIndex[15];
    /* 1535 */ u8 mChildNum;
    /* 1536 */ u16 mChildEntryBmp;
    /* 1538 */ MbRequestPieceBuf mReqDataBuf;
    /* 1754 */ u16 mReq2child[15];
    /* 1772 */ u8 mChildUserBuf[0x16];
    /* 1788 */ u8 mFileInfo[0x1d1f - 0x1788];
    /* 1d1f */ u8 mSeqNoFixed;
    /* 1d20 */ u8 mSeqNoVolat;
    /* 1d21 */ u8 mFileNo;
    /* 1d22 */ u8 mUnk_1d22[0x1d2c - 0x1d22];
    /* 1d2c */ u8 mBlockInfoTable[0x14];
    /* 1d40 */ struct MBGameRegistry *mGameReg;
    /* 1d44 */ struct SegmentBuffer *mSrcAdr;
    /* 1d48 */ u16 mCurrentb;
    /* 1d4a */ u16 mNextb;
    /* 1d4c */ u16 mPollbmp;
    /* 1d4e */ u16 mGameinfoChildBmp;
    /* 1d50 */ u16 mGameinfoChangedBmp;
    /* 1d52 */ u8 mEntryUsed;
    /* 1d53 */ u8 mUpdate;
    /* 1d54 */ MBiCacheList *mCacheList;
    /* 1d58 */ u32 *mCardMapping;
    /* 1d5c */ u8 mUnk_1d5c[0x74c8 - 0x1d5c];
    /* 74c8 */ s32 mUseWvrFlag;
    /* 74cc */ u8 mPadding2[0x74e0 - 0x74cc];
    /* 74e0 */ WorkerQueue mTaskWork;
    /* ---- */ u8 mUnk_74e0_end[0x800 - sizeof(WorkerQueue)];
    /* 7ce0 */ DataRangeLoadJob mCurTask;
    /* 7cf8 */ u8 mUnk_7cf8[8];
} MB_CommPWork;

u32 MBi_calc_nextsendblock(u32 first, u32 second);
void MBi_calc_sendblock(u32 entryIndex);

int MBi_CommParentSendData(void);
u32 MBi_CommParentSendBlock(void);


void MBi_ReloadCache(DataRangeLoadJob *job);
u32 MBi_CommParentSendDLFileInfo(void);

int MBi_CommParentSendMsg(u8 messageKind, u32 childMask);

void MBi_CommParentRecvData(WMMpRecvHeader *header);
void MBi_CommParentRecvDataPerChild(WMMpRecvData *childData, u32 child);
void MBi_CommParentCallback(s32 eventCode, WirelessMessage *eventData);
void MBi_CommChangeParentStateCallbackOnly(u32 child, u32 value, void *data);
void MBi_CommChangeParentState(u32 child, u32 value, void *data);
u32 MB_CommResponseRequest(u32 child, u32 pairIndex);
u32 MB_CommIsBootable(u32 child);
void *MB_CommGetChildUser(u32 child);
void MBi_CommCallParentError(u32 aid, u16 errcode);
u32 IsChildAidValid(u32 aid);

void MB_CommSetParentStateCallback(MBParentStateCallback parentStateCallback);

extern u8 prev_fid;
