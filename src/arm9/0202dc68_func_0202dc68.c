/* Decompiled C draft; module arm9; ROM address 0202dc68. No matching claim. */
#include "types.h"
#include "deps/0202dc68_func_0202dc68.h"

void func_0202dc68(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = func_0202dd80();
  if (iVar1 == 0) {
    func_0202e43c(*(undefined4 *)(*piRam0202dcd8 + param_1 * 4 + iRam0202dcdc));
    iVar2 = *(int *)(*piRam0202dcd8 + iRam0202dce0);
    iVar1 = GetCourseIdFromInternalId();
    func_020616c0(iVar2 + iVar1 * 0x30,param_2);
    return;
  }
  iVar1 = *piRam0202dcd8;
  func_020616c0(*(int *)(iVar1 + iRam0202dce8) +
                iRam0202dcf0 *
                (*(uint *)(iVar1 + (param_1 - *(int *)(iVar1 + iRam0202dce4)) * 4 + iRam0202dcec) &
                0xff),param_2);
  return;
}

