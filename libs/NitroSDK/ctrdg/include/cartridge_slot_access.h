#pragma once

#include "types.h"

// Two words filled by CTRDGi_LockByProcessor and ReadSomeExmemcntData_from_thumb and read back by
// CTRDGi_UnlockByProcessor and CTRDGi_RestoreAccessCycle.
typedef struct CartridgeAccessSave {
    union {
        /* 00 */ vs32 mCycle1;
        /* 00 */ vs32 mOwnerFlag;
    };
    union {
        /* 04 */ vs32 mCycle2;
        /* 04 */ vs32 mSavedIrq;
    };
} CartridgeAccessSave;

// Two halfwords at the start of the first object this file defines.
typedef struct CTRDGWork {
    // Set to 1 by Fifo13Handler_0_from_thumb; CTRDGi_InitModuleInfo waits until it is 1.
    /* 00 */ u16 mReplyReceived;
    // The Os_AllocateLockId result stored by CTRDGi_InitCommon_from_thumb; the first argument of every lock and unlock call of this
    // file.
    /* 02 */ u16 mLockId;
} CTRDGWork;

// The tail of the cartridge header, which CTRDGi_InitModuleInfo copies and reads: game, maker and module ids.
typedef struct CartridgeHeaderTail {
    /* 00 */ u8 mUnk_00[0x2c];
    /* 2c */ u32 mGameCode;
    /* 30 */ u16 mMakerCode;
    /* 32 */ u8 mUnk_32[3];
    /* 35 */ u8 mExLsiId[3];
    /* 38 */ u8 mUnk_38[6];
    /* 3e */ u16 mModuleId;
} CartridgeHeaderTail;

typedef struct CartridgeHeaderCopy {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 mBiosBytes[0x7c];
    // The 0x40 bytes copied from 0x08000080; CTRDGi_InitModuleInfo reads the fields at +0x2c, +0x30, +0x35 and
    // +0x3e of it into the record.
    /* 80 */ CartridgeHeaderTail mHeaderTailCopy;
} CartridgeHeaderCopy;

// Fixed-address object written by CTRDGi_InitModuleInfo and read by MaybeDebuggerOrAddonCode_from_thumb.
typedef struct CTRDGModuleInfo {
    // Written by CTRDGi_InitModuleInfo from +0xbe of the copy; MaybeDebuggerOrAddonCode_from_thumb returns 0 when it is 0xffff and
    // compares it with the window.
    /* 00 */ u16 mIdHalfword;
    /* 02 */ u8 mExLsiId[3];
    /* 05 */ u8 mIsAgbCartridge : 1;
    u8 mDetectPullOut : 1;
    u8 mUnk_05_2 : 6;
    /* 06 */ u16 mMakerCode;
    // Written by CTRDGi_InitModuleInfo from +0xac of the copy; MaybeDebuggerOrAddonCode_from_thumb compares it with the word at
    // 0x080000ac.
    /* 08 */ u32 mIdWord;
} CTRDGModuleInfo;

// The id halfword of the record while no cartridge id has been read, and the selector byte value that makes the
// header halfword the one to compare.
#define CARTRIDGE_NO_ID_HALFWORD 0xffff
#define CARTRIDGE_ID_SELECTOR_HEADER_HALFWORD 0x96

// Fixed-address object read by MaybeDebuggerOrAddonCode_from_thumb.
typedef struct CTRDGHeader {
    /* 00 */ u8 mUnk_00[0xac];
    // The word at 0x080000ac; MaybeDebuggerOrAddonCode_from_thumb compares it with the word of the record at +8.
    /* ac */ u32 mIdWord;
    /* b0 */ u8 mUnk_b0[2];
    // The byte at 0x080000b2; MaybeDebuggerOrAddonCode_from_thumb compares it with 0x96 to choose which halfword it compares with the
    // record.
    /* b2 */ u8 mIdSelector;
    /* b3 */ u8 mUnk_b3[0xb];
    // The halfword at 0x080000be; MaybeDebuggerOrAddonCode_from_thumb compares it with the record's halfword at +0 when mIdSelector is
    // 0x96.
    /* be */ u16 mIdHalfword;
} CTRDGHeader;

// In the comments below, "the window" is the memory at 0x08000000, "the record" the object at 0x027ffc30 and "the
// copy" gCartridgeHeaderCopy.
// Two halfwords, mReplyReceived and mLockId; CTRDGi_InitCommon_from_thumb clears and fills them.
extern CTRDGWork gCartridgeState;
// Tested and set to 1 at the top of CTRDGi_InitModuleInfo, which returns at once when it is not 0.
extern s32 gHeaderCopyStarted;
// Tested and set to 1 at the top of CTRDG_Initialize_from_thumb, which does nothing when it is not 0.
extern s32 gCartridgeInitStarted;
// Function pointer that Fifo13Handler_1_from_thumb calls; CTRDG_Initialize_from_thumb sets it to 0 and nothing else writes it.
extern s32 (*gCartridgeRemovalCallback)(void);
// 0xc0 bytes: CTRDGi_InitModuleInfo fills +4 with 0x9c bytes from 0xffff0020 and +0x80 with 0x40 bytes from
// 0x08000080, reads four fields from the second part, and sends the block's address on tag 13.
extern CartridgeHeaderCopy gCartridgeHeaderCopy;

// Calls j_Operation_CartArm7(lockID) when the first word of info is 0, then Os_RestoreIrq with the second word of
// info.
void CTRDGi_UnlockByProcessor(u16 lockID, CartridgeAccessSave *info);
// Loops: stores Os_DisableIrq() in the second word of info and the owner id of the lock word at 0x027fffe8
// (Os_Lock_GetOwnerId) & 0x40 in the first word, and returns when that is not 0; otherwise calls
// Operation_CartArm9(lockID) and returns when it gives 0; else calls Os_RestoreIrq, Svc_Delay_from_thumb(1) and tries
// again. Returns with the interrupts disabled.
void CTRDGi_LockByProcessor(u16 lockID, CartridgeAccessSave *info);
// Writes the first word of r (shifted left by 2) into bits 2 and 3 and the second word (shifted left by 4) into bit 4
// of the halfword at 0x04000204.
void CTRDGi_RestoreAccessCycle(CartridgeAccessSave *cycleInfo);
// Stores bits 2 and 3 of the halfword at 0x04000204 (as 0 to 3) in the first word of the record r and bit 4 in the
// second word, then sets bits 2 and 3 and clears bit 4.
void ReadSomeExmemcntData_from_thumb(CartridgeAccessSave *cycleInfo);
// Returns 0 when the halfword at 0x027ffc30 is 0xffff or bit 1 of the byte at 0x027ffc35 is set. Otherwise locks and
// compares the record with the window: the halfword at 0x080000be (0x0801fffe when the byte at 0x080000b2 is not 0x96)
// against the halfword at 0x027ffc30, and when bit 0 of the byte at 0x027ffc35 is set the word at 0x080000ac against
// the word at 0x027ffc38. On a difference sets bit 1 of that byte and returns 0, otherwise 1. Its only caller is
// PM_GoSleepMode.
s32 MaybeDebuggerOrAddonCode_from_thumb(void);
// Zero-fills the 4 bytes of gCartridgeState (Svc_Copy_from_thumb, one word) and stores Os_AllocateLockId() in gCartridgeState.mLockId.
void CTRDGi_InitCommon_from_thumb(void);
// Sends the word 2 with CTRDGi_SendtoPxi, then calls Os_Terminate. Its only caller is
// Fifo13Handler_1_from_thumb.
void CTRDG_TerminateForPulledOut(void);
// Tag 13 callback after CTRDG_Initialize_from_thumb: when the low 6 bits of the second argument are 0x11 calls gCartridgeRemovalCallback
// if it is not 0 (nothing in the game sets it, so the result is 0) and calls CTRDG_TerminateForPulledOut when the
// result is not 0; for any other value calls Os_Terminate. "Removal" rests on the name of its callee.
void Fifo13Handler_1_from_thumb(u32 tag, u32 data);
// Tag 13 callback while CTRDGi_InitModuleInfo waits: when the low 6 bits of the second argument are 1 sets
// gCartridgeState.mReplyReceived to 1, otherwise calls Os_Terminate.
void Fifo13Handler_0_from_thumb(u32 tag, u32 data);
// Runs once (gHeaderCopyStarted); returns when bit 0 of the halfword at 0x04000300 is 0. Under the cartridge lock
// copies the 0x40 bytes at 0x08000080 to the copy plus 0x80 (MI_DmaCopy16, channel 1), then fills the record from the
// copy, copies 0x9c bytes from 0xffff0020 to the copy plus 4, flushes the cache, sends ((copy - the start of NtrMain RAM)
// >> 5) << 6 | 1 on tag 13 and waits for mReplyReceived. Its only caller is CTRDG_Initialize_from_thumb.
void CTRDGi_InitModuleInfo(void);
// Runs once (gCartridgeInitStarted). Calls CTRDGi_InitCommon_from_thumb and j_Fifo_Initialize, loops until Fifo_IsHandlerReady(13, 1) is
// not 0, installs Fifo13Handler_0_from_thumb as the tag 13 callback, calls CTRDGi_InitModuleInfo, removes the
// callback (Fifo_RegisterHandler(13, 0)), installs Fifo13Handler_1_from_thumb as the tag 13 callback and sets
// gCartridgeRemovalCallback to 0. Os_Initialize calls it as its 13th call, before Card_Initialize.
void CTRDG_Initialize_from_thumb(void);
