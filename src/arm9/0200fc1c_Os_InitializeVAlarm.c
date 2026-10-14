/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define OS_DisableIrqMask Os_DisableIrqHandler
#define OSi_UseVAlarm SDK_data_02170268
#define OSi_VAlarmQueue SDK_data_02170274
#define OSi_VFrameCount SDK_data_02170270
#define OSi_PreviousVCount SDK_data_0217026c
#define OS_InitVAlarm Os_InitializeVAlarm
#include "OS_valarm.h"
#include "OS_interrupt.h"
#include "code32.h"

static struct OSiVAlarmQueue
{
    OSVAlarm *head;
    OSVAlarm *tail;
} OSi_VAlarmQueue;

static u16 OSi_UseVAlarm = FALSE;

static s32 OSi_VFrameCount;
static s32 OSi_PreviousVCount;

void OS_InitVAlarm(void)
{
    if (!OSi_UseVAlarm)
    {
        OSi_UseVAlarm = TRUE;

        OSi_VAlarmQueue.head = NULL;
        OSi_VAlarmQueue.tail = NULL;

        (void)OS_DisableIrqMask(OS_IE_V_COUNT);

        OSi_VFrameCount = 0;
        OSi_PreviousVCount = 0;
    }
}
