/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OSi_ThreadIdCount SDK_data_038076ec
#define OSi_GetUnusedThreadId FUN_037f9660
#include <nitro/os.h>
#include <nitro/mi.h>
#include <nitro/utest.h>

#include <nitro/code32.h>

#include  <nitro/codereset.h>
extern int OSi_ThreadIdCount;
#pragma thumb off
int OSi_GetUnusedThreadId (void)
    {
        ++OSi_ThreadIdCount;
        SDK_ASSERT(OSi_ThreadIdCount > 0);
        return OSi_ThreadIdCount;
    }
