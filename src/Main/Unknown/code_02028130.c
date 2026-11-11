#include "Main/Unknown/code_02028130.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025eb0.h"
#include "Main/Unknown/code_02028774.h"
#include "Main/Unknown/code_0202881c.h"
#include "Main/Unknown/code_02028724.h"
#include "Main/Unknown/code_02028000.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_02028d9c.h"
#include "Main/Unknown/code_02028f20.h"
#include "Main/Unknown/code_02029008.h"
#include "Main/Unknown/code_020291f0.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_0202b604.h"
#include "Main/Unknown/code_0202b000.h"
#include "Main/Unknown/code_02027e78.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02077bc0.h"
#include "Main/Unknown/code_020adb04.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_021105a0.h"
#include "Main/Unknown/code_021106a8.h"
#include "Main/Unknown/code_02116ec0.h"
#include "Main/Unknown/code_0211f378.h"
#include "Main/Unknown/code_0211f394.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_02121e84.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_0212b1a8.h"
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
#include "Main/Unknown/code_02025edc.h"
#include "Main/Unknown/code_0202bb80.h"

#pragma optimize_for_size on

u16 SelectKartGetInputSlotNewBits(InputSlot *inputSlot, u32 mask) {
    return inputSlot->mPressedBits & mask;
}

u16 SelectKartGetNewBits(u32 slotIndex, u32 mask) {
    return SelectKartGetInputSlotNewBits(&gInputSlots[slotIndex], mask);
}

#pragma thumb on

int AdvanceSelectKart(void) {
    SelectKart *selectKart;
    CellFileSet *selectKartParts;
    s32 oldKartIndex;
    s32 result;
    s32 padInputSlot;
    s32 isReturnTouched;
    CellFileSet *characterParts;
    u32 value;
    selectKart = gSelectKart;
    oldKartIndex = selectKart->mKartIndex;
    isReturnTouched = 0;
    result = 0;
    characterParts = &selectKart->mSelectCharacterGpMParts;
    selectKartParts = &selectKart->mSelectKartSParts;
    padInputSlot = GetPadInputSlot();
    AdvanceInterpolation(&gSelectKart->mInterpolations[0]);
    AdvanceInterpolation(&gSelectKart->mInterpolations[1]);
    AdvanceInterpolation(&gSelectKart->mInterpolations[2]);
    AdvanceInterpolation(&gSelectKart->mInterpolations[3]);
    AdvanceInterpolation(&gSelectKart->mInterpolations[4]);
    SetSelectKartGpMPartsOffsets();
    if (SelectKartMB_IsMultiBootChildWrapper() == 0) {
        AdvancePaletteBlend();
    }
    if (SelectKartMB_IsMultiBootChildWrapper() == 0) {
        gSelectKart->mTouchRect = UpdateSelectKartTouchHold();
    } else {
        gSelectKart->mTouchRect = -1;
    }
    selectKart = gSelectKart;
    switch (selectKart->mState) {
        case 0:
            if (selectKart->mInterpolations[4].mState == 1) {
                selectKart->mStateFrames = 0;
                if (SelectKartMB_IsMultiBootChildWrapper() != 0) {
                    value = 1;
                } else {
                    value = 2;
                }
                gSelectKart->mState = value;
            }
            SetSelectKartSPartsOffsetY();
            break;
        case 1:
            SetDataSharingSendByteInState8(selectKart->mKartIndex | 0x80);
            gSelectKart->mResult = 1;
            gSelectKart->mState = 5;
            break;
        case 2:
            if (SelectKartIsSlotPairNew(padInputSlot) != 0) {
                isReturnTouched = IsSelectReturnState2NoState3Or4RequestAndInRect(SelectKartGetSlotPairX(padInputSlot),
                                                                                  SelectKartGetSlotPairY(padInputSlot));
            }
            if (SelectKartGetNewBits(padInputSlot, PAD_KEY_A) != 0 || gSelectKart->mTouchRect == 2 ||
                IsSelectKartModeAndTimerZero() != 0) {
                gSelectKart->mStateFrames = 0;
                gSelectKart->mResult = 1;
                gSelectKart->mState = 4;
                selectKartParts->mCellTable[18].mVisible = 0;
                SetLabelPaletteIndex(data_usa_02153834[4], 0, selectKartParts->mLabelLayout,
                                     selectKartParts->mCellTable, selectKartParts->mCellLayout);
                StartSeqPair(GetCharacterSeqPairNo(gSelectKart->mCharacterIndex), 1);
                SetKartModelMenuSpinStopped(1);
                StopPaletteBlend();
            } else if (SelectKartGetNewBits(padInputSlot, PAD_KEY_B) != 0 || isReturnTouched != 0) {
                gSelectKart->mStateFrames = 0;
                gSelectKart->mResult = 2;
                StartSelectKartEntryListKindIfUsed(0);
                SetInterpolationStateIfOpposite(&gSelectKart->mInterpolations[1], 2);
                SetInterpolationStateIfOpposite(&gSelectKart->mInterpolations[3], 2);
                SetInterpolationStateIfOpposite(&gSelectKart->mInterpolations[4], 2);
                gSelectKart->mState = 7;
                if (gSelectKart->mMode != 0) {
                    value = 1;
                } else {
                    value = 0;
                }
                RequestSelectReturnState3WithSound(value);
            } else if (GetNewOrRepeatBits(padInputSlot, PAD_KEY_RIGHT) != 0 || IsSelectKartTouchRepeat(1) != 0) {
                MoveSelectKartNext();
                gSelectKart->mSlidingCellIndex = 3;
                selectKartParts->mCellTable[1].mVisible = 0;
                selectKartParts->mCellTable[3].mVisible = 1;
            } else if (GetNewOrRepeatBits(padInputSlot, PAD_KEY_LEFT) != 0 || IsSelectKartTouchRepeat(0) != 0) {
                MoveSelectKartPrev();
                gSelectKart->mSlidingCellIndex = 2;
                selectKartParts->mCellTable[0].mVisible = 0;
                selectKartParts->mCellTable[2].mVisible = 1;
            }
            if (oldKartIndex != gSelectKart->mKartIndex) {
                StartCursorMoveSound();
                PrintSelectKartMessage();
                RefreshKartMenuParamElements();
                gSelectKart->mState = 3;
                gSelectKart->mStateFrames = 0;
            }
            break;
        case 3:
            selectKart->mStateFrames = selectKart->mStateFrames + 1;
            if (gSelectKart->mStateFrames > 6) {
                gSelectKart->mStateFrames = 0;
                gSelectKart->mState = 2;
                selectKartParts->mCellTable[gSelectKart->mSlidingCellIndex].mOffsetX = 0;
                selectKartParts->mCellTable[1].mVisible = 1;
                selectKartParts->mCellTable[0].mVisible = 1;
                selectKartParts->mCellTable[3].mVisible = 0;
                selectKartParts->mCellTable[2].mVisible = 0;
            } else {
                value = LookupFrameOffset(gSelectKart->mStateFrames);
                if (gSelectKart->mSlidingCellIndex == 2) {
                    value = -value;
                }
                selectKartParts->mCellTable[gSelectKart->mSlidingCellIndex].mOffsetX = value;
            }
            break;
        case 4:
            selectKart->mStateFrames = selectKart->mStateFrames + 1;
            selectKart = gSelectKart;
            if (selectKart->mStateFrames >= 5) {
                switch (selectKart->mMode) {
                    case 0:
                        GetRaceSetupCopy()->mEntries[gSelectKart->mEntryIndex].mKartIndex = selectKart->mKartIndex;
                        GetRaceSetupCopy()->mEntries[gSelectKart->mEntryIndex].mKartStored = 1;
                        FillRandomKartIndices();
                        gSelectKart->mState = 6;
                        break;
                    case 1:
                        RequestSelectReturnState4();
                        SetDataSharingSendByteInState8(gSelectKart->mKartIndex | 0x80);
                        gSelectKart->mState = 5;
                        break;
                    case 2:
                        RequestSelectReturnState4();
                        SetWiFiSessionOwnKartIndex(gSelectKart->mKartIndex);
                        gSelectKart->mState = 5;
                        break;
                }
                gSelectKart->mStateFrames = 0;
                selectKartParts->mCellTable[18].mVisible = 1;
                SetLabelPaletteIndex(data_usa_02153834[4], 1, selectKartParts->mLabelLayout,
                                     selectKartParts->mCellTable, selectKartParts->mCellLayout);
            }
            break;
        case 5:
            if (selectKart->mMode == 1 && IsEveryPlayerKartStored() != 0 ||
                gSelectKart->mMode == 2 && IsWiFiSessionStep7Reached() != 0) {
                gSelectKart->mStateFrames = 0;
                gSelectKart->mState = 6;
            }
            break;
        case 6:
            selectKart->mStateFrames = selectKart->mStateFrames + 1;
            if (gSelectKart->mStateFrames > 0x3c) {
                SetInterpolationStateIfOpposite(&gSelectKart->mInterpolations[0], 2);
                SetInterpolationStateIfOpposite(&gSelectKart->mInterpolations[1], 2);
                SetInterpolationStateIfOpposite(&gSelectKart->mInterpolations[2], 2);
                SetInterpolationStateIfOpposite(&gSelectKart->mInterpolations[3], 2);
                SetInterpolationStateIfOpposite(&gSelectKart->mInterpolations[4], 2);
                if (gSelectKart->mMode == 2) {
                    WriteWiFiSessionToRaceSetupCopy();
                    StartSelectKartEntryListKindIfUsed(3);
                } else {
                    StartSelectKartEntryListKindIfUsed(2);
                }
                if (SelectKartMB_IsMultiBootChildWrapper() == 0) {
                    StartKartModelMenuBg0Decrease();
                } else {
                    SlideOutSelectRaceRuleWait();
                }
                gSelectKart->mStateFrames = 0;
                gSelectKart->mState = 7;
            }
            break;
        case 7:
            if (selectKart->mInterpolations[4].mState == 3) {
                GetRaceSetupCopy()->mEntries[gSelectKart->mEntryIndex].mKartStored = selectKart->mResult == 1;
                gSelectKart->mState = 8;
            }
            SetSelectKartSPartsOffsetY();
            break;
        case 8:
            result = selectKart->mResult;
            break;
    }
    if (SelectKartMB_IsMultiBootChildWrapper() == 0) {
        RequestKartModelMenuCharacter(gSelectKart->mCharacterIndex);
        RequestKartModelMenuKart(gSelectKart->mKartIndex);
        AdvanceKartModelMenu(GetRaceSetupCopy()->mMirrorMode);
        DrawKartModelMenu();
    }
    selectKart = gSelectKart;
    if (selectKart->mEntryListUsed != FALSE) {
        AdvancePlayerEntryList();
    } else {
        DrawLayoutTable(characterParts->mCellLayout, characterParts->mCells, NULL, selectKart->mMainOam,
                        characterParts->mCellTable);
    }
    if (SelectKartMB_IsMultiBootChildWrapper() == 0) {
        selectKart = gSelectKart;
        if (selectKart->mState != 8) {
            DrawLayoutTable(selectKartParts->mCellLayout, selectKartParts->mCells, selectKartParts->mLabelLayout,
                            selectKart->mSubOam, selectKartParts->mCellTable);
        }
    } else {
        AdvanceSelectRaceRuleWait();
    }
    switch (result) {
        case 1:
            GetRaceSetupCopy()->mEntryTransition = 0;
            break;
        case 2:
            GetRaceSetupCopy()->mEntryTransition = 2;
            break;
    }
    return result;
}
