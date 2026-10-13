/* Decompiled C draft; module arm9; ROM address 0214818c. No matching claim. */
#include "types.h"
#include "deps/0214818c_VecFx32_Normalize.h"

void VecFx32_Normalize(uint param_1,int *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined4 *puVar3;
  longlong *plVar4;
  ushort *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar12;
  uint uVar11;
  
  puVar3 = puRam021482b4;
  uVar11 = param_1 + 4 & 3;
  uVar7 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar7 = uVar7 >> uVar11 * 8 | uVar7 << uVar11 * -8 + 0x20;
  uVar9 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar11 = param_1 + 8 & 3;
  uVar10 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar11 = uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20;
  lVar1 = (longlong)(int)uVar11 * (longlong)(int)uVar11 +
          (longlong)(int)uVar9 * (longlong)(int)uVar9 + (longlong)(int)uVar7 * (longlong)(int)uVar7;
  *puRam021482b0 = 2;
  *puVar3 = 0;
  plVar4 = plRam021482b8;
  puVar3[1] = 0x1000000;
  puVar5 = puRam021482bc;
  *plVar4 = lVar1;
  plVar4 = plRam021482c0;
  *puVar5 = 1;
  *plVar4 = lVar1 * 4;
  do {
  } while ((*puVar5 & 0x8000) != 0);
  uVar11 = *(uint *)(uRam021482c4 & 0xfffffffc) >> (uRam021482c4 & 3) * 8 |
           *(uint *)(uRam021482c4 & 0xfffffffc) << (uRam021482c4 & 3) * -8 + 0x20;
  do {
  } while ((*puRam021482b0 & 0x8000) != 0);
  uVar9 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar10 = *(uint *)(uRam021482c8 & 0xfffffffc) >> (uRam021482c8 & 3) * 8 |
           *(uint *)(uRam021482c8 & 0xfffffffc) << (uRam021482c8 & 3) * -8 + 0x20;
  uVar2 = (ulonglong)uVar11 * (ulonglong)uVar10;
  iVar8 = (int)uVar2;
  uVar7 = uRam021482c8 + 4 & 3;
  uVar12 = *(uint *)(uRam021482c8 + 4 & 0xfffffffc);
  iVar6 = (uVar12 >> uVar7 * 8 | uVar12 << uVar7 * -8 + 0x20) * uVar11 +
          uVar10 * ((int)uVar11 >> 0x1f) + (int)(uVar2 >> 0x20);
  *param_2 = (int)(iVar6 * uVar9 +
                   iVar8 * ((int)uVar9 >> 0x1f) +
                   (int)((ulonglong)uVar9 * (uVar2 & 0xffffffff) >> 0x20) + 0x1000) >> 0xd;
  uVar11 = param_1 + 4 & 3;
  uVar7 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar11 = uVar7 >> uVar11 * 8 | uVar7 << uVar11 * -8 + 0x20;
  param_2[1] = (int)(iVar6 * uVar11 +
                     iVar8 * ((int)uVar11 >> 0x1f) +
                     (int)((ulonglong)uVar11 * (uVar2 & 0xffffffff) >> 0x20) + 0x1000) >> 0xd;
  uVar11 = param_1 + 8 & 3;
  uVar7 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar11 = uVar7 >> uVar11 * 8 | uVar7 << uVar11 * -8 + 0x20;
  param_2[2] = (int)(iVar6 * uVar11 +
                     iVar8 * ((int)uVar11 >> 0x1f) +
                     (int)((ulonglong)uVar11 * (uVar2 & 0xffffffff) >> 0x20) + 0x1000) >> 0xd;
  return;
}

