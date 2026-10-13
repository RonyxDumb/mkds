/* Decompiled C draft; module arm7; ROM address 037ffea4. No matching claim. */
#include "types.h"
#include "deps/037ffea4_FUN_037ffea4.h"

void FUN_037ffea4(void)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  puVar2 = DAT_037fff3c;
  DAT_037fff3c[3] = 0xfffffffd;
  puVar2[4] = 0;
  puVar2[7] = 0;
  *puVar2 = 0;
  puVar2[2] = 0;
  puVar2[6] = 0;
  puVar2[5] = 0;
  puVar2[0x3e] = 0;
  puVar2[0x3d] = 0;
  puVar2[0x3c] = 4;
  uVar1 = (uint)(puVar2 + 0x3c) & 3;
  uVar3 = *(uint *)((uint)(puVar2 + 0x3c) & 0xfffffffc);
  FUN_037f92d0(DAT_037fff40,DAT_037fff44,0,DAT_037fff48,0x400,
               uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  FUN_037f9054(DAT_037fff40);
  FUN_037fb6c0(0xb,DAT_037fff4c);
  if (*DAT_037fff50 != 2) {
    FUN_037ffe94(1);
  }
  return;
}

