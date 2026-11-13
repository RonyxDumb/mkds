#include "03/System/pointer_stack.h"
#include "03/code_021d1d88.h"
#include "03/System/exp_heap.h"
#include "03/code_021d1d60.h"
#include "03/code_021d1d4c.h"
#include "code_0200c914.h"
#include "code_0200fc8c.h"
#include "code_02147cd8.h"

PointerStack *CreatePointerStack(u32 count) {
    PointerStack *list = AllocExpHeapBlock((count + 1) * 4 + 8, 4);

    list->mSlotCount = count + 1;
    list->mBottomIndex = 0;
    list->mTopIndex = 0;
    return list;
}

PointerStack *CreateFilledPointerStack(s32 count, void *buffer, s32 stride) {
    u8 *entry = buffer;
    PointerStack *list = CreatePointerStack(count);
    s32 index;

    for (index = 0; index < count; index++) {
        list->mPointers[index] = entry;
        entry += stride;
    }
    list->mTopIndex = count;
    return list;
}

void DeletePointerStack(void *block, ...) {
    FreeExpHeapBlockAndClearPointer(&block);
}

void PushPointerStack(PointerStack *stack, void *pointer) {
    u32 interrupts = OS_DisableIrqMask(1);
    u32 newTop = FX_ModS32(stack->mTopIndex + 1, stack->mSlotCount);

    if (newTop == stack->mBottomIndex) {
        OS_Terminate();
    }
    stack->mPointers[stack->mTopIndex] = pointer;
    stack->mTopIndex = newTop;
    OS_EnableIrqMask(interrupts);
}

void *PopPointerStack(PointerStack *stack) {
    void *pointer = NULL;
    u32 interrupts = OS_DisableIrqMask(1);
    u8 top = stack->mTopIndex;

    if (stack->mBottomIndex != top) {
        stack->mTopIndex = FX_ModS32(top + stack->mSlotCount - 1, stack->mSlotCount);
        pointer = stack->mPointers[stack->mTopIndex];
    }
    OS_EnableIrqMask(interrupts);
    return pointer;
}
