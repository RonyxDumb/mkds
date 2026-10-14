/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define OS_SleepThread Os_Thread_Sleep
#define OS_RestoreInterrupts Os_RestoreIrq
#define cardi_common SDK_data_0217fa40
#define CARDi_TaskThread Card_ContextThreadMain
#include "CARD_request.h"
#include "OS_cache.h"
#include "OS_system.h"
#include "OS_thread.h"
#include "code32.h"
extern CARDiCommon cardi_common;
#pragma thumb off
void CARDi_TaskThread(void *arg)
{
#pragma unused (arg)
    CARDiCommon *const p = &cardi_common;

    while (TRUE)
    {
        OSIntrMode bak_psr = OS_DisableInterrupts();
        while ((p->flag & CARD_STAT_TASK) == 0)
        {
            p->cur_th = p->thread;
            OS_SleepThread(NULL);
        }
        (void)OS_RestoreInterrupts(bak_psr);
        (*p->task_func)(p);
    }
}
