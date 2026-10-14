/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SendMessageToWmDirect FUN_0600f19c
#define AddTask FUN_06008a8c
#define IssueMlmeConfirm FUN_0600fafc

#include "WlSys.h"
#include "TaskMan.h"

#include "WlLib.h"
#include "Param.h"
#include "WlNic.h"
#include "WlCmdIf.h"
#include "MLME.h"
#include "MAC.h"
#include "Flash.h"

#include "TxCtrl.h"

#pragma thumb off
void IssueMlmeConfirm(void)
{
    LPHEAP_MAN pHeapMan = &wlMan->HeapMan;
    LPCMDIF_MAN pCmdIf = &wlMan->CmdIf;

    pCmdIf->Busy &= ~CMDBUSY_MLME;

    SendMessageToWmDirect(&pHeapMan->RequestCmd, pCmdIf->pCmd);

    if (GetHeapBufCount(&pHeapMan->RequestCmd) != 0) {
        AddTask(TASK_NORMAL_PRIORITY, REQUEST_CMD_TASK_ID);
    }
}
