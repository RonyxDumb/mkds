#include "Main/Unknown/code_0212a724.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02120610.h"

s32 func_0212a8d0(void) {
    BOOL result = FALSE;
    if (!gSaveData->mFirstBlock->mLocateFriendOff) {
        if (func_021213f4() != FALSE) {
            result = TRUE;
        }
    }
    return result;
}

#pragma thumb on
void InitKeyboardLabelCanvases(void) {
    s32 remaining[2] = {0x4000, 0x4000};
    u8 buttonSizes[2][2][2] = {{{0x50, 0x10}, {0x50, 0x10}}, {{0x50, 0x10}, {0x50, 0x10}}};
    u8 charSizes[2][12][2] = {
        {{8, 16}, {8, 16}, {8, 16}, {8, 16}, {8, 16}, {8, 16}, {8, 16}, {8, 16}, {8, 16}, {8, 16}, {8, 16}, {8, 16}},
        {{16, 16}, {16, 16}, {16, 16}, {16, 16}, {16, 16}, {16, 16}, {16, 16}, {16, 16}, {16, 16}, {16, 16}}};
    s32 i;
    s32 j;
    s32 l;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            remaining[1] -= jn_ui_initLabel(
                nickname_sState->mHeap, data_0215d0e4[i][j], nickname_sState->mBnlls[i], buttonSizes[i][j][0], buttonSizes[i][j][1],
                data_0215d128[i][j][0], nickname_sState->mNcer, nickname_sState->mBncls[i], nickname_sState->mTables[i][1], remaining[1]);
        }
    }
    for (j = 0; j < 2; j++) {
        for (l = 0; l < 2; l++) {
            for (i = 0; i < gKeyboardTextLimits[j]; i++) {
                remaining[l] -=
                    jn_ui_initLabel(nickname_sState->mHeap, data_0215d134[j][i], nickname_sState->mBnlls[j], charSizes[j][i][0],
                                    charSizes[j][i][1], data_0215d14c[j][i], nickname_sState->mNcer, nickname_sState->mBncls[j],
                                    nickname_sState->mTables[j][l], remaining[l]);
            }
        }
    }
}
#pragma thumb off

// placeholder: an object of the original file that is not known yet; it only sets the order of the tables above
u8 data_0212a724_pad[12];
