#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Graphics/oam_upload.h"
#include "arena_cache_init.h"
#include "vram_load_2d_graphics.h"

#pragma thumb on

void CopyOamBuffersToMemory_from_thumb(void *mainOamList, void *subOamList) {
    if (mainOamList != NULL) {
        Arm_FlushRange(mainOamList, 0x00000400u);
        CopyToOamA(mainOamList, 0, 0x00000400u);
    }
    if (subOamList != NULL) {
        Arm_FlushRange(subOamList, 0x00000400u);
        CopyToOamB(subOamList, 0, 0x00000400u);
    }
}

u16 GetOamMatrixCount(const RaceHudOamBuffer *oamList) {
    return oamList->mMatrixCount;
}

#pragma thumb off
