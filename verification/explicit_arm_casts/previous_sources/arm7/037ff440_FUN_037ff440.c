/* Decompiled C draft; module arm7; ROM address 037ff440. No matching claim. */
#include "types.h"
#include "deps/037ff440_FUN_037ff440.h"

void FUN_037ff440(uint param_1)

{
  undefined1 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar7;
  uint uVar6;
  
  puVar1 = (undefined1 *)(DAT_037ff500 + param_1 * 0x40);
  if (*(char *)(DAT_037ff500 + param_1 * 0x40) != '\0') {
    FUN_037fa564(puVar1 + 0x14);
    *puVar1 = 0;
  }
  uVar2 = (uint)(puVar1 + 4) & 3;
  uVar5 = *(uint *)((uint)(puVar1 + 4) & 0xfffffffc);
  uVar6 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
  uVar2 = (uint)(puVar1 + 8) & 3;
  uVar5 = *(uint *)((uint)(puVar1 + 8) & 0xfffffffc);
  uVar4 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
  uVar2 = (uint)(puVar1 + 0xc) & 3;
  uVar5 = *(uint *)((uint)(puVar1 + 0xc) & 0xfffffffc);
  uVar3 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
  uVar2 = (uint)(puVar1 + 0x10) & 3;
  uVar5 = *(uint *)((uint)(puVar1 + 0x10) & 0xfffffffc);
  uVar2 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
  param_1 = param_1 | (uint)(byte)puVar1[1] << 8;
  FUN_037fa814(puVar1 + 0x14);
  if (uVar2 == 0 && uVar3 == 0) {
    FUN_037fa670(puVar1 + 0x14,uVar6,uVar4,DAT_037ff504,param_1);
  }
  else {
    lVar7 = FUN_037fa278();
    lVar7 = lVar7 + CONCAT44(uVar4,uVar6);
    FUN_037fa5f4(puVar1 + 0x14,(int)lVar7,(int)((ulonglong)lVar7 >> 0x20),uVar3,uVar2,DAT_037ff504,
                 param_1);
  }
  *puVar1 = 1;
  return;
}

