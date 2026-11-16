#include "Main/Unknown/code_020cec88.h"
#include "Main/Unknown/code_0203206c.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_02032000.h"

#pragma optimize_for_size on
#pragma thumb on
void menu_state14Render(void) {
    switch (AdvanceSelectGame()) {
        case 1:
            switch (menu_getRaceConfig()->mMode) {
                case 3:
                    menu_gotoState(8, 0x1f);
                    break;
                case 2:
                    menu_gotoState(0xf, 0x1f);
                    break;
            }
            break;
        case 2:
            menu_gotoState(0, 0x1f);
            break;
        case 3:
            menu_gotoState(0x1b, 0x1f);
            break;
    }
}
#pragma thumb off
