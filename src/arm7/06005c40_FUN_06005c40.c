/* Decompiled C draft; module arm7; ROM address 06005c40. No matching claim. */
#include "types.h"
#include "deps/06005c40_FUN_06005c40.h"

void FUN_06005c40(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined2 *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined8 uVar12;
  undefined1 auStack_210 [512];
  
  iVar4 = FUN_06000680();
  uVar1 = iVar4 + 0x154cU & 3;
  uVar5 = *(uint *)(iVar4 + 0x154cU & 0xfffffffc);
  uVar5 = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
  uVar1 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar11 = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x10U & 3;
  uVar5 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  uVar1 = (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) & 0xffff;
  uVar5 = param_1 + 4U & 3;
  uVar8 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar2 = param_1 + 8U & 3;
  uVar9 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar3 = param_1 + 0xcU & 3;
  uVar10 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  iVar4 = FUN_06002394((undefined2 *)(void *)(auStack_210),(uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) & 0xffff,
                       (uVar9 >> uVar2 * 8 | uVar9 << uVar2 * -8 + 0x20) & 0xffff,
                       (uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20) & 0xffff);
  if (*(short *)(iVar4 + 4) == 0) {
    if (uVar1 == DAT_06005d44) {
      *(undefined4 *)(uVar11 + 0x7b4) = 0;
      *(undefined4 *)(uVar11 + 0x7b8) = 0;
    }
    else {
      if (uVar1 == 0) {
        iVar6 = 1;
        iVar4 = 0;
      }
      else {
        iVar6 = thunk_FUN_03806b2c(uVar1 * DAT_06005d48,0x40);
        iVar4 = iVar6 >> 0x1f;
      }
      *(int *)(uVar11 + 0x7b4) = iVar6;
      *(int *)(uVar11 + 0x7b8) = iVar4;
    }
    uVar12 = thunk_FUN_037fa278();
    iVar4 = 0;
    do {
      iVar6 = uVar11 + iVar4 * 8;
      *(uint *)(iVar6 + 0x734) = (uint)uVar12 | 1;
      *(int *)(iVar6 + 0x738) = (int)((ulonglong)uVar12 >> 0x20);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x10);
    puVar7 = (undefined2 *)thunk_FUN_03807424();
    *puVar7 = 0x1d;
    puVar7[1] = 0;
    thunk_FUN_038074cc();
  }
  else {
    FUN_06005c04(DAT_06005d40);
  }
  return;
}

