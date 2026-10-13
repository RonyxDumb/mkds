/* Decompiled C draft; module arm9; ROM address 020215bc. No matching claim. */
#include "types.h"
#include "deps/020215bc_Sound_InitializeCommands.h"

void Sound_InitializeCommands(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  int *piVar12;
  int iVar13;
  
  Sound_RegisterFifoHandler();
  piVar1 = piRam0202169c;
  iVar13 = 0;
  *piRam020216a0 = (int)piRam0202169c;
  piVar12 = piVar1;
  do {
    iVar13 = iVar13 + 1;
    *piVar12 = (int)(piVar1 + iVar13 * 6);
    puVar11 = puRam020216d0;
    uVar10 = uRam020216cc;
    puVar9 = puRam020216c8;
    puVar8 = puRam020216bc;
    puVar7 = puRam020216b8;
    puVar6 = puRam020216b4;
    puVar5 = puRam020216b0;
    puVar4 = puRam020216ac;
    puVar3 = puRam020216a8;
    iVar2 = iRam020216a4;
    piVar12 = piVar12 + 6;
  } while (iVar13 < 0xff);
  *puRam020216c4 = uRam020216c0;
  *(undefined4 *)(iVar2 + 0x7e8) = 0;
  *puVar3 = 0;
  *puVar4 = 0;
  *puVar5 = 0;
  *puVar6 = 0;
  *puVar7 = 0;
  *puVar9 = 1;
  *puVar8 = 0;
  *puVar11 = uVar10;
  func_020217b4();
  iVar13 = Sound_AllocateCommand(1);
  if (iVar13 != 0) {
    *(undefined4 *)(iVar13 + 4) = 0x1d;
    *(uint *)(iVar13 + 8) =
         *(uint *)((uint)puVar11 & 0xfffffffc) >> ((uint)puVar11 & 3) * 8 |
         *(uint *)((uint)puVar11 & 0xfffffffc) << ((uint)puVar11 & 3) * -8 + 0x20;
    func_020213a4();
    Sound_FlushCommand(1);
    return;
  }
  return;
}

