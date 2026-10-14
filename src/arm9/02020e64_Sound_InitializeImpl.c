/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_InitMutex Os_Mutex_Initialize
#define SND_CommandInit Sound_InitializeCommands
#define SND_AlarmInit Sound_InitializeAlarms
#define sSndInitialized SDK_data_021732ac
#define sSndMutex SDK_data_021732b0
#define SND_Init Sound_InitializeImpl
#include "SND_main.h"
#include "SND_command.h"
#include "SND_alarm.h"

#include "nitro/types.h"
#include "OS_mutex.h"
#include "code32.h"
extern s32 sSndInitialized;
extern struct OSMutex sSndMutex;
#pragma thumb off
void SND_Init(void) {
    if (sSndInitialized)
        return;
    sSndInitialized = 1;
    OS_InitMutex(&sSndMutex);
    SND_CommandInit();
    SND_AlarmInit();
}
