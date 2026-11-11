#pragma once

#include "types.h"
#include "code_0200ad00.h"
#include "code_0200fc8c.h"
#include "code_0200aeb4.h"
#include "code_02008934.h"
#include "mb_data.h"

struct SegmentBuffer;

// Object behind mbc. The members from 0x1788 on are reached from a pointer advanced in steps of 0x5d4
// bytes, so their offsets here include the 0x1788.
typedef struct MB_CommPWork {
    /* 0000 */ u8 mUnk_0000[0x1300];
    /* 1300 */ MBUserInfo mUser;
    /* 1316 */ u16 mIsMbInitialized;
    /* 1318 */ s32 mBlockSizeMax;
    /* 131c */ u32 mStartMpBusy;
    /* 1320 */ u32 mIsStartedEx;
    /* 1324 */ u8 mUnk_1324[0x1340 - 0x1324];
    /* 1340 */ MBUserInfo mChildUser[15];
    /* 148a */ u16 mChildversion[15];
    /* 14a8 */ u32 mChildggid[15];
    /* 14e4 */ void (*mCallback)(u32, u32, void *);
    /* 14e8 */ u32 mPCommState[15];
    /* 1524 */ u8 mEntryCount;
    /* 1525 */ u8 mCurFileid;
    /* 1526 */ s8 mChildEntryIndex[15];
    /* 1535 */ u8 mChildNum;
    /* 1536 */ u16 mChildEntryBmp;
    /* 1538 */ MbRequestPieceBuf mReqDataBuf;
    /* 1754 */ u16 mReq2child[15];
    /* 1772 */ u8 mChildUserBuf[0x16];
    /* 1788 */ u8 mUnk_1788[0x1d1f - 0x1788];
    /* 1d1f */ u8 mUnk_1d1f;
    /* 1d20 */ u8 mUnk_1d20;
    /* 1d21 */ u8 mUnk_1d21;
    /* 1d22 */ u8 mUnk_1d22[0x1d2c - 0x1d22];
    /* 1d2c */ u8 mUnk_1d2c[0x14];
    /* 1d40 */ struct MBGameRegistry *mGameReg;
    /* 1d44 */ struct SegmentBuffer *mSrcAdr;
    /* 1d48 */ u16 mCurrentb;
    /* 1d4a */ u16 mNextb;
    /* 1d4c */ u16 mPollbmp;
    /* 1d4e */ u16 mGameinfoChildBmp;
    /* 1d50 */ u16 mGameinfoChangedBmp;
    /* 1d52 */ u8 mEntryUsed;
    /* 1d53 */ u8 mUnk_1d53;
    /* 1d54 */ MBiCacheList *mCacheList;
    /* 1d58 */ u32 *mCardMapping;
    /* 1d5c */ u8 mUnk_1d5c[0x74c8 - 0x1d5c];
    /* 74c8 */ s32 mUseWvrFlag;
    /* 74cc */ u8 mUnk_74cc[0x74e0 - 0x74cc];
    /* 74e0 */ WorkerQueue mUnk_74e0;
    /* ---- */ u8 mUnk_74e0_end[0x800 - sizeof(WorkerQueue)];
    /* 7ce0 */ u8 mCurTask[0x20];
} MB_CommPWork;

u32 MBi_calc_nextsendblock(u32 first, u32 second);
void MBi_calc_sendblock(u32 entryIndex);
