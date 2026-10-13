/* Decompiled C draft; module arm9; ROM address 0200e52c. No matching claim. */
#include "types.h"
#include "deps/0200e52c_Os_InsertThread.h"

void Os_InsertThread(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar7;
  uint uVar8;
  uint uVar6;
  
  iVar2 = iRam0200e590;
  uVar7 = iRam0200e590 + 8U & 3;
  uVar5 = *(uint *)(iRam0200e590 + 8U & 0xfffffffc);
  uVar6 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
  uVar7 = 0;
  uVar5 = uVar6;
  while ((uVar5 != 0 &&
         (uVar1 = uVar5 + 0x70 & 3, uVar4 = *(uint *)(uVar5 + 0x70 & 0xfffffffc),
         uVar8 = param_1 + 0x70U & 3, uVar3 = *(uint *)(param_1 + 0x70U & 0xfffffffc),
         (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) <
         (uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20)))) {
    uVar1 = uVar5 + 0x68 & 3;
    uVar8 = *(uint *)(uVar5 + 0x68 & 0xfffffffc);
    uVar7 = uVar5;
    uVar5 = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20;
  }
  if (uVar7 == 0) {
    *(uint *)(param_1 + 0x68) = uVar6;
    *(int *)(iVar2 + 8) = param_1;
  }
  else {
    uVar5 = uVar7 + 0x68 & 3;
    uVar6 = *(uint *)(uVar7 + 0x68 & 0xfffffffc);
    *(uint *)(param_1 + 0x68) = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
    *(int *)(uVar7 + 0x68) = param_1;
  }
  return;
}

