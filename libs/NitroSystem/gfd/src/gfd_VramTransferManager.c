#include "gfd_VramTransferManager.h"
#include "code_02016638.h"
#include "code_0200eddc.h"
#include "code_0214b824.h"
#include "code_0214b338.h"
#include "gx_load3d.h"
#include "code_0201661c.h"
#include "code_020165d8.h"
#include "code_020165b8.h"
#include "code_02016574.h"

u16 GetNextIndex_(NNSGfdVramTransferTaskQueue *queue, u32 index) {
    return (index + 1) % queue->mLengthOfArray;
}

s32 IsVramTransferTaskQueueFull_(NNSGfdVramTransferTaskQueue *queue) {
    return queue->mNumTasks == queue->mLengthOfArray;
}

s32 IsVramTransferTaskQueueEmpty_(NNSGfdVramTransferTaskQueue *queue) {
    return queue->mNumTasks == 0;
}

void DoTransfer3dTex(const void *pSrc, u32 offset, u32 szByte) {
    GX_BeginLoadTex();
    GX_LoadTex(pSrc, offset, szByte);
    GX_EndLoadTex();
}

void DoTransfer3dTexPltt(const void *pSrc, u32 offset, u32 szByte) {
    GX_BeginLoadTexPltt();
    GX_LoadTexPltt(pSrc, offset, szByte);
    GX_EndLoadTexPltt();
}

void DoTransfer3dClearImageColor(const void *pSrc, u32 offset, u32 szByte) {
    GX_BeginLoadClearImage();
    GX_LoadClearImageColor(pSrc, szByte);
    GX_EndLoadClearImage();
}

void DoTransfer3dClearImageDepth(const void *pSrc, u32 offset, u32 szByte) {
    GX_BeginLoadClearImage();
    GX_LoadClearImageDepth(pSrc, szByte);
    GX_EndLoadClearImage();
}

void DoTransfer2dBG0CharMain(const void *pSrc, u32 offset, u32 szByte) {
    GX_LoadBG0Char(pSrc, offset, szByte);
}

void DoTransfer2dBG1CharMain(const void *pSrc, u32 offset, u32 szByte) {
    GX_LoadBG1Char(pSrc, offset, szByte);
}

void DoTransfer2dBG2CharMain(const void *pSrc, u32 offset, u32 szByte) {
    GX_LoadBG2Char(pSrc, offset, szByte);
}

void DoTransfer2dBG3CharMain(const void *pSrc, u32 offset, u32 szByte) {
    GX_LoadBG3Char(pSrc, offset, szByte);
}

void DoTransfer2dBG0ScrMain(const void *pSrc, u32 offset, u32 szByte) {
    GX_LoadBG0Scr(pSrc, offset, szByte);
}

void DoTransfer2dBG1ScrMain(const void *pSrc, u32 offset, u32 szByte) {
    GX_LoadBG1Scr(pSrc, offset, szByte);
}

void DoTransfer2dBG2ScrMain(const void *pSrc, u32 offset, u32 szByte) {
    GX_LoadBG2Scr(pSrc, offset, szByte);
}

void DoTransfer2dBG3ScrMain(const void *pSrc, u32 offset, u32 szByte) {
    GX_LoadBG3Scr(pSrc, offset, szByte);
}

void DoTransfer2dBG2BmpMain(const void *pSrc, u32 offset, u32 szByte) {
    GX_LoadBG2Scr(pSrc, offset, szByte);
}

void DoTransfer2dBG3BmpMain(const void *pSrc, u32 offset, u32 szByte) {
    GX_LoadBG3Scr(pSrc, offset, szByte);
}

void DoTransfer2dObjPlttMain(const void *pSrc, u32 offset, u32 szByte) {
    GX_LoadOBJPltt(pSrc, offset, szByte);
}

void DoTransfer2dBGPlttMain(const void *pSrc, u32 offset, u32 szByte) {
    GX_LoadBGPltt(pSrc, offset, szByte);
}

void DoTransfer2dObjExtPlttMain(const void *pSrc, u32 offset, u32 szByte) {
    GX_BeginLoadOBJExtPltt();
    GX_LoadOBJExtPltt(pSrc, offset, szByte);
    GX_EndLoadOBJExtPltt();
}

void DoTransfer2dBGExtPlttMain(const void *pSrc, u32 offset, u32 szByte) {
    GX_BeginLoadBGExtPltt();
    GX_LoadBGExtPltt(pSrc, offset, szByte);
    GX_EndLoadBGExtPltt();
}

void DoTransfer2dObjOamMain(const void *pSrc, u32 offset, u32 szByte) {
    GX_LoadOAM(pSrc, offset, szByte);
}

void DoTransfer2dObjCharMain(const void *pSrc, u32 offset, u32 szByte) {
    GX_LoadOBJ(pSrc, offset, szByte);
}

void DoTransfer2dBG0CharSub(const void *pSrc, u32 offset, u32 szByte) {
    GXS_LoadBG0Char(pSrc, offset, szByte);
}

void DoTransfer2dBG1CharSub(const void *pSrc, u32 offset, u32 szByte) {
    GXS_LoadBG1Char(pSrc, offset, szByte);
}

void DoTransfer2dBG2CharSub(const void *pSrc, u32 offset, u32 szByte) {
    GXS_LoadBG2Char(pSrc, offset, szByte);
}

void DoTransfer2dBG3CharSub(const void *pSrc, u32 offset, u32 szByte) {
    GXS_LoadBG3Char(pSrc, offset, szByte);
}

void DoTransfer2dBG0ScrSub(const void *pSrc, u32 offset, u32 szByte) {
    GXS_LoadBG0Scr(pSrc, offset, szByte);
}

void DoTransfer2dBG1ScrSub(const void *pSrc, u32 offset, u32 szByte) {
    GXS_LoadBG1Scr(pSrc, offset, szByte);
}

void DoTransfer2dBG2ScrSub(const void *pSrc, u32 offset, u32 szByte) {
    GXS_LoadBG2Scr(pSrc, offset, szByte);
}

void DoTransfer2dBG3ScrSub(const void *pSrc, u32 offset, u32 szByte) {
    GXS_LoadBG3Scr(pSrc, offset, szByte);
}

void DoTransfer2dBG2BmpSub(const void *pSrc, u32 offset, u32 szByte) {
    GXS_LoadBG2Scr(pSrc, offset, szByte);
}

void DoTransfer2dBG3BmpSub(const void *pSrc, u32 offset, u32 szByte) {
    GXS_LoadBG3Scr(pSrc, offset, szByte);
}

void DoTransfer2dObjPlttSub(const void *pSrc, u32 offset, u32 szByte) {
    GXS_LoadOBJPltt(pSrc, offset, szByte);
}

void DoTransfer2dBGPlttSub(const void *pSrc, u32 offset, u32 szByte) {
    GXS_LoadBGPltt(pSrc, offset, szByte);
}

void DoTransfer2dObjExtPlttSub(const void *pSrc, u32 offset, u32 szByte) {
    GXS_BeginLoadOBJExtPltt();
    GXS_LoadOBJExtPltt(pSrc, offset, szByte);
    GXS_EndLoadOBJExtPltt();
}

void DoTransfer2dBGExtPlttSub(const void *pSrc, u32 offset, u32 szByte) {
    GXS_BeginLoadBGExtPltt();
    GXS_LoadBGExtPltt(pSrc, offset, szByte);
    GXS_EndLoadBGExtPltt();
}

void DoTransfer2dObjOamSub(const void *pSrc, u32 offset, u32 szByte) {
    GXS_LoadOAM(pSrc, offset, szByte);
}

void DoTransfer2dObjCharSub(const void *pSrc, u32 offset, u32 szByte) {
    GXS_LoadOBJ(pSrc, offset, szByte);
}

void DoTransfer_(NNSGfdVramTransferTask *task) {
    void (*f)(const void *, u32, u32);

    f = data_02152c54[task->mType];
    DC_FlushRange(task->mPSrc, task->mSzByte);
    f(task->mPSrc, task->mDstAddr, task->mSzByte);
}

void ResetTaskQueue_(NNSGfdVramTransferTaskQueue *queue) {
    u32 zero;
    zero = 0u;
    queue->mIdxRear = zero;
    queue->mIdxFront = queue->mIdxRear;
    queue->mNumTasks = zero;
    queue->mTotalSize = zero;
}

s32 NNSi_GfdPushVramTransferTaskQueue(NNSGfdVramTransferTaskQueue *queue) {
    if (IsVramTransferTaskQueueFull_(queue) != 0) {
        return 0;
    }
    queue->mIdxRear = GetNextIndex_(queue, queue->mIdxRear);
    queue->mNumTasks += 1;
    return 1;
}

NNSGfdVramTransferTask *NNSi_GfdGetFrontVramTransferTaskQueue(NNSGfdVramTransferTaskQueue *queue) {
    return queue->mPTaskArray + queue->mIdxFront;
}

NNSGfdVramTransferTask *NNSi_GfdGetEndVramTransferTaskQueue(NNSGfdVramTransferTaskQueue *queue) {
    return queue->mPTaskArray + queue->mIdxRear;
}

s32 NNSi_GfdPopVramTransferTaskQueue(NNSGfdVramTransferTaskQueue *queue) {
    if (IsVramTransferTaskQueueEmpty_(queue) != 0) {
        return 0;
    }
    queue->mIdxFront = GetNextIndex_(queue, queue->mIdxFront);
    queue->mNumTasks -= 1;
    return 1;
}

NNSGfdVramTransferTaskQueue data_02173220;

void NNS_GfdInitVramTransferManager(NNSGfdVramTransferTask *pTaskArray, u32 lengthOfArray) {
    data_02173220.mPTaskArray = pTaskArray;
    data_02173220.mLengthOfArray = lengthOfArray;
    ResetTaskQueue_(&data_02173220);
}

void NNS_GfdDoVramTransfer(void) {
    NNSGfdVramTransferTaskQueue *queue;
    NNSGfdVramTransferTask *task;

    queue = &data_02173220;
    task = NNSi_GfdGetFrontVramTransferTaskQueue(queue);
    while (NNSi_GfdPopVramTransferTaskQueue(queue) != 0) {
        DoTransfer_(task);
        queue->mTotalSize -= task->mSzByte;
        task = NNSi_GfdGetFrontVramTransferTaskQueue(queue);
    }
}

s32 NNS_GfdRegisterNewVramTransferTask(u32 type, u32 dstAddr, void *pSrc, u32 szByte) {
    NNSGfdVramTransferTaskQueue *queue;
    NNSGfdVramTransferTask *task;

    queue = &data_02173220;
    if (IsVramTransferTaskQueueFull_(queue) != 0) {
        return 0;
    }
    task = NNSi_GfdGetEndVramTransferTaskQueue(queue);
    task->mType = type;
    task->mPSrc = pSrc;
    task->mDstAddr = dstAddr;
    task->mSzByte = szByte;
    NNSi_GfdPushVramTransferTaskQueue(queue);
    queue->mTotalSize = queue->mTotalSize + task->mSzByte;
    return 1;
}
