#pragma once

#include "types.h"

s32 j_Operation_CartArm7(u16 lockID);
// Takes a free lock id out of the lock id table and returns it, or -3 when none is left.
s32 Os_AllocateLockId(void);
// Puts a lock id back into the lock id table.
void Os_ReleaseLockId(u16 lockID);

void Os_Lock_Wait(void);

typedef struct OSLockWord OSLockWord;

// Returns the owner id of a lock word.
u16 Os_Lock_GetOwnerId(OSLockWord *lockp);

void SetCardOwnerArm7(void);
// Hands the card bus to the ARM9 (clears bit 0x800 of the halfword at 0x04000204). Os_TryLockCard runs it once the card
// lock word is taken.
void SetCardOwnerArm9(void);

s32 Os_UnlockCard(u16 lockID);
// Takes the card lock word for lockID, retrying (with Os_Lock_Wait between tries) until it succeeds, with IRQ
// disabled during each try; gives the card bus to the ARM9 once it is taken. Returns the result of the last try, 0
// when taken.
s32 Os_TryLockCard(u16 lockID);

void SetCartOwnerArm7(void);
// Hands the cartridge bus to the ARM9 (clears bit 0x80 of the halfword at 0x04000204). Operation_CartArm9 runs it
// once the cartridge lock word is taken.
void SetCartOwnerArm9(void);

typedef struct OSLockWord {
    /* 00 */ u32 mLockFlag;
    /* 04 */ u16 mOwnerID;
    /* 06 */ u16 mExtension;
} OSLockWord;

// Set to 1 by the first call of Os_InitializeLock; later calls return at once.
extern s32 g_Os_LockInitialized;

// One try on the cartridge lock word for lockID, with IRQ and FIQ disabled during the try; gives the cartridge bus
// to the ARM9 once it is taken. Returns the result of the try, 0 when taken.
s32 Operation_CartArm9(u16 lockID);
// Releases the cartridge lock word when lockID holds it, else returns -2. Gives the cartridge bus back to the ARM7,
// clears the owner id and the lock word with IRQ and FIQ disabled, returns 0.
s32 Operation_CartArm7(u16 lockID);
// One try on a lock word: swaps lockID into lockp.mLockFlag with interrupts disabled (IRQ and FIQ when disableFiq is
// set). When the swap finds it free, runs ctrlFuncp and stores lockID as the owner. Returns the old lock flag.
s32 Os_Lock_HandleTryLock(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), s32 disableFiq);
// Releases a lock word when lockID owns it, else returns -2. Clears the owner, runs ctrlFuncp, then clears the lock
// flag, with interrupts disabled. Returns 0.
s32 Os_Lock_UnlockImpl(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), s32 disableFiq);
// Unlocks a lock word with IRQ disabled.
s32 Os_Lock_Unlock(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void));
// Tries a lock word again, waiting between tries, until it is taken. Returns the result of the last try.
s32 Os_Lock_TryLockImpl(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), s32 disableFiq);
// Locks a lock word with IRQ disabled.
s32 Os_Lock_TryLock(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void));
// Runs once. Takes the lock word at 0x027ffff0 with id 0x7e and waits until its extension is 0, sets the lock id
// bits at 0x027fffb0 and 0x027fffb4, clears 0x28 bytes at 0x027fffc0, hands the card and cartridge buses to the
// ARM7, releases the lock with id 0x7e and takes it again with id 0x7f.
void Os_InitializeLock(void);
