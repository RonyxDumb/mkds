/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OSi_ThreadInfo SDK_data_038076fc
#define OSi_InsertThreadToList FUN_037f951c
#include <nitro/os.h>
#include <nitro/mi.h>
#include <nitro/utest.h>

#include <nitro/code32.h>

#include  <nitro/codereset.h>
extern OSThreadInfo OSi_ThreadInfo;
#pragma thumb off
void OSi_InsertThreadToList (OSThread * thread)
{
    OSThread * t = OSi_ThreadInfo.list;
    OSThread * pre = NULL;

    while (t && t->priority < thread->priority) {
        pre = t;
        t = t->next;
    }

    if (!pre) {
        thread->next = OSi_ThreadInfo.list;
        OSi_ThreadInfo.list = thread;
    } else {
        thread->next = pre->next;
        pre->next = thread;
    }
}
