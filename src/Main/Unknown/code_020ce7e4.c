#include "Main/Unknown/code_020ce7e4.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020ce744.h"
#include "Main/Unknown/code_020ce778.h"
#include "Main/Unknown/code_021189f4.h"
#include "gx.h"
#include "code_02148950.h"

#pragma thumb on

void WriteVsSelectCupCourseRegisters(void) {
    int flag;
    flag = GetMenuScreenSwitched();
    if (flag != 0) {
        flag = VsSelectCupMB_IsMultiBootChildWrapper();
        if (flag == 0) {
            VsSelectGX_SetVisiblePlane(0x19);
            GX_SetGraphicsMode(1, 0, 0);
            VsSelectGXS_SetVisiblePlane(0x1e);
            GXS_SetGraphicsMode(0);
        } else {
            VsSelectGX_SetVisiblePlane(0x1c);
            GX_SetGraphicsMode(1, 0, 0);
            VsSelectGXS_SetVisiblePlane(0x12);
            GXS_SetGraphicsMode(0);
        }
    }
    WriteSelectCupCourseBgOffsets();
}

#pragma thumb off
