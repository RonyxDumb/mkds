/* Decompiled C draft; module arm9; ROM address 02105338. No matching claim. */
#include "types.h"
#include "deps/02105338_func_02105338.h"

void func_02105338(int param_1,int param_2,uint param_3)

{
  longlong lVar1;
  uint uVar2;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar3;
  
  uVar6 = param_1 + 0xfcU & 3;
  uVar2 = *(uint *)(param_1 + 0xfcU & 0xfffffffc);
  puVar3 = (undefined4 *)(uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20);
  uVar4 = puVar3[1];
  uVar5 = puVar3[2];
  *(undefined4 *)(param_1 + 4) = *puVar3;
  *(undefined4 *)(param_1 + 8) = uVar4;
  *(undefined4 *)(param_1 + 0xc) = uVar5;
  if (param_2 < 1) {
    param_2 = 1;
  }
  *(short *)(param_1 + 0x66) = (short)param_2;
  uVar2 = uRam021053d4;
  uVar6 = *(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
          *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20;
  lVar1 = (ulonglong)uRam021053d4 * (ulonglong)uVar6;
  *(uint *)(param_1 + 0x1c) =
       (uint)lVar1 >> 0xc |
       (((int)uVar6 >> 0x1f) * uRam021053d4 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
  uVar6 = param_3 + 4 & 3;
  uVar7 = *(uint *)(param_3 + 4 & 0xfffffffc);
  uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  lVar1 = (ulonglong)uVar2 * (ulonglong)uVar6;
  *(uint *)(param_1 + 0x20) =
       (uint)lVar1 >> 0xc |
       (((int)uVar6 >> 0x1f) * uVar2 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
  uVar6 = param_3 + 8 & 3;
  uVar7 = *(uint *)(param_3 + 8 & 0xfffffffc);
  uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  lVar1 = (ulonglong)uVar2 * (ulonglong)uVar6;
  *(uint *)(param_1 + 0x24) =
       (uint)lVar1 >> 0xc |
       (((int)uVar6 >> 0x1f) * uVar2 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
  return;
}

