#include "fx_mtx44.h"
#include "code_021479b4.h"

void MTX_Concat44(const MtxFx44 *lhs, const MtxFx44 *rhs, MtxFx44 *product) {
    MtxFx44 scratch;
    MtxFx44 *result;
    s32 lhsRow0;
    s32 lhsRow1;
    s32 lhsRow2;
    s32 lhsRow3;
    s32 rhsColumn0;
    s32 rhsColumn1;
    s32 rhsColumn2;
    s32 rhsColumn3;

    result = product;
    if (result == rhs) {
        result = &scratch;
    }
    lhsRow0 = lhs->mRows[0].x;
    lhsRow1 = lhs->mRows[0].y;
    lhsRow2 = lhs->mRows[0].z;
    lhsRow3 = lhs->mRows[0].wComponent;
    result->mRows[0].x = DOT4_FIXED12(lhsRow0, rhs->mRows[0].x, lhsRow1, rhs->mRows[1].x, lhsRow2, rhs->mRows[2].x,
                                      lhsRow3, rhs->mRows[3].x);
    result->mRows[0].y = DOT4_FIXED12(lhsRow0, rhs->mRows[0].y, lhsRow1, rhs->mRows[1].y, lhsRow2, rhs->mRows[2].y,
                                      lhsRow3, rhs->mRows[3].y);
    result->mRows[0].wComponent = DOT4_FIXED12(lhsRow0, rhs->mRows[0].wComponent, lhsRow1, rhs->mRows[1].wComponent,
                                               lhsRow2, rhs->mRows[2].wComponent, lhsRow3, rhs->mRows[3].wComponent);
    rhsColumn0 = rhs->mRows[0].z;
    rhsColumn1 = rhs->mRows[1].z;
    rhsColumn2 = rhs->mRows[2].z;
    rhsColumn3 = rhs->mRows[3].z;
    result->mRows[0].z =
        DOT4_FIXED12(lhsRow0, rhsColumn0, lhsRow1, rhsColumn1, lhsRow2, rhsColumn2, lhsRow3, rhsColumn3);
    lhsRow0 = lhs->mRows[1].x;
    lhsRow1 = lhs->mRows[1].y;
    lhsRow2 = lhs->mRows[1].z;
    lhsRow3 = lhs->mRows[1].wComponent;
    result->mRows[1].z =
        DOT4_FIXED12(lhsRow0, rhsColumn0, lhsRow1, rhsColumn1, lhsRow2, rhsColumn2, lhsRow3, rhsColumn3);
    result->mRows[1].y = DOT4_FIXED12(lhsRow0, rhs->mRows[0].y, lhsRow1, rhs->mRows[1].y, lhsRow2, rhs->mRows[2].y,
                                      lhsRow3, rhs->mRows[3].y);
    result->mRows[1].wComponent = DOT4_FIXED12(lhsRow0, rhs->mRows[0].wComponent, lhsRow1, rhs->mRows[1].wComponent,
                                               lhsRow2, rhs->mRows[2].wComponent, lhsRow3, rhs->mRows[3].wComponent);
    rhsColumn0 = rhs->mRows[0].x;
    rhsColumn1 = rhs->mRows[1].x;
    rhsColumn2 = rhs->mRows[2].x;
    rhsColumn3 = rhs->mRows[3].x;
    result->mRows[1].x =
        DOT4_FIXED12(lhsRow0, rhsColumn0, lhsRow1, rhsColumn1, lhsRow2, rhsColumn2, lhsRow3, rhsColumn3);
    lhsRow0 = lhs->mRows[2].x;
    lhsRow1 = lhs->mRows[2].y;
    lhsRow2 = lhs->mRows[2].z;
    lhsRow3 = lhs->mRows[2].wComponent;
    result->mRows[2].x =
        DOT4_FIXED12(lhsRow0, rhsColumn0, lhsRow1, rhsColumn1, lhsRow2, rhsColumn2, lhsRow3, rhsColumn3);
    result->mRows[2].y = DOT4_FIXED12(lhsRow0, rhs->mRows[0].y, lhsRow1, rhs->mRows[1].y, lhsRow2, rhs->mRows[2].y,
                                      lhsRow3, rhs->mRows[3].y);
    result->mRows[2].wComponent = DOT4_FIXED12(lhsRow0, rhs->mRows[0].wComponent, lhsRow1, rhs->mRows[1].wComponent,
                                               lhsRow2, rhs->mRows[2].wComponent, lhsRow3, rhs->mRows[3].wComponent);
    rhsColumn0 = rhs->mRows[0].z;
    rhsColumn1 = rhs->mRows[1].z;
    rhsColumn2 = rhs->mRows[2].z;
    rhsColumn3 = rhs->mRows[3].z;
    result->mRows[2].z =
        DOT4_FIXED12(lhsRow0, rhsColumn0, lhsRow1, rhsColumn1, lhsRow2, rhsColumn2, lhsRow3, rhsColumn3);
    lhsRow0 = lhs->mRows[3].x;
    lhsRow1 = lhs->mRows[3].y;
    lhsRow2 = lhs->mRows[3].z;
    lhsRow3 = lhs->mRows[3].wComponent;
    result->mRows[3].z =
        DOT4_FIXED12(lhsRow0, rhsColumn0, lhsRow1, rhsColumn1, lhsRow2, rhsColumn2, lhsRow3, rhsColumn3);
    result->mRows[3].y = DOT4_FIXED12(lhsRow0, rhs->mRows[0].y, lhsRow1, rhs->mRows[1].y, lhsRow2, rhs->mRows[2].y,
                                      lhsRow3, rhs->mRows[3].y);
    result->mRows[3].x = DOT4_FIXED12(lhsRow0, rhs->mRows[0].x, lhsRow1, rhs->mRows[1].x, lhsRow2, rhs->mRows[2].x,
                                      lhsRow3, rhs->mRows[3].x);
    result->mRows[3].wComponent = DOT4_FIXED12(lhsRow0, rhs->mRows[0].wComponent, lhsRow1, rhs->mRows[1].wComponent,
                                               lhsRow2, rhs->mRows[2].wComponent, lhsRow3, rhs->mRows[3].wComponent);
    if (result == &scratch) {
        *product = scratch;
    }
}

asm void MTX_Identity44_(MtxFx44 *dst) {
    mov r2, #0x1000
    mov r3, #0
    stmia r0!, {r2, r3}
    mov r1, #0
    stmia r0!, {r1, r3}
    stmia r0!, {r1, r2, r3}
    stmia r0!, {r1, r3}
    stmia r0!, {r1, r2, r3}
    stmia r0!, {r1, r3}
    stmia r0!, {r1, r2}
    bx lr
}

// Copies the first three words of each of the four rows of the 4x4 matrix at src to dst (a 4x3 matrix).
asm void MTX_Copy44To43_(const MtxFx44 *src, MtxFx43 *dst) {
    ldmia r0!, {r2, r3, ip}
    add r0, r0, #4
    stmia r1!, {r2, r3, ip}
    ldmia r0!, {r2, r3, ip}
    add r0, r0, #4
    stmia r1!, {r2, r3, ip}
    ldmia r0!, {r2, r3, ip}
    add r0, r0, #4
    stmia r1!, {r2, r3, ip}
    ldmia r0!, {r2, r3, ip}
    add r0, r0, #4
    stmia r1!, {r2, r3, ip}
    bx lr
}
// clang-format on
