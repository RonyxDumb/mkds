#pragma once

#include "types.h"

// An emblem's 0x200 bytes of pixels and a byte that is 1 once the pixels are filled in.
typedef struct EmblemData {
    /* 000 */ u8 mPixels[0x200];
    /* 200 */ u8 mHasPixels;
} EmblemData;

void BuildRecordList(void);
u16 GetRecordCount(void);
s32 IsRecordFlagged(u16 listIndex);
s32 GetRecordMatchKind0FirstCount(u16 listIndex);
s32 GetRecordMatchKind1FirstCount(u16 listIndex);
s32 GetRecordMatchKind2FirstCount(u16 listIndex);
s32 GetRecordMatchKind0SecondCount(u16 listIndex);
s32 GetRecordMatchKind1SecondCount(u16 listIndex);
s32 GetRecordMatchKind2SecondCount(u16 listIndex);
s32 GetRecordDate(u16 listIndex, void *dateBytes);
void CopyRecordText(u16 listIndex, void *buffer, u32 bufferSize);
s32 SetRecordFlag(u16 listIndex);
s32 ClearRecordFlag(u16 listIndex);
void ReadRecordEmblem(u16 listIndex, EmblemData *emblem, void *tiles);
void EraseRecord(u16 listIndex);
s32 GetRecordFriendKeyText(u16 listIndex, void *text);
