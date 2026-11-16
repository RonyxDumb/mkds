#include "Main/Unknown/code_02029a90.h"
#include "Main/Ui/BackScreen.h"

#pragma thumb on
void gpres_finalize(void) {
    u32 unused;
    gmenu_finish();
}
#pragma thumb off

#pragma thumb on
void gpres_vblank(void) {
    u32 unused;
    gmenu_vblank();
}
#pragma thumb off
