#pragma once

#include "types.h"

// A VRAM transfer task: the type that selects the transfer function, the source, the destination and the size.
typedef struct NNSGfdVramTransferTask {
    /* 00 */ u32 mType;
    /* 04 */ const void *mPSrc;
    /* 08 */ u32 mDstAddr;
    /* 0c */ u32 mSzByte;
} NNSGfdVramTransferTask;

// Object at g_GlobalTEQ: a pointer to an array of NNSGfdVramTransferTask, its length at 04, two indices at 08
// and 0a that StructTEQ_IncrementValidateIndex advances modulo the length, and a count at 0c (StructTEQ_IsTEQSubListFull compares it
// with the length, StructTEQ_IsCounterEmpty tests it for zero).
typedef struct NNSGfdVramTransferTaskQueue {
    /* 00 */ NNSGfdVramTransferTask *mPTaskArray;
    /* 04 */ u32 mLengthOfArray;
    /* 08 */ u16 mIdxFront;
    /* 0a */ u16 mIdxRear;
    /* 0c */ u16 mNumTasks;
    /* 10 */ u32 mTotalSize;
} NNSGfdVramTransferTaskQueue;

extern void (*const g_TEQSubFnList[36])(const void *pSrc, u32 offset, u32 szByte);

void StructTEQSub_HandleTEQSub(NNSGfdVramTransferTask *task);
void TEQSub_Fn35(const void *pSrc, u32 offset, u32 szByte);
void j_CopyToOamB(const void *pSrc, u32 offset, u32 szByte);
void TEQSub_Fn33(const void *pSrc, u32 offset, u32 szByte);
void TEQSub_Fn32(const void *pSrc, u32 offset, u32 szByte);
void j_CopyPaletteBottom(const void *pSrc, u32 offset, u32 szByte);
void TEQSub_Fn30(const void *pSrc, u32 offset, u32 szByte);
void TEQSub_Fn29(const void *pSrc, u32 offset, u32 szByte);
void TEQSub_Fn28(const void *pSrc, u32 offset, u32 szByte);
void TEQSub_Fn27(const void *pSrc, u32 offset, u32 szByte);
void TEQSub_Fn26(const void *pSrc, u32 offset, u32 szByte);
void TEQSub_Fn25(const void *pSrc, u32 offset, u32 szByte);
void TEQSub_Fn24(const void *pSrc, u32 offset, u32 szByte);
void TEQSub_Fn23(const void *pSrc, u32 offset, u32 szByte);
void TEQSub_Fn22(const void *pSrc, u32 offset, u32 szByte);
void j_CopyTileDataBottom(const void *pSrc, u32 offset, u32 szByte);
void TEQSub_Fn20(const void *pSrc, u32 offset, u32 szByte);
void j_CopySomeTileData(const void *pSrc, u32 offset, u32 szByte);
void j_CopyToOamA(const void *pSrc, u32 offset, u32 szByte);
void TEQSub_Fn17(const void *pSrc, u32 offset, u32 szByte);
void TEQSub_Fn16(const void *pSrc, u32 offset, u32 szByte);
void j_CopyPaletteTop(const void *pSrc, u32 offset, u32 szByte);
void j_CopySomePaletteData(const void *pSrc, u32 offset, u32 szByte);
void TEQSub_Fn13(const void *pSrc, u32 offset, u32 szByte);
void TEQSub_Fn12(const void *pSrc, u32 offset, u32 szByte);
void TEQSub_Fn11(const void *pSrc, u32 offset, u32 szByte);
void TEQSub_Fn10(const void *pSrc, u32 offset, u32 szByte);
void TEQSub_Fn9(const void *pSrc, u32 offset, u32 szByte);
void TEQSub_Fn8(const void *pSrc, u32 offset, u32 szByte);
void TEQSub_Fn7(const void *pSrc, u32 offset, u32 szByte);
void TEQSub_Fn6(const void *pSrc, u32 offset, u32 szByte);
void j_CopyTileDataTop(const void *pSrc, u32 offset, u32 szByte);
void TEQSub_Fn4(const void *pSrc, u32 offset, u32 szByte);
void TEQSub_Fn3(const void *pSrc, u32 offset, u32 szByte);
void TEQSub_Fn2(const void *pSrc, u32 offset, u32 szByte);
void TEQSub_Fn1(const void *pSrc, u32 offset, u32 szByte);
void TEQSub_Fn0(const void *pSrc, u32 offset, u32 szByte);
s32 StructTEQ_IsCounterEmpty(NNSGfdVramTransferTaskQueue *queue);
s32 StructTEQ_IsTEQSubListFull(NNSGfdVramTransferTaskQueue *queue);
u16 StructTEQ_IncrementValidateIndex(NNSGfdVramTransferTaskQueue *queue, u32 index);
