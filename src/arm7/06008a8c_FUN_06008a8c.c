/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableIrqMask thunk_FUN_037f8850
#define OS_EnableIrqMask thunk_FUN_037f888c
#define OS_SendMessage thunk_FUN_037f9854
#define AddTask FUN_06008a8c

#include "WlSys.h"
#include "WlLib.h"

#include "TaskMan.h"
#include "Param.h"
#include "TxCtrl.h"
#include "RxCtrl.h"
#include "CAM.h"
#include "WlCmdIf.h"
#include "WlIntrTask.h"

#include "MAC.h"

#pragma thumb off
void AddTask(s32 nPriority, u32 nTaskID)
{
    LPTASK_MAN pTaskMan = &wlMan->TaskMan;
    LPTASK_TBL pTaskTbl;
    u32 x;

    ASSERT(nPriority >= TASK_MAX_PRIORITY);

    pTaskTbl = pTaskMan->TaskTbl;

    x = OS_DisableIrqMask(OS_IE_WIRELESS | OS_IE_TIMER1);

    if (pTaskTbl[nTaskID].Flag == TASK_FREE) {
        pTaskTbl[nTaskID].Flag = TASK_RESERVED;

        pTaskTbl[nTaskID].NextId = TASK_LAST;

        if (pTaskMan->DeQ[nPriority] == TASK_LAST) {
            pTaskMan->EnQ[nPriority] = (u16)nTaskID;
        } else {
            pTaskMan->TaskTbl[pTaskMan->DeQ[nPriority]].NextId = (u16)nTaskID;
        }

        pTaskMan->DeQ[nPriority] = (u16)nTaskID;

        if (nPriority < pTaskMan->NextPri) {
            pTaskMan->NextPri = (u16)nPriority;
        }
    }

    OS_EnableIrqMask(x);

    if ((nPriority != TASK_LOW_PRIORITY) && (pTaskMan->TaskPri == TASK_LOW_PRIORITY)) {
        OS_SendMessage(wlMan->pRecvMsgQueue, NULL, OS_MESSAGE_NOBLOCK);
    }
}
