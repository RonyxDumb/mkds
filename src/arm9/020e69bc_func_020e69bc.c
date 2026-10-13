/* Decompiled C draft; module arm9; ROM address 020e69bc. No matching claim. */
#include "types.h"
#include "deps/020e69bc_func_020e69bc.h"

int func_020e69bc(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  longlong lVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  
  uVar1 = param_1 + 4 & 3;
  uVar11 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar13 = *(uint *)(uRam020e6a14 & 0xfffffffc) >> (uRam020e6a14 & 3) * 8 |
           *(uint *)(uRam020e6a14 & 0xfffffffc) << (uRam020e6a14 & 3) * -8 + 0x20;
  uVar2 = uVar13 + 0x14 & 3;
  uVar9 = *(uint *)(uVar13 + 0x14 & 0xfffffffc);
  uVar3 = uVar13 + 8 & 3;
  uVar12 = *(uint *)(uVar13 + 8 & 0xfffffffc);
  uVar4 = param_1 + 8 & 3;
  uVar10 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar5 = uVar13 + 0x20 & 3;
  uVar8 = *(uint *)(uVar13 + 0x20 & 0xfffffffc);
  uVar6 = uVar13 + 0x2c & 3;
  uVar13 = *(uint *)(uVar13 + 0x2c & 0xfffffffc);
  lVar7 = (longlong)(int)(uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) *
          (longlong)(int)(uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20) +
          (longlong)(int)(uVar12 >> uVar3 * 8 | uVar12 << uVar3 * -8 + 0x20) *
          (longlong)
          (int)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
               *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) +
          (longlong)(int)(uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20) *
          (longlong)(int)(uVar9 >> uVar2 * 8 | uVar9 << uVar2 * -8 + 0x20);
  return (int)-((uVar13 >> uVar6 * 8 | uVar13 << uVar6 * -8 + 0x20) +
               ((uint)lVar7 >> 0xc | (int)((ulonglong)lVar7 >> 0x20) << 0x14)) >> 9;
}

