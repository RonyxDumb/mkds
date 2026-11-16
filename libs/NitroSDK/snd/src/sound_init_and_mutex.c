#include "sound_init_and_mutex.h"

#include "thread_mutex_types.h"
#include "mutex_init_decl.h"
#include "sound_command_queue.h"
#include "sound_shared_work_access.h"

u32 g_SoundInnerInitialized;
OSMutex g_SoundMutex;

// Sets up the sound library once: the mutex, the command queue and the alarm table.
void Sound_InitializeImpl(void) {
    if (g_SoundInnerInitialized != 0) {
        return;
    }
    g_SoundInnerInitialized = 1;
    Os_Mutex_Initialize(&g_SoundMutex);
    Sound_InitializeCommands();
    Sound_InitializeAlarms();
}

// Takes the mutex that guards the shared sound data.
void Sound_LockMutex(void) {
    Os_Mutex_Lock(&g_SoundMutex);
}

// Releases the mutex that guards the shared sound data.
void Sound_UnlockMutex(void) {
    Os_Mutex_Unlock(&g_SoundMutex);
}
