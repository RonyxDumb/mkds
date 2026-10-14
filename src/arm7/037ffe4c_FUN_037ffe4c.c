/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts FUN_037faf70
#define OS_SetThreadPriority FUN_037f8e98
#define OS_RestoreInterrupts FUN_037faf84
#define cardi_common SDK_data_038090c0
#define CARD_SetThreadPriority FUN_037ffe4c
#include <nitro.h>
#include <nitro/mb.h>

#include "../include/card_common.h"
#include "../include/card_spi.h"
extern CARDiCommon *const p = &cardi_common;
#pragma thumb off
u32 CARD_SetThreadPriority (u32 prior)
{
	CARDiCommon *const p = &cardi_common;
	SDK_ASSERT(CARD_IsAvailable());

	{
		OSIntrMode bak_psr = OS_DisableInterrupts();
		u32 ret = p->priority;
		SDK_ASSERT((prior >= OS_THREAD_PRIORITY_MIN) && (prior <= OS_THREAD_PRIORITY_MAX));
		p->priority = prior;
		(void)OS_SetThreadPriority(p->thread, p->priority);
		(void)OS_RestoreInterrupts(bak_psr);
		return ret;
	}
}
