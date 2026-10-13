/* Decompiled C draft; module arm9_ov003; ROM address 021d34e4. No matching claim. */
#include "types.h"
#include "deps/021d34e4_FUN_021d34e4.h"

int FUN_021d34e4(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,undefined1 param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = FUN_021d1cd4(*(undefined4 *)(*DAT_021d3540 + param_1 * 0x3c));
  *(undefined4 *)(iVar1 + 8) = param_2;
  *(undefined4 *)(iVar1 + 0xc) = param_3;
  *(char *)(iVar1 + 0x10) = (char)param_4;
  *(undefined1 *)(iVar1 + 0x11) = param_5;
  uVar2 = func_0x0200ca9c(1);
  for (iVar3 = *(int *)(*DAT_021d3540 + param_1 * 0x3c + 0x10); *(byte *)(iVar3 + 0x10) <= param_4;
      iVar3 = *(int *)(iVar3 + 4)) {
  }
  FUN_021d2e68(iVar3,iVar1);
  func_0x0200cae4(uVar2);
  return iVar1;
}

