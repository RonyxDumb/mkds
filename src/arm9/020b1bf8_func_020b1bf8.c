/* Decompiled C draft; module arm9; ROM address 020b1bf8. No matching claim. */
#include "types.h"
#include "deps/020b1bf8_func_020b1bf8.h"

void func_020b1bf8(uint param_1,uint param_2,short *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  longlong lVar6;
  short sVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  
  uVar1 = param_1 + 4 & 3;
  uVar13 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar2 = param_2 + 4 & 3;
  uVar12 = *(uint *)(param_2 + 4 & 0xfffffffc);
  uVar3 = param_1 + 8 & 3;
  uVar10 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar4 = param_2 + 8 & 3;
  uVar8 = *(uint *)(param_2 + 8 & 0xfffffffc);
  iVar11 = ((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) * 0x3c +
           (uVar13 >> uVar1 * 8 | uVar13 << uVar1 * -8 + 0x20)) * 1000 +
           (uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20);
  iVar9 = ((*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
           *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) * 0x3c +
          (uVar12 >> uVar2 * 8 | uVar12 << uVar2 * -8 + 0x20)) * 1000 +
          (uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20);
  if (iVar11 < iVar9) {
    iVar11 = iVar9 - iVar11;
  }
  else {
    iVar11 = iVar11 - iVar9;
  }
  lVar5 = (longlong)iRam020b1ccc;
  iVar9 = -(iVar11 >> 0x1f) + (int)((longlong)iRam020b1cc8 * (longlong)iVar11 >> 0x2e);
  iVar14 = iVar11 - iVar9 * iRam020b1cd0;
  lVar6 = (longlong)iRam020b1ccc;
  sVar7 = (short)uRam020b1cd4;
  if (iVar9 < 100) {
    *(char *)(param_3 + 1) = (char)iVar9;
  }
  if (iVar9 < 100) {
    *(char *)((int)param_3 + 3) = (char)(int)(lVar6 * iVar14 >> 0x26) - (char)(iVar14 >> 0x1f);
    *param_3 = (short)iVar11 -
               sVar7 * ((short)-(iVar11 >> 0x1f) + (short)(int)(lVar5 * iVar11 >> 0x26));
    return;
  }
  *(undefined1 *)(param_3 + 1) = 99;
  sVar7 = (short)uRam020b1cd8;
  *(undefined1 *)((int)param_3 + 3) = 0x3b;
  *param_3 = sVar7;
  return;
}

