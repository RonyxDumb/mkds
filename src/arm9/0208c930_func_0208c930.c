/* Decompiled C draft; module arm9; ROM address 0208c930. No matching claim. */
#include "types.h"
#include "deps/0208c930_func_0208c930.h"

void func_0208c930(int param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  
  uVar4 = param_1 + 0x40U & 3;
  uVar2 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  if (uVar2 >> uVar4 * 8 == 0 && uVar2 << uVar4 * -8 + 0x20 == 0) {
    return;
  }
  *(short *)(param_1 + 0x48) = *(short *)(param_1 + 0x48) + 1;
  if (*(short *)(param_1 + 0x48) < 0xb) {
    uVar4 = 0;
    do {
      iVar10 = uVar4 * 6;
      iVar7 = param_2 + iVar10;
      iVar6 = param_1 + uVar4 * 4;
      uVar1 = *(undefined2 *)(iVar7 + 2);
      uVar2 = iVar6 + 0x20U & 3;
      uVar5 = *(uint *)(iVar6 + 0x20U & 0xfffffffc);
      uVar2 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
      iVar3 = uVar4 * 0xc;
      *(undefined2 *)(uVar2 + 0x50) = *(undefined2 *)(param_2 + iVar10);
      *(undefined2 *)(uVar2 + 0x52) = uVar1;
      *(undefined2 *)(uVar2 + 0x54) = *(undefined2 *)(iVar7 + 4);
      uVar1 = *(undefined2 *)(iVar7 + 2);
      uVar2 = iVar6 + 0x28U & 3;
      uVar5 = *(uint *)(iVar6 + 0x28U & 0xfffffffc);
      uVar2 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
      uVar4 = uVar4 + 1 & 0xffff;
      *(undefined2 *)(uVar2 + 0x50) = *(undefined2 *)(param_2 + iVar10);
      *(undefined2 *)(uVar2 + 0x52) = uVar1;
      iVar10 = param_3 + iVar3;
      *(undefined2 *)(uVar2 + 0x54) = *(undefined2 *)(iVar7 + 4);
      uVar2 = iVar6 + 0x20U & 3;
      uVar5 = *(uint *)(iVar6 + 0x20U & 0xfffffffc);
      uVar11 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
      uVar5 = param_3 + iVar3 & 3;
      uVar9 = *(uint *)(param_3 + iVar3 & 0xfffffffc);
      uVar2 = uVar11 + 0x20 & 3;
      uVar8 = *(uint *)(uVar11 + 0x20 & 0xfffffffc);
      uVar8 = uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20;
      uVar2 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      uVar2 = (uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) + 4;
      uVar8 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      *(uint *)(uVar11 + 0x28) =
           (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20) +
           (uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20);
      uVar2 = uVar11 + 0x20 & 3;
      uVar5 = *(uint *)(uVar11 + 0x20 & 0xfffffffc);
      uVar8 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
      uVar5 = iVar10 + 4U & 3;
      uVar9 = *(uint *)(iVar10 + 4U & 0xfffffffc);
      uVar2 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      uVar2 = (uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) + 8;
      uVar8 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      *(uint *)(uVar11 + 0x2c) =
           (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20) +
           (uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20);
      uVar2 = uVar11 + 0x20 & 3;
      uVar5 = *(uint *)(uVar11 + 0x20 & 0xfffffffc);
      uVar8 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
      uVar5 = iVar10 + 8U & 3;
      uVar9 = *(uint *)(iVar10 + 8U & 0xfffffffc);
      uVar2 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      uVar2 = (uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) + 0xc;
      uVar8 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      *(uint *)(uVar11 + 0x30) =
           (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20) +
           (uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20);
      uVar2 = iVar6 + 0x28U & 3;
      uVar5 = *(uint *)(iVar6 + 0x28U & 0xfffffffc);
      uVar11 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
      uVar5 = param_3 + iVar3 & 3;
      uVar9 = *(uint *)(param_3 + iVar3 & 0xfffffffc);
      uVar2 = uVar11 + 0x20 & 3;
      uVar8 = *(uint *)(uVar11 + 0x20 & 0xfffffffc);
      uVar8 = uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20;
      uVar2 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      uVar2 = (uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) + 4;
      uVar8 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      *(uint *)(uVar11 + 0x28) =
           (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20) +
           (uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20);
      uVar2 = uVar11 + 0x20 & 3;
      uVar5 = *(uint *)(uVar11 + 0x20 & 0xfffffffc);
      uVar8 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
      uVar5 = iVar10 + 4U & 3;
      uVar9 = *(uint *)(iVar10 + 4U & 0xfffffffc);
      uVar2 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      uVar2 = (uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) + 8;
      uVar8 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      *(uint *)(uVar11 + 0x2c) =
           (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20) +
           (uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20);
      uVar2 = uVar11 + 0x20 & 3;
      uVar5 = *(uint *)(uVar11 + 0x20 & 0xfffffffc);
      uVar8 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
      uVar5 = iVar10 + 8U & 3;
      uVar9 = *(uint *)(iVar10 + 8U & 0xfffffffc);
      uVar2 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      uVar2 = (uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) + 0xc;
      uVar8 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      *(uint *)(uVar11 + 0x30) =
           (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20) +
           (uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20);
    } while (uVar4 < 2);
    return;
  }
  uVar4 = param_1 + 0x40U & 3;
  uVar2 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  if (uVar2 >> uVar4 * 8 != 0 || uVar2 << uVar4 * -8 + 0x20 != 0) {
    uVar4 = 0;
    do {
      uVar2 = param_1 + uVar4 * 4 + 0x20;
      uVar5 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      func_0208b710(uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20);
      uVar2 = param_1 + uVar4 * 4 + 0x28;
      uVar5 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      func_0208b710(uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20);
      iVar3 = param_1 + uVar4 * 4;
      *(undefined4 *)(iVar3 + 0x20) = 0;
      uVar4 = uVar4 + 1 & 0xffff;
      *(undefined4 *)(iVar3 + 0x28) = 0;
    } while (uVar4 < 2);
  }
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined2 *)(param_1 + 0x48) = 0;
  return;
}

