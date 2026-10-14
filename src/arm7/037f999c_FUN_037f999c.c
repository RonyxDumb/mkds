/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts FUN_037faf70
#define OSi_DequeueItem FUN_037f9918
#define OS_WakeupThread FUN_037f9088
#define OS_RestoreInterrupts FUN_037faf84
#define OSi_ThreadInfo SDK_data_038076fc
#define OS_UnlockMutex FUN_037f999c
#include <nitro/types.h>
#include <nitro.h>
extern void OSi_DequeueItem (OSThread * thread, OSMutex * mutex);
#pragma thumb off
void OS_UnlockMutex (OSMutex * mutex)
{
    OSIntrMode saved;
    OSThread * currentThread;

    SDK_ASSERT(mutex);

    saved = OS_DisableInterrupts();
    currentThread = OS_GetCurrentThread();

    if (mutex->thread == currentThread && --mutex->count == 0) {
        OSi_DequeueItem(currentThread, mutex);
        mutex->thread = NULL;
        OS_WakeupThread(&mutex->queue);
    }

    (void)OS_RestoreInterrupts(saved);
}
