/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MultiPollRevicedClearSeq FUN_0600c514

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

#pragma thumb off
void MultiPollRevicedClearSeq(void)
{
    LPTX_CTRL pTxCtrl = &wlMan->TxCtrl;

    if (pTxCtrl->BkKeyOut != 0xFFFF) {
        u16 bkKeyIn;

        bkKeyIn = *(vu16 *)MREG_KEYIN_ADRS;
        *(vu16 *)MREG_KEYIN_ADRS = pTxCtrl->BkKeyOut;
        *(vu16 *)MREG_MDP_CONFIG |= 0x0080;
        *(vu16 *)MREG_KEYIN_ADRS = bkKeyIn;

        pTxCtrl->BkKeyOut = 0xFFFF;

        DbgClrDDO(DDO_WL_MACBUG_NOTPOLL, DDO_WL_MACBUG_NOTPOLL_RESET);
    }
}
