/* Decompiled C draft; module arm7; ROM address 06009aa0. No matching claim. */
#include "types.h"
#include "deps/06009aa0_FUN_06009aa0.h"

void FUN_06009aa0(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(DAT_06009af0 & 0xfffffffc) >> (DAT_06009af0 & 3) * 8 |
          *(uint *)(DAT_06009af0 & 0xfffffffc) << (DAT_06009af0 & 3) * -8 + 0x20;
  iVar1 = thunk_FUN_037fa824();
  if (iVar1 == 0) {
    *(ushort *)(uVar2 + 0x33e) = *(ushort *)(uVar2 + 0x33e) | 0x40;
  }
  else {
    thunk_FUN_037fa814(uVar2 + DAT_06009af4);
    thunk_FUN_037fa814(uVar2 + DAT_06009af8);
    thunk_FUN_037fa814(uVar2 + 0x660);
  }
  return;
}

