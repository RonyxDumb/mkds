/* Decompiled C draft; module arm9; ROM address 02141c98. No matching claim. */
#include "types.h"
#include "deps/02141c98_func_02141c98.h"

void func_02141c98(uint *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  uint uVar11;
  int iVar12;
  uint auStack_68 [17];
  
  uVar11 = 0;
  uVar2 = param_2 + 4U & 3;
  uVar8 = *(uint *)(param_2 + 4U & 0xfffffffc);
  uVar3 = param_3 + 4U & 3;
  uVar5 = *(uint *)(param_3 + 4U & 0xfffffffc);
  iVar6 = ((uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) & 0xff) +
          ((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) & 0xff);
  puVar9 = (uint *)((int)auStack_68 + iVar6);
  uVar3 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) & 0xffffff00;
  uVar2 = (4 - ((uint)param_1 & 3)) * 8 & 0x1f;
  *param_1 = uVar3 >> uVar2 | uVar3 << 0x20 - uVar2;
  puVar10 = puVar9;
  while (iVar1 = iVar6 + -1, 0 < iVar1) {
    uVar2 = param_3 + 4U & 3;
    uVar3 = *(uint *)(param_3 + 4U & 0xfffffffc);
    iVar7 = ((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0xff) - 1;
    iVar12 = (iVar1 - iVar7) + -1;
    if (iVar12 < 0) {
      iVar12 = 0;
      iVar7 = iVar6 + -2;
    }
    uVar3 = param_2 + 5 + iVar12;
    uVar5 = param_3 + 5 + iVar7;
    uVar2 = param_2 + 4U & 3;
    uVar8 = *(uint *)(param_2 + 4U & 0xfffffffc);
    iVar12 = ((uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) & 0xff) - iVar12;
    iVar6 = iVar7 + 1;
    if (iVar12 < iVar7 + 1) {
      iVar6 = iVar12;
    }
    for (; 0 < iVar6; iVar6 = iVar6 + -1) {
      uVar11 = ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) & 0xff) *
               ((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) & 0xff) + uVar11;
      uVar3 = uVar3 + 1;
      uVar5 = uVar5 - 1;
    }
    puVar10 = (uint *)((int)puVar10 + -1);
    uVar3 = uVar11 - (uint)((ulonglong)uRam02141f0c * (ulonglong)uVar11 >> 0x23) * iRam02141f10 &
            0xff | (*(uint *)((uint)puVar10 & 0xfffffffc) >> ((uint)puVar10 & 3) * 8 |
                   *(uint *)((uint)puVar10 & 0xfffffffc) << ((uint)puVar10 & 3) * -8 + 0x20) &
                   0xffffff00;
    uVar2 = (4 - ((uint)puVar10 & 3)) * 8 & 0x1f;
    *puVar10 = uVar3 >> uVar2 | uVar3 << 0x20 - uVar2;
    uVar11 = (uint)((ulonglong)uRam02141f0c * (ulonglong)uVar11 >> 0x23);
    iVar6 = iVar1;
  }
  *(short *)((int)param_1 + 2) = *(short *)(param_2 + 2) + *(short *)(param_3 + 2);
  if (uVar11 != 0) {
    puVar10 = (uint *)((int)puVar10 + -1);
    uVar2 = uVar11 & 0xff |
            (*(uint *)((uint)puVar10 & 0xfffffffc) >> ((uint)puVar10 & 3) * 8 |
            *(uint *)((uint)puVar10 & 0xfffffffc) << ((uint)puVar10 & 3) * -8 + 0x20) & 0xffffff00;
    uVar11 = (4 - ((uint)puVar10 & 3)) * 8 & 0x1f;
    *puVar10 = uVar2 >> uVar11 | uVar2 << 0x20 - uVar11;
    *(short *)((int)param_1 + 2) = *(short *)((int)param_1 + 2) + 1;
  }
  uVar11 = 0;
  for (; ((int)uVar11 < 0x20 && (puVar10 < puVar9)); puVar10 = (uint *)((int)puVar10 + 1)) {
    puVar4 = (uint *)((int)param_1 + uVar11 + 5);
    uVar3 = (*(uint *)((uint)puVar10 & 0xfffffffc) >> ((uint)puVar10 & 3) * 8 |
            *(uint *)((uint)puVar10 & 0xfffffffc) << ((uint)puVar10 & 3) * -8 + 0x20) & 0xff |
            (*(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
            *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20) & 0xffffff00;
    uVar2 = (4 - ((uint)puVar4 & 3)) * 8 & 0x1f;
    *puVar4 = uVar3 >> uVar2 | uVar3 << 0x20 - uVar2;
    uVar11 = uVar11 + 1;
  }
  puVar4 = param_1 + 1;
  uVar2 = uVar11 & 0xff |
          (*(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
          *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20) & 0xffffff00;
  uVar11 = (4 - ((uint)puVar4 & 3)) * 8 & 0x1f;
  *puVar4 = uVar2 >> uVar11 | uVar2 << 0x20 - uVar11;
  if (puVar9 <= puVar10) {
    return;
  }
  uVar11 = (*(uint *)((uint)puVar10 & 0xfffffffc) >> ((uint)puVar10 & 3) * 8 |
           *(uint *)((uint)puVar10 & 0xfffffffc) << ((uint)puVar10 & 3) * -8 + 0x20) & 0xff;
  if (uVar11 < 5) {
    return;
  }
  puVar4 = puVar10;
  if (uVar11 == 5) {
    do {
      puVar4 = (uint *)((int)puVar4 + 1);
      if (puVar9 <= puVar4) {
        uVar11 = (int)puVar10 - 1U & 3;
        uVar2 = *(uint *)((int)puVar10 - 1U & 0xfffffffc);
        if (((uVar2 >> uVar11 * 8 | uVar2 << uVar11 * -8 + 0x20) & 1) == 0) {
          return;
        }
        break;
      }
    } while (((*(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
              *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20) & 0xff) == 0);
  }
  uVar11 = (uint)(param_1 + 1) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  func_0214214c((int)(uintptr_t)(param_1),(uVar2 >> uVar11 * 8 | uVar2 << uVar11 * -8 + 0x20) & 0xff);
  return;
}

