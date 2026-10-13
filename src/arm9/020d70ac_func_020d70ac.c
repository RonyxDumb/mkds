/* Decompiled C draft; module arm9; ROM address 020d70ac. No matching claim. */
#include "types.h"
#include "deps/020d70ac_func_020d70ac.h"

int func_020d70ac(uint param_1,int *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined4 *puVar3;
  longlong *plVar4;
  ushort *puVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar11;
  uint uVar12;
  uint uVar10;
  
  puVar3 = puRam020d71f4;
  uVar10 = param_1 + 4 & 3;
  uVar8 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar8 = uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20;
  uVar11 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
           *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar10 = param_1 + 8 & 3;
  uVar9 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar10 = uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20;
  lVar1 = (longlong)(int)uVar10 * (longlong)(int)uVar10 +
          (longlong)(int)uVar11 * (longlong)(int)uVar11 +
          (longlong)(int)uVar8 * (longlong)(int)uVar8;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    *puRam020d71f0 = 2;
    *puVar3 = 0;
    plVar4 = plRam020d71f8;
    puVar3[1] = 0x1000000;
    puVar5 = puRam020d71fc;
    *plVar4 = lVar1;
    plVar4 = plRam020d7200;
    *puVar5 = 1;
    *plVar4 = lVar1 * 4;
    do {
    } while ((*puVar5 & 0x8000) != 0);
    uVar10 = *(uint *)(uRam020d7204 & 0xfffffffc) >> (uRam020d7204 & 3) * 8 |
             *(uint *)(uRam020d7204 & 0xfffffffc) << (uRam020d7204 & 3) * -8 + 0x20;
    do {
    } while ((*puRam020d71f0 & 0x8000) != 0);
    uVar9 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
    uVar11 = *(uint *)(uRam020d7208 & 0xfffffffc) >> (uRam020d7208 & 3) * 8 |
             *(uint *)(uRam020d7208 & 0xfffffffc) << (uRam020d7208 & 3) * -8 + 0x20;
    uVar2 = (ulonglong)uVar10 * (ulonglong)uVar11;
    iVar7 = (int)uVar2;
    uVar8 = uRam020d7208 + 4 & 3;
    uVar12 = *(uint *)(uRam020d7208 + 4 & 0xfffffffc);
    iVar6 = (uVar12 >> uVar8 * 8 | uVar12 << uVar8 * -8 + 0x20) * uVar10 +
            uVar11 * ((int)uVar10 >> 0x1f) + (int)(uVar2 >> 0x20);
    *param_2 = (int)(iVar6 * uVar9 +
                     iVar7 * ((int)uVar9 >> 0x1f) +
                     (int)((ulonglong)uVar9 * (uVar2 & 0xffffffff) >> 0x20) + 0x1000) >> 0xd;
    uVar8 = param_1 + 4 & 3;
    uVar9 = *(uint *)(param_1 + 4 & 0xfffffffc);
    uVar8 = uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20;
    param_2[1] = (int)(iVar6 * uVar8 +
                       iVar7 * ((int)uVar8 >> 0x1f) +
                       (int)((ulonglong)uVar8 * (uVar2 & 0xffffffff) >> 0x20) + 0x1000) >> 0xd;
    uVar8 = param_1 + 8 & 3;
    uVar9 = *(uint *)(param_1 + 8 & 0xfffffffc);
    uVar8 = uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20;
    param_2[2] = (int)(iVar6 * uVar8 +
                       iVar7 * ((int)uVar8 >> 0x1f) +
                       (int)((ulonglong)uVar8 * (uVar2 & 0xffffffff) >> 0x20) + 0x1000) >> 0xd;
    return (int)(uVar10 + 1) >> 1;
  }
  return 0;
}

