/* Decompiled C draft; module arm9_ov001; ROM address 0219f198. No matching claim. */
#include "types.h"
#include "deps/0219f198_FUN_0219f198.h"

void FUN_0219f198(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_0219f1f0;
  *(undefined4 *)(*DAT_0219f1f0 + 0x20) = 5;
  *(undefined4 *)(*piVar1 + 0x24) = 0;
  iVar2 = *(int *)(*piVar1 + 0x58);
  if (iVar2 == 1) {
    iVar2 = FUN_0219f31c();
    if (iVar2 != 0) {
      func_0x02105980(3,10);
      return;
    }
    func_0x02105980(0,10);
    return;
  }
  if (iVar2 != 2) {
    return;
  }
  func_0x02105980(4,10);
  return;
}

