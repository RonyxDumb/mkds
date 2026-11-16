#include "Main/Menu/cup_picture_load.h"
#include "Main/System/heap_call.h"
#include "Main/System/heap.h"
#include "Main/System/thread_function_queue_run.h"
#include "Main/Race/race_start_battle.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/System/archive_slots.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "print_memory_multibyte_write.h"
#include "Main/Menu/menu_screen_callbacks.h"
#include "Main/Menu/cup_picture.h"

struct CupPicture *g_GlobalB4A4;

u32 GetActiveExecutionContextHeapHandle_0(void) {
    u32 heap;
    heap = (u32) GetActiveExecutionContext();
    heap = (u32) ExecutionContext_GetHeapHandle((void *) heap);
    return heap;
}

#pragma thumb on

void InitializeGlobalB4A4_from_thumb(void) {
    int result;
    CupPicture *cupPicture;
    u32 heap;
    result = j_IsDwc_1();
    if (result == 0) {
        heap = GetActiveExecutionContextHeapHandle_0();
        cupPicture = Mem_AllocateHeap((void *) heap, (0x0000185cu));
        g_GlobalB4A4 = cupPicture;
        cupPicture->mCupPictureIndex = 0;
        TrySetCupPictureIndexAndQueueLoads(0x14);
    }
}

#pragma thumb off

#pragma opt_propagation off

#pragma thumb on
void ResetGlobalB4A4_from_thumb(void) {
    g_GlobalB4A4 = NULL;
}

void LoadCupPictureNclr(void) {
    char buf[0x100];
    s32 pictureIndex;
    s32 nitroOrRetro;
    s32 pictureNumber;

    pictureIndex = g_GlobalB4A4->mCupPictureIndex;
    nitroOrRetro = gCupPictureNitroOrRetroTable[pictureIndex * 2];
    pictureNumber = gCupPictureNumberTable[pictureIndex * 2];
    _snprintf(buf, 0x100, "%s%s%02d%s", gCupPicturePrefix, nitroOrRetro == 0 ? gCupPictureNitro : gCupPictureRetro,
             pictureNumber, "_m_b.NCLR");
    OpenReadEntireFileBuffer_from_thumb(buf, g_GlobalB4A4->mCupPictureNclrFile, 0x228);
    Gfx_ReadPalette(&g_GlobalB4A4->mCupPictureNclr, g_GlobalB4A4->mCupPictureNclrFile);
}

void LoadCupPictureNcgr(void) {
    char buf[0x100];
    s32 pictureIndex;
    s32 nitroOrRetro;
    s32 pictureNumber;

    pictureIndex = g_GlobalB4A4->mCupPictureIndex;
    nitroOrRetro = gCupPictureNitroOrRetroTable[pictureIndex * 2];
    pictureNumber = gCupPictureNumberTable[pictureIndex * 2];
    _snprintf(buf, 0x100, "%s%s%02d%s", gCupPicturePrefix, nitroOrRetro == 0 ? gCupPictureNitro : gCupPictureRetro,
             pictureNumber, "_m_b.NCGR");
    OpenReadEntireFileBuffer_from_thumb(buf, g_GlobalB4A4->mCupPictureNcgrFile, 0xe00);
    Gfx_ReadCharGraphicsV2(&g_GlobalB4A4->mCupPictureNcgr, g_GlobalB4A4->mCupPictureNcgrFile);
}

void LoadCupPictureNscr(void) {
    char buf[0x100];
    s32 pictureIndex;
    s32 nitroOrRetro;
    s32 pictureNumber;

    pictureIndex = g_GlobalB4A4->mCupPictureIndex;
    nitroOrRetro = gCupPictureNitroOrRetroTable[pictureIndex * 2];
    pictureNumber = gCupPictureNumberTable[pictureIndex * 2];
    _snprintf(buf, 0x100, "%s%s%02d%s", gCupPicturePrefix, nitroOrRetro == 0 ? gCupPictureNitro : gCupPictureRetro,
             pictureNumber, "_m_picture.NSCR");
    OpenReadEntireFileBuffer_from_thumb(buf, g_GlobalB4A4->mCupPictureNscrFile, 0x824);
    MaybeReadScreenBlock_0(&g_GlobalB4A4->mCupPictureNscr, g_GlobalB4A4->mCupPictureNscrFile);
}
#pragma thumb off
