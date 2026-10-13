/* Decompiled C draft; module arm9; ROM address 0210fa40. No matching claim. */
#include "types.h"
#include "deps/0210fa40_func_0210fa40.h"

void func_0210fa40(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (param_2 != 0) {
    if (param_1 == 1) {
      uVar1 = iRam0210fa70 + 8U & 3;
      uVar2 = *(uint *)(iRam0210fa70 + 8U & 0xfffffffc);
      *(uint *)(iRam0210fa70 + 8) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 4;
    }
    else {
      uVar1 = iRam0210fa70 + 8U & 3;
      uVar2 = *(uint *)(iRam0210fa70 + 8U & 0xfffffffc);
      *(uint *)(iRam0210fa70 + 8) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xfffffffb;
    }
    return;
  }
  return;
}

