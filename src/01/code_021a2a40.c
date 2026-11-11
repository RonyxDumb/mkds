#include "01/code_021a2a40.h"

#include "01/code_02184f7c.h"
#include "Main/Unknown/code_02056700.h"
#include "Main/Unknown/code_020ca670.h"
#include "Main/Unknown/code_020ca820.h"
#include "01/code_021a5140.h"
#include "01/code_021928c8.h"
#include "01/code_02185000.h"
#include "01/code_02184000.h"
#include "01/code_021a6000.h"
#include "01/code_02180ce8.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ac2c4.h"
#include "Main/Unknown/code_020ca000.h"
#include "Main/Unknown/code_020ca69c.h"
#include "Main/Unknown/code_020ca844.h"
#include "Main/Unknown/code_02105000.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_020ac000.h"
#include "code_0212df7c.h"
#include "01/code_02192000.h"
#include "01/code_021a4000.h"
#include "01/code_021a5000.h"
#include "Main/Unknown/code_02076cd0.h"
#include "Main/Unknown/code_02077000.h"
#include "Main/Unknown/code_02110000.h"
#include "Main/Unknown/code_0214a000.h"
#include "code_0214b824.h"
#include "Main/Unknown/code_020aa81c.h"
#include "01/code_02181000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020ca6a8.h"
#include "Main/Unknown/code_021108bc.h"
#include "Main/Unknown/code_02148000.h"
#include "code_0200eddc.h"
#include "gx.h"
#include "code_0214a390.h"
#include "registers.h"

void UploadEmblemMainScreen(void) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x1700;
    reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffcfffef;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 1;
    reg_G2_BG1CNT = reg_G2_BG1CNT & ~3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & 0x43) | 0x400;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & ~3) | 3;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & 0x43) | 0x600;
    DC_FlushRange(gEmblem->mEmblemMONclr->mData, gEmblem->mEmblemMONclr->mDataSize);
    GX_LoadOBJPltt(gEmblem->mEmblemMONclr->mData, 0, gEmblem->mEmblemMONclr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemMONcgr->mData, gEmblem->mEmblemMONcgr->mDataSize);
    GX_LoadOBJ(gEmblem->mEmblemMONcgr->mData, 0, gEmblem->mEmblemMONcgr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemMBNclr->mData, gEmblem->mEmblemMBNclr->mDataSize);
    GX_LoadBGPltt(gEmblem->mEmblemMBNclr->mData, 0, gEmblem->mEmblemMBNclr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemMBNcgr->mData, gEmblem->mEmblemMBNcgr->mDataSize);
    GX_LoadBG1Char((gEmblem->mEmblemMBNcgr->mData), 0, gEmblem->mEmblemMBNcgr->mDataSize);
    DC_FlushRange(gEmblem->mUnk_0a7c, 0x200);
    GX_LoadBG2Char(gEmblem->mUnk_0a7c, 0, 0x200);
    DC_FlushRange(gEmblem->mEmblemMNscr->mData, gEmblem->mEmblemMNscr->mDataSize);
    GX_LoadBG1Scr(gEmblem->mEmblemMNscr->mData, 0, gEmblem->mEmblemMNscr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemMBgNscr->mData, gEmblem->mEmblemMBgNscr->mDataSize);
    GX_LoadBG2Scr(gEmblem->mEmblemMBgNscr->mData, 0, gEmblem->mEmblemMBgNscr->mDataSize);
    reg_G2_BG1OFS = 0;
    reg_G2_BG2OFS = 0;
}

void UploadEmblemSubScreen(void) {
    GXS_SetGraphicsMode(1);
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | 0x1e00;
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~3) | 1;
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & 0x43) | 0x8a10;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 2;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & 0x43) | 0xc10;
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~3) | 3;
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & 0x43) | 0xe10;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 2;
    reg_G2S_DB_BG0OFS = 0;
    reg_G2S_DB_BG1OFS = 0;
    reg_G2S_DB_BG2OFS = 0;
    G2x_SetBGyAffine_(&reg_G2S_DB_BG3PA, gEmblemSubBg3AffineMatrix, 16, 16, -0x70, -0x40);
    DC_FlushRange(gEmblem->mEmblemSONclr->mData, gEmblem->mEmblemSONclr->mDataSize);
    GXS_LoadOBJPltt(gEmblem->mEmblemSONclr->mData, 0, gEmblem->mEmblemSONclr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemSONcgr->mData, gEmblem->mEmblemSONcgr->mDataSize);
    GXS_LoadOBJ(gEmblem->mEmblemSONcgr->mData, 0, gEmblem->mEmblemSONcgr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemSBNclr->mData, gEmblem->mEmblemSBNclr->mDataSize);
    GXS_LoadBGPltt(gEmblem->mEmblemSBNclr->mData, 0, gEmblem->mEmblemSBNclr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemSBNcgr->mData, gEmblem->mEmblemSBNcgr->mDataSize);
    GXS_LoadBG1Char((gEmblem->mEmblemSBNcgr->mData), 0, gEmblem->mEmblemSBNcgr->mDataSize);
    DC_FlushRange(GetEmblemGridCells(), GetEmblemGridCharSize());
    GXS_LoadBG3Char(GetEmblemGridCells(), GetEmblemGridCharOffset(), GetEmblemGridCharSize());
    DC_FlushRange(gEmblem->mEmblemSTemplateFrameNscr->mData, gEmblem->mEmblemSTemplateFrameNscr->mDataSize);
    GXS_LoadBG0Scr(gEmblem->mEmblemSTemplateFrameNscr->mData, 0, gEmblem->mEmblemSTemplateFrameNscr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemSToolNscr->mData, gEmblem->mEmblemSToolNscr->mDataSize);
    GXS_LoadBG1Scr(gEmblem->mEmblemSToolNscr->mData, 0, gEmblem->mEmblemSToolNscr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemSBgNscr->mData, gEmblem->mEmblemSBgNscr->mDataSize);
    GXS_LoadBG2Scr(gEmblem->mEmblemSBgNscr->mData, 0, gEmblem->mEmblemSBgNscr->mDataSize);
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x1010;
    DC_FlushRange(gEmblem->mEmblemSTemplateDarkNscr->mData, gEmblem->mEmblemSTemplateDarkNscr->mDataSize);
    GXS_LoadBG3Scr(gEmblem->mEmblemSTemplateDarkNscr->mData, 0, gEmblem->mEmblemSTemplateDarkNscr->mDataSize);
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x1218;
    DC_FlushRange((const void *) GetEmblemGridScr(), GetEmblemGridScrSize());
    GXS_LoadBG3Scr((const void *) (GetEmblemGridScr()), GetEmblemGridScrOffset(), GetEmblemGridScrSize());
}

void UploadEmblemCameraSubScreen(void) {
    GXS_SetGraphicsMode(1);
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | 0x1600;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 3;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & 0x43) | 0xe10;
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~3) | 3;
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & 0x43) | 0x1010;
    reg_G2S_DB_BG1OFS = 0;
    reg_G2S_DB_BG2OFS = 0;
    reg_G2S_DB_BG3OFS = 0;
    DC_FlushRange(gEmblem->mEmblemSONclr->mData, gEmblem->mEmblemSONclr->mDataSize);
    GXS_LoadOBJPltt(gEmblem->mEmblemSONclr->mData, 0, gEmblem->mEmblemSONclr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemCameraSONcgr->mData, gEmblem->mEmblemCameraSONcgr->mDataSize);
    GXS_LoadOBJ(gEmblem->mEmblemCameraSONcgr->mData, 0, gEmblem->mEmblemCameraSONcgr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemSBNclr->mData, gEmblem->mEmblemSBNclr->mDataSize);
    GXS_LoadBGPltt(gEmblem->mEmblemSBNclr->mData, 0, gEmblem->mEmblemSBNclr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemCameraSBNcgr->mData, gEmblem->mEmblemCameraSBNcgr->mDataSize);
    GXS_LoadBG1Char((gEmblem->mEmblemCameraSBNcgr->mData), 0, gEmblem->mEmblemCameraSBNcgr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemCameraSDSNscr->mData, gEmblem->mEmblemCameraSDSNscr->mDataSize);
    GXS_LoadBG1Scr(gEmblem->mEmblemCameraSDSNscr->mData, 0, gEmblem->mEmblemCameraSDSNscr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemCameraSBgNscr->mData, gEmblem->mEmblemCameraSBgNscr->mDataSize);
    GXS_LoadBG2Scr(gEmblem->mEmblemCameraSBgNscr->mData, 0, gEmblem->mEmblemCameraSBgNscr->mDataSize);
}

void StartEmblemChoises(void) {
    RequestEmblemChoisesGraphicsUpload();
    SetEmblemChoisesShownAndReset(1);
    gEmblem->mUnk_1090 = 10;
    gEmblem->mUnk_1098 = 14;
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 1), -3);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 2), -3);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 3), -3);
}

void StopEmblemChoises(void) {
    SetEmblemChoisesShownAndReset(0);
    gEmblem->mUnk_1090 = 0;
    gEmblem->mUnk_1098 = 15;
    gEmblem->mUnk_10b0 = FALSE;
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 1), -1);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 2), -1);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 3), -1);
}

void StartEmblemTemplateSlideIn(void) {
    gEmblem->mUnk_1090 = 2;
    gEmblem->mUnk_1098 = 2;
    gEmblem->mUnk_10a0 = 0;
    gEmblem->mUnk_10a4 = 32;
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemTemplateSLld, 1), 0);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 1), -3);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 2), -3);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 3), -3);
}

void AdvanceEmblemTemplateSlideIn(void) {
    gEmblem->mUnk_10a0 += gEmblem->mUnk_10a4;
    gEmblem->mUnk_10a4 -= 2;
    if (gEmblem->mUnk_10a0 >= 0xc0) {
        gEmblem->mUnk_10a0 = 0xc0;
        gEmblem->mUnk_1090 = 1;
        gEmblem->mUnk_1098 = 3;
        gEmblem->mUnk_10b0 = FALSE;
    }
    gEmblem->mEmblemTemplateSLld->mOffsetY = gEmblem->mUnk_10a0 - 0xc0;
}

void StartEmblemTemplateSlideOut(void) {
    gEmblem->mUnk_1090 = 3;
    gEmblem->mUnk_1098 = 6;
    gEmblem->mUnk_10a0 = 0xc0;
    gEmblem->mUnk_10a4 = -0x20;
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 1), -1);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 2), -1);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 3), -1);
}

void AdvanceEmblemTemplateSlideOut(void) {
    gEmblem->mUnk_10a0 += gEmblem->mUnk_10a4;
    gEmblem->mUnk_10a4 += 2;
    if (gEmblem->mUnk_10a0 <= 0) {
        gEmblem->mUnk_10a0 = 0;
        gEmblem->mUnk_1090 = 0;
        gEmblem->mUnk_1098 = 7;
        gEmblem->mUnk_10b0 = FALSE;
    }
    gEmblem->mEmblemTemplateSLld->mOffsetY = gEmblem->mUnk_10a0 - 0xc0;
}

void StartEmblemFadeOutToCamera(void) {
    gEmblem->mUnk_1090 = 5;
    gEmblem->mUnk_1098 = 13;
    gEmblem->mUnk_109c = 0;
}

void StartEmblemFadeOutToGrid(void) {
    gEmblem->mUnk_1090 = 7;
    gEmblem->mUnk_1098 = 10;
    gEmblem->mUnk_109c = 0;
    SetKartModelMenuInputSeqs(2, 0);
}

void AdvanceEmblemFadeOutToCamera(void) {
    gEmblem->mUnk_109c += 2;
    if (gEmblem->mUnk_109c > 16) {
        gEmblem->mUnk_109c = 16;
        gEmblem->mUnk_1090 = 6;
        gEmblem->mUnk_1098 = 9;
    }
}

void AdvanceEmblemFadeInAtCamera(void) {
    gEmblem->mUnk_109c -= 2;
    if (gEmblem->mUnk_109c < 0) {
        gEmblem->mUnk_109c = 0;
        gEmblem->mUnk_1090 = 4;
        gEmblem->mUnk_1098 = 11;
        gEmblem->mUnk_10b0 = FALSE;
    }
}

void AdvanceEmblemFadeOutToGrid(void) {
    gEmblem->mUnk_109c += 2;
    if (gEmblem->mUnk_109c > 16) {
        gEmblem->mUnk_109c = 16;
        gEmblem->mUnk_1090 = 8;
        gEmblem->mUnk_1098 = 12;
    }
}

void AdvanceEmblemFadeInAtGrid(void) {
    gEmblem->mUnk_109c -= 2;
    if (gEmblem->mUnk_109c < 0) {
        gEmblem->mUnk_109c = 0;
        gEmblem->mUnk_1090 = 0;
        gEmblem->mUnk_1098 = 8;
        gEmblem->mUnk_10b0 = FALSE;
    }
}

void ActivateEmblemEntry(s32 entryIndex, s32 isTouch) {
    s32 templateByteSize;
    u8 *templateBytes;
    u16 templateCellValues[16];

    switch (gEmblem->mUnk_1090) {
        case 0:
            switch (entryIndex) {
                case 0x1b:
                case 0x1c:
                case 0x1d:
                case 0x1e:
                case 0x1f:
                case 0x20:
                case 0x21:
                case 0x22:
                case 0x23:
                case 0x24:
                case 0x25:
                case 0x26:
                case 0x27:
                case 0x28:
                case 0x29:
                    if (isTouch) {
                        SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 9), 0);
                        SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 10), 0x1000);
                        gEmblem->mUnk_1080 = entryIndex - 0x1b;
                        func_ov001_021a63c0(gEmblem->mUnk_1080 + 1);
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f1);
                    } else {
                        gEmblem->mUnk_1080 = entryIndex - 0x1b;
                        func_ov001_021a5df0((gEmblem->mEmblemSLld), entryIndex);
                        func_ov001_021a63c0(gEmblem->mUnk_1080 + 1);
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f0);
                    }
                    if (func_ov001_021a639c() == 1) {
                        func_ov001_021a5ab0(gEmblem->mEmblemSLld, func_ov001_021a637c() + 0xe);
                        func_ov001_021a63a8(0);
                    }
                    gEmblem->mUnk_1094 = 3;
                    return;
                case 0x2a:
                    if (isTouch) {
                        SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 10), 0x1000);
                    }
                    func_ov001_021a59cc((gEmblem->mEmblemSLld), entryIndex);
                    if (isTouch) {
                        gEmblem->mUnk_1094 = 3;
                        return;
                    }
                    break;
                case 0xe:
                case 0xf:
                case 0x10:
                    func_ov001_021a5ab0((gEmblem->mEmblemSLld), entryIndex);
                    func_ov001_021a63a8(0);
                    func_ov001_021a6388(entryIndex - 0xe);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f2);
                    gEmblem->mUnk_1094 = 3;
                    return;
                case 0x11:
                case 0x12:
                case 0x13:
                    func_ov001_021a5ab0((gEmblem->mEmblemSLld), entryIndex);
                    func_ov001_021a63a8(1);
                    func_ov001_021a6388(entryIndex - 0x11);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f2);
                    gEmblem->mUnk_1094 = 3;
                    return;
                case 0x14:
                    func_ov001_021a5ab0((gEmblem->mEmblemSLld), entryIndex);
                    func_ov001_021a63a8(2);
                    func_ov001_021a6388(0);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f2);
                    gEmblem->mUnk_1094 = 3;
                    return;
                case 0x15:
                    func_ov001_021a5ab0((gEmblem->mEmblemSLld), entryIndex);
                    func_ov001_021a63a8(3);
                    func_ov001_021a6388(0);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f2);
                    gEmblem->mUnk_1094 = 3;
                    return;
                case 0x16:
                    if (gEmblem->mUnk_108c == NULL) {
                        gEmblem->mUnk_108c = StartEmblemTemplateSlideIn;
                        func_ov001_021a5d00((gEmblem->mEmblemSLld), entryIndex);
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f3);
                        gEmblem->mUnk_10b0 = TRUE;
                    }
                    gEmblem->mUnk_1094 = 3;
                    return;
                case 0x17:
                    if (IsEmblemGridChanged()) {
                        if (IsEmblemGridSwapped()) {
                            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1fb);
                        } else {
                            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1fc);
                        }
                        SwapEmblemGridCells();
                        func_ov001_021a5d00((gEmblem->mEmblemSLld), entryIndex);
                    }
                    if (isTouch) {
                        gEmblem->mUnk_1094 = 3;
                        return;
                    }
                    break;
                case 0x19:
                    if (gEmblem->mUnk_108c == NULL) {
                        gEmblem->mUnk_108c = StartEmblemFadeOutToCamera;
                        func_ov001_021a5d00((gEmblem->mEmblemSLld), entryIndex);
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0xc);
                        gEmblem->mUnk_10b0 = TRUE;
                        gEmblem->mUnk_10ac = FALSE;
                    }
                    gEmblem->mUnk_1094 = 3;
                    return;
                case 0x1a:
                    if (gEmblem->mUnk_108c == NULL) {
                        gEmblem->mUnk_108c = StartEmblemChoises;
                        func_ov001_021a5c28((gEmblem->mEmblemSLld), entryIndex);
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 4);
                        gEmblem->mUnk_10b0 = TRUE;
                    }
                    gEmblem->mUnk_1094 = 3;
                    return;
            }
            break;
        case 1:
            switch (entryIndex) {
                case 0:
                    if (gEmblem->mUnk_108c == NULL) {
                        gEmblem->mUnk_108c = StartEmblemTemplateSlideOut;
                        func_ov001_021a5a40((gEmblem->mEmblemTemplateSLld), 1);
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0xe);
                        gEmblem->mUnk_10b0 = TRUE;
                    }
                    gEmblem->mUnk_1094 = 3;
                    return;
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 0xa:
                case 0xb:
                case 0xc:
                case 0xd:
                case 0xe:
                case 0xf:
                case 0x10:
                case 0x11:
                case 0x12:
                case 0x13:
                case 0x14:
                case 0x15:
                case 0x16:
                case 0x17:
                case 0x18:
                case 0x19:
                case 0x1a:
                case 0x1b:
                case 0x1c:
                case 0x1d:
                case 0x1e:
                case 0x1f:
                    if (gEmblem->mUnk_108c == NULL) {
                        templateByteSize = (s32) (GetEmblemGridSide() * GetEmblemGridSide()) / 2;
                        templateBytes =
                            (u8 *) gEmblem->mEmblemTemplateBNcgr->mData + (entryIndex - 3) * templateByteSize;
                        templateCellValues[0] = 0;
                        templateCellValues[1] = (func_ov001_021a63b4() == 1) ? 2 : 1;
                        templateCellValues[2] = func_ov001_021a63b4();
                        SplitBytesIntoNibbles(templateBytes, gEmblem->mUnk_0c7c, GetEmblemGridSide());
                        SetEmblemGridCellsFromTable((gEmblem->mUnk_0c7c), (templateCellValues));
                        ClearEmblemGridCopied();
                        gEmblem->mUnk_108c = StartEmblemTemplateSlideOut;
                        func_ov001_021a5d00((gEmblem->mEmblemTemplateSLld), entryIndex);
                        gEmblem->mUnk_1084 = entryIndex - 3;
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f6);
                    }
                    gEmblem->mUnk_1094 = 3;
                    return;
            }
            break;
        case 4:
            if (entryIndex == 1) {
                if (gEmblem->mUnk_108c == NULL) {
                    gEmblem->mUnk_108c = StartEmblemFadeOutToGrid;
                    func_ov001_021a5d00((gEmblem->mEmblemCameraSLld), entryIndex);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0xc);
                    gEmblem->mUnk_10ac = TRUE;
                }
                gEmblem->mUnk_1094 = 3;
            }
            break;
    }
}

void AdvanceEmblemKartList(void) {
    int kartListNumber;
    int kartListCount;

    kartListNumber = GetKartListNumber();
    kartListCount = GetKartListCount();
    AdvanceKartModelMenuInput();
    if (kartListCount >= 10) {
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 4), 0);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 5), -5);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 6), kartListCount / 10);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 7), kartListCount % 10);
        if (kartListNumber >= 10) {
            ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 1), kartListNumber / 10);
            ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 2), kartListNumber % 10);
        } else {
            ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 1), -5);
            ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 2), kartListNumber);
        }
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 3), -5);
    } else {
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 4), -5);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 5), 0);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 6), -5);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 7), kartListCount);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 1), -5);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 2), -5);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 3), kartListNumber);
    }
}

void AdvanceEmblemGridScreen(void) {
    s32 touchedEntry;
    s32 inputX;
    s32 inputY;
    s32 dx;
    s32 dy;
    s32 dz;
    s32 previousCursor;
    BOOL flag;
    void *buttonCursorEntry;
    void *colorCursorEntry;
    void *targetEntry;

    flag = FALSE;
    if (GetEmblemInputPressed()) {
        inputY = GetEmblemInputY();
        inputX = GetEmblemInputX();
        touchedEntry = FindLldEntryAtPoint(gEmblem->mEmblemSLld, 0, inputX, inputY);
        while (touchedEntry >= 0) {
            ActivateEmblemEntry(touchedEntry, 1);
            inputY = GetEmblemInputY();
            inputX = GetEmblemInputX();
            touchedEntry = FindLldEntryAtPoint(gEmblem->mEmblemSLld, touchedEntry + 1, inputX, inputY);
        }
    }

    if (GetEmblemInputNewBits(8)) {
        ActivateEmblemEntry(0x1a, 0);
    } else if (GetEmblemInputNewBits(4)) {
        ActivateEmblemEntry(0x19, 0);
    } else if (GetEmblemInputNewBits(2)) {
        ActivateEmblemEntry(0x17, 0);
    } else if (GetEmblemInputNewBits(0x800)) {
        ActivateEmblemEntry(0x2a, 0);
    } else {
        buttonCursorEntry = GetLldEntry(gEmblem->mEmblemSLld, 8);
        GetLldEntry(gEmblem->mEmblemSLld, gEmblemButtonLldEntries[gEmblem->mUnk_107c]);
        colorCursorEntry = GetLldEntry(gEmblem->mEmblemSLld, 9);
        GetLldEntry(gEmblem->mEmblemSLld, gEmblemColorLldEntries[gEmblem->mUnk_1080]);
        dx = 0;
        dy = 0;
        dz = 0;
        dx += GetNewOrRepeatBits(8, PAD_KEY_LEFT) ? -1 : 0;
        dx += GetNewOrRepeatBits(8, PAD_KEY_RIGHT) ? 1 : 0;
        dy += GetNewOrRepeatBits(8, PAD_KEY_UP) ? -1 : 0;
        dy += GetNewOrRepeatBits(8, PAD_KEY_DOWN) ? 1 : 0;
        dz += GetNewOrRepeatBits(8, PAD_KEY_L) ? -1 : 0;
        dz += GetNewOrRepeatBits(8, PAD_KEY_R) ? 1 : 0;

        switch (gEmblem->mUnk_1094) {
            case 0:
                ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xb), -5);
                ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xc), 0);
                ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xd), -5);
                if (dz > 0) {
                    gEmblem->mUnk_1094 = 2;
                    gEmblem->mUnk_1080 = func_ov001_021a63b4() - 1;
                    SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 9), 0x1000);
                    SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 10), 0);
                    SetLldEntryCallback(GetLldEntry(gEmblem->mEmblemSLld, 9), NULL);
                    SetLldEntryCallback(GetLldEntry(gEmblem->mEmblemSLld, 10), NULL);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1ee);
                } else if (dz < 0) {
                    gEmblem->mUnk_1094 = 1;
                    switch (func_ov001_021a639c()) {
                        case 0:
                            gEmblem->mUnk_107c = func_ov001_021a637c() + data_ov001_021a6fc8[func_ov001_021a639c()];
                            break;
                        case 1:
                            gEmblem->mUnk_107c = func_ov001_021a637c() + data_ov001_021a6fc8[func_ov001_021a639c()];
                            break;
                        case 2:
                            gEmblem->mUnk_107c = data_ov001_021a6fc8[func_ov001_021a639c()];
                            break;
                        case 3:
                            gEmblem->mUnk_107c = data_ov001_021a6fc8[func_ov001_021a639c()];
                            break;
                    }
                    SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 8), 0x1000);
                    SetLldEntryCallback(GetLldEntry(gEmblem->mEmblemSLld, 8), NULL);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1ee);
                }
                break;
            case 1:
                ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xb), 0);
                ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xc), -5);
                ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xd), -5);
                if (dz < 0) {
                    gEmblem->mUnk_1094 = 2;
                    gEmblem->mUnk_1080 = func_ov001_021a63b4() - 1;
                    SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 9), 0x1000);
                    SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 10), 0);
                    SetLldEntryCallback(GetLldEntry(gEmblem->mEmblemSLld, 9), NULL);
                    SetLldEntryCallback(GetLldEntry(gEmblem->mEmblemSLld, 10), NULL);
                    ApplyLldEntryFrameCommand(buttonCursorEntry, -5);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1ee);
                } else if (dz > 0) {
                    gEmblem->mUnk_1094 = 3;
                    ApplyLldEntryFrameCommand(buttonCursorEntry, -5);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1ee);
                } else if (GetEmblemInputNewBits(1)) {
                    if (gEmblemButtonLldEntries[gEmblem->mUnk_107c] != 0x17 || IsEmblemGridChanged()) {
                        ActivateEmblemEntry(gEmblemButtonLldEntries[gEmblem->mUnk_107c], 0);
                    }
                } else {
                    previousCursor = gEmblem->mUnk_107c;
                    gEmblem->mUnk_107c = gEmblemButtonCursorVerticalMoves[dy + 1][previousCursor];
                    gEmblem->mUnk_107c = gEmblemButtonCursorHorizontalMoves[dx + 1][gEmblem->mUnk_107c];
                    targetEntry = GetLldEntry(gEmblem->mEmblemSLld, gEmblemButtonLldEntries[gEmblem->mUnk_107c]);
                    ApplyLldEntryFrameCommand(buttonCursorEntry, 0);
                    SetLldEntryPos(buttonCursorEntry, GetLldEntryX(targetEntry), GetLldEntryY(targetEntry));
                    if (gEmblem->mUnk_107c != previousCursor) {
                        StartSoundOncePerFrame(0x1ef);
                    }
                }
                func_ov001_021a5f70(0, GetEmblemInputX(), GetEmblemInputY(), 0, 0, 0);
                break;
            case 2:
                ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xb), -5);
                ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xc), -5);
                ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xd), 0);
                if (dz > 0) {
                    gEmblem->mUnk_1094 = 1;
                    switch (func_ov001_021a639c()) {
                        case 0:
                            gEmblem->mUnk_107c = func_ov001_021a637c() + data_ov001_021a6fb8[func_ov001_021a639c()];
                            break;
                        case 1:
                            gEmblem->mUnk_107c = func_ov001_021a637c() + data_ov001_021a6fb8[func_ov001_021a639c()];
                            break;
                        case 2:
                            gEmblem->mUnk_107c = data_ov001_021a6fb8[func_ov001_021a639c()];
                            break;
                        case 3:
                            gEmblem->mUnk_107c = data_ov001_021a6fb8[func_ov001_021a639c()];
                            break;
                    }
                    SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 8), 0x1000);
                    SetLldEntryCallback(GetLldEntry(gEmblem->mEmblemSLld, 8), NULL);
                    SetLldEntryScale(colorCursorEntry, 0);
                    SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 10), 0x1000);
                    gEmblem->mUnk_1080 = func_ov001_021a63b4() - 1;
                    ApplyLldEntryFrameCommand(colorCursorEntry, -5);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1ee);
                } else if (dz < 0) {
                    gEmblem->mUnk_1094 = 3;
                    SetLldEntryScale(colorCursorEntry, 0);
                    SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 10), 0x1000);
                    gEmblem->mUnk_1080 = func_ov001_021a63b4() - 1;
                    ApplyLldEntryFrameCommand(colorCursorEntry, -5);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1ee);
                } else if (GetEmblemInputNewBits(1)) {
                    ActivateEmblemEntry(gEmblemColorLldEntries[gEmblem->mUnk_1080], 0);
                } else {
                    previousCursor = gEmblem->mUnk_1080;
                    gEmblem->mUnk_1080 = gEmblemColorCursorVerticalMoves[dy + 1][previousCursor];
                    gEmblem->mUnk_1080 = gEmblemColorCursorHorizontalMoves[dx + 1][gEmblem->mUnk_1080];
                    GetLldEntry(gEmblem->mEmblemSLld, gEmblemColorLldEntries[gEmblem->mUnk_1080]);
                    if (gEmblem->mUnk_1080 < 0xf) {
                        ApplyLldEntryFrameCommand(colorCursorEntry, 0);
                    } else {
                        ApplyLldEntryFrameCommand(colorCursorEntry, -5);
                    }
                    if (gEmblem->mUnk_1080 != previousCursor) {
                        StartSoundOncePerFrame(0x1ef);
                    }
                }
                func_ov001_021a5f70(0, GetEmblemInputX(), GetEmblemInputY(), 0, 0, 0);
                break;
        }
    }

    if (GetEmblemInputPressed() && IsEmblemPointInGrid(GetEmblemInputX(), GetEmblemInputY())) {
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xb), -5);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xc), 0);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xd), -5);
        gEmblem->mUnk_1080 = func_ov001_021a63b4() - 1;
        if (GetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 9)) == 0x1000) {
            SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 9), 0);
            SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 10), 0x1000);
        }
        if (GetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 8)) == 0x1000) {
            SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 8), 0);
        }
        gEmblem->mUnk_1094 = 0;
    } else if (gEmblem->mUnk_1094 == 3) {
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xb), -5);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xc), 0);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xd), -5);
        gEmblem->mUnk_1080 = func_ov001_021a63b4() - 1;
        if (GetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 9)) == 0x1000) {
            SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 9), 0);
            SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 10), 0x1000);
        }
        if (GetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 8)) == 0x1000) {
            SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 8), 0);
        }
        if (!GetEmblemInputDown() && !GetEmblemInputBits(1) && !GetEmblemInputBits(2)) {
            gEmblem->mUnk_1094 = 0;
        }
    }

    if (gEmblem->mUnk_1094 == 0) {
        dx = 0;
        dy = 0;
        dx += IsEmblemInputRepeat(0x20) ? -1 : 0;
        dx += IsEmblemInputRepeat(0x10) ? 1 : 0;
        dy += IsEmblemInputRepeat(0x40) ? -1 : 0;
        dy += IsEmblemInputRepeat(0x80) ? 1 : 0;
        if (func_ov001_021a5f70(GetEmblemInputDown(), GetEmblemInputX(), GetEmblemInputY(), GetEmblemInputBits(1), dx,
                                dy)) {
            if (func_ov001_021a639c() == 3) {
                gEmblem->mUnk_1080 = func_ov001_021a63b4() - 1;
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f4);
            } else if (func_ov001_021a639c() == 2) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f5);
            }
        } else if (GetEmblemInputBits(0x400)) {
            flag = TRUE;
            if (func_ov001_021a6278()) {
                gEmblem->mUnk_1080 = func_ov001_021a63b4() - 1;
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f4);
            }
        }
        if (GetEmblemInputDown() && !GetEmblemInputPrevDown() &&
            IsEmblemPointInGrid(GetEmblemInputX(), GetEmblemInputY())) {
            gEmblem->mUnk_10b8 = TRUE;
        } else if (GetEmblemInputDown() &&
                   (IsEmblemPointInGrid(GetEmblemInputX(), GetEmblemInputY()) ||
                    IsEmblemPointInGrid(GetEmblemInputPrevX(), GetEmblemInputPrevY())) &&
                   (func_ov001_021a633c() != func_ov001_021a6314() || func_ov001_021a6328() != func_ov001_021a6300())) {
            gEmblem->mUnk_10b8 = TRUE;
        } else if (GetEmblemInputNewBits(1)) {
            gEmblem->mUnk_10b8 = TRUE;
        } else if (GetEmblemInputBits(1) &&
                   (func_ov001_021a633c() != func_ov001_021a6314() || func_ov001_021a6328() != func_ov001_021a6300())) {
            gEmblem->mUnk_10b8 = TRUE;
        }
    } else {
        func_ov001_021a5f70(0, GetEmblemInputX(), GetEmblemInputY(), 0, 0, 0);
    }

    SetLldEntryPos(GetLldEntry(gEmblem->mEmblemSLld, 0), func_ov001_021a633c(), func_ov001_021a6328());
    SetLldEntryPos(GetLldEntry(gEmblem->mEmblemSLld, 1), func_ov001_021a633c(), func_ov001_021a6328());
    SetLldEntryPos(GetLldEntry(gEmblem->mEmblemSLld, 2), func_ov001_021a633c(), func_ov001_021a6328());
    SetLldEntryPos(GetLldEntry(gEmblem->mEmblemSLld, 3), func_ov001_021a633c(), func_ov001_021a6328());

    if (gEmblem->mUnk_1094 == 0 && GetEmblemInputDown() && IsEmblemPointInGrid(GetEmblemInputX(), GetEmblemInputY())) {
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0), -5);
        gEmblem->mUnk_1088 = -1;
    } else if (gEmblem->mUnk_1094 == 0 && GetEmblemInputDown() &&
               GetLldEntryFrameIndex(GetLldEntry(gEmblem->mEmblemSLld, 0)) == -5) {
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0), -5);
        gEmblem->mUnk_1088 = -1;
    } else {
        gEmblem->mUnk_1088 = func_ov001_021a637c();
        if (flag) {
            ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0), 3);
        } else {
            switch (func_ov001_021a639c()) {
                case 0:
                    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0), 0);
                    break;
                case 2:
                    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0), 1);
                    break;
                case 1:
                    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0), 2);
                    break;
                case 3:
                    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0), 3);
                    break;
            }
        }
    }

    switch (gEmblem->mUnk_1088) {
        case 0:
            ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 1), -4);
            ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 2), -5);
            ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 3), -5);
            break;
        case 1:
            ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 1), -5);
            ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 2), -4);
            ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 3), -5);
            break;
        case 2:
            ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 1), -5);
            ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 2), -5);
            ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 3), -4);
            break;
    }

    targetEntry = GetLldEntry(gEmblem->mEmblemSLld, gEmblemColorLldEntries[gEmblem->mUnk_1080]);
    SetLldEntryPos(GetLldEntry(gEmblem->mEmblemSLld, 9), GetLldEntryX(targetEntry), GetLldEntryY(targetEntry));
    SetLldEntryPos(GetLldEntry(gEmblem->mEmblemSLld, 10), GetLldEntryX(targetEntry), GetLldEntryY(targetEntry));

    if (gEmblem->mUnk_1080 < 0xf) {
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 4), -5);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 5), -5);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 6), -5);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 7), -5);
    } else {
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 4), 0);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 5), 0);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 6), 0);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 7), 0);
    }

    if (IsEmblemGridChanged() && GetLldEntryFrameIndex(GetLldEntry(gEmblem->mEmblemSLld, 0x17)) == 2) {
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0x17), 0);
    }
}

void AdvanceEmblemTemplateScreen(void) {
    void *templateCursorEntry;
    void *templateEntry;
    s32 touchedEntry;
    s32 horizontalStep;
    s32 verticalStep;
    s32 colorStep;
    s32 sel;
    s32 u;
    s32 t;
    u32 inputY;
    s32 inputX;
    void *colorEntry;
    void *colorCursorEntry;

    if (GetEmblemInputPressed() != 0) {
        inputY = GetEmblemInputY();
        inputX = GetEmblemInputX();
        touchedEntry = FindLldEntryAtPoint(gEmblem->mEmblemTemplateSLld, 0, inputX, inputY);
        while (touchedEntry >= 0) {
            ActivateEmblemEntry(touchedEntry, 1);
            inputY = GetEmblemInputY();
            inputX = GetEmblemInputX();
            touchedEntry = FindLldEntryAtPoint(gEmblem->mEmblemTemplateSLld, touchedEntry + 1, inputX, inputY);
        }
    }
    if (GetEmblemInputNewBits(1) != 0) {
        ActivateEmblemEntry(gEmblemTemplateLldEntries[gEmblem->mUnk_1084], 0);
        return;
    }
    if (GetEmblemInputNewBits(2) != 0) {
        ActivateEmblemEntry(0, 0);
        return;
    }
    horizontalStep = 0;
    verticalStep = 0;
    colorStep = 0;
    horizontalStep += (GetNewOrRepeatBits(8, PAD_KEY_LEFT) != 0) ? -1 : 0;
    horizontalStep += (GetNewOrRepeatBits(8, PAD_KEY_RIGHT) != 0) ? 1 : 0;
    verticalStep += (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) ? -1 : 0;
    verticalStep += (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0) ? 1 : 0;
    colorStep += (GetNewOrRepeatBits(8, PAD_KEY_L) != 0) ? -1 : 0;
    colorStep += (GetNewOrRepeatBits(8, PAD_KEY_R) != 0) ? 1 : 0;
    gEmblem->mUnk_1080 = colorStep + (func_ov001_021a63b4() - 1);
    t = gEmblem->mUnk_1080;
    if (t < 0) {
        t = 0xe;
    }
    gEmblem->mUnk_1080 = t;
    u = gEmblem->mUnk_1080;
    if (u > 0xe) {
        u = 0;
    }
    gEmblem->mUnk_1080 = u;
    sel = gEmblem->mUnk_1080;
    if (sel != func_ov001_021a63b4() - 1) {
        colorEntry = GetLldEntry(gEmblem->mEmblemSLld, gEmblemTemplateScreenColorEntries[sel]);
        colorCursorEntry = GetLldEntry(gEmblem->mEmblemSLld, 9);
        SetLldEntryPos(colorCursorEntry, GetLldEntryX(colorEntry), GetLldEntryY(colorEntry));
        colorCursorEntry = GetLldEntry(gEmblem->mEmblemSLld, 10);
        SetLldEntryPos(colorCursorEntry, GetLldEntryX(colorEntry), GetLldEntryY(colorEntry));
        func_ov001_021a63c0(gEmblem->mUnk_1080 + 1);
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f1);
    }
    sel = gEmblem->mUnk_1084;
    gEmblem->mUnk_1084 = gEmblemTemplateCursorVerticalMoves[verticalStep + 1][sel];
    gEmblem->mUnk_1084 = gEmblemTemplateCursorHorizontalMoves[horizontalStep + 1][gEmblem->mUnk_1084];
    templateCursorEntry = GetLldEntry(gEmblem->mEmblemTemplateSLld, 2);
    templateEntry = GetLldEntry(gEmblem->mEmblemTemplateSLld, gEmblemTemplateLldEntries[gEmblem->mUnk_1084]);
    ApplyLldEntryFrameCommand(templateCursorEntry, 0);
    SetLldEntryPos(templateCursorEntry, GetLldEntryX(templateEntry), GetLldEntryY(templateEntry));
    if (gEmblem->mUnk_1084 != sel) {
        StartSoundOncePerFrame(0x1ef);
    }
    {
        s32 templateIndex;
        void *entryAtIndex;

        for (templateIndex = 0; templateIndex < 0x1d; templateIndex++) {
            entryAtIndex = GetLldEntry(gEmblem->mEmblemTemplateSLld, gEmblemTemplateLldEntries[templateIndex]);
            ApplyLldEntryFrameCommand(entryAtIndex, templateIndex == gEmblem->mUnk_1084 ? 1 : 0);
        }
    }
}

void AdvanceEmblemCameraScreen(void) {
    s32 touchedEntry;
    u32 inputY;
    s32 inputX;

    if (GetEmblemInputPressed() != 0) {
        inputY = GetEmblemInputY();
        inputX = GetEmblemInputX();
        touchedEntry = FindLldEntryAtPoint(gEmblem->mEmblemCameraSLld, 0, inputX, inputY);
        while (touchedEntry >= 0) {
            ActivateEmblemEntry(touchedEntry, 1);
            inputY = GetEmblemInputY();
            inputX = GetEmblemInputX();
            touchedEntry = FindLldEntryAtPoint(gEmblem->mEmblemCameraSLld, touchedEntry + 1, inputX, inputY);
        }
    }
    if (GetEmblemInputNewBits(4) != 0) {
        ActivateEmblemEntry(1, 0);
    }
}

void AdvanceEmblemChoisesScreen(void) {
    s32 choisesResult;

    choisesResult = GetEmblemChoisesResult();
    switch (choisesResult) {
        case -2:
        case 0:
            StopEmblemChoises();
            break;
        case 1:
            SetEmblemChoisesShownAndReset(0);
            JoinNibbleTilesIntoBytes(GetEmblemGridCells(), gEmblem->mUnk_087c, GetEmblemGridSide());
            SetEmblemRecordAndWriteBackup(gEmblem->mUnk_087c);
            gEmblem->mUnk_1090 = 0xb;
            gEmblem->mUnk_1098 = 1;
            break;
        case 2:
            SetEmblemChoisesShownAndReset(0);
            gEmblem->mUnk_1090 = 0xb;
            gEmblem->mUnk_1098 = 1;
            break;
    }
    UpdateEmblemChoises();
    WriteEmblemChoisesScreenMapWrapper();
}

void AdvanceEmblem(void) {
    s32 t;

    AdvanceEmblemInput();
    gEmblem->mUnk_10a8 += 0x4cd;
    t = gEmblem->mUnk_10a8;
    if (t >= 0x100000) {
        t -= 0x100000;
    }
    gEmblem->mUnk_10a8 = t;
    ClearOamListCounts(gEmblem, &gEmblem->mUnk_0404);
    AdvanceLld(gEmblem->mEmblemMLld, &gEmblem->mUnk_0000);
    switch (gEmblem->mUnk_1090) {
        case 0:
            if (gEmblem->mUnk_10b0 == FALSE) {
                AdvanceEmblemGridScreen();
            }
            AdvanceLld(gEmblem->mEmblemSLld, &gEmblem->mUnk_0404);
            break;
        case 1:
            if (gEmblem->mUnk_10b0 == FALSE) {
                AdvanceEmblemTemplateScreen();
            }
            AdvanceLld(gEmblem->mEmblemTemplateSLld, &gEmblem->mUnk_0404);
            AdvanceLld(gEmblem->mEmblemSLld, &gEmblem->mUnk_0404);
            break;
        case 2:
            AdvanceEmblemTemplateSlideIn();
            AdvanceLld(gEmblem->mEmblemTemplateSLld, &gEmblem->mUnk_0404);
            AdvanceLld(gEmblem->mEmblemSLld, &gEmblem->mUnk_0404);
            break;
        case 3:
            AdvanceEmblemTemplateSlideOut();
            AdvanceLld(gEmblem->mEmblemTemplateSLld, &gEmblem->mUnk_0404);
            AdvanceLld(gEmblem->mEmblemSLld, &gEmblem->mUnk_0404);
            break;
        case 4:
            if (gEmblem->mUnk_10ac == FALSE) {
                AdvanceEmblemKartList();
            }
            if (gEmblem->mUnk_10b0 == FALSE) {
                AdvanceEmblemCameraScreen();
            }
            AdvanceLld(gEmblem->mEmblemCameraSLld, &gEmblem->mUnk_0404);
            break;
        case 5:
            if (gEmblem->mUnk_10ac == FALSE) {
                AdvanceEmblemKartList();
            }
            AdvanceEmblemFadeOutToCamera();
            AdvanceLld(gEmblem->mEmblemSLld, &gEmblem->mUnk_0404);
            break;
        case 6:
            if (gEmblem->mUnk_10ac == FALSE) {
                AdvanceEmblemKartList();
            }
            AdvanceEmblemFadeInAtCamera();
            AdvanceLld(gEmblem->mEmblemCameraSLld, &gEmblem->mUnk_0404);
            break;
        case 7:
            if (gEmblem->mUnk_10b0 == FALSE) {
                AdvanceEmblemGridScreen();
            }
            AdvanceEmblemFadeOutToGrid();
            AdvanceLld(gEmblem->mEmblemCameraSLld, &gEmblem->mUnk_0404);
            break;
        case 8:
            if (gEmblem->mUnk_10b0 == FALSE) {
                AdvanceEmblemGridScreen();
            }
            AdvanceEmblemFadeInAtGrid();
            AdvanceLld(gEmblem->mEmblemSLld, &gEmblem->mUnk_0404);
            break;
        case 10:
            AdvanceEmblemChoisesScreen();
            AdvanceLld(gEmblem->mEmblemSLld, &gEmblem->mUnk_0404);
            break;
        case 11:
            AdvanceLld(gEmblem->mEmblemSLld, &gEmblem->mUnk_0404);
            if (gBackupBuffers->mBusy == 0) {
                if (gBackupAccess->mBackupEnabled != 0) {
                    t = gBackupAccess->mCommandRunning;
                } else {
                    t = 0;
                }
            } else {
                t = 1;
            }
            if (t == 0) {
                gEmblem->mUnk_1090 = 0xc;
            }
            break;
        case 12:
            AdvanceLld(gEmblem->mEmblemSLld, &gEmblem->mUnk_0404);
            break;
    }
    HideUnusedOams(gEmblem, &gEmblem->mUnk_0404);
    AdvanceShownSlotAndQueueEmblem();
    DrawKartModelMenuUnmirrored();
    JoinNibbleTilesIntoBytes(GetEmblemGridCells(), gEmblem->mUnk_087c, GetEmblemGridSide());
    JoinNibblesIntoBytes(GetEmblemGridCells(), gEmblem->mUnk_0a7c, GetEmblemGridSide());
}
