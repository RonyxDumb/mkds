/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_AllocFromHeap thunk_FUN_037fa04c
#define AddHeapBuf FUN_06008f34
#define AllocateHeapBuf FUN_06009138

#include "WlSys.h"

#include "WlLib.h"
#include "BufMan.h"
#include "TaskMan.h"
#include "Param.h"
extern u32 AddHeapBuf(LPHEAPBUF_MAN pBufMan, void *pBuf);
#pragma thumb off
void *AllocateHeapBuf(LPHEAPBUF_MAN pBufMan, u32 Length)
{
    u32 AllocPages;
    LPHEAPBUF_HEADER pAllocBuf;
    LPHEAP_MAN pHeapMan = &wlMan->HeapMan;

    if (Length == 0) {
        return (void *)HEAPBUF_NOT_ENOUGH_MEMORY;
    }

    AllocPages = Length + sizeof(HEAPBUF_HEADER);

    switch (pHeapMan->HeapInfo.heapType) {
    case WL_HEAP_OS:
        pAllocBuf = (LPHEAPBUF_HEADER)OS_AllocFromHeap(pHeapMan->HeapInfo.func.os.id, pHeapMan->HeapInfo.func.os.heapHandle, AllocPages);
        break;

    case WL_HEAP_EXT:
        pAllocBuf = (LPHEAPBUF_HEADER)(*pHeapMan->HeapInfo.func.ext.alloc)(AllocPages);
        break;
    }

    if (pAllocBuf != NULL) {
        pAllocBuf->BufID = HEAPBUF_ID;
        pAllocBuf->Flag = HEAPBUF_NOUSE;

        AddHeapBuf(pBufMan, pAllocBuf);

        return (void *)pAllocBuf;
    }

    return NULL;
}
