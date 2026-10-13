/* Decompiled C draft; module arm9; ROM address 02098b68. No matching claim. */
#include "types.h"
#include "deps/02098b68_func_02098b68.h"

void func_02098b68(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 local_70;
  undefined1 auStack_6c [36];
  undefined1 auStack_48 [36];
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  
  local_70 = 0x1e;
  func_01ff9048(0x14,(undefined4)(uintptr_t)(&local_70),1);
  uVar3 = param_2 + 4U & 3;
  uVar2 = *(uint *)(param_2 + 4U & 0xfffffffc);
  *(int *)(param_2 + 0x4c) = (int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) >> 4;
  uVar3 = param_2 + 8U & 3;
  uVar2 = *(uint *)(param_2 + 8U & 0xfffffffc);
  *(int *)(param_2 + 0x50) = (int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) >> 4;
  uVar3 = param_2 + 0xcU & 3;
  uVar2 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
  *(int *)(param_2 + 0x54) = (int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) >> 4;
  func_01ff9048(0x19,param_2 + 0x28,0xc);
  uVar3 = param_2 + 0x1f8U & 3;
  uVar2 = *(uint *)(param_2 + 0x1f8U & 0xfffffffc);
  local_20 = (int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) >> 4;
  local_24 = 0;
  local_1c = 0;
  func_01ff9048(0x1c,(undefined4)(uintptr_t)(&local_24),3);
  uVar3 = param_2 + 0x1dcU & 3;
  uVar2 = *(uint *)(param_2 + 0x1dcU & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 != 0) {
    iVar1 = (int)(uVar3 & 0xffff) >> 4;
    MTX_RotY33__from_thumb
              ((undefined4 *)(void *)(auStack_6c),(int)*(short *)(iRam02098cfc + iVar1 * 4),
               (int)*(short *)(iRam02098cfc + (iVar1 * 2 + 1) * 2));
    func_01ff9048(0x1a,(undefined4)(uintptr_t)(auStack_6c),9);
  }
  uVar3 = param_2 + 0x1e0U & 3;
  uVar2 = *(uint *)(param_2 + 0x1e0U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 != 0) {
    iVar1 = (int)(uVar3 & 0xffff) >> 4;
    MTX_RotX33__from_thumb
              ((undefined4 *)(void *)(auStack_48),(int)*(short *)(iRam02098cfc + iVar1 * 4),
               (int)*(short *)(iRam02098cfc + (iVar1 * 2 + 1) * 2));
    func_01ff9048(0x1a,(undefined4)(uintptr_t)(auStack_48),9);
  }
  uVar3 = param_2 + 0x1f0U & 3;
  uVar2 = *(uint *)(param_2 + 0x1f0U & 0xfffffffc);
  local_18 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  local_14 = local_18;
  local_10 = local_18;
  func_01ff9048(0x1b,(undefined4)(uintptr_t)(&local_18),3);
  func_01ff9048(0x1b,param_2 + 0x1c,3);
  StructMapObject_MaybeSetPolygonId
            (*(uint *)(uRam02098d00 & 0xfffffffc) >> (uRam02098d00 & 3) * 8 |
             *(uint *)(uRam02098d00 & 0xfffffffc) << (uRam02098d00 & 3) * -8 + 0x20,
             *(undefined2 *)(param_2 + 0xa0));
  uVar3 = param_2 + 0xa4U & 3;
  uVar2 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
  StructMapObject_MaybeSetNsbcaFrame
            (*(uint *)(uRam02098d00 & 0xfffffffc) >> (uRam02098d00 & 3) * 8 |
             *(uint *)(uRam02098d00 & 0xfffffffc) << (uRam02098d00 & 3) * -8 + 0x20,
             ((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) << 4) >> 0x10);
  DrawObject2D3D(param_1,*(uint *)(uRam02098d00 & 0xfffffffc) >> (uRam02098d00 & 3) * 8 |
                         *(uint *)(uRam02098d00 & 0xfffffffc) << (uRam02098d00 & 3) * -8 + 0x20,
                 param_2);
  return;
}

