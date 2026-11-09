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

Unk027ffc40 *VsSelectCupGetBootInfo(void) {
    return gBootInfo;
}

BOOL VsSelectCupIsDownloadBoot(void) {
    return VsSelectCupGetBootInfo()->mUnk_00 == 2 ? 1 : 0;
}

BOOL VsSelectCupIsDownloadBootWrapper(void) {
    return VsSelectCupIsDownloadBoot();
}
