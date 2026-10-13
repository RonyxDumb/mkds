/* Decompiled C draft; module arm9; ROM address 02098a58. No matching claim. */
#include "types.h"
#include "deps/02098a58_func_02098a58.h"

void func_02098a58(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 local_28;
  uint local_24;
  int local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  
  uVar1 = param_2 + 4U & 3;
  uVar4 = *(uint *)(param_2 + 4U & 0xfffffffc);
  local_24 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar1 = param_2 + 8U & 3;
  uVar5 = *(uint *)(param_2 + 8U & 0xfffffffc);
  uVar4 = param_2 + 0x1f8U & 3;
  uVar2 = *(uint *)(param_2 + 0x1f8U & 0xfffffffc);
  local_20 = (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) +
             (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20);
  uVar1 = param_2 + 0xcU & 3;
  uVar4 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
  local_1c = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  local_28 = 0x1e;
  func_01ff9048(0x14,&local_28,1);
  uVar3 = func_020e6cf8(&local_24);
  func_01ff9048(0x19,uVar3,0xc);
  uVar1 = param_2 + 0x1f0U & 3;
  uVar4 = *(uint *)(param_2 + 0x1f0U & 0xfffffffc);
  local_18 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  local_14 = local_18;
  local_10 = local_18;
  func_01ff9048(0x1b,&local_18,3);
  func_01ff9048(0x1b,param_2 + 0x1c,3);
  StructMapObject_MaybeSetPolygonId
            (*(uint *)(uRam02098b18 & 0xfffffffc) >> (uRam02098b18 & 3) * 8 |
             *(uint *)(uRam02098b18 & 0xfffffffc) << (uRam02098b18 & 3) * -8 + 0x20,
             *(undefined2 *)(param_2 + 0xa0));
  DrawObject2D3D(param_1,*(uint *)(uRam02098b18 & 0xfffffffc) >> (uRam02098b18 & 3) * 8 |
                         *(uint *)(uRam02098b18 & 0xfffffffc) << (uRam02098b18 & 3) * -8 + 0x20,
                 param_2);
  return;
}

