#include "gxasm.h"

// clang-format off
// Sends the twelve words at pSrc, three at a time, all to the one address pDest (no update of pDest).
// Kept as asm: it reads with `ldm r0!` into r2, r3 and ip and stores them with `stm r1`.
asm void GX_SendFifo48B(const void *pSrc, void *pDest) {
    ldmia r0!, {r2, r3, ip}
    stmia r1, {r2, r3, ip}
    ldmia r0!, {r2, r3, ip}
    stmia r1, {r2, r3, ip}
    ldmia r0!, {r2, r3, ip}
    stmia r1, {r2, r3, ip}
    ldmia r0!, {r2, r3, ip}
    stmia r1, {r2, r3, ip}
    bx lr
}

// Sends the sixteen words at pSrc, eight at a time, all to the one address pDest (no update of pDest).
// Kept as asm: it saves r4-r8 without lr and without a padding word, and copies eight registers at a time with
// `ldm r0!` / `stm r1`.
asm void GX_SendFifo64B(const void *pSrc, void *pDest) {
    stmfd sp!, {r4, r5, r6, r7, r8}
    ldmia r0!, {r2, r3, r4, r5, r6, r7, r8, ip}
    stmia r1, {r2, r3, r4, r5, r6, r7, r8, ip}
    ldmia r0!, {r2, r3, r4, r5, r6, r7, r8, ip}
    stmia r1, {r2, r3, r4, r5, r6, r7, r8, ip}
    ldmfd sp!, {r4, r5, r6, r7, r8}
    bx lr
}
// clang-format on
