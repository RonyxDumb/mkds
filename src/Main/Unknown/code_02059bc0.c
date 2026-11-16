#include "Main/Unknown/code_02059bc0.h"

#include "Main/Unknown/code_0202a5a0.h"
#include "Main/System/Heap.h"
#include "fs_file.h"
#include "Main/Unknown/code_0202a000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_0205a000.h"
#include "Main/Unknown/code_0205a4e8.h"
#include "Main/Unknown/code_0205a534.h"
#include "Main/Unknown/code_0205a50c.h"
#include "Main/Unknown/code_0205a548.h"
#include "Main/Unknown/unk_00000000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_02180000.h"
#include "02/unk_02180500.h"
#include "code_02003be0.h"
#include "code_02004dc0.h"
#include "code_020176c0.h"
#include "frameheap.h"

static inline void func_0205a140_inline(s32 entryIndex, s32 overlayId, u32 startAddress, u32 endAddress) {
    OverlayLoaderEntry *entry;

    entry = &gOverlayData->mEntries[entryIndex];
    entry->mOverlayId = overlayId;
    entry->mStart = startAddress;
    entry->mEnd = endAddress;
    if (entry->mStart < gOverlayData->mLowestStart) {
        gOverlayData->mLowestStart = entry->mStart;
    }
    if (entry->mEnd > gOverlayData->mHighestEnd) {
        gOverlayData->mHighestEnd = entry->mEnd;
    }
}

void sub_205A4B0(Unk0217aa14_104_68 *a, s32 b) {
    s32 t;

    a->fieldE = 0;
    t = gStruct217AA14->field728;
    a->fieldC = 2;
    a->field0 = b;
    a->field8 = t + 0x78;
    a->field4 = 0x13;
}

void sub_205A350(void) {
    u8 i;
    Unk0217aa14_104_68 *p;
    s32 d;
    Unk0217aa14_104_20 *h;

    for (i = 0; i < 4; i++) {
        if (sub_205A50C(i) != 0) {
            p = &gStruct217AA14->field104[i].mUnk_68_view;
            h = sub_205A4E8(i, i);
            switch (p->fieldC) {
                case 0:
                    if (h->field0_12 == 2) {
                        sub_205A71C(i);
                        sub_205A4B0(p, h->field0_7);
                    }
                    break;
                case 2:
                    d = p->field8 - gStruct217AA14->field728;
                    if ((s32) p->fieldE < 100) {
                        sub_205A7DC(i, d, p->field0, 2);
                        p->fieldE = p->fieldE + 1;
                    } else if (d > 20) {
                        sub_205A7DC(i, d, p->field0, 2);
                    } else {
                        sub_205A7AC(i);
                        if (d <= 0) {
                            p->fieldC = 3;
                        }
                    }
                    break;
                case 3:
                    sub_205A534(p);
                    break;
                case 4:
                    if (h->field0_12 != 2) {
                        p->fieldC = 0;
                    }
                    break;
            }
        }
    }
}

s32 sub_205A310(s32 a) {
    BOOL r;
    Unk0217aa14_104 *e;

    e = &gStruct217AA14->field104[a];
    r = FALSE;
    if ((u16) (e->field74 + 0xffff) <= 1) {
        r = TRUE;
    }
    return r;
}

s32 sub_205A2AC(s32 a) {
    s32 r;
    BOOL f;

    r = 0x13;
    f = FALSE;
    if ((u16) (gStruct217AA14->field104[a].field74 + 0xffff) <= 1) {
        f = TRUE;
    }
    if (f == FALSE) {
        r = gStruct217AA14->field104[a].field68;
    }
    return r;
}

// Allocates the overlay record and fills the table of the three overlays and the address range they cover.
void overlay_init(void *heap) {
    gOverlayData = heap_alloc(heap, 0xb0);
    gOverlayData->mLowestStart = -1;
    gOverlayData->mHighestEnd = 0;
    func_0205a140_inline(0, (s32) SDK_OVERLAY_OV000_ID, (u32) OV000_TEXT_START, (u32) OV000_BSS_END);
    func_0205a140_inline(1, (s32) SDK_OVERLAY_OV001_ID, (u32) OV001_TEXT_START, (u32) OV001_BSS_END);
    func_0205a140_inline(2, (s32) SDK_OVERLAY_OV002_ID, (u32) OV002_CTOR_START, (u32) OV002_BSS_END);
    gOverlayData->mFrmHeap = NULL;
    gOverlayData->mExpHeap = NULL;
}

// Creates the frame heap in a fixed 0x50000-byte buffer.
void overlay_createFrmHeap(void) {
    gOverlayData->mFrmHeap = NNS_FndCreateFrmHeapEx(data_ov002_02180500, 0x50000, 0);
}

// Marks no overlay as current: index 4 is past the three table entries.
void overlay_reset(void) {
    gOverlayData->mCurrentOverlay = 4;
    gOverlayData->mLoadState = 0;
}

// Starts loading the overlay: nothing while a load runs; a loaded overlay is unloaded first.
void overlay_beginLoad(s32 overlay) {
    OverlayLoader *loader;
    s32 current;
    s32 state;

    loader = gOverlayData;
    current = loader->mCurrentOverlay;
    if (current == overlay) {
        return;
    }
    state = loader->mLoadState;
    switch (state) {
        case 0:
            FS_LoadOverlayInfo(&loader->mInfo, 0, loader->mEntries[overlay].mOverlayId);
            FS_InitFile(&gOverlayData->mFile);
            FS_LoadOverlayImageAsync(&gOverlayData->mInfo, &gOverlayData->mFile);
            gOverlayData->mLoadState = 1;
            gOverlayData->mCurrentOverlay = overlay;
            break;
        case 1:
            break;
        case 2:
            switch (state) {
                case 1:
                case 2:
                    if (FS_UnloadOverlay(0, loader->mEntries[current].mOverlayId) != 0) {
                        gOverlayData->mCurrentOverlay = 4;
                        gOverlayData->mLoadState = 0;
                        if (gOverlayData->mExpHeap != NULL) {
                            NNS_FndDestroyExpHeap(gOverlayData->mExpHeap);
                            gOverlayData->mExpHeap = NULL;
                        }
                    }
                    break;
            }
            FS_LoadOverlayInfo(&gOverlayData->mInfo, 0, gOverlayData->mEntries[overlay].mOverlayId);
            FS_InitFile(&gOverlayData->mFile);
            FS_LoadOverlayImageAsync(&gOverlayData->mInfo, &gOverlayData->mFile);
            gOverlayData->mLoadState = 1;
            gOverlayData->mCurrentOverlay = overlay;
            break;
        case 3:
            switch (state) {
                case 1:
                case 2:
                    if (FS_UnloadOverlay(0, loader->mEntries[current].mOverlayId) != 0) {
                        gOverlayData->mCurrentOverlay = 4;
                        gOverlayData->mLoadState = 0;
                        if (gOverlayData->mExpHeap != NULL) {
                            NNS_FndDestroyExpHeap(gOverlayData->mExpHeap);
                            gOverlayData->mExpHeap = NULL;
                        }
                    }
                    break;
            }
            FS_LoadOverlayInfo(&gOverlayData->mInfo, 0, gOverlayData->mEntries[overlay].mOverlayId);
            FS_InitFile(&gOverlayData->mFile);
            FS_LoadOverlayImageAsync(&gOverlayData->mInfo, &gOverlayData->mFile);
            gOverlayData->mLoadState = 1;
            gOverlayData->mCurrentOverlay = overlay;
            break;
    }
}

// Waits in a loop for the read to end, then starts the overlay and closes the file.
void overlay_finishLoad(void) {
    BOOL finished;
    s32 loadState;

    do {
        finished = FALSE;
        loadState = gOverlayData->mLoadState;
        if (loadState == 2) {
            finished = TRUE;
        } else if (loadState == 1) {
            if (((gOverlayData->mFile.mStat & 1) ? 1 : 0) == 0) {
                FS_StartOverlay(&gOverlayData->mInfo);
                FS_CloseFile(&gOverlayData->mFile);
                gOverlayData->mLoadState = 2;
                finished = TRUE;
            }
        }
    } while (finished == FALSE);
}

// Creates the expandable heap only while overlay 1 is the current one.
void overlay_createExpHeap(void) {
    if (gOverlayData->mCurrentOverlay != 1) {
        return;
    }
    gOverlayData->mExpHeap = NNS_FndCreateExpHeapEx(aHpxe_11, 0x20800, 1);
}

void overlay_destroyExpHeap(void) {
    if (gOverlayData->mExpHeap == NULL) {
        return;
    }
    NNS_FndDestroyExpHeap(gOverlayData->mExpHeap);
    gOverlayData->mExpHeap = NULL;
}

// Same finish as the wait loop without waiting: returns 1 when the overlay is loaded, else 0.
s32 overlay_tryFinishLoad(void) {
    enum { K0 } r;
    s32 state;
    OverlayLoader *loader;

    r = 0;
    loader = gOverlayData;
    state = loader->mLoadState;
    if (state == 2) {
        return 1;
    }
    if (state != 1) {
        return r;
    }
    if (loader->mFile.mStat & 1) {
        state = 1;
    } else {
        state = r;
    }
    if (state != 0) {
        return r;
    }
    FS_StartOverlay(&loader->mInfo);
    FS_CloseFile(&gOverlayData->mFile);
    gOverlayData->mLoadState = 2;
    return 1;
}

void overlay_unload(void) {
    if (gOverlayData->mLoadState != 1 && gOverlayData->mLoadState != 2) {
        return;
    }
    if (FS_UnloadOverlay(0, gOverlayData->mEntries[gOverlayData->mCurrentOverlay].mOverlayId) == 0) {
        return;
    }
    gOverlayData->mCurrentOverlay = 4;
    gOverlayData->mLoadState = 0;
    if (gOverlayData->mExpHeap != NULL) {
        NNS_FndDestroyExpHeap(gOverlayData->mExpHeap);
        gOverlayData->mExpHeap = NULL;
    }
}

// 1 when the address lies between the lowest start and the highest end of the three overlays.
u32 overlay_isAddressInOverlay(struct MapObjectKindDescriptor *address) {
    u32 inRange;

    inRange = 0;
    if ((u32) address >= gOverlayData->mLowestStart) {
        if ((u32) address <= gOverlayData->mHighestEnd) {
            inRange = 1;
        }
    }
    return inRange;
}

void ressc_init(void) {
    result_init(proc_getHeap(proc_getCurrent()));
}

void ressc_finalize(void) {
    u32 value12;
    result_finalize();
}

void ressc_vblank(void) {
    u32 value12;
    result_vblank();
}

void ressc_update(u32 arg0) {
    u32 value0 = arg0;
    u32 value12;
    result_update(value0);
}
