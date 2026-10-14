/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define GetHeapBufNextAdrs FUN_06008e48
#define ReleaseHeapBuf FUN_060090b4
#define ReleaseAllHeapBuf FUN_06008c98

#include "WlSys.h"

#include "WlLib.h"
#include "BufMan.h"
#include "TaskMan.h"
#include "Param.h"
extern void *GetHeapBufNextAdrs(void *pBuf);
extern u32 ReleaseHeapBuf(LPHEAPBUF_MAN pBufMan, void *pBuf);
#pragma thumb off
void ReleaseAllHeapBuf(LPHEAPBUF_MAN pHeapBufMan)
{
    u32 *pNext;
    u32 *pBuf = (u32 *)GetHeapBufHeadAdrs(pHeapBufMan);

    if (pHeapBufMan->Count != 0) {
        while ((u32)pBuf != HEAPBUF_HEAD_NONE) {
            pNext = (u32 *)GetHeapBufNextAdrs(pBuf);
            ReleaseHeapBuf(pHeapBufMan, pBuf);
            pBuf = pNext;
        }
    }
}
