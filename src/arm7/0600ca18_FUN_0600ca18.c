/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SetupUsTimeOut FUN_06009860
#define AddTask FUN_06008a8c
#define MacBugTxMp SDK_data_0600c5a8
#define WlIntrMpEnd FUN_0600ca18

#include "WlSys.h"
#include "TaskMan.h"

#include "WlLib.h"
#include "MA.h"
#include "TxCtrl.h"
#include "RxCtrl.h"
#include "MAC.h"
#include "WlIntr.h"
#include "Compati.h"
#include "MA.h"
#include "WlOpe.h"
extern void MacBugTxMp(void *arg);
#pragma thumb off
void WlIntrMpEnd(u32 bMacBugPatch)
{
    LPTX_CTRL pTxCtrl = &wlMan->TxCtrl;
    u32 cnt;

#if (EMU_MACREG)
    *(vu16 *)MREG_ISR &= ~MISR_MPEND;
#else
    *(vu16 *)MREG_ISR = MISR_MPEND;
#endif

    DbgWlPutchar(B_WL_DBG_INT | B_WL_DBG_MP, (WL_DBG_INT_MPEND));

    if (pTxCtrl->Mp.Busy == FALSE) {
        DbgPuts("Mp end err\r");
        return;
    }

    DbgSetDDO(DDO_WL_INT, DDO_WL_INT_MPEND);

    if (wlMan->WlOperation & MAC_BUG_TXMP_AFTER_MPEND) {
        if (bMacBugPatch) {
            u16 pri = *(vu16 *)MREG_TXQ_CURR;
            u16 state = *(vu16 *)MREG_MAC_STATE;

            if ((state == MAC_STATE_TX) || (state == MAC_STATE_WAIT)) {
                if (pri == 0) {
                    u16 tm, map;

                    DbgSetDDO(DDO_WL_MAC, DDO_WL_MAC_MPEND_ERR);
                    map = pTxCtrl->Mp.pMacFrm->MacHeader.Tx.Status2;
                    cnt = 0;
                    while (map != 0) {
                        cnt += (map & 1);
                        map >>= 1;
                    }
                    tm = cnt * (10 + *(u16 *)&pTxCtrl->Mp.pMacFrm->Body[0]) + 96 + (pTxCtrl->Mp.pMacFrm->MacHeader.Tx.MPDU) * TIME_BYTE_2M + 96;
                    SetupUsTimeOut(tm, MacBugTxMp);
                    DbgClrDDO(DDO_WL_MAC, DDO_WL_MAC_MPEND_ERR);
                    DbgWlPrint(B_WL_DBG_ERRMSG, "MpEnd err(%u:%u)\r\n", tm, bMacBugPatch);

                    wlMan->Work.MpEndErrCount++;
                    return;
                }
            }
        }
    }

    DbgClrDDO(DDO_WL_PS, DDO_WL_PS_MPING);
    DbgClrDDO(DDO_WL_MAC, DDO_WL_MAC_MPING | DDO_WL_MAC_MP_RESUME);
    DbgClrDDO(DDO_WL_MP, DDO_WL_MP_MPING);

    AddTask(TASK_CRITICAL_PRIORITY, INTR_MPEND_TASK_ID);

    DbgClrDDO(DDO_WL_INT, DDO_WL_INT_MPEND);
}
