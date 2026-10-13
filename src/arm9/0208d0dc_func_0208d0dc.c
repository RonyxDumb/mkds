/* Decompiled C draft; module arm9; ROM address 0208d0dc. No matching claim. */
#include "types.h"
#include "deps/0208d0dc_func_0208d0dc.h"

void func_0208d0dc(int param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar4;
  
  uVar2 = 0;
  do {
    iVar7 = uVar2 * 6;
    iVar9 = param_2 + iVar7;
    iVar8 = param_1 + uVar2 * 4;
    uVar1 = *(undefined2 *)(iVar9 + 2);
    uVar4 = iVar8 + 0x10U & 3;
    uVar3 = *(uint *)(iVar8 + 0x10U & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    iVar6 = uVar2 * 0xc;
    *(undefined2 *)(uVar4 + 0x50) = *(undefined2 *)(param_2 + iVar7);
    *(undefined2 *)(uVar4 + 0x52) = uVar1;
    *(undefined2 *)(uVar4 + 0x54) = *(undefined2 *)(iVar9 + 4);
    uVar1 = *(undefined2 *)(iVar9 + 2);
    uVar4 = iVar8 + 0x18U & 3;
    uVar3 = *(uint *)(iVar8 + 0x18U & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    uVar2 = uVar2 + 1 & 0xffff;
    *(undefined2 *)(uVar4 + 0x50) = *(undefined2 *)(param_2 + iVar7);
    *(undefined2 *)(uVar4 + 0x52) = uVar1;
    iVar7 = param_3 + iVar6;
    *(undefined2 *)(uVar4 + 0x54) = *(undefined2 *)(iVar9 + 4);
    uVar4 = iVar8 + 0x10U & 3;
    uVar3 = *(uint *)(iVar8 + 0x10U & 0xfffffffc);
    uVar5 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    uVar3 = param_3 + iVar6 & 3;
    uVar11 = *(uint *)(param_3 + iVar6 & 0xfffffffc);
    uVar4 = uVar5 + 0x20 & 3;
    uVar10 = *(uint *)(uVar5 + 0x20 & 0xfffffffc);
    uVar10 = uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20;
    uVar4 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar4 = (uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20) + 4;
    uVar10 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    *(uint *)(uVar5 + 0x28) =
         (uVar11 >> uVar3 * 8 | uVar11 << uVar3 * -8 + 0x20) +
         (uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20);
    uVar4 = uVar5 + 0x20 & 3;
    uVar3 = *(uint *)(uVar5 + 0x20 & 0xfffffffc);
    uVar10 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    uVar3 = iVar7 + 4U & 3;
    uVar11 = *(uint *)(iVar7 + 4U & 0xfffffffc);
    uVar4 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar4 = (uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20) + 8;
    uVar10 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    *(uint *)(uVar5 + 0x2c) =
         (uVar11 >> uVar3 * 8 | uVar11 << uVar3 * -8 + 0x20) +
         (uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20);
    uVar4 = uVar5 + 0x20 & 3;
    uVar3 = *(uint *)(uVar5 + 0x20 & 0xfffffffc);
    uVar10 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    uVar3 = iVar7 + 8U & 3;
    uVar11 = *(uint *)(iVar7 + 8U & 0xfffffffc);
    uVar4 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar4 = (uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20) + 0xc;
    uVar10 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    *(uint *)(uVar5 + 0x30) =
         (uVar11 >> uVar3 * 8 | uVar11 << uVar3 * -8 + 0x20) +
         (uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20);
    uVar4 = iVar8 + 0x18U & 3;
    uVar3 = *(uint *)(iVar8 + 0x18U & 0xfffffffc);
    uVar5 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    uVar3 = param_3 + iVar6 & 3;
    uVar11 = *(uint *)(param_3 + iVar6 & 0xfffffffc);
    uVar4 = uVar5 + 0x20 & 3;
    uVar10 = *(uint *)(uVar5 + 0x20 & 0xfffffffc);
    uVar10 = uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20;
    uVar4 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar4 = (uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20) + 4;
    uVar10 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    *(uint *)(uVar5 + 0x28) =
         (uVar11 >> uVar3 * 8 | uVar11 << uVar3 * -8 + 0x20) +
         (uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20);
    uVar4 = uVar5 + 0x20 & 3;
    uVar3 = *(uint *)(uVar5 + 0x20 & 0xfffffffc);
    uVar10 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    uVar3 = iVar7 + 4U & 3;
    uVar11 = *(uint *)(iVar7 + 4U & 0xfffffffc);
    uVar4 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar4 = (uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20) + 8;
    uVar10 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    *(uint *)(uVar5 + 0x2c) =
         (uVar11 >> uVar3 * 8 | uVar11 << uVar3 * -8 + 0x20) +
         (uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20);
    uVar4 = uVar5 + 0x20 & 3;
    uVar3 = *(uint *)(uVar5 + 0x20 & 0xfffffffc);
    uVar10 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    uVar3 = iVar7 + 8U & 3;
    uVar11 = *(uint *)(iVar7 + 8U & 0xfffffffc);
    uVar4 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar4 = (uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20) + 0xc;
    uVar10 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    *(uint *)(uVar5 + 0x30) =
         (uVar11 >> uVar3 * 8 | uVar11 << uVar3 * -8 + 0x20) +
         (uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20);
  } while (uVar2 < 2);
  return;
}

