/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_InitArena FUN_037f9c04
#define PXI_Init thunk_FUN_037fb72c
#define OS_InitLock FUN_037f8cbc
#define OS_InitIrqTable FUN_037f89ec
#define OS_InitTick FUN_037fa3c0
#define OS_InitAlarm FUN_037fa834
#define OS_InitThread FUN_037f93cc
#define OS_InitReset FUN_037fb0e4
#define CTRDG_Init FUN_03803f9c
#define OS_Init FUN_037f9ab4
#include <nitro/os.h>
#include <nitro/mi/wram.h>
#include <nitro/pxi.h>
#include <nitro/spi.h>
    #include <nitro/ctrdg.h>

#include <nitro/code32.h>

#include <nitro/codereset.h>

#pragma thumb off
void OS_Init (void)
{
#ifdef SDK_ARM9
    SDK_ASSERT((u32) & (OS_GetSystemWork()->command_area) == HW_CMD_AREA);
#ifdef SDK_ENABLE_ARM7_PRINT
    OS_InitPrintServer();
#endif
    OS_InitArena();

    PXI_Init();

    OS_InitLock();
    OS_InitArenaEx();
    OS_InitIrqTable();
    OS_SetIrqStackChecker();
    OS_InitException();

    MI_Init();

    OS_InitVAlarm();
    OSi_InitVramExclusive();

#ifndef SDK_NO_THREAD
    OS_InitThread();
#endif

#ifndef SDK_SMALL_BUILD
    OS_InitReset();
#endif

#ifndef SDK_TEG
    CTRDG_Init();
#endif

#ifndef SDK_SMALL_BUILD
    CARD_Init();
#endif

#ifndef SDK_TEG
    PM_Init();
#endif

    OSi_WaitVCount0();

#else
    OS_InitArena();
    PXI_Init();
    OS_InitLock();
    OS_InitIrqTable();

#define SDK_EXCEPTION_BUG
#ifndef SDK_EXCEPTION_BUG
    OS_InitException();
#endif
    OS_InitTick();
    OS_InitAlarm();
    OS_InitThread();

#ifndef SDK_SMALL_BUILD
    OS_InitReset();
#endif

#ifndef SDK_TEG
    CTRDG_Init();
#endif

#endif
}
