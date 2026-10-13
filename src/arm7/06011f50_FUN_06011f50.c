/* Decompiled C draft; module arm7; ROM address 06011f50. No matching claim. */
#include "types.h"
#include "deps/06011f50_FUN_06011f50.h"

void FUN_06011f50(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined2 uVar3;
  uint uVar4;
  undefined2 *puVar5;
  uint uVar6;
  
  uVar4 = *(uint *)(DAT_06012070 & 0xfffffffc) >> (DAT_06012070 & 3) * 8 |
          *(uint *)(DAT_06012070 & 0xfffffffc) << (DAT_06012070 & 3) * -8 + 0x20;
  FUN_06009f84();
  FUN_06009ecc();
  uVar3 = FUN_06009e98(6);
  *(undefined2 *)(uVar4 + 0x3f0) = uVar3;
  if (*(short *)(param_1 + 0x12) == 4) {
    FUN_06009e58(6,0);
  }
  thunk_FUN_037fb218(0,DAT_06012074,0xc);
  uVar1 = DAT_06012074;
  *(undefined2 *)(DAT_06012074 + 8) = 0x14;
  *(undefined2 *)(uVar1 + 10) = 2000;
  uVar2 = DAT_0601207c;
  uVar6 = 0;
  uVar3 = (undefined2)DAT_06012078;
  puVar5 = (undefined2 *)(uVar1 + 0xc);
  do {
    *puVar5 = uVar3;
    uVar6 = uVar6 + 2;
    puVar5 = puVar5 + 1;
  } while (uVar6 < uVar2);
  *(undefined2 *)(DAT_06012074 + 0xc) = 8;
  *DAT_06012080 = 6;
  *(undefined2 *)(uVar4 + 0x34c) = 0x12;
  *(undefined2 *)(uVar4 + 0x35c) = 1;
  FUN_0600af7c(*(undefined2 *)(param_1 + 0x16));
  *DAT_06012084 = 0x8000;
  FUN_06009a68(DAT_06012088);
  *DAT_0601208c = 2;
  *DAT_06012090 = 1;
  *DAT_06012094 = 1;
  *DAT_0601209c = (ushort)(((DAT_06012074 & DAT_06012098) << 0xf) >> 0x10) | 0x8000;
  return;
}

