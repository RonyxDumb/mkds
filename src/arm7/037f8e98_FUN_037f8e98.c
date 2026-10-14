/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts FUN_037faf70
#define OS_RestoreInterrupts FUN_037faf84
#define OSi_InsertThreadToList FUN_037f951c
#define OSi_RescheduleThread FUN_037f8f48
#define OSi_ThreadInfo SDK_data_038076fc
#define OSi_IdleThread SDK_data_0380770c
#define OS_SetThreadPriority FUN_037f8e98
#include <nitro/os.h>
#include <nitro/mi.h>
#include <nitro/utest.h>

#include <nitro/code32.h>

#include  <nitro/codereset.h>
extern void OSi_InsertThreadToList (OSThread * thread);
extern void OSi_RescheduleThread (void);
extern OSThreadInfo OSi_ThreadInfo;
extern OSThread OSi_IdleThread;
#pragma thumb off
BOOL OS_SetThreadPriority (OSThread * thread, u32 prio)
{
    OSThread * t = OSi_ThreadInfo.list;
    OSThread * pre = NULL;
    OSIntrMode enable;

    SDK_ASSERTMSG(OS_THREAD_PRIORITY_MIN <= prio
                  && prio <= OS_THREAD_PRIORITY_MAX, "invalid priority");
    SDK_ASSERTMSG(thread != &OSi_IdleThread, "cannot change idle thread priority.");

    enable = OS_DisableInterrupts();

    while (t && t != thread) {
        pre = t;
        t = t->next;
    }

    if (!t || t == &OSi_IdleThread) {
        (void)OS_RestoreInterrupts(enable);
        return FALSE;
    }

    if (t->priority != prio) {

        if (!pre) {
            OSi_ThreadInfo.list = thread->next;
        } else {
            pre->next = thread->next;
        }

        thread->priority = prio;

        OSi_InsertThreadToList(thread);
        OSi_RescheduleThread();
    }

    (void)OS_RestoreInterrupts(enable);
    return TRUE;
}
