#pragma once

#include "types.h"
#include "code_0200c4a4.h"
#include "os_spinLock.h"
#include "code_0200eddc.h"
#include "code_021458c4.h"
#include "code_0214d93c.h"

typedef u32 OSIntrMode;

#define BOOT_TYPE_MULTIBOOT 2

// The boot information block in shared memory: the first halfword, then 0x3e bytes the game copies.
typedef struct BootInfo {
    /* 00 */ u16 mBootType;
    /* 02 */ u8 mParentBssDesc[0x3e];
} BootInfo;

// The user settings the system leaves in shared memory at 0x027ffc80: the owner data and the touch panel calibration
// words.
typedef struct NvramUserInfo {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u8 mFavoriteColor;
    /* 03 */ u8 mBirthdayMonth;
    /* 04 */ u8 mBirthdayDay;
    /* 05 */ u8 mUnk_05;
    /* 06 */ u8 mNickName[0x14];
    /* 1a */ u8 mNickNameLength;
    /* 1b */ u8 mUnk_1b;
    /* 1c */ u8 mComment[0x34];
    /* 50 */ u8 mCommentLength;
    /* 51 */ u8 mUnk_51[7];
    /* 58 */ u16 mRawX1;
    /* 5a */ u16 mRawY1;
    /* 5c */ u8 mDx1;
    /* 5d */ u8 mDy1;
    /* 5e */ u16 mRawX2;
    /* 60 */ u16 mRawY2;
    /* 62 */ u8 mDx2;
    /* 63 */ u8 mDy2;
    /* 64 */ u16 mOption;
    /* 66 */ u8 mUnk_66[0xe];
    // The 6 bytes OS_GetMacAddress copies.
    /* 74 */ u8 mMacAddress[6];
    // The halfword WM_GetAllowedChannel returns.
    /* 7a */ u16 mAllowedChannel;
    /* 7c */ u8 mUnk_7c[0x84];
} NvramUserInfo;

// OSSystemWork.mButtonXY bit that is set while the console is closed; the sleep wait and the pad readers test it.
#define SYSTEM_BUTTON_XY_CLOSED 0x8000

// The shared memory block at 0x027ffc00 that both processors read and write.
typedef struct OSSystemWork {
    /* 000 */ u8 mUnk_000[0x30];
    /* 030 */ CTRDGModuleInfo mCartridgeModuleInfo;
    /* 03c */ vu32 mVblankCount;
    /* 040 */ BootInfo mWmBootBuf;
    /* 080 */ NvramUserInfo mNvramUserInfo;
    /* 180 */ u8 mUnk_180[0x20];
    /* 1a0 */ OSArenaInfo mArenaInfo;
    /* 1e8 */ RTCRawData mRealTimeClock;
    /* 1f0 */ u8 mUnk_1f0[0x10];
    /* 200 */ CARDRomHeader mRomHeader;
    /* 360 */ u8 mUnk_360[0x28];
    /* 388 */ u32 mPxiHandleChecker[2];
    /* 390 */ u32 mMicLastAddress;
    /* 394 */ u16 mMicSamplingData;
    /* 396 */ u16 mWmCallbackControl;
    /* 398 */ u8 mUnk_398[0x10];
    // Bit 15 (SYSTEM_BUTTON_XY_CLOSED) is set while the console is closed.
    /* 3a8 */ vu16 mButtonXY;
    /* 3aa */ u16 mTouchPanel[2];
    /* 3ae */ u8 mUnk_3ae[2];
    /* 3b0 */ u32 mLockIdFlagMain[2];
    /* 3b8 */ u8 mUnk_3b8[8];
    /* 3c0 */ OSLockWord mLockVramC;
    /* 3c8 */ u8 mUnk_3c8[0x18];
    /* 3e0 */ OSLockWord mLockCard;
    /* 3e8 */ OSLockWord mLockCartridge;
    /* 3f0 */ OSLockWord mLockInit;
    /* 3f8 */ u8 mUnk_3f8[2];
    /* 3fa */ u16 mMmemCheckerSub;
    /* 3fc */ u8 mUnk_3fc[4];
} OSSystemWork;

#define HW_MAIN_MEM_SYSTEM 0x027ffc00
#define SYSTEM_WORK ((OSSystemWork *) HW_MAIN_MEM_SYSTEM)
#define HW_MAIN_MEM_SYSTEM_BUF ((u8 *) HW_MAIN_MEM_SYSTEM)
#define gBootInfo (&SYSTEM_WORK->mWmBootBuf)

// Clears the IRQ disable bit and returns the previous bit.
OSIntrMode OS_EnableInterrupts(void);
// Sets the IRQ disable bit and returns the previous bit.
OSIntrMode OS_DisableInterrupts(void);
// Puts the IRQ disable bit back to the one in state and returns the previous bit.
OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
// Returns the processor mode (low five bits of the status register).
u32 OS_GetProcMode(void);

// Filled by OS_GetOwnerInfo from the bytes of a fixed-address block: mUnk_04 holds the 0x14 bytes at offset 0x06 of the
// block and mUnk_1a the 0x34 bytes at offset 0x1c.
typedef struct OwnerInfo {
    /* 00 */ u8 mLanguage;
    /* 01 */ u8 mFavoriteColor;
    /* 02 */ u8 mBirthdayMonth;
    /* 03 */ u8 mBirthdayDay;
    /* 04 */ u8 mNickName[0x14];
    /* 18 */ u16 mNickNameLength;
    /* 1a */ u8 mComment[0x34];
    /* 4e */ u16 mCommentLength;
} OwnerInfo;

// Disables interrupts and halts forever.
void OS_Terminate(void);

extern u16 OSi_IsInitReset;
extern u16 OSi_IsResetOccurred;

// Sets the IRQ and FIQ disable bits and returns their previous value.
OSIntrMode OS_DisableInterrupts_IrqAndFiq(void);
// Puts the IRQ and FIQ disable bits back to those in state and returns their previous value.
OSIntrMode OS_RestoreInterrupts_IrqAndFiq(OSIntrMode state);
// Halts the processor until the next interrupt.
void OS_Halt(void);
// Busy wait of about cycle / 4 loops.
void OS_SpinWait(u32 cycle);
// Receive function registered for channel 12 by OS_InitReset. Takes the command from bits 8 to 14 of its second
// argument: command 0x10 stores 1 in the halfword OSi_IsResetOccurred (nothing reads it), any other command ends in
// OS_Terminate.
void OSi_CommonCallback(u32 tag, u32 data);
// Runs once: opens PXI tag 12, waits for the other processor and installs OSi_CommonCallback, which stores 1 in
// the halfword OSi_IsResetOccurred for command 0x10 and halts for any other command. Nothing else reads the halfword.
void OS_InitReset(void);
// Fills the record from the words at 0x027ffc80: bits 0-2 of the halfword at +0x64, the low 4 bits of byte +2, bytes +3
// and +4, a 20-byte text from +6 with its length from byte +0x1a, a 52-byte text from +0x1c with its length from byte
// +0x50. The game copies the first text with its length into its own buffers.
void OS_GetOwnerInfo(OwnerInfo *info);
// Copies the 6 bytes at 0x027ffcf4 into the buffer (one game site prints them as six hex pairs joined by dashes).
void OS_GetMacAddress(void *macAddress);
