/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts FUN_037faf70
#define OSi_EnqueueTail FUN_037f993c
#define OS_SleepThread FUN_037f9104
#define OS_RestoreInterrupts FUN_037faf84
#define OSi_ThreadInfo SDK_data_038076fc
#define OS_LockMutex FUN_037f9a0c
#include <nitro/types.h>
#include <nitro.h>
extern void OSi_EnqueueTail (OSThread * thread, OSMutex * mutex);
#pragma thumb off
void OS_LockMutex (OSMutex * mutex)
{
    OSIntrMode saved;
    OSThread * currentThread;
    OSThread * ownerThread;

    SDK_ASSERT(mutex);

    saved = OS_DisableInterrupts();
    currentThread = OS_GetCurrentThread();

    for (;;) {
        ownerThread = ((volatile OSMutex *)mutex)->thread;

        if (ownerThread == NULL) {
            mutex->thread = currentThread;
            mutex->count++;
            OSi_EnqueueTail(currentThread, mutex);
            break;
        } else if (ownerThread == currentThread)   {
            mutex->count++;
            break;
        } else {
            currentThread->mutex = mutex;
            OS_SleepThread(&mutex->queue);
            currentThread->mutex = NULL;
        }
    }

    (void)OS_RestoreInterrupts(saved);
}
