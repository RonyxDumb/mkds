#include "Main/Unknown/code_020cadf4.h"
#include "Main/Unknown/code_020cae24.h"
#include "Main/Unknown/code_020cae38.h"
#include "Main/Unknown/code_020cae54.h"

#pragma thumb on
#pragma optimize_for_size on
void menu_gotoRaceStateRender(Unk020cadf4 *a) {
    if (a != NULL) {
        if (menu_sysdat_getOverlayRelatedNum() != 0 && menu_sysdat_getIsMBChild() != 0) {
            a->field4 = 6;
            func_020cae24(1);
        } else {
            a->field4 = 2;
        }
    }
}
#pragma thumb off
