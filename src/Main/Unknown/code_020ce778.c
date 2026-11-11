#include "Main/Unknown/code_020ce778.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_021189f4.h"
#include "Main/Unknown/code_0211d4a8.h"

#pragma optimize_for_size on
#pragma thumb on
void UpdateVsSelectCupCourse(void) {
    switch (AdvanceSelectCupCourse()) {
        case 1:
            SwitchMenuScreen(0x1d, 0x1f);
            break;
        case 2:
            SwitchMenuScreen(0xc, 0x1f);
            break;
    }
}
#pragma thumb off

BootInfo *VsSelectCupMB_GetMultiBootParam(void) {
    return gBootInfo;
}

BOOL VsSelectCupMB_IsMultiBootChild(void) {
    return VsSelectCupMB_GetMultiBootParam()->mBootType == 2 ? 1 : 0;
}

BOOL VsSelectCupMB_IsMultiBootChildWrapper(void) {
    return VsSelectCupMB_IsMultiBootChild();
}
