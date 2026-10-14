/* Decompiled C draft; module arm9; ROM address 0214f6bc. No matching claim. */
#include "types.h"
#include "deps/0214f6bc_func_0214f6bc.h"

undefined4 func_0214f6bc(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = func_021501d8();
  iVar1 = iRam0214f70c;
  if (iVar2 != 0) {
    uVar3 = param_1 & 0xff | uRam0214f708;
    *(undefined4 *)(iRam0214f70c + 4) = param_2;
    *(undefined4 *)(iVar1 + 8) = param_3;
    func_0214fa7c(uVar3);
    return 0;
  }
  return 1;
}

