#include "g2d_CharCanvas.h"
#include "code_0214d018.h"
#include "Main/Menu/menu_label_cell_rows.h"
#include "code_02022aa8.h"
#include "Main/Graphics/cell_file_set.h"

void NNSi_G2dTextCanvasDrawString(TextCanvas *pTxn, s32 drawX, s32 drawY, u32 cl, u16 *str, u16 **pPos) {
    s32 hSpace;
    NNSG2dFont *font;
    u16 *pos;
    SplitCharFunc *readChar;
    u16 code;

    hSpace = pTxn->mCharSpacing;
    font = pTxn->mFont;
    pos = str;
    readChar = font->mCbCharSpliter;
    code = readChar(&pos);
    if (code != 0) {
        do {
            if (code == 10) {
                break;
            }
            drawX += NNS_G2dCharCanvasDrawChar(pTxn->mCharCanvas, font, drawX, drawY, cl, code);
            drawX += hSpace;
            code = readChar(&pos);
        } while (code != 0);
    }
    if (pPos != 0) {
        *pPos = code == 10 ? pos : 0;
    }
}

void NNSi_G2dTextCanvasDrawTextAlign(TextCanvas *pTxn, s32 drawX, s32 drawY, s32 areaWidth, u32 cl, u32 flags,
                                     u16 *txt) {
    s32 lineHeight;
    s32 lineWidth;
    s32 lineX;
    u32 alignRight;
    u32 alignCenter;
    s32 halfWidth;
    u16 *pos;

    lineHeight = pTxn->mLineSpacing + ((NNSG2dFont *) pTxn->mFont)->mPRes->mLinefeed;
    pos = txt;
    if (pos == 0) {
        return;
    }
    alignRight = flags & 0x800;
    alignCenter = flags & 0x400;
    halfWidth = (areaWidth + 1) / 2;
    do {
        lineX = drawX;
        if (alignRight != 0) {
            lineWidth = NNSi_G2dFontGetStringWidth(pTxn->mFont, pTxn->mCharSpacing, (u8 *) pos, 0);
            lineX = drawX + (areaWidth - lineWidth);
        } else if (alignCenter != 0) {
            lineWidth = NNSi_G2dFontGetStringWidth(pTxn->mFont, pTxn->mCharSpacing, (u8 *) pos, 0);
            lineX = drawX + (halfWidth - (lineWidth + 1) / 2);
        }
        NNSi_G2dTextCanvasDrawString(pTxn, lineX, drawY, cl, pos, &pos);
        drawY += lineHeight;
    } while (pos != 0);
}

u32 NNSi_G2dTextCanvasDrawText(TextCanvas *pTxn, s32 drawX, s32 drawY, u32 cl, u32 flags, void *txt) {
    NNSG2dTextRect rect;

    NNSi_G2dFontGetTextRect(&rect, pTxn->mFont, pTxn->mCharSpacing, pTxn->mLineSpacing, txt);
    if (flags & 0x10) {
        drawX -= (rect.mWidth + 1) / 2;
    } else if (flags & 0x20) {
        drawX -= rect.mWidth;
    }
    if (flags & 2) {
        drawY -= (rect.mHeight + 1) / 2;
    } else if (flags & 4) {
        drawY -= rect.mHeight;
    }
    NNSi_G2dTextCanvasDrawTextAlign(pTxn, drawX, drawY, rect.mWidth, cl, flags, txt);
}

void NNSi_G2dTextCanvasDrawTextRect(TextCanvas *pTxn, s32 drawX, s32 drawY, s32 areaWidth, s32 areaHeight, s32 cl,
                                    u32 flags, u16 *txt) {
    s32 textHeight;

    if (flags & 0x100) {
        textHeight = NNSi_G2dFontGetTextHeight(pTxn->mFont, pTxn->mLineSpacing, (u8 *) txt);
        drawY += areaHeight - textHeight;
    } else if (flags & 0x80) {
        textHeight = NNSi_G2dFontGetTextHeight(pTxn->mFont, pTxn->mLineSpacing, (u8 *) txt);
        drawY += (areaHeight + 1) / 2 - (textHeight + 1) / 2;
    }
    NNSi_G2dTextCanvasDrawTextAlign(pTxn, drawX, drawY, areaWidth, cl, flags, txt);
}

// clang-format off
// Written as assembly because it uses clz.
asm u32 GetCharIndex1D(u32 cx, u32 cy, u32 areaWidth, u32 areaHeight, u32 objWidth, u32 objHeight) {
    stmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    sub sp, sp, #0x4
    ldr r11, =objs
    mov r9, #0x0
    mov r10, #0x3
    mvn r7, #0x0
loop_top:
    ldr r4, [sp, #0x2c]
    ldr r6, [sp, #0x28]
    and ip, r3, r7, lsl r4
    cmp ip, r1
    mov r8, r7, lsl r6
    mov r5, r7, lsl r4
    and lr, r2, r7, lsl r6
    bhi d_masked_above
    mla r9, r2, ip, r9
    cmp lr, r0
    movhi r2, lr
    subhi r1, r1, ip
    subhi r3, r3, ip
    bhi next_sizes
    sub r3, r3, ip
    mla r9, lr, r3, r9
    sub r0, r0, lr
    sub r1, r1, ip
    sub r2, r2, lr
    b next_sizes
d_masked_above:
    cmp lr, r0
    mlals r9, lr, ip, r9
    mvn r3, r5
    movls r3, ip
    subls r0, r0, lr
    subls r2, r2, lr
    bls next_sizes
    and r2, r1, r5
    mla r5, lr, r2, r9
    and r2, r0, r8
    and r1, r1, r3
    add r2, r5, r2, lsl r4
    mvn r3, r8
    add r1, r2, r1, lsl r6
    and r0, r0, r3
    add sp, sp, #0x4
    add r0, r1, r0
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    bx lr
next_sizes:
    cmp r2, #0x8
    movlt r4, r2
    movge r5, r10
    clzlt r4, r4
    rsblt r5, r4, #0x1f
    cmp r3, #0x8
    movge r4, r10
    movlt r4, r3
    clzlt r4, r4
    rsblt r4, r4, #0x1f
    add r4, r11, r4, lsl #0x3
    add r6, r4, r5, lsl #0x1
    ldrb r5, [r4, r5, lsl #0x1]
    ldrb r4, [r6, #0x1]
    str r5, [sp, #0x28]
    str r4, [sp, #0x2c]
    b loop_top
    add sp, sp, #0x4
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    bx lr
}// clang-format on
