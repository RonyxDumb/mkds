/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_UnLockCartridge thunk_FUN_037f8b24
#define OS_RestoreInterrupts FUN_037faf84
#define CTRDGi_UnlockByProcessor FUN_038039ac
#include <nitro/ctrdg.h>

#include <../include/ctrdg_work.h>

#include <nitro/os/ARM9/cache.h>

#pragma thumb off
void CTRDGi_UnlockByProcessor (u16 lockID, CTRDGLockByProc *info)
{
	if (!info->locked) {
		(void)OS_UnLockCartridge(lockID);
	}

	(void)OS_RestoreInterrupts(info->irq);
}
