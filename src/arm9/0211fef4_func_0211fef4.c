/* Decompiled C draft; module arm9; ROM address 0211fef4. No matching claim. */
#include "types.h"
#include "deps/0211fef4_func_0211fef4.h"

void func_0211fef4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(uRam0211ff70 & 0xfffffffc) >> (uRam0211ff70 & 3) * 8 |
          *(uint *)(uRam0211ff70 & 0xfffffffc) << (uRam0211ff70 & 3) * -8 + 0x20;
  if (*(short *)(uVar4 + 0x16) != 5) {
    return;
  }
  uVar4 = uVar4 + 0x1f38;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if (uVar4 >> uVar1 * 8 != 0 || uVar4 << uVar1 * -8 + 0x20 != 0) {
    uVar2 = func_0x0219bb50();
    iVar3 = func_02121990(param_2,param_3,param_1,uVar2);
    if (iVar3 == 0) {
      func_0205b504(param_1,param_2,param_3,0);
      return;
    }
    return;
  }
  return;
}

