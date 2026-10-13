/* Decompiled C draft; module arm9; ROM address 020b5658. No matching claim. */
#include "types.h"
#include "deps/020b5658_func_020b5658.h"

void func_020b5658(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined1 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int local_20;
  int iStack_1c;
  int local_18;
  uint uVar11;
  
  uVar13 = *(uint *)(uRam020b57b0 & 0xfffffffc) >> (uRam020b57b0 & 3) * 8 |
           *(uint *)(uRam020b57b0 & 0xfffffffc) << (uRam020b57b0 & 3) * -8 + 0x20;
  uVar1 = uVar13 + 0x6c & 3;
  uVar10 = *(uint *)(uVar13 + 0x6c & 0xfffffffc);
  uVar11 = uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20;
  uVar1 = uVar13 + 0x70 & 3;
  uVar10 = *(uint *)(uVar13 + 0x70 & 0xfffffffc);
  uVar4 = uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20;
  uVar1 = uVar13 + 0x74 & 3;
  uVar12 = *(uint *)(uVar13 + 0x74 & 0xfffffffc);
  uVar10 = uVar13 + 0x78 & 3;
  uVar5 = *(uint *)(uVar13 + 0x78 & 0xfffffffc);
  uVar2 = uVar13 + 0x8c & 3;
  uVar6 = *(uint *)(uVar13 + 0x8c & 0xfffffffc);
  if (uVar6 >> uVar2 * 8 == 0 && uVar6 << uVar2 * -8 + 0x20 == 0) {
    uVar3 = GetCurrentPlayerRacerId();
    GetDriverVec354(&local_20,uVar3);
  }
  else {
    local_20 = *(int *)(uVar13 + 0x90);
    iStack_1c = *(int *)(uVar13 + 0x94);
    local_18 = *(int *)(uVar13 + 0x98);
  }
  iVar7 = func_020b1dbc();
  if (iVar7 == 3) {
    piVar8 = (int *)func_020b57e4();
    local_20 = *piVar8;
    iStack_1c = piVar8[1];
    local_18 = piVar8[2];
  }
  iVar7 = GetB350_T5();
  iVar7 = (int)(iVar7 + ((uint)(iVar7 >> 4) >> 0x1b)) >> 5;
  iVar14 = ((uVar12 >> uVar1 * 8 | uVar12 << uVar1 * -8 + 0x20) - uVar11) * iVar7;
  iVar7 = ((uVar5 >> uVar10 * 8 | uVar5 << uVar10 * -8 + 0x20) - uVar4) * iVar7;
  local_20 = local_20 - ((int)(iVar14 + ((uint)(iVar14 >> 8) >> 0x17)) >> 9);
  local_18 = local_18 - ((int)(iVar7 + ((uint)(iVar7 >> 8) >> 0x17)) >> 9);
  uVar10 = *(uint *)(uRam020b57b0 & 0xfffffffc) >> (uRam020b57b0 & 3) * 8 |
           *(uint *)(uRam020b57b0 & 0xfffffffc) << (uRam020b57b0 & 3) * -8 + 0x20;
  uVar1 = uVar10 + 0x7c;
  uVar2 = uVar1 & 3;
  uVar5 = *(uint *)(uVar1 & 0xfffffffc);
  uVar10 = uVar10 + 0x80;
  uVar1 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  uVar9 = func_020b57b4(local_20 - uVar11,uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20,
                        uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20);
  SomeFxProduct(0x200000,uVar9);
  uVar9 = func_020b5250();
  *(undefined4 *)(param_1 + 0x10) = uVar9;
  uVar10 = *(uint *)(uRam020b57b0 & 0xfffffffc) >> (uRam020b57b0 & 3) * 8 |
           *(uint *)(uRam020b57b0 & 0xfffffffc) << (uRam020b57b0 & 3) * -8 + 0x20;
  uVar1 = uVar10 + 0x84;
  uVar2 = uVar1 & 3;
  uVar5 = *(uint *)(uVar1 & 0xfffffffc);
  uVar10 = uVar10 + 0x88;
  uVar1 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  uVar9 = func_020b57b4(local_18 - uVar4,uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20,
                        uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20);
  SomeFxProduct(0x200000,uVar9);
  uVar9 = func_020b5250();
  *(undefined4 *)(param_1 + 0x14) = uVar9;
  uVar1 = param_1 + 0x10U & 3;
  uVar10 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  *(uint *)(param_1 + 0x18) = (uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20) - 0x80;
  uVar1 = param_1 + 0x14U & 3;
  uVar10 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  *(uint *)(param_1 + 0x1c) = (uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20) - 0x60;
  return;
}

