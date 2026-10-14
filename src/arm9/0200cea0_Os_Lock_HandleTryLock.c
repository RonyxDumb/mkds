/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define _ZN3IRQ10DisableAllEv Os_DisableIrqFiq
#define _ZN3IRQ7DisableEv Os_DisableIrq
#define func_0205a74c Mem_Swap16
#define _ZN3IRQ10RestoreAllEj Os_RestoreIrqFiq
#define _ZN3IRQ7RestoreEj Os_RestoreIrq
#define func_02057198 Os_Lock_HandleTryLock
#include "../../vendor/sm64ds/include/types.h"
typedef struct {
    u32 lock;
    u16 owner;
} LockObj;

extern u32 _ZN3IRQ10DisableAllEv(void);
extern u32 _ZN3IRQ7DisableEv(void);
extern void _ZN3IRQ10RestoreAllEj(u32 state);
extern void _ZN3IRQ7RestoreEj(u32 state);

extern u32 func_0205a74c(u32 val, LockObj *addr);

u32 func_02057198(u32 val, LockObj *addr, void (*cleanupFn)(void), u32 useAll)
{
    u32 state;
    u32 old;

    if (useAll)
        state = _ZN3IRQ10DisableAllEv();
    else
        state = _ZN3IRQ7DisableEv();

    old = func_0205a74c(val, addr);
    if (old == 0)
    {
        if (cleanupFn)
            cleanupFn();
        addr->owner = (u16)val;
    }

    if (useAll)
        _ZN3IRQ10RestoreAllEj(state);
    else
        _ZN3IRQ7RestoreEj(state);

    return old;
}
