#include "Main/Unknown/code_02116dc8.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b4000.h"

#include "Main/Unknown/code_02116dd4.h"
#include "Main/Unknown/unk_0216d000.h"

#pragma thumb on

void wait_unpackData(void) {
    void *sceneFile;
    Unk02021dc8 *cells;
    Ncgr *chars;
    Nclr *palette[1];
    cells = NULL;
    chars = NULL;
    palette[0] = NULL;
    sceneFile = arc_getSceneArcFile(wait_sNcerName);
    g2du_unpackCellBankData(&cells, sceneFile);
    sceneFile = arc_getSceneArcFile(wait_sNcgrName);
    g2du_unpackCharacterData(&chars, sceneFile);
    sceneFile = arc_getSceneArcFile(wait_sNclrName);
    g2du_unpackPaletteData(palette, sceneFile);
}

void wait_init(void *heap, Unk02021dc8 *destinationNcer, Unk0201ea30 *destinationBncl, u32 destinationBnclIndex,
                u16 paletteIndex, u32 f) {
    Wait *v1;
    Wait *newWait;
    void *sceneFile;
    newWait = heap_alloc(heap, 0x2c);
    sWaitData = newWait;
    sceneFile = arc_getSceneArcFile(wait_sNcerName);
    g2du_getCellBankData(&sWaitData->mNcer, sceneFile);
    sceneFile = arc_getSceneArcFile(wait_sNcgrName);
    g2du_getCharacterData((Ncgr **) &sWaitData->mNcgr, sceneFile);
    sceneFile = arc_getSceneArcFile(wait_sNclrName);
    g2du_getPaletteData(&sWaitData->mNclr, sceneFile);
    sceneFile = arc_getSceneArcFile(wait_sBnclName);
    sWaitData->mBncl = sceneFile;
    sWaitData->mDestinationNcer = destinationNcer;
    sWaitData->mDestinationBncl = destinationBncl;
    sWaitData->mDestinationBnclIndex = destinationBnclIndex;
    sWaitData->mPaletteIndex = paletteIndex;
    sWaitData->field20 = f;
    sWaitData->mFrameIndex = 2;
    sWaitData->mFrameIndexFrames = 3;
}

#pragma thumb off

#pragma thumb on
void wait_free(void) {
    u32 pointerAddress;
    u32 zero;
    zero = 0u;
    pointerAddress = (u32) &sWaitData;
    *(u32 *) ((pointerAddress) + 0u) = zero;
}
#pragma thumb off
