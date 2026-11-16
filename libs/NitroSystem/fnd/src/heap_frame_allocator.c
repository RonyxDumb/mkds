#include "heap_frame_allocator.h"
#include "print_memory_multibyte_write.h"
#include "00/Lib/DWC/access_point_manager.h"

// Sets up a frame heap over startAddress to endAddress with nothing allocated.
NNSiFndHeapHead *Mem_Frame_Initialize(void *startAddress, void *endAddress, u16 optFlag) {
    NNSiFndHeapHead *heap;
    NNSiFndFrmHeapHead *frmHeap;

    heap = startAddress;
    frmHeap = FRAME_HEAP_HEAD(heap);
    Mem_InitializeHeapHead(heap, HEAP_SIGNATURE_FRAME_HEAP, frmHeap + 1, endAddress, optFlag);
    frmHeap->mHeadAllocator = heap->mHeapStart;
    frmHeap->mTailAllocator = heap->mHeapEnd;
    frmHeap->mState = 0;
    return heap;
}

// Takes size bytes from the front of the free memory, aligned to alignment, and returns them or NULL.
void *Mem_Frame_AllocFromHead(NNSiFndFrmHeapHead *frmHeap, u32 size, int alignment) {
    u32 mask;
    u32 start;
    u32 end;
    u32 oldHead;
    u32 clearSize;

    oldHead = (u32) frmHeap->mHeadAllocator;
    mask = alignment - 1;
    start = (mask + oldHead) & ~mask;
    end = size + start;
    if (end > (u32) frmHeap->mTailAllocator) {
        return 0;
    }
    clearSize = end - oldHead;
    {
        volatile u32 zero;

        if ((u16) (((NNSiFndHeapHead *) frmHeap - 1)->mAttribute & HEAP_OPTION_FLAG_MASK) & 1) {
            zero = 0;
            MIi_CpuClear32(zero, (void *) oldHead, clearSize);
        }
    }
    frmHeap->mHeadAllocator = (u8 *) end;
    return (void *) start;
}

// Takes size bytes from the end of the free memory, aligned to alignment, and returns them or NULL.
void *Mem_Frame_AllocFromTail(NNSiFndFrmHeapHead *frmHeap, u32 size, int alignment) {
    u32 mask;
    u8 *oldTail;
    u8 *start;
    u32 clearSize;

    oldTail = frmHeap->mTailAllocator;
    mask = alignment - 1;
    start = (u8 *) (((u32) oldTail - size) & ~mask);
    if (start < frmHeap->mHeadAllocator) {
        return 0;
    }
    clearSize = oldTail - start;
    {
        volatile u32 zero;

        if ((u16) (((NNSiFndHeapHead *) frmHeap - 1)->mAttribute & HEAP_OPTION_FLAG_MASK) & 1) {
            zero = 0;
            MIi_CpuClear32(zero, start, clearSize);
        }
    }
    frmHeap->mTailAllocator = start;
    return start;
}

// Frees everything taken from the front of the heap and drops the recorded states.
void Mem_Frame_ResetFromHead(NNSiFndHeapHead *heap) {
    NNSiFndFrmHeapHead *frmHeap;

    frmHeap = FRAME_HEAP_HEAD(heap);
    frmHeap->mHeadAllocator = heap->mHeapStart;
    frmHeap->mState = 0;
}

// Frees everything taken from the back of the heap, also in the recorded states.
void Mem_Frame_ResetFromTail(NNSiFndHeapHead *heap) {
    NNSiFndFrmHeapState *state;
    NNSiFndFrmHeapHead *frmHeap;

    frmHeap = FRAME_HEAP_HEAD(heap);
    state = frmHeap->mState;
    if (state != 0) {
        do {
            state->mTailAllocator = heap->mHeapEnd;
            state = state->mPrevState;
        } while (state != 0);
    }
    frmHeap->mTailAllocator = heap->mHeapEnd;
}

// Sets up a frame heap in the memory of size bytes at startAddress, or returns NULL when it is too small.
NNSFndHeapHandle Mem_Frame_Create(void *startAddress, u32 size, u16 optFlag) {
    void *bufferEnd;

    bufferEnd = (void *) ((size + (u32) startAddress) & ~3);
    startAddress = (void *) (((u32) startAddress + 3) & ~3);
    if (startAddress > bufferEnd || (u32) bufferEnd - (u32) startAddress < 0x30) {
        return 0;
    }
    return Mem_Frame_Initialize(startAddress, bufferEnd, optFlag);
}

// Takes the heap out of the heap list; its memory stays with the caller.
void Mem_Frame_Finalize(NNSFndHeapHandle heap) {
    Mem_FinalizeHeapHead(heap);
}

// Allocates size bytes, rounded up to a multiple of 4 and at least 4, from the front of the heap, or from the back when
// alignment is negative.
void *Mem_Frame_Allocate(NNSFndHeapHandle heap, u32 size, int alignment) {
    NNSiFndFrmHeapHead *frmHeap;

    frmHeap = FRAME_HEAP_HEAD(heap);
    if (size == 0) {
        size = 1;
    }
    size = (size + 3) & ~3;
    if (alignment >= 0) {
        return Mem_Frame_AllocFromHead(frmHeap, size, alignment);
    }
    return Mem_Frame_AllocFromTail(frmHeap, size, -alignment);
}

// Frees the front of the heap for bit 0 of mode and the back for bit 1.
void Mem_ResetFrameHeap(NNSFndHeapHandle heap, int mode) {
    if (mode & 1) {
        Mem_Frame_ResetFromHead(heap);
    }
    if (mode & 2) {
        Mem_Frame_ResetFromTail(heap);
    }
}

// Returns the size of the largest block that can be allocated with the given alignment (its sign is ignored).
u32 Mem_Frame_GetAllocatableSize(NNSFndHeapHandle heap, int alignment) {
    u32 mask;
    u8 *start;
    u8 *tail;
    NNSiFndFrmHeapHead *frmHeap;

    mask = abs(alignment);
    frmHeap = FRAME_HEAP_HEAD(heap);
    tail = frmHeap->mTailAllocator;
    start = (u8 *) (((mask - 1) + (u32) frmHeap->mHeadAllocator) & ~(mask - 1));
    if (start > tail) {
        return 0;
    }
    return tail - start;
}

// Records both allocation positions under tagName in a 16-byte entry taken from the front; returns 0 when there is no
// room for it.
BOOL Mem_CreateFrameHeapState(NNSFndHeapHandle heap, u32 tagName) {
    u8 *oldHead;
    NNSiFndFrmHeapState *state;
    NNSiFndFrmHeapHead *frmHeap;

    frmHeap = FRAME_HEAP_HEAD(heap);
    oldHead = frmHeap->mHeadAllocator;
    state = Mem_Frame_AllocFromHead(frmHeap, 0x10, 4);
    if (state == 0) {
        return 0;
    }
    state->mTagName = tagName;
    state->mHeadAllocator = oldHead;
    state->mTailAllocator = frmHeap->mTailAllocator;
    state->mPrevState = frmHeap->mState;
    frmHeap->mState = state;
    return 1;
}

// Goes back to the state recorded under tagName, or to the newest one when tagName is 0; returns 0 when there is none.
BOOL Mem_RestoreFrameHeapState(NNSFndHeapHandle heap, u32 tagName) {
    NNSiFndFrmHeapState *state;
    NNSiFndFrmHeapHead *frmHeap;

    frmHeap = FRAME_HEAP_HEAD(heap);
    state = frmHeap->mState;
    if (tagName != 0 && state != 0) {
        do {
            if (state->mTagName == tagName) {
                break;
            }
            state = state->mPrevState;
        } while (state != 0);
    }
    if (state == 0) {
        return 0;
    }
    frmHeap->mHeadAllocator = state->mHeadAllocator;
    frmHeap->mTailAllocator = state->mTailAllocator;
    frmHeap->mState = state->mPrevState;
    return 1;
}

// Cuts the end of the heap back to the allocated front and returns the new size of the heap; returns 0 when memory is
// allocated from the back.
u32 Mem_Frame_SomeFn4(NNSFndHeapHandle heap) {
    NNSiFndFrmHeapHead *frmHeap;

    frmHeap = FRAME_HEAP_HEAD(heap);
    if (heap->mHeapEnd - frmHeap->mTailAllocator != 0) {
        return 0;
    }
    heap->mHeapEnd = frmHeap->mHeadAllocator;
    frmHeap->mTailAllocator = heap->mHeapEnd;
    return heap->mHeapEnd - (u8 *) heap;
}
