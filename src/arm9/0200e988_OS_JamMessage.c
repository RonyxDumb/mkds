/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define OS_RestoreInterrupts Os_RestoreIrq
#define OS_SleepThread Os_Thread_Sleep
#define OS_WakeupThread Os_Thread_WakeUp
#include "OS_message.h"
#include "OS_system.h"
#include "OS_thread.h"
#include "code32.h"

BOOL OS_JamMessage(OSMessageQueue *mq, OSMessage msg, s32 flags)
{
    OSIntrMode enabled = OS_DisableInterrupts();

    while (mq->msgCount <= mq->usedCount)
    {
        if (!(flags & OS_MESSAGE_BLOCK))
        {
            (void)OS_RestoreInterrupts(enabled);
            return FALSE;
        }
        else
        {
            OS_SleepThread(&mq->queueSend);
        }
    }

    mq->firstIndex = (mq->firstIndex + mq->msgCount - 1) % mq->msgCount;
    mq->msgArray[mq->firstIndex] = msg;
    mq->usedCount++;

    OS_WakeupThread(&mq->queueReceive);

    (void)OS_RestoreInterrupts(enabled);
    return TRUE;
}
