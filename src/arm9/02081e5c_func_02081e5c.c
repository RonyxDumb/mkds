/* Decompiled C draft; module arm9; ROM address 02081e5c. No matching claim. */
#include "types.h"
#include "deps/02081e5c_func_02081e5c.h"

void func_02081e5c(int param_1,int param_2)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar8;
  uint uVar9;
  uint uVar7;
  
  if (param_2 != 0) {
    return;
  }
  bVar2 = *(byte *)(param_1 + 0x9a);
  iVar3 = GetDriverEntry(*(undefined1 *)(param_1 + 0x9b));
  uVar5 = iVar3 + 0x508U & 3;
  uVar6 = *(uint *)(iVar3 + 0x508U & 0xfffffffc);
  uVar7 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
  uVar5 = param_1 + 0x20U & 3;
  uVar6 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar6 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
  uVar5 = uVar6 & 3;
  uVar4 = *(uint *)(uVar6 & 0xfffffffc);
  uVar6 = uVar7 + 4 & 3;
  uVar9 = *(uint *)(uVar7 + 4 & 0xfffffffc);
  uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 4;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar1 = uVar7 + 8 & 3;
  uVar8 = *(uint *)(uVar7 + 8 & 0xfffffffc);
  *(uint *)(param_1 + 0x28) =
       (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) +
       ((int)(*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
             *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) >> 4);
  uVar5 = param_1 + 0x20U & 3;
  uVar4 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 8;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *(uint *)(param_1 + 0x2c) =
       (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) +
       ((int)(uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) >> 4);
  uVar5 = param_1 + 0x20U & 3;
  uVar6 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar6 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar5 = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + 0xc;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *(uint *)(param_1 + 0x30) =
       (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) +
       ((int)(uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20) >> 4);
  if (bVar2 < *(byte *)(param_1 + 0x99)) {
    *(byte *)(param_1 + 0x9a) = bVar2 + 1;
    return;
  }
  if (bVar2 == *(byte *)(param_1 + 0x99)) {
    uVar5 = param_1 + 0x24U & 3;
    uVar6 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
    *(uint *)(param_1 + 0x24) = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) & 0xfffffffe | 1;
  }
  return;
}

