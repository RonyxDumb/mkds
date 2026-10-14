/* Decompiled C draft; module arm9; ROM address 02021488. No matching claim. */
#include "types.h"
#include "deps/02021488_Sound_CommandReceiveAndReply.h"

uint Sound_CommandReceiveAndReply(uint param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  bool bVar11;
  bool bVar12;
  
  uVar3 = Os_DisableIrq();
  if ((param_1 & 1) == 0) {
    uVar4 = func_02021834();
    if ((*(uint *)((uint)piRam020215a4 & 0xfffffffc) >> ((uint)piRam020215a4 & 3) * 8 |
        *(uint *)((uint)piRam020215a4 & 0xfffffffc) << ((uint)piRam020215a4 & 3) * -8 + 0x20) ==
        uVar4) {
      Os_RestoreIrq(uVar3);
      return 0;
    }
  }
  else {
    uVar4 = func_02021834();
    piVar1 = piRam020215a4;
    if ((*(uint *)((uint)piRam020215a4 & 0xfffffffc) >> ((uint)piRam020215a4 & 3) * 8 |
        *(uint *)((uint)piRam020215a4 & 0xfffffffc) << ((uint)piRam020215a4 & 3) * -8 + 0x20) ==
        uVar4) {
      do {
        Os_RestoreIrq(uVar3);
        Os_SpinWait(100);
        uVar3 = Os_DisableIrq();
        uVar5 = func_02021834();
        uVar4 = (uint)piVar1 & 3;
        uVar9 = *(uint *)((uint)piVar1 & 0xfffffffc);
      } while ((uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20) == uVar5);
    }
  }
  piVar1 = piRam020215a8;
  uVar9 = *(uint *)((uint)piRam020215a8 & 0xfffffffc) >> ((uint)piRam020215a8 & 3) * 8 |
          *(uint *)((uint)piRam020215a8 & 0xfffffffc) << ((uint)piRam020215a8 & 3) * -8 + 0x20;
  iVar10 = uVar9 + 1;
  uVar4 = iRam020215ac + uVar9 * 4;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  *piRam020215a8 = iVar10;
  bVar12 = SBORROW4(iVar10,8);
  bVar11 = iVar10 != 8;
  if (8 < iVar10) {
    iVar10 = 0;
  }
  if (bVar11 && (int)(uVar9 - 7) < 0 == bVar12) {
    *piVar1 = iVar10;
  }
  piVar2 = piRam020215b4;
  piVar1 = piRam020215a4;
  uVar5 = uVar4;
  if (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 != 0 ||
      *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20 != 0) {
    do {
      uVar5 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
              *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
    } while (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 != 0 ||
             *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20 != 0);
  }
  puVar6 = (uint *)(*(uint *)((uint)puRam020215b0 & 0xfffffffc) >> ((uint)puRam020215b0 & 3) * 8 |
                   *(uint *)((uint)puRam020215b0 & 0xfffffffc) <<
                   ((uint)puRam020215b0 & 3) * -8 + 0x20);
  puVar7 = puRam020215b8;
  if (puVar6 != (uint *)0x0) {
    *puVar6 = uVar4;
    puVar7 = puVar6;
  }
  uVar9 = *(uint *)((uint)piVar2 & 0xfffffffc);
  if (puVar6 == (uint *)0x0) {
    *puVar7 = uVar4;
  }
  uVar8 = *(uint *)((uint)piVar1 & 0xfffffffc);
  *puRam020215b0 = uVar5;
  *piVar2 = (uVar9 >> ((uint)piVar2 & 3) * 8 | uVar9 << ((uint)piVar2 & 3) * -8 + 0x20) - 1;
  *piVar1 = (uVar8 >> ((uint)piVar1 & 3) * 8 | uVar8 << ((uint)piVar1 & 3) * -8 + 0x20) + 1;
  Os_RestoreIrq(uVar3);
  return uVar4;
}

