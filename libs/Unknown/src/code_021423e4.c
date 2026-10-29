#pragma avoid_byte all

#include "code_021423e4.h"
#include "code_02004dc0.h"
#include "Main/Unknown/unk_0217e000.h"

// non-matching: tail jump to func_0214240c (a load of the address and bx ip)
void func_02142590(void) {
    func_0214240c();
}

Unk0217ee98 *func_02142584(void) {
    return &data_0217eeb8;
}

u32 *func_02142578(void) {
    return &data_0217eeb4;
}

void func_02142540(void) {
    void (**p)(void);

    for (p = data_usa_02161748; p != 0 && *p != 0; p++) {
        (*p)();
    }
}

void func_021424e8(void) {
    Unk02005210 *n;

    n = data_0217eeb0;
    if (n == 0) {
        return;
    }
    do {
        data_0217eeb0 = n->mUnk_00;
        ((void (*)(void *, s32)) n->mUnk_04)(n->mUnk_08, -1);
        n = data_0217eeb0;
    } while (n != 0);
}

s32 func_0214245c(s32 a, u8 *b, u32 *c) {
    u32 i;
    u32 n;

    n = *c;
    for (i = 0; i < n; i++) {
        b[i] = (u8) func_021423f8();
        if (b[i] == 13 || b[i] == 10) {
            *c = i + 1;
            break;
        }
    }
    return 0;
}

s32 func_02142424(s32 a, const u8 *b, const u32 *c) {
    u32 i;
    u32 n;

    n = *c;
    for (i = 0; i < n; i++) {
        func_021423e4(b + i);
    }
    return 0;
}

s32 func_0214241c(void) {
    return 0;
}

// non-matching: the original is a supervisor call (swi 0x123456 with r0 = 24, r1 = 0) that C cannot express
void func_0214240c(void) {
}

// non-matching: the original is a supervisor call (swi 0x123456 with r0 = 7, r1 = 0) that C cannot express
u32 func_021423f8(void) {
    return 0;
}

// non-matching: the original is a supervisor call (swi 0x123456 with r0 = 3, r1 = a) that C cannot express
void func_021423e4(const void *a) {
}
