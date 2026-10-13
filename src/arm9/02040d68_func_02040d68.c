/* Decompiled C draft; module arm9; ROM address 02040d68. No matching claim. */
#include "types.h"
#include "deps/02040d68_func_02040d68.h"

uint func_02040d68(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = param_1 + 4 & 3;
  uVar5 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar2 = param_2 + 4 & 3;
  uVar4 = *(uint *)(param_2 + 4 & 0xfffffffc);
  lVar3 = (longlong)
          (int)(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
               *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) *
          (longlong)
          (int)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
               *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) +
          (longlong)(int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) *
          (longlong)(int)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) + 0x800;
  return (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000;
}

