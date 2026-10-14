/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define TxqPri FUN_0601536c
#define SetParentTbttTxqTask FUN_0600da78

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
#include "WlIntrTask.h"
#include "WlOpe.h"

#pragma thumb off
void SetParentTbttTxqTask(void)
{
    LPHEAP_MAN pHeapMan = &wlMan->HeapMan;

    if ((*(vu16 *)MREG_DTIM_COUNT == 0) && (GetHeapBufCount(&pHeapMan->TxPri[QID_BROADCAST]) != 0)) {
        TxqOpen(TXQ_OPEN_TXQ2);
        TxqPri(QID_BROADCAST);
    } else {
        if ((wlMan->CamMan.PowerMgtMode & ~wlMan->CamMan.NotClass3) == 0) {
            TxqOpen(TXQ_OPEN_TXQ2);

            if (GetHeapBufCount(&pHeapMan->TxPri[QID_BROADCAST]) != 0) {
                TxqPri(QID_BROADCAST);
            }
        }

        TxqOpen(TXQ_OPEN_TXQ1 | TXQ_OPEN_TXQ0);
        if (GetHeapBufCount(&pHeapMan->TxPri[QID_MANCTRL]) != 0) {
            TxqPri(QID_MANCTRL);
        }
        if (GetHeapBufCount(&pHeapMan->TxPri[QID_DATA]) != 0) {
            TxqPri(QID_DATA);
        }
    }
}
