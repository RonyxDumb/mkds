#include "code_021479b4.h"

// Multiplies the 4x4 matrices a and b and writes the product to ab; ab may be the same as a or b.
void MTX_Concat44(const MtxFx44 *a, const MtxFx44 *b, MtxFx44 *ab) {
    MtxFx44 tmp;
    MtxFx44 *result;
    s32 x0;
    s32 x1;
    s32 x2;
    s32 x3;
    s32 y0;
    s32 y1;
    s32 y2;
    s32 y3;

    result = ab;
    if (result == b) {
        result = &tmp;
    }
    x0 = a->mUnk_00[0].x;
    x1 = a->mUnk_00[0].y;
    x2 = a->mUnk_00[0].z;
    x3 = a->mUnk_00[0].w;
    result->mUnk_00[0].x = ((s64) x0 * b->mUnk_00[0].x + (s64) x1 * b->mUnk_00[1].x + (s64) x2 * b->mUnk_00[2].x +
                            (s64) x3 * b->mUnk_00[3].x) >>
                           12;
    result->mUnk_00[0].y = ((s64) x0 * b->mUnk_00[0].y + (s64) x1 * b->mUnk_00[1].y + (s64) x2 * b->mUnk_00[2].y +
                            (s64) x3 * b->mUnk_00[3].y) >>
                           12;
    result->mUnk_00[0].w = ((s64) x0 * b->mUnk_00[0].w + (s64) x1 * b->mUnk_00[1].w + (s64) x2 * b->mUnk_00[2].w +
                            (s64) x3 * b->mUnk_00[3].w) >>
                           12;
    y0 = b->mUnk_00[0].z;
    y1 = b->mUnk_00[1].z;
    y2 = b->mUnk_00[2].z;
    y3 = b->mUnk_00[3].z;
    result->mUnk_00[0].z = ((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2 + (s64) x3 * y3) >> 12;
    x0 = a->mUnk_00[1].x;
    x1 = a->mUnk_00[1].y;
    x2 = a->mUnk_00[1].z;
    x3 = a->mUnk_00[1].w;
    result->mUnk_00[1].z = ((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2 + (s64) x3 * y3) >> 12;
    result->mUnk_00[1].y = ((s64) x0 * b->mUnk_00[0].y + (s64) x1 * b->mUnk_00[1].y + (s64) x2 * b->mUnk_00[2].y +
                            (s64) x3 * b->mUnk_00[3].y) >>
                           12;
    result->mUnk_00[1].w = ((s64) x0 * b->mUnk_00[0].w + (s64) x1 * b->mUnk_00[1].w + (s64) x2 * b->mUnk_00[2].w +
                            (s64) x3 * b->mUnk_00[3].w) >>
                           12;
    y0 = b->mUnk_00[0].x;
    y1 = b->mUnk_00[1].x;
    y2 = b->mUnk_00[2].x;
    y3 = b->mUnk_00[3].x;
    result->mUnk_00[1].x = ((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2 + (s64) x3 * y3) >> 12;
    x0 = a->mUnk_00[2].x;
    x1 = a->mUnk_00[2].y;
    x2 = a->mUnk_00[2].z;
    x3 = a->mUnk_00[2].w;
    result->mUnk_00[2].x = ((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2 + (s64) x3 * y3) >> 12;
    result->mUnk_00[2].y = ((s64) x0 * b->mUnk_00[0].y + (s64) x1 * b->mUnk_00[1].y + (s64) x2 * b->mUnk_00[2].y +
                            (s64) x3 * b->mUnk_00[3].y) >>
                           12;
    result->mUnk_00[2].w = ((s64) x0 * b->mUnk_00[0].w + (s64) x1 * b->mUnk_00[1].w + (s64) x2 * b->mUnk_00[2].w +
                            (s64) x3 * b->mUnk_00[3].w) >>
                           12;
    y0 = b->mUnk_00[0].z;
    y1 = b->mUnk_00[1].z;
    y2 = b->mUnk_00[2].z;
    y3 = b->mUnk_00[3].z;
    result->mUnk_00[2].z = ((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2 + (s64) x3 * y3) >> 12;
    x0 = a->mUnk_00[3].x;
    x1 = a->mUnk_00[3].y;
    x2 = a->mUnk_00[3].z;
    x3 = a->mUnk_00[3].w;
    result->mUnk_00[3].z = ((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2 + (s64) x3 * y3) >> 12;
    result->mUnk_00[3].y = ((s64) x0 * b->mUnk_00[0].y + (s64) x1 * b->mUnk_00[1].y + (s64) x2 * b->mUnk_00[2].y +
                            (s64) x3 * b->mUnk_00[3].y) >>
                           12;
    result->mUnk_00[3].x = ((s64) x0 * b->mUnk_00[0].x + (s64) x1 * b->mUnk_00[1].x + (s64) x2 * b->mUnk_00[2].x +
                            (s64) x3 * b->mUnk_00[3].x) >>
                           12;
    result->mUnk_00[3].w = ((s64) x0 * b->mUnk_00[0].w + (s64) x1 * b->mUnk_00[1].w + (s64) x2 * b->mUnk_00[2].w +
                            (s64) x3 * b->mUnk_00[3].w) >>
                           12;
    if (result == &tmp) {
        *ab = tmp;
    }
}
