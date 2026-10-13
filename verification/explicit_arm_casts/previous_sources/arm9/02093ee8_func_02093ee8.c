/* Decompiled C draft; module arm9; ROM address 02093ee8. No matching claim. */
#include "types.h"
#include "deps/02093ee8_func_02093ee8.h"

void func_02093ee8(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 local_10;
  
  local_10 = 0x1e;
  func_01ff9048(0x14,&local_10,1);
  func_01ff9048(0x1b,param_2 + 0x1c,3);
  uVar1 = param_2 + 4U & 3;
  uVar2 = *(uint *)(param_2 + 4U & 0xfffffffc);
  *(int *)(param_2 + 0x4c) = (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = param_2 + 8U & 3;
  uVar2 = *(uint *)(param_2 + 8U & 0xfffffffc);
  *(int *)(param_2 + 0x50) = (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = param_2 + 0xcU & 3;
  uVar2 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
  *(int *)(param_2 + 0x54) = (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) >> 4;
  func_01ff9048(0x19,param_2 + 0x28,0xc);
  DrawObject2D3D(param_1,*(uint *)(uRam02093f74 & 0xfffffffc) >> (uRam02093f74 & 3) * 8 |
                         *(uint *)(uRam02093f74 & 0xfffffffc) << (uRam02093f74 & 3) * -8 + 0x20,
                 param_2);
  return;
}

