#include "00/Lib/DWC/code_02188694.h"
#include "00/Lib/DWC/code_021884d8.h"
#include "00/Lib/DWC/code_02188ec0.h"
#include "code_0214d018.h"

#pragma opt_common_subs off

void DWCi_AC_InsertApInfo(int slotIndex, void *info) {
    ACWORK *work;
    work = DWCi_AC_GetMemPtr(0x10);
    MIi_CpuCopy32(info, &work->mUserInfo[slotIndex], 0xf0);
}

void *DWCi_AC_Alloc(u8 name, u32 size) {
    ACHOLD *hold;
    void *block;
    hold = DWCi_AC_GetMemPtr(1);
    if ((hold->mAllocState & name) == 0) {
        hold->mAllocState = hold->mAllocState | name;
        block = hold->mAlloc(name, size);
        return block;
    }
    return NULL;
}

void DWCi_AC_Free(u8 name, void *ptr, u32 size) {
    ACHOLD *hold = DWCi_AC_GetMemPtr(1);
    if ((hold->mAllocState & name) != 0) {
        hold->mAllocState = hold->mAllocState & ~name;
        hold->mFree(name, (u32) ptr, size);
    }
}
