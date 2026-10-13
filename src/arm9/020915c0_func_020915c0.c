/* Decompiled C draft; module arm9; ROM address 020915c0. No matching claim. */
#include "types.h"
#include "deps/020915c0_func_020915c0.h"

void func_020915c0(undefined4 param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  
  local_20 = 0x1e;
  func_01ff9048(0x14,(undefined4)(uintptr_t)(&local_20),1);
  uVar2 = MaybeGetBBMtxAtPosition(param_2 + 4);
  func_01ff9048(0x19,uVar2,0xc);
  func_01ff9048(0x1b,param_2 + 0x1c,3);
  uVar1 = param_2 + 0xb4U & 3;
  uVar3 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
  local_1c = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  local_18 = local_1c;
  local_14 = local_1c;
  func_01ff9048(0x1b,(undefined4)(uintptr_t)(&local_1c),3);
  DrawObject2D3D(param_1,*(uint *)(uRam02091650 & 0xfffffffc) >> (uRam02091650 & 3) * 8 |
                         *(uint *)(uRam02091650 & 0xfffffffc) << (uRam02091650 & 3) * -8 + 0x20,
                 param_2);
  return;
}

