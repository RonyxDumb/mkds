/* Decompiled C draft; module arm9; ROM address 0214fd54. No matching claim. */
#include "types.h"
#include "deps/0214fd54_func_0214fd54.h"

undefined4 func_0214fd54(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = func_021501d8();
  iVar1 = iRam0214fdc8;
  if (iVar2 != 0) {
    uVar3 = param_1 & 0xff | uRam0214fdc4;
    *(undefined4 *)(iRam0214fdc8 + 4) = param_3;
    *(undefined4 *)(iVar1 + 8) = param_4;
    func_0214fa7c(uVar3);
    func_0214fa7c(param_2 & uRam0214fdcc | uRam0214fdd0);
    return 0;
  }
  return 1;
}

