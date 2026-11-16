#include "Main/Unknown/code_020ce998.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_02028000.h"
#include "Main/Unknown/code_02028130.h"

#pragma optimize_for_size on
#pragma thumb on
void menu_state9Render(void) {
    switch (AdvanceSelectKart()) {
        case 1:
            menu_gotoState(0xa, 0x1f);
            break;
        case 2:
            menu_gotoState(8, 0x1f);
            break;
    }
}
#pragma thumb off
