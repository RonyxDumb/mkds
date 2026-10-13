/* Decompiled C draft; module arm9; ROM address 02098954. No matching claim. */
#include "types.h"
#include "deps/02098954_func_02098954.h"

void func_02098954(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar5;
  undefined4 local_28;
  int local_24;
  int local_20;
  int local_1c;
  uint uVar4;
  
  uVar4 = param_2 + 0x1e8U & 3;
  uVar2 = *(uint *)(param_2 + 0x1e8U & 0xfffffffc);
  uVar2 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
  uVar4 = param_2 + 0x1f0U & 3;
  uVar3 = *(uint *)(param_2 + 0x1f0U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  local_28 = 0x1e;
  iVar5 = (0x3000 - uVar2) - uVar4;
  func_01ff9048(0x14,(undefined4)(uintptr_t)(&local_28),1);
  uVar1 = MaybeGetBBMtxAtPosition(param_2 + 4);
  func_01ff9048(0x19,uVar1,0xc);
  local_20 = uVar2 + uVar4 + -0x1000;
  local_24 = iVar5;
  local_1c = iVar5;
  func_01ff9048(0x1b,(undefined4)(uintptr_t)(&local_24),3);
  func_01ff9048(0x1b,param_2 + 0x1c,3);
  DrawObject2D3D(param_1,*(uint *)(uRam020989f8 & 0xfffffffc) >> (uRam020989f8 & 3) * 8 |
                         *(uint *)(uRam020989f8 & 0xfffffffc) << (uRam020989f8 & 3) * -8 + 0x20,
                 param_2);
  return;
}

