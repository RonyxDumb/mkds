/* Decompiled C draft; module arm9; ROM address 0200f65c. No matching claim. */
#include "types.h"
#include "deps/0200f65c_Os_CountTicks.h"

void Os_CountTicks(void)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  puVar4 = puRam0200f6d4;
  piVar3 = piRam0200f6d0;
  uVar9 = *(uint *)((uint)piRam0200f6d0 & 0xfffffffc) >> ((uint)piRam0200f6d0 & 3) * 8 |
          *(uint *)((uint)piRam0200f6d0 & 0xfffffffc) << ((uint)piRam0200f6d0 & 3) * -8 + 0x20;
  uVar1 = (uint)(piRam0200f6d0 + 1) & 3;
  uVar8 = *(uint *)((uint)(piRam0200f6d0 + 1) & 0xfffffffc);
  uVar2 = (uint)puRam0200f6d4 & 3;
  uVar7 = *(uint *)((uint)puRam0200f6d4 & 0xfffffffc);
  *piRam0200f6d0 = uVar9 + 1;
  piVar3[1] = (uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20) + (uint)(0xfffffffe < uVar9);
  puVar6 = puRam0200f6dc;
  puVar5 = puRam0200f6d8;
  if (uVar7 >> uVar2 * 8 != 0 || uVar7 << uVar2 * -8 + 0x20 != 0) {
    *puRam0200f6d8 = 0;
    *puVar6 = 0;
    *puVar5 = 0xc1;
    *puVar4 = 0;
  }
  Os_SetTimerIrqHandler(0,uRam0200f6e0,0);
  return;
}

