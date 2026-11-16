#include "Main/Unknown/code_0205dc84.h"
#include "Main/Unknown/code_020365ac.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_02036588.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02001000.h"
#include "Main/Unknown/code_02039000.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0212030c.h"
#include "Main/Unknown/code_02108ed8.h"
#include "Main/Unknown/code_02108ec4.h"
#include "03/code_021c2000.h"
#include "03/code_021c209c.h"
#include "00/code_021a3000.h"
#include "00/code_021a3760.h"
#include "01/code_021956dc.h"
#include "code_02004dc0.h"
#include "code_0200c914.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200fc8c.h"
#include "code_02148950.h"
#include "gx.h"
#include "code_021458c4.h"
#include "Main/Unknown/unk_00000000.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "registers.h"

#pragma opt_loop_invariants off

static inline void func_0205dee0_inline(void *c, void *overlayId) {
    u8 languageIndex;
    u32 f;
    if (FS_LoadOverlay(0, (u32) overlayId) != 0) {
        OS_SetIrqFunction(1, NULL);
        OS_DisableIrqMask(1);
        reg_OS_IME;
        reg_OS_IME = 0;
        OS_DisableInterrupts();
        GX_VBlankIntr(0);
        func_ov000_021a397c(2);
        f = 1;
        languageIndex = gSystemData->mLanguageIndex;
        if (languageIndex < 6) {
            f = scproc_sLanguageToDwcUtil[languageIndex];
        }
#ifdef version_EUR
        func_ov003_021c2494(c, f, 0);
#else
        func_ov003_021c2494(c, f, 0x20);
#endif
        mkds_restoreIrqs();
        FS_UnloadOverlay(0, (u32) overlayId);
    }
}

void scproc_runWifiUtil(void) {
    void *expHeapFromMaxFree;
    void *c;
    void *a;
    a = proc_getHeap(proc_getCurrent());
    bgwkr_waitForCompletion();
    if (gSaveCore->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (((Unk027ffc40 *) 0x027ffc40)->field0 != 2 && scproc_sSceneProc->mSndHeapsBuffer != NULL) {
        ReleaseSndHeaps();
        heap_free(a, scproc_sSceneProc->mSndHeapsBuffer);
        scproc_sSceneProc->mSndHeapsBuffer = NULL;
    }
    func_02108ed8();
    expHeapFromMaxFree = heap_createSubExpHeap(a);
    c = heap_allocEx(expHeapFromMaxFree, 0x40000, 0x20);
    func_0205dee0_inline(c, SDK_OVERLAY_OV003_ID);
    heap_destroySubHeap(expHeapFromMaxFree);
    GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, 0x10);
    GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, 0x10);
    dc_enableDisplay();
    sound_setSdatAsCurrent();
    a = heap_alloc(a, sound_getSomeSize2(1));
    CreateSndHeaps(1, (u32) a);
    scproc_sSceneProc->mSndHeapsBuffer = a;
}

static inline BOOL func_0205dd38_inline(void) {
    if (scproc_sSceneProc->field4 == 3 || scproc_sSceneProc->field4 == scproc_sSceneProc->field0) {
        return TRUE;
    }
    return FALSE;
}

s32 scproc_sceneProcMain(s16 *sceneNumber) {
    HeapCall heapCall;
    void *heap;
    scproc_overlay_205E0B0();
    while (func_0205dd38_inline()) {
        scproc_sSceneProc->field4 = 3;
        scproc_sSceneManager[0] = scproc_sSceneManager[1];
        scproc_sSceneManager[1] = *sceneNumber;
        scproc_sSceneManager[2] = -1;
        proc_init(&heapCall, scproc_sSceneTable[*sceneNumber]);
        proc_run(&heapCall, (u32) scproc_sSceneManager);
        if (scproc_sSceneManager[2] != -1) {
            *sceneNumber = scproc_sSceneManager[2];
        } else {
            *sceneNumber = 9;
        }
        switch (gSystemData->field20) {
            case 0:
            case 1:
            case 2:
                scproc_sSceneProc->field4 = 0;
                break;
            case 3:
                scproc_sSceneProc->field4 = 1;
                break;
            case 4:
                scproc_runWifiUtil();
                gSystemData->field20 = 3;
                break;
        }
    }
    heap = proc_getHeap(proc_getCurrent());
    if (((Unk027ffc40 *) 0x027ffc40)->field0 != 2 && scproc_sSceneProc->mSndHeapsBuffer != NULL) {
        ReleaseSndHeaps();
        heap_free(heap, scproc_sSceneProc->mSndHeapsBuffer);
        scproc_sSceneProc->mSndHeapsBuffer = NULL;
    }
    switch (scproc_sSceneProc->field0) {
        case 0:
            func_02054330();
            break;
        case 1:
            DeleteWiFiSessionHeap();
            break;
    }
    return 0;
}

void scproc_run(void) {
    HeapCall heapCall;
    scproc_sSceneProc->mSceneNumber = 9;
    scproc_sSceneProc->field0 = 0;
    if (((Unk027ffc40 *) 0x027ffc40)->field0 == 2) {
        gSystemData->field20 = 2;
        gStruct217B488->field74 = 0;
        scproc_sSceneProc->mSceneNumber = 6;
    }
    do {
        scproc_sSceneProc->field4 = 3;
        proc_init(&heapCall, (u32) scproc_sceneProcMain);
        proc_run(&heapCall, (u32) &scproc_sSceneProc->mSceneNumber);
        scproc_sSceneProc->field0 = scproc_sSceneProc->field4;
    } while (1);
}
