/* Decompiled C draft; module arm9; ROM address 020b57f8. No matching claim. */
#include "types.h"
#include "deps/020b57f8_func_020b57f8.h"

void func_020b57f8(int param_1)

{
  uint uVar1;
  undefined1 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int local_18;
  int iStack_14;
  int local_10;
  
  uVar12 = *(uint *)(uRam020b58f4 & 0xfffffffc) >> (uRam020b58f4 & 3) * 8 |
           *(uint *)(uRam020b58f4 & 0xfffffffc) << (uRam020b58f4 & 3) * -8 + 0x20;
  uVar1 = uVar12 + 0x6c & 3;
  uVar10 = *(uint *)(uVar12 + 0x6c & 0xfffffffc);
  uVar9 = uVar12 + 0x70 & 3;
  uVar3 = *(uint *)(uVar12 + 0x70 & 0xfffffffc);
  uVar8 = uVar12 + 0x8c & 3;
  uVar4 = *(uint *)(uVar12 + 0x8c & 0xfffffffc);
  if (uVar4 >> uVar8 * 8 == 0 && uVar4 << uVar8 * -8 + 0x20 == 0) {
    uVar2 = GetCurrentPlayerRacerId();
    GetDriverVec354(&local_18,uVar2);
  }
  else {
    local_18 = *(int *)(uVar12 + 0x90);
    iStack_14 = *(int *)(uVar12 + 0x94);
    local_10 = *(int *)(uVar12 + 0x98);
  }
  iVar5 = func_020b1dbc();
  if (iVar5 == 3) {
    piVar6 = (int *)func_020b57e4();
    local_18 = *piVar6;
    iStack_14 = piVar6[1];
    local_10 = piVar6[2];
  }
  uVar4 = *(uint *)(uRam020b58f4 & 0xfffffffc) >> (uRam020b58f4 & 3) * 8 |
          *(uint *)(uRam020b58f4 & 0xfffffffc) << (uRam020b58f4 & 3) * -8 + 0x20;
  uVar8 = uVar4 + 0x7c;
  uVar12 = uVar8 & 3;
  uVar11 = *(uint *)(uVar8 & 0xfffffffc);
  uVar4 = uVar4 + 0x80;
  uVar8 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar7 = func_020b57b4(local_18 - (uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20),
                        uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20,
                        uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20);
  SomeFxProduct(0x200000,uVar7);
  uVar7 = func_020b5250();
  *(undefined4 *)(param_1 + 0x10) = uVar7;
  uVar8 = *(uint *)(uRam020b58f4 & 0xfffffffc) >> (uRam020b58f4 & 3) * 8 |
          *(uint *)(uRam020b58f4 & 0xfffffffc) << (uRam020b58f4 & 3) * -8 + 0x20;
  uVar1 = uVar8 + 0x84;
  uVar4 = uVar1 & 3;
  uVar10 = *(uint *)(uVar1 & 0xfffffffc);
  uVar8 = uVar8 + 0x88;
  uVar1 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  uVar7 = func_020b57b4(local_10 - (uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20),
                        uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20,
                        uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20);
  SomeFxProduct(0x200000,uVar7);
  uVar7 = func_020b5250();
  *(undefined4 *)(param_1 + 0x14) = uVar7;
  uVar1 = param_1 + 0x10U & 3;
  uVar9 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  *(uint *)(param_1 + 0x18) = (uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20) - 0x80;
  uVar1 = param_1 + 0x14U & 3;
  uVar9 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  *(uint *)(param_1 + 0x1c) = (uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20) - 0x60;
  return;
}

