/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_InitMessageQueue FUN_037f98e8
#include <nitro/os.h>
#include <nitro/os/common/message.h>

#pragma thumb off
void OS_InitMessageQueue (OSMessageQueue * mq, OSMessage * msgArray, s32 msgCount)
{
    OS_InitThreadQueue(&mq->queueSend);
    OS_InitThreadQueue(&mq->queueReceive);

    mq->msgArray = msgArray;
    mq->msgCount = msgCount;
    mq->firstIndex = 0;
    mq->usedCount = 0;
}
