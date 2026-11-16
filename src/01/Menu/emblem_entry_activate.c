#include "01/Menu/emblem_entry_activate.h"
#include "01/MapObjects/lld.h"
#include "Main/Menu/keyboard_keys.h"
#include "Main/Sound/sound_system.h"
#include "sound_player_control.h"
#include "01/Menu/emblem_grid.h"
#include "01/Menu/emblem_screen_upload.h"
#include "01/Menu/emblem_state_and_lld.h"
#include "01/Menu/menu_screen_work_structs.h"
#include "sound_archive_load_result.h"

void ActivateEmblemEntry(s32 entryIndex, s32 isTouch) {
    s32 templateByteSize;
    u8 *templateBytes;
    u16 templateCellValues[16];

    switch (gEmblem->mState) {
        case EMBLEM_STATE_GRID:
            switch (entryIndex) {
                case EMBLEM_ENTRY_COLOR_FIRST:
                case EMBLEM_ENTRY_COLOR_FIRST + 1:
                case EMBLEM_ENTRY_COLOR_FIRST + 2:
                case EMBLEM_ENTRY_COLOR_FIRST + 3:
                case EMBLEM_ENTRY_COLOR_FIRST + 4:
                case EMBLEM_ENTRY_COLOR_FIRST + 5:
                case EMBLEM_ENTRY_COLOR_FIRST + 6:
                case EMBLEM_ENTRY_COLOR_FIRST + 7:
                case EMBLEM_ENTRY_COLOR_FIRST + 8:
                case EMBLEM_ENTRY_COLOR_FIRST + 9:
                case EMBLEM_ENTRY_COLOR_FIRST + 10:
                case EMBLEM_ENTRY_COLOR_FIRST + 11:
                case EMBLEM_ENTRY_COLOR_FIRST + 12:
                case EMBLEM_ENTRY_COLOR_FIRST + 13:
                case EMBLEM_ENTRY_COLOR_FIRST + 14:
                    if (isTouch) {
                        SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 9), 0);
                        SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 10), 0x1000);
                        gEmblem->mColorCursorIndex = entryIndex - EMBLEM_ENTRY_COLOR_FIRST;
                        SetEmblemCursorCellValue(gEmblem->mColorCursorIndex + 1);
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f1);
                    } else {
                        gEmblem->mColorCursorIndex = entryIndex - EMBLEM_ENTRY_COLOR_FIRST;
                        StartEmblemColorCursorShrinkAndGrow((gEmblem->mEmblemSLld), entryIndex);
                        SetEmblemCursorCellValue(gEmblem->mColorCursorIndex + 1);
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f0);
                    }
                    if (GetEmblemCursorMode() == EMBLEM_CURSOR_MODE_ERASE) {
                        StartEmblemModeButtonPress(gEmblem->mEmblemSLld,
                                                   GetEmblemCursorSizeIndex() + EMBLEM_ENTRY_DRAW_BRUSH_FIRST);
                        SetEmblemCursorMode(EMBLEM_CURSOR_MODE_DRAW);
                    }
                    gEmblem->mCursorTargetState = EMBLEM_CURSOR_TARGET_HELD;
                    return;
                case EMBLEM_ENTRY_TOGGLE_BUTTON:
                    if (isTouch) {
                        SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 10), 0x1000);
                    }
                    StartEmblemButtonBounceAndToggle((gEmblem->mEmblemSLld), entryIndex);
                    if (isTouch) {
                        gEmblem->mCursorTargetState = EMBLEM_CURSOR_TARGET_HELD;
                        return;
                    }
                    break;
                case EMBLEM_ENTRY_DRAW_BRUSH_FIRST:
                case EMBLEM_ENTRY_DRAW_BRUSH_FIRST + 1:
                case EMBLEM_ENTRY_DRAW_BRUSH_FIRST + 2:
                    StartEmblemModeButtonPress((gEmblem->mEmblemSLld), entryIndex);
                    SetEmblemCursorMode(EMBLEM_CURSOR_MODE_DRAW);
                    SetEmblemCursorSizeIndex(entryIndex - EMBLEM_ENTRY_DRAW_BRUSH_FIRST);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f2);
                    gEmblem->mCursorTargetState = EMBLEM_CURSOR_TARGET_HELD;
                    return;
                case EMBLEM_ENTRY_ERASE_BRUSH_FIRST:
                case EMBLEM_ENTRY_ERASE_BRUSH_FIRST + 1:
                case EMBLEM_ENTRY_ERASE_BRUSH_FIRST + 2:
                    StartEmblemModeButtonPress((gEmblem->mEmblemSLld), entryIndex);
                    SetEmblemCursorMode(EMBLEM_CURSOR_MODE_ERASE);
                    SetEmblemCursorSizeIndex(entryIndex - EMBLEM_ENTRY_ERASE_BRUSH_FIRST);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f2);
                    gEmblem->mCursorTargetState = EMBLEM_CURSOR_TARGET_HELD;
                    return;
                case EMBLEM_ENTRY_FILL:
                    StartEmblemModeButtonPress((gEmblem->mEmblemSLld), entryIndex);
                    SetEmblemCursorMode(EMBLEM_CURSOR_MODE_FILL);
                    SetEmblemCursorSizeIndex(EMBLEM_BRUSH_1X1);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f2);
                    gEmblem->mCursorTargetState = EMBLEM_CURSOR_TARGET_HELD;
                    return;
                case EMBLEM_ENTRY_PICK_VALUE:
                    StartEmblemModeButtonPress((gEmblem->mEmblemSLld), entryIndex);
                    SetEmblemCursorMode(EMBLEM_CURSOR_MODE_PICK_VALUE);
                    SetEmblemCursorSizeIndex(EMBLEM_BRUSH_1X1);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f2);
                    gEmblem->mCursorTargetState = EMBLEM_CURSOR_TARGET_HELD;
                    return;
                case EMBLEM_ENTRY_TEMPLATE_BUTTON:
                    if (gEmblem->mPendingTransitionFunc == NULL) {
                        gEmblem->mPendingTransitionFunc = StartEmblemTemplateSlideIn;
                        StartEmblemButtonBounceThenWait((gEmblem->mEmblemSLld), entryIndex);
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f3);
                        gEmblem->mTransitionRunning = TRUE;
                    }
                    gEmblem->mCursorTargetState = EMBLEM_CURSOR_TARGET_HELD;
                    return;
                case EMBLEM_ENTRY_SWAP_CELLS:
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
                        gEmblem->mCursorTargetState = EMBLEM_CURSOR_TARGET_HELD;
                        return;
                    }
                    break;
                case EMBLEM_ENTRY_CAMERA:
                    if (gEmblem->mPendingTransitionFunc == NULL) {
                        gEmblem->mPendingTransitionFunc = StartEmblemFadeOutToCamera;
                        StartEmblemButtonBounceThenWait((gEmblem->mEmblemSLld), entryIndex);
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0xc);
                        gEmblem->mTransitionRunning = TRUE;
                        gEmblem->mKartListSkipped = FALSE;
                    }
                    gEmblem->mCursorTargetState = EMBLEM_CURSOR_TARGET_HELD;
                    return;
                case EMBLEM_ENTRY_CHOISES:
                    if (gEmblem->mPendingTransitionFunc == NULL) {
                        gEmblem->mPendingTransitionFunc = StartEmblemChoises;
                        StartEmblemButtonBounce((gEmblem->mEmblemSLld), entryIndex);
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 4);
                        gEmblem->mTransitionRunning = TRUE;
                    }
                    gEmblem->mCursorTargetState = EMBLEM_CURSOR_TARGET_HELD;
                    return;
            }
            break;
        case EMBLEM_STATE_TEMPLATE:
            switch (entryIndex) {
                case 0:
                    if (gEmblem->mPendingTransitionFunc == NULL) {
                        gEmblem->mPendingTransitionFunc = StartEmblemTemplateSlideOut;
                        StartEmblemButtonHold((gEmblem->mEmblemTemplateSLld), 1);
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0xe);
                        gEmblem->mTransitionRunning = TRUE;
                    }
                    gEmblem->mCursorTargetState = EMBLEM_CURSOR_TARGET_HELD;
                    return;
                case EMBLEM_TEMPLATE_ENTRY_FIRST:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 1:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 2:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 3:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 4:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 5:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 6:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 7:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 8:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 9:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 10:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 11:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 12:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 13:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 14:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 15:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 16:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 17:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 18:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 19:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 20:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 21:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 22:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 23:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 24:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 25:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 26:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 27:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 28:
                    if (gEmblem->mPendingTransitionFunc == NULL) {
                        templateByteSize = (s32) (GetEmblemGridSide() * GetEmblemGridSide()) / 2;
                        templateBytes = (u8 *) gEmblem->mEmblemTemplateBNcgr->mData +
                                        (entryIndex - EMBLEM_TEMPLATE_ENTRY_FIRST) * templateByteSize;
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
                    gEmblem->mCursorTargetState = EMBLEM_CURSOR_TARGET_HELD;
                    return;
            }
            break;
        case EMBLEM_STATE_CAMERA:
            if (entryIndex == 1) {
                if (gEmblem->mPendingTransitionFunc == NULL) {
                    gEmblem->mPendingTransitionFunc = StartEmblemFadeOutToGrid;
                    StartEmblemButtonBounceThenWait((gEmblem->mEmblemCameraSLld), entryIndex);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0xc);
                    gEmblem->mKartListSkipped = TRUE;
                }
                gEmblem->mCursorTargetState = EMBLEM_CURSOR_TARGET_HELD;
            }
            break;
    }
}
