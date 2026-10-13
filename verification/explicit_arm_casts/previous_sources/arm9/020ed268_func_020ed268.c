/* Decompiled C draft; module arm9; ROM address 020ed268. No matching claim. */
#include "types.h"
#include "deps/020ed268_func_020ed268.h"

void func_020ed268(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                  undefined4 param_6,int param_7,undefined4 param_8,undefined2 param_9,
                  undefined4 param_10)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  func_020f2b94(param_1,param_2,-(uint)(param_7 == 0),param_5,param_6,param_8);
  *(undefined4 *)(param_1 + 0x214) = param_3;
  *(undefined4 *)(param_1 + 0x218) = param_4;
  uVar1 = param_2 + 0xcU & 3;
  uVar4 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
  uVar4 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar1 = uVar4 + 0x1f0;
  uVar2 = uVar1 & 3;
  uVar3 = *(uint *)(uVar1 & 0xfffffffc);
  uVar4 = uVar4 + 500;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(uint *)(param_1 + 0x21c) = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  *(uint *)(param_1 + 0x220) = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  func_020f371c(param_1 + 0x21c,param_1 + 0x168,param_9,param_10);
  *(undefined4 *)(param_1 + 0x224) = 0;
  return;
}

