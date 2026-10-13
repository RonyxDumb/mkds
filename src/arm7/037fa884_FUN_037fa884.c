/* Decompiled C draft; module arm7; ROM address 037fa884. No matching claim. */
#include "types.h"
#include "deps/037fa884_FUN_037fa884.h"

void FUN_037fa884(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar6;
  uint uVar5;
  
  uVar6 = FUN_037fa278();
  *DAT_037fa910 = 0;
  uVar1 = param_1 + 0xcU & 3;
  uVar4 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar5 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x10U & 3;
  uVar4 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  uVar3 = uVar5 - (uint)uVar6;
  iVar2 = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) -
          ((int)((ulonglong)uVar6 >> 0x20) + (uint)(uVar5 < (uint)uVar6));
  FUN_037f88f8(1,DAT_037fa914);
  uVar1 = DAT_037fa918;
  if ((-1 < iVar2) && (uVar1 = 0, iVar2 < (int)(uint)(uVar3 < 0x10000))) {
    uVar1 = ~uVar3 & 0xffff;
  }
  *DAT_037fa91c = (short)uVar1;
  *DAT_037fa910 = 0xc1;
  FUN_037f888c(0x10);
  return;
}

