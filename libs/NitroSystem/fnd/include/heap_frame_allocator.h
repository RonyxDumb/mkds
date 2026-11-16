#pragma once

#include "types.h"
#include "heap_list_common_head.h" // NNSiFndHeapHead, NNSFndHeapHandle

// A state recorded in a frame heap: the tag name and both allocation positions, chained through mPrevState.
typedef struct NNSiFndFrmHeapState {
    /* 00 */ u32 mTagName;
    /* 04 */ u8 *mHeadAllocator;
    /* 08 */ u8 *mTailAllocator;
    /* 0c */ struct NNSiFndFrmHeapState *mPrevState;
} NNSiFndFrmHeapState;

// Follows the NNSiFndHeapHead of a frame heap: the two addresses that Mem_Frame_AllocFromHead and Mem_Frame_AllocFromTail move towards
// each other, and the newest recorded state.
typedef struct NNSiFndFrmHeapHead {
    /* 00 */ u8 *mHeadAllocator;
    /* 04 */ u8 *mTailAllocator;
    /* 08 */ NNSiFndFrmHeapState *mState;
} NNSiFndFrmHeapHead;

// The frame heap head sits right after the common head.
#define FRAME_HEAP_HEAD(heap) ((NNSiFndFrmHeapHead *) ((heap) + 1))

u32 Mem_Frame_SomeFn4(NNSFndHeapHandle heap);
BOOL Mem_RestoreFrameHeapState(NNSFndHeapHandle heap, u32 tagName);
BOOL Mem_CreateFrameHeapState(NNSFndHeapHandle heap, u32 tagName);
u32 Mem_Frame_GetAllocatableSize(NNSFndHeapHandle heap, int alignment);
void Mem_ResetFrameHeap(NNSFndHeapHandle heap, int mode);
void *Mem_Frame_Allocate(NNSFndHeapHandle heap, u32 size, int alignment);
void Mem_Frame_Finalize(NNSFndHeapHandle heap);
NNSFndHeapHandle Mem_Frame_Create(void *startAddress, u32 size, u16 optFlag);
void Mem_Frame_ResetFromTail(NNSiFndHeapHead *heap);
// Also clears the recorded states.
void Mem_Frame_ResetFromHead(NNSiFndHeapHead *heap);
void *Mem_Frame_AllocFromTail(NNSiFndFrmHeapHead *frmHeap, u32 size, int alignment);
void *Mem_Frame_AllocFromHead(NNSiFndFrmHeapHead *frmHeap, u32 size, int alignment);
NNSiFndHeapHead *Mem_Frame_Initialize(void *startAddress, void *endAddress, u16 optFlag);
