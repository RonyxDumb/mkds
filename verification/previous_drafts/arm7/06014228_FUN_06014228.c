/* Decompiled C draft; module arm7; ROM address 06014228. No matching claim. */
#include "types.h"
#include "deps/06014228_FUN_06014228.h"

void FUN_06014228(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = DAT_06014248 & 3;
  uVar2 = *(uint *)(DAT_06014248 & 0xfffffffc);
  *DAT_0601424c = 0;
  *(undefined2 *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x4a4) = 0;
  return;
}

