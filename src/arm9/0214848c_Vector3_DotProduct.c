/* Decompiled C draft; module arm9; ROM address 0214848c. No matching claim. */
#include "types.h"
#include "deps/0214848c_Vector3_DotProduct.h"

uint Vector3_DotProduct(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar1 = param_1 + 4 & 3;
  uVar8 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar2 = param_2 + 4 & 3;
  uVar7 = *(uint *)(param_2 + 4 & 0xfffffffc);
  uVar3 = param_1 + 8 & 3;
  uVar9 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar4 = param_2 + 8 & 3;
  uVar6 = *(uint *)(param_2 + 8 & 0xfffffffc);
  lVar5 = (longlong)(int)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) *
          (longlong)(int)(uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) +
          (longlong)
          (int)(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
               *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) *
          (longlong)
          (int)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
               *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) +
          (longlong)(int)(uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20) *
          (longlong)(int)(uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) + 0x800;
  return (uint)lVar5 >> 0xc | (int)((ulonglong)lVar5 >> 0x20) * 0x100000;
}

