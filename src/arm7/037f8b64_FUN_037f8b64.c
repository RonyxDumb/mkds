#define OS_DisableInterrupts_IrqAndFiq FUN_037faf9c
#define OS_DisableInterrupts FUN_037faf70
#define MI_SwapWord FUN_037fb4c0
#define OS_RestoreInterrupts_IrqAndFiq FUN_037fafb0
#define OS_RestoreInterrupts FUN_037faf84
/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#include <nitro.h>

void _ISDbgLib_Initialize(void);
void _ISDbgLib_AllocateEmualtor(void);
void _ISDbgLib_FreeEmulator(void);

s32 OS_LockByWord_IrqAndFiq(u16 lockID, OSLockWord * lockp, void (*ctrlFuncp)(void));
s32 OS_UnlockByWord_IrqAndFiq(u16 lockID, OSLockWord * lockp, void (*ctrlFuncp)(void));
s32 OS_TryLockByWord_IrqAndFiq(u16 lockID, OSLockWord * lockp, void (*crtlFuncp)(void));

static s32 OSi_DoLockByWord(u16 lockID, OSLockWord * lockp, void (*ctrlFuncp)(void), BOOL disableFiq);
static s32 OSi_DoUnlockByWord(u16 lockID, OSLockWord * lockp, void (*ctrlFuncp)(void), BOOL disableFIQ);
static s32 FUN_037f8b64(u16 lockID, OSLockWord * lockp, void (*ctrlFuncp)(void), BOOL disableFIQ);

static void OSi_AllocateCartridgeBus(void);
static void OSi_FreeCartridgeBus(void);
static void OSi_AllocateCardBus(void);
static void OSi_FreeCardBus(void);
static void OSi_WaitByLoop(void);

#ifdef  SDK_ARM9
#define OSi_ASSERT_ID(id)       SDK_ASSERTMSG(id >= OS_MAINP_LOCK_ID_START && id <= OS_MAINP_SYSTEM_LOCK_ID, \
                                              "lock ID %d is out of bounds", id)
#else
#define OSi_ASSERT_ID(id)       SDK_ASSERTMSG(id >= OS_SUBP_LOCK_ID_START && id <= OS_SUBP_SYSTEM_LOCK_ID, \
                                              "lock ID %d is out of bounds", id)
#endif

#define OSi_LOCKID_INITIAL_FLAG_0     0xffffffff
#define OSi_LOCKID_INITIAL_FLAG_1     0xffff0000

#ifdef SDK_ARM9
    #define OSi_ANYP_LOCK_ID_FLAG  HW_LOCK_ID_FLAG_MAIN
    #define OSi_ANYP_LOCK_ID_START OS_MAINP_LOCK_ID_START
#else
    #define OSi_ANYP_LOCK_ID_FLAG  HW_LOCK_ID_FLAG_SUB
    #define OSi_ANYP_LOCK_ID_START OS_SUBP_LOCK_ID_START
#endif

static inline void OSi_WaitByLoop (void)
{
    SVC_WaitByLoop(0x1000 / 4);
}

void OS_InitLock (void)
{
    static BOOL isInitialized = FALSE;
    OSLockWord * lockp;

    if (isInitialized)
        return;

    isInitialized = TRUE;
    lockp = (OSLockWord *)HW_INIT_LOCK_BUF;

#ifdef SDK_ARM9
    {
        lockp->lockFlag = 0;
        (void)OS_LockByWord(OS_MAINP_SYSTEM_LOCK_ID - 1, lockp, NULL);

        while (lockp->extension != 0) {
            OSi_WaitByLoop();
        }

        ((u32 *)OSi_ANYP_LOCK_ID_FLAG)[0] = OSi_LOCKID_INITIAL_FLAG_0;
        ((u32 *)OSi_ANYP_LOCK_ID_FLAG)[1] = OSi_LOCKID_INITIAL_FLAG_1;

        MI_CpuClear32((void *)HW_SHARED_LOCK_BUF, HW_CTRDG_LOCK_BUF - HW_SHARED_LOCK_BUF);

        MIi_SetCardProcessor(MI_PROCESSOR_ARM7);
        MIi_SetCartridgeProcessor(MI_PROCESSOR_ARM7);

#ifndef SDK_FINALROM
        _ISDbgLib_Initialize();
#endif
        (void)OS_UnlockByWord(OS_MAINP_SYSTEM_LOCK_ID - 1, lockp, NULL);
        (void)OS_LockByWord(OS_MAINP_SYSTEM_LOCK_ID, lockp, NULL);
    }

#else
    {
        lockp->extension = 0;
        while (lockp->ownerID != OS_MAINP_SYSTEM_LOCK_ID) {
            OSi_WaitByLoop();
        }

#ifndef SDK_FINALROM
        _ISDbgLib_Initialize();
#endif

        ((u32 *)OSi_ANYP_LOCK_ID_FLAG)[0] = OSi_LOCKID_INITIAL_FLAG_0;
        ((u32 *)OSi_ANYP_LOCK_ID_FLAG)[1] = OSi_LOCKID_INITIAL_FLAG_1;

        lockp->extension = OS_SUBP_SYSTEM_LOCK_ID;
    }
#endif
}

static s32 OSi_DoLockByWord (u16 lockID, OSLockWord * lockp, void (*ctrlFuncp)(void), BOOL disableFiq)
{
    s32 lastLockFlag;

    while ((lastLockFlag = FUN_037f8b64(lockID, lockp, ctrlFuncp, disableFiq)) > OS_LOCK_SUCCESS) {
        OSi_WaitByLoop();
    }

    return lastLockFlag;
}

s32 OS_LockByWord (u16 lockID, OSLockWord * lockp, void (*ctrlFuncp)(void))
{
    return OSi_DoLockByWord(lockID, lockp, ctrlFuncp, FALSE);
}

s32 OS_LockByWord_IrqAndFiq (u16 lockID, OSLockWord * lockp, void (*ctrlFuncp)(void))
{
    return OSi_DoLockByWord(lockID, lockp, ctrlFuncp, TRUE);
}

static s32 OSi_DoUnlockByWord (u16 lockID, OSLockWord * lockp, void (*ctrlFuncp)(void), BOOL disableFIQ)
{
    OSIntrMode lastInterrupts;

    OSi_ASSERT_ID(lockID);

    if (lockID != lockp->ownerID) {
        return OS_UNLOCK_ERROR;
    }

    lastInterrupts = (disableFIQ) ? FUN_037faf9c() : FUN_037faf70();

    lockp->ownerID = 0;
    if (ctrlFuncp) {
        ctrlFuncp();
    }
    lockp->lockFlag = 0;

    if (disableFIQ) {
        (void)FUN_037fafb0(lastInterrupts);
    } else {
        (void)FUN_037faf84(lastInterrupts);
    }

    return OS_UNLOCK_SUCCESS;
}

s32 OS_UnlockByWord (u16 lockID, OSLockWord * lockp, void (*ctrlFuncp)(void))
{
    return OSi_DoUnlockByWord(lockID, lockp, ctrlFuncp, FALSE);
}

s32 OS_UnLockByWord (u16 lockID, OSLockWord * lockp, void (*ctrlFuncp)(void))
{
    return OSi_DoUnlockByWord(lockID, lockp, ctrlFuncp, FALSE);
}

s32 OS_UnlockByWord_IrqAndFiq (u16 lockID, OSLockWord * lockp, void (*ctrlFuncp)(void))
{
    return OSi_DoUnlockByWord(lockID, lockp, ctrlFuncp, TRUE);
}

static s32 FUN_037f8b64 (u16 lockID, OSLockWord * lockp, void (*ctrlFuncp)(void), BOOL disableFIQ)
{
    s32 lastLockFlag;
    OSIntrMode lastInterrupts;

    OSi_ASSERT_ID(lockID);

    lastInterrupts = (disableFIQ) ? FUN_037faf9c() : FUN_037faf70();
    lastLockFlag = (s32)FUN_037fb4c0(lockID, &lockp->lockFlag);

    if (lastLockFlag == OS_LOCK_SUCCESS) {
        if (ctrlFuncp) {
            ctrlFuncp();
        }

        lockp->ownerID = lockID;
    }

    if (disableFIQ) {
        (void)FUN_037fafb0(lastInterrupts);
    } else {
        (void)FUN_037faf84(lastInterrupts);
    }

    return lastLockFlag;
}

s32 OS_TryLockByWord (u16 lockID, OSLockWord * lockp, void (*ctrlFuncp)(void))
{
    return FUN_037f8b64(lockID, lockp, ctrlFuncp, FALSE);
}

s32 OS_TryLockByWord_IrqAndFiq (u16 lockID, OSLockWord * lockp, void (*ctrlFuncp)(void))
{
    return FUN_037f8b64(lockID, lockp, ctrlFuncp, TRUE);
}

s32 OS_LockCartridge (u16 lockID)
{
    s32 lastLockFlag;

    OSi_ASSERT_ID(lockID);
    lastLockFlag = OSi_DoLockByWord(lockID, (OSLockWord *)HW_CTRDG_LOCK_BUF, OSi_AllocateCartridgeBus, TRUE);

#ifndef SDK_FINALROM
    _ISDbgLib_AllocateEmualtor();
#endif

    return lastLockFlag;
}

s32 OS_UnlockCartridge (u16 lockID)
{
    s32 lastLockFlag;

    OSi_ASSERT_ID(lockID);

#ifndef SDK_FINALROM
    _ISDbgLib_FreeEmulator();
#endif

    lastLockFlag = OSi_DoUnlockByWord(lockID, (OSLockWord *)HW_CTRDG_LOCK_BUF, OSi_FreeCartridgeBus, TRUE);
    return lastLockFlag;
}

extern s32 OS_UnLockCartridge (u16 lockID);

s32 OS_TryLockCartridge (u16 lockID)
{
    s32 lastLockFlag;

    lastLockFlag = FUN_037f8b64(lockID, (OSLockWord *)HW_CTRDG_LOCK_BUF, OSi_AllocateCartridgeBus, TRUE);

#ifndef SDK_FINALROM
    if (lastLockFlag == OS_LOCK_SUCCESS) {
        _ISDbgLib_AllocateEmualtor();
    }
#endif

    return lastLockFlag;
}

static void OSi_AllocateCartridgeBus (void)
{
#ifdef SDK_ARM9
    MIi_SetCartridgeProcessor(MI_PROCESSOR_ARM9);
#endif
}

static void OSi_FreeCartridgeBus (void)
{
#ifdef SDK_ARM9
    MIi_SetCartridgeProcessor(MI_PROCESSOR_ARM7);
#endif
}

#if defined(SDK_TEG)
    static u32 osi_card_lock = OS_LOCK_ID_ERROR;

    static s32 OSi_LockCardID (u16 lockID, BOOL blocking)
    {
        s32 ret = OS_LOCK_ID_ERROR;
        for (;;) {
            OSIntrMode bak_psr = FUN_037faf70();
            ret = osi_card_lock;
            if (ret == OS_LOCK_ID_ERROR) {
                osi_card_lock = lockID;
                ret = OS_LOCK_SUCCESS;
            }
            (void)FUN_037faf84(bak_psr);
            if ((ret != OS_LOCK_SUCCESS) && blocking) {
                OSi_WaitByLoop();
                continue;
            }
            break;
        }
        return ret;
    }

    static s32 OSi_UnlockCardID (u16 lockID)
    {
        if (osi_card_lock != lockID)
            return OS_UNLOCK_ERROR;
        osi_card_lock = OS_LOCK_ID_ERROR;
        return OS_UNLOCK_SUCCESS;
    }
#endif

s32 OS_LockCard (u16 lockID)
{
    OSi_ASSERT_ID(lockID);

#if defined(SDK_TEG)
    return OSi_LockCardID(lockID, TRUE);
#else
    return OS_LockByWord(lockID, (OSLockWord *)HW_CARD_LOCK_BUF, OSi_AllocateCardBus);
#endif
}

s32 OS_UnlockCard (u16 lockID)
{
    OSi_ASSERT_ID(lockID);

#if defined(SDK_TEG)
    return OSi_UnlockCardID(lockID);
#else
    return OS_UnlockByWord(lockID, (OSLockWord *)HW_CARD_LOCK_BUF, OSi_FreeCardBus);
#endif
}

extern s32 OS_UnLockCard (u16 lockID);

s32 OS_TryLockCard (u16 lockID)
{
#if defined(SDK_TEG)
    return OSi_LockCardID(lockID, FALSE);
#else
    return OS_TryLockByWord(lockID, (OSLockWord *)HW_CARD_LOCK_BUF, OSi_AllocateCardBus);
#endif
}

static void OSi_AllocateCardBus (void)
{
#ifdef SDK_ARM9
    MIi_SetCardProcessor(MI_PROCESSOR_ARM9);
#endif
}

static void OSi_FreeCardBus (void)
{
#ifdef SDK_ARM9
    MIi_SetCardProcessor(MI_PROCESSOR_ARM7);
#endif
}

u16 OS_ReadOwnerOfLockWord (OSLockWord * lockp)
{
    return lockp->ownerID;
}

#include <nitro/code32.h>

extern s32 OS_GetLockID (void);

extern void OS_ReleaseLockID (register u16 lockID);

#include <nitro/codereset.h>
#undef OS_DisableInterrupts_IrqAndFiq
#undef OS_DisableInterrupts
#undef MI_SwapWord
#undef OS_RestoreInterrupts_IrqAndFiq
#undef OS_RestoreInterrupts
