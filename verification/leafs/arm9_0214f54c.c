/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define PMi_DeleteList func_0214f54c
#include <nitro/spi/ARM9/pm.h>
#include <nitro/pxi.h>
#include <nitro/gx.h>
#include <nitro/spi/common/config.h>
#include <nitro/ctrdg.h>
#include <nitro/mb.h>

#pragma thumb off
void PMi_DeleteList (PMSleepCallbackInfo ** listp, PMSleepCallbackInfo * info)
{
    PMSleepCallbackInfo * p = *listp;
    PMSleepCallbackInfo * pre;

    if (!listp) {
        return;
    }

    pre = p = *listp;
    while (p) {
        if (p == info) {
            if (p == pre) {
                *listp = p->next;
            } else {
                pre->next = p->next;
            }
            break;
        }

        pre = p;
        p = p->next;
    }
}
