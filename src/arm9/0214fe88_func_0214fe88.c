/* Decompiled C draft; module arm9; ROM address 0214fe88. No matching claim. */
#include "types.h"
#include "deps/0214fe88_func_0214fe88.h"

undefined4 func_0214fe88(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = func_021501d8();
  iVar1 = iRam0214feec;
  if (iVar2 != 0) {
    uVar3 = param_1 >> 0x10 & 0xff | uRam0214fef0;
    *(undefined4 *)(iRam0214feec + 4) = param_2;
    *(undefined4 *)(iVar1 + 8) = param_3;
    func_0214fa7c(uVar3);
    func_0214fa7c(param_1 & uRam0214fef4 | uRam0214fef8);
    return 0;
  }
  return 1;
}

