/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MI_CpuCopy8 FUN_037fb390
#define cardi_common SDK_data_038090c0
#define CARDi_ReadFromCache FUN_03800b84
#include <nitro.h>

#include "../include/card_common.h"
#include "../include/card_rom.h"
extern CARDiCommon *p = &cardi_common;
#pragma thumb off
BOOL CARDi_ReadFromCache (CARDRomStat *p)
{
	CARDiCommon *c = &cardi_common;
	const u32 cur_page = CARD_ALIGN_HI_BIT(c->src);

	if (cur_page == (u32)p->cache_page) {
		const u32 mod = c->src - cur_page;
		u32 len = CARD_ROM_PAGE_SIZE - mod;

		if (len > c->len)
			len = c->len;

		MI_CpuCopy8(p->cache_buf + mod, (void *)c->dst, len);

		c->src += len;
		c->dst += len;
		c->len -= len;
	}

	return (c->len > 0);
}
