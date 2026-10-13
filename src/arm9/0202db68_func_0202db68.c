/* Decompiled C draft; module arm9; ROM address 0202db68. No matching claim. */
#include "types.h"
#include "deps/0202db68_func_0202db68.h"

void func_0202db68(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = func_0202dd80();
  if (iVar1 == 0) {
    func_0202e43c(*(undefined4 *)(*piRam0202dbcc + param_1 * 4 + iRam0202dbd0));
    iVar2 = *(int *)(*piRam0202dbcc + iRam0202dbd4);
    iVar1 = GetCourseIdFromInternalId();
    func_02061678(iVar2 + iVar1 * 0x30);
    return;
  }
  iVar1 = *piRam0202dbcc;
  func_02061678(*(int *)(iVar1 + iRam0202dbdc) +
                iRam0202dbe4 *
                (*(uint *)(iVar1 + (param_1 - *(int *)(iVar1 + iRam0202dbd8)) * 4 + iRam0202dbe0) &
                0xff));
  return;
}

