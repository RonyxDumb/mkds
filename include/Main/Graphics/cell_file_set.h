#pragma once

#include "types.h"

typedef struct CellFileSet CellFileSet;

// Row of a label canvas table: mLabelIndex, mWidth, mHeight and mEntryIndex for SetupLabelCanvas, and mMessageIndex
// (only gSelectKartSLabelCanvasEntries uses it; SetupLabelCanvas also reads shorter rows that stop after mEntryIndex).
typedef struct LabelCanvasEntry {
    /* 00 */ s16 mLabelIndex;
    /* 02 */ u16 mWidth;
    /* 04 */ u16 mHeight;
    /* 06 */ s16 mEntryIndex;
    /* 08 */ s32 mMessageIndex;
} LabelCanvasEntry;

// Which screen a file set goes to.
typedef enum ScreenSide {
    SCREEN_SIDE_MAIN = 0,
    SCREEN_SIDE_SUB = 1,
} ScreenSide;

// Result of GetKartSoundTableRow: the row of gKartSoundRowSoundIds; NONE is for a kart index no list names (it is not a
// row of the table).
typedef enum KartSoundTableRow {
    KART_SOUND_TABLE_ROW_FIRST = 0,
    KART_SOUND_TABLE_ROW_SECOND = 1,
    KART_SOUND_TABLE_ROW_THIRD = 2,
    KART_SOUND_TABLE_ROW_NONE = 3,
} KartSoundTableRow;

u32 GetKartSoundTableRow(u32 kartIndex);
void LoadAndQueueScreenMapFileSet(u32 screen, void *fileSetPointer, const char *charsName, const char *paletteName,
                                  const char *screenMapName, s32 index, void *(*findFile)(const char *) );
void LoadScreenMapFileSet(void *fileSetPointer, const char *charsName, const char *paletteName,
                          const char *screenMapName, s32 index, void *(*findFile)(const char *) );
void LocateAndQueueScreenMapFileSet(u32 screen, void *fileSetPointer, const char *charsName, const char *paletteName,
                                    const char *screenMapName, s32 index, void *(*findFile)(const char *) );
void LocateScreenMapFileSet(void *fileSetPointer, const char *charsName, const char *paletteName,
                            const char *screenMapName, s32 index, void *(*findFile)(const char *) );
void QueueScreenMapFileSet(u32 screen, void *fileSetPointer, u32 index);
s32 SetupLabelCanvas(u32 screen, void *heap, CellFileSet *fileSet, const void *entryPointer, s32 objSizeLeft);
void SetupCellFileSet(u32 screen, void *heap, CellFileSet *fileSet);
void LoadCellFileSet(void *fileSetPointer, const char *charsName, const char *cellsName, const char *paletteName,
                     const char *cellLayoutName, const char *labelLayoutName, const char *rectsName,
                     void *(*findFile)(const char *) );
void LocateCellFileSet(void *fileSetPointer, const char *charsName, const char *cellsName, const char *paletteName,
                       const char *cellLayoutName, const char *labelLayoutName, const char *rectsName,
                       void *(*findFile)(const char *) );
