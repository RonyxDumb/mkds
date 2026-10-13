/* Decompiled C draft; module arm9; ROM address 02084a88. No matching claim. */
#include "types.h"
#include "deps/02084a88_StructAD00Sh_SomeFn_4.h"

void StructAD00Sh_SomeFn_4(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar5;
  uint uVar4;
  
  uVar1 = param_1 + 0x54U & 3;
  uVar2 = *(uint *)(param_1 + 0x54U & 0xfffffffc);
  uVar4 = param_1 + 4U & 3;
  uVar3 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
    uVar5 = 2;
  }
  else {
    uVar5 = 1;
  }
  ModelBlock_SomeTexPltFn_3(uVar4,0);
  ModelBlock_SomeTexPltFn_1(uVar4,0,uVar5);
  func_02013468(uVar4,0,param_2);
  return;
}

