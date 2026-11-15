#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Graphics/oam_upload.h"
#include "arena_cache_init.h"
#include "vram_load_2d_graphics.h"

#pragma thumb on

void UploadOamLists(void *mainOamList, void *subOamList) {
    if (mainOamList != NULL) {
        DC_FlushRange(mainOamList, 0x00000400u);
        GX_LoadOAM(mainOamList, 0, 0x00000400u);
    }
    if (subOamList != NULL) {
        DC_FlushRange(subOamList, 0x00000400u);
        GXS_LoadOAM(subOamList, 0, 0x00000400u);
    }
}

u16 GetOamMatrixCount(const RaceHudOamBuffer *oamList) {
    return oamList->mMatrixCount;
}

#pragma thumb off
