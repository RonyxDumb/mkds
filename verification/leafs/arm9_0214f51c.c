/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define PMi_ExecuteList func_0214f51c
#include <nitro/spi/ARM9/pm.h>
#include <nitro/pxi.h>
#include <nitro/gx.h>
#include <nitro/spi/common/config.h>
#include <nitro/ctrdg.h>
#include <nitro/mb.h>

#pragma thumb off
void PMi_ExecuteList (PMSleepCallbackInfo * listp)
{
    while (listp) {
        (listp->callback)(listp->arg);
        listp = listp->next;
    }
}
