/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts FUN_037faf70
#define OS_SleepThread FUN_037f9104
#define OS_RestoreInterrupts FUN_037faf84
#define CARDi_ReadRomIDCore FUN_03800988
#define OS_WakeupThread FUN_037f9088
#define OS_WakeupThreadDirect FUN_037f9054
#define cardi_common SDK_data_038090c0
#define CARDi_ReadRomID FUN_0380084c
#include <nitro.h>

#include "../include/card_common.h"
#include "../include/card_rom.h"
extern u32 CARDi_ReadRomIDCore (void);
extern CARDiCommon *p = &cardi_common;
#pragma thumb off
    u32 CARDi_ReadRomID (void)
    {
        CARDRomStat *const p = &rom_stat;
        CARDiCommon *const c = &cardi_common;

        u32 ret = 0;

        SDK_ASSERT(CARD_IsAvailable());
        SDK_ASSERTMSG(CARDi_GetTargetMode() == CARD_TARGET_ROM, "must be locked by CARD_LockRom()");

        CARDi_WaitTask(c, NULL, NULL);

        ret = CARDi_ReadRomIDCore();
        CARDi_ReadEnd();
        return ret;
    }
