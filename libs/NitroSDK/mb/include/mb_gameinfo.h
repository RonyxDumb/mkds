#pragma once

#include "types.h"
#include "wireless_power_mp.h"

// Values of mDataAttr in the game info entries and in the beacon block: the whole entry with its icon, the entry
// without the icon (sent when the icon files could not be read), and the part that changes while the game runs.
enum {
    MULTIBOOT_DATA_ATTR_FIXED_WITH_ICON = 0,
    MULTIBOOT_DATA_ATTR_FIXED_NO_ICON = 1,
    MULTIBOOT_DATA_ATTR_VOLATILE = 2,
};

// Bytes of game info in one beacon block, and how many blocks a fixed entry takes with and without the icon.
#define MULTIBOOT_GAME_INFO_BLOCK_SIZE 0x62
#define MULTIBOOT_FIXED_BLOCK_COUNT_WITH_ICON 9
#define MULTIBOOT_FIXED_BLOCK_COUNT_NO_ICON 4

// Count-down counts: a received entry lives this long without a new beacon; while one entry is followed the scan
// counts in bigger steps for the lock time, and the follow ends after that many lost beacons in a row.
#define MULTIBOOT_GAME_INFO_LIFETIME 0x1771
#define MULTIBOOT_LOCKED_SCAN_COUNT_UNIT 0x16
#define MULTIBOOT_LOCK_TIME_COUNT 0x321
#define MULTIBOOT_LOCK_NOT_FOUND_LIMIT 4

// An entry is dropped when its sequence number repeats more than this many times in a row.
#define MULTIBOOT_SEQUENCE_REPEAT_LIMIT 3

typedef struct MBGameInfoRecvList {
    /* 000 */ u8 mIcon[0x220];
    /* 220 */ u8 mFixedNoIcon[0x138];
    /* 358 */ u8 mNowPlayerNum;
    /* 359 */ u8 mUnk_359;
    /* 35a */ u16 mNowPlayerFlag;
    /* 35c */ u16 mChangePlayerFlag;
    /* 35e */ u8 mMember[0x14a];
    /* 4a8 */ u8 mUserVolatData[8];
    /* 4b0 */ u8 mBroadcastedPlayerFlag[2];
    /* 4b2 */ u8 mDataAttr;
    /* 4b3 */ u8 mSeqNoFixed;
    /* 4b4 */ u8 mSeqNoVolat;
    /* 4b5 */ u8 mFileNo;
    /* 4b6 */ u8 mPad[2];
    /* 4b8 */ u32 mGgid;
    /* 4bc */ u8 mNext[4];
    /* 4c0 */ WMBssDesc mScanBuffer;
    /* 580 */ u32 mGetFlagmentFlag;
    /* 584 */ u32 mAllFlagmentFlag;
    /* 588 */ u16 mGetPlayerFlag;
    /* 58a */ s16 mTimer;
    /* 58c */ u16 mLinkLevel;
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
    /* 0e */ u16 mPad;
    /* 10 */ MBGameInfoRecvList mEntries[16];
} MbBeaconRecvStatus;

// Characters in the name of a user.
#define MB_USER_NAME_LENGTH 10

// Element of the array at 0x10 in MbBeacon.
typedef struct MBUserInfo {
    /* 00 */ union {
        u8 mColorAndPlayerNo;
        struct {
            u8 mFavoriteColor : 4;
            u8 mPlayerNo : 4;
        };
    };
    /* 01 */ u8 mNameLength;
    /* 02 */ u16 mName[MB_USER_NAME_LENGTH];
} MBUserInfo;

// Object behind gReceivedGameInfo.
typedef struct MbBeacon {
    /* 00 */ u32 mGgid;
    /* 04 */ u8 mDataAttr : 2;
    /* 04 */ u8 mFileNo : 6;
    /* 05 */ u8 mSeqNoFixed;
    /* 06 */ u8 mSeqNoVolat;
    /* 07 */ u8 mSequence;
    /* 08 */ u16 mChecksum;
    /* 0a */ u8 mByte0a;
    /* 0b */ u8 mFlagmentMaxNum;
    union {
        /* 0c */ u16 mHalf0c;
        /* 0c */ u8 mByteCount;
    };
    /* 0e */ u16 mHalf0e;
    /* 10 */ MBUserInfo mMember[4];
    /* 68 */ u8 mUserVolatData[8];
} MbBeacon;

typedef void (*EntryCallbackFunc)(u32 event, void *entry, u32 entryIndex);

extern MbBeaconRecvStatus *mbrsp;
extern MbBeacon *gReceivedGameInfo;
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

void MBi_CheckTGID(WMBssDesc *newBlock, int entryIndex);

void MBi_AnalyzeBeacon(WMBssDesc *scanBlock, u32 entryIndex, u32 value);
void MB_CountGameInfoLifetime(EntryCallbackFunc callback, u32 value);
void MBi_CheckCompleteGameInfoFlagments(u32 entryIndex, EntryCallbackFunc callback);
s32 MBi_GetStoreElement(const WMBssDesc *scanBlock, EntryCallbackFunc callback);

void MBi_SetSSIDToBssDesc(WMBssDesc *scanBlock, u32 value);

void MB_InitRecvGameInfoStatus(void);
