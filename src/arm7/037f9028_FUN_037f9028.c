/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OSi_ThreadInfo SDK_data_038076fc
#define OS_SelectThread FUN_037f9028
#include <nitro/os.h>
#include <nitro/mi.h>
#include <nitro/utest.h>

#include <nitro/code32.h>

#include  <nitro/codereset.h>
extern OSThreadInfo OSi_ThreadInfo;
#pragma thumb off
OSThread * OS_SelectThread (void)
{
    OSThread * t = OSi_ThreadInfo.list;

    while (t && !OS_IsThreadRunnable(t)) {
        t = t->next;
    }

    return t;
}
