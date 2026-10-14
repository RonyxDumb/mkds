/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define OS_RestoreInterrupts Os_RestoreIrq
#define OS_SleepThread Os_Thread_Sleep
#define OS_ReadMessage func_0200e904
#include "OS_message.h"
#include "OS_system.h"
#include "OS_thread.h"
#include "code32.h"

BOOL OS_ReadMessage(OSMessageQueue *mq, OSMessage *msg, s32 flags)
{
    OSIntrMode enabled = OS_DisableInterrupts();

    while (mq->usedCount == 0)
    {
        if (!(flags & OS_MESSAGE_BLOCK))
        {
            (void)OS_RestoreInterrupts(enabled);
            return FALSE;
        }
        else
        {
            OS_SleepThread(&mq->queueReceive);
        }
    }

    if (msg != NULL)
    {
        *msg = mq->msgArray[mq->firstIndex];
    }

    (void)OS_RestoreInterrupts(enabled);
    return TRUE;
}
