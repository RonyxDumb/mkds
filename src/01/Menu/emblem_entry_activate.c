#include "01/Menu/emblem_entry_activate.h"
#include "01/MapObjects/lld.h"
#include "Main/Menu/keyboard_keys.h"
#include "Main/Sound/sound_system.h"
#include "player.h"
#include "01/Menu/emblem_grid.h"
#include "01/Menu/emblem_screen_upload.h"
#include "01/code_021a5140.h"
#include "01/code_02181000.h"
#include "01/code_02184000.h"
#include "01/code_02185000.h"
#include "01/code_021a4000.h"
#include "01/code_021a5000.h"
#include "01/code_021a6000.h"
#include "code_0212df7c.h"

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
