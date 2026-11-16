#include "Main/Unknown/code_02025f80.h"
#include "registers.h"

#include "Main/Unknown/code_02025edc.h"
#include "Main/Unknown/code_0202b000.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_0211f498.h"
#include "Main/Unknown/unk_02174000.h"
#include "code_0214a390.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_02025eb0.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025ebc.h"
#include "Main/Unknown/code_02027000.h"
#include "Main/Unknown/code_0202bb80.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_0202b604.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02077000.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02077bc0.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ae5d4.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_021105a0.h"
#include "Main/Unknown/code_021106a8.h"
#include "Main/Unknown/code_02116ec0.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0211f378.h"
#include "Main/Unknown/code_0211f394.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_02121e84.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02175628.h"
#include "code_0201ea58.h"
#include "Main/Unknown/code_02025b84.h"
#include "Main/Unknown/code_02025bb4.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_0202c000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_0211f4b0.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/code_02025f54.h"
#include "Main/Unknown/code_0202719c.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02025e28.h"

#pragma thumb on

void func_02027188(void) {
    func_0202719c();
    func_020271e8();
}

#pragma thumb off

#pragma thumb on

void func_020270fc(s32 previousTableIndex) {
    sMenuCsState->mUnk_064 = previousTableIndex;
    switch (sMenuCsState->mUnk_07c) {
        case 8:
            func_02027be0();
            break;
        case 9:
            func_02027a58();
            break;
        case 10:
            func_02027850();
            break;
        case 11:
            func_02027648();
            break;
        case 12:
            func_02027448();
            break;
    }
    func_02027188();
    SPM_CharName_202721C();
    interp_setStateDirect(&sMenuCsState->mInterpolations[0], 0);
    sMenuCsState->mCharacterIndex = sMenuCsState->mUnk_090[sMenuCsState->mUnk_060].mCharacterIndex;
    sMenuCsState->mKartIndex = func_02025e60(sMenuCsState->mCharacterIndex);
}

#pragma thumb off

#pragma thumb on

u32 func_020270d0(void) {
    int result;
    if ((sMenuCsState->mUnk_080 != 0) && (result = IsPlayerEntryListTimerZero(), result != 0)) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

void func_02027084(void) {
    CellFileSet *sParts = &sMenuCsState->mUnk_01c;
    s32 i;
    s32 elementCount;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        elementCount = sParts->mCellLayout->mUnk_06;
        for (i = 0; i < elementCount; i++) {
            jn_ui_setElementAffine(&sParts->mCellTable[i], sMenuCsState->mUnk_074, sMenuCsState->mUnk_070);
        }
    }
}

#pragma thumb off

#pragma thumb on

void menucs_init(void *parentHeap, s32 mode, void *mainOam, void *subOam) {
    void *heap;
    SelectCharacter *selectCharacter;
    CellFileSet *sParts;
    Unk021534bc *positions;
    s32 i;
    s32 tableIndex;
    s32 modeValue;
    BOOL f;
    CellFileSet titleParts;
    CellFileSet w;

    heap = heap_createSubFrmHeap(parentHeap);
    sMenuCsState = heap_alloc(heap, 0x12c);
    MemFillWordsByBlock_inline(sMenuCsState, 0x12c);
    sMenuCsState->mHeap = heap;
    sMenuCsState->mUnk_080 = mode;
    switch (menu_getRaceConfig()->mUnk_108) {
        case 0:
            interp_init(&sMenuCsState->mInterpolations[0], 0, 10, -0x80, 0);
            interp_init(&sMenuCsState->mInterpolations[2], 0, 10, 0x60, 0);
            if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
                StartKartModelMenuBg0Increase();
            }
            break;
        case 2:
            interp_init(&sMenuCsState->mInterpolations[0], 1, 10, -0x80, 0);
            interp_init(&sMenuCsState->mInterpolations[2], 1, 10, 0x60, 0);
            switch (sMenuCsState->mUnk_080) {
                case 1:
                    if (gStruct217AA00->mUnk_0004 == 8) {
                        gStruct217AA00->mUnk_15f7 = 0xff;
                    }
                    break;
                case 2:
                    SetWiFiSessionOwnCharacterIndexNone();
                    break;
            }
            break;
    }
    interp_init(&sMenuCsState->mInterpolations[1], 0, 10, -0x40, 0);
    sMenuCsState->mMainOam = mainOam;
    sMenuCsState->mUnk_058 = subOam;
    if (sMenuCsState->mUnk_080 != 0 || menu_getRaceConfig()->mMode == 3 || menu_getRaceConfig()->mMode == 2) {
        f = TRUE;
    } else {
        f = FALSE;
    }
    sMenuCsState->mUnk_128 = f;
    if (sMenuCsState->mUnk_128 != FALSE) {
        switch (sMenuCsState->mUnk_080) {
            case 0:
                modeValue = 0;
                break;
            case 1:
                modeValue = 1;
                break;
            case 2:
                modeValue = 2;
                break;
        }
        SetupPlayerEntryList(modeValue, PLAYER_ENTRY_LIST_CHARACTER);
    }
    selectCharacter = sMenuCsState;
    switch (selectCharacter->mUnk_080) {
        case 0:
            selectCharacter->mEntryIndex = 0;
            break;
        case 1:
            selectCharacter->mEntryIndex =
                gStruct217AA00->mUnk_1e52[(u16) (gStruct217AA00->mUnk_0000 == 2 ? gStruct217AA00->mOwnIndex : 0)]
                    .mEntryIndex;
            break;
        case 2:
            sMenuCsState->mEntryIndex = menu_getRaceConfigField10C();
            break;
    }
    selectCharacter = sMenuCsState;
    if (selectCharacter->mUnk_128 == FALSE) {
        mutil2_loadLayout(&selectCharacter->mUnk_000, aSelect_character_gp_m_nce_ncgr_0, aSelect_character_gp_m_nce_ncer_0,
                          aSelect_character_gp_m_o_nclr_0, aSelect_character_gp_m_bncl, NULL, NULL,
                          arc_get2dArcFile);
        mutil2_initLayout(0, sMenuCsState->mHeap, &selectCharacter->mUnk_000);
        mutil2_loadLayout(&titleParts, aSelect_character_gp_title_m_nce_ncg_0, aSelect_character_gp_title_m_nce_nce_0, NULL,
                          aSelect_character_gp_title_m_bncl, NULL, NULL, arc_get2dArcFile);
        jn_ui_fillPlaceholder(0, titleParts.mCells, titleParts.mChars, titleParts.mCellLayout, 0, 0,
                       selectCharacter->mUnk_000.mCells, selectCharacter->mUnk_000.mCellLayout);
        mutil2_loadLayout(&sMenuCsState->mUnk_038, aSelect_character_gp_name_m_nce_ncgr_0, aSelect_character_gp_name_m_nce_ncer_0,
                          NULL, aSelect_character_gp_name_m_bncl, NULL, NULL, arc_get2dArcFile);
        selectCharacter->mUnk_000.mCellTable[9].mVisible = 0;
        selectCharacter->mUnk_000.mCellTable[8].mVisible = selectCharacter->mUnk_000.mCellTable[9].mVisible;
        selectCharacter->mUnk_000.mCellTable[7].mVisible = selectCharacter->mUnk_000.mCellTable[8].mVisible;
        selectCharacter->mUnk_000.mCellTable[6].mVisible = selectCharacter->mUnk_000.mCellTable[7].mVisible;
        selectCharacter->mUnk_000.mCellTable[5].mVisible = selectCharacter->mUnk_000.mCellTable[6].mVisible;
        selectCharacter->mUnk_000.mCellTable[4].mVisible = selectCharacter->mUnk_000.mCellTable[5].mVisible;
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        sParts = &sMenuCsState->mUnk_01c;
        mutil2_loadLayout(sParts, aSelect_character_s_nce_ncgr_0, aSelect_character_s_nce_ncer_0, aSelect_character_s_o_nclr_0,
                          aSelect_character_s_bncl, NULL, aSelect_character_s_bnbl, arc_get2dArcFile);
        mutil2_initLayout(1, sMenuCsState->mHeap, sParts);
        sParts->mCellTable[24].mVisible = 0;
        for (i = 0; i < 12; i++) {
            sParts->mCellTable[data_02153554[i].mUnk_04].mUseMatrix = 1;
            sParts->mCellTable[data_02153554[i].mUnk_02].mUseMatrix =
                sParts->mCellTable[data_02153554[i].mUnk_04].mUseMatrix;
            sParts->mCellTable[data_02153554[i].mUnk_00].mUseMatrix =
                sParts->mCellTable[data_02153554[i].mUnk_02].mUseMatrix;
            sParts->mCellTable[data_02153554[i].mUnk_04].mUnk_34 = 0;
            sParts->mCellTable[data_02153554[i].mUnk_02].mUnk_34 =
                sParts->mCellTable[data_02153554[i].mUnk_04].mUnk_34;
            sParts->mCellTable[data_02153554[i].mUnk_00].mUnk_34 =
                sParts->mCellTable[data_02153554[i].mUnk_02].mUnk_34;
        }
        sParts->mCellTable[25].mUseMatrix = 1;
        sParts->mCellTable[24].mUseMatrix = sParts->mCellTable[25].mUseMatrix;
        sParts->mCellTable[25].mUnk_34 = 0;
        sParts->mCellTable[24].mUnk_34 = sParts->mCellTable[25].mUnk_34;
    } else if (menu_getRaceConfig()->mMode == 2) {
        InitSelectRaceRuleWait(sMenuCsState->mHeap, sMenuCsState->mUnk_058);
        func_0211f394();
    }
    sMenuCsState->mUnk_07c = 8;
    for (i = 0; i < 8; i++) {
        sMenuCsState->mUnk_090[i] = data_021535b4[i];
    }
    if (savd_isUnlockBitSet(0x15) != 0) {
        sMenuCsState->mUnk_090[i] = data_021535b4[8];
        i++;
        sMenuCsState->mUnk_07c++;
    }
    if (savd_isUnlockBitSet(0x14) != 0) {
        sMenuCsState->mUnk_090[i] = data_021535b4[9];
        i++;
        sMenuCsState->mUnk_07c++;
    }
    if (savd_isUnlockBitSet(0x16) != 0) {
        sMenuCsState->mUnk_090[i] = data_021535b4[10];
        i++;
        sMenuCsState->mUnk_07c++;
    }
    if (savd_isUnlockBitSet(0x17) != 0) {
        sMenuCsState->mUnk_090[i] = data_021535b4[11];
        i++;
        sMenuCsState->mUnk_07c++;
    }
    for (; i < 12; i++) {
        sMenuCsState->mUnk_090[i].mCharacterIndex = -1;
    }
    for (tableIndex = 0; tableIndex < sMenuCsState->mUnk_07c; tableIndex++) {
        if (sMenuCsState->mUnk_090[tableIndex].mCharacterIndex ==
            menu_getRaceConfig()->mEntries[sMenuCsState->mEntryIndex].mCharacterIndex) {
            sMenuCsState->mUnk_060 = tableIndex;
        }
    }
    sMenuCsState->mUnk_064 = sMenuCsState->mUnk_060;
    selectCharacter = sMenuCsState;
    selectCharacter->mCharacterIndex = menu_getRaceConfig()->mEntries[selectCharacter->mEntryIndex].mCharacterIndex;
    if (sMenuCsState->mCharacterIndex == -1) {
        sMenuCsState->mCharacterIndex = 0;
    }
    sMenuCsState->mKartIndex = func_02025e60(sMenuCsState->mCharacterIndex);
    menu_getRaceConfig()->mEntries[sMenuCsState->mEntryIndex].mCharacterIndex = -1;
    menu_getRaceConfig()->mEntries[sMenuCsState->mEntryIndex].mKartIndex = -1;
    menu_getRaceConfig()->mEntries[sMenuCsState->mEntryIndex].mUnk_14 = 0;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        sParts = &sMenuCsState->mUnk_01c;
        mutil2_loadPortraits(0, &w);
        for (i = 0; i < sMenuCsState->mUnk_07c; i++) {
            func_0212481c(sMenuCsState->mUnk_090[i].mCharacterIndex, w.mCells, w.mChars, w.mPalette, w.mCellLayout,
                          1, data_02153554[i].mUnk_02, sParts->mCells, sParts->mCellLayout);
        }
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        positions = NULL;
        sParts = &sMenuCsState->mUnk_01c;
        switch (sMenuCsState->mUnk_07c) {
            case 8:
                positions = data_021534bc;
                func_02027be0();
                break;
            case 9:
                positions = data_021534dc;
                func_02027a58();
                break;
            case 10:
                positions = data_02153500;
                func_02027850();
                break;
            case 11:
                positions = data_02153528;
                func_02027648();
                break;
            case 12:
                func_02027448();
                break;
        }
        if (positions != NULL) {
            for (i = 0; i < sMenuCsState->mUnk_07c; i++) {
                func_02025c94(data_02153554[i].mUnk_00, positions[i].mUnk_00, positions[i].mUnk_02,
                              sParts->mCellLayout);
                func_02025c94(data_02153554[i].mUnk_02, positions[i].mUnk_00, positions[i].mUnk_02,
                              sParts->mCellLayout);
                RectTableSetEntryXY(data_02153554[i].mRectEntryId, positions[i].mUnk_00, positions[i].mUnk_02,
                                    sParts->mRects);
                func_02025c94(data_02153554[i].mUnk_04, (s16) (positions[i].mUnk_00 + 3),
                              (s16) (positions[i].mUnk_02 + 3), sParts->mCellLayout);
            }
            for (; i < 12; i++) {
                sParts->mCellTable[data_02153554[i].mUnk_00].mVisible = 0;
                sParts->mCellTable[data_02153554[i].mUnk_02].mVisible = 0;
                sParts->mCellTable[data_02153554[i].mUnk_04].mVisible = 0;
                RectTableSetEntryXY(data_02153554[i].mRectEntryId, 0x400, 0x400, sParts->mRects);
            }
        }
        func_020271e8();
        SPM_CharName_202721C();
    }
    if (sMenuCsState->mUnk_080 == 0) {
        func_021170f8();
        gmenu_setSeqArcIndex(0xe);
        RequestSelectReturnState1();
    }
    if (mbright_isFadedIn() != 0) {
        sMenuCsState->mUnk_06c = 1;
    } else {
        mbright_fadeIn(10);
        func_0202734c(0);
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        func_02077f48(0);
    }
    heap_adjustSubFrmHeap(sMenuCsState->mHeap);
}

#pragma thumb off

#pragma thumb on

static inline s32 func_02026120_inline(u16 inputSlot) {
    BOOL result = FALSE;
    if (data_02175674[inputSlot].mPressedBits == 0 && data_02175680[inputSlot].mPressedBits < 5) {
        result = TRUE;
    }
    return result;
}

static inline s32 func_02026120_inline_2(u16 inputSlot) {
    BOOL result = FALSE;
    if (func_02026120_inline(inputSlot) == 0 && data_0217567c[inputSlot].mPressedBits == 0 &&
        data_02175674[inputSlot].mPressedBits != 0) {
        result = TRUE;
    }
    return result;
}

int menucs_render(void) {
    int result;
    SelectCharacter *selectCharacter;
    CellFileSet *sParts;
    s32 previousTableIndex;
    SelectCharacter *selectCharacterReload;
    u16 inputSlot;
    s32 nextState;
    s32 tableIndex;
    s32 rectEntryId;
    s32 pointX;
    s32 pointY;
    u16 keyBits;
    u8 flaggedCharacterIndex;
    s16 targetTableIndex;
    s16 interpolatedValue;

    result = 0;
    inputSlot = input_getDirectInputUnitId();
    selectCharacter = sMenuCsState;
    sParts = &selectCharacter->mUnk_01c;
    switch (selectCharacter->mUnk_06c) {
        case 0:
            if (mbright_isFadedIn() != 0) {
                sMenuCsState->mUnk_06c = 1;
            }
            break;
        case 1:
            if (selectCharacter->mUnk_068 == 0) {
                func_0202734c(1);
            }
            sMenuCsState->mUnk_068++;
            selectCharacterReload = sMenuCsState;
            if (selectCharacterReload->mUnk_068 < 10) {
                selectCharacterReload->mUnk_070 = (selectCharacterReload->mUnk_068 << 12) / 10;
            } else {
                selectCharacterReload->mUnk_070 = 0x1000;
                sMenuCsState->mUnk_068 = 0;
                if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
                    nextState = 2;
                } else {
                    nextState = 3;
                }
                sMenuCsState->mUnk_06c = nextState;
            }
            func_02027084();
            break;
        case 2:
            selectCharacter->mCharacterIndex = 0xc;
            sMenuCsState->mKartIndex = 0x24;
            sMenuCsState->mUnk_068 = 0;
            sMenuCsState->mUnk_08c = 1;
            if (menu_getRaceConfig()->mMode == 3) {
                flaggedCharacterIndex = sMenuCsState->mCharacterIndex | 0x40;
                if (gStruct217AA00->mUnk_0004 == 8) {
                    gStruct217AA00->mUnk_15f7 = flaggedCharacterIndex;
                }
                func_02027424(1);
                sMenuCsState->mUnk_06c = 8;
            } else if (menu_getRaceConfig()->mMode == 2) {
                flaggedCharacterIndex = sMenuCsState->mCharacterIndex | 0xc0;
                if (gStruct217AA00->mUnk_0004 == 8) {
                    gStruct217AA00->mUnk_15f7 = flaggedCharacterIndex;
                }
                sMenuCsState->mUnk_06c = 6;
            }
            break;
        case 3:
            previousTableIndex = selectCharacter->mUnk_060;
            if (func_02026120_inline_2(inputSlot) != 0) {
                pointX = data_02175670[inputSlot].mPressedBits;
                pointY = data_02175672[inputSlot].mPressedBits;
                rectEntryId = jn_ui_checkTouch(sParts->mRects, pointX, pointY);
                if (rectEntryId >= 0) {
                    for (tableIndex = 0; tableIndex < sMenuCsState->mUnk_07c; tableIndex++) {
                        if (rectEntryId == data_02153554[tableIndex].mRectEntryId) {
                            sMenuCsState->mUnk_060 = tableIndex;
                            break;
                        }
                    }
                    func_020270fc(previousTableIndex);
                    func_021106a8(func_02025eb0(sMenuCsState->mCharacterIndex), 0);
                    sMenuCsState->mUnk_068 = 0;
                    sMenuCsState->mUnk_06c = 5;
                } else if (sMenuCsState->mUnk_080 == 0 &&
                           gmenu_checkSelectReturnTouch(pointX, pointY) != FALSE) {
                    StartSelectCharacterReturn();
                }
            } else if (func_020270d0() != 0) {
                sMenuCsState->mUnk_068 = 0;
                sMenuCsState->mUnk_08c = 3;
                sMenuCsState->mUnk_06c = 6;
                func_021106a8(func_02025eb0(sMenuCsState->mCharacterIndex), 0);
                func_02077f48(1);
                selectCharacterReload = sMenuCsState;
                switch (selectCharacterReload->mUnk_080) {
                    case 2:
                        SetWiFiSessionOwnCharacterIndex(selectCharacterReload->mCharacterIndex);
                        SetWiFiSessionOwnKartIndex(sMenuCsState->mKartIndex);
                        break;
                    case 1:
                        flaggedCharacterIndex = selectCharacterReload->mCharacterIndex | 0xc0;
                        if (gStruct217AA00->mUnk_0004 == 8) {
                            gStruct217AA00->mUnk_15f7 = flaggedCharacterIndex;
                        }
                        break;
                }
            } else {
                keyBits = gInputUnits[inputSlot].mPressedBits;
                if ((u16) (keyBits & PAD_KEY_A) != 0) {
                    sMenuCsState->mUnk_068 = 0;
                    sMenuCsState->mUnk_06c = 5;
                    func_02027188();
                    func_021106a8(func_02025eb0(sMenuCsState->mCharacterIndex), 0);
                } else if (sMenuCsState->mUnk_080 == 0 && (u16) (keyBits & PAD_KEY_B) != 0) {
                    StartSelectCharacterReturn();
                } else {
                    if (mutil_checkKeys(inputSlot, PAD_KEY_UP) != 0) {
                        selectCharacterReload = sMenuCsState;
                        targetTableIndex = selectCharacterReload->mTableIndexByKey[0];
                        if (targetTableIndex != -1) {
                            selectCharacterReload->mUnk_060 = targetTableIndex;
                        }
                    } else if (mutil_checkKeys(inputSlot, PAD_KEY_DOWN) != 0) {
                        selectCharacterReload = sMenuCsState;
                        targetTableIndex = selectCharacterReload->mTableIndexByKey[1];
                        if (targetTableIndex != -1) {
                            selectCharacterReload->mUnk_060 = targetTableIndex;
                        }
                    } else if (mutil_checkKeys(inputSlot, PAD_KEY_RIGHT) != 0) {
                        selectCharacterReload = sMenuCsState;
                        targetTableIndex = selectCharacterReload->mTableIndexByKey[2];
                        if (targetTableIndex != -1) {
                            selectCharacterReload->mUnk_060 = targetTableIndex;
                        }
                    } else if (mutil_checkKeys(inputSlot, PAD_KEY_LEFT) != 0) {
                        selectCharacterReload = sMenuCsState;
                        targetTableIndex = selectCharacterReload->mTableIndexByKey[3];
                        if (targetTableIndex != -1) {
                            selectCharacterReload->mUnk_060 = targetTableIndex;
                        }
                    }
                    if (sMenuCsState->mUnk_060 != previousTableIndex) {
                        func_02110698();
                        func_020270fc(previousTableIndex);
                        sMenuCsState->mUnk_06c = 4;
                    }
                }
            }
            break;
        case 4:
            selectCharacter->mUnk_068++;
            if (sMenuCsState->mUnk_068 > 5) {
                func_020272ec();
                sMenuCsState->mUnk_068 = 0;
                sMenuCsState->mUnk_06c = 3;
            }
            break;
        case 5:
            selectCharacter->mUnk_068++;
            selectCharacterReload = sMenuCsState;
            if (selectCharacterReload->mUnk_068 > 5) {
                selectCharacterReload->mUnk_068 = 0;
                sMenuCsState->mUnk_08c = 1;
                func_020272ec();
                selectCharacterReload = sMenuCsState;
                switch (selectCharacterReload->mUnk_080) {
                    case 0:
                        menu_getRaceConfig()->mEntries[sMenuCsState->mEntryIndex].mCharacterIndex =
                            selectCharacterReload->mCharacterIndex;
                        menu_getRaceConfig()->mEntries[sMenuCsState->mEntryIndex].mKartIndex =
                            sMenuCsState->mKartIndex;
                        SPM_2116FB0();
                        if (menu_getRaceConfig()->mMode == 2) {
                            menu_getRaceConfig()->mEntries[sMenuCsState->mEntryIndex].mUnk_14 = 1;
                            func_02077f48(1);
                            sMenuCsState->mUnk_06c = 7;
                            func_02117060();
                            SetKartIndicesFromCharacters();
                        } else {
                            func_02027424(1);
                            func_02077f5c();
                            sMenuCsState->mUnk_06c = 8;
                            interp_setState(&sMenuCsState->mInterpolations[1], 2);
                        }
                        break;
                    case 1:
                        if (menu_getRaceConfig()->mMode == 3) {
                            flaggedCharacterIndex = sMenuCsState->mCharacterIndex | 0x40;
                            if (gStruct217AA00->mUnk_0004 == 8) {
                                gStruct217AA00->mUnk_15f7 = flaggedCharacterIndex;
                            }
                            interp_setState(&sMenuCsState->mInterpolations[1], 2);
                            func_02027424(1);
                            sMenuCsState->mUnk_06c = 8;
                            func_02077f5c();
                        } else if (menu_getRaceConfig()->mMode == 2) {
                            flaggedCharacterIndex = sMenuCsState->mCharacterIndex | 0xc0;
                            if (gStruct217AA00->mUnk_0004 == 8) {
                                gStruct217AA00->mUnk_15f7 = flaggedCharacterIndex;
                            }
                            func_02077f48(1);
                            sMenuCsState->mUnk_06c = 6;
                        }
                        break;
                    case 2:
                        SetWiFiSessionOwnCharacterIndex(selectCharacterReload->mCharacterIndex);
                        interp_setState(&sMenuCsState->mInterpolations[1], 2);
                        func_02027424(1);
                        sMenuCsState->mUnk_06c = 8;
                        func_02077f5c();
                        break;
                }
            }
            break;
        case 6:
            if ((selectCharacter->mUnk_080 == 1 && IsEveryPlayerKartStored() != 0) ||
                (sMenuCsState->mUnk_080 == 2 && func_02121d0c() != 0)) {
                if (sMenuCsState->mUnk_080 == 2) {
                    func_021219cc();
                }
                if (menu_getRaceConfig()->mMode == 2 || func_020270d0() != 0) {
                    sMenuCsState->mUnk_06c = 7;
                } else {
                    func_02027424(1);
                    interp_setState(&sMenuCsState->mInterpolations[1], 2);
                    sMenuCsState->mUnk_06c = 8;
                }
            }
            break;
        case 7:
            selectCharacter->mUnk_068++;
            selectCharacterReload = sMenuCsState;
            if (selectCharacterReload->mUnk_068 > 60) {
                if (selectCharacterReload->mUnk_080 == 2) {
                    func_02027424(3);
                } else {
                    func_02027424(2);
                }
                interp_setState(&sMenuCsState->mInterpolations[1], 2);
                if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
                    StartKartModelMenuBg0Decrease();
                } else if (menu_getRaceConfig()->mMode == 2) {
                    func_0211f378();
                }
                sMenuCsState->mUnk_068 = 0;
                sMenuCsState->mUnk_06c = 8;
            }
            break;
        case 8:
            selectCharacter->mUnk_068++;
            selectCharacterReload = sMenuCsState;
            if (selectCharacterReload->mUnk_068 < 10) {
                selectCharacterReload->mUnk_070 = ((10 - selectCharacterReload->mUnk_068) << 12) / 10;
            } else {
                menu_getRaceConfig()->mEntries[sMenuCsState->mEntryIndex].mCharacterIndex =
                    selectCharacterReload->mCharacterIndex;
                menu_getRaceConfig()->mEntries[sMenuCsState->mEntryIndex].mKartIndex = sMenuCsState->mKartIndex;
                sMenuCsState->mUnk_06c = 9;
            }
            sMenuCsState->mUnk_074 += 0x1000;
            func_02027084();
            break;
        case 9:
            result = selectCharacter->mUnk_08c;
            break;
    }

    interp_update(&sMenuCsState->mInterpolations[0]);
    interp_update(&sMenuCsState->mInterpolations[1]);
    interp_update(&sMenuCsState->mInterpolations[2]);
    func_0202728c(interp_interpolate(&sMenuCsState->mInterpolations[0]));
    interpolatedValue = interp_interpolate(&sMenuCsState->mInterpolations[1]);
    func_020272c0(interpolatedValue, interp_interpolate(&sMenuCsState->mInterpolations[2]));
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        selectCharacterReload = sMenuCsState;
        if (selectCharacterReload->mUnk_08c != 2) {
            RequestKartModelMenuCharacter(selectCharacterReload->mCharacterIndex);
            RequestKartModelMenuKart(sMenuCsState->mKartIndex);
        }
        SPM_2078420(menu_getRaceConfig()->mMirrorMode);
    }
    if (sMenuCsState->mUnk_128 != FALSE) {
        AdvancePlayerEntryList();
    } else {
        jn_ui_renderElements(selectCharacter->mUnk_000.mCellLayout, selectCharacter->mUnk_000.mCells, NULL,
                        sMenuCsState->mMainOam, selectCharacter->mUnk_000.mCellTable);
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        jn_ui_renderElementsNoIncrAffine(sParts->mCellLayout, sParts->mCells, NULL, sMenuCsState->mUnk_058, sParts->mCellTable);
        oam_increaseAffineCount(sMenuCsState->mUnk_058);
    } else if (menu_getRaceConfig()->mMode == 2) {
        AdvanceSelectRaceRuleWait();
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        SPM_RenderCharacterSelect3D();
    }
    switch (result) {
        case 1:
            if (menu_getRaceConfig()->mMode == 2) {
                menu_getRaceConfig()->mUnk_108 = 0;
            } else {
                menu_getRaceConfig()->mUnk_108 = 1;
            }
            break;
        case 2:
            if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
                RequestKartModelMenuCharacter(-1);
                RequestKartModelMenuKart(-1);
            }
            menu_getRaceConfig()->mUnk_108 = 0;
            break;
    }
    return result;
}

#pragma thumb off

#pragma thumb on

void ReleaseSelectCharacter(void) {
    if (*(vu16 *) 0x27ffc40 == 2) {
        if (menu_getRaceConfig()->mMode == 2) {
            func_0211f498();
        }
    }
    heap_destroySubHeap(sMenuCsState->mHeap);
    sMenuCsState = NULL;
}

void menucs_2026058(void) {
    u32 displayBits = 0x18;

    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 0x3f, 6, 10);
    if (!(sMenuCsState->mUnk_06c == 9 && sMenuCsState->mUnk_08c == 2)) {
        displayBits |= 1;
    }
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | (displayBits << 8);
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | 0x1600;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 1;
    if (sMenuCsState->mUnk_128 != FALSE) {
        WritePlayerEntryListRegisters();
    }
}

void func_02025f90(void) {
    Ncgr *chars = NULL;
    Nclr *palette = NULL;
    Unk02021dc8 *cells = NULL;

    g2du_unpackCharacterData(&chars, arc_get2dArcFile(aSelect_character_gp_m_nce_ncgr));
    g2du_unpackCellBankData(&cells, arc_get2dArcFile(aSelect_character_gp_m_nce_ncer));
    g2du_unpackPaletteData(&palette, arc_get2dArcFile(aSelect_character_gp_m_o_nclr));
    g2du_unpackCharacterData(&chars, arc_get2dArcFile(aSelect_character_s_nce_ncgr));
    g2du_unpackCellBankData(&cells, arc_get2dArcFile(aSelect_character_s_nce_ncer));
    g2du_unpackPaletteData(&palette, arc_get2dArcFile(aSelect_character_s_o_nclr));
    g2du_unpackCharacterData(&chars, arc_get2dArcFile(aSelect_character_gp_name_m_nce_ncgr));
    g2du_unpackCellBankData(&cells, arc_get2dArcFile(aSelect_character_gp_name_m_nce_ncer));
    g2du_unpackCharacterData(&chars, arc_get2dArcFile(aSelect_character_gp_title_m_nce_ncgr));
    g2du_unpackCellBankData(&cells, arc_get2dArcFile(aSelect_character_gp_title_m_nce_ncer));
}

void interp_init(Interpolation *interpolation, s32 state, s32 counterLimit, s16 startValue, s32 endValue) {
    interpolation->mCounterLimit = counterLimit;
    interpolation->mStartValue = startValue;
    interpolation->mEndValue = endValue;
    interp_setState(interpolation, state);
}

#pragma thumb off
