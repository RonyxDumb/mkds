#include "Main/Unknown/code_020cec24.h"
#include "Main/Unknown/code_02025f80.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_02026000.h"

#pragma optimize_for_size on
#pragma thumb on
void menu_state15Render(void) {
    switch (menucs_render()) {
        case 1:
        case 3:
            menu_gotoState(0x10, 0x1f);
            break;
        case 2:
            menu_gotoState(0xe, 0x1f);
            break;
    }
}
#pragma thumb off
