/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WaitLoop_BbpAccess FUN_0600f00c

#include "WlSys.h"
#include "WlLib.h"

#include "MAC.h"
#include "DbgChar.h"
#include "WaitLoop.h"

#pragma thumb off
u32 WaitLoop_BbpAccess(void)
{
    u32 i;

    for (i = 0; i < 10240; i++) {
        if ((*(vu16 *)MREG_BBP_STS & SRLDEV_STS_BUSY) == 0) {
            return 0;
        }
    }

    DbgPuts("Check BBP Timeout\r");

    return 1;
}
