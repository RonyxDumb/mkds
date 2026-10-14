/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define WM_GetSystemWork Wm_GetGlobal
#define func_0206152c Wm_CheckInitialized
#define _ZN4CP1519InvalidateDataCacheEjj DC_InvalidateRangeNoClean
#define func_020619ac func_021432ac
#include "../../vendor/sm64ds/include/types.h"
extern int WM_GetSystemWork(void);
extern int func_0206152c(void);
extern void _ZN4CP1519InvalidateDataCacheEjj(u32 a, u32 b);

char* func_020619ac(char* a, unsigned int idx)
{
    int h;
    int n;
    char* local[16];
    int i;
    h = WM_GetSystemWork();
    if (func_0206152c() != 0) return 0;
    if (idx < 1) goto ret0;
    if (idx > 0xf) { ret0: return 0; }
    _ZN4CP1519InvalidateDataCacheEjj((u32)*(char**)(h + 4) + 0x17e, 2);
    if ((*(u16*)(*(char**)(h + 4) + 0x100 + 0x7e) & (1u << idx)) == 0) return 0;
    n = *(u16*)(a + 4);
    if (n == 0) return 0;
    local[0] = a + 0xa;
    i = 0;
    for (;;) {
        if (idx == *(u16*)(local[i] + 4)) return local[i];
        i++;
        local[i] = (char*)(*(u16*)(a + 6) + (u32)local[i - 1]);
        if (i >= *(volatile u16*)(a + 4)) break;
    }
    return 0;
}
