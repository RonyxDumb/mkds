/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MI_CpuCopy8 Mem_CpuCopy8
#define cardi_common SDK_data_0217fa40
#define CARDi_ReadFromCache GlobalSZ_SomeFn
#include "nitro/types.h"
#include "CARD_pullOut.h"
#include "CARD_rom.h"
#include "MI_dma_card.h"
#include "MI_memory.h"
#include "OS_cache.h"
#include "OS_interrupt.h"
#include "code32.h"
extern CARDiCommon *p = &cardi_common;
#pragma thumb off
BOOL CARDi_ReadFromCache(CARDRomStat *p)
{
    CARDiCommon *c = &cardi_common;
    const u32 cur_page = CARD_ALIGN_HI_BIT(c->src);
    if (cur_page == (u32)p->cache_page)
    {
        const u32 mod = c->src - cur_page;
        u32 len = CARD_ROM_PAGE_SIZE - mod;
        if (len > c->len)
        {
            len = c->len;
        }
        MI_CpuCopy8(p->cache_buf + mod, (void *)c->dst, len);
        c->src += len;
        c->dst += len;
        c->len -= len;
    }
    return (c->len > 0);
}
