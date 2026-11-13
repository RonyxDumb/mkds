#include "Main/Menu/wait_load.h"
#include "Main/System/heap.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/font_and_player_character.h"

#include "Main/Menu/data_0216d000.h"

#pragma thumb on

char *gWaitNclrName = "common/wait.nclr";
Wait *gWait = NULL;
char *gWaitNcerName = "common/wait.nce.ncer";
char *gWaitBnclName = "common/wait.bncl";
char *gWaitNcgrName = "common/wait.nce.ncgr";

void LoadWaitData(void) {
    void *sceneFile;
    NNSG2dCellDataBank *cells;
    Ncgr *chars;
    Nclr *palette[1];
    cells = NULL;
    chars = NULL;
    palette[0] = NULL;
    sceneFile = FindSceneFile(gWaitNcerName);
    LoadNcerData(&cells, sceneFile);
    sceneFile = FindSceneFile(gWaitNcgrName);
    LoadNcgrData2(&chars, sceneFile);
    sceneFile = FindSceneFile(gWaitNclrName);
    LoadNclrData(palette, sceneFile);
}

void CreateWait(void *heap, NNSG2dCellDataBank *destinationNcer, LayoutEntryTable *destinationBncl, u32 destinationBnclIndex,
                u16 paletteIndex, u32 queueSelector) {
    Wait *wait;
    Wait *newWait;
    void *sceneFile;
    newWait = HeapAlloc(heap, 0x2c);
    gWait = newWait;
    sceneFile = FindSceneFile(gWaitNcerName);
    LocateNcer(&gWait->mNcer, sceneFile);
    sceneFile = FindSceneFile(gWaitNcgrName);
    LocateNcgr2(&gWait->mNcgr, sceneFile);
    sceneFile = FindSceneFile(gWaitNclrName);
    LocateNclr(&gWait->mNclr, sceneFile);
    sceneFile = FindSceneFile(gWaitBnclName);
    gWait->mBncl = sceneFile;
    gWait->mDestinationNcer = destinationNcer;
    gWait->mDestinationBncl = destinationBncl;
    gWait->mDestinationBnclIndex = destinationBnclIndex;
    gWait->mPaletteIndex = paletteIndex;
    gWait->mQueueSelector = queueSelector;
    gWait->mFrameIndex = 2;
    gWait->mFrameIndexFrames = 3;
}

#pragma thumb off

#pragma thumb on
void ClearWaitPointer(void) {
    gWait = NULL;
}
#pragma thumb off
