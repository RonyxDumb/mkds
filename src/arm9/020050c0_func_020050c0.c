/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define DGT_SetOverlayTableMode func_02150dc8
#define FSi_CompareDigest Fs_ComputeCompareDigest
#define OS_Terminate Os_Terminate
#define OS_DisableInterrupts Os_DisableIrq
#define OS_RestoreInterrupts Os_RestoreIrq
#define SDK_OVERLAYTABLE_DIGEST SDK_data_0216f2dc
#define fsi_ovt9 SDK_data_0216f35c
#define fsi_ovt7 SDK_data_0216f364
#define FS_AttachOverlayTable func_020050c0
#include <nitro/os.h>
#include <nitro/mi.h>
#include <nitro/fs.h>
#include <nitro/mb.h>
#include <nitro/dgt/common.h>
#include <nitro/dgt/dgt.h>

#include "../include/util.h"
#include "../include/rom.h"
#include "../include/mw_dtor.h"
extern BOOL FSi_CompareDigest (const u8 *spec_digest, void *src, int len);
extern u8 SDK_OVERLAYTABLE_DIGEST[];
#pragma thumb off
void FS_AttachOverlayTable (MIProcessor target, const void *ptr, u32 len)
{
#ifdef  SDK_TS
	if ((ptr != NULL) && (target == MI_PROCESSOR_ARM9)) {
		int bak_ovt_mode = DGT_SetOverlayTableMode(TRUE);
		if (!FSi_CompareDigest((const u8 *)SDK_OVERLAYTABLE_DIGEST, (void *)ptr, (int)len)) {
			OS_TPanic("FS_AttachOverlayTable() failed! (invalid overlay-table data)");
		}
		(void)DGT_SetOverlayTableMode(bak_ovt_mode);
	}
#endif

	{
		CARDRomRegion *const pr = (target == MI_PROCESSOR_ARM9) ? &fsi_ovt9 : &fsi_ovt7;
		OSIntrMode bak_psr = OS_DisableInterrupts();

		pr->offset = (u32)ptr;
		pr->length = len;

		(void)OS_RestoreInterrupts(bak_psr);
	}
}
