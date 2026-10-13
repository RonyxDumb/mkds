/* Decompiled C draft; module arm7; ROM address 037fb844. No matching claim. */
#include "types.h"
#include "deps/037fb844_FUN_037fb844.h"

void FUN_037fb844(void)

{
  ushort uVar1;
  
  uVar1 = 0;
  FUN_037fb808(0x8000);
  if ((*DAT_037fb87c & 0x80) != 0) {
    uVar1 = 0x8000;
  }
  *DAT_037fb880 = uVar1 | (ushort)((*DAT_037fb87c & 0xb) << 10);
  return;
}

