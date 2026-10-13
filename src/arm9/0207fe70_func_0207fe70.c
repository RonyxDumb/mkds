/* Decompiled C draft; module arm9; ROM address 0207fe70. No matching claim. */
#include "types.h"
#include "deps/0207fe70_func_0207fe70.h"

uint func_0207fe70(uint param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x20;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = *(short *)((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 2) * 0x1000;
  lVar1 = (ulonglong)uVar2 * 0x29;
  uVar3 = (uint)lVar1;
  return uVar3 + 0x800 >> 0xc |
         (((int)uVar2 >> 0x1f) * 0x29 + (int)((ulonglong)lVar1 >> 0x20) + (uint)(0xfffff7ff < uVar3)
         ) * 0x100000;
}

