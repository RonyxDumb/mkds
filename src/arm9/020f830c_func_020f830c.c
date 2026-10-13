/* Decompiled C draft; module arm9; ROM address 020f830c. No matching claim. */
#include "types.h"
#include "deps/020f830c_func_020f830c.h"

void func_020f830c(uint param_1)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  uint uVar13;
  uint uVar12;
  uint uVar14;
  
  uVar3 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  if (uVar3 == 0) {
    return;
  }
  if (uVar3 != 1) {
    if (uVar3 == 2) {
      uVar3 = param_1 + 0x10 & 3;
      uVar4 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
      *(uint *)(param_1 + 0xc) = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
    }
    return;
  }
  uVar3 = (uint)*puRam020f8400;
  iVar5 = iRam020f8410;
  if (uVar3 == 0) {
    uVar3 = (uint)*puRam020f840c;
    iVar5 = iRam020f8414;
  }
  piVar9 = (int *)((*(uint *)(uRam020f8404 & 0xfffffffc) >> (uRam020f8404 & 3) * 8 |
                   *(uint *)(uRam020f8404 & 0xfffffffc) << (uRam020f8404 & 3) * -8 + 0x20) +
                  iRam020f8408);
  if (uVar3 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = (uint)(piVar9 + 2) & 3;
    uVar11 = *(uint *)((uint)(piVar9 + 2) & 0xfffffffc);
    uVar12 = uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20;
    uVar10 = *(uint *)((uint)piVar9 & 0xfffffffc) >> ((uint)piVar9 & 3) * 8 |
             *(uint *)((uint)piVar9 & 0xfffffffc) << ((uint)piVar9 & 3) * -8 + 0x20;
    uVar4 = (uint)(piVar9 + 1) & 3;
    uVar6 = *(uint *)((uint)(piVar9 + 1) & 0xfffffffc);
    lVar2 = (ulonglong)uVar10 * (ulonglong)uVar12;
    uVar8 = (uint)lVar2;
    uVar11 = (uint)(piVar9 + 3) & 3;
    uVar7 = *(uint *)((uint)(piVar9 + 3) & 0xfffffffc);
    uVar1 = (uint)(piVar9 + 4) & 3;
    uVar13 = *(uint *)((uint)(piVar9 + 4) & 0xfffffffc);
    uVar14 = uVar13 >> uVar1 * 8 | uVar13 << uVar1 * -8 + 0x20;
    uVar1 = (uint)(piVar9 + 5) & 3;
    uVar13 = *(uint *)((uint)(piVar9 + 5) & 0xfffffffc);
    *piVar9 = uVar14 + uVar8;
    piVar9[1] = (uVar13 >> uVar1 * 8 | uVar13 << uVar1 * -8 + 0x20) +
                (uVar7 >> uVar11 * 8 | uVar7 << uVar11 * -8 + 0x20) * uVar10 +
                uVar12 * (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) +
                (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar14,uVar8);
    if (uVar3 == 0) {
      uVar4 = (uint)(piVar9 + 1) & 3;
      uVar11 = *(uint *)((uint)(piVar9 + 1) & 0xfffffffc);
      uVar4 = uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20;
    }
    else {
      uVar4 = (uint)(piVar9 + 1) & 3;
      uVar11 = *(uint *)((uint)(piVar9 + 1) & 0xfffffffc);
      uVar4 = (uint)((ulonglong)uVar3 *
                     (ulonglong)(uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20) >> 0x20);
    }
  }
  uVar4 = uVar4 & 0xffff;
  uVar1 = param_1 + 0xc & 3;
  uVar7 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  uVar11 = iVar5 + uVar4 * 4;
  uVar6 = uVar11 & 3;
  uVar11 = *(uint *)(uVar11 & 0xfffffffc);
  if (((uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) ==
       (uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20)) &&
     (uVar4 = uVar4 + 1 & 0xffff, uVar3 <= uVar4)) {
    uVar4 = 0;
  }
  uVar3 = iVar5 + uVar4 * 4;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(uint *)(param_1 + 0xc) = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  return;
}

