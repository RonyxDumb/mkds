/* Decompiled C draft; module arm9; ROM address 0208d02c. No matching claim. */
#include "types.h"
#include "deps/0208d02c_func_0208d02c.h"

void func_0208d02c(int param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  
  uVar3 = 0;
  do {
    iVar6 = param_2 + uVar3 * 6;
    iVar9 = param_1 + uVar3 * 4;
    uVar1 = *(undefined2 *)(iVar6 + 2);
    uVar7 = iVar9 + 0x10;
    uVar5 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    uVar7 = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20;
    iVar2 = uVar3 * 0xc;
    *(undefined2 *)(uVar7 + 0x50) = *(undefined2 *)(param_2 + uVar3 * 6);
    *(undefined2 *)(uVar7 + 0x52) = uVar1;
    *(undefined2 *)(uVar7 + 0x54) = *(undefined2 *)(iVar6 + 4);
    uVar7 = iVar9 + 0x10;
    uVar5 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    uVar8 = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20;
    uVar7 = param_3 + iVar2;
    uVar5 = uVar7 & 3;
    uVar10 = *(uint *)(uVar7 & 0xfffffffc);
    uVar7 = uVar8 + 0x20 & 3;
    uVar4 = *(uint *)(uVar8 + 0x20 & 0xfffffffc);
    uVar4 = uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20;
    uVar3 = uVar3 + 1 & 0xffff;
    uVar7 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    iVar2 = param_3 + iVar2;
    uVar7 = (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) + 4;
    uVar4 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    *(uint *)(uVar8 + 0x28) =
         (uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20) +
         (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20);
    uVar7 = uVar8 + 0x20 & 3;
    uVar5 = *(uint *)(uVar8 + 0x20 & 0xfffffffc);
    uVar4 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
    uVar7 = iVar2 + 4;
    uVar5 = uVar7 & 3;
    uVar10 = *(uint *)(uVar7 & 0xfffffffc);
    uVar7 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar7 = (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) + 8;
    uVar4 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    *(uint *)(uVar8 + 0x2c) =
         (uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20) +
         (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20);
    uVar7 = uVar8 + 0x20 & 3;
    uVar5 = *(uint *)(uVar8 + 0x20 & 0xfffffffc);
    uVar4 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
    uVar7 = iVar2 + 8;
    uVar5 = uVar7 & 3;
    uVar10 = *(uint *)(uVar7 & 0xfffffffc);
    uVar7 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar7 = (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) + 0xc;
    uVar4 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    *(uint *)(uVar8 + 0x30) =
         (uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20) +
         (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20);
  } while (uVar3 < 2);
  return;
}

