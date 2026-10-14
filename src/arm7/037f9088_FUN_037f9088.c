/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts FUN_037faf70
#define OSi_RemoveLinkFromQueue FUN_037f95b4
#define OSi_RescheduleThread FUN_037f8f48
#define OS_RestoreInterrupts FUN_037faf84
#define OS_WakeupThread FUN_037f9088
#include <nitro/os.h>
#include <nitro/mi.h>
#include <nitro/utest.h>

#include <nitro/code32.h>

#include  <nitro/codereset.h>
extern OSThread * OSi_RemoveLinkFromQueue (OSThreadQueue * queue);
extern void OSi_RescheduleThread (void);
#pragma thumb off
void OS_WakeupThread (OSThreadQueue * queue)
{
    OSIntrMode enable;
#ifndef SDK_THREAD_INFINITY
    u32 mask;
#else
    BOOL isNeedRescheduling = FALSE;
#endif
    SDK_ASSERT(queue);
    enable = OS_DisableInterrupts();

#ifndef SDK_THREAD_INFINITY
    mask = (u32) * queue;
    if (mask) {

        OSThread * t = OSi_ThreadInfo.list;
        while (t) {
            if (mask & (1UL << t->id)) {
                t->state = OS_THREAD_STATE_READY;
            }

            t = t->next;
        }

        OS_InitThreadQueue(queue);
        OSi_RescheduleThread();
    }
#else
    if (queue->head) {
        while (queue->head) {
            OSThread * thread = OSi_RemoveLinkFromQueue(queue);

            thread->state = OS_THREAD_STATE_READY;
            thread->queue = NULL;
            thread->link.prev = thread->link.next = NULL;
        }

        OS_InitThreadQueue(queue);
        OSi_RescheduleThread();
    }
#endif

    (void)OS_RestoreInterrupts(enable);
}
