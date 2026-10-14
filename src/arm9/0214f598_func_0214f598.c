/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define PMi_AppendList func_0214f598
#include <nitro/spi/ARM9/pm.h>
#include <nitro/pxi.h>
#include <nitro/gx.h>
#include <nitro/spi/common/config.h>
#include <nitro/ctrdg.h>
#include <nitro/mb.h>

#pragma thumb off
void PMi_AppendList (PMSleepCallbackInfo ** listp, PMSleepCallbackInfo * info)
{
    if (!listp) {
        return;
    }

    if (!*listp) {
        info->next = NULL;
        *listp = info;
    } else {
        PMSleepCallbackInfo * p = *listp;
        while (p->next) {
            p = p->next;
        }

        info->next = p->next;
        p->next = info;
    }
}
