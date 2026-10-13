/* Decompiled C draft; module arm9; ROM address 01ff9940. No matching claim. */
#include "types.h"
#include "deps/01ff9940_func_01ff9940.h"

void func_01ff9940(uint *param_1,uint param_2,int param_3,uint param_4)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  bVar2 = *(byte *)(param_3 + 3);
  if ((param_4 & 4) == 0) {
    param_1[1] = *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                 *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
    uVar6 = param_2 + 4 & 3;
    uVar7 = *(uint *)(param_2 + 4 & 0xfffffffc);
    param_1[2] = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
    uVar6 = param_2 + 8 & 3;
    uVar7 = *(uint *)(param_2 + 8 & 0xfffffffc);
    param_1[3] = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
    if ((bVar2 & 2) != 0) {
      bVar3 = *(byte *)(param_3 + 1);
      iVar9 = (*(uint *)(uRam01ff9a84 & 0xfffffffc) >> (uRam01ff9a84 & 3) * 8 |
              *(uint *)(uRam01ff9a84 & 0xfffffffc) << (uRam01ff9a84 & 3) * -8 + 0x20) + 0xc4;
      uVar6 = iVar9 + (uint)(bVar3 >> 5) * 4;
      uVar7 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      iVar8 = (uint)bVar3 * 0x18;
      *(uint *)(iVar9 + (uint)(bVar3 >> 5) * 4) =
           (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & ~(1 << (bVar3 & 0x1f));
      iVar9 = iRam01ff9a8c;
      uVar6 = param_2 + 0xc & 3;
      uVar7 = *(uint *)(param_2 + 0xc & 0xfffffffc);
      *(uint *)(iRam01ff9a88 + iVar8) = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
      iVar4 = iRam01ff9a90;
      uVar6 = param_2 + 0x10 & 3;
      uVar7 = *(uint *)(param_2 + 0x10 & 0xfffffffc);
      *(uint *)(iVar9 + iVar8) = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
      uVar6 = param_2 + 0x14 & 3;
      uVar7 = *(uint *)(param_2 + 0x14 & 0xfffffffc);
      *(uint *)(iVar4 + iVar8) = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
    }
  }
  else {
    *param_1 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20 | 1;
    if ((bVar2 & 2) != 0) {
      iVar9 = (*(uint *)(uRam01ff9a84 & 0xfffffffc) >> (uRam01ff9a84 & 3) * 8 |
              *(uint *)(uRam01ff9a84 & 0xfffffffc) << (uRam01ff9a84 & 3) * -8 + 0x20) + 0xc4;
      uVar6 = (uint)(*(byte *)(param_3 + 1) >> 5);
      uVar7 = iVar9 + uVar6 * 4;
      uVar1 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      *(uint *)(iVar9 + uVar6 * 4) =
           uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20 | 1 << (*(byte *)(param_3 + 1) & 0x1f);
    }
  }
  uVar6 = uRam01ff9a84;
  if ((bVar2 & 1) != 0) {
    bVar2 = *(byte *)(param_3 + 2);
    *param_1 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20 | 0x20;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + (uint)(bVar2 >> 5) * 4 + 0xc4;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    if ((1 << (bVar2 & 0x1f) & (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20)) == 0) {
      puVar5 = (uint *)((uint)bVar2 * 0x18 + iRam01ff9a88);
      uVar6 = puVar5[1];
      uVar7 = puVar5[2];
      param_1[4] = *puVar5;
      param_1[5] = uVar6;
      param_1[6] = uVar7;
    }
    else {
      *param_1 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                 *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20 | 8;
    }
  }
  *param_1 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
             *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20 | 0x10;
  return;
}

