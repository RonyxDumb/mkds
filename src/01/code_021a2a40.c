#include "01/code_021a2a40.h"

#include "01/code_02184f7c.h"
#include "Main/Save/mission_record.h"
#include "Main/Menu/emblem_choises_shown.h"
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
#include "Main/Graphics/nibbles_join.h"
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
#include "Main/Kart/kart_model_menu.h"
#include "Main/Unknown/code_02077000.h"
#include "Main/Unknown/code_02110000.h"
#include "Main/Unknown/code_0214a000.h"
#include "gx_load2d.h"
#include "Main/Unknown/code_020aa81c.h"
#include "01/code_02181000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020ca6a8.h"
#include "Main/Sound/race_end_seq.h"
#include "Main/Unknown/code_02148000.h"
#include "code_0200eddc.h"
#include "gx.h"
#include "g2.h"
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
    DC_FlushRange(gEmblem->mGridCharBytes, 0x200);
    GX_LoadBG2Char(gEmblem->mGridCharBytes, 0, 0x200);
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
    gEmblem->mState = 10;
    gEmblem->mDisplayState = 14;
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 1), -3);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 2), -3);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 3), -3);
}

void StopEmblemChoises(void) {
    SetEmblemChoisesShownAndReset(0);
    gEmblem->mState = 0;
    gEmblem->mDisplayState = 15;
    gEmblem->mTransitionRunning = FALSE;
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 1), -1);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 2), -1);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 3), -1);
}

void StartEmblemTemplateSlideIn(void) {
    gEmblem->mState = 2;
    gEmblem->mDisplayState = 2;
    gEmblem->mTemplateSlideOffset = 0;
    gEmblem->mTemplateSlideSpeed = 32;
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemTemplateSLld, 1), 0);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 1), -3);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 2), -3);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 3), -3);
}

void AdvanceEmblemTemplateSlideIn(void) {
    gEmblem->mTemplateSlideOffset += gEmblem->mTemplateSlideSpeed;
    gEmblem->mTemplateSlideSpeed -= 2;
    if (gEmblem->mTemplateSlideOffset >= 0xc0) {
        gEmblem->mTemplateSlideOffset = 0xc0;
        gEmblem->mState = 1;
        gEmblem->mDisplayState = 3;
        gEmblem->mTransitionRunning = FALSE;
    }
    gEmblem->mEmblemTemplateSLld->mOffsetY = gEmblem->mTemplateSlideOffset - 0xc0;
}

void StartEmblemTemplateSlideOut(void) {
    gEmblem->mState = 3;
    gEmblem->mDisplayState = 6;
    gEmblem->mTemplateSlideOffset = 0xc0;
    gEmblem->mTemplateSlideSpeed = -0x20;
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 1), -1);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 2), -1);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 3), -1);
}

void AdvanceEmblemTemplateSlideOut(void) {
    gEmblem->mTemplateSlideOffset += gEmblem->mTemplateSlideSpeed;
    gEmblem->mTemplateSlideSpeed += 2;
    if (gEmblem->mTemplateSlideOffset <= 0) {
        gEmblem->mTemplateSlideOffset = 0;
        gEmblem->mState = 0;
        gEmblem->mDisplayState = 7;
        gEmblem->mTransitionRunning = FALSE;
    }
    gEmblem->mEmblemTemplateSLld->mOffsetY = gEmblem->mTemplateSlideOffset - 0xc0;
}

void StartEmblemFadeOutToCamera(void) {
    gEmblem->mState = 5;
    gEmblem->mDisplayState = 13;
    gEmblem->mFadeLevel = 0;
}

void StartEmblemFadeOutToGrid(void) {
    gEmblem->mState = 7;
    gEmblem->mDisplayState = 10;
    gEmblem->mFadeLevel = 0;
    SetKartModelMenuInputSeqs(2, 0);
}

void AdvanceEmblemFadeOutToCamera(void) {
    gEmblem->mFadeLevel += 2;
    if (gEmblem->mFadeLevel > 16) {
        gEmblem->mFadeLevel = 16;
        gEmblem->mState = 6;
        gEmblem->mDisplayState = 9;
    }
}

void AdvanceEmblemFadeInAtCamera(void) {
    gEmblem->mFadeLevel -= 2;
    if (gEmblem->mFadeLevel < 0) {
        gEmblem->mFadeLevel = 0;
        gEmblem->mState = 4;
        gEmblem->mDisplayState = 11;
        gEmblem->mTransitionRunning = FALSE;
    }
}

void AdvanceEmblemFadeOutToGrid(void) {
    gEmblem->mFadeLevel += 2;
    if (gEmblem->mFadeLevel > 16) {
        gEmblem->mFadeLevel = 16;
        gEmblem->mState = 8;
        gEmblem->mDisplayState = 12;
    }
}

void AdvanceEmblemFadeInAtGrid(void) {
    gEmblem->mFadeLevel -= 2;
    if (gEmblem->mFadeLevel < 0) {
        gEmblem->mFadeLevel = 0;
        gEmblem->mState = 0;
        gEmblem->mDisplayState = 8;
        gEmblem->mTransitionRunning = FALSE;
    }
}

void ActivateEmblemEntry(s32 entryIndex, s32 isTouch) {
    s32 templateByteSize;
    u8 *templateBytes;
    u16 templateCellValues[16];

    switch (gEmblem->mState) {
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
                        gEmblem->mColorCursorIndex = entryIndex - 0x1b;
                        SetEmblemCursorCellValue(gEmblem->mColorCursorIndex + 1);
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f1);
                    } else {
                        gEmblem->mColorCursorIndex = entryIndex - 0x1b;
                        StartEmblemColorCursorShrinkAndGrow((gEmblem->mEmblemSLld), entryIndex);
                        SetEmblemCursorCellValue(gEmblem->mColorCursorIndex + 1);
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f0);
                    }
                    if (GetEmblemCursorMode() == 1) {
                        StartEmblemModeButtonPress(gEmblem->mEmblemSLld, GetEmblemCursorSizeIndex() + 0xe);
                        SetEmblemCursorMode(0);
                    }
                    gEmblem->mCursorTargetState = 3;
                    return;
                case 0x2a:
                    if (isTouch) {
                        SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 10), 0x1000);
                    }
                    StartEmblemButtonBounceAndToggle((gEmblem->mEmblemSLld), entryIndex);
                    if (isTouch) {
                        gEmblem->mCursorTargetState = 3;
                        return;
                    }
                    break;
                case 0xe:
                case 0xf:
                case 0x10:
                    StartEmblemModeButtonPress((gEmblem->mEmblemSLld), entryIndex);
                    SetEmblemCursorMode(0);
                    SetEmblemCursorSizeIndex(entryIndex - 0xe);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f2);
                    gEmblem->mCursorTargetState = 3;
                    return;
                case 0x11:
                case 0x12:
                case 0x13:
                    StartEmblemModeButtonPress((gEmblem->mEmblemSLld), entryIndex);
                    SetEmblemCursorMode(1);
                    SetEmblemCursorSizeIndex(entryIndex - 0x11);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f2);
                    gEmblem->mCursorTargetState = 3;
                    return;
                case 0x14:
                    StartEmblemModeButtonPress((gEmblem->mEmblemSLld), entryIndex);
                    SetEmblemCursorMode(2);
                    SetEmblemCursorSizeIndex(0);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f2);
                    gEmblem->mCursorTargetState = 3;
                    return;
                case 0x15:
                    StartEmblemModeButtonPress((gEmblem->mEmblemSLld), entryIndex);
                    SetEmblemCursorMode(3);
                    SetEmblemCursorSizeIndex(0);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f2);
                    gEmblem->mCursorTargetState = 3;
                    return;
                case 0x16:
                    if (gEmblem->mPendingTransitionFunc == NULL) {
                        gEmblem->mPendingTransitionFunc = StartEmblemTemplateSlideIn;
                        StartEmblemButtonBounceThenWait((gEmblem->mEmblemSLld), entryIndex);
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f3);
                        gEmblem->mTransitionRunning = TRUE;
                    }
                    gEmblem->mCursorTargetState = 3;
                    return;
                case 0x17:
                    if (IsEmblemGridChanged()) {
                        if (IsEmblemGridSwapped()) {
                            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1fb);
                        } else {
                            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1fc);
                        }
                        SwapEmblemGridCells();
                        StartEmblemButtonBounceThenWait((gEmblem->mEmblemSLld), entryIndex);
                    }
                    if (isTouch) {
                        gEmblem->mCursorTargetState = 3;
                        return;
                    }
                    break;
                case 0x19:
                    if (gEmblem->mPendingTransitionFunc == NULL) {
                        gEmblem->mPendingTransitionFunc = StartEmblemFadeOutToCamera;
                        StartEmblemButtonBounceThenWait((gEmblem->mEmblemSLld), entryIndex);
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0xc);
                        gEmblem->mTransitionRunning = TRUE;
                        gEmblem->mKartListSkipped = FALSE;
                    }
                    gEmblem->mCursorTargetState = 3;
                    return;
                case 0x1a:
                    if (gEmblem->mPendingTransitionFunc == NULL) {
                        gEmblem->mPendingTransitionFunc = StartEmblemChoises;
                        StartEmblemButtonBounce((gEmblem->mEmblemSLld), entryIndex);
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 4);
                        gEmblem->mTransitionRunning = TRUE;
                    }
                    gEmblem->mCursorTargetState = 3;
                    return;
            }
            break;
        case 1:
            switch (entryIndex) {
                case 0:
                    if (gEmblem->mPendingTransitionFunc == NULL) {
                        gEmblem->mPendingTransitionFunc = StartEmblemTemplateSlideOut;
                        StartEmblemButtonHold((gEmblem->mEmblemTemplateSLld), 1);
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0xe);
                        gEmblem->mTransitionRunning = TRUE;
                    }
                    gEmblem->mCursorTargetState = 3;
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
                    if (gEmblem->mPendingTransitionFunc == NULL) {
                        templateByteSize = (s32) (GetEmblemGridSide() * GetEmblemGridSide()) / 2;
                        templateBytes =
                            (u8 *) gEmblem->mEmblemTemplateBNcgr->mData + (entryIndex - 3) * templateByteSize;
                        templateCellValues[0] = 0;
                        templateCellValues[1] = (GetEmblemCursorCellValue() == 1) ? 2 : 1;
                        templateCellValues[2] = GetEmblemCursorCellValue();
                        SplitBytesIntoNibbles(templateBytes, gEmblem->mCellNibbles, GetEmblemGridSide());
                        SetEmblemGridCellsFromTable((gEmblem->mCellNibbles), (templateCellValues));
                        ClearEmblemGridCopied();
                        gEmblem->mPendingTransitionFunc = StartEmblemTemplateSlideOut;
                        StartEmblemButtonBounceThenWait((gEmblem->mEmblemTemplateSLld), entryIndex);
                        gEmblem->mTemplateCursorIndex = entryIndex - 3;
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f6);
                    }
                    gEmblem->mCursorTargetState = 3;
                    return;
            }
            break;
        case 4:
            if (entryIndex == 1) {
                if (gEmblem->mPendingTransitionFunc == NULL) {
                    gEmblem->mPendingTransitionFunc = StartEmblemFadeOutToGrid;
                    StartEmblemButtonBounceThenWait((gEmblem->mEmblemCameraSLld), entryIndex);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0xc);
                    gEmblem->mKartListSkipped = TRUE;
                }
                gEmblem->mCursorTargetState = 3;
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
        GetLldEntry(gEmblem->mEmblemSLld, gEmblemButtonLldEntries[gEmblem->mButtonCursorIndex]);
        colorCursorEntry = GetLldEntry(gEmblem->mEmblemSLld, 9);
        GetLldEntry(gEmblem->mEmblemSLld, gEmblemColorLldEntries[gEmblem->mColorCursorIndex]);
        dx = 0;
        dy = 0;
        dz = 0;
        dx += GetNewOrRepeatBits(8, PAD_KEY_LEFT) ? -1 : 0;
        dx += GetNewOrRepeatBits(8, PAD_KEY_RIGHT) ? 1 : 0;
        dy += GetNewOrRepeatBits(8, PAD_KEY_UP) ? -1 : 0;
        dy += GetNewOrRepeatBits(8, PAD_KEY_DOWN) ? 1 : 0;
        dz += GetNewOrRepeatBits(8, PAD_KEY_L) ? -1 : 0;
        dz += GetNewOrRepeatBits(8, PAD_KEY_R) ? 1 : 0;

        switch (gEmblem->mCursorTargetState) {
            case 0:
                ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xb), -5);
                ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xc), 0);
                ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xd), -5);
                if (dz > 0) {
                    gEmblem->mCursorTargetState = 2;
                    gEmblem->mColorCursorIndex = GetEmblemCursorCellValue() - 1;
                    SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 9), 0x1000);
                    SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 10), 0);
                    SetLldEntryCallback(GetLldEntry(gEmblem->mEmblemSLld, 9), NULL);
                    SetLldEntryCallback(GetLldEntry(gEmblem->mEmblemSLld, 10), NULL);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1ee);
                } else if (dz < 0) {
                    gEmblem->mCursorTargetState = 1;
                    switch (GetEmblemCursorMode()) {
                        case 0:
                            gEmblem->mButtonCursorIndex =
                                GetEmblemCursorSizeIndex() + gEmblemLPressButtonCursorIndices[GetEmblemCursorMode()];
                            break;
                        case 1:
                            gEmblem->mButtonCursorIndex =
                                GetEmblemCursorSizeIndex() + gEmblemLPressButtonCursorIndices[GetEmblemCursorMode()];
                            break;
                        case 2:
                            gEmblem->mButtonCursorIndex = gEmblemLPressButtonCursorIndices[GetEmblemCursorMode()];
                            break;
                        case 3:
                            gEmblem->mButtonCursorIndex = gEmblemLPressButtonCursorIndices[GetEmblemCursorMode()];
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
                    gEmblem->mCursorTargetState = 2;
                    gEmblem->mColorCursorIndex = GetEmblemCursorCellValue() - 1;
                    SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 9), 0x1000);
                    SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 10), 0);
                    SetLldEntryCallback(GetLldEntry(gEmblem->mEmblemSLld, 9), NULL);
                    SetLldEntryCallback(GetLldEntry(gEmblem->mEmblemSLld, 10), NULL);
                    ApplyLldEntryFrameCommand(buttonCursorEntry, -5);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1ee);
                } else if (dz > 0) {
                    gEmblem->mCursorTargetState = 3;
                    ApplyLldEntryFrameCommand(buttonCursorEntry, -5);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1ee);
                } else if (GetEmblemInputNewBits(1)) {
                    if (gEmblemButtonLldEntries[gEmblem->mButtonCursorIndex] != 0x17 || IsEmblemGridChanged()) {
                        ActivateEmblemEntry(gEmblemButtonLldEntries[gEmblem->mButtonCursorIndex], 0);
                    }
                } else {
                    previousCursor = gEmblem->mButtonCursorIndex;
                    gEmblem->mButtonCursorIndex = gEmblemButtonCursorVerticalMoves[dy + 1][previousCursor];
                    gEmblem->mButtonCursorIndex =
                        gEmblemButtonCursorHorizontalMoves[dx + 1][gEmblem->mButtonCursorIndex];
                    targetEntry =
                        GetLldEntry(gEmblem->mEmblemSLld, gEmblemButtonLldEntries[gEmblem->mButtonCursorIndex]);
                    ApplyLldEntryFrameCommand(buttonCursorEntry, 0);
                    SetLldEntryPos(buttonCursorEntry, GetLldEntryX(targetEntry), GetLldEntryY(targetEntry));
                    if (gEmblem->mButtonCursorIndex != previousCursor) {
                        StartSoundOncePerFrame(0x1ef);
                    }
                }
                AdvanceEmblemCursor(0, GetEmblemInputX(), GetEmblemInputY(), 0, 0, 0);
                break;
            case 2:
                ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xb), -5);
                ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xc), -5);
                ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xd), 0);
                if (dz > 0) {
                    gEmblem->mCursorTargetState = 1;
                    switch (GetEmblemCursorMode()) {
                        case 0:
                            gEmblem->mButtonCursorIndex =
                                GetEmblemCursorSizeIndex() + gEmblemRPressButtonCursorIndices[GetEmblemCursorMode()];
                            break;
                        case 1:
                            gEmblem->mButtonCursorIndex =
                                GetEmblemCursorSizeIndex() + gEmblemRPressButtonCursorIndices[GetEmblemCursorMode()];
                            break;
                        case 2:
                            gEmblem->mButtonCursorIndex = gEmblemRPressButtonCursorIndices[GetEmblemCursorMode()];
                            break;
                        case 3:
                            gEmblem->mButtonCursorIndex = gEmblemRPressButtonCursorIndices[GetEmblemCursorMode()];
                            break;
                    }
                    SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 8), 0x1000);
                    SetLldEntryCallback(GetLldEntry(gEmblem->mEmblemSLld, 8), NULL);
                    SetLldEntryScale(colorCursorEntry, 0);
                    SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 10), 0x1000);
                    gEmblem->mColorCursorIndex = GetEmblemCursorCellValue() - 1;
                    ApplyLldEntryFrameCommand(colorCursorEntry, -5);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1ee);
                } else if (dz < 0) {
                    gEmblem->mCursorTargetState = 3;
                    SetLldEntryScale(colorCursorEntry, 0);
                    SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 10), 0x1000);
                    gEmblem->mColorCursorIndex = GetEmblemCursorCellValue() - 1;
                    ApplyLldEntryFrameCommand(colorCursorEntry, -5);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1ee);
                } else if (GetEmblemInputNewBits(1)) {
                    ActivateEmblemEntry(gEmblemColorLldEntries[gEmblem->mColorCursorIndex], 0);
                } else {
                    previousCursor = gEmblem->mColorCursorIndex;
                    gEmblem->mColorCursorIndex = gEmblemColorCursorVerticalMoves[dy + 1][previousCursor];
                    gEmblem->mColorCursorIndex = gEmblemColorCursorHorizontalMoves[dx + 1][gEmblem->mColorCursorIndex];
                    GetLldEntry(gEmblem->mEmblemSLld, gEmblemColorLldEntries[gEmblem->mColorCursorIndex]);
                    if (gEmblem->mColorCursorIndex < 0xf) {
                        ApplyLldEntryFrameCommand(colorCursorEntry, 0);
                    } else {
                        ApplyLldEntryFrameCommand(colorCursorEntry, -5);
                    }
                    if (gEmblem->mColorCursorIndex != previousCursor) {
                        StartSoundOncePerFrame(0x1ef);
                    }
                }
                AdvanceEmblemCursor(0, GetEmblemInputX(), GetEmblemInputY(), 0, 0, 0);
                break;
        }
    }

    if (GetEmblemInputPressed() && IsEmblemPointInGrid(GetEmblemInputX(), GetEmblemInputY())) {
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xb), -5);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xc), 0);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xd), -5);
        gEmblem->mColorCursorIndex = GetEmblemCursorCellValue() - 1;
        if (GetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 9)) == 0x1000) {
            SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 9), 0);
            SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 10), 0x1000);
        }
        if (GetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 8)) == 0x1000) {
            SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 8), 0);
        }
        gEmblem->mCursorTargetState = 0;
    } else if (gEmblem->mCursorTargetState == 3) {
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xb), -5);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xc), 0);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xd), -5);
        gEmblem->mColorCursorIndex = GetEmblemCursorCellValue() - 1;
        if (GetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 9)) == 0x1000) {
            SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 9), 0);
            SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 10), 0x1000);
        }
        if (GetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 8)) == 0x1000) {
            SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 8), 0);
        }
        if (!GetEmblemInputDown() && !GetEmblemInputBits(1) && !GetEmblemInputBits(2)) {
            gEmblem->mCursorTargetState = 0;
        }
    }

    if (gEmblem->mCursorTargetState == 0) {
        dx = 0;
        dy = 0;
        dx += IsEmblemInputRepeat(0x20) ? -1 : 0;
        dx += IsEmblemInputRepeat(0x10) ? 1 : 0;
        dy += IsEmblemInputRepeat(0x40) ? -1 : 0;
        dy += IsEmblemInputRepeat(0x80) ? 1 : 0;
        if (AdvanceEmblemCursor(GetEmblemInputDown(), GetEmblemInputX(), GetEmblemInputY(), GetEmblemInputBits(1), dx,
                                dy)) {
            if (GetEmblemCursorMode() == 3) {
                gEmblem->mColorCursorIndex = GetEmblemCursorCellValue() - 1;
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f4);
            } else if (GetEmblemCursorMode() == 2) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f5);
            }
        } else if (GetEmblemInputBits(0x400)) {
            flag = TRUE;
            if (SetEmblemCursorCellValueFromGrid()) {
                gEmblem->mColorCursorIndex = GetEmblemCursorCellValue() - 1;
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f4);
            }
        }
        if (GetEmblemInputDown() && !GetEmblemInputPrevDown() &&
            IsEmblemPointInGrid(GetEmblemInputX(), GetEmblemInputY())) {
            gEmblem->mSoundPending = TRUE;
        } else if (GetEmblemInputDown() &&
                   (IsEmblemPointInGrid(GetEmblemInputX(), GetEmblemInputY()) ||
                    IsEmblemPointInGrid(GetEmblemInputPrevX(), GetEmblemInputPrevY())) &&
                   (GetEmblemCursorPointX() != GetEmblemCursorPrevPointX() ||
                    GetEmblemCursorPointY() != GetEmblemCursorPrevPointY())) {
            gEmblem->mSoundPending = TRUE;
        } else if (GetEmblemInputNewBits(1)) {
            gEmblem->mSoundPending = TRUE;
        } else if (GetEmblemInputBits(1) && (GetEmblemCursorPointX() != GetEmblemCursorPrevPointX() ||
                                             GetEmblemCursorPointY() != GetEmblemCursorPrevPointY())) {
            gEmblem->mSoundPending = TRUE;
        }
    } else {
        AdvanceEmblemCursor(0, GetEmblemInputX(), GetEmblemInputY(), 0, 0, 0);
    }

    SetLldEntryPos(GetLldEntry(gEmblem->mEmblemSLld, 0), GetEmblemCursorPointX(), GetEmblemCursorPointY());
    SetLldEntryPos(GetLldEntry(gEmblem->mEmblemSLld, 1), GetEmblemCursorPointX(), GetEmblemCursorPointY());
    SetLldEntryPos(GetLldEntry(gEmblem->mEmblemSLld, 2), GetEmblemCursorPointX(), GetEmblemCursorPointY());
    SetLldEntryPos(GetLldEntry(gEmblem->mEmblemSLld, 3), GetEmblemCursorPointX(), GetEmblemCursorPointY());

    if (gEmblem->mCursorTargetState == 0 && GetEmblemInputDown() &&
        IsEmblemPointInGrid(GetEmblemInputX(), GetEmblemInputY())) {
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0), -5);
        gEmblem->mCursorSizeIndex = -1;
    } else if (gEmblem->mCursorTargetState == 0 && GetEmblemInputDown() &&
               GetLldEntryFrameIndex(GetLldEntry(gEmblem->mEmblemSLld, 0)) == -5) {
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0), -5);
        gEmblem->mCursorSizeIndex = -1;
    } else {
        gEmblem->mCursorSizeIndex = GetEmblemCursorSizeIndex();
        if (flag) {
            ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0), 3);
        } else {
            switch (GetEmblemCursorMode()) {
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

    switch (gEmblem->mCursorSizeIndex) {
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

    targetEntry = GetLldEntry(gEmblem->mEmblemSLld, gEmblemColorLldEntries[gEmblem->mColorCursorIndex]);
    SetLldEntryPos(GetLldEntry(gEmblem->mEmblemSLld, 9), GetLldEntryX(targetEntry), GetLldEntryY(targetEntry));
    SetLldEntryPos(GetLldEntry(gEmblem->mEmblemSLld, 10), GetLldEntryX(targetEntry), GetLldEntryY(targetEntry));

    if (gEmblem->mColorCursorIndex < 0xf) {
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
        ActivateEmblemEntry(gEmblemTemplateLldEntries[gEmblem->mTemplateCursorIndex], 0);
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
    gEmblem->mColorCursorIndex = colorStep + (GetEmblemCursorCellValue() - 1);
    t = gEmblem->mColorCursorIndex;
    if (t < 0) {
        t = 0xe;
    }
    gEmblem->mColorCursorIndex = t;
    u = gEmblem->mColorCursorIndex;
    if (u > 0xe) {
        u = 0;
    }
    gEmblem->mColorCursorIndex = u;
    sel = gEmblem->mColorCursorIndex;
    if (sel != GetEmblemCursorCellValue() - 1) {
        colorEntry = GetLldEntry(gEmblem->mEmblemSLld, gEmblemTemplateScreenColorEntries[sel]);
        colorCursorEntry = GetLldEntry(gEmblem->mEmblemSLld, 9);
        SetLldEntryPos(colorCursorEntry, GetLldEntryX(colorEntry), GetLldEntryY(colorEntry));
        colorCursorEntry = GetLldEntry(gEmblem->mEmblemSLld, 10);
        SetLldEntryPos(colorCursorEntry, GetLldEntryX(colorEntry), GetLldEntryY(colorEntry));
        SetEmblemCursorCellValue(gEmblem->mColorCursorIndex + 1);
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f1);
    }
    sel = gEmblem->mTemplateCursorIndex;
    gEmblem->mTemplateCursorIndex = gEmblemTemplateCursorVerticalMoves[verticalStep + 1][sel];
    gEmblem->mTemplateCursorIndex =
        gEmblemTemplateCursorHorizontalMoves[horizontalStep + 1][gEmblem->mTemplateCursorIndex];
    templateCursorEntry = GetLldEntry(gEmblem->mEmblemTemplateSLld, 2);
    templateEntry = GetLldEntry(gEmblem->mEmblemTemplateSLld, gEmblemTemplateLldEntries[gEmblem->mTemplateCursorIndex]);
    ApplyLldEntryFrameCommand(templateCursorEntry, 0);
    SetLldEntryPos(templateCursorEntry, GetLldEntryX(templateEntry), GetLldEntryY(templateEntry));
    if (gEmblem->mTemplateCursorIndex != sel) {
        StartSoundOncePerFrame(0x1ef);
    }
    {
        s32 templateIndex;
        void *entryAtIndex;

        for (templateIndex = 0; templateIndex < 0x1d; templateIndex++) {
            entryAtIndex = GetLldEntry(gEmblem->mEmblemTemplateSLld, gEmblemTemplateLldEntries[templateIndex]);
            ApplyLldEntryFrameCommand(entryAtIndex, templateIndex == gEmblem->mTemplateCursorIndex ? 1 : 0);
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
            JoinNibbleTilesIntoBytes(GetEmblemGridCells(), gEmblem->mRecordBytes, GetEmblemGridSide());
            SetEmblemRecordAndWriteBackup(gEmblem->mRecordBytes);
            gEmblem->mState = 0xb;
            gEmblem->mDisplayState = 1;
            break;
        case 2:
            SetEmblemChoisesShownAndReset(0);
            gEmblem->mState = 0xb;
            gEmblem->mDisplayState = 1;
            break;
    }
    UpdateEmblemChoises();
    WriteEmblemChoisesScreenMapWrapper();
}

void AdvanceEmblem(void) {
    s32 t;

    AdvanceEmblemInput();
    gEmblem->mBgScrollPosition += 0x4cd;
    t = gEmblem->mBgScrollPosition;
    if (t >= 0x100000) {
        t -= 0x100000;
    }
    gEmblem->mBgScrollPosition = t;
    ClearOamListCounts(gEmblem, &gEmblem->mSubOam);
    AdvanceLld(gEmblem->mEmblemMLld, &gEmblem->mMainOam);
    switch (gEmblem->mState) {
        case 0:
            if (gEmblem->mTransitionRunning == FALSE) {
                AdvanceEmblemGridScreen();
            }
            AdvanceLld(gEmblem->mEmblemSLld, &gEmblem->mSubOam);
            break;
        case 1:
            if (gEmblem->mTransitionRunning == FALSE) {
                AdvanceEmblemTemplateScreen();
            }
            AdvanceLld(gEmblem->mEmblemTemplateSLld, &gEmblem->mSubOam);
            AdvanceLld(gEmblem->mEmblemSLld, &gEmblem->mSubOam);
            break;
        case 2:
            AdvanceEmblemTemplateSlideIn();
            AdvanceLld(gEmblem->mEmblemTemplateSLld, &gEmblem->mSubOam);
            AdvanceLld(gEmblem->mEmblemSLld, &gEmblem->mSubOam);
            break;
        case 3:
            AdvanceEmblemTemplateSlideOut();
            AdvanceLld(gEmblem->mEmblemTemplateSLld, &gEmblem->mSubOam);
            AdvanceLld(gEmblem->mEmblemSLld, &gEmblem->mSubOam);
            break;
        case 4:
            if (gEmblem->mKartListSkipped == FALSE) {
                AdvanceEmblemKartList();
            }
            if (gEmblem->mTransitionRunning == FALSE) {
                AdvanceEmblemCameraScreen();
            }
            AdvanceLld(gEmblem->mEmblemCameraSLld, &gEmblem->mSubOam);
            break;
        case 5:
            if (gEmblem->mKartListSkipped == FALSE) {
                AdvanceEmblemKartList();
            }
            AdvanceEmblemFadeOutToCamera();
            AdvanceLld(gEmblem->mEmblemSLld, &gEmblem->mSubOam);
            break;
        case 6:
            if (gEmblem->mKartListSkipped == FALSE) {
                AdvanceEmblemKartList();
            }
            AdvanceEmblemFadeInAtCamera();
            AdvanceLld(gEmblem->mEmblemCameraSLld, &gEmblem->mSubOam);
            break;
        case 7:
            if (gEmblem->mTransitionRunning == FALSE) {
                AdvanceEmblemGridScreen();
            }
            AdvanceEmblemFadeOutToGrid();
            AdvanceLld(gEmblem->mEmblemCameraSLld, &gEmblem->mSubOam);
            break;
        case 8:
            if (gEmblem->mTransitionRunning == FALSE) {
                AdvanceEmblemGridScreen();
            }
            AdvanceEmblemFadeInAtGrid();
            AdvanceLld(gEmblem->mEmblemSLld, &gEmblem->mSubOam);
            break;
        case 10:
            AdvanceEmblemChoisesScreen();
            AdvanceLld(gEmblem->mEmblemSLld, &gEmblem->mSubOam);
            break;
        case 11:
            AdvanceLld(gEmblem->mEmblemSLld, &gEmblem->mSubOam);
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
                gEmblem->mState = 0xc;
            }
            break;
        case 12:
            AdvanceLld(gEmblem->mEmblemSLld, &gEmblem->mSubOam);
            break;
    }
    HideUnusedOams(gEmblem, &gEmblem->mSubOam);
    AdvanceShownSlotAndQueueEmblem();
    DrawKartModelMenuUnmirrored();
    JoinNibbleTilesIntoBytes(GetEmblemGridCells(), gEmblem->mRecordBytes, GetEmblemGridSide());
    JoinNibblesIntoBytes(GetEmblemGridCells(), gEmblem->mGridCharBytes, GetEmblemGridSide());
}
