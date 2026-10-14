/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_IsThreadTerminated FUN_037f9158
#include <nitro/os.h>
#include <nitro/mi.h>
#include <nitro/utest.h>

#include <nitro/code32.h>

#include  <nitro/codereset.h>

#pragma thumb off
BOOL OS_IsThreadTerminated (const OSThread * thread)
{
    return (thread->state == OS_THREAD_STATE_TERMINATED) ? TRUE : FALSE;
}
