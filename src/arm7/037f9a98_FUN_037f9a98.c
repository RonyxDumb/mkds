/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_InitMutex FUN_037f9a98
#include <nitro/types.h>
#include <nitro.h>

#pragma thumb off
void OS_InitMutex (OSMutex * mutex)
{
    SDK_ASSERT(mutex);

    OS_InitThreadQueue(&mutex->queue);

    mutex->thread = NULL;
    mutex->count = 0;
}
