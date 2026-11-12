#include "Main/Menu/multi_select_ns_registers.h"
#include "Main/Menu/multi_select_member_group.h"
#include "Main/Menu/multi_select_ns_input.h"
#include "Main/Unknown/unk_02174000.h"
#include "registers.h"

#pragma optimize_for_size on

void MultiSelectNSG2S_SetWnd0Position(u32 startX, u32 startY, u32 endX, u32 endY) {
    reg_G2S_DB_WIN0H = ((startX << 8) & 0xff00) | (endX & 0xff);
    reg_G2S_DB_WIN0V = ((startY << 8) & 0xff00) | (endY & 0xff);
}

#pragma thumb on

void WriteMultiSelectNSRegisters(void) {
    MultiSelectNS *multiSelectNS;

    MultiSelectNSGXS_SetVisiblePlane(0x16);
    multiSelectNS = gMultiSelectNS;
    if (multiSelectNS->mOffset != 0) {
        MultiSelectNSWriteSubWinEnableBits(1);
        MultiSelectNSG2S_SetWnd0InsidePlane(0x1f, 1);
        MultiSelectNSG2S_SetWndOutsidePlane(7, 1);
        MultiSelectNSG2S_SetWnd0Position(0, 0, 0xff, gMultiSelectNS->mOffset + 0xc0);
    } else {
        MultiSelectNSWriteSubWinEnableBits(0);
    }
}

#pragma thumb off
