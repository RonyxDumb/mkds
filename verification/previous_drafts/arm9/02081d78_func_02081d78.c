/* Decompiled C draft; module arm9; ROM address 02081d78. No matching claim. */
#include "types.h"
#include "deps/02081d78_func_02081d78.h"

void func_02081d78(int param_1,int param_2)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  if (param_2 != 0) {
    return;
  }
  bVar2 = *(byte *)(param_1 + 0x9a);
  iVar3 = GetDriverEntry(*(undefined1 *)(param_1 + 0x9b));
  uVar7 = iVar3 + 0x508U & 3;
  uVar10 = *(uint *)(iVar3 + 0x508U & 0xfffffffc);
  uVar11 = uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20;
  uVar7 = param_1 + 0x20U & 3;
  uVar10 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar10 = uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20;
  uVar7 = uVar10 & 3;
  uVar4 = *(uint *)(uVar10 & 0xfffffffc);
  uVar10 = uVar11 + 4 & 3;
  uVar9 = *(uint *)(uVar11 + 4 & 0xfffffffc);
  uVar7 = (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) + 4;
  uVar4 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar1 = uVar11 + 8 & 3;
  uVar5 = *(uint *)(uVar11 + 8 & 0xfffffffc);
  *(uint *)(param_1 + 0x28) =
       (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) +
       ((int)(*(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
             *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20) >> 4);
  uVar7 = param_1 + 0x20U & 3;
  uVar4 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar4 = uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20;
  uVar7 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar7 = (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) + 8;
  uVar4 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  *(uint *)(param_1 + 0x2c) =
       (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) +
       ((int)(uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20) >> 4);
  uVar7 = param_1 + 0x20U & 3;
  uVar10 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar10 = uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20;
  uVar7 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  uVar7 = (uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) + 0xc;
  uVar10 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  *(uint *)(param_1 + 0x30) =
       (uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20) +
       ((int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) >> 4);
  uVar6 = *(undefined4 *)(iVar3 + 0x3b4);
  uVar8 = *(undefined4 *)(iVar3 + 0x3b8);
  *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(iVar3 + 0x3b0);
  *(undefined4 *)(param_1 + 0x44) = uVar6;
  *(undefined4 *)(param_1 + 0x48) = uVar8;
  if (bVar2 < *(byte *)(param_1 + 0x99)) {
    *(byte *)(param_1 + 0x9a) = bVar2 + 1;
    return;
  }
  if (bVar2 == *(byte *)(param_1 + 0x99)) {
    uVar7 = param_1 + 0x24U & 3;
    uVar10 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
    *(uint *)(param_1 + 0x24) = (uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) & 0xfffffffe | 1
    ;
  }
  return;
}

