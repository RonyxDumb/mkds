/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_EnableIrqMask Os_EnableIrqHandler
#include "OS_interrupt.h"

#include "nitro/types.h"
#include "registers.h"
#include "mmap.h"
#include "OS_thread.h"
#include "code32.h"

OSIrqMask OS_EnableIrqMask(OSIrqMask mask)
{
    u16 regIme = reg_OS_IME;
    reg_OS_IME = 0;
    OSIrqMask regIe = reg_OS_IE;
    reg_OS_IE = regIe | mask;
    u16 unused = reg_OS_IME;
    reg_OS_IME = regIme;
    return regIe;
}
