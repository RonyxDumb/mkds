/* Decompiled C draft; module arm9; ROM address 020d6f78. No matching claim. */
#include "types.h"
#include "deps/020d6f78_func_020d6f78.h"

int func_020d6f78(uint param_1,int *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined4 *puVar3;
  uint *puVar4;
  ushort *puVar5;
  longlong *plVar6;
  int iVar7;
  uint uVar8;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar9;
  
  puVar3 = puRam020d7094;
  uVar9 = param_1 + 8 & 3;
  uVar8 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar9 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
  uVar8 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  lVar1 = (longlong)(int)uVar8 * (longlong)(int)uVar8 + (longlong)(int)uVar9 * (longlong)(int)uVar9;
  uVar9 = (uint)((ulonglong)lVar1 >> 0x20);
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)uVar9) {
    *puRam020d7090 = 2;
    *puVar3 = 0;
    puVar4 = puRam020d7098;
    puVar3[1] = 0x1000000;
    *puVar4 = (uint)lVar1;
    puVar5 = puRam020d709c;
    puVar4[1] = uVar9;
    plVar6 = plRam020d70a0;
    *puVar5 = 1;
    *plVar6 = lVar1 * 4;
    do {
    } while ((*puVar5 & 0x8000) != 0);
    uVar9 = *(uint *)(uRam020d70a4 & 0xfffffffc) >> (uRam020d70a4 & 3) * 8 |
            *(uint *)(uRam020d70a4 & 0xfffffffc) << (uRam020d70a4 & 3) * -8 + 0x20;
    do {
    } while ((*puRam020d7090 & 0x8000) != 0);
    uVar10 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
             *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
    uVar11 = *(uint *)(uRam020d70a8 & 0xfffffffc) >> (uRam020d70a8 & 3) * 8 |
             *(uint *)(uRam020d70a8 & 0xfffffffc) << (uRam020d70a8 & 3) * -8 + 0x20;
    uVar2 = (ulonglong)uVar9 * (ulonglong)uVar11;
    uVar8 = uRam020d70a8 + 4 & 3;
    uVar12 = *(uint *)(uRam020d70a8 + 4 & 0xfffffffc);
    iVar7 = (uVar12 >> uVar8 * 8 | uVar12 << uVar8 * -8 + 0x20) * uVar9 +
            uVar11 * ((int)uVar9 >> 0x1f) + (int)(uVar2 >> 0x20);
    *param_2 = (int)(iVar7 * uVar10 +
                     (int)uVar2 * ((int)uVar10 >> 0x1f) +
                     (int)((ulonglong)uVar10 * (uVar2 & 0xffffffff) >> 0x20) + 0x1000) >> 0xd;
    uVar8 = param_1 + 8 & 3;
    uVar10 = *(uint *)(param_1 + 8 & 0xfffffffc);
    uVar8 = uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20;
    param_2[2] = (int)(iVar7 * uVar8 +
                       (int)uVar2 * ((int)uVar8 >> 0x1f) +
                       (int)((ulonglong)uVar8 * (uVar2 & 0xffffffff) >> 0x20) + 0x1000) >> 0xd;
    return (int)(uVar9 + 1) >> 1;
  }
  return 0;
}

