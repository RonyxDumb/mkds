/* Decompiled C draft; module arm9; ROM address 0214f630. No matching claim. */
#include "types.h"
#include "deps/0214f630_func_0214f630.h"

undefined4 func_0214f630(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = func_021501d8();
  uVar2 = uRam0214f67c;
  iVar1 = iRam0214f678;
  if (iVar3 != 0) {
    *(undefined4 *)(iRam0214f678 + 4) = param_2;
    *(undefined4 *)(iVar1 + 8) = param_3;
    *(undefined4 *)(iVar1 + 0xc) = param_1;
    func_0214fa7c(uVar2);
    return 0;
  }
  return 1;
}

