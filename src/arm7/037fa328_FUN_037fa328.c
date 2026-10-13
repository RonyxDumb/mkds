/* Decompiled C draft; module arm7; ROM address 037fa328. No matching claim. */
#include "types.h"
#include "deps/037fa328_FUN_037fa328.h"

void FUN_037fa328(void)

{
  uint uVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined2 *puVar4;
  uint uVar5;
  uint uVar6;
  
  piVar2 = DAT_037fa39c;
  uVar6 = *(uint *)((uint)DAT_037fa39c & 0xfffffffc) >> ((uint)DAT_037fa39c & 3) * 8 |
          *(uint *)((uint)DAT_037fa39c & 0xfffffffc) << ((uint)DAT_037fa39c & 3) * -8 + 0x20;
  uVar1 = (uint)(DAT_037fa39c + 1) & 3;
  uVar5 = *(uint *)((uint)(DAT_037fa39c + 1) & 0xfffffffc);
  *DAT_037fa39c = uVar6 + 1;
  piVar2[1] = (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + (uint)(0xfffffffe < uVar6);
  puVar4 = DAT_037fa3a4;
  puVar3 = DAT_037fa3a0;
  if (*(uint *)((uint)DAT_037fa3a0 & 0xfffffffc) >> ((uint)DAT_037fa3a0 & 3) * 8 != 0 ||
      *(uint *)((uint)DAT_037fa3a0 & 0xfffffffc) << ((uint)DAT_037fa3a0 & 3) * -8 + 0x20 != 0) {
    *DAT_037fa3a4 = 0;
    *DAT_037fa3a8 = 0;
    *puVar4 = 0xc1;
    *puVar3 = 0;
  }
  FUN_037f88f8(0,DAT_037fa3ac,0);
  return;
}

