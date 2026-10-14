/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_EnableIrqMask FUN_037f888c
#include <nitro.h>
    #include <nitro/itcm_begin.h>
    #include <nitro/itcm_end.h>

#pragma thumb off
OSIrqMask OS_EnableIrqMask (OSIrqMask intr)
{
    BOOL ime = OS_DisableIrq();
    OSIrqMask prep = reg_OS_IE;
    reg_OS_IE = prep | intr;
    (void)OS_RestoreIrq(ime);
    return prep;
}
