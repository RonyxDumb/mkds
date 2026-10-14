/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_ResetRequestIrqMask FUN_037f881c
#include <nitro.h>
    #include <nitro/itcm_begin.h>
    #include <nitro/itcm_end.h>

#pragma thumb off
OSIrqMask OS_ResetRequestIrqMask (OSIrqMask intr)
{
    BOOL ime = OS_DisableIrq();
    OSIrqMask prep = reg_OS_IF;
    reg_OS_IF = intr;
    (void)OS_RestoreIrq(ime);
    return prep;
}
