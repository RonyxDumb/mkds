/* Decompiled C draft; module arm9; ROM address 0208c6dc. No matching claim. */
#include "types.h"
#include "deps/0208c6dc_func_0208c6dc.h"

void func_0208c6dc(int param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  
  uVar7 = param_1 + 0x44U & 3;
  uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  if (uVar2 >> uVar7 * 8 == 0 && uVar2 << uVar7 * -8 + 0x20 == 0) {
    return;
  }
  *(short *)(param_1 + 0x4a) = *(short *)(param_1 + 0x4a) + 1;
  if (8 < *(short *)(param_1 + 0x4a)) {
    uVar7 = param_1 + 0x44U & 3;
    uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    if (uVar2 >> uVar7 * 8 != 0 || uVar2 << uVar7 * -8 + 0x20 != 0) {
      uVar7 = 0;
      do {
        uVar2 = param_1 + uVar7 * 4 + 8;
        uVar3 = uVar2 & 3;
        uVar2 = *(uint *)(uVar2 & 0xfffffffc);
        func_0208b710(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
        iVar4 = uVar7 * 4;
        uVar7 = uVar7 + 1 & 0xffff;
        *(undefined4 *)(param_1 + iVar4 + 8) = 0;
      } while (uVar7 < 2);
    }
    uVar7 = 0;
    *(undefined4 *)(param_1 + 0x44) = 0;
    *(undefined2 *)(param_1 + 0x4a) = 0;
    uVar2 = param_1 + 0x3cU & 3;
    uVar3 = *(uint *)(param_1 + 0x3cU & 0xfffffffc);
    if (uVar3 >> uVar2 * 8 != 0 || uVar3 << uVar2 * -8 + 0x20 != 0) {
      do {
        uVar2 = param_1 + uVar7 * 4;
        uVar3 = uVar2 & 3;
        uVar2 = *(uint *)(uVar2 & 0xfffffffc);
        uVar5 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
        uVar2 = uVar5 + 0x24;
        uVar3 = uVar2 & 3;
        uVar2 = *(uint *)(uVar2 & 0xfffffffc);
        uVar7 = uVar7 + 1 & 0xffff;
        *(uint *)(uVar5 + 0x24) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0xfffffffd;
      } while (uVar7 < 2);
      return;
    }
    return;
  }
  uVar7 = 0;
  do {
    iVar8 = param_2 + uVar7 * 6;
    iVar9 = param_1 + uVar7 * 4;
    uVar1 = *(undefined2 *)(iVar8 + 2);
    uVar2 = iVar9 + 8;
    uVar3 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    iVar4 = uVar7 * 0xc;
    *(undefined2 *)(uVar2 + 0x50) = *(undefined2 *)(param_2 + uVar7 * 6);
    *(undefined2 *)(uVar2 + 0x52) = uVar1;
    *(undefined2 *)(uVar2 + 0x54) = *(undefined2 *)(iVar8 + 4);
    uVar2 = iVar9 + 8;
    uVar3 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar6 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    uVar2 = param_3 + iVar4;
    uVar3 = uVar2 & 3;
    uVar10 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = uVar6 + 0x20 & 3;
    uVar5 = *(uint *)(uVar6 + 0x20 & 0xfffffffc);
    uVar5 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
    uVar7 = uVar7 + 1 & 0xffff;
    uVar2 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    iVar4 = param_3 + iVar4;
    uVar2 = (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) + 4;
    uVar5 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    *(uint *)(uVar6 + 0x28) =
         (uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20) +
         (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20);
    uVar2 = uVar6 + 0x20 & 3;
    uVar3 = *(uint *)(uVar6 + 0x20 & 0xfffffffc);
    uVar5 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
    uVar2 = iVar4 + 4;
    uVar3 = uVar2 & 3;
    uVar10 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar2 = (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) + 8;
    uVar5 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    *(uint *)(uVar6 + 0x2c) =
         (uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20) +
         (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20);
    uVar2 = uVar6 + 0x20 & 3;
    uVar3 = *(uint *)(uVar6 + 0x20 & 0xfffffffc);
    uVar5 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
    uVar2 = iVar4 + 8;
    uVar3 = uVar2 & 3;
    uVar10 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar2 = (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) + 0xc;
    uVar5 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    *(uint *)(uVar6 + 0x30) =
         (uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20) +
         (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20);
  } while (uVar7 < 2);
  uVar7 = param_1 + 0x3cU & 3;
  uVar2 = *(uint *)(param_1 + 0x3cU & 0xfffffffc);
  if (uVar2 >> uVar7 * 8 != 0 || uVar2 << uVar7 * -8 + 0x20 != 0) {
    uVar7 = 0;
    do {
      uVar2 = param_1 + uVar7 * 4;
      uVar3 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      uVar5 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      uVar2 = uVar5 + 0x24;
      uVar3 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      uVar7 = uVar7 + 1 & 0xffff;
      *(uint *)(uVar5 + 0x24) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20 | 2;
    } while (uVar7 < 2);
    return;
  }
  return;
}

