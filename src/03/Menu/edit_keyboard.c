#include "03/Menu/edit_keyboard.h"
#include "03/Menu/edit_keyboard_slide_out.h"
#include "03/Menu/edit_keyboard_touch.h"
#include "03/code_021c04ec.h"
#include "03/code_021c0000.h"
#include "03/unk_021da000.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/System/task_input.h"
#include "03/System/rect.h"
#include "03/unk_021d5f00.h"
#include "03/unk_021d6000.h"
#include "03/Graphics/nce_oam.h"
#include "03/System/tasks.h"
#include "03/code_021bf000.h"
#include "03/code_021d1790.h"
#include "03/code_021d197c.h"
#include "03/Graphics/text_canvas.h"
#include "03/code_021d1000.h"
#include "03/System/exp_heap.h"
#include "03/code_021d1c18.h"
#include "03/unk_021d5000.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/Menu/edit_addr_keyboard.h"
#include "03/Graphics/hl_scr.h"
#include "03/System/application.h"
#include "code_02147cd8.h"
#include "03/code_021d1970.h"
#include "03/code_021d2ecc.h"
#include "03/code_021d3000.h"
#include "code_02142eac.h"
#include "gx_load2d.h"
#include "03/unk_021d67d8.h"
#include "registers.h"
#include "03/Menu/edit_keyboard_create.h"

const u16 gEditKeyboardPage1KeyPosition[1][2] = {{4, 0x7d}};
const u16 gEditKeyboardLastExtraKeyPositions[2][2] = {{4, 0x93}, {0xdc, 0x51}};
const u16 gEditKeyboardExtraKeyPositions[1][2] = {{4, 0x67}};

u16 gEditKeyboardPage0KeyTexts[50] = {
    0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x30, 0x2d, 0x3d, 0x71, 0x77, 0x65, 0x72, 0x74,
    0x79, 0x75, 0x69, 0x6f, 0x70, 0x5b, 0x5d, 0x61, 0x73, 0x64, 0x66, 0x67, 0x68, 0x6a, 0x6b, 0x6c, 0x3b,
    0x27, 0x60, 0x7a, 0x78, 0x63, 0x76, 0x62, 0x6e, 0x6d, 0x2c, 0x2e, 0x2f, 0x5c, 0x20, 0,    0,
};
u16 gEditKeyboardPage1KeyTexts[50] = {
    0x21, 0x40, 0x23, 0x24, 0x25, 0x5e, 0x26, 0x2a, 0x28, 0x29, 0x5f, 0x2b, 0x51, 0x57, 0x45, 0x52, 0x54,
    0x59, 0x55, 0x49, 0x4f, 0x50, 0x7b, 0x7d, 0x41, 0x53, 0x44, 0x46, 0x47, 0x48, 0x4a, 0x4b, 0x4c, 0x3a,
    0x22, 0x7e, 0x5a, 0x58, 0x43, 0x56, 0x42, 0x4e, 0x4d, 0x3c, 0x3e, 0x3f, 0x7c, 0x20, 0,    0,
};
u16 gEditKeyboardPage2KeyTexts[50] = {
    0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x30, 0x2d, 0x3d, 0x51, 0x57, 0x45, 0x52, 0x54,
    0x59, 0x55, 0x49, 0x4f, 0x50, 0x5b, 0x5d, 0x41, 0x53, 0x44, 0x46, 0x47, 0x48, 0x4a, 0x4b, 0x4c, 0x3b,
    0x27, 0x60, 0x5a, 0x58, 0x43, 0x56, 0x42, 0x4e, 0x4d, 0x2c, 0x2e, 0x2f, 0x5c, 0x20, 0,    0,
};
u8 gEditKeyboardPage1Inputs[0x30] = {
    0x21, 0x40, 0x23, 0x24, 0x25, 0x5e, 0x26, 0x2a, 0x28, 0x29, 0x5f, 0x2b, 0x51, 0x57, 0x45, 0x52,
    0x54, 0x59, 0x55, 0x49, 0x4f, 0x50, 0x7b, 0x7d, 0x41, 0x53, 0x44, 0x46, 0x47, 0x48, 0x4a, 0x4b,
    0x4c, 0x3a, 0x22, 0x7e, 0x5a, 0x58, 0x43, 0x56, 0x42, 0x4e, 0x4d, 0x3c, 0x3e, 0x3f, 0x7c, 0,
};
u8 gEditKeyboardPage2Inputs[0x30] = {
    0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x30, 0x2d, 0x3d, 0x51, 0x57, 0x45, 0x52,
    0x54, 0x59, 0x55, 0x49, 0x4f, 0x50, 0x5b, 0x5d, 0x41, 0x53, 0x44, 0x46, 0x47, 0x48, 0x4a, 0x4b,
    0x4c, 0x3b, 0x27, 0x60, 0x5a, 0x58, 0x43, 0x56, 0x42, 0x4e, 0x4d, 0x2c, 0x2e, 0x2f, 0x5c, 0,
};
u8 gEditKeyboardPage0Inputs[0x30] = {
    0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x30, 0x2d, 0x3d, 0x71, 0x77, 0x65, 0x72,
    0x74, 0x79, 0x75, 0x69, 0x6f, 0x70, 0x5b, 0x5d, 0x61, 0x73, 0x64, 0x66, 0x67, 0x68, 0x6a, 0x6b,
    0x6c, 0x3b, 0x27, 0x60, 0x7a, 0x78, 0x63, 0x76, 0x62, 0x6e, 0x6d, 0x2c, 0x2e, 0x2f, 0x5c, 0,
};
u32 gEditKeyboardExtraKeySoundSeqs[4] = {0, 0, 0, 2};
EditKeyboard *gEditKeyboard;
u8 *gEditKeyboardPageInputs[3] = {gEditKeyboardPage0Inputs, gEditKeyboardPage1Inputs, gEditKeyboardPage2Inputs};
u16 *gEditKeyboardPageKeyTexts[3] = {gEditKeyboardPage0KeyTexts, gEditKeyboardPage1KeyTexts,
                                     gEditKeyboardPage2KeyTexts};
EditKeyboardRowCounts gEditKeyboardExtraKeyCounts = {{1, 1, 1, 1, 0}};
EditKeyboardRowCounts gEditKeyboardRow4KeyCounts = {{0, 0, 0, 0, 2}};
EditKeyboardRowCounts gEditKeyboardKeyCounts = {{0xc, 0xc, 0xc, 0xb, 0}};

void ChangeEditKeyboardHighlight(int keyIndex) {
    if (keyIndex != gEditKeyboard->mHighlightedKeyIndex) {
        SetEditKeyboardKeyHighlight(keyIndex, 1);
        SetEditKeyboardKeyHighlight(gEditKeyboard->mHighlightedKeyIndex, 0);
        gEditKeyboard->mHighlightedKeyIndex = keyIndex;
    }
}

void UpdateEditKeyboardPad(void) {
    s32 cursorKeyIndex;
    if (AreKeysPressedOrRepeated(0x20) != 0) {
        MoveEditKeyboardCursor(0);
    }
    if (AreKeysPressedOrRepeated(0x40) != 0) {
        MoveEditKeyboardCursor(1);
    }
    if (AreKeysPressedOrRepeated(0x10) != 0) {
        MoveEditKeyboardCursor(2);
    }
    if (AreKeysPressedOrRepeated(0x80) != 0) {
        MoveEditKeyboardCursor(3);
    }
    if (AreKeysPressed(1) != 0) {
        cursorKeyIndex = gEditKeyboard->mCursorKeyIndex;
        if (cursorKeyIndex < EDIT_KEY_MAIN_COUNT) {
            if (gEditKeyboard->mAddCharEnabled == 0) {
                StartSoundSeq(9);
                return;
            }
            gEditKeyboard->mInput = gEditKeyboardPageInputs[gEditKeyboard->mPage][cursorKeyIndex];
            if (gEditKeyboard->mPage == EDIT_KEYBOARD_PAGE1) {
                ChangeEditKeyboardPage(0);
            }
            return;
        }
        if (cursorKeyIndex - EDIT_KEY_MAIN_COUNT < 4) {
            switch (cursorKeyIndex - EDIT_KEY_MAIN_COUNT) {
                case EDIT_KEY_PAGE2_TOGGLE - EDIT_KEY_MAIN_COUNT:
                    ToggleEditKeyboardPage2();
                    return;
                case EDIT_KEY_PAGE1_TOGGLE - EDIT_KEY_MAIN_COUNT:
                    ToggleEditKeyboardPage1();
                    return;
                case EDIT_KEY_SPACE - EDIT_KEY_MAIN_COUNT:
                    if (gEditKeyboard->mAddCharEnabled == 0) {
                        StartSoundSeq(9);
                        return;
                    }
                    break;
                case EDIT_KEY_REMOVE - EDIT_KEY_MAIN_COUNT:
                    if (gEditKeyboard->mRemoveCharEnabled == 0) {
                        StartSoundSeq(9);
                        return;
                    }
                    break;
            }
            if (gEditKeyboard->mPage == EDIT_KEYBOARD_PAGE1) {
                ChangeEditKeyboardPage(0);
            }
            gEditKeyboard->mInput = gEditKeyboardExtraKeyInputs[cursorKeyIndex - EDIT_KEY_MAIN_COUNT];
            return;
        }
        gEditKeyboard->mInput = gEditKeyboardRow4Inputs[cursorKeyIndex - EDIT_KEY_BOTTOM_LEFT];
    }
    if (AreKeysPressedOrRepeated(2) != 0) {
        if (gEditKeyboard->mRemoveCharEnabled == 0) {
            if (gEditKeyboard->mRemoveDisabledSoundPlayed != 0) {
                return;
            }
            StartSoundSeq(9);
            gEditKeyboard->mRemoveDisabledSoundPlayed = 1;
            return;
        }
        gEditKeyboard->mInput = EDIT_KEYBOARD_INPUT_REMOVE_CHAR;
    } else if (AreKeysReleased(2) != 0) {
        gEditKeyboard->mRemoveDisabledSoundPlayed = 0;
    }
    if (AreKeysPressed(0x400) != 0) {
        ToggleEditKeyboardPage2();
    }
    if (AreKeysPressed(0x800) != 0) {
        ToggleEditKeyboardPage1();
    }
}

void SetEditKeyboardRowY(u32 page, s32 row, u32 yPos) {
    EditKeyboardRowCounts keyCounts;
    EditKeyboardRowCounts extraKeyCounts;
    EditKeyboardRowCounts row4KeyCounts;
    s32 rowKeyIndex;
    s32 keyIndex;
    s32 extraKeyIndex;
    OamEntry *key;
    keyCounts = gEditKeyboardKeyCounts;
    extraKeyCounts = gEditKeyboardExtraKeyCounts;
    row4KeyCounts = gEditKeyboardRow4KeyCounts;
    keyIndex = row * 12;
    for (rowKeyIndex = 0; rowKeyIndex < keyCounts.mCounts[(u32) row]; rowKeyIndex++, keyIndex++) {
        key = gEditKeyboard->mKeys[keyIndex];
        key->mAttr01 = key->mAttr01 & OAM_ATTR01_NOT_EFFECT_MASK;
        key = gEditKeyboard->mKeys[keyIndex];
        key->mAttr01 = ((gEditKeyboardKeyPositions[keyIndex][0] & 0x1ff) << 16) |
                       ((key->mAttr01 & OAM_ATTR01_NOT_POSITION_MASK) | (yPos & 0xff));
    }
    if (row < 4) {
        ArrangeObjTextCanvasRange(gEditKeyboard->mRowTexts[page][row], gEditKeyboardKeyPositions[row * 12][0], yPos,
                                  gEditKeyboard->mRowTextRanges[row], 2);
    }
    extraKeyIndex = FX_ModS32(row + 3, 4);
    for (rowKeyIndex = 0; rowKeyIndex < extraKeyCounts.mCounts[(u32) row]; rowKeyIndex++) {
        key = gEditKeyboard->mExtraKeys[extraKeyIndex];
        key->mAttr01 = key->mAttr01 & OAM_ATTR01_NOT_EFFECT_MASK;
        key = gEditKeyboard->mExtraKeys[extraKeyIndex];
        key->mAttr01 = ((gEditKeyboardExtraKeyPositions[extraKeyIndex][0] & 0x1ff) << 16) |
                       ((key->mAttr01 & OAM_ATTR01_NOT_POSITION_MASK) | (yPos & 0xff));
    }
    for (rowKeyIndex = 0; rowKeyIndex < row4KeyCounts.mCounts[(u32) row]; rowKeyIndex++) {
        SetOamRangeEffect(gEditKeyboard->mRow4Keys[rowKeyIndex], -1, 0, 0);
        SetOamRangePosition(gEditKeyboard->mRow4Keys[rowKeyIndex], -1, gEditKeyboardRow4KeyPositions[rowKeyIndex][0],
                            yPos);
    }
}

void ChangeEditKeyboardPage(int page) {
    BOOL page2Selected;
    BOOL page1Selected;
    s32 rowIndex;
    s32 firstKeyIndex;
    page2Selected = FALSE;
    page1Selected = FALSE;
    gEditKeyboard->mPage = page;
    rowIndex = 0;
    if (rowIndex < 4) {
        firstKeyIndex = 0;
        do {
            SetEditKeyboardRowY(page, rowIndex, gEditKeyboardKeyPositions[firstKeyIndex][1]);
            firstKeyIndex = (s32) (firstKeyIndex + 12);
            rowIndex++;
        } while (rowIndex < 4);
    }
    if (page == 2) {
        page2Selected = TRUE;
    } else if (page == 1) {
        page1Selected = TRUE;
    }
    SetEditKeyboardKeyHighlight(EDIT_KEY_PAGE2_TOGGLE, page2Selected);
    SetEditKeyboardKeyHighlight(EDIT_KEY_PAGE1_TOGGLE, page1Selected);
}

void SetEditKeyboardKeyHighlight(int keyIndex, int highlight) {
    OamEntry *key;
    s32 extraKeyIndex;
    if (keyIndex < 0) {
        return;
    }
    if (keyIndex < EDIT_KEY_MAIN_COUNT) {
        key = gEditKeyboard->mKeys[keyIndex];
        key->mAttr01 = key->mAttr01 & OAM_ATTR01_NOT_MODE_MASK;
        key->mAttr2 = (key->mAttr2 & OAM_ATTR2_NOT_PALETTE_MASK) | (gEditKeyboardKeyPalettes[highlight] << 12);
        return;
    }
    extraKeyIndex = keyIndex - EDIT_KEY_MAIN_COUNT;
    if (extraKeyIndex < 4) {
        key = gEditKeyboard->mExtraKeys[extraKeyIndex];
        key->mAttr01 = key->mAttr01 & OAM_ATTR01_NOT_MODE_MASK;
        key->mAttr2 = (key->mAttr2 & OAM_ATTR2_NOT_PALETTE_MASK) | (gEditKeyboardKeyPalettes[highlight] << 12);
        return;
    }
    SetOamRangeMode(gEditKeyboard->mRow4Keys[keyIndex - EDIT_KEY_BOTTOM_LEFT], -1, 0,
                    gEditKeyboardRow4HighlightValues[highlight]);
}

void PlaceEditKeyboardCursor(void) {
    u32 imageIndex;
    switch (gEditKeyboard->mCursorKeyIndex) {
        case EDIT_KEY_PAGE2_TOGGLE:
            imageIndex = 0x42;
            break;
        case EDIT_KEY_PAGE1_TOGGLE:
            imageIndex = 0x41;
            break;
        case EDIT_KEY_SPACE:
            imageIndex = 0x43;
            break;
        case EDIT_KEY_REMOVE:
            imageIndex = 0x41;
            break;
        case EDIT_KEY_BOTTOM_LEFT:
        case EDIT_KEY_BOTTOM_RIGHT:
            imageIndex = 0x45;
            break;
        default:
            imageIndex = 0x40;
            break;
    }
    CopyNceImageToOamEntries(0, imageIndex, GetOamRangeEntry(gEditKeyboard->mCursor, 0));
    SetOamRangePriority(gEditKeyboard->mCursor, -1, 2);
    SetOamRangePosition(gEditKeyboard->mCursor, -1, gEditKeyboardCursorPositions[gEditKeyboard->mCursorKeyIndex][0],
                        gEditKeyboardCursorPositions[gEditKeyboard->mCursorKeyIndex][1]);
}

void MoveEditKeyboardCursor(int direction) {
    s8 previousKeyIndex;
    previousKeyIndex = gEditKeyboard->mCursorKeyIndex;
    gEditKeyboard->mCursorKeyIndex = gEditKeyboardCursorMoves[previousKeyIndex][direction];
    if (gEditKeyboard->mCursorKeyIndex == EDIT_KEY(3, 10) && direction == 3) {
        gEditKeyboard->mPreviousKeyIndex = previousKeyIndex;
    } else if (gEditKeyboard->mCursorKeyIndex == EDIT_KEY_BOTTOM_LEFT && (direction == 1 || direction == 3)) {
        gEditKeyboard->mPreviousKeyIndex = previousKeyIndex;
    } else if (gEditKeyboard->mCursorKeyIndex == EDIT_KEY_BOTTOM_RIGHT && (direction == 1 || direction == 3)) {
        if (previousKeyIndex != EDIT_KEY(3, 10)) {
            gEditKeyboard->mPreviousKeyIndex = previousKeyIndex;
        }
    } else if (gEditKeyboard->mCursorKeyIndex == EDIT_KEY_UP_FROM_LAST_GRID_KEY) {
        if (gEditKeyboard->mPreviousKeyIndex == EDIT_KEY(2, 11) ||
            gEditKeyboard->mPreviousKeyIndex == EDIT_KEY_REMOVE) {
            gEditKeyboard->mCursorKeyIndex = EDIT_KEY(2, 11);
        } else {
            gEditKeyboard->mCursorKeyIndex = EDIT_KEY(2, 10);
        }
    } else if (gEditKeyboard->mCursorKeyIndex == EDIT_KEY_UP_FROM_BOTTOM_LEFT) {
        switch (gEditKeyboard->mPreviousKeyIndex) {
            case EDIT_KEY(0, 0):
            case EDIT_KEY_SPACE:
                gEditKeyboard->mCursorKeyIndex = EDIT_KEY_SPACE;
                break;
            case EDIT_KEY(0, 1):
            case EDIT_KEY(3, 0):
                gEditKeyboard->mCursorKeyIndex = EDIT_KEY(3, 0);
                break;
            case EDIT_KEY(0, 3):
            case EDIT_KEY(3, 2):
                gEditKeyboard->mCursorKeyIndex = EDIT_KEY(3, 2);
                break;
            case EDIT_KEY(0, 4):
            case EDIT_KEY(3, 3):
                gEditKeyboard->mCursorKeyIndex = EDIT_KEY(3, 3);
                break;
            case EDIT_KEY(0, 5):
            case EDIT_KEY(3, 4):
                gEditKeyboard->mCursorKeyIndex = EDIT_KEY(3, 4);
                break;
            default:
                gEditKeyboard->mCursorKeyIndex = EDIT_KEY(3, 1);
                break;
        }
    } else if (gEditKeyboard->mCursorKeyIndex == EDIT_KEY_UP_FROM_BOTTOM_RIGHT) {
        switch (gEditKeyboard->mPreviousKeyIndex) {
            case EDIT_KEY(0, 6):
            case EDIT_KEY(3, 5):
                gEditKeyboard->mCursorKeyIndex = EDIT_KEY(3, 5);
                break;
            case EDIT_KEY(0, 7):
            case EDIT_KEY(3, 6):
                gEditKeyboard->mCursorKeyIndex = EDIT_KEY(3, 6);
                break;
            case EDIT_KEY(0, 9):
            case EDIT_KEY(3, 8):
                gEditKeyboard->mCursorKeyIndex = EDIT_KEY(3, 8);
                break;
            case EDIT_KEY(0, 10):
            case EDIT_KEY(3, 9):
                gEditKeyboard->mCursorKeyIndex = EDIT_KEY(3, 9);
                break;
            case EDIT_KEY(0, 11):
            case EDIT_KEY(2, 10):
            case EDIT_KEY(2, 11):
            case EDIT_KEY_REMOVE:
                gEditKeyboard->mCursorKeyIndex = EDIT_KEY(3, 10);
                break;
            default:
                gEditKeyboard->mCursorKeyIndex = EDIT_KEY(3, 7);
                break;
        }
    } else if (gEditKeyboard->mCursorKeyIndex == EDIT_KEY_DOWN_FROM_BOTTOM_LEFT) {
        switch (gEditKeyboard->mPreviousKeyIndex) {
            case EDIT_KEY(0, 0):
            case EDIT_KEY_SPACE:
                gEditKeyboard->mCursorKeyIndex = EDIT_KEY(0, 0);
                break;
            case EDIT_KEY(0, 1):
            case EDIT_KEY(3, 0):
                gEditKeyboard->mCursorKeyIndex = EDIT_KEY(0, 1);
                break;
            case EDIT_KEY(0, 3):
            case EDIT_KEY(3, 2):
                gEditKeyboard->mCursorKeyIndex = EDIT_KEY(0, 3);
                break;
            case EDIT_KEY(0, 4):
            case EDIT_KEY(3, 3):
                gEditKeyboard->mCursorKeyIndex = EDIT_KEY(0, 4);
                break;
            case EDIT_KEY(0, 5):
            case EDIT_KEY(3, 4):
                gEditKeyboard->mCursorKeyIndex = EDIT_KEY(0, 5);
                break;
            default:
                gEditKeyboard->mCursorKeyIndex = EDIT_KEY(0, 2);
                break;
        }
    } else if (gEditKeyboard->mCursorKeyIndex == EDIT_KEY_DOWN_FROM_BOTTOM_RIGHT) {
        switch (gEditKeyboard->mPreviousKeyIndex) {
            case EDIT_KEY(0, 6):
            case EDIT_KEY(3, 5):
                gEditKeyboard->mCursorKeyIndex = EDIT_KEY(0, 6);
                break;
            case EDIT_KEY(0, 7):
            case EDIT_KEY(3, 6):
                gEditKeyboard->mCursorKeyIndex = EDIT_KEY(0, 7);
                break;
            case EDIT_KEY(0, 9):
            case EDIT_KEY(3, 8):
                gEditKeyboard->mCursorKeyIndex = EDIT_KEY(0, 9);
                break;
            case EDIT_KEY(0, 10):
            case EDIT_KEY(3, 9):
                gEditKeyboard->mCursorKeyIndex = EDIT_KEY(0, 10);
                break;
            case EDIT_KEY(0, 11):
            case EDIT_KEY(2, 10):
                gEditKeyboard->mCursorKeyIndex = EDIT_KEY(0, 11);
                break;
            case EDIT_KEY(2, 11):
            case EDIT_KEY_REMOVE:
                gEditKeyboard->mCursorKeyIndex = EDIT_KEY_REMOVE;
                break;
            default:
                gEditKeyboard->mCursorKeyIndex = EDIT_KEY(0, 8);
                break;
        }
    }
    PlaceEditKeyboardCursor();
    StartSoundSeq(8);
}
