/* Decompiled C draft; module arm9_ov000; ROM address 0219a760. No matching claim. */
#include "types.h"
#include "deps/0219a760_FUN_0219a760.h"

undefined1 * FUN_0219a760(int param_1,int param_2,undefined1 *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (param_3 == (undefined1 *)0x0) {
    uVar2 = *DAT_0219a7d0;
    *DAT_0219a7d0 = uVar2 ^ 1;
    param_3 = (undefined1 *)(DAT_0219a7d4 + (uVar2 ^ 1) * 0x16);
  }
  if (param_1 == 0) {
    if (param_2 == 0) {
      *param_3 = 0;
    }
    else {
      func_0x02135014(param_3,DAT_0219a7e0,param_2);
    }
  }
  else if (param_2 == 0) {
    uVar1 = FUN_021a8c6c(param_1,&stack0xfffffff4);
    func_0x02135014(param_3,DAT_0219a7dc,uVar1);
  }
  else {
    uVar1 = FUN_021a8c6c(param_1,&stack0xfffffff4);
    func_0x02135014(param_3,DAT_0219a7d8,uVar1,param_2);
  }
  return param_3;
}

