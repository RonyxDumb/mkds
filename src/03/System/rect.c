#include "03/System/rect.h"
#include "03/types_021d299c.h"
#include "03/unk_021d6000.h"

const Rect gTouchScreenRect = {0, 0, 0x100, 0xc0};

void SetPosition(u16 positionX, u16 positionY, u16 *output) {
    *output = positionX;
    output[1] = positionY;
}

void SetRectCorners(s32 left, s32 top, s32 right, s32 bottom, u16 *corners) {
    *corners = left;
    corners[1] = top;
    corners[2] = right;
    corners[3] = bottom;
}

void ComputeRectFromOriginAndSize(const u16 *origin, const u16 *size, Rect *rect) {
    rect->mX = *origin;
    rect->mY = origin[1];
    rect->mUnk_04 = *origin + *size;
    rect->mUnk_06 = origin[1] + size[1];
}
