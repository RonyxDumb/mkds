/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define _ZN3IRQ7DisableEv Os_DisableIrq
#define _ZN3IRQ7RestoreEj Os_RestoreIrq
#define data_020a8114 SDK_data_02180448
#define func_0205ff20 func_021501d8
#include "../../vendor/sm64ds/include/types.h"
extern u32 _ZN3IRQ7DisableEv(void);
extern void _ZN3IRQ7RestoreEj(u32 prev);

extern u32 data_020a8114;  /* 0x020a8114 */

u32 func_0205ff20(void) {
    u32 saved = _ZN3IRQ7DisableEv();
    u32 r2 = data_020a8114;
    if (r2 != 0) {
        _ZN3IRQ7RestoreEj(saved);
        return 0;
    }
    data_020a8114 = 1;
    _ZN3IRQ7RestoreEj(saved);
    return 1;
}
