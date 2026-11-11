#include "01/code_021a41c8.h"
#include "01/code_02184f7c.h"
#include "Main/Unknown/code_020aa81c.h"
#include "Main/Unknown/unk_0217d068.h"
#include "01/code_02180ce8.h"
#include "01/code_021a4724.h"
#include "01/code_021a5140.h"
#include "01/code_02181000.h"
#include "01/code_02184000.h"
#include "01/code_02185000.h"
#include "01/code_021a4000.h"
#include "01/code_021a5000.h"
#include "01/code_021a6000.h"
#include "Main/Unknown/code_020ac000.h"
#include "code_0212df7c.h"

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
                        SetEmblemCursorCellValue(gEmblem->mUnk_1080 + 1);
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f1);
                    } else {
                        gEmblem->mUnk_1080 = entryIndex - 0x1b;
                        StartEmblemColorCursorShrinkAndGrow((gEmblem->mEmblemSLld), entryIndex);
                        SetEmblemCursorCellValue(gEmblem->mUnk_1080 + 1);
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f0);
                    }
                    if (GetEmblemCursorMode() == 1) {
                        StartEmblemModeButtonPress(gEmblem->mEmblemSLld, GetEmblemCursorSizeIndex() + 0xe);
                        SetEmblemCursorMode(0);
                    }
                    gEmblem->mUnk_1094 = 3;
                    return;
                case 0x2a:
                    if (isTouch) {
                        SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 10), 0x1000);
                    }
                    StartEmblemButtonBounceAndToggle((gEmblem->mEmblemSLld), entryIndex);
                    if (isTouch) {
                        gEmblem->mUnk_1094 = 3;
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
                    gEmblem->mUnk_1094 = 3;
                    return;
                case 0x11:
                case 0x12:
                case 0x13:
                    StartEmblemModeButtonPress((gEmblem->mEmblemSLld), entryIndex);
                    SetEmblemCursorMode(1);
                    SetEmblemCursorSizeIndex(entryIndex - 0x11);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f2);
                    gEmblem->mUnk_1094 = 3;
                    return;
                case 0x14:
                    StartEmblemModeButtonPress((gEmblem->mEmblemSLld), entryIndex);
                    SetEmblemCursorMode(2);
                    SetEmblemCursorSizeIndex(0);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f2);
                    gEmblem->mUnk_1094 = 3;
                    return;
                case 0x15:
                    StartEmblemModeButtonPress((gEmblem->mEmblemSLld), entryIndex);
                    SetEmblemCursorMode(3);
                    SetEmblemCursorSizeIndex(0);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f2);
                    gEmblem->mUnk_1094 = 3;
                    return;
                case 0x16:
                    if (gEmblem->mUnk_108c == NULL) {
                        gEmblem->mUnk_108c = StartEmblemTemplateSlideIn;
                        StartEmblemButtonBounceThenWait((gEmblem->mEmblemSLld), entryIndex);
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
                        StartEmblemButtonBounceThenWait((gEmblem->mEmblemSLld), entryIndex);
                    }
                    if (isTouch) {
                        gEmblem->mUnk_1094 = 3;
                        return;
                    }
                    break;
                case 0x19:
                    if (gEmblem->mUnk_108c == NULL) {
                        gEmblem->mUnk_108c = StartEmblemFadeOutToCamera;
                        StartEmblemButtonBounceThenWait((gEmblem->mEmblemSLld), entryIndex);
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0xc);
                        gEmblem->mUnk_10b0 = TRUE;
                        gEmblem->mUnk_10ac = FALSE;
                    }
                    gEmblem->mUnk_1094 = 3;
                    return;
                case 0x1a:
                    if (gEmblem->mUnk_108c == NULL) {
                        gEmblem->mUnk_108c = StartEmblemChoises;
                        StartEmblemButtonBounce((gEmblem->mEmblemSLld), entryIndex);
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
                        StartEmblemButtonHold((gEmblem->mEmblemTemplateSLld), 1);
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
                        templateCellValues[1] = (GetEmblemCursorCellValue() == 1) ? 2 : 1;
                        templateCellValues[2] = GetEmblemCursorCellValue();
                        SplitBytesIntoNibbles(templateBytes, gEmblem->mUnk_0c7c, GetEmblemGridSide());
                        SetEmblemGridCellsFromTable((gEmblem->mUnk_0c7c), (templateCellValues));
                        ClearEmblemGridCopied();
                        gEmblem->mUnk_108c = StartEmblemTemplateSlideOut;
                        StartEmblemButtonBounceThenWait((gEmblem->mEmblemTemplateSLld), entryIndex);
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
                    StartEmblemButtonBounceThenWait((gEmblem->mEmblemCameraSLld), entryIndex);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0xc);
                    gEmblem->mUnk_10ac = TRUE;
                }
                gEmblem->mUnk_1094 = 3;
            }
            break;
    }
}
