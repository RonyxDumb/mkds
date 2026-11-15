#pragma once

#include "types.h"
#include "03/System/tasks.h"

typedef struct PointerStack PointerStack;

// The units of the object character memory the ranges are cut from: the first one and the one after the last.
#define OBJ_CHAR_RANGE_FIRST_UNIT 0x300
#define OBJ_CHAR_RANGE_END_UNIT 0x400

typedef struct ObjCharRange {
    /* 00 */ struct ObjCharRange *mPrev;
    /* 04 */ struct ObjCharRange *mNext;
    /* 08 */ u16 mStart;
    /* 0a */ u16 mLength;
} ObjCharRange;

typedef struct ObjCharRanges {
    /* 000 */ u8 mRanges[0x180];
    /* 180 */ ObjCharRange mListStart;
    /* 18c */ ObjCharRange mListEnd;
    /* 198 */ void *mList;
    /* 19c */ PointerStack *mFreeRanges;
} ObjCharRanges;

typedef struct OamBuffers {
    /* 000 */ u8 mBuffers[2][0x400];
    /* 800 */ PointerStack *mFreeEntries[2];
    /* 808 */ TaskEntry *mUploadTask;
} OamBuffers;

void UploadOamBuffers(TaskEntry *task, void *arg);
void InitOamBuffers(void);
void DeleteObjCharRange(ObjCharRange *range);
ObjCharRange *CreateObjCharRange(u32 screen, s32 charCount, s32 fromFront, u32 *outStart);
void InitObjCharRanges(void);

extern struct ObjCharRanges *gObjCharRanges;
