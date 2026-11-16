#include "03/Menu/edit_keyboard_create.h"
#include "03/Menu/edit_keyboard.h"
#include "03/Menu/edit_keyboard_slide_out.h"
#include "03/Menu/edit_keyboard_touch.h"
#include "03/Menu/wifi_menu_shared.h"
#include "03/Menu/edit_keyboard_row_counts.h"
#include "03/Menu/wifi_menu_tables.h"
#include "03/Graphics/nce_oam.h"
#include "03/System/tasks.h"
#include "03/Graphics/text_canvas.h"
#include "03/System/exp_heap.h"
#include "03/Graphics/oam_range_set.h"
#include "03/Graphics/oam_range.h"
#include "03/Graphics/nce_file.h"
#include "03/Graphics/oam_range_entry.h"
#include "wireless_link_control.h"

const u16 gEditKeyboardKeyPositionsThird[15][2] = {
    {0xb5, 0x7d}, {0xc7, 0x7d}, {0xd9, 0x7d}, {0xeb, 0x7d}, {0x2d, 0x93}, {0x3f, 0x93}, {0x51, 0x93}, {0x63, 0x93},
    {0x75, 0x93}, {0x87, 0x93}, {0x99, 0x93}, {0xab, 0x93}, {0xbd, 0x93}, {0xcf, 0x93}, {0xe1, 0x93}};
const u16 gEditKeyboardCursorPositions[53][2] = {
    {2, 0x4f},    {0x14, 0x4f}, {0x26, 0x4f}, {0x38, 0x4f}, {0x4a, 0x4f}, {0x5c, 0x4f}, {0x6e, 0x4f}, {0x80, 0x4f},
    {0x92, 0x4f}, {0xa4, 0x4f}, {0xb6, 0x4f}, {0xc8, 0x4f}, {0x1e, 0x65}, {0x30, 0x65}, {0x42, 0x65}, {0x54, 0x65},
    {0x66, 0x65}, {0x78, 0x65}, {0x8a, 0x65}, {0x9c, 0x65}, {0xae, 0x65}, {0xc0, 0x65}, {0xd2, 0x65}, {0xe4, 0x65},
    {0x23, 0x7b}, {0x35, 0x7b}, {0x47, 0x7b}, {0x59, 0x7b}, {0x6b, 0x7b}, {0x7d, 0x7b}, {0x8f, 0x7b}, {0xa1, 0x7b},
    {0xb3, 0x7b}, {0xc5, 0x7b}, {0xd7, 0x7b}, {0xe9, 0x7b}, {0x2b, 0x91}, {0x3d, 0x91}, {0x4f, 0x91}, {0x61, 0x91},
    {0x73, 0x91}, {0x85, 0x91}, {0x97, 0x91}, {0xa9, 0x91}, {0xbb, 0x91}, {0xcd, 0x91}, {0xdf, 0x91}, {2, 0x65},
    {2, 0x7b},    {2, 0x91},    {0xda, 0x4f}, {2, 0xa8},    {0x82, 0xa8}};
const s8 gEditKeyboardCursorMoves[53][4] = {
    {0x32, 0x33, 1, 0x2f},    {0, 0x33, 2, 0xc},        {1, 0x33, 3, 0xd},        {2, 0x33, 4, 0xe},
    {3, 0x33, 5, 0xf},        {4, 0x33, 6, 0x10},       {5, 0x34, 7, 0x11},       {6, 0x34, 8, 0x12},
    {7, 0x34, 9, 0x13},       {8, 0x34, 0xa, 0x14},     {9, 0x34, 0xb, 0x15},     {0xa, 0x34, 0x32, 0x16},
    {0x2f, 1, 0xd, 0x18},     {0xc, 2, 0xe, 0x19},      {0xd, 3, 0xf, 0x1a},      {0xe, 4, 0x10, 0x1b},
    {0xf, 5, 0x11, 0x1c},     {0x10, 6, 0x12, 0x1d},    {0x11, 7, 0x13, 0x1e},    {0x12, 8, 0x14, 0x1f},
    {0x13, 9, 0x15, 0x20},    {0x14, 0xa, 0x16, 0x21},  {0x15, 0xb, 0x17, 0x22},  {0x16, 0x32, 0x2f, 0x23},
    {0x30, 0xc, 0x19, 0x24},  {0x18, 0xd, 0x1a, 0x25},  {0x19, 0xe, 0x1b, 0x26},  {0x1a, 0xf, 0x1c, 0x27},
    {0x1b, 0x10, 0x1d, 0x28}, {0x1c, 0x11, 0x1e, 0x29}, {0x1d, 0x12, 0x1f, 0x2a}, {0x1e, 0x13, 0x20, 0x2b},
    {0x1f, 0x14, 0x21, 0x2c}, {0x20, 0x15, 0x22, 0x2d}, {0x21, 0x16, 0x23, 0x2e}, {0x22, 0x17, 0x30, 0x2e},
    {0x31, 0x18, 0x25, 0x33}, {0x24, 0x19, 0x26, 0x33}, {0x25, 0x1a, 0x27, 0x33}, {0x26, 0x1b, 0x28, 0x33},
    {0x27, 0x1c, 0x29, 0x33}, {0x28, 0x1d, 0x2a, 0x34}, {0x29, 0x1e, 0x2b, 0x34}, {0x2a, 0x1f, 0x2c, 0x34},
    {0x2b, 0x20, 0x2d, 0x34}, {0x2c, 0x21, 0x2e, 0x34},
    {0x2d, EDIT_KEY_UP_FROM_LAST_GRID_KEY, 0x31, 0x34},
    {0x17, 0, 0xc, 0x30},     {0x23, 0x2f, 0x18, 0x31}, {0x2e, 0x30, 0x24, 0x33}, {0xb, 0x34, 0, 0x17},
    {0x34, EDIT_KEY_UP_FROM_BOTTOM_LEFT, 0x34, EDIT_KEY_DOWN_FROM_BOTTOM_LEFT},
    {0x33, EDIT_KEY_UP_FROM_BOTTOM_RIGHT, 0x33, EDIT_KEY_DOWN_FROM_BOTTOM_RIGHT}};

void CreateEditKeyboard(void) {
    u16 textRect[4] = {0};
    u32 entryCount;
    u16 text[2];
    EditKeyboard *keyboard;
    int index;
    int rowIndex;
    int columnIndex;
    int charIndex;

    textRect[2] = gEditKeyboardKeySize[0][0];
    textRect[3] = gEditKeyboardKeySize[0][1];
    keyboard = AllocZeroedExpHeapBlock(0x128, 4);
    gEditKeyboard = keyboard;
    keyboard->mInput = EDIT_KEYBOARD_INPUT_NOT_READY;
    gEditKeyboard->mCursorKeyIndex = 0;
    gEditKeyboard->mRemoveCharEnabled = 1;
    gEditKeyboard->mAddCharEnabled = 1;
    for (index = 0; index < EDIT_KEY_MAIN_COUNT; index++) {
        gEditKeyboard->mKeys[index] = CreateOamEntryFromNceImage(0, 0x34);
        gEditKeyboard->mKeys[index]->mAttr01 =
            (gEditKeyboard->mKeys[index]->mAttr01 & OAM_ENTRY_NOT_EFFECT_AND_AFFINE_INDEX_MASK)
                | OAM_ENTRY_EFFECT_HIDDEN;
        gEditKeyboard->mKeys[index]->mAttr2 =
            (gEditKeyboard->mKeys[index]->mAttr2 & OAM_ENTRY_NOT_PRIORITY_MASK) | 0xc00;
    }
    for (index = 0; index < 4; index++) {
        gEditKeyboard->mExtraKeys[index] = CreateOamEntryFromNceImage(0, gEditKeyboardExtraKeyImages[index]);
        gEditKeyboard->mExtraKeys[index]->mAttr01 =
            (gEditKeyboard->mExtraKeys[index]->mAttr01 & OAM_ENTRY_NOT_EFFECT_AND_AFFINE_INDEX_MASK)
                | OAM_ENTRY_EFFECT_HIDDEN;
        gEditKeyboard->mExtraKeys[index]->mAttr2 =
            (gEditKeyboard->mExtraKeys[index]->mAttr2 & OAM_ENTRY_NOT_PRIORITY_MASK) | 0xc00;
    }
    for (index = 0; index < 2; index++) {
        gEditKeyboard->mRow4Keys[index] = CreateOamRangeFromNceImage(0, gEditKeyboardRow4KeyImages[index], 1);
        SetOamRangeEffect(gEditKeyboard->mRow4Keys[index], -1, 0x200, 0);
        SetOamRangePriority(gEditKeyboard->mRow4Keys[index], -1, 3);
    }
    text[1] = 0;
    for (index = 0; index < 3; index++) {
        for (rowIndex = 0; rowIndex < 4; rowIndex++) {
            gEditKeyboard->mRowTexts[index][rowIndex] = CreateObjTextCanvas(
                0, gEditKeyboardRowTextAreaSize[0], gEditKeyboardRowTextAreaSize[1], 0, &entryCount, 0);
            charIndex = rowIndex * 12;
            for (columnIndex = 0, textRect[0] = 0; columnIndex < 12; columnIndex++, charIndex++, textRect[0] += 0x12) {
                text[0] = gEditKeyboardPageKeyTexts[index][charIndex];
                DrawCanvasTextRect(gEditKeyboard->mRowTexts[index][rowIndex], textRect[0], textRect[1], textRect[2],
                                   textRect[3], 2, 0x480, text);
            }
            if (index == 0) {
                gEditKeyboard->mRowTextRanges[rowIndex] = CreateOamRange(0, entryCount, 1);
            }
        }
    }
    gEditKeyboard->mCursor = CreateOamRangeFromNceImage(0, 0x40, 1);
    SetOamRangeEffect(gEditKeyboard->mCursor, -1, 0x200, 0);
    SetOamRangePriority(gEditKeyboard->mCursor, -1, 2);
    gEditKeyboard->mStepTask = AddTask(0, AdvanceEditKeyboardSlideInRow0, NULL, 0x78);
    SetEditKeyboardRowY(gEditKeyboard->mPage, 0, 0xc0);
}

void StartEditKeyboardSlideOut(void) {
    DeleteOamRange(gEditKeyboard->mCursor);
    SetTaskCallback(gEditKeyboard->mStepTask, AdvanceEditKeyboardSlideOutRow4);
}

u8 GetEditKeyboardInput(void) {
    return gEditKeyboard->mInput;
}

void SetEditKeyboardRemoveCharEnabled(u8 canRemove) {
    gEditKeyboard->mRemoveCharEnabled = canRemove;
}

void SetEditKeyboardAddCharEnabled(u8 canAdd) {
    gEditKeyboard->mAddCharEnabled = canAdd;
}

BOOL HasEditKeyboard(void) {
    if (gEditKeyboard != NULL) {
        return 1;
    }
    return 0;
}

static inline void EditKeyboardInG2_GetOBJPosition(OamEntry *object, u32 *x, u32 *y) {
    *x = (object->mAttr01 & OAM_ENTRY_X_POSITION_MASK) >> 16;
    *y = object->mAttr01 & OAM_ENTRY_Y_POSITION_MASK;
}

void AdvanceEditKeyboardSlideInRow0(TaskEntry *task, void *arg) {
    s32 xPos;
    s32 yPos;
    EditKeyboardInG2_GetOBJPosition(gEditKeyboard->mKeys[0], (u32 *) &xPos, (u32 *) &yPos);
    yPos -= 12;
    if (yPos > gEditKeyboardKeyPositions[0][1]) {
        SetEditKeyboardRowY(gEditKeyboard->mPage, 0, yPos);
        return;
    }
    SetEditKeyboardRowY(gEditKeyboard->mPage, 0, gEditKeyboardKeyPositions[0][1]);
    SetEditKeyboardRowY(gEditKeyboard->mPage, 1, 0xc0);
    SetTaskCallback(task, AdvanceEditKeyboardSlideInRow1);
}

void AdvanceEditKeyboardSlideInRow1(TaskEntry *task, void *arg) {
    s32 xPos;
    s32 yPos;
    EditKeyboardInG2_GetOBJPosition(gEditKeyboard->mKeys[12], (u32 *) &xPos, (u32 *) &yPos);
    yPos -= 12;
    if (yPos > gEditKeyboardKeyPositions[12][1]) {
        SetEditKeyboardRowY(gEditKeyboard->mPage, 1, yPos);
        return;
    }
    SetEditKeyboardRowY(gEditKeyboard->mPage, 1, gEditKeyboardKeyPositions[12][1]);
    SetEditKeyboardRowY(gEditKeyboard->mPage, 2, 0xc0);
    SetTaskCallback(task, AdvanceEditKeyboardSlideInRow2);
}

void AdvanceEditKeyboardSlideInRow2(TaskEntry *task, void *arg) {
    s32 xPos;
    s32 yPos;
    EditKeyboardInG2_GetOBJPosition(gEditKeyboard->mKeys[24], (u32 *) &xPos, (u32 *) &yPos);
    yPos -= 12;
    if (yPos > gEditKeyboardKeyPositionsSecond[8][1]) {
        SetEditKeyboardRowY(gEditKeyboard->mPage, 2, yPos);
        return;
    }
    SetEditKeyboardRowY(gEditKeyboard->mPage, 2, gEditKeyboardKeyPositionsSecond[8][1]);
    SetEditKeyboardRowY(gEditKeyboard->mPage, 3, 0xc0);
    SetTaskCallback(task, AdvanceEditKeyboardSlideInRow3);
}

void AdvanceEditKeyboardSlideInRow3(TaskEntry *task, void *arg) {
    s32 xPos;
    s32 yPos;
    EditKeyboardInG2_GetOBJPosition(gEditKeyboard->mKeys[36], (u32 *) &xPos, (u32 *) &yPos);
    yPos -= 12;
    if (yPos > gEditKeyboardKeyPositionsThird[4][1]) {
        SetEditKeyboardRowY(gEditKeyboard->mPage, 3, yPos);
        return;
    }
    SetEditKeyboardRowY(gEditKeyboard->mPage, 3, gEditKeyboardKeyPositionsThird[4][1]);
    SetEditKeyboardRowY(gEditKeyboard->mPage, 4, 0xc0);
    SetTaskCallback(task, AdvanceEditKeyboardSlideInRow4);
}

void AdvanceEditKeyboardSlideInRow4(TaskEntry *task, void *arg) {
    s32 xPos;
    s32 yPos;
    GetOamRangeEntryPosition(gEditKeyboard->mRow4Keys[0], 0, &xPos, &yPos);
    yPos -= 12;
    if (yPos > gEditKeyboardRow4KeyPositions[0][1]) {
        SetEditKeyboardRowY(gEditKeyboard->mPage, 4, yPos);
        return;
    }
    SetEditKeyboardRowY(gEditKeyboard->mPage, 4, gEditKeyboardRow4KeyPositions[0][1]);
    PlaceEditKeyboardCursor();
    SetTaskCallback(task, AdvanceEditKeyboardInput);
}
