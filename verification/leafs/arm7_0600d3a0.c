/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WlIntrTxErr FUN_0600d3a0

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
void WlIntrTxErr(void) __attribute__((never_inline))
{
    LPTXFRM_MAC pMFrm;
    u32 i;

#if (EMU_MACREG)
    *(vu16 *)MREG_ISR &= ~MISR_TXERR;
#else
    *(vu16 *)MREG_ISR = MISR_TXERR;
#endif

    if (wlMan->Config.Diversity != WL_CMDLABEL_DIVERSITY_OFF) {
        if ((*(vu16 *)MREG_SIGNAL_STATE & (SIGNAL_STATE_CCA || SIGNAL_STATE_TXPE)) == 0) {
            WChangeAntenna();
        }
    }

    if (wlMan->WlOperation & MAC_BUG_WEP) {
        LPWORK_PARAM pWork = &wlMan->Work;
        LPTX_CTRL pTxCtrl = &wlMan->TxCtrl;

        for (i = 0; i < 3; i++) {
            if (pTxCtrl->Txq[i].Busy) {
                pMFrm = (LPTXFRM_MAC)pTxCtrl->Txq[i].pMacFrm;

                if ((pMFrm->Dot11Header.FrameCtrl.Data & B_FC_WEP) && (LoadLow(&pMFrm->MacHeader.Tx.rsv_RetryCount) != 0)) {
                    u16 *pIcv = (u16 *)(((u32)&pMFrm->Dot11Header + pMFrm->MacHeader.Tx.MPDU - 8 + 1) & 0xFFFFFFFE);

                    if ((pIcv[0] == 0) && (pIcv[1] == 0)) {
                        pMFrm->MacHeader.Tx.rsv_RetryCount = 0;

                        *(vu16 *)MREG_WEP_CONFIG = 0x0000;
                        *(vu16 *)MREG_WEP_CONFIG = 0x8000;

                        pWork->WepErrCount++;

                        DbgSetDDO(DDO_WL_MAC, DDO_WL_MAC_WEP_ERR);
                        DbgWlPutchar(B_WL_DBG_ERRMSG, 'E');
                        DbgClrDDO(DDO_WL_MAC, DDO_WL_MAC_WEP_ERR);
                    }
                }
            }
        }
    }

    DbgWlPutchar(B_WL_DBG_INT, (WL_DBG_INT_TXERR));
}
