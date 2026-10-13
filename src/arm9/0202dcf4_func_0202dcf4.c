/* Decompiled C draft; module arm9; ROM address 0202dcf4. No matching claim. */
#include "types.h"
#include "deps/0202dcf4_func_0202dcf4.h"

void func_0202dcf4(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = func_0202dd80();
  if (iVar1 == 0) {
    func_0202e43c(*(undefined4 *)(*piRam0202dd64 + param_1 * 4 + iRam0202dd68));
    iVar2 = *(int *)(*piRam0202dd64 + iRam0202dd6c);
    iVar1 = GetCourseIdFromInternalId();
    func_02061704(iVar2 + iVar1 * 0x30,(ushort *)(uintptr_t)(param_2));
    return;
  }
  iVar1 = *piRam0202dd64;
  func_02061704(*(int *)(iVar1 + iRam0202dd74) +
                iRam0202dd7c *
                (*(uint *)(iVar1 + (param_1 - *(int *)(iVar1 + iRam0202dd70)) * 4 + iRam0202dd78) &
                0xff),(ushort *)(uintptr_t)(param_2));
  return;
}

