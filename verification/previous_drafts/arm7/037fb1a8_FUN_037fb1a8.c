/* Decompiled C draft; module arm7; ROM address 037fb1a8. No matching claim. */
#include "types.h"
#include "deps/037fb1a8_FUN_037fb1a8.h"

void FUN_037fb1a8(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  FUN_037faf70();
  iVar2 = DAT_037fb210;
  uVar4 = DAT_037fb210 + (param_1 * 3 + 2) * 4;
  do {
    uVar1 = uVar4 & 3;
    uVar3 = *(uint *)(uVar4 & 0xfffffffc);
  } while (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x80000000) != 0);
  if (param_1 == 0) {
    uRam040000b0 = 0;
    *(undefined4 *)(DAT_037fb210 + 4) = 0;
    *(undefined4 *)(iVar2 + 8) = DAT_037fb214;
  }
  FUN_037faf84();
  return;
}

