#pragma once

#include "types.h"
#include "multiboot_file_register.h"
#include "multiboot_checksum.h"
#include "cpu_copy_clear_16.h"
#include "wireless_beacon_wep_settings.h"
#include "file_open_read.h"
#include "file_handle_setup.h"
#include "multiboot_game_info_beacon.h"

// Entry of the list that mbss walks (the lists are chained through mNext). MB_GetGameInfoRecvList returns one;
// the 0xc0 bytes at 0x4c0 are moved out by MB_FakeGetParentBssDesc.
typedef struct GameInfoEntry {
    /* 000 */ u8 mIcon[0x220];
    /* 220 */ u8 mParent[0x16];
    /* 236 */ u8 mMaxPlayerNum;
    /* 237 */ u8 mUnk_237;
    /* 238 */ u8 mGameName[0x60];
    /* 298 */ u8 mGameIntroduction[0xc0];
    /* 358 */ u8 mNowPlayerNum;
    /* 359 */ u8 mUnk_359;
    /* 35a */ u16 mNowPlayerFlag;
    /* 35c */ u16 mChangePlayerFlag;
    /* 35e */ u8 mMember[0x14a];
    /* 4a8 */ u8 mUserVolatData[8];
    /* 4b0 */ u16 mBroadcastedPlayerFlag;
    /* 4b2 */ u8 mDataAttr;
    /* 4b3 */ u8 mSeqNoFixed;
    /* 4b4 */ u8 mSeqNoVolat;
    /* 4b5 */ u8 mFileNo;
    /* 4b6 */ u8 mPad[2];
    /* 4b8 */ u32 mGgid;
    /* 4bc */ struct GameInfoEntry *mNext;
    /* 4c0 */ WMBssDesc mBssDesc;
} GameInfoEntry;

// State of the walk over the GameInfoEntry list: the first entry, the current entry, the position in the current
// entry, and five bytes that MBi_ClearSendStatus clears.
// Values of GameInfoList.mState: pick the next entry, then send its fixed beacon fragments and its volatile beacon.
// Values 0 and 6 are only read by MB_SendGameInfoBeacon.
enum {
    GAME_INFO_SEND_STATE_IDLE,
    GAME_INFO_SEND_STATE_PICK_ENTRY,
    GAME_INFO_SEND_STATE_INIT_FIXED,
    GAME_INFO_SEND_STATE_SEND_FIXED,
    GAME_INFO_SEND_STATE_INIT_VOLATILE,
    GAME_INFO_SEND_STATE_SEND_VOLATILE,
    GAME_INFO_SEND_STATE_NO_ACTION,
};

typedef struct GameInfoList {
    /* 00 */ GameInfoEntry *mFirst;
    /* 04 */ GameInfoEntry *mCurrent;
    /* 08 */ u8 *mSrcp;
    /* 0c */ u8 mState;
    /* 0d */ u8 mSeqNoFixed;
    /* 0e */ u8 mSeqNoVolat;
    /* 0f */ u8 mFlagmentNo;
    /* 10 */ u8 mFlagmentMaxNum;
    /* 11 */ u8 mNextSequence;
    /* 12 */ u8 mUnk_12[2];
} GameInfoList;

// 0x70-byte block that MBi_SendVolatBeacon and MBi_SendFixedBeacon fill and pass to WM_SetGameInfo. The halfword at 0xc
// and the bytes from 0xe have another layout in MBi_SendFixedBeacon.
typedef struct GameInfoBlock {
    /* 00 */ u32 mGgid;
    /* 04 */ union {
        u8 mUnk_04;
        struct {
            u8 mDataAttr : 2;
            u8 mFileNo : 6;
        };
    };
    /* 05 */ u8 mSeqNoFixed;
    /* 06 */ u8 mSeqNoVolat;
    /* 07 */ u8 mSequence;
    /* 08 */ u16 mChecksum;
    /* 0a */ u8 mByte0a;
    /* 0b */ u8 mFlagmentMaxNum;
    /* 0c */ union {
        u16 mNowPlayerFlag;
        u8 mSize;
    };
    /* 0e */ u16 mHalf0e;
    /* 10 */ u8 mMember[0x58];
    /* 68 */ u8 mUserVolatData[8];
} GameInfoBlock;

// Fields MBi_MakeGameInfo reads.
typedef struct MBGameRegistry {
    /* 00 */ const u8 *mRomFilePathp;
    /* 04 */ const u16 *mGameNamep;
    /* 08 */ const u8 *mGameIntroductionp;
    /* 0c */ const u8 *mIconCharPathp;
    /* 10 */ const u8 *mIconPalettePathp;
    /* 14 */ u32 mGgid;
    /* 18 */ u8 mMaxPlayerNum;
    /* 19 */ u8 mPad[3];
    /* 1c */ u8 mUserParam[0x20];
} MBGameRegistry;

extern u32 sSendVolatCallbackTimming;
extern void (*sSendVolatCallback)(u32 gameGroupId);
extern GameInfoList mbss;
extern GameInfoBlock gGameInfoBlock;
extern WMBssDesc bssDescbuf;

u32 MBi_CheckMBParent(WMBssDesc *scanBlock);
u32 MB_RecvGameInfoBeacon(EntryCallbackFunc callback, u32 value, WMBssDesc *scanBlock);
void MBi_SendVolatBeacon(u32 ggid, u16 tgid, u32 attr);
void MBi_InitSendVolatBeacon(void);
void MBi_SendFixedBeacon(u32 ggid, u16 tgid, u32 attr);
void MBi_InitSendFixedBeacon(void);
u32 MBi_ReadyBeaconSendStatus(void);
void MB_SendGameInfoBeacon(u32 ggid, u16 tgid, u32 attr);
void MBi_ClearSendStatus(void);
void MB_InitSendGameInfoStatus(void);
void MB_AddGameInfo(GameInfoEntry *newEntry);
u32 mystrlen(const u16 *string);
void MB_UpdateGameInfoMember(GameInfoEntry *entry, const void *records, u32 recordMask, u32 value);
u32 MBi_ReadIconInfo(const u8 *path, u8 *buffer, u32 isLarge);
void MBi_MakeGameInfo(GameInfoEntry *entry, MBGameRegistry *params, const u8 *record);

