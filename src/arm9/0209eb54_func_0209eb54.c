/* Decompiled C draft; module arm9; ROM address 0209eb54. No matching claim. */
#include "types.h"
#include "deps/0209eb54_func_0209eb54.h"

void func_0209eb54(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  local_20 = 0x1e;
  func_01ff9048(0x14,(undefined4)(uintptr_t)(&local_20),1);
  uVar1 = param_2 + 0xcU & 3;
  uVar6 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
  uVar2 = param_2 + 8U & 3;
  uVar5 = *(uint *)(param_2 + 8U & 0xfffffffc);
  uVar3 = param_2 + 4U & 3;
  uVar4 = *(uint *)(param_2 + 4U & 0xfffffffc);
  local_14 = (int)(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) >> 4;
  local_18 = (int)((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) + iRam0209ebf8) >> 4;
  local_1c = (int)(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) >> 4;
  func_01ff9048(0x1c,(undefined4)(uintptr_t)(&local_1c),3);
  func_01ff9048(0x1b,param_2 + 0x1c,3);
  func_01ff9048(0x1a,param_2 + 0x28,9);
  DrawObject2D3D(param_1,*(uint *)(uRam0209ebfc & 0xfffffffc) >> (uRam0209ebfc & 3) * 8 |
                         *(uint *)(uRam0209ebfc & 0xfffffffc) << (uRam0209ebfc & 3) * -8 + 0x20,
                 param_2);
  return;
}

