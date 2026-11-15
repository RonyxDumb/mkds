#include "00/Lib/DWC/access_point_alloc.h"
#include "00/Lib/DWC/access_point_state.h"
#include "00/Lib/DWC/access_point_power_mode.h"
#include "cpu_copy_fill.h"

#pragma opt_common_subs off

void DWCi_AC_InsertApInfo(int slotIndex, void *info) {
    ACWORK *work;
    work = DWCi_AC_GetMemPtr(AC_MEM_WORK);
    MIi_CpuCopy32(info, &work->mUserInfo[slotIndex], 0xf0);
}

void *DWCi_AC_Alloc(u8 name, u32 size) {
    ACHOLD *hold;
    void *block;
    hold = DWCi_AC_GetMemPtr(AC_MEM_HOLD);
    if ((hold->mAllocState & name) == 0) {
        hold->mAllocState = hold->mAllocState | name;
        block = hold->mAlloc(name, size);
        return block;
    }
    return NULL;
}

void DWCi_AC_Free(u8 name, void *ptr, u32 size) {
    ACHOLD *hold = DWCi_AC_GetMemPtr(AC_MEM_HOLD);
    if ((hold->mAllocState & name) != 0) {
        hold->mAllocState = hold->mAllocState & ~name;
        hold->mFree(name, ptr, size);
    }
}
