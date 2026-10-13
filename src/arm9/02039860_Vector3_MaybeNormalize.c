/* Decompiled C draft; module arm9; ROM address 02039860. No matching claim. */
#include "types.h"
#include "deps/02039860_Vector3_MaybeNormalize.h"

int Vector3_MaybeNormalize(uint param_1,int *param_2)

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
  
  puVar3 = puRam02039990;
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
  *puRam0203998c = 2;
  *puVar3 = 0;
  plVar4 = plRam02039994;
  puVar3[1] = 0x1000000;
  puVar5 = puRam02039998;
  *plVar4 = lVar1;
  plVar4 = plRam0203999c;
  *puVar5 = 1;
  *plVar4 = lVar1 * 4;
  do {
  } while ((*puVar5 & 0x8000) != 0);
  uVar11 = *(uint *)(uRam020399a0 & 0xfffffffc) >> (uRam020399a0 & 3) * 8 |
           *(uint *)(uRam020399a0 & 0xfffffffc) << (uRam020399a0 & 3) * -8 + 0x20;
  do {
  } while ((*puRam0203998c & 0x8000) != 0);
  uVar9 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar10 = *(uint *)(uRam020399a4 & 0xfffffffc) >> (uRam020399a4 & 3) * 8 |
           *(uint *)(uRam020399a4 & 0xfffffffc) << (uRam020399a4 & 3) * -8 + 0x20;
  uVar2 = (ulonglong)uVar11 * (ulonglong)uVar10;
  iVar8 = (int)uVar2;
  uVar7 = uRam020399a4 + 4 & 3;
  uVar12 = *(uint *)(uRam020399a4 + 4 & 0xfffffffc);
  iVar6 = (uVar12 >> uVar7 * 8 | uVar12 << uVar7 * -8 + 0x20) * uVar11 +
          uVar10 * ((int)uVar11 >> 0x1f) + (int)(uVar2 >> 0x20);
  *param_2 = (int)(iVar6 * uVar9 +
                   iVar8 * ((int)uVar9 >> 0x1f) +
                   (int)((ulonglong)uVar9 * (uVar2 & 0xffffffff) >> 0x20) + 0x1000) >> 0xd;
  uVar7 = param_1 + 4 & 3;
  uVar9 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar7 = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
  param_2[1] = (int)(iVar6 * uVar7 +
                     iVar8 * ((int)uVar7 >> 0x1f) +
                     (int)((ulonglong)uVar7 * (uVar2 & 0xffffffff) >> 0x20) + 0x1000) >> 0xd;
  uVar7 = param_1 + 8 & 3;
  uVar9 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar7 = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
  param_2[2] = (int)(iVar6 * uVar7 +
                     iVar8 * ((int)uVar7 >> 0x1f) +
                     (int)((ulonglong)uVar7 * (uVar2 & 0xffffffff) >> 0x20) + 0x1000) >> 0xd;
  return (int)(uVar11 + 1) >> 1;
}

