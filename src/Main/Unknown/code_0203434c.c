#include "Main/Unknown/code_0203434c.h"
#include "Main/Unknown/code_020487fc.h" // SceneNumbers
#include "Main/Unknown/code_0202d990.h"
#include "Main/Unknown/code_02034bf4.h"
#include "Main/Unknown/code_020351c8.h"
#include "Main/Unknown/code_02036000.h"

#include "00/code_02181f98.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025d5c.h"
#include "Main/Unknown/code_0202d000.h"
#include "Main/Unknown/code_0202dd9c.h"
#include "Main/Unknown/code_02034000.h"
#include "Main/Unknown/code_02035000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_0204e000.h"
#include "Main/Unknown/code_0204ece0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_0204ed04.h"
#include "Main/Unknown/code_0204f5e4.h"
#include "Main/Unknown/code_0204f7f4.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02054f58.h"
#include "Main/Unknown/code_020566a8.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/code_02125ed0.h"
#include "Main/Unknown/code_02125f2c.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02126230.h"
#include "Main/Unknown/code_021262f0.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_0201ea58.h"
#include "code_0212d214.h"
#include "code_0212df7c.h"
#include "code_0214d018.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_02025edc.h"

#pragma thumb on

static inline s32 GhostGetScanIsBackupCommandRunning(void) {
    BackupAccess *backupAccess = gBackupAccess;
    if (backupAccess->mBackupEnabled != 0) {
        return backupAccess->mCommandRunning;
    }
    return 0;
}

static inline s32 GhostGetScanIsBackupBusy(void) {
    if (data_0217aa08->mBusy == 0) {
        return GhostGetScanIsBackupCommandRunning();
    }
    return 1;
}

s32 AdvanceTimeAttackGhostGetScan(SceneNumbers *sceneNumbers) {
    CellFileSet *subCellFileSet;
    CellFileSet *cellFileSet;
    s32 previousSelectedIndex;
    u16 slotIndex;
    s32 result;
    s32 touchInReturnRect;
    s32 rectIndex;
    s32 entryIndex;
    s32 courseLabelIndex;
    s32 courseMessageIndex;
    BOOL pairIsNew;
    BOOL pairRecentlyGone;
    u16 hasPair;
    s32 pairX;
    s32 pairY;
    void *message;
    void *buttonText;
    void *secondButtonText;
    u8 idBytes[3];
    GhostRecordInfo ghostRecordInfo;
    u16 formattedText[0x100];

    previousSelectedIndex = gTimeAttackGhostGetScan->mInfoFileSets.mSelectedIndex;
    slotIndex = GetPadInputSlot();
    touchInReturnRect = 0;
    result = -1;
    rectIndex = -1;
    subCellFileSet = &gTimeAttackGhostGetScan->mInfoFileSets.mCellFileSets[1];
    AdvanceInterpolation(&gTimeAttackGhostGetScan->mInterpolation);
    switch (gTimeAttackGhostGetScan->mState) {
        case 0:
            if (AreBrightnessFadesClear() == 0) {
                RequestSelectReturnState1();
                SetupGhostMainTextShort();
                SetInterpolationStateIfOpposite(&gTimeAttackGhostGetScan->mInterpolation, 0);
                gTimeAttackGhostGetScan->mState = 1;
            }
            break;
        case 1:
            if (gTimeAttackGhostGetScan->mInterpolation.mState == 1) {
                gTimeAttackGhostGetScan->mState = 2;
            } else {
                UpdateScanSlideOffsets();
            }
            break;
        case 2:
            switch (AdvanceConnectionSetup(0, NULL)) {
                case 1:
                    SetupTxtSystemSubText(GetBmgEntry(gTimeAttackGhostGetScan->mGhostMessages, 0xf));
                    NNS_SndArcSetCurrent(&gOnMemorySndArc);
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 9);
                    NNS_SndArcSetCurrent(&gFileSndArc);
                    gTimeAttackGhostGetScan->mState = 5;
                    break;
                case 0:
                    if (gTimeAttackGhostGetScan->mGhostPicked != FALSE) {
                        break;
                    }
                    if (IsTxtSystemState0NoOpenRequest() != 0) {
                        SetupGhostMainTextShort();
                    }
                    gTimeAttackGhostGetScan->mFilledCount = 0;
                    for (entryIndex = 0; entryIndex < 4; entryIndex++) {
                        courseLabelIndex = entryIndex + 4;
                        if (TryGetScanGhostInfo(entryIndex, &ghostRecordInfo, &idBytes[0], &idBytes[1], &idBytes[2],
                                                &ghostRecordInfo.mTime.mMinute, &ghostRecordInfo.mTime.mSecond,
                                                &ghostRecordInfo.mTime.mMillisecond)) {
                            ghostRecordInfo.mKartIndex = idBytes[0];
                            ghostRecordInfo.mCharacterIndex = idBytes[1];
                            ghostRecordInfo.mCourseId = idBytes[2];
                            gTimeAttackGhostGetScan->mFilledCount++;
                            if (gTimeAttackGhostGetScan->mGhostInfoEntries[entryIndex].mFilled == FALSE ||
                                AreGhostRecordInfosDifferent(
                                    &gTimeAttackGhostGetScan->mGhostInfoEntries[entryIndex].mInfo, &ghostRecordInfo) !=
                                    FALSE) {
                                courseMessageIndex = GetGhostCourseMessageIndex(ghostRecordInfo.mCourseId);
                                ghostRecordInfo.mName[10] = 0;
                                PrintLabelLayoutTextNoFixedAdvance(
                                    1, gTimeAttackGhostGetScanSSelLabelTextRows[entryIndex][0],
                                    subCellFileSet->mLabelLayout, &ghostRecordInfo, subCellFileSet->mCellLayout,
                                    subCellFileSet->mCellTable);
                                PrintLabelLayoutTextNoFixedAdvance(
                                    1, gTimeAttackGhostGetScanSSelLabelTextRows[courseLabelIndex][0],
                                    subCellFileSet->mLabelLayout,
                                    GetBmgEntry(gTimeAttackGhostGetScan->mGhostMessages, courseMessageIndex),
                                    subCellFileSet->mCellLayout, subCellFileSet->mCellTable);
                                MIi_CpuCopyFast(&ghostRecordInfo,
                                                &gTimeAttackGhostGetScan->mGhostInfoEntries[entryIndex].mInfo, 0x28);
                                gTimeAttackGhostGetScan->mGhostInfoEntries[entryIndex].mFilled = TRUE;
                                SetInterpolationStateIfOpposite(
                                    &gTimeAttackGhostGetScan->mGhostInfoEntries[entryIndex].mInterpolation, 0);
                                if (gTimeAttackGhostGetScan->mInfoFileSets.mSelectedIndex == entryIndex) {
                                    RefreshScanSelectedGhostInfo();
                                }
                                NNS_SndArcSetCurrent(&gOnMemorySndArc);
                                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 7);
                                NNS_SndArcSetCurrent(&gFileSndArc);
                            }
                        } else {
                            SetInterpolationStateIfOpposite(
                                &gTimeAttackGhostGetScan->mGhostInfoEntries[entryIndex].mInterpolation, 2);
                            gTimeAttackGhostGetScan->mGhostInfoEntries[entryIndex].mFilled = FALSE;
                        }
                    }
                    UpdateScanSelectedIndex();
                    pairIsNew = FALSE;
                    pairRecentlyGone = FALSE;
                    hasPair = data_02175674[slotIndex].mPressedBits;
                    if (hasPair == 0 && data_02175680[slotIndex].mPressedBits < 5) {
                        pairRecentlyGone = TRUE;
                    }
                    if (pairRecentlyGone == FALSE && data_0217567c[slotIndex].mPressedBits == 0 && hasPair != 0) {
                        pairIsNew = TRUE;
                    }
                    if (pairIsNew != FALSE) {
                        pairX = data_02175670[slotIndex].mPressedBits;
                        pairY = data_02175672[slotIndex].mPressedBits;
                        touchInReturnRect = IsSelectReturnState2NoState3Or4RequestAndInRect(pairX, pairY);
                        rectIndex = RectTableFindContaining(subCellFileSet->mRects, pairX, pairY);
                    }
                    if (rectIndex >= 0 && gTimeAttackGhostGetScan->mGhostInfoEntries[rectIndex].mFilled != FALSE) {
                        SetupGhostSubTextTwoButtons();
                        SetScanSelectedEntryHighlight(
                            gTimeAttackGhostGetScan->mInfoFileSets.mSelectedIndex != rectIndex ? 1 : 0);
                        gTimeAttackGhostGetScan->mInfoFileSets.mSelectedIndex = rectIndex;
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
                        RequestSelectReturnState4();
                        gTimeAttackGhostGetScan->mGhostPicked = TRUE;
                        gTimeAttackGhostGetScan->mStateFrames = 0;
                        gTimeAttackGhostGetScan->mState = 3;
                    } else if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_A) != 0 &&
                               gTimeAttackGhostGetScan->mInfoFileSets.mSelectedIndex >= 0) {
                        SetupGhostSubTextTwoButtons();
                        SetScanSelectedEntryHighlight(0);
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
                        RequestSelectReturnState4();
                        gTimeAttackGhostGetScan->mGhostPicked = TRUE;
                        gTimeAttackGhostGetScan->mStateFrames = 0;
                        gTimeAttackGhostGetScan->mState = 3;
                    } else if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_B) != 0 || touchInReturnRect != 0) {
                        gTimeAttackGhostGetScan->mState = 12;
                        RequestSelectReturnState3WithSound(0);
                    } else if (GetNewOrRepeatBits(slotIndex, PAD_KEY_UP)) {
                        if (gTimeAttackGhostGetScan->mFilledCount == 2) {
                            MoveSelectedGhostUp(0);
                        } else if (gTimeAttackGhostGetScan->mFilledCount > 2) {
                            MoveSelectedGhostUp(1);
                        }
                    } else if (GetNewOrRepeatBits(slotIndex, PAD_KEY_DOWN)) {
                        if (gTimeAttackGhostGetScan->mFilledCount == 2) {
                            MoveSelectedGhostDown(0);
                        } else if (gTimeAttackGhostGetScan->mFilledCount > 2) {
                            MoveSelectedGhostDown(1);
                        }
                    }
                    break;
                case 2:
                    break;
            }
            if (previousSelectedIndex != gTimeAttackGhostGetScan->mInfoFileSets.mSelectedIndex) {
                RefreshScanSelectedGhostInfo();
                RefreshScanEntryPalettes();
            }
            break;
        case 3:
            gTimeAttackGhostGetScan->mStateFrames++;
            if (gTimeAttackGhostGetScan->mStateFrames > 5) {
                SetScanSelectedEntryHighlight(1);
                gTimeAttackGhostGetScan->mStateFrames = 0;
                gTimeAttackGhostGetScan->mState = 4;
            }
            break;
        case 4:
            if (GetTxtSystemDone() != 0) {
                if (GetTxtSystemSelectedIndex() == 0) {
                    SetSelectedScanEntry(gTimeAttackGhostGetScan->mInfoFileSets.mSelectedIndex);
                } else {
                    RequestSelectReturnState1();
                    gTimeAttackGhostGetScan->mGhostPicked = FALSE;
                }
                RequestTxtSystemClose();
                gTimeAttackGhostGetScan->mState = 2;
            }
            break;
        case 5:
            switch (AdvanceBlockCountRequest()) {
                case 1:
                    ResetPendingFiles();
                    SetBlockEntryBuffer(0, GetSlotGhostBuffer());
                    gTimeAttackGhostGetScan->mState = 6;
                    break;
                case 2:
                    StartTimeAttackGhostGetScanState15();
                    break;
            }
            break;
        case 6:
            switch (AdvanceBlockReceive()) {
                case 1:
                    gTimeAttackGhostGetScan->mState = 7;
                    break;
                case 2:
                    StartTimeAttackGhostGetScanState15();
                    break;
            }
            break;
        case 7:
            if (AdvanceConnectionEndStopOnError() == 1) {
                SendLedPatternWireless();
                gTimeAttackGhostGetScan->mState = 8;
            }
            break;
        case 12:
            if (AdvanceConnectionEndStopOnError() == 1) {
                SendLedPatternWireless();
                gMenuShared->mMenuEntryKind = 5;
                if (sceneNumbers != NULL) {
                    sceneNumbers->mNextScene = 1;
                }
                gTimeAttackGhostGetScan->mState = 16;
            }
            break;
        case 8:
            if (DoesAnySlotGhostMatchCourse(
                    gTimeAttackGhostGetScan->mGhostInfoEntries[gTimeAttackGhostGetScan->mInfoFileSets.mSelectedIndex]
                        .mInfo.mCourseId) != 0) {
                courseMessageIndex = GetGhostCourseMessageIndex(
                    gTimeAttackGhostGetScan->mGhostInfoEntries[gTimeAttackGhostGetScan->mInfoFileSets.mSelectedIndex]
                        .mInfo.mCourseId);
                message = GetBmgEntry(gTimeAttackGhostGetScan->mGhostMessages, 0x55);
                buttonText = GetBmgEntry(gTimeAttackGhostGetScan->mInfoFileSets.mCommonMessages, 0);
                secondButtonText = GetBmgEntry(gTimeAttackGhostGetScan->mInfoFileSets.mCommonMessages, 1);
                FormatMessageWithText(GetBmgEntry(gTimeAttackGhostGetScan->mGhostMessages, courseMessageIndex), message,
                                      formattedText, 0x100);
                SetTxtSystemSoundId(0, -1);
                SetupTxtSystemSubTextTwoButtonsEx(formattedText, buttonText, secondButtonText, 1, 0, 1, 1, 0);
                gTimeAttackGhostGetScan->mState = 9;
            } else if (GetSlotGhostCount() == 10) {
                RequestTxtSystemClose();
                gTimeAttackGhostGetScan->mNextCallbacksIndex = 2;
                gTimeAttackGhostGetScan->mState = 13;
                SetInterpolationStateIfOpposite(&gTimeAttackGhostGetScan->mInterpolation, 2);
            } else {
                gTimeAttackGhostGetScan->mGhostSlot = FindUnfilledGhostSlot();
                GetSlotGhostBuffer()->mHead.mFilled = 1;
                WriteSlotGhostRecord((u8) gTimeAttackGhostGetScan->mGhostSlot, GetSlotGhostBuffer());
                NNS_SndArcSetCurrent(&gOnMemorySndArc);
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 10);
                NNS_SndArcSetCurrent(&gFileSndArc);
                gTimeAttackGhostGetScan->mState = 11;
            }
            break;
        case 9:
            if (GetTxtSystemInputAccepted() != 0 && GetTxtSystemSelectedIndex() == 0) {
                NNS_SndArcSetCurrent(&gOnMemorySndArc);
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 10);
                NNS_SndArcSetCurrent(&gFileSndArc);
            }
            if (GetTxtSystemDone() != 0) {
                RequestTxtSystemClose();
                if (GetTxtSystemSelectedIndex() == 0) {
                    gTimeAttackGhostGetScan->mGhostSlot = FindSlotGhostForCourse(
                        gTimeAttackGhostGetScan
                            ->mGhostInfoEntries[gTimeAttackGhostGetScan->mInfoFileSets.mSelectedIndex]
                            .mInfo.mCourseId);
                    GetSlotGhostBuffer()->mHead.mFilled = 1;
                    WriteSlotGhostRecord((u8) gTimeAttackGhostGetScan->mGhostSlot, GetSlotGhostBuffer());
                    gTimeAttackGhostGetScan->mState = 11;
                } else {
                    gTimeAttackGhostGetScan->mState = 10;
                }
            }
            break;
        case 10:
            if (IsTxtSystemState0NoOpenRequest() != 0) {
                message = GetBmgEntry(gTimeAttackGhostGetScan->mGhostMessages, 0x54);
                buttonText = GetBmgEntry(gTimeAttackGhostGetScan->mInfoFileSets.mCommonMessages, 4);
                SetTxtSystemSoundId(0, 5);
                SetupTxtSystemSubTextButton(message, buttonText);
                gTimeAttackGhostGetScan->mState = 14;
            }
            break;
        case 11:
            if (GhostGetScanIsBackupBusy() != 0) {
                message = GetBmgEntry(gTimeAttackGhostGetScan->mGhostMessages, 0x10);
                buttonText = GetBmgEntry(gTimeAttackGhostGetScan->mInfoFileSets.mCommonMessages, 4);
                SetTxtSystemSoundId(0, 5);
                SetupTxtSystemSubTextButton(message, buttonText);
                gTimeAttackGhostGetScan->mState = 14;
            }
            break;
        case 15:
            if (IsTxtSystemState2AfterState1() != 0) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x15);
            }
            if (GetTxtSystemDone() != 0) {
                gTimeAttackGhostGetScan->mStateFrames = 0;
                gTimeAttackGhostGetScan->mState = 12;
                RequestTxtSystemClose();
            }
            break;
        case 14:
            if (GetTxtSystemDone() != 0) {
                gMenuShared->mMenuEntryKind = 5;
                if (sceneNumbers != NULL) {
                    sceneNumbers->mNextScene = 1;
                }
                gTimeAttackGhostGetScan->mState = 16;
            }
            break;
        case 13:
            if (gTimeAttackGhostGetScan->mInterpolation.mState == 3) {
                result = gTimeAttackGhostGetScan->mNextCallbacksIndex;
                gTimeAttackGhostGetScan->mState = 16;
            } else {
                UpdateScanSlideOffsets();
            }
            break;
    }
    UpdateScanEntryOffsetX();
    UpdateConnectionSendTimer();
    for (entryIndex = 0; entryIndex < 2; entryIndex++) {
        cellFileSet = &gTimeAttackGhostGetScan->mInfoFileSets.mCellFileSets[entryIndex];
        DrawLayoutTable(cellFileSet->mCellLayout, cellFileSet->mCells, cellFileSet->mLabelLayout,
                        gTimeAttackGhostGetScan->mOamLists[entryIndex], cellFileSet->mCellTable);
    }
    return result;
}

#pragma thumb off

#pragma thumb on

void ReleaseTimeAttackGhostGetScan(void) {
    HeapDestroy((void *) ((u32) gTimeAttackGhostGetScan->mHeap));
    *&gTimeAttackGhostGetScan = NULL;
}

#pragma thumb off
