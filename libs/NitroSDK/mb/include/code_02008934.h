#pragma once

#include "types.h"

// One 0x590-byte entry of the table in MbBeaconRecvStatus.
typedef struct MBGameInfoRecvList {
    /* 000 */ u8 mUnk_000[0x220];
    /* 220 */ u8 mUnk_220[0x138];
    /* 358 */ u8 mUnk_358;
    /* 359 */ u8 mUnk_359;
    /* 35a */ u16 mUnk_35a;
    /* 35c */ u16 mUnk_35c;
    /* 35e */ u8 mUnk_35e[0x14a];
    /* 4a8 */ u8 mUnk_4a8[8];
    /* 4b0 */ u8 mUnk_4b0[2];
    /* 4b2 */ u8 mUnk_4b2;
    /* 4b3 */ u8 mUnk_4b3;
    /* 4b4 */ u8 mUnk_4b4;
    /* 4b5 */ u8 mUnk_4b5;
    /* 4b6 */ u8 mUnk_4b6[2];
    /* 4b8 */ u32 mUnk_4b8;
    /* 4bc */ u8 mUnk_4bc[4];
    /* 4c0 */ u8 mScanBuffer[4];
    /* 4c4 */ u8 mBssid[6];
    /* 4ca */ u8 mUnk_4ca[0x3e];
    /* 508 */ u16 mUnk_508;
    /* 50a */ u8 mUnk_50a[0x76];
    /* 580 */ u32 mUnk_580;
    /* 584 */ u32 mUnk_584;
    /* 588 */ u16 mUnk_588;
    /* 58a */ s16 mTimer;
    /* 58c */ u16 mUnk_58c;
    /* 58e */ u8 mLastSequence;
    /* 58f */ u8 mSequenceRepeats;
} MBGameInfoRecvList;

// Object behind mbrsp: sixteen entries from 0x10 on.
typedef struct MbBeaconRecvStatus {
    /* 00 */ u16 mUsedMask;
    /* 02 */ u16 mUsefulGameInfoFlag;
    /* 04 */ u16 mValidGameInfoFlag;
    /* 06 */ u16 mNowScanTargetFlag;
    /* 08 */ s16 mNowLockTimeCount;
    /* 0a */ s16 mNotFoundLockTargetCount;
    /* 0c */ u16 mScanCountUnit;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ MBGameInfoRecvList mEntries[16];
} MbBeaconRecvStatus;

// Element of the array at 0x10 in Unk0216fc1c.
typedef struct Unk0216fc1c_10 {
    /* 00 */ u8 mUnk_00 : 4;
    /* 00 */ u8 mUnk_00_4 : 4;
    /* 01 */ u8 mUnk_01[0x15];
} Unk0216fc1c_10;

// Object behind gReceivedGameInfo.
typedef struct Unk0216fc1c {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 mUnk_04 : 2;
    /* 04 */ u8 mUnk_04_2 : 6;
    /* 05 */ u8 mUnk_05;
    /* 06 */ u8 mUnk_06;
    /* 07 */ u8 mSequence;
    /* 08 */ u8 mChecksum[2];
    /* 0a */ u8 mUnk_0a;
    /* 0b */ u8 mUnk_0b;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ Unk0216fc1c_10 mUnk_10[4];
    /* 68 */ u8 mUnk_68[8];
} Unk0216fc1c;

typedef void (*EntryCallbackFunc)(u32 a, void *b, u32 c);

extern MbBeaconRecvStatus *mbrsp;
extern Unk0216fc1c *gReceivedGameInfo;
extern void (*gClearBssidCallback)(void);
extern void (*gSetBssidCallback)(const u8 *);

MBGameInfoRecvList *MB_GetGameInfoRecvList();
void MB_DeleteRecvGameInfoWithoutBssdesc(u32 entryIndex);
void MB_DeleteRecvGameInfo(u32 entryIndex);
void MBi_UnlockScanTarget(void);
void MBi_LockScanTarget(u32 entryIndex);
void MBi_RecvVolatBeacon(u32 entryIndex);
void MBi_RecvFixedBeacon(u32 entryIndex);
void MBi_InvalidateGameInfoBssID(const u8 *bssid);
void MBi_CheckSeqNoVolat(u32 entryIndex);
void MBi_CheckSeqNoFixed(u32 entryIndex);
