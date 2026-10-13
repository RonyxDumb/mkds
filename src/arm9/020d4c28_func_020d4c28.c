/* Decompiled C draft; module arm9; ROM address 020d4c28. No matching claim. */
#include "types.h"
#include "deps/020d4c28_func_020d4c28.h"

void func_020d4c28(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar11;
  int iVar12;
  int iStack_28;
  code *pcVar10;
  
  uVar7 = param_1 + 0x10U & 3;
  uVar9 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  pcVar10 = (code *)(uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20);
  uVar8 = (uint)*(ushort *)(param_1 + 4);
  uVar7 = param_1 + 0x24U & 3;
  uVar9 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
  uVar7 = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
  if (pcVar10 == (code *)0x0) {
    return;
  }
  uVar9 = param_1 + 0x1cU & 3;
  uVar4 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  if (uVar4 >> uVar9 * 8 == 0 && uVar4 << uVar9 * -8 + 0x20 == 0) {
    iVar12 = 0;
    if (uVar8 == 0) {
      return;
    }
    do {
      uVar9 = uVar7 + iVar12 * 4;
      uVar4 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      uVar9 = uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20;
      if (((*(ushort *)(uVar9 + 2) & 0x12) == 0) && (*(short *)(uVar9 + 0x66) != 0)) {
        (*pcVar10)(param_1,uVar9,param_2);
      }
      iVar12 = iVar12 + 1;
    } while (iVar12 < (int)uVar8);
    return;
  }
  iVar12 = 0;
  uVar9 = 0;
  if (uVar8 == 0) {
    return;
  }
  do {
    uVar4 = uVar7 + iVar12 * 4;
    uVar11 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar11 = uVar4 >> uVar11 * 8 | uVar4 << uVar11 * -8 + 0x20;
    uVar4 = uVar9;
    iVar3 = iStack_28;
    if (((((*(ushort *)(uVar11 + 2) & 0x12) == 0) && (*(short *)(uVar11 + 0x66) != 0)) &&
        ((*pcVar10)(param_1,uVar11,param_2), uVar4 = uVar11, iVar3 = iVar12, uVar9 != 0)) &&
       (uVar1 = uVar11 + 0x78 & 3, uVar6 = *(uint *)(uVar11 + 0x78 & 0xfffffffc),
       uVar2 = uVar9 + 0x78 & 3, uVar5 = *(uint *)(uVar9 + 0x78 & 0xfffffffc),
       ((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) & 0x3fffffe0) <
       ((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) & 0x3fffffe0))) {
      *(uint *)(uVar7 + iStack_28 * 4) = uVar11;
      *(uint *)(uVar7 + iVar12 * 4) = uVar9;
      uVar4 = uVar9;
    }
    iStack_28 = iVar3;
    iVar12 = iVar12 + 1;
    uVar9 = uVar4;
  } while (iVar12 < (int)uVar8);
  return;
}

