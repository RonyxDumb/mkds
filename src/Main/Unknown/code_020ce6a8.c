#include "Main/Unknown/code_020ce6a8.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Scene/SelectCupM.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma optimize_for_size on
#pragma thumb on
void menu_state12Render(void) {
    switch (AdvanceSelectCupM()) {
        case 1:
            menu_gotoState(0xd, 0x1f);
            break;
        case 2:
            menu_gotoState(0xb, 0x1f);
            break;
    }
}
#pragma thumb off

s32 mpicn_createRainStarIcon(void) {
    return mpicn_createMapObjIcon(&mpicn_sRainStarIcon, 0x154);
}
