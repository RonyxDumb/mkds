/* Decompiled C draft; module arm9; ROM address 02071980. No matching claim. */
#include "types.h"
#include "deps/02071980_func_02071980.h"

void func_02071980(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar1 = param_1 + 0x500U & 3;
  uVar4 = *(uint *)(param_1 + 0x500U & 0xfffffffc);
  uVar2 = param_1 + 0x3e0U & 3;
  uVar5 = *(uint *)(param_1 + 0x3e0U & 0xfffffffc);
  uVar3 = param_1 + 0x3e4U & 3;
  uVar6 = *(uint *)(param_1 + 0x3e4U & 0xfffffffc);
  func_0210b2a8(param_1,param_2,uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20,
                uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20,
                uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  return;
}

