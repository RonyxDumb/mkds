/* Decompiled C draft; module arm9; ROM address 02147fd8. No matching claim. */
#include "types.h"
#include "deps/02147fd8_VecFx32_AddScale1.h"

void VecFx32_AddScale1(int param_1,uint param_2,uint param_3,int *param_4)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  
  lVar3 = (longlong)param_1 *
          (longlong)
          (int)(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
               *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20);
  *param_4 = (*(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
             *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20) +
             ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14);
  uVar1 = param_2 + 4 & 3;
  uVar5 = *(uint *)(param_2 + 4 & 0xfffffffc);
  uVar2 = param_3 + 4 & 3;
  uVar4 = *(uint *)(param_3 + 4 & 0xfffffffc);
  lVar3 = (longlong)param_1 * (longlong)(int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20);
  param_4[1] = (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) +
               ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14);
  uVar1 = param_2 + 8 & 3;
  uVar4 = *(uint *)(param_2 + 8 & 0xfffffffc);
  uVar2 = param_3 + 8 & 3;
  uVar5 = *(uint *)(param_3 + 8 & 0xfffffffc);
  lVar3 = (longlong)param_1 * (longlong)(int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  param_4[2] = (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) +
               ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14);
  return;
}

