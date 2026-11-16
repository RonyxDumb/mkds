#include "vram_transfer_queue.h"
#include "transfer_task_types.h"
#include "arena_cache_init.h"
#include "vram_load_2d_graphics.h"
#include "vram_load_3d_graphics.h"
#include "transfer_queue_reset.h"
#include "transfer_queue_push.h"
#include "transfer_queue_peek.h"
#include "transfer_queue_pop.h"

u16 StructTEQ_IncrementValidateIndex(NNSGfdVramTransferTaskQueue *queue, u32 index) {
    return (index + 1) % queue->mLengthOfArray;
}

s32 StructTEQ_IsTEQSubListFull(NNSGfdVramTransferTaskQueue *queue) {
    return queue->mNumTasks == queue->mLengthOfArray;
}

s32 StructTEQ_IsCounterEmpty(NNSGfdVramTransferTaskQueue *queue) {
    return queue->mNumTasks == 0;
}

void TEQSub_Fn0(const void *pSrc, u32 offset, u32 szByte) {
    GX_BeginLoadTex();
    GX_LoadTex(pSrc, offset, szByte);
    GX_EndLoadTex();
}

void TEQSub_Fn1(const void *pSrc, u32 offset, u32 szByte) {
    GX_BeginLoadTexPltt();
    SomeDmaCopy_0(pSrc, offset, szByte);
    GX_EndLoadTexPltt();
}

void TEQSub_Fn2(const void *pSrc, u32 offset, u32 szByte) {
    GX_BeginLoadClearImage();
    GX_LoadClearImageColor(pSrc, szByte);
    GX_EndLoadClearImage();
}

void TEQSub_Fn3(const void *pSrc, u32 offset, u32 szByte) {
    GX_BeginLoadClearImage();
    GX_LoadClearImageDepth(pSrc, szByte);
    GX_EndLoadClearImage();
}

void TEQSub_Fn4(const void *pSrc, u32 offset, u32 szByte) {
    CopyBgData_Bg0_Top(pSrc, offset, szByte);
}

void j_CopyTileDataTop(const void *pSrc, u32 offset, u32 szByte) {
    CopyBgData_Bg1_Top(pSrc, offset, szByte);
}

void TEQSub_Fn6(const void *pSrc, u32 offset, u32 szByte) {
    CopyBgData_Bg2_Top(pSrc, offset, szByte);
}

void TEQSub_Fn7(const void *pSrc, u32 offset, u32 szByte) {
    CopyBgData_Bg3_Top(pSrc, offset, szByte);
}

void TEQSub_Fn8(const void *pSrc, u32 offset, u32 szByte) {
    TEQSub_Fn8Impl(pSrc, offset, szByte);
}

void TEQSub_Fn9(const void *pSrc, u32 offset, u32 szByte) {
    TEQSub_Fn9Impl(pSrc, offset, szByte);
}

void TEQSub_Fn10(const void *pSrc, u32 offset, u32 szByte) {
    TEQSub_Fn10Impl_Fn12Impl(pSrc, offset, szByte);
}

void TEQSub_Fn11(const void *pSrc, u32 offset, u32 szByte) {
    TEQSub_Fn11Impl_Fn13Impl(pSrc, offset, szByte);
}

void TEQSub_Fn12(const void *pSrc, u32 offset, u32 szByte) {
    TEQSub_Fn10Impl_Fn12Impl(pSrc, offset, szByte);
}

void TEQSub_Fn13(const void *pSrc, u32 offset, u32 szByte) {
    TEQSub_Fn11Impl_Fn13Impl(pSrc, offset, szByte);
}

void j_CopySomePaletteData(const void *pSrc, u32 offset, u32 szByte) {
    CopySomePaletteData(pSrc, offset, szByte);
}

void j_CopyPaletteTop(const void *pSrc, u32 offset, u32 szByte) {
    CopyPaletteTop(pSrc, offset, szByte);
}

void TEQSub_Fn16(const void *pSrc, u32 offset, u32 szByte) {
    GX_BeginLoadOBJExtPltt();
    GX_LoadOBJExtPltt(pSrc, offset, szByte);
    GX_EndLoadOBJExtPltt();
}

void TEQSub_Fn17(const void *pSrc, u32 offset, u32 szByte) {
    GX_BeginLoadBGExtPltt();
    GX_LoadBGExtPltt(pSrc, offset, szByte);
    GX_EndLoadBGExtPltt();
}

void j_CopyToOamA(const void *pSrc, u32 offset, u32 szByte) {
    CopyToOamA(pSrc, offset, szByte);
}

void j_CopySomeTileData(const void *pSrc, u32 offset, u32 szByte) {
    CopyTileDataTop_0(pSrc, offset, szByte);
}

void TEQSub_Fn20(const void *pSrc, u32 offset, u32 szByte) {
    CopyBgData_Bg0_Bottom(pSrc, offset, szByte);
}

void j_CopyTileDataBottom(const void *pSrc, u32 offset, u32 szByte) {
    CopyBgData_Bg1_Bottom(pSrc, offset, szByte);
}

void TEQSub_Fn22(const void *pSrc, u32 offset, u32 szByte) {
    CopyBgData_Bg2_Bottom(pSrc, offset, szByte);
}

void TEQSub_Fn23(const void *pSrc, u32 offset, u32 szByte) {
    CopyBgData_Bg3_Bottom(pSrc, offset, szByte);
}

void TEQSub_Fn24(const void *pSrc, u32 offset, u32 szByte) {
    TEQSub_Fn24Impl(pSrc, offset, szByte);
}

void TEQSub_Fn25(const void *pSrc, u32 offset, u32 szByte) {
    TEQSub_Fn25Impl(pSrc, offset, szByte);
}

void TEQSub_Fn26(const void *pSrc, u32 offset, u32 szByte) {
    TEQSub_Fn26Impl_Fn28Impl(pSrc, offset, szByte);
}

void TEQSub_Fn27(const void *pSrc, u32 offset, u32 szByte) {
    TEQSub_Fn27Impl_Fn29Impl(pSrc, offset, szByte);
}

void TEQSub_Fn28(const void *pSrc, u32 offset, u32 szByte) {
    TEQSub_Fn26Impl_Fn28Impl(pSrc, offset, szByte);
}

void TEQSub_Fn29(const void *pSrc, u32 offset, u32 szByte) {
    TEQSub_Fn27Impl_Fn29Impl(pSrc, offset, szByte);
}

void TEQSub_Fn30(const void *pSrc, u32 offset, u32 szByte) {
    TEQSub_Fn30Impl(pSrc, offset, szByte);
}

void j_CopyPaletteBottom(const void *pSrc, u32 offset, u32 szByte) {
    CopyPaletteBottom(pSrc, offset, szByte);
}

void TEQSub_Fn32(const void *pSrc, u32 offset, u32 szByte) {
    GXS_BeginLoadOBJExtPltt();
    GXS_LoadOBJExtPltt(pSrc, offset, szByte);
    GXS_EndLoadOBJExtPltt();
}

void TEQSub_Fn33(const void *pSrc, u32 offset, u32 szByte) {
    GXS_BeginLoadBGExtPltt();
    GXS_LoadBGExtPltt(pSrc, offset, szByte);
    GXS_EndLoadBGExtPltt();
}

void j_CopyToOamB(const void *pSrc, u32 offset, u32 szByte) {
    CopyToOamB(pSrc, offset, szByte);
}

void TEQSub_Fn35(const void *pSrc, u32 offset, u32 szByte) {
    TEQSub_Fn35Impl(pSrc, offset, szByte);
}

void (*const g_TEQSubFnList[36])(const void *pSrc, u32 offset, u32 szByte) = {
    TEQSub_Fn0,
    TEQSub_Fn1,
    TEQSub_Fn2,
    TEQSub_Fn3,
    TEQSub_Fn4,
    j_CopyTileDataTop,
    TEQSub_Fn6,
    TEQSub_Fn7,
    TEQSub_Fn8,
    TEQSub_Fn9,
    TEQSub_Fn10,
    TEQSub_Fn11,
    TEQSub_Fn12,
    TEQSub_Fn13,
    j_CopySomePaletteData,
    j_CopyPaletteTop,
    TEQSub_Fn16,
    TEQSub_Fn17,
    j_CopyToOamA,
    j_CopySomeTileData,
    TEQSub_Fn20,
    j_CopyTileDataBottom,
    TEQSub_Fn22,
    TEQSub_Fn23,
    TEQSub_Fn24,
    TEQSub_Fn25,
    TEQSub_Fn26,
    TEQSub_Fn27,
    TEQSub_Fn28,
    TEQSub_Fn29,
    TEQSub_Fn30,
    j_CopyPaletteBottom,
    TEQSub_Fn32,
    TEQSub_Fn33,
    j_CopyToOamB,
    TEQSub_Fn35,
};

void StructTEQSub_HandleTEQSub(NNSGfdVramTransferTask *task) {
    void (*transfer)(const void *, u32, u32);

    transfer = g_TEQSubFnList[task->mType];
    Arm_FlushRange(task->mPSrc, task->mSzByte);
    transfer(task->mPSrc, task->mDstAddr, task->mSzByte);
}

void StructTEQ_Initialize(NNSGfdVramTransferTaskQueue *queue) {
    u32 zero;
    zero = 0u;
    queue->mIdxRear = zero;
    queue->mIdxFront = queue->mIdxRear;
    queue->mNumTasks = zero;
    queue->mTotalSize = zero;
}

s32 StructTEQ_ReserveTEQSub(NNSGfdVramTransferTaskQueue *queue) {
    if (StructTEQ_IsTEQSubListFull(queue) != 0) {
        return 0;
    }
    queue->mIdxRear = StructTEQ_IncrementValidateIndex(queue, queue->mIdxRear);
    queue->mNumTasks += 1;
    return 1;
}

NNSGfdVramTransferTask *StructTEQ_GetTopUsedTEQSub(NNSGfdVramTransferTaskQueue *queue) {
    return queue->mPTaskArray + queue->mIdxFront;
}

NNSGfdVramTransferTask *StructTEQ_GetNextFreeTEQSub(NNSGfdVramTransferTaskQueue *queue) {
    return queue->mPTaskArray + queue->mIdxRear;
}

s32 StructTEQ_TryPopTEQSub(NNSGfdVramTransferTaskQueue *queue) {
    if (StructTEQ_IsCounterEmpty(queue) != 0) {
        return 0;
    }
    queue->mIdxFront = StructTEQ_IncrementValidateIndex(queue, queue->mIdxFront);
    queue->mNumTasks -= 1;
    return 1;
}

NNSGfdVramTransferTaskQueue g_GlobalTEQ;

void InitializeGlobalTEQ(NNSGfdVramTransferTask *pTaskArray, u32 lengthOfArray) {
    g_GlobalTEQ.mPTaskArray = pTaskArray;
    g_GlobalTEQ.mLengthOfArray = lengthOfArray;
    StructTEQ_Initialize(&g_GlobalTEQ);
}

void HandleAllGlobalTEQSubs(void) {
    NNSGfdVramTransferTaskQueue *queue;
    NNSGfdVramTransferTask *task;

    queue = &g_GlobalTEQ;
    task = StructTEQ_GetTopUsedTEQSub(queue);
    while (StructTEQ_TryPopTEQSub(queue) != 0) {
        StructTEQSub_HandleTEQSub(task);
        queue->mTotalSize -= task->mSzByte;
        task = StructTEQ_GetTopUsedTEQSub(queue);
    }
}

s32 AllocateReserveTEQSub(u32 type, u32 dstAddr, void *pSrc, u32 szByte) {
    NNSGfdVramTransferTaskQueue *queue;
    NNSGfdVramTransferTask *task;

    queue = &g_GlobalTEQ;
    if (StructTEQ_IsTEQSubListFull(queue) != 0) {
        return 0;
    }
    task = StructTEQ_GetNextFreeTEQSub(queue);
    task->mType = type;
    task->mPSrc = pSrc;
    task->mDstAddr = dstAddr;
    task->mSzByte = szByte;
    StructTEQ_ReserveTEQSub(queue);
    queue->mTotalSize = queue->mTotalSize + task->mSzByte;
    return 1;
}
