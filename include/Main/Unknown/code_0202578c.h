#pragma once

#include "types.h"

// 12-byte entries of the table at data_02153918.
typedef struct Unk02153918 {
    /* 00 */ s16 field0;
    /* 02 */ u16 field2;
    /* 04 */ u16 field4;
    /* 06 */ s16 field6;
    /* 08 */ s32 field8;
} Unk02153918;

u32 sub_202578C(u32 a);
void mutil2_initUnpackBgGraphics(u32 a, void *fileSetPointer, const char *charsName, const char *paletteName,
                   const char *screenMapName, s32 index, void *(*findFile)(const char *) );
void mutil2_loadUnpackBgGraphics(void *fileSetPointer, const char *charsName, const char *paletteName,
                          const char *screenMapName, s32 index, void *(*findFile)(const char *) );
void mutil2_initBgGraphics(u32 a, void *fileSetPointer, const char *charsName, const char *paletteName,
                   const char *screenMapName, s32 index, void *(*findFile)(const char *) );
void mutil2_loadBgGraphics(void *fileSetPointer, const char *charsName, const char *paletteName,
                            const char *screenMapName, s32 index, void *(*findFile)(const char *) );
void mutil2_bgVramTransferTask(u32 a, void *fileSetPointer, u32 index);
s32 mutil2_initLabel(u32 a, void *heap, void *fileSetPointer, void *entryPointer, s32 e);
void mutil2_initLayout(u32 a, void *heap, void *fileSetPointer);
void mutil2_loadUnpackLayout(void *fileSetPointer, const char *charsName, const char *cellsName, const char *paletteName,
                     const char *cellLayoutName, const char *labelLayoutName, const char *rectsName,
                     void *(*findFile)(const char *) );
void mutil2_loadLayout(void *fileSetPointer, const char *charsName, const char *cellsName, const char *paletteName,
                       const char *cellLayoutName, const char *labelLayoutName, const char *rectsName,
                       void *(*findFile)(const char *) );
