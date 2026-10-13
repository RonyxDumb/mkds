/* Decompiled C draft; module arm9; ROM address 0207d814. No matching claim. */
#include "types.h"
#include "deps/0207d814_func_0207d814.h"

void func_0207d814(uint *param_1,uint param_2)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = uRam0207d8e0;
  uVar3 = (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
          *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) + 0x2cc;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x10;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *param_1 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  param_1[1] = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  param_1[5] = 0xffffffff;
  param_1[6] = 0;
  param_1[4] = 0;
  uVar3 = uVar5 & 3;
  uVar4 = *(uint *)(uVar5 & 0xfffffffc);
  uVar3 = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + 0xc;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if (uVar3 == 5) {
    *(uint *)((*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
              *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) + 0x2a8) =
         *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
         *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
    return;
  }
  if (uVar3 != 6) {
    func_0207e088();
    return;
  }
  iVar2 = func_0207fe70(param_2 + 8);
  uVar5 = *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
          *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
  uVar3 = uVar5 + 0x2cc;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x10;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) * (longlong)iVar2 + 0x800
  ;
  *(uint *)(uVar5 + 0x2a8) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
  uVar5 = *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
          *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
  uVar3 = uVar5 + 0x2a8;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(uint *)(uVar5 + 0xcc) = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  uVar5 = *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
          *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
  uVar3 = uVar5 + 0xcc;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(uint *)(uVar5 + 0xd0) = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  return;
}

