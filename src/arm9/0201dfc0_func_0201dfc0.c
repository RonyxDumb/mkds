/* Decompiled C draft; module arm9; ROM address 0201dfc0. No matching claim. */
#include "types.h"
#include "deps/0201dfc0_func_0201dfc0.h"

void func_0201dfc0(uint param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_2 + 8U & 3;
  uVar3 = *(uint *)(param_2 + 8U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  lVar1 = (longlong)(int)*(short *)(param_1 + 0xc) *
          (longlong)
          (int)((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) - uVar4) + 0x800;
  *(uint *)(param_2 + 8) = uVar4 + ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000)
  ;
  uVar4 = param_2 + 0xcU & 3;
  uVar3 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
  uVar2 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  uVar4 = param_1 + 4 & 3;
  uVar3 = *(uint *)(param_1 + 4 & 0xfffffffc);
  lVar1 = (longlong)(int)*(short *)(param_1 + 0xc) *
          (longlong)(int)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) - uVar2) + 0x800;
  *(uint *)(param_2 + 0xc) =
       uVar2 + ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000);
  uVar4 = param_2 + 0x10U & 3;
  uVar3 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
  uVar2 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  uVar4 = param_1 + 8 & 3;
  uVar3 = *(uint *)(param_1 + 8 & 0xfffffffc);
  lVar1 = (longlong)(int)*(short *)(param_1 + 0xc) *
          (longlong)(int)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) - uVar2) + 0x800;
  *(uint *)(param_2 + 0x10) =
       uVar2 + ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000);
  return;
}

