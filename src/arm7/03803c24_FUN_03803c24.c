/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SVC_CpuSet thunk_FUN_038011e4
#define OS_GetLockID FUN_037f8a1c
#define CTRDGi_Work SDK_data_03809f38
#define CTRDGi_InitCommon FUN_03803c24
#include <nitro/ctrdg.h>

#include <../include/ctrdg_work.h>

#include <nitro/os/ARM9/cache.h>
extern CTRDGWork CTRDGi_Work;
#pragma thumb off
void CTRDGi_InitCommon (void)
{
	SVC_CpuClear(0, &CTRDGi_Work, sizeof(CTRDGi_Work), 32);
	CTRDGi_Work.lockID = (u16)OS_GetLockID();
}
