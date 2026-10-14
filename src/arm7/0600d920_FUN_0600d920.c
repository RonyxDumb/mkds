/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WlIntrStartTx FUN_0600c95c
#define WlIntrStartRx FUN_0600c6e8
#define WlIntrPreTbtt FUN_0600d894
#define WlIntrTbtt FUN_0600d598
#define WlIntrActEnd FUN_0600d51c
#define WlIntrRfWakeup FUN_0600d508
#define WlIntrTxErr FUN_0600d3a0
#define WlIntrRxCntup FUN_0600d1dc
#define WlIntrRxEnd FUN_0600cb28
#define WlIntrCntOvf FUN_0600d4cc
#define WlIntrTxEnd FUN_0600cf6c
#define WlIntrMpEnd FUN_0600ca18
#define WlIntr FUN_0600d920

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
extern void WlIntrStartTx(void) __attribute__((never_inline));
extern void WlIntrStartRx(void) __attribute__((never_inline));
extern void WlIntrPreTbtt(void) __attribute__((never_inline));
extern void WlIntrTbtt(void) __attribute__((never_inline));
extern void WlIntrActEnd(void) __attribute__((never_inline));
extern void WlIntrRfWakeup(void) __attribute__((never_inline));
extern void WlIntrTxErr(void) __attribute__((never_inline));
extern void WlIntrRxCntup(void) __attribute__((never_inline));
extern void WlIntrRxEnd(void) __attribute__((never_inline));
extern void WlIntrCntOvf(void) __attribute__((never_inline));
extern void WlIntrTxEnd(void) __attribute__((never_inline));
extern void WlIntrMpEnd(u32 bMacBugPatch);
#pragma thumb off
void WlIntr(void)
{
    u32 isr;

#ifdef SDK_TEG
    if (wlMan->bUnLocked) {
        OS_LockCartridge(wlMan->lockID);
    }
#endif

    while (1) {
        isr = *(vu16 *)MREG_ISR & *(vu16 *)MREG_IMR;
        if (isr == 0) {
            break;
        }

        if (isr & MISR_START_TX) {
            WlIntrStartTx();
        }
        if (isr & MISR_START_RX) {
            WlIntrStartRx();
        }
        if (isr & MISR_PRE_TBTT) {
            WlIntrPreTbtt();
        }
        if (isr & MISR_TBTT) {
            WlIntrTbtt();
        }
        if (isr & MISR_ACTEND) {
            WlIntrActEnd();
        }

        if (isr & MISR_RF_WAKEUP) {
            WlIntrRfWakeup();
        }
        if (isr & MISR_TXERR) {
            WlIntrTxErr();
        }
        if (isr & MISR_RXCNTUP) {
            WlIntrRxCntup();
        }
        if (isr & MISR_RXEND) {
            WlIntrRxEnd();
        }
        if (isr & MISR_CNT_OVF) {
            WlIntrCntOvf();
        }
        if (isr & MISR_TXEND) {
            WlIntrTxEnd();
        }
        if (isr & MISR_MPEND) {
            WlIntrMpEnd(1);
        }
    }

    DbgClrDDO(DDO_WL_TASK, DDO_WL_TASK_INT_WL);

#ifdef SDK_TEG
    if (wlMan->bUnLocked) {
        OS_UnLockCartridge(wlMan->lockID);
    }
#endif

    OS_SetIrqCheckFlag(OS_IE_WIRELESS);
}
