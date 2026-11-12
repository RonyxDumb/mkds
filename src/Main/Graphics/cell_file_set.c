#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Menu/data_02174000.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "code_02022aa8.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/multi_select_member_group.h"
#include "tp.h"
#include "Main/Save/buddy_record_time.h"
#include "g2d_CellTransferManager.h"
#include "gfd_VramTransferManager.h"

#pragma thumb on

void LocateCellFileSet(void *fileSetPointer, const char *charsName, const char *cellsName, const char *paletteName,
                       const char *cellLayoutName, const char *labelLayoutName, const char *rectsName,
                       void *(*findFile)(const char *) ) {
    CellFileSet *fileSet = fileSetPointer;
    if (charsName) {
        LocateNcgr2(&fileSet->mChars, findFile(charsName));
    }
    if (cellsName) {
        LocateNcer(&fileSet->mCells, findFile(cellsName));
    }
    if (paletteName) {
        LocateNclr(&fileSet->mPalette, findFile(paletteName));
    }
    if (cellLayoutName) {
        fileSet->mCellLayout = findFile(cellLayoutName);
    }
    if (labelLayoutName) {
        fileSet->mLabelLayout = findFile(labelLayoutName);
    }
    if (rectsName) {
        fileSet->mRects = findFile(rectsName);
    }
}

void LoadCellFileSet(void *fileSetPointer, const char *charsName, const char *cellsName, const char *paletteName,
                     const char *cellLayoutName, const char *labelLayoutName, const char *rectsName,
                     void *(*findFile)(const char *) ) {
    CellFileSet *fileSet = fileSetPointer;
    if (charsName) {
        LoadNcgrData2(&fileSet->mChars, findFile(charsName));
    }
    if (cellsName) {
        LoadNcerData(&fileSet->mCells, findFile(cellsName));
    }
    if (paletteName) {
        LoadNclrData(&fileSet->mPalette, findFile(paletteName));
    }
    if (cellLayoutName) {
        fileSet->mCellLayout = findFile(cellLayoutName);
    }
    if (labelLayoutName) {
        fileSet->mLabelLayout = findFile(labelLayoutName);
    }
    if (rectsName) {
        fileSet->mRects = findFile(rectsName);
    }
}

void SetupCellFileSet(u32 screen, void *heap, CellFileSet *fileSet) {
    u32 charsCode;
    InitLayoutTable(heap, fileSet->mCellLayout, fileSet->mLabelLayout, &fileSet->mCellTable);
    if (screen == 0) {
        charsCode = 0x13;
        NNS_GfdRegisterNewVramTransferTask(0xe, 0, fileSet->mPalette->mData, 0x1a0);
        NNS_GfdRegisterNewVramTransferTask(0xe, 0x1c0, (u8 *) fileSet->mPalette->mData + 0x1c0, 0x40);
    } else {
        charsCode = 0x23;
        NNS_GfdRegisterNewVramTransferTask(0x1e, 0, fileSet->mPalette->mData, fileSet->mPalette->mDataSize);
    }
    NNS_GfdRegisterNewVramTransferTask(charsCode, 0, fileSet->mChars->mData, fileSet->mChars->mDataSize);
}

s32 SetupLabelCanvas(u32 screen, void *heap, CellFileSet *fileSet, void *entryPointer, s32 objSizeLeft) {
    LabelCanvasEntry *entry = entryPointer;
    s32 result;
    result =
        InitLabelCanvas(heap, entry->mLabelIndex, fileSet->mLabelLayout, entry->mWidth, entry->mHeight,
                        entry->mEntryIndex, fileSet->mCells, fileSet->mCellLayout, fileSet->mCellTable, objSizeLeft);
    ClearAndQueueLabelLayoutText(screen, entry->mLabelIndex, fileSet->mLabelLayout, fileSet->mCellLayout,
                                 fileSet->mCellTable);
    return result;
}

void QueueScreenMapFileSet(u32 screen, void *fileSetPointer, u32 index) {
    ScreenMapFileSet *fileSet = fileSetPointer;
    u32 charsCode;
    u32 screenMapCode;
    u32 paletteCode;
    if (screen == 0) {
        paletteCode = 0xf;
        switch (index) {
            case 0:
                charsCode = 4;
                screenMapCode = 8;
                break;
            case 1:
                charsCode = 5;
                screenMapCode = 9;
                break;
            case 2:
                charsCode = 6;
                screenMapCode = 10;
                break;
            case 3:
                charsCode = 7;
                screenMapCode = 11;
                break;
        }
    } else {
        paletteCode = 0x1f;
        switch (index) {
            case 0:
                charsCode = 0x14;
                screenMapCode = 0x18;
                break;
            case 1:
                charsCode = 0x15;
                screenMapCode = 0x19;
                break;
            case 2:
                charsCode = 0x16;
                screenMapCode = 0x1a;
                break;
            case 3:
                charsCode = 0x17;
                screenMapCode = 0x1b;
                break;
        }
    }
    NNS_GfdRegisterNewVramTransferTask(charsCode, 0, fileSet->mChars[index]->mData, fileSet->mChars[index]->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(paletteCode, 0, fileSet->mPalette->mData, 0x140);
    NNS_GfdRegisterNewVramTransferTask(screenMapCode, 0, &fileSet->mScreenMaps[index]->mData,
                                       fileSet->mScreenMaps[index]->mDataSize);
}

void LocateScreenMapFileSet(void *fileSetPointer, const char *charsName, const char *paletteName,
                            const char *screenMapName, s32 index, void *(*findFile)(const char *) ) {
    ScreenMapFileSet *fileSet = fileSetPointer;
    if (charsName) {
        LocateNcgr(&fileSet->mChars[index], findFile(charsName));
    }
    if (paletteName) {
        LocateNclr(&fileSet->mPalette, findFile(paletteName));
    }
    if (screenMapName) {
        LocateNscr(&fileSet->mScreenMaps[index], findFile(screenMapName));
    }
}

void LocateAndQueueScreenMapFileSet(u32 screen, void *fileSetPointer, const char *charsName, const char *paletteName,
                                    const char *screenMapName, s32 index, void *(*findFile)(const char *) ) {
    LocateScreenMapFileSet(fileSetPointer, charsName, paletteName, screenMapName, index, findFile);
    QueueScreenMapFileSet(screen, fileSetPointer, index);
}

void LoadScreenMapFileSet(void *fileSetPointer, const char *charsName, const char *paletteName,
                          const char *screenMapName, s32 index, void *(*findFile)(const char *) ) {
    ScreenMapFileSet *fileSet = fileSetPointer;
    if (charsName) {
        LoadNcgrData(&fileSet->mChars[index], findFile(charsName));
    }
    if (paletteName) {
        LoadNclrData(&fileSet->mPalette, findFile(paletteName));
    }
    if (screenMapName) {
        LoadNscrData(&fileSet->mScreenMaps[index], findFile(screenMapName));
    }
}

void LoadAndQueueScreenMapFileSet(u32 screen, void *fileSetPointer, const char *charsName, const char *paletteName,
                                  const char *screenMapName, s32 index, void *(*findFile)(const char *) ) {
    LoadScreenMapFileSet(fileSetPointer, charsName, paletteName, screenMapName, index, findFile);
    QueueScreenMapFileSet(screen, fileSetPointer, index);
}

#pragma thumb off

u32 GetKartSoundTableRow(u32 kartIndex) {
    u32 result = 3;
    switch (kartIndex) {
        case 0:
        case 3:
        case 6:
        case 9:
        case 12:
        case 15:
        case 18:
        case 21:
        case 24:
        case 27:
        case 30:
        case 33:
        case 36:
            result = 0;
            break;
        case 2:
        case 8:
        case 13:
        case 14:
        case 20:
        case 23:
        case 25:
        case 28:
        case 31:
            result = 0;
            break;
        case 1:
        case 7:
        case 19:
        case 22:
        case 26:
        case 29:
        case 32:
        case 34:
        case 35:
            result = 1;
            break;
        case 4:
        case 5:
        case 10:
        case 11:
        case 16:
        case 17:
            result = 2;
            break;
    }
    return result;
}
