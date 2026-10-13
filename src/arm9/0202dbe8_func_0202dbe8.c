/* Decompiled C draft; module arm9; ROM address 0202dbe8. No matching claim. */
#include "types.h"
#include "deps/0202dbe8_func_0202dbe8.h"

void func_0202dbe8(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = func_0202dd80();
  if (iVar1 == 0) {
    func_0202e43c(*(undefined4 *)(*piRam0202dc4c + param_1 * 4 + iRam0202dc50));
    iVar2 = *(int *)(*piRam0202dc4c + iRam0202dc54);
    iVar1 = GetCourseIdFromInternalId();
    func_0206169c(iVar2 + iVar1 * 0x30);
    return;
  }
  iVar1 = *piRam0202dc4c;
  func_0206169c(*(int *)(iVar1 + iRam0202dc5c) +
                iRam0202dc64 *
                (*(uint *)(iVar1 + (param_1 - *(int *)(iVar1 + iRam0202dc58)) * 4 + iRam0202dc60) &
                0xff));
  return;
}

