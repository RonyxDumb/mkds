/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts FUN_037faf70
#define OS_RestoreInterrupts FUN_037faf84
#define OS_SleepThread FUN_037f9104
#define OS_ReadMessage FUN_037f973c
#include <nitro/os.h>
#include <nitro/os/common/message.h>

#pragma thumb off
BOOL OS_ReadMessage (OSMessageQueue * mq, OSMessage * msg, s32 flags)
{
    OSIntrMode enabled;

    enabled = OS_DisableInterrupts();

    while (mq->usedCount == 0) {
        if (!(flags & OS_MESSAGE_BLOCK)) {
            (void)OS_RestoreInterrupts(enabled);
            return FALSE;
        } else {
            OS_SleepThread(&mq->queueReceive);
        }
    }

    if (msg != NULL) {
        *msg = mq->msgArray[mq->firstIndex];
    }

    (void)OS_RestoreInterrupts(enabled);
    return TRUE;
}
