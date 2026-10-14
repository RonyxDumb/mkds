/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts FUN_037faf70
#define OSi_RescheduleThread FUN_037f8f48
#define OS_RestoreInterrupts FUN_037faf84
#define OS_WakeupThreadDirect FUN_037f9054
#include <nitro/os.h>
#include <nitro/mi.h>
#include <nitro/utest.h>

#include <nitro/code32.h>

#include  <nitro/codereset.h>
extern void OSi_RescheduleThread (void);
#pragma thumb off
void OS_WakeupThreadDirect (OSThread * thread)
{
    OSIntrMode enable;

    SDK_ASSERT(thread);
    SDK_ASSERT(thread->state != OS_THREAD_STATE_TERMINATED);

    enable = OS_DisableInterrupts();

    {
        thread->state = OS_THREAD_STATE_READY;
        OSi_RescheduleThread();

    }

    (void)OS_RestoreInterrupts(enable);
}
