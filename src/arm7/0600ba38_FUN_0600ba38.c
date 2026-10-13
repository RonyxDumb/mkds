/* Decompiled C draft; module arm7; ROM address 0600ba38. No matching claim. */
#include "types.h"
#include "deps/0600ba38_FUN_0600ba38.h"

undefined4 FUN_0600ba38(uint param_1)

{
  uint uVar1;
  
  if (param_1 < 2) {
    uVar1 = *(uint *)(DAT_0600ba6c & 0xfffffffc) >> (DAT_0600ba6c & 3) * 8 |
            *(uint *)(DAT_0600ba6c & 0xfffffffc) << (DAT_0600ba6c & 3) * -8 + 0x20;
    *(ushort *)(uVar1 + 0x33a) = *(ushort *)(uVar1 + 0x33a) & 0xfffe | (ushort)param_1 & 1;
    return 0;
  }
  return 5;
}

