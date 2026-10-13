/* Decompiled C draft; module arm9; ROM address 01ffcf7c. No matching claim. */
#include "types.h"
#include "deps/01ffcf7c_func_01ffcf7c.h"

void func_01ffcf7c(uint param_1,int *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined4 *puVar3;
  longlong *plVar4;
  ushort *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  
  puVar3 = puRam01ffd0d0;
  uVar8 = param_1 + 4 & 3;
  uVar7 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar7 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
  uVar10 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
           *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar8 = param_1 + 8 & 3;
  uVar11 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar12 = uVar11 >> uVar8 * 8 | uVar11 << uVar8 * -8 + 0x20;
  uVar8 = param_1 + 0xc & 3;
  uVar11 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  uVar8 = uVar11 >> uVar8 * 8 | uVar11 << uVar8 * -8 + 0x20;
  lVar1 = (longlong)(int)uVar8 * (longlong)(int)uVar8 +
          (longlong)(int)uVar12 * (longlong)(int)uVar12 +
          (longlong)(int)uVar10 * (longlong)(int)uVar10 +
          (longlong)(int)uVar7 * (longlong)(int)uVar7;
  *puRam01ffd0cc = 2;
  *puVar3 = 0;
  plVar4 = plRam01ffd0d4;
  puVar3[1] = 0x1000000;
  puVar5 = puRam01ffd0d8;
  *plVar4 = lVar1;
  plVar4 = plRam01ffd0dc;
  *puVar5 = 1;
  *plVar4 = lVar1 * 4;
  do {
  } while ((*puVar5 & 0x8000) != 0);
  uVar8 = *(uint *)(uRam01ffd0e0 & 0xfffffffc) >> (uRam01ffd0e0 & 3) * 8 |
          *(uint *)(uRam01ffd0e0 & 0xfffffffc) << (uRam01ffd0e0 & 3) * -8 + 0x20;
  do {
  } while ((*puRam01ffd0cc & 0x8000) != 0);
  uVar11 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
           *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar10 = *(uint *)(uRam01ffd0e4 & 0xfffffffc) >> (uRam01ffd0e4 & 3) * 8 |
           *(uint *)(uRam01ffd0e4 & 0xfffffffc) << (uRam01ffd0e4 & 3) * -8 + 0x20;
  uVar2 = (ulonglong)uVar8 * (ulonglong)uVar10;
  iVar9 = (int)uVar2;
  uVar7 = uRam01ffd0e4 + 4 & 3;
  uVar12 = *(uint *)(uRam01ffd0e4 + 4 & 0xfffffffc);
  iVar6 = (uVar12 >> uVar7 * 8 | uVar12 << uVar7 * -8 + 0x20) * uVar8 +
          uVar10 * ((int)uVar8 >> 0x1f) + (int)(uVar2 >> 0x20);
  *param_2 = (int)(iVar6 * uVar11 +
                   iVar9 * ((int)uVar11 >> 0x1f) +
                   (int)((ulonglong)uVar11 * (uVar2 & 0xffffffff) >> 0x20) + 0x1000) >> 0xd;
  uVar8 = param_1 + 4 & 3;
  uVar7 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
  param_2[1] = (int)(iVar6 * uVar8 +
                     iVar9 * ((int)uVar8 >> 0x1f) +
                     (int)((ulonglong)uVar8 * (uVar2 & 0xffffffff) >> 0x20) + 0x1000) >> 0xd;
  uVar8 = param_1 + 8 & 3;
  uVar7 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
  param_2[2] = (int)(iVar6 * uVar8 +
                     iVar9 * ((int)uVar8 >> 0x1f) +
                     (int)((ulonglong)uVar8 * (uVar2 & 0xffffffff) >> 0x20) + 0x1000) >> 0xd;
  uVar8 = param_1 + 0xc & 3;
  uVar7 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
  param_2[3] = (int)(iVar6 * uVar8 +
                     iVar9 * ((int)uVar8 >> 0x1f) +
                     (int)((ulonglong)uVar8 * (uVar2 & 0xffffffff) >> 0x20) + 0x1000) >> 0xd;
  return;
}

