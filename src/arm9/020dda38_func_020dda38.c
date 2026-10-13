/* Decompiled C draft; module arm9; ROM address 020dda38. No matching claim. */
#include "types.h"
#include "deps/020dda38_func_020dda38.h"

void func_020dda38(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined2 param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  func_020e6a18(param_2);
  iVar2 = func_020d3c44();
  uVar1 = param_2 + 0x14U & 3;
  uVar4 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
  *(uint *)(param_2 + 0x14) = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 0xc0ffffff;
  uVar1 = param_2 + 0x14U & 3;
  uVar4 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
  *(uint *)(param_2 + 0x14) = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20 | iVar2 << 0x18;
  uVar3 = MaybeGetBBMtxAtPosition(param_3);
  func_020e67c4(param_2,uVar3,param_1 + 0x34,1,param_5);
  return;
}

