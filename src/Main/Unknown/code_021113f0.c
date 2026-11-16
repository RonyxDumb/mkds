#include "Main/Unknown/code_021113f0.h"
#include "Main/System/Heap.h"

#include "Main/Unknown/code_02111428.h"
#include "Main/Unknown/code_021114cc.h"
#include "Main/Unknown/code_021144b4.h"
#include "Main/Unknown/code_0211732c.h"
#include "Main/Ui/BackScreen.h"
#include "Main/Unknown/code_0212a920.h"
#include "Main/Unknown/code_0212abd0.h"
#include "Main/Unknown/code_0212a910.h"
#include "Main/Unknown/unk_0216d000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_02111450.h"
#include "Main/Unknown/code_02111488.h"
#include "Main/Unknown/code_02111494.h"
#include "Main/Unknown/code_021114b0.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02111a98.h"
#include "Main/Unknown/code_02114158.h"
#include "Main/Scene/RecordVSErase.h"
#include "Main/Unknown/code_0212a000.h"
#include "01/code_0219a050.h"
#include "Main/Unknown/code_02111584.h"
#include "Main/Unknown/code_021115b0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0211130c.h"
#include "Main/Unknown/code_02111684.h"
#include "Main/Unknown/code_021144c0.h"
#include "Main/Unknown/code_02125000.h"
#include "01/OptionSelectMenu.h"
#include "Main/Unknown/code_02111b40.h"
#include "Main/Unknown/code_02111b94.h"
#include "Main/Unknown/code_02112b48.h"
#include "registers.h"
#include "code_0201ea58.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_021128b4.h"
#include "Main/Unknown/code_021128cc.h"
#include "Main/Unknown/code_02112b30.h"
#include "Main/Unknown/code_021137a8.h"
#include "Main/Unknown/code_021138e4.h"
#include "Main/Unknown/code_021139b4.h"
#include "Main/Unknown/code_02113790.h"
#include "Main/Unknown/code_02113ef0.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217d068.h"
#include "00/code_02181f98.h"
#include "01/code_02193c5c.h"
#include "01/code_021956dc.h"

#pragma thumb on

void AdvanceRecordVSState0(void) {
    int fadesClear;
    fadesClear = mbright_isFadedIn();
    if (fadesClear != 0) {
        RequestRecordVSState1();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceRecordVSState1(void) {
    u16 transientBase;
    u16 mainBase;
    s32 i;
    s32 j;
    s16 offset;
    gRecordVS->mStateFrames = gRecordVS->mStateFrames + 1;
    offset = mutil_interpolate(1, -192, 0, gRecordVS->mStateFrames, 10);
    gRecordVS->mBg0OffsetY = offset;
    gRecordVS->mBg1OffsetY = offset;
    mainBase = gRecordVS->mRecordVSMBncl->mUnk_06;
    gRecordVS->mRecordVSMTable[0].mOffsetY = offset;
    gRecordVS->mRecordVSMTable[1].mOffsetY = offset;
    gRecordVS->mRecordVSMTable[2].mOffsetY = offset;
    gRecordVS->mRecordVSMTable[3].mOffsetY = offset;
    gRecordVS->mRecordVSMTable[mainBase].mOffsetY = offset;
    gRecordVS->mRecordVSMTable[mainBase + 1].mOffsetY = offset;
    gRecordVS->mRecordVSMTable[mainBase + 11].mOffsetY = offset;
    gRecordVS->mRecordVSMTable[mainBase + 12].mOffsetY = offset;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            gRecordVS->mRecordVSMTable[mainBase + gRecordVSGridLabelIndices[i][j]].mOffsetY = offset;
        }
    }
    transientBase = gRecordVS->mRecordVSMTransientBncl->mUnk_06;
    gRecordVS->mRecordVSMTransientTable[1].mOffsetY = offset;
    gRecordVS->mRecordVSMTransientTable[0].mOffsetY = offset;
    gRecordVS->mRecordVSMTransientTable[transientBase].mOffsetY = offset;
    gRecordVS->mRecordVSMTransientTable[transientBase + 1].mOffsetY = offset;
    gRecordVS->mRecordVSMTransientTable[transientBase + 14].mOffsetY = offset;
    for (j = 0; j < 12; j++) {
        gRecordVS->mRecordVSMTransientTable[transientBase + gRecordVSFriendKeyLabelIndices[j]].mOffsetY = offset;
    }
    if (gRecordVS->mStateFrames >= 10) {
        RequestRecordVSState2AndRefreshPage();
    }
}

void AdvanceRecordVSState2(void) {
    s16 offset;
    s32 i;
    u16 subBase;
    AdvanceRecordVSOffsetTimers();
    gRecordVS->mStateFrames = gRecordVS->mStateFrames + 1;
    offset = mutil_interpolate(1, 0x100, 0, gRecordVS->mStateFrames, 10);
    subBase = gRecordVS->mRecordVSSBncl->mUnk_06;
    gRecordVS->mRecordVSSTable[20].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[21].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[24].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[25].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[26].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[subBase + 5].mOffsetX = offset;
    for (i = 0; i < 5; i++) {
        gRecordVS->mRecordVSSTable[gRecordVSUnhighlightedObjectIndices[i]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSHighlightObjectIndices[i]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSUnflaggedObjectIndices[i]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSFlaggedObjectIndices[i]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[subBase + gRecordVSRowLabelIndices[i]].mOffsetX = offset;
    }
    if (gRecordVS->mStateFrames >= 10) {
        RequestRecordVSState3();
    }
    if (gRecordVS->mStateFrames == 4) {
        gRecordVS->mRecordVSSTable[24].mVisible = 1;
        gRecordVS->mRecordVSSTable[25].mVisible = 0;
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceRecordVSState3(void) {
    int selectReturnState2NoRequest;
    selectReturnState2NoRequest = IsSelectReturnState2NoState3Or4Request();
    if (selectReturnState2NoRequest != 0) {
        RequestRecordVSState4();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceRecordVSState4(void) {
    s32 a;
    s32 b;
    InputSlotIndex inputSlotIndex;
    BOOL g;
    BOOL f;
    u16 x;
    InputSlot *touchSlot;
    InputSlot *keySlot;
    s16 rowIndex;
    a = -1;
    b = -1;
    inputSlotIndex = UNK_02175628_INDEX_8;
    AdvanceRecordVSOffsetTimers();
    AdvanceRecordVSIndexChange();
    g = TRUE;
    f = FALSE;
    touchSlot = &data_02175674[inputSlotIndex];
    x = data_02175674[inputSlotIndex].mPressedBits;
    if (x == 0 && data_02175680[inputSlotIndex].mPressedBits < 5) {
        f = TRUE;
    }
    if (f == FALSE && x == 0) {
        g = FALSE;
    }
    if (g != FALSE) {
        a = jn_ui_checkTouch(gRecordVS->mRecordVSSBnbl, data_02175670[inputSlotIndex].mPressedBits,
                                    data_02175672[inputSlotIndex].mPressedBits);
    }
    g = FALSE;
    f = FALSE;
    x = touchSlot->mPressedBits;
    if (x == 0 && data_02175680[inputSlotIndex].mPressedBits < 5) {
        f = TRUE;
    }
    if (f == FALSE && data_0217567c[inputSlotIndex].mPressedBits == 0 && x != 0) {
        g = TRUE;
    }
    if (g != FALSE) {
        b = jn_ui_checkTouch(gRecordVS->mRecordVSSBnbl, data_02175670[inputSlotIndex].mPressedBits,
                                    data_02175672[inputSlotIndex].mPressedBits);
    }
    if (a != 10) {
        gRecordVS->mUnk_88 = FALSE;
    }
    if (a != 11) {
        gRecordVS->mUnk_8c = FALSE;
    }
    keySlot = &gInputUnits[inputSlotIndex];
    if ((u16) (gInputUnits[inputSlotIndex].mPressedBits & PAD_KEY_B) == 0) {
        g = FALSE;
        f = FALSE;
        x = touchSlot->mPressedBits;
        if (x == 0 && data_02175680[inputSlotIndex].mPressedBits < 5) {
            f = TRUE;
        }
        if (f == FALSE && data_0217567c[inputSlotIndex].mPressedBits == 0 && x != 0) {
            g = TRUE;
        }
        if (g == FALSE ||
            gmenu_checkSelectReturnTouch(data_02175670[inputSlotIndex].mPressedBits,
                                                            data_02175672[inputSlotIndex].mPressedBits) == FALSE) {
            goto l1;
        }
    }
    if (IsRecordVSIndexChangeRunning() != 0) {
        return;
    }
    RequestRecordVSState7();
    if (GetRecordPrevScene() == 12) {
        gRecordVS->mUnk_90 = 6;
        RequestSelectReturnState3WithSound(1);
        return;
    }
    gRecordVS->mUnk_90 = 0;
    RequestSelectReturnState3WithSound(0);
    return;
l1:
    if ((a == 10 && gRecordVS->mUnk_88 != FALSE) || (b == 10 && gRecordVS->mUnk_88 == FALSE) ||
        (u16) (data_0217562a[inputSlotIndex].mBits & PAD_KEY_LEFT) != 0) {
        if (IsRecordVSIndexChangeRunning() != 0) {
            return;
        }
        if (gRecordVS->mRecordVSSTable[20].mVisible == 0) {
            return;
        }
        gRecordVS->mPageDecrement = 1;
        gRecordVS->mOffsetTimers[0] = 6;
        gRecordVS->mUnk_88 = TRUE;
        RequestRecordVSState5();
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 2);
        return;
    }
    if ((a == 11 && gRecordVS->mUnk_8c != FALSE) || (b == 11 && gRecordVS->mUnk_8c == FALSE) ||
        (u16) (data_0217562a[inputSlotIndex].mBits & PAD_KEY_RIGHT) != 0) {
        if (IsRecordVSIndexChangeRunning() != 0) {
            return;
        }
        if (gRecordVS->mRecordVSSTable[21].mVisible == 0) {
            return;
        }
        gRecordVS->mPageDecrement = 0;
        gRecordVS->mOffsetTimers[1] = 6;
        gRecordVS->mUnk_8c = TRUE;
        RequestRecordVSState5();
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 2);
        return;
    }
    if ((u32) (b - 5) <= 4) {
        rowIndex = data_0215c44c[b];
        if (IsRecordVSRowFilled(rowIndex) == 0) {
            return;
        }
        gRecordVS->mIndex = rowIndex;
        ToggleRecordVSRowFlag(rowIndex);
        return;
    }
    if ((u32) b <= 4) {
        rowIndex = data_0215c44c[b];
        if (rowIndex == gRecordVS->mIndex) {
            ToggleRecordVSRowFlag(rowIndex);
            return;
        }
        if (IsRecordVSRowFilled(rowIndex) == 0) {
            return;
        }
        gRecordVS->mIndex = rowIndex;
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
        return;
    }
    if (b == 12 || (u16) (keySlot->mPressedBits & PAD_KEY_X) != 0) {
        RequestRecordVSState9();
        gRecordVS->mUnk_90 = 4;
        return;
    }
    if ((u16) (keySlot->mPressedBits & PAD_KEY_A) != 0) {
        ToggleRecordVSRowFlag(gRecordVS->mIndex);
        return;
    }
    if (mutil_checkKeys(8, PAD_KEY_UP) != 0) {
        DecrementRecordVSIndex();
        return;
    }
    if (mutil_checkKeys(8, PAD_KEY_DOWN) != 0) {
        IncrementRecordVSIndex();
    }
}

void AdvanceRecordVSState5(void) {
    s32 i;
    u16 transientBase;
    u16 subBase;
    s32 l;
    u16 mainBase;
    s32 j;
    s16 endOffset;
    s16 offset;
    endOffset = 0;
    AdvanceRecordVSOffsetTimers();
    switch (gRecordVS->mPageDecrement) {
        case 0:
            endOffset = -256;
            break;
        case 1:
            endOffset = 0x100;
            break;
    }
    gRecordVS->mStateFrames = gRecordVS->mStateFrames + 1;
    mainBase = gRecordVS->mRecordVSMBncl->mUnk_06;
    transientBase = gRecordVS->mRecordVSMTransientBncl->mUnk_06;
    subBase = gRecordVS->mRecordVSSBncl->mUnk_06;
    offset = mutil_interpolate(1, 0, endOffset, gRecordVS->mStateFrames, 10);
    gRecordVS->mBg0OffsetX = offset;
    gRecordVS->mBg1OffsetX = offset;
    gRecordVS->mRecordVSMTable[1].mOffsetX = offset;
    gRecordVS->mRecordVSMTable[2].mOffsetX = offset;
    gRecordVS->mRecordVSMTable[3].mOffsetX = offset;
    gRecordVS->mRecordVSMTable[mainBase].mOffsetX = offset;
    gRecordVS->mRecordVSMTable[mainBase + 1].mOffsetX = offset;
    gRecordVS->mRecordVSMTable[mainBase + 11].mOffsetX = offset;
    gRecordVS->mRecordVSMTable[mainBase + 12].mOffsetX = offset;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            gRecordVS->mRecordVSMTable[mainBase + gRecordVSGridLabelIndices[i][j]].mOffsetX = offset;
        }
    }
    gRecordVS->mRecordVSMTransientTable[1].mOffsetX = offset;
    gRecordVS->mRecordVSMTransientTable[transientBase].mOffsetX = offset;
    gRecordVS->mRecordVSMTransientTable[transientBase + 1].mOffsetX = offset;
    gRecordVS->mRecordVSMTransientTable[transientBase + 14].mOffsetX = offset;
    for (j = 0; j < 12; j++) {
        gRecordVS->mRecordVSMTransientTable[transientBase + gRecordVSFriendKeyLabelIndices[j]].mOffsetX = offset;
    }
    for (l = 0; l < 5; l++) {
        gRecordVS->mRecordVSSTable[gRecordVSUnhighlightedObjectIndices[l]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSHighlightObjectIndices[l]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSUnflaggedObjectIndices[l]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSFlaggedObjectIndices[l]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[subBase + gRecordVSRowLabelIndices[l]].mOffsetX = offset;
    }
    if (gRecordVS->mStateFrames >= 10) {
        RequestRecordVSState6AndChangePage();
    }
}

void AdvanceRecordVSState6(void) {
    s32 i;
    u16 transientBase;
    u16 subBase;
    s32 l;
    u16 mainBase;
    s32 j;
    s16 startOffset;
    s16 offset;
    startOffset = 0;
    AdvanceRecordVSOffsetTimers();
    switch (gRecordVS->mPageDecrement) {
        case 0:
            startOffset = 0x100;
            break;
        case 1:
            startOffset = -256;
            break;
    }
    gRecordVS->mStateFrames = gRecordVS->mStateFrames + 1;
    mainBase = gRecordVS->mRecordVSMBncl->mUnk_06;
    transientBase = gRecordVS->mRecordVSMTransientBncl->mUnk_06;
    subBase = gRecordVS->mRecordVSSBncl->mUnk_06;
    offset = mutil_interpolate(1, startOffset, 0, gRecordVS->mStateFrames, 10);
    gRecordVS->mBg0OffsetX = offset;
    gRecordVS->mBg1OffsetX = offset;
    gRecordVS->mRecordVSMTable[1].mOffsetX = offset;
    gRecordVS->mRecordVSMTable[2].mOffsetX = offset;
    gRecordVS->mRecordVSMTable[3].mOffsetX = offset;
    gRecordVS->mRecordVSMTable[mainBase].mOffsetX = offset;
    gRecordVS->mRecordVSMTable[mainBase + 1].mOffsetX = offset;
    gRecordVS->mRecordVSMTable[mainBase + 11].mOffsetX = offset;
    gRecordVS->mRecordVSMTable[mainBase + 12].mOffsetX = offset;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            gRecordVS->mRecordVSMTable[mainBase + gRecordVSGridLabelIndices[i][j]].mOffsetX = offset;
        }
    }
    gRecordVS->mRecordVSMTransientTable[1].mOffsetX = offset;
    gRecordVS->mRecordVSMTransientTable[transientBase].mOffsetX = offset;
    gRecordVS->mRecordVSMTransientTable[transientBase + 1].mOffsetX = offset;
    gRecordVS->mRecordVSMTransientTable[transientBase + 14].mOffsetX = offset;
    for (j = 0; j < 12; j++) {
        gRecordVS->mRecordVSMTransientTable[transientBase + gRecordVSFriendKeyLabelIndices[j]].mOffsetX = offset;
    }
    for (l = 0; l < 5; l++) {
        gRecordVS->mRecordVSSTable[gRecordVSUnhighlightedObjectIndices[l]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSHighlightObjectIndices[l]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSUnflaggedObjectIndices[l]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSFlaggedObjectIndices[l]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[subBase + gRecordVSRowLabelIndices[l]].mOffsetX = offset;
    }
    if (gRecordVS->mStateFrames >= 10) {
        RequestRecordVSState4();
    }
}

void AdvanceRecordVSState7(void) {
    s16 offset;
    s32 i;
    u16 subBase;
    gRecordVS->mStateFrames = gRecordVS->mStateFrames + 1;
    offset = mutil_interpolate(1, 0, 0x100, gRecordVS->mStateFrames, 10);
    subBase = gRecordVS->mRecordVSSBncl->mUnk_06;
    gRecordVS->mRecordVSSTable[20].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[21].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[24].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[25].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[26].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[subBase + 5].mOffsetX = offset;
    for (i = 0; i < 5; i++) {
        gRecordVS->mRecordVSSTable[gRecordVSUnhighlightedObjectIndices[i]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSHighlightObjectIndices[i]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSUnflaggedObjectIndices[i]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSFlaggedObjectIndices[i]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[subBase + gRecordVSRowLabelIndices[i]].mOffsetX = offset;
    }
    if (gRecordVS->mStateFrames >= 10) {
        RequestRecordVSState8();
    }
    if (gRecordVS->mStateFrames == 6) {
        gRecordVS->mRecordVSSTable[24].mVisible = 0;
        gRecordVS->mRecordVSSTable[25].mVisible = 0;
    }
}

void AdvanceRecordVSState8(void) {
    u16 transientBase;
    u16 mainBase;
    s32 i;
    s32 j;
    s16 offset;
    if (GetRecordNextScene() == -1 && gRecordVS->mUnk_90 == 6) {
        SetRecordNextScene(12);
    }
    gRecordVS->mStateFrames = gRecordVS->mStateFrames + 1;
    offset = mutil_interpolate(1, 0, -192, gRecordVS->mStateFrames, 10);
    gRecordVS->mBg0OffsetY = offset;
    gRecordVS->mBg1OffsetY = offset;
    mainBase = gRecordVS->mRecordVSMBncl->mUnk_06;
    gRecordVS->mRecordVSMTable[0].mOffsetY = offset;
    gRecordVS->mRecordVSMTable[1].mOffsetY = offset;
    gRecordVS->mRecordVSMTable[2].mOffsetY = offset;
    gRecordVS->mRecordVSMTable[3].mOffsetY = offset;
    gRecordVS->mRecordVSMTable[mainBase].mOffsetY = offset;
    gRecordVS->mRecordVSMTable[mainBase + 1].mOffsetY = offset;
    gRecordVS->mRecordVSMTable[mainBase + 11].mOffsetY = offset;
    gRecordVS->mRecordVSMTable[mainBase + 12].mOffsetY = offset;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            gRecordVS->mRecordVSMTable[mainBase + gRecordVSGridLabelIndices[i][j]].mOffsetY = offset;
        }
    }
    transientBase = gRecordVS->mRecordVSMTransientBncl->mUnk_06;
    gRecordVS->mRecordVSMTransientTable[1].mOffsetY = offset;
    gRecordVS->mRecordVSMTransientTable[0].mOffsetY = offset;
    gRecordVS->mRecordVSMTransientTable[transientBase].mOffsetY = offset;
    gRecordVS->mRecordVSMTransientTable[transientBase + 1].mOffsetY = offset;
    gRecordVS->mRecordVSMTransientTable[transientBase + 14].mOffsetY = offset;
    for (j = 0; j < 12; j++) {
        gRecordVS->mRecordVSMTransientTable[transientBase + gRecordVSFriendKeyLabelIndices[j]].mOffsetY = offset;
    }
    if (gRecordVS->mStateFrames >= 10 && gRecordVS->mUnk_90 != 6) {
        RequestRecordScreen(gRecordVS->mUnk_90);
    }
}

void AdvanceRecordVSState9(void) {
    s16 offset;
    u16 subBase;
    gRecordVS->mStateFrames = gRecordVS->mStateFrames + 1;
    offset = mutil_getButtonOutEffectOffset(gRecordVS->mStateFrames);
    subBase = gRecordVS->mRecordVSSBncl->mUnk_06;
    gRecordVS->mRecordVSSTable[24].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[25].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[26].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[subBase + 5].mOffsetX = offset;
    if (gRecordVS->mStateFrames >= 10) {
        RequestRecordVSState10();
    }
}

void AdvanceRecordVSState10(void) {
    s16 offset;
    s32 i;
    u16 subBase;
    gRecordVS->mStateFrames = gRecordVS->mStateFrames + 1;
    offset = mutil_interpolate(1, 0, 0x100, gRecordVS->mStateFrames, 10);
    subBase = gRecordVS->mRecordVSSBncl->mUnk_06;
    gRecordVS->mRecordVSSTable[20].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[21].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[24].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[25].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[26].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[subBase + 5].mOffsetX = offset;
    for (i = 0; i < 5; i++) {
        gRecordVS->mRecordVSSTable[gRecordVSUnhighlightedObjectIndices[i]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSHighlightObjectIndices[i]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSUnflaggedObjectIndices[i]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSFlaggedObjectIndices[i]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[subBase + gRecordVSRowLabelIndices[i]].mOffsetX = offset;
    }
    if (gRecordVS->mStateFrames >= 10) {
        RequestRecordScreen(gRecordVS->mUnk_90);
    }
    if (gRecordVS->mStateFrames == 6) {
        gRecordVS->mRecordVSSTable[24].mVisible = 0;
        gRecordVS->mRecordVSSTable[25].mVisible = 0;
    }
}

void AdvanceRecordVSState11(void) {
    s16 offset;
    s32 i;
    u16 subBase;
    AdvanceRecordVSOffsetTimers();
    gRecordVS->mStateFrames = gRecordVS->mStateFrames + 1;
    offset = mutil_interpolate(1, 0x100, 0, gRecordVS->mStateFrames, 10);
    subBase = gRecordVS->mRecordVSSBncl->mUnk_06;
    gRecordVS->mRecordVSSTable[20].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[21].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[24].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[25].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[26].mOffsetX = offset;
    gRecordVS->mRecordVSSTable[subBase + 5].mOffsetX = offset;
    for (i = 0; i < 5; i++) {
        gRecordVS->mRecordVSSTable[gRecordVSUnhighlightedObjectIndices[i]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSHighlightObjectIndices[i]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSUnflaggedObjectIndices[i]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[gRecordVSFlaggedObjectIndices[i]].mOffsetX = offset;
        gRecordVS->mRecordVSSTable[subBase + gRecordVSRowLabelIndices[i]].mOffsetX = offset;
    }
    if (gRecordVS->mStateFrames >= 10) {
        RequestRecordVSState4();
    }
    if (gRecordVS->mStateFrames == 2) {
        gRecordVS->mRecordVSSTable[24].mVisible = 1;
        gRecordVS->mRecordVSSTable[25].mVisible = 0;
    }
}

void AdvanceRecordVS(void) {
    RecordVS *recordVS;
    gRecordVS->mState = gRecordVS->mNextState;
    switch (gRecordVS->mState) {
        case 0:
            AdvanceRecordVSState0();
            break;
        case 1:
            AdvanceRecordVSState1();
            break;
        case 2:
            AdvanceRecordVSState2();
            break;
        case 3:
            AdvanceRecordVSState3();
            break;
        case 4:
            AdvanceRecordVSState4();
            break;
        case 5:
            AdvanceRecordVSState5();
            break;
        case 6:
            AdvanceRecordVSState6();
            break;
        case 7:
            AdvanceRecordVSState7();
            break;
        case 8:
            AdvanceRecordVSState8();
            break;
        case 9:
            AdvanceRecordVSState9();
            break;
        case 10:
            AdvanceRecordVSState10();
            break;
        case 11:
            AdvanceRecordVSState11();
            break;
    }
    AdvanceRecordVSRowObjects();
    recordVS = gRecordVS;
    switch (recordVS->mShowsFriendKey) {
        case 0:
            jn_ui_renderElements(recordVS->mRecordVSMBncl, recordVS->mRecordVSMNcer, recordVS->mRecordVSMBnll,
                            GetRecordMainOam(), recordVS->mRecordVSMTable);
            break;
        case 1:
            jn_ui_renderElements(recordVS->mRecordVSMTransientBncl, recordVS->mRecordVSMNcer,
                            recordVS->mRecordVSMTransientBnll, GetRecordMainOam(), recordVS->mRecordVSMTransientTable);
            break;
    }
    recordVS = gRecordVS;
    jn_ui_renderElements(recordVS->mRecordVSSBncl, recordVS->mRecordVSSNcer, recordVS->mRecordVSSBnll, GetRecordSubOam(),
                    recordVS->mRecordVSSTable);
}

#pragma thumb off

#pragma thumb on

void WriteRecordVSBgOffsets(void) {
    reg_G2_BG0OFS = (-gRecordVS->mBg0OffsetX & 0x1ff) | ((-gRecordVS->mBg0OffsetY << 16) & 0x1ff0000);
    reg_G2_BG1OFS = (-gRecordVS->mBg1OffsetX & 0x1ff) | ((-gRecordVS->mBg1OffsetY << 16) & 0x1ff0000);
    AdvanceRecordSceneRegistersTimer();
}

#pragma thumb off

#pragma thumb on

void WriteRecordVSRegisters(void) {
    u32 planeBits;
    if (GetRecordPrevScene() == 12) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x1b00;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | 0x1600;
    } else {
        planeBits = (reg_GX_DISPCNT & 0x1f00) >> 8;
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | ((planeBits | 0x13) << 8);
    }
}

void RegisterRecordVSCallbacks(void) {
    RecordScreenCallbacks callbacks = {InitRecordVS, ReleaseRecordVS, AdvanceRecordVS, WriteRecordVSBgOffsets,
                                       WriteRecordVSRegisters};
    SetRecordScreenCallbacks(&callbacks);
}

void func_02111a98(void) {
    gRecordScene->mScreenCallbacks.mInit = NULL;
    gRecordScene->mScreenCallbacks.mRelease = NULL;
    gRecordScene->mScreenCallbacks.mAdvance = NULL;
    gRecordScene->mScreenCallbacks.mWriteOffsets = NULL;
}

#pragma thumb off

#pragma thumb on

void LoadRecordSceneData(void) {
    void *file;
    LoadedPartPointer loadedPart;
    loadedPart.mNcgr = NULL;
    file = arc_getSceneArcFile(gRecordTopMenuMBNcgrName);
    g2du_unpackCharacterDataBG(&loadedPart.mNcgr, file);
    file = arc_getSceneArcFile(gRecordTopMenuMBNclrName);
    g2du_unpackPaletteData(&loadedPart.mNclr, file);
    file = arc_getSceneArcFile(gRecordTopMenuMNscrName);
    g2du_unpackScreenData(&loadedPart.mNscr, file);
    file = arc_getSceneArcFile(gRecordTopMenuMNcgrName);
    g2du_unpackCharacterData(&loadedPart.mNcgr, file);
    file = arc_getSceneArcFile(gRecordTopMenuMNcerName);
    g2du_unpackCellBankData(&loadedPart.mNcer, file);
    file = arc_getSceneArcFile(gRecordTopMenuMONclrName);
    g2du_unpackPaletteData(&loadedPart.mNclr, file);
    file = arc_getSceneArcFile(gRecordTopMenuSNcgrName);
    g2du_unpackCharacterData(&loadedPart.mNcgr, file);
    file = arc_getSceneArcFile(gRecordTopMenuSNcerName);
    g2du_unpackCellBankData(&loadedPart.mNcer, file);
    file = arc_getSceneArcFile(gRecordTopMenuSONclrName);
    g2du_unpackPaletteData(&loadedPart.mNclr, file);
    file = arc_getSceneArcFile(gRecordGpxMNcgrName);
    g2du_unpackCharacterDataBG(&loadedPart.mNcgr, file);
    file = arc_getSceneArcFile(gRecordGpxMNcerName);
    g2du_unpackCellBankData(&loadedPart.mNcer, file);
    file = arc_getSceneArcFile(gRecordGpxMONclrName);
    g2du_unpackPaletteData(&loadedPart.mNclr, file);
    file = arc_getSceneArcFile(gRecordGpxMBNcgrName);
    g2du_unpackCharacterData(&loadedPart.mNcgr, file);
    file = arc_getSceneArcFile(gRecordGpxMBNclrName);
    g2du_unpackPaletteData(&loadedPart.mNclr, file);
    file = arc_getSceneArcFile(gRecordGpxMNscrName);
    g2du_unpackScreenData(&loadedPart.mNscr, file);
    file = arc_getSceneArcFile(gRecordGpxSNcgrName);
    g2du_unpackCharacterDataBG(&loadedPart.mNcgr, file);
    file = arc_getSceneArcFile(gRecordGpxSNcerName);
    g2du_unpackCellBankData(&loadedPart.mNcer, file);
    file = arc_getSceneArcFile(gRecordGpxSONclrName);
    g2du_unpackPaletteData(&loadedPart.mNclr, file);
    file = arc_getSceneArcFile(gRecordGpxSBNcgrName);
    g2du_unpackCharacterData(&loadedPart.mNcgr, file);
    file = arc_getSceneArcFile(gRecordGpxSBNclrName);
    g2du_unpackPaletteData(&loadedPart.mNclr, file);
    file = arc_getSceneArcFile(gRecordGpxSNscrName);
    g2du_unpackScreenData(&loadedPart.mNscr, file);
    file = arc_getSceneArcFile(gRecordTrophyONcgrName);
    g2du_unpackCharacterDataBG(&loadedPart.mNcgr, file);
    file = arc_getSceneArcFile(gRecordTrophyONcerName);
    g2du_unpackCellBankData(&loadedPart.mNcer, file);
    file = arc_getSceneArcFile(gRecordTrophySONclrName);
    g2du_unpackPaletteData(&loadedPart.mNclr, file);
    file = arc_getSceneArcFile(gRecordTAttMNcgrName);
    g2du_unpackCharacterDataBG(&loadedPart.mNcgr, file);
    file = arc_getSceneArcFile(gRecordTAttMNcerName);
    g2du_unpackCellBankData(&loadedPart.mNcer, file);
    file = arc_getSceneArcFile(gRecordTAttMONclrName);
    g2du_unpackPaletteData(&loadedPart.mNclr, file);
    file = arc_getSceneArcFile(gRecordTAttMBNcgrName);
    g2du_unpackCharacterData(&loadedPart.mNcgr, file);
    file = arc_getSceneArcFile(gRecordTAttMNscrName);
    g2du_unpackScreenData(&loadedPart.mNscr, file);
    file = arc_getSceneArcFile(gRecordTAttMScoreNscrName);
    g2du_unpackScreenData(&loadedPart.mNscr, file);
    file = arc_getSceneArcFile(gRecordTAttMBNclrName);
    g2du_unpackPaletteData(&loadedPart.mNclr, file);
    file = arc_getSceneArcFile(gRecordTAttSNcgrName);
    g2du_unpackCharacterDataBG(&loadedPart.mNcgr, file);
    file = arc_getSceneArcFile(gRecordTAttSNcerName);
    g2du_unpackCellBankData(&loadedPart.mNcer, file);
    file = arc_getSceneArcFile(gRecordTAttSONclrName);
    g2du_unpackPaletteData(&loadedPart.mNclr, file);
    file = arc_getSceneArcFile(gRecordTAttSBNcgrName);
    g2du_unpackCharacterData(&loadedPart.mNcgr, file);
    file = arc_getSceneArcFile(gRecordTAttSBNclrName);
    g2du_unpackPaletteData(&loadedPart.mNclr, file);
    file = arc_getSceneArcFile(gRecordTAttSNscrName);
    g2du_unpackScreenData(&loadedPart.mNscr, file);
    file = arc_getSceneArcFile(gRecordVSMNcgrName);
    g2du_unpackCharacterDataBG(&loadedPart.mNcgr, file);
    file = arc_getSceneArcFile(gRecordVSMNcerName);
    g2du_unpackCellBankData(&loadedPart.mNcer, file);
    file = arc_getSceneArcFile(gRecordVSMONclrName);
    g2du_unpackPaletteData(&loadedPart.mNclr, file);
    file = arc_getSceneArcFile(gRecordVSMBNcgrName);
    g2du_unpackCharacterData(&loadedPart.mNcgr, file);
    file = arc_getSceneArcFile(gRecordVSMNscrName);
    g2du_unpackScreenData(&loadedPart.mNscr, file);
    file = arc_getSceneArcFile(gRecordVSM02NscrName);
    g2du_unpackScreenData(&loadedPart.mNscr, file);
    file = arc_getSceneArcFile(gRecordVSMBNclrName);
    g2du_unpackPaletteData(&loadedPart.mNclr, file);
    file = arc_getSceneArcFile(gRecordVSSNcgrName);
    g2du_unpackCharacterDataBG(&loadedPart.mNcgr, file);
    file = arc_getSceneArcFile(gRecordVSSNcerName);
    g2du_unpackCellBankData(&loadedPart.mNcer, file);
    file = arc_getSceneArcFile(gRecordVSSONclrName);
    g2du_unpackPaletteData(&loadedPart.mNclr, file);
    file = arc_getSceneArcFile(gRecordVSM03NscrName);
    g2du_unpackScreenData(&loadedPart.mNscr, file);
    file = arc_getSceneArcFile(gRecordVSSBNcgrName);
    g2du_unpackCharacterData(&loadedPart.mNcgr, file);
    file = arc_getSceneArcFile(gRecordVSSEraseNscrName);
    g2du_unpackScreenData(&loadedPart.mNscr, file);
    file = arc_getSceneArcFile(gRecordVSSBNclrName);
    g2du_unpackPaletteData(&loadedPart.mNclr, file);
    kic_unpackDataForGhost();
    LoadCupMarkData();
}

#pragma thumb off

#pragma thumb on

void InitRecordSceneObject(void *heap, s16 previousScene) {
    Unk02125de0Arg v;
    gRecordScene = heap_alloc(heap, 0x34);
    gRecordScene->mHeap = heap;
    gRecordScene->mPageIndex = 0;
    gRecordScene->mIndex = 0;
    func_021250b0(heap);
    InitLinkLevelIcons(heap, GetRecordMainOam());
    v.mUnk_00 = TRUE;
    v.mUnk_04 = m2d_getFont(1);
    v.mUnk_08 = 0;
    v.mUnk_0c = 1;
    v.mUnk_10 = 0;
    v.mUnk_14 = FALSE;
    v.mUnk_1c = TRUE;
    v.mUnk_20 = TRUE;
    v.mUnk_24 = 0;
    gmenu_unpackData();
    gmenu_init(heap, &v);
    CreateRecordList(gRecordScene->mHeap);
    BuildRecordList();
    gRecordScene->mStateHeap = heap_createSubExpHeap(gRecordScene->mHeap);
    LoadRecordSceneData();
    func_02111a98();
    gRecordScene->mPrevScene = previousScene;
    gRecordScene->mNextScene = -1;
    gRecordScene->mNextScreen = -1;
    gRecordScene->mRegistersTimer = 2;
    if (gRecordScene->mPrevScene == 12) {
        gRecordScene->mPrevScreen = 6;
        gRecordScene->mScreen = 3;
        RegisterRecordVSCallbacks();
    } else {
        gRecordScene->mPrevScreen = 5;
        gRecordScene->mScreen = 0;
        RegisterRecordTopMenuCallbacks();
    }
    gRecordScene->mScreenCallbacks.mInit(gRecordScene->mStateHeap);
}

#pragma thumb off

#pragma thumb on

void ReleaseRecordSceneObject(void) {
    ClearRecordListPointer();
    gRecordScene->mScreenCallbacks.mRelease();
    func_02111a98();
    ClearLinkLevelIconsPointer();
    gmenu_finish();
    *&gRecordScene = NULL;
}

#pragma thumb off

#pragma thumb on

// Switches to the requested screen when there is one, then runs the running screen's step.
void AdvanceRecordScene(void) {
    if (gRecordScene->mNextScreen != -1) {
        gRecordScene->mScreenCallbacks.mRelease();
        func_02111a98();
        heap_destroySubHeap(gRecordScene->mStateHeap);
        gRecordScene->mStateHeap = heap_createSubExpHeap(gRecordScene->mHeap);
        switch (gRecordScene->mNextScreen) {
            case 0:
                if (gRecordScene->mScreen == 3) {
                    BuildRecordList();
                }
                RegisterRecordTopMenuCallbacks();
                break;
            case 1:
                RegisterRecordGpxCallbacks();
                break;
            case 2:
                RegisterRecordTAttCallbacks();
                break;
            case 3:
                RegisterRecordVSCallbacks();
                break;
            case 4:
                RegisterRecordVSEraseCallbacks();
                break;
        }
        gRecordScene->mPrevScreen = gRecordScene->mScreen;
        gRecordScene->mScreen = gRecordScene->mNextScreen;
        gRecordScene->mNextScreen = -1;
        gRecordScene->mRegistersTimer = 2;
        gRecordScene->mScreenCallbacks.mInit(gRecordScene->mStateHeap);
    }
    gRecordScene->mScreenCallbacks.mAdvance();
    gmenu_render();
    AdvanceLinkLevelIcons();
}

#pragma thumb off

#pragma thumb on

void WriteRecordSceneRegisters(void) {
    gRecordScene->mScreenCallbacks.mWriteOffsets();
    gmenu_vblank();
}

#pragma thumb off

#pragma thumb on

void SetRecordScreenCallbacks(const void *callbacks) {
    gRecordScene->mScreenCallbacks = *(const RecordScreenCallbacks *) callbacks;
}

#pragma thumb off

#pragma thumb on
void RequestRecordScreen(s32 screen) {
    u32 screenCopy = screen;
    u32 unused;
    gRecordScene->mNextScreen = screenCopy;
}
#pragma thumb off

#pragma thumb on

u32 GetRecordPrevScreen(void) {
    return (gRecordScene->mPrevScreen);
}

u32 GetRecordPrevScene(void) {
    return (gRecordScene->mPrevScene);
}

u32 GetRecordNextScene(void) {
    return (gRecordScene->mNextScene);
}

void SetRecordNextScene(u32 scene) {
    gRecordScene->mNextScene = (u16) scene;
}

#pragma thumb off

#pragma thumb on

// Counts the registers timer down and calls the screen's register writer when it reaches 0.
void AdvanceRecordSceneRegistersTimer(void) {
    if (gRecordScene->mRegistersTimer > 0) {
        gRecordScene->mRegistersTimer = gRecordScene->mRegistersTimer - 1;
        if (gRecordScene->mRegistersTimer == 0) {
            gRecordScene->mScreenCallbacks.mWriteRegisters();
        }
    }
}

#pragma thumb off

#pragma thumb on
u32 GetRecordScenePageIndex(void) {
    u32 value0;
    u32 recordScene;
    value0 = (u32) &gRecordScene;
    recordScene = *(const u32 *) ((value0) + 0u);
    value0 = 48u;
    value0 = *(const s16 *) ((recordScene) + (value0));
    return value0;
}
#pragma thumb off

#pragma thumb on
u32 GetRecordSceneIndex(void) {
    u32 value0;
    u32 recordScene;
    value0 = (u32) &gRecordScene;
    recordScene = *(const u32 *) ((value0) + 0u);
    value0 = 50u;
    value0 = *(const s16 *) ((recordScene) + (value0));
    return value0;
}
#pragma thumb off

#pragma thumb on
void SetRecordScenePageIndex(u32 pageIndex) {
    u32 pageIndexCopy = pageIndex;
    u32 unused;
    gRecordScene->mPageIndex = (u16) pageIndexCopy;
}
#pragma thumb off

#pragma thumb on
void SetRecordSceneIndex(u32 index) {
    u32 indexCopy = index;
    u32 unused;
    gRecordScene->mIndex = (u16) indexCopy;
}
#pragma thumb off
