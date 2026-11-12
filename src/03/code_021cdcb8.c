#include "03/code_021cdcb8.h"
#include "03/code_021d1000.h"
#include "03/code_021d3000.h"
#include "03/unk_021da000.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0200eddc.h"
#include "gx_load2d.h"

#include "03/code_021d1440.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021d3488.h"

void LoadMenuPairScreenMap(u32 pathIndex) {
    gMenuPairScreenMap = LoadFile(BuildFilePathWithLanguage(gMenuPairScreenMapPaths[pathIndex]), NULL, 4);
    AddTask(1, AdvanceUploadMenuPairScreenMap, NULL, 0x78);
}

void AdvanceUploadMenuPairScreenMap(u32 task) {
    DC_FlushRange(gMenuPairScreenMap, (0x00000600u));
    GXS_LoadBG1Scr(gMenuPairScreenMap, 0, (0x00000600u));
    DeleteLoadedFile(gMenuPairScreenMap);
    RequestTaskRemoval(1, task);
}
