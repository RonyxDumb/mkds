/* Decompiled C draft; module arm9; ROM address 02040d24. No matching claim. */
#include "types.h"
#include "deps/02040d24_func_02040d24.h"

undefined8 func_02040d24(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  uVar1 = param_1 + 4 & 3;
  uVar6 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar2 = param_2 + 4 & 3;
  uVar4 = *(uint *)(param_2 + 4 & 0xfffffffc);
  lVar3 = (longlong)
          (int)(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
               *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) *
          (longlong)
          (int)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
               *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) +
          (longlong)(int)(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) *
          (longlong)(int)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) + 0x800;
  iVar5 = (int)((ulonglong)lVar3 >> 0x20);
  return CONCAT44(iVar5 >> 0xc,(uint)lVar3 >> 0xc | iVar5 * 0x100000);
}

