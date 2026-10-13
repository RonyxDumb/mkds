/* Decompiled C draft; module arm7; ROM address 060089c0. No matching claim. */
#include "types.h"
#include "deps/060089c0_FUN_060089c0.h"

void FUN_060089c0(void)

{
  uint uVar1;
  uint uVar2;
  undefined1 auStack_8 [8];
  
  uVar2 = (*(uint *)(DAT_06008a00 & 0xfffffffc) >> (DAT_06008a00 & 3) * 8 |
          *(uint *)(DAT_06008a00 & 0xfffffffc) << (DAT_06008a00 & 3) * -8 + 0x20) + 0x308;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  thunk_FUN_037f97b4(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,auStack_8,1);
  FUN_06008980(auStack_8);
  FUN_06008a8c(3,0xc);
  return;
}

