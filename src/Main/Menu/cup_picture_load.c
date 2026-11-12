#include "Main/Menu/cup_picture_load.h"
#include "Main/Unknown/code_020d113c.h"
#include "Main/System/heap_call.h"
#include "Main/Unknown/code_020d1108.h"
#include "Main/System/heap.h"
#include "Main/Unknown/code_020d0efc.h"
#include "Main/Race/race_start_battle.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/System/archive_slots.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Unknown/code_02048000.h"
#include "code_02134398.h"
#include "Main/Unknown/unk_0216a000.h"

u32 CupPictureGetCurrentHeap(void) {
    u32 value0;
    value0 = (u32) GetCurrentHeapCall();
    value0 = (u32) GetHeap((void *) value0);
    return value0;
}

#pragma thumb on

void InitCupPicture(void) {
    int result;
    CupPicture *cupPicture;
    u32 heap;
    result = CupPictureMB_IsMultiBootChildWrapper();
    if (result == 0) {
        heap = CupPictureGetCurrentHeap();
        cupPicture = HeapAlloc((void *) heap, (0x0000185cu));
        gCupPicture = cupPicture;
        cupPicture->mCupPictureIndex = 0;
        TrySetCupPictureIndexAndQueueLoads(0x14);
    }
}

#pragma thumb off

#pragma opt_propagation off

#pragma thumb on
void ClearCupPicturePointer(void) {
    gCupPicture = NULL;
}

void LoadCupPictureNclr(void) {
    char buf[0x100];
    s32 pictureIndex;
    s32 nitroOrRetro;
    s32 pictureNumber;

    pictureIndex = gCupPicture->mCupPictureIndex;
    nitroOrRetro = data_0216aea8[pictureIndex * 2];
    pictureNumber = data_0216aeac[pictureIndex * 2];
    snprintf(buf, 0x100, "%s%s%02d%s", gCupPicturePrefix, nitroOrRetro == 0 ? gCupPictureNitro : gCupPictureRetro,
             pictureNumber, "_m_b.NCLR");
    ReadWholeFile(buf, gCupPicture->mCupPictureNclrFile, 0x228);
    LoadNclrData(&gCupPicture->mCupPictureNclr, gCupPicture->mCupPictureNclrFile);
}

void LoadCupPictureNcgr(void) {
    char buf[0x100];
    s32 pictureIndex;
    s32 nitroOrRetro;
    s32 pictureNumber;

    pictureIndex = gCupPicture->mCupPictureIndex;
    nitroOrRetro = data_0216aea8[pictureIndex * 2];
    pictureNumber = data_0216aeac[pictureIndex * 2];
    snprintf(buf, 0x100, "%s%s%02d%s", gCupPicturePrefix, nitroOrRetro == 0 ? gCupPictureNitro : gCupPictureRetro,
             pictureNumber, "_m_b.NCGR");
    ReadWholeFile(buf, gCupPicture->mCupPictureNcgrFile, 0xe00);
    LoadNcgrData(&gCupPicture->mCupPictureNcgr, gCupPicture->mCupPictureNcgrFile);
}

void LoadCupPictureNscr(void) {
    char buf[0x100];
    s32 pictureIndex;
    s32 nitroOrRetro;
    s32 pictureNumber;

    pictureIndex = gCupPicture->mCupPictureIndex;
    nitroOrRetro = data_0216aea8[pictureIndex * 2];
    pictureNumber = data_0216aeac[pictureIndex * 2];
    snprintf(buf, 0x100, "%s%s%02d%s", gCupPicturePrefix, nitroOrRetro == 0 ? gCupPictureNitro : gCupPictureRetro,
             pictureNumber, "_m_picture.NSCR");
    ReadWholeFile(buf, gCupPicture->mCupPictureNscrFile, 0x824);
    LoadNscrData(&gCupPicture->mCupPictureNscr, gCupPicture->mCupPictureNscrFile);
}
#pragma thumb off
