/* Decompiled C draft; module arm9; ROM address 02081120. No matching claim. */
#include "types.h"
#include "deps/02081120_func_02081120.h"

void func_02081120(int param_1,int param_2)

{
  uint uVar1;
  byte bVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  if (param_2 != 0) {
    return;
  }
  uVar9 = (uint)*(byte *)(param_1 + 0x9b);
  bVar2 = *(byte *)(param_1 + 0x9a);
  bVar3 = false;
  iVar4 = GetDriverEntry(uVar9);
  uVar7 = iVar4 + 0x508U & 3;
  uVar10 = *(uint *)(iVar4 + 0x508U & 0xfffffffc);
  uVar11 = uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20;
  uVar7 = param_1 + 0x20U & 3;
  uVar10 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar10 = uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20;
  uVar7 = uVar10 & 3;
  uVar5 = *(uint *)(uVar10 & 0xfffffffc);
  uVar10 = uVar11 + 4 & 3;
  uVar8 = *(uint *)(uVar11 + 4 & 0xfffffffc);
  uVar7 = (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) + 4;
  uVar5 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar1 = uVar11 + 8 & 3;
  uVar6 = *(uint *)(uVar11 + 8 & 0xfffffffc);
  *(uint *)(param_1 + 0x28) =
       (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) +
       ((int)(*(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
             *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20) >> 4);
  uVar7 = param_1 + 0x20U & 3;
  uVar5 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar5 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
  uVar7 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar7 = (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) + 8;
  uVar5 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  *(uint *)(param_1 + 0x2c) =
       (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) +
       ((int)(uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) >> 4);
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
       ((int)(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) >> 4);
  if (bVar2 < *(byte *)(param_1 + 0x99)) {
    *(byte *)(param_1 + 0x9a) = bVar2 + 1;
  }
  else if (bVar2 == *(byte *)(param_1 + 0x99)) {
    uVar7 = param_1 + 0x24U & 3;
    uVar10 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
    bVar3 = true;
    *(uint *)(param_1 + 0x24) = (uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) & 0xfffffffe | 1
    ;
  }
  if (!bVar3) {
    iVar4 = GetDriverEntry(uVar9);
    uVar7 = iVar4 + 0xc4U & 3;
    uVar10 = *(uint *)(iVar4 + 0xc4U & 0xfffffffc);
    *(int *)(param_1 + 0x6c) =
         (int)(short)((ushort)(uVar10 >> uVar7 * 8) | (ushort)(uVar10 << uVar7 * -8 + 0x20));
    return;
  }
  *(undefined4 *)
   (uVar9 * 0x58 +
    (*(uint *)(uRam02081220 & 0xfffffffc) >> (uRam02081220 & 3) * 8 |
    *(uint *)(uRam02081220 & 0xfffffffc) << (uRam02081220 & 3) * -8 + 0x20) + 0x30) = 0;
  return;
}

