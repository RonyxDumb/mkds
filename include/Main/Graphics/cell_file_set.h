#pragma once

#include "types.h"

typedef struct CellFileSet CellFileSet;

// 12-byte entries of the tables at data_usa_02153918 and data_usa_021537f4.
typedef struct LabelCanvasEntry {
    /* 00 */ s16 mLabelIndex;
    /* 02 */ u16 mWidth;
    /* 04 */ u16 mHeight;
    /* 06 */ s16 mEntryIndex;
    /* 08 */ s32 mMessageIndex;
} LabelCanvasEntry;

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
s32 SetupLabelCanvas(u32 screen, void *heap, CellFileSet *fileSet, void *entryPointer, s32 objSizeLeft);
void SetupCellFileSet(u32 screen, void *heap, CellFileSet *fileSet);
void LoadCellFileSet(void *fileSetPointer, const char *charsName, const char *cellsName, const char *paletteName,
                     const char *cellLayoutName, const char *labelLayoutName, const char *rectsName,
                     void *(*findFile)(const char *) );
void LocateCellFileSet(void *fileSetPointer, const char *charsName, const char *cellsName, const char *paletteName,
                       const char *cellLayoutName, const char *labelLayoutName, const char *rectsName,
                       void *(*findFile)(const char *) );
