/* Decompiled C draft; module arm9_ov000; ROM address 0219d630. No matching claim. */
#include "types.h"
#include "deps/0219d630_FUN_0219d630.h"

int FUN_0219d630(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_0219c9c4();
  iVar2 = func_0x02152520(uVar1,*(int *)(*DAT_0219d65c + 0x18) + param_1 * 0xc);
  if ((iVar2 == 0) || (iVar2 == -1)) {
    iVar2 = 0;
  }
  return iVar2;
}

