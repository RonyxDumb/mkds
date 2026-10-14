/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableIrqMask thunk_FUN_037f8850
#define OS_EnableIrqMask thunk_FUN_037f888c
#define DeleteTask FUN_06008a04

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
u32 DeleteTask(u32 nPriority)
{
    LPTASK_MAN pTaskMan = &wlMan->TaskMan;
    LPTASK_TBL pTaskTbl;
    u32 x, nTaskID, nOfstTaskID;

    x = OS_DisableIrqMask(OS_IE_WIRELESS | OS_IE_TIMER1);

    if ((nTaskID = pTaskMan->EnQ[nPriority]) != TASK_LAST) {
        pTaskTbl = pTaskMan->TaskTbl;
        nOfstTaskID = nTaskID;

        pTaskTbl[nOfstTaskID].Flag = TASK_FREE;

        if (pTaskTbl[nOfstTaskID].NextId == TASK_LAST) {
            pTaskMan->EnQ[nPriority] = TASK_LAST;
            pTaskMan->DeQ[nPriority] = TASK_LAST;
        } else {
            pTaskMan->EnQ[nPriority] = pTaskTbl[nOfstTaskID].NextId;
            pTaskTbl[nOfstTaskID].NextId = TASK_LAST;
        }
    }

    OS_EnableIrqMask(x);

    return nTaskID;
}
