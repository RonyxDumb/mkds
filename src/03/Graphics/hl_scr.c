#include "03/Graphics/hl_scr.h"
#include "03/code_021bf000.h"
#include "03/Net/essid_wcm.h"
#include "03/code_021cd2e0.h"
#include "03/System/dwc_archive.h"
#include "03/unk_021d5000.h"
#include "03/Menu/menu_pair_loading.h"

#include "03/System/tasks.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0200eddc.h"
#include "gx_load2d.h"
#include "03/code_021d1000.h"
#include "code_0214d018.h"
#include "03/System/exp_heap.h"
#include "03/unk_021d67d8.h"

void ReleaseHlScr(void) {
    FreeExpHeapBlockAndClearPointer(&gHlScr);
}

void LoadHlScr(int b) {
    void *a;

    a = LoadFile(BuildFilePathWithLanguage(gHlNscNames[b]), NULL, 4);
    MIi_CpuCopyFast(a, gHlScr, 0xc0);
    DeleteLoadedFile(a);
    AddTask(1, UploadHlScr, NULL, 0x78);
}

void LoadHlSetScr(void) {
    u32 value0;
    value0 = GetApWorkCopy()->mEntryIndex;
    value0 = (value0) + (5u);
    LoadHlScr(value0);
}

void LoadHlListScr(void) {
    u32 value0;
    value0 = GetApWorkCopy()->mEntryIndex;
    value0 = (value0) + (2u);
    LoadHlScr(value0);
}

void UploadHlScr(u32 a) {
    DC_FlushRange(gHlScr, 0xc0);
    GX_LoadBG1Scr(gHlScr, 0, 0xc0);
    RequestTaskRemoval(1, a);
}
