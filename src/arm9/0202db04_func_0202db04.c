/* Decompiled C draft; module arm9; ROM address 0202db04. No matching claim. */
#include "types.h"
#include "deps/0202db04_func_0202db04.h"

void func_0202db04(int param_1)

{
  int iVar1;
  
  iVar1 = func_0202dd80();
  if (iVar1 == 0) {
    func_0202e43c(*(undefined4 *)(*piRam0202db50 + param_1 * 4 + iRam0202db54));
    return;
  }
  iVar1 = *piRam0202db50;
  func_02061654(*(int *)(iVar1 + iRam0202db5c) +
                iRam0202db64 *
                (*(uint *)(iVar1 + (param_1 - *(int *)(iVar1 + iRam0202db58)) * 4 + iRam0202db60) &
                0xff));
  return;
}

