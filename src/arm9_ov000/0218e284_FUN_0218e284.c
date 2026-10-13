/* Decompiled C draft; module arm9_ov000; ROM address 0218e284. No matching claim. */
#include "types.h"
#include "deps/0218e284_FUN_0218e284.h"

int FUN_0218e284(int param_1,int param_2)

{
  undefined4 uVar1;
  int extraout_r1;
  
  if (param_2 - param_1 != 0) {
    uVar1 = FUN_0218e2c0();
    func_0x02133068(uVar1,param_2 - param_1);
    param_1 = extraout_r1 + param_1;
  }
  return param_1;
}

