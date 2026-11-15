#pragma avoid_byte all

#include "code_021423e4.h"
#include "code_02004dc0.h"
#include "Main/System/runtime_locks_stdio_buffers.h"
#include "stream.h"
#include "code_0212d214.h"

u32 gFloatStatus;
struct MWiDestructorChain *gGlobalDestructorChain;
FloatTrapTable gFloatTrapTable;

void ExitViaSwi(void) {
    SwiCall24();
}

FloatTrapTable *GetFloatTrapTable(void) {
    return &gFloatTrapTable;
}

u32 *GetFloatStatus(void) {
    return &gFloatStatus;
}

void __call_static_initializers(void) {
    void (**initializer)(void);

    for (initializer = gStaticInitializers; initializer != 0 && *initializer != 0; initializer++) {
        (*initializer)();
    }
}

void RunListNodeCallbacks(void) {
    MWiDestructorChain *node;

    node = gGlobalDestructorChain;
    if (node == 0) {
        return;
    }
    do {
        gGlobalDestructorChain = node->mNext;
        ((void (*)(void *, s32)) node->mDtor)(node->mObj, -1);
        node = gGlobalDestructorChain;
    } while (node != 0);
}

s32 SwiReadBytes(s32 fileHandle, u8 *buffer, u32 *countPtr) {
    u32 index;
    u32 capacity;

    capacity = *countPtr;
    for (index = 0; index < capacity; index++) {
        buffer[index] = SwiReadByte();
        if (buffer[index] == 13 || buffer[index] == 10) {
            *countPtr = index + 1;
            break;
        }
    }
    return 0;
}

s32 SwiWriteBytes(s32 fileHandle, const u8 *buffer, const u32 *countPtr) {
    u32 index;
    u32 count;

    count = *countPtr;
    for (index = 0; index < count; index++) {
        SwiWriteByte(buffer + index);
    }
    return 0;
}

s32 SwiCloseFile(void) {
    return 0;
}

// clang-format off
// Makes supervisor call 0x123456 with r0 = 3 and r1 = a; SwiWriteBytes calls it once per byte of a buffer, with the
// byte's address.
// Kept as asm: swi, and it saves lr alone with a single store and returns by loading pc.
asm void SwiWriteByte(const void *bytePtr) {
    str lr, [sp, #-4]!
    mov r1, r0
    mov r0, #3
    swi 0x123456
    ldr pc, [sp], #4
}

// Makes supervisor call 0x123456 with r0 = 7 and r1 = 0 and returns its r0; SwiReadBytes stores the low byte of each
// result into a buffer.
// Kept as asm: swi, and the same one-word frame and return as SwiWriteByte.
asm u32 SwiReadByte(void) {
    str lr, [sp, #-4]!
    mov r1, #0
    mov r0, #7
    swi 0x123456
    ldr pc, [sp], #4
}

// Makes supervisor call 0x123456 with r0 = 24 and r1 = 0, then returns.
// Kept as asm: swi, and it returns with `mov pc, lr`.
asm void SwiCall24(void) {
    mov r1, #0
    mov r0, #24
    swi 0x123456
    mov pc, lr
}
// clang-format on
