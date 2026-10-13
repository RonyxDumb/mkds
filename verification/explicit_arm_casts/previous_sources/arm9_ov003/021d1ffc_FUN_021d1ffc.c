/* Decompiled C draft; module arm9_ov003; ROM address 021d1ffc. No matching claim. */
#include "types.h"
#include "deps/021d1ffc_FUN_021d1ffc.h"

void FUN_021d1ffc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 uVar1;
  
  uVar1 = FUN_021d1974(param_4,0);
  FUN_021d18f0(param_4,0xffffffff,0,0);
  FUN_021d1890(param_4,0xffffffff,0,0xf);
  FUN_021d1790(param_4,0xffffffff,param_5);
  func_0x02022eb0(uVar1,*(undefined1 *)(param_1 + 0x36),*(undefined1 *)(param_1 + 0x37),param_2,
                  param_3,0,*(undefined2 *)(param_1 + 0x34),2);
  return;
}

