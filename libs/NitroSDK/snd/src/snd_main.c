#include "snd_main.h"

#include "code_0200e77c.h"
#include "code_0200edc0.h"
#include "snd_command.h"
#include "snd_work.h"

u32 g_SoundInnerInitialized;
OSMutex g_SoundMutex;

// Sets up the sound library once: the mutex, the command queue and the alarm table.
void SND_Init(void) {
    if (g_SoundInnerInitialized != 0) {
        return;
    }
    g_SoundInnerInitialized = 1;
    OS_InitMutex(&g_SoundMutex);
    SND_CommandInit();
    SND_AlarmInit();
}

// Takes the mutex that guards the shared sound data.
void SNDi_LockMutex(void) {
    OS_LockMutex(&g_SoundMutex);
}

// Releases the mutex that guards the shared sound data.
void SNDi_UnlockMutex(void) {
    OS_UnlockMutex(&g_SoundMutex);
}
