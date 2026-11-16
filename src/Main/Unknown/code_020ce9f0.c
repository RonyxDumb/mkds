#include "Main/Unknown/code_020ce9f0.h"
#include "Main/Unknown/code_02025f80.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_02026000.h"

#pragma optimize_for_size on
#pragma thumb on
void menu_state8Render(void) {
    switch (menucs_render()) {
        case 1:
            menu_gotoState(9, 0x1f);
            break;
        case 2:
            menu_gotoState(0, 0x1f);
            break;
        case 3:
            menu_gotoState(0xa, 0x1f);
            break;
    }
}
#pragma thumb off
