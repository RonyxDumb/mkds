/* Decompiled C draft; module arm9_ov000; ROM address 02182d28. No matching claim. */
#include "types.h"
#include "deps/02182d28_FUN_02182d28.h"

void FUN_02182d28(void)

{
  int iVar1;
  
  *(int *)(*DAT_02182d70 + 0x10) = *(int *)(*DAT_02182d70 + 0x10) + 1;
  iVar1 = func_0x02125fa4();
  if ((iVar1 != 0) && (0x78 < *(int *)(*DAT_02182d70 + 0x10))) {
    func_0x02125fc0();
  }
  iVar1 = func_0x02125f88();
  if (iVar1 != 0) {
    *(undefined4 *)(*DAT_02182d70 + 4) = 2;
    FUN_02182de8();
    *(undefined4 *)(*DAT_02182d70 + 0x10) = 0;
  }
  return;
}

