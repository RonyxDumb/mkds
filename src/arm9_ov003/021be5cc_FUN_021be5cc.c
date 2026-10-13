/* Decompiled C draft; module arm9_ov003; ROM address 021be5cc. No matching claim. */
#include "types.h"
#include "deps/021be5cc_FUN_021be5cc.h"

undefined4 FUN_021be5cc(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (0 < param_2) {
    func_0x0200ed34(DAT_021be5fc);
    uVar1 = (*(code *)*DAT_021be600)(param_2);
    func_0x0200ecc4(DAT_021be5fc);
    return uVar1;
  }
  return 0;
}

