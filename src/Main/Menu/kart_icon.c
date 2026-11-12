#include "Main/Menu/kart_icon.h"
#include "Main/System/heap.h"

#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Unknown/unk_0217d000.h"
#include "gfd_VramTransferManager.h"
#include "Main/Unknown/code_02117218.h"
#include "Main/Unknown/code_02117224.h"
#include "Main/Unknown/code_021172a8.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/unk_0216d000.h"
#include "Main/Unknown/code_0211732c.h"
#include "Main/System/result_archive_path.h"

#pragma thumb on

void LoadKartIconData(void) {
    void *sceneFile;
    int paletteCount;
    const char **nclrNameCursor;
    Ncgr *chars;
    Unk02021dc8 *cells;
    Nclr *palette[2];
    chars = NULL;
    cells = NULL;
    palette[0] = NULL;
    sceneFile = FindSceneFile(gKartIconNcgrName);
    LoadNcgrData(&chars, sceneFile);
    sceneFile = FindSceneFile(gKartIconNcerName);
    LoadNcerData(&cells, sceneFile);
    paletteCount = 0;
    nclrNameCursor = gKartIconNclrNames;
    do {
        sceneFile = FindSceneFile(*nclrNameCursor);
        LoadNclrData(palette, sceneFile);
        nclrNameCursor = nclrNameCursor + 1;
        paletteCount = paletteCount + 1;
    } while (paletteCount < 3);
}

void LoadCommonKartIconData(void) {
    void *sceneFile;
    int paletteCount;
    const char **nclrNameCursor;
    Ncgr *chars;
    Unk02021dc8 *cells;
    Nclr *palette[2];
    chars = NULL;
    cells = NULL;
    palette[0] = NULL;
    sceneFile = FindSceneFile(gCommonKartIconNcgrName);
    LoadNcgrData(&chars, sceneFile);
    sceneFile = FindSceneFile(gCommonKartIconNcerName);
    LoadNcerData(&cells, sceneFile);
    paletteCount = 0;
    nclrNameCursor = gCommonKartIconNclrNames;
    do {
        sceneFile = FindSceneFile(*nclrNameCursor);
        LoadNclrData(palette, sceneFile);
        nclrNameCursor = nclrNameCursor + 1;
        paletteCount = paletteCount + 1;
    } while (paletteCount < 3);
}

#pragma thumb off

#pragma thumb on

void CreateKartIcon(void *heap) {
    int nclrIndex;

    gKartIcon = HeapAlloc(heap, 0x18);
    LocateNcgr2(&gKartIcon->mNcgr, FindSceneFile(gKartIconNcgrName));
    LocateNcer(&gKartIcon->mNcer, FindSceneFile(gKartIconNcerName));
    for (nclrIndex = 0; nclrIndex < 3; nclrIndex++) {
        LocateNclr(&gKartIcon->mNclrs[nclrIndex], FindSceneFile(gKartIconNclrNames[nclrIndex]));
    }
    gKartIcon->mBncl = FindSceneFile(gKartIconBnclName);
}

#pragma thumb off

#pragma thumb on

void CreateCommonKartIcon(void *heap) {
    s32 nclrIndex;

    gKartIcon = HeapAlloc(heap, 0x18);
    LocateNcgr2(&gKartIcon->mNcgr, FindSceneFile(gCommonKartIconNcgrName));
    LocateNcer(&gKartIcon->mNcer, FindSceneFile(gCommonKartIconNcerName));
    for (nclrIndex = 0; nclrIndex < 3; nclrIndex++) {
        LocateNclr(&gKartIcon->mNclrs[nclrIndex], FindSceneFile(gCommonKartIconNclrNames[nclrIndex]));
    }
    gKartIcon->mBncl = FindSceneFile(gCommonKartIconBnclName);
}

#pragma thumb off

#pragma thumb on
void ClearKartIconPointer(void) {
    gKartIcon = NULL;
}
#pragma thumb off

#pragma thumb on

void QueueKartIcon(s32 iconIndex, Unk02021dc8 *destinationNcer, LayoutEntryTable *destinationBncl,
                   u32 destinationBnclIndex, u16 paletteIndex, s32 queueSelector) {
    int queueKind;

    queueKind = 0x12;
    switch (queueSelector) {
        case 0:
            queueKind = 0xe;
            break;
        case 1:
            queueKind = 0x1e;
            break;
    }
    QueueCellChars(gKartIconRows[iconIndex].mBnclIndex, gKartIcon->mNcer, gKartIcon->mNcgr, gKartIcon->mBncl,
                   queueSelector, destinationBnclIndex, destinationNcer, destinationBncl);
    NNS_GfdRegisterNewVramTransferTask(
        queueKind, paletteIndex * 32,
        gKartIcon->mNclrs[gKartIconRows[iconIndex].mNclrIndex]->mData + gKartIconRows[iconIndex].mNclrStart * 16, 0x20);
}

#pragma thumb off
