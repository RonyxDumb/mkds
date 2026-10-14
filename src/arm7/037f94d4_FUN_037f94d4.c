/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OSi_ThreadInfo SDK_data_038076fc
#define OSi_RemoveThreadFromList FUN_037f94d4
#include <nitro/os.h>
#include <nitro/mi.h>
#include <nitro/utest.h>

#include <nitro/code32.h>

#include  <nitro/codereset.h>
extern OSThreadInfo OSi_ThreadInfo;
#pragma thumb off
void OSi_RemoveThreadFromList (OSThread * thread)
{
    OSThread * t = OSi_ThreadInfo.list;
    OSThread * pre = NULL;

    while (t && t != thread) {
        pre = t;
        t = t->next;
    }

    SDK_ASSERTMSG(t, "Cannot remove thread from list.");

    if (!pre) {
        OSi_ThreadInfo.list = thread->next;
    } else {
        pre->next = thread->next;
    }
}
