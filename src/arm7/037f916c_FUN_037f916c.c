/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts FUN_037faf70
#define OS_SleepThread FUN_037f9104
#define OS_RestoreInterrupts FUN_037faf84
#define OS_JoinThread FUN_037f916c
#include <nitro/os.h>
#include <nitro/mi.h>
#include <nitro/utest.h>

#include <nitro/code32.h>

#include  <nitro/codereset.h>
extern void OS_SleepThread (OSThreadQueue * queue);
#pragma thumb off
void OS_JoinThread (OSThread * thread)
{
    OSIntrMode enabled = OS_DisableInterrupts();

    SDK_ASSERT(thread);

    if (thread->state != OS_THREAD_STATE_TERMINATED) {
        OS_SleepThread(&thread->joinQueue);
    }

    (void)OS_RestoreInterrupts(enabled);
}
