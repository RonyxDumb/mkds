/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_ResetRequestIrqMask SetIF
#include "OS_interrupt.h"

#include "nitro/types.h"
#include "registers.h"
#include "mmap.h"
#include "OS_thread.h"
#include "code32.h"

OSIrqMask OS_ResetRequestIrqMask(OSIrqMask mask)
{
    u16 regIme = reg_OS_IME;
    reg_OS_IME = 0;
    OSIrqMask regIf = reg_OS_IF;
    reg_OS_IF = mask;
    u16 unused = reg_OS_IME;
    reg_OS_IME = regIme;
    return regIf;
}
