#include "snd_main.h"

#include "thread_mutex_types.h"
#include "mutex_init_decl.h"
#include "snd_command.h"
#include "snd_work.h"

u32 sSndInitialized;
OSMutex sSndMutex;

// Sets up the sound library once: the mutex, the command queue and the alarm table.
void SND_Init(void) {
    if (sSndInitialized != 0) {
        return;
    }
    sSndInitialized = 1;
    OS_InitMutex(&sSndMutex);
    SND_CommandInit();
    SND_AlarmInit();
}

// Takes the mutex that guards the shared sound data.
void SNDi_LockMutex(void) {
    OS_LockMutex(&sSndMutex);
}

// Releases the mutex that guards the shared sound data.
void SNDi_UnlockMutex(void) {
    OS_UnlockMutex(&sSndMutex);
}
