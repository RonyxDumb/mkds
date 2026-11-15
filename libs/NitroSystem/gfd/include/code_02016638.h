#pragma once

#include "types.h"

// 16 bytes: an index into transFunc and three words passed to the function it selects.
typedef struct NNSGfdVramTransferTask {
    /* 00 */ u32 mType;
    /* 04 */ const void *mPSrc;
    /* 08 */ u32 mDstAddr;
    /* 0c */ u32 mSzByte;
} NNSGfdVramTransferTask;

// Object at s_VramTransferManager: a pointer to an array of NNSGfdVramTransferTask, its length at 04, two indices at 08
// and 0a that GetNextIndex_ advances modulo the length, and a count at 0c (IsVramTransferTaskQueueFull_ compares it
// with the length, IsVramTransferTaskQueueEmpty_ tests it for zero).
typedef struct NNSGfdVramTransferTaskQueue {
    /* 00 */ NNSGfdVramTransferTask *mPTaskArray;
    /* 04 */ u32 mLengthOfArray;
    /* 08 */ u16 mIdxFront;
    /* 0a */ u16 mIdxRear;
    /* 0c */ u16 mNumTasks;
    /* 10 */ u32 mTotalSize;
} NNSGfdVramTransferTaskQueue;

extern void (*const transFunc[36])(const void *pSrc, u32 offset, u32 szByte);

void DoTransfer_(NNSGfdVramTransferTask *task);
void DoTransfer2dObjCharSub(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dObjOamSub(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBGExtPlttSub(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dObjExtPlttSub(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBGPlttSub(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dObjPlttSub(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG3BmpSub(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG2BmpSub(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG3ScrSub(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG2ScrSub(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG1ScrSub(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG0ScrSub(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG3CharSub(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG2CharSub(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG1CharSub(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG0CharSub(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dObjCharMain(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dObjOamMain(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBGExtPlttMain(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dObjExtPlttMain(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBGPlttMain(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dObjPlttMain(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG3BmpMain(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG2BmpMain(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG3ScrMain(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG2ScrMain(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG1ScrMain(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG0ScrMain(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG3CharMain(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG2CharMain(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG1CharMain(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer2dBG0CharMain(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer3dClearImageDepth(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer3dClearImageColor(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer3dTexPltt(const void *pSrc, u32 offset, u32 szByte);
void DoTransfer3dTex(const void *pSrc, u32 offset, u32 szByte);
s32 IsVramTransferTaskQueueEmpty_(NNSGfdVramTransferTaskQueue *queue);
s32 IsVramTransferTaskQueueFull_(NNSGfdVramTransferTaskQueue *queue);
u16 GetNextIndex_(NNSGfdVramTransferTaskQueue *queue, u32 index);
