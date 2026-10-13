/* Decompiled C draft; module arm9_ov000; ROM address 021a8c94. No matching claim. */
#include "types.h"
#include "deps/021a8c94_FUN_021a8c94.h"

void FUN_021a8c94(int param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  
  puVar1 = DAT_021a8d78;
  *DAT_021a8d78 = (uint)(*(int *)(param_1 + 0xc) == 1);
  uVar2 = DAT_021a8d84;
  uVar3 = *(uint *)(param_1 + 0x10);
  puVar1[1] = uVar3 << 0x18 & DAT_021a8d7c |
              uVar3 << 8 & DAT_021a8d80 | uVar3 >> 0x18 | uVar3 >> 8 & DAT_021a8d84;
  uVar3 = *(uint *)(param_1 + 0x14);
  puVar1[2] = uVar3 << 0x18 & DAT_021a8d7c |
              uVar3 << 8 & DAT_021a8d80 | uVar3 >> 0x18 | uVar3 >> 8 & uVar2;
  uVar3 = *(uint *)(param_1 + 0x18);
  puVar1[3] = uVar3 << 0x18 & DAT_021a8d7c |
              uVar3 << 8 & DAT_021a8d80 | uVar3 >> 0x18 | uVar3 >> 8 & uVar2;
  uVar3 = *(uint *)(param_1 + 0x1c);
  puVar1[4] = uVar3 << 0x18 & DAT_021a8d7c |
              uVar3 << 8 & DAT_021a8d80 | uVar3 >> 0x18 | uVar3 >> 8 & uVar2;
  uVar3 = *(uint *)(param_1 + 0x20);
  puVar1[5] = uVar3 << 0x18 & DAT_021a8d7c |
              uVar3 << 8 & DAT_021a8d80 | uVar3 >> 0x18 | uVar3 >> 8 & uVar2;
  puVar1[6] = DAT_021a8d88;
  puVar1[7] = DAT_021a8d8c;
  *DAT_021a8d90 = *(undefined4 *)(param_1 + 4);
  *DAT_021a8d94 = *(undefined4 *)(param_1 + 8);
  puVar1[8] = 0x40;
  puVar1[0xc] = *(uint *)(param_1 + 0x2c);
  puVar1[0xd] = *(uint *)(param_1 + 0x30);
  FUN_021a6ee4((int)(uintptr_t)(puVar1));
  return;
}

