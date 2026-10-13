/* Decompiled C draft; module arm7; ROM address 0600ba00. No matching claim. */
#include "types.h"
#include "deps/0600ba00_FUN_0600ba00.h"

undefined4 FUN_0600ba00(uint param_1)

{
  uint uVar1;
  
  if (param_1 < 2) {
    uVar1 = *(uint *)(DAT_0600ba34 & 0xfffffffc) >> (DAT_0600ba34 & 3) * 8 |
            *(uint *)(DAT_0600ba34 & 0xfffffffc) << (DAT_0600ba34 & 3) * -8 + 0x20;
    *(ushort *)(uVar1 + 0x33a) = *(ushort *)(uVar1 + 0x33a) & 0xfffd | (ushort)((param_1 & 1) << 1);
    return 0;
  }
  return 5;
}

