/* Decompiled C draft; module arm9; ROM address 0200dd94. No matching claim. */
#include "types.h"
#include "deps/0200dd94_func_0200dd94.h"

void func_0200dd94(void)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  bool bVar11;
  uint uVar10;
  
  uVar8 = 0;
  uVar7 = 0;
  iVar6 = 0;
  uVar5 = iRam0200de4c + 4U & 3;
  uVar9 = *(uint *)(iRam0200de4c + 4U & 0xfffffffc);
  uVar10 = uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20;
  uVar1 = Os_DisableIrq();
  uVar5 = iRam0200de4c + 8U & 3;
  uVar9 = *(uint *)(iRam0200de4c + 8U & 0xfffffffc);
  uVar5 = uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20;
  if (uVar5 != 0) {
    uVar9 = uVar10 + 0x70 & 3;
    uVar4 = *(uint *)(uVar10 + 0x70 & 0xfffffffc);
    uVar2 = 0;
    do {
      if (uVar5 == uVar10) {
        uVar8 = uVar2;
      }
      uVar2 = uVar5 + 0x70 & 3;
      uVar3 = *(uint *)(uVar5 + 0x70 & 0xfffffffc);
      bVar11 = (uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) ==
               (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
      if (bVar11) {
        uVar7 = uVar5;
      }
      uVar2 = uVar5 + 0x68 & 3;
      uVar3 = *(uint *)(uVar5 + 0x68 & 0xfffffffc);
      uVar3 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
      if (bVar11) {
        iVar6 = iVar6 + 1;
      }
      uVar2 = uVar5;
      uVar5 = uVar3;
    } while (uVar3 != 0);
  }
  if ((1 < iVar6) && (uVar7 != uVar10)) {
    if (uVar8 == 0) {
      uVar5 = uVar10 + 0x68 & 3;
      uVar8 = *(uint *)(uVar10 + 0x68 & 0xfffffffc);
      *(uint *)(iRam0200de4c + 8) = uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20;
    }
    else {
      uVar5 = uVar10 + 0x68 & 3;
      uVar9 = *(uint *)(uVar10 + 0x68 & 0xfffffffc);
      *(uint *)(uVar8 + 0x68) = uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20;
    }
    uVar5 = uVar7 + 0x68 & 3;
    uVar8 = *(uint *)(uVar7 + 0x68 & 0xfffffffc);
    *(uint *)(uVar10 + 0x68) = uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20;
    *(uint *)(uVar7 + 0x68) = uVar10;
    Os_RescheduleThread();
    Os_RestoreIrq(uVar1);
    return;
  }
  Os_RestoreIrq(uVar1);
  return;
}

