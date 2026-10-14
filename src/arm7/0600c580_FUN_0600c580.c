/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define AdjustRingPointer FUN_0600c580

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
void *AdjustRingPointer(void *p)
{
    if ((u32)p >= (MAC_MEM_BASE + MBUF_MAC_RX_END)) {
        p = (void *)((u32)p - (u32)wlMan->Work.Ofst.RxBuf.Size);
    }

    return p;
}
